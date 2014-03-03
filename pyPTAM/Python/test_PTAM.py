#!/usr/bin/python
import libpyPTAM

## Rough python call
# print "Importing the lib is OK, starting PTAM"
# libpyPTAM.instanciateAndRun()

## Try the more detailled interface :
newSlam = libpyPTAM.pyPTAM("settings.cfg")

# Start the Process:
newSlam.Run()

# Gather the current pose, and print it:
keep_going = True
i_pict = 0

while keep_going:
    new_pose = newSlam.GetPose()

    print('Current pose : {}'.format(new_pose))

    i_pict += 1
    keep_going = (i_pict < 200)





