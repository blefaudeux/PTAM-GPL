// This is a wrapper to the PTAM start procedure, exposing it to python using Boost.Python
// Very basic from now, just testing the idea..
// Benjamin Lefaudeux

#include <stdlib.h>
#include <iostream>
#include <gvars3/instances.h>
#include "System.h"

#include <boost/python.hpp>

using namespace std;
using namespace GVars3;

void instanciate()
{
  cout << " Starting the PTAM Slam " << endl;
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


BOOST_PYTHON_MODULE(libpyPTAM)
{
    using namespace boost::python;
    def("instanciate", instanciate);
}
