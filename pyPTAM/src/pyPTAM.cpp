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
 * A structure declaring the PTAM slam,
 * which we can access from Python.
 * To be completed.
 */
typedef std::vector<float> pyVecFloat;

struct pyPTAM {
  public :
    System s;
    std::string config_file;
    bool is_slam_started;
    float current_pose[9];

    // Create the SLAM and parse the settings
    pyPTAM(std::string config_file):config_file("settings.cfg") {
      cout << "  Parsing " <<  config_file << endl;
      GUI.LoadFile(config_file);
      GUI.StartParserThread(); // Start parsing of the console input
      atexit(GUI.StopParserThread);
      is_slam_started = false;
    }

    // Start the frame grabbing and computations
    void Run() {
      is_slam_started = true;
      s.Run();
    }

    // Get current pose
    pyVecFloat GetPose() {
      pyVecFloat lPose;

      if (!is_slam_started) {
        // Return an empty vec
        lPose.clear();
      } else {
        // Update the pose and return it
        s.GetCurrentPose(current_pose);

        // Copy it to the Python list structure (a bit clumsy..)
        for (int i=0; i<9; ++i) {
          lPose.push_back(current_pose[i]);
        }
      }

      return lPose;
    }
};


BOOST_PYTHON_MODULE(libpyPTAM)
{
  using namespace boost::python;

  // Function which creates the PTAM Slam and start it right away
  def("instanciateAndRun", instanciateAndRun);


  class_<pyVecFloat>("pyVecFloat")
          .def(vector_indexing_suite<pyVecFloat>() );

  // More potent API : constructor, start the SLAM, get pose values
  class_<pyPTAM>("pyPTAM", init<std::string>())
      .def("Run",     &pyPTAM::Run)
      .def("GetPose", &pyPTAM::GetPose)
      ;
}
