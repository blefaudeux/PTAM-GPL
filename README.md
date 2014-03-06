PTAM-GPL
========

PTAM (Parallel Tracking and Mapping) re-released under GPLv3.

What is PTAM
------------

PTAM is a monocular SLAM (Simultaneous Localization and Mapping) system useful for real-time
6-DOF camera tracking in small scenes. It was originally developed as a research system in the Active 
Vision Laboratory of the University of Oxford, as described in the following papers:

- Georg Klein and David Murray, "Parallel Tracking and Mapping for Small AR Workspaces", Proc. ISMAR 2007
- Georg Klein and David Murray, "Improving the Agility of Keyframe-based SLAM", Proc. ECCV 2008


Previous PTAM release
---------------------

PTAM was initially released in 2008 by Isis Innovation under a license suitable for
academic use. That version is also available for commercial use subject to a license
agreement with Isis Innovation. That version remains available here:
http://www.robots.ox.ac.uk/~gk/PTAM/

This code represents a re-licensed fork of Isis Innovation's PTAM Source Code Release v1.0-r114.


BLefaudeux : 
---------------------
- CMakelist compilation, but TooN, libCVD and GVars3 must be installed beforehand. A lot easier to use and compile on Linux. See E. Rosten Github (https://github.com/edrosten) to get up to date TooN, CVD and GVars3. /!\ install TooN before CVD /!\ 

- Seperate the PTAM lib & calibration routine, and a demo application which instanciates a PTAM Slam.

- Added a basic Python interface, called pyPTAM, to instanciate a PTAM Slam from within Python. Camera attitude computed by PTAM is accessible from within Python, while the slam runs in a seperate thread. (This has a dedicated CMakeLists, must be built after the original PTAM lib is built and installed)
---------------------
