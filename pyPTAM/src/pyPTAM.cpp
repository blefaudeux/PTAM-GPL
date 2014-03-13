// This is a wrapper to the PTAM start procedure, exposing it to Python using Boost.Python
// Very basic from now, just testing the idea..
// Benjamin Lefaudeux

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
  std::string config_file;
  boost::thread *sys_thread;
  std::vector <double> new_pose;
  std::string AR_assets_file;

  // Create the SLAM context, and start the parser thread
  pyPTAM(std::string config_file):config_file("settings.cfg") {
    s = NULL;
    is_slam_started = false;
  }

  // Desctructor : stop the brackground thread first !
  inline ~pyPTAM() {
    if (is_slam_started) {
      s->Stop();
      is_slam_started = false;
    }

    sys_thread->join();
    cout << "PTAM thread returned" << endl;
  }

  void ConstructAndWrap() {
    // Read the settings
    cout << "  Parsing " <<  config_file << " and console" <<  endl;
    GUI.LoadFile(config_file);
    GUI.StartParserThread(); // Start parsing of the console input
    atexit(GUI.StopParserThread);

    // Build the new context
    s = new System();

    // Load the assets if needed
    if (!AR_assets_file.empty()) {
        cout << "Deferred loading taking place" << endl;
        s->setARModel(AR_assets_file);
      }

    // Start the computations
    is_slam_started = true;
    cout << "Starting computations" << endl;
    s->Run();

    // TODO : quit the Python VM if the function returned..
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
   * \brief GetCurrentPoints:
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

//  void MapReset() {
//    if (is_slam_started) {
//      s->mpMap.Reset();
//      cout << "PTAM: Map reset" << endl;
//    }
//  }

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

  // Start the frame grabbing and computations on a seperate thread
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
      .def(vector_indexing_suite<std::vector<double> >())
      ;

  // Declare the Python API : constructor, start the SLAM, get pose values, etc..
  class_<pyPTAM>("pyPTAM", init<std::string>())
      .def("Start",               &pyPTAM::Start)
      .def("GetPose",             &pyPTAM::GetPose)
      .def("GetCurrentKeyframes", &pyPTAM::GetCurrentKeyframes)
      .def("GetCurrentPoints",    &pyPTAM::GetCurrentPoints)
      .def("GetDiscardedPoints",  &pyPTAM::GetDiscardedPoints)
      .def("LoadARModel",         &pyPTAM::LoadARModel)
      ;
}
