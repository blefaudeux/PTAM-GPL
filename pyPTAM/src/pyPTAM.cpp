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

  // Create the SLAM context, and start the parser thread
  pyPTAM(std::string config_file):config_file("settings.cfg") {
    cout << "  Parsing " <<  config_file << endl;
    GUI.LoadFile(config_file);
    GUI.StartParserThread(); // Start parsing of the console input
    atexit(GUI.StopParserThread);

    s = new System();

    is_slam_started = false;
  }

  // Start the frame grabbing and computations on a seperate thread
  void Run() {
    if (!is_slam_started) {
        is_slam_started = true;
        //s->RunBackgroundThread();
        s->Run();
      } else {
        cout << "PTAM : Already started" << endl;
      }
  }

  // Get current pose
  boost::python::list GetPose() {
    boost::python::list new_pose;

    if (is_slam_started) {
        // Update the pose and return it
        current_pose.resize(9);
        s->GetCurrentPose(&current_pose[0]);

        // put all the strings inside the python list
        vector<float>::iterator it;
        for (it = current_pose.begin(); it != current_pose.end(); ++it){
            new_pose.append(*it);
          }
      }

    return new_pose;
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

  // More potent API : constructor, start the SLAM, get pose values
  class_<pyPTAM>("pyPTAM", init<std::string>())
      .def("Run",     &pyPTAM::Run)
      .def("GetPose", &pyPTAM::GetPose)
      ;
}
