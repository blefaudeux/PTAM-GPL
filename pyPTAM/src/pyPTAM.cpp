/*! \brief This is a wrapper to the PTAM start procedure, exposing it to Python using Boost.Python
 * Very basic from now, just testing the idea..
 *
 * @author : Benjamin Lefaudeux
 */

#include <stdlib.h>
#include <iostream>
#include <gvars3/instances.h>
#include "System.h"

// Boost / Python bindings
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <list>

using namespace std;
using namespace GVars3;

/*!
 * \brief The pyPTAM struct
 * A structure declaring the PTAM Slam,
 * which we can access from Python.
 * To be completed...
 */
struct pyPTAM {
public :
  System *s;
  bool is_slam_started;
  bool b_automated_start;

  std::string config_file;
  boost::thread *sys_thread;
  std::vector <double> new_pose;
  std::string AR_assets_file;

  // Create the SLAM context, and start the parser thread
  pyPTAM(std::string m_config_file, bool automate_start = false)
    :config_file("settings.cfg") {
    config_file = m_config_file;
    s = NULL;
    is_slam_started = false;
    b_automated_start = automate_start;
  }

  // Destructor : stop the brackground thread first !
  inline ~pyPTAM() {
    if (is_slam_started) {
      s->Stop();
      is_slam_started = false;
    }

    sys_thread->join();
  }

  /*!
   * \brief ConstructAndWrap.
   * Creates the context for a thread, and run
   */
  void ConstructAndWrap() {
    // Read the settings
    cout << "  Parsing " <<  config_file << " and console" <<  endl;
    GUI.LoadFile(config_file);

    // Build the new context
    s = new System(b_automated_start);

    // Load the assets if needed
    if (!AR_assets_file.empty()) {
        cout << "Deferred loading taking place" << endl;
        s->setARModel(AR_assets_file);
      }

    // Start the computations
    is_slam_started = true;
    cout << "Starting computations" << endl;
    s->Run();
  }

  /*!
   * \brief GetPose
   * \param Python list to output the values
   */
  std::vector<double> GetPose() {
    // Update the pose and return it
    if (is_slam_started) {
      new_pose.resize(12);
      s->GetCurrentPose(&new_pose[0]);
    } else {
      new_pose.resize(12);
      memset(&new_pose[0], 0, 12 * sizeof(double));
    }

    return this->new_pose;
  }

  /*!
   * \brief GetCurrentKeyframes
   * \return the current number of
   * keyframes stored in the map
   */
  int GetCurrentKeyframes() {
    if (is_slam_started)
      return s->GetCurrentKeyframes();
    else
      return 0;
  }

  /*!
   * \brief GetCurrentPoints
   * \return the current number of points positionned
   */
  int GetCurrentPoints() {
    if (is_slam_started)
      return s->GetCurrentPoints();
    else
      return 0;
  }

  /*!
   * \brief GetDiscardedPoints
   * \return the current number of discarded points
   */
  int GetDiscardedPoints() {
    if (is_slam_started)
      return s->GetDiscardedPoints();
    else
      return 0;
  }

  bool IsAlive() {
    if (is_slam_started)
      return s->isAlive();
    else
      return false;
  }

  /*!
   * \brief LoadARModel : setup the file describing the 3D model used for AR
   * \param model_file (handled by ASSIMP, see compatible types)
   */
  void LoadARModel(std::string model_file) {
    if (NULL == s) {
        cout << "Deferred AR assets loading " << endl;
        AR_assets_file = model_file;
      } else {
        cout << "Loading AR Model" << endl;
        s->setARModel(model_file);
        cout << "Model loaded" << endl;
      }
  }

  /*!
   * \brief ResetMap : Request a reset of the mapping process
   */
  void ResetMap() {
    this->s->resetMap();
  }

  /*!
   * \brief Start the frame grabbing and computations on a seperate thread
   */
  void Start() {
    if (!is_slam_started) {
      // Start the thread, OpenGL context will be allocated within
      sys_thread = new boost::thread(boost::bind(&pyPTAM::ConstructAndWrap, this));

      cout << "PTAM: Thread started" << endl;
    } else {
      cout << "PTAM: Already started" << endl;
    }
  }
};


/***********************************/
/* Define the Python access points */
BOOST_PYTHON_MODULE(libpyPTAM)
{
  using namespace boost::python;

  class_<std::vector<double> >("double_vector")
      .def(vector_indexing_suite<std::vector<double> >());

  // Declare the Python API : constructor, start the SLAM, get pose values, etc..
  class_<pyPTAM>("pyPTAM", init<std::string, bool>())
      .def("Start",               &pyPTAM::Start)
      .def("GetPose",             &pyPTAM::GetPose)
      .def("GetCurrentKeyframes", &pyPTAM::GetCurrentKeyframes)
      .def("GetCurrentPoints",    &pyPTAM::GetCurrentPoints)
      .def("GetDiscardedPoints",  &pyPTAM::GetDiscardedPoints)
      .def("LoadARModel",         &pyPTAM::LoadARModel)
      .def("ResetMap",            &pyPTAM::ResetMap)
      .def("IsAlive",             &pyPTAM::IsAlive)
      ;
}
