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
 * \brief instanciateAndRun
 * A 'do it all' function, test the c++/python bindings
 */
void instanciateAndRun()
{
  cout << " Starting the PTAM Slam straightaway" << endl;
  cout << "  Parsing settings.cfg ...." << endl;

  GUI.LoadFile("settings.cfg");
  GUI.StartParserThread(); // Start parsing of the console input
  atexit(GUI.StopParserThread);

  try
  {
    System s;
    s.Run();
  }
  catch(CVD::Exceptions::All e)
  {
    cout << endl;
    cout << "!! Failed to run system; got exception. " << endl;
    cout << "   Exception was: " << endl;
    cout << e.what << endl;
  }
}

/*!
 * \brief The pyPTAM struct
 * A structure declaring the PTAM Slam,
 * which we can access from Python.
 * To be completed...
 */

struct pyPTAM {
public :
  System *s;
  std::string config_file;
  bool is_slam_started;
  std::vector<float> current_pose;
  boost::thread *sys_thread;

  // Create the SLAM context, and start the parser thread
  pyPTAM(std::string config_file):config_file("settings.cfg") {
    is_slam_started = false;
  }

  // Desctructor : stop the brackground thread first !
  inline ~pyPTAM() {
    if (is_slam_started)
      s->Stop();

    sys_thread->join();
    delete s;
  }

  void ConstructAndWrap() {
    // Read the settings
    cout << "  Parsing " <<  config_file << "and console" <<  endl;
    GUI.LoadFile(config_file);
    GUI.StartParserThread(); // Start parsing of the console input
    atexit(GUI.StopParserThread);

    // Build the new context
    s = new System();

    // Start the computations
    is_slam_started = true;
    s->Run();
  }

  // Start the frame grabbing and computations on a seperate thread
  void Start() {
    if (!is_slam_started) {
        // Start the thread, OpenGL context will be allocated within
        sys_thread = new boost::thread(boost::bind(&pyPTAM::ConstructAndWrap, this));

        cout << "PTAM : Thread started" << endl;
      } else {
        cout << "PTAM : Already started" << endl;
      }
  }

  /*!
   * \brief GetPose
   * \param Python list to output the values
   */
  void GetPose(boost::python::list current_pose_py) {

    // Update the pose and return it
    if (is_slam_started) {
        current_pose.resize(9);
        s->GetCurrentPose(&current_pose[0]);
      } else {
        current_pose.resize(9);
        memset(&current_pose[0], 0, 9 * sizeof(float));
      }

    // Put all the floats inside the python list
    vector<float>::iterator it;
    for (it = current_pose.begin(); it != current_pose.end(); ++it){
        current_pose_py.append(*it);
      }
  }

  int GetCurrentKeyframes() {
    if (is_slam_started)
      return s->GetCurrentKeyframes();
    else
      return 0;
  }

  int GetCurrentPoints() {
    if (is_slam_started)
      return s->GetCurrentPoints();
    else
      return 0;
  }

  int GetDiscardedPoints() {
    if (is_slam_started)
      return s->GetDiscardedPoints();
    else
      return 0;
  }
};


BOOST_PYTHON_MODULE(libpyPTAM)
{
  using namespace boost::python;

  // Function which creates the PTAM Slam and start it right away
  def("instanciateAndRun", instanciateAndRun);

  class_<std::vector<float> >("float_vector")
      .def(vector_indexing_suite<std::vector<float> >())
      ;

  // Declare the Python API : constructor, start the SLAM, get pose values, etc..
  class_<pyPTAM>("pyPTAM", init<std::string>())
      .def("Start",     &pyPTAM::Start)
      .def("GetPose", &pyPTAM::GetPose)
      .def("GetCurrentKeyframes", &pyPTAM::GetCurrentKeyframes)
      .def("GetCurrentPoints", &pyPTAM::GetCurrentPoints)
      .def("GetDiscardedPoints", &pyPTAM::GetDiscardedPoints)
      ;
}
