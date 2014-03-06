#!/usr/bin/python
import libpyPTAM
import time

## Try the more detailled pyPTAM interface :
newSlam = libpyPTAM.pyPTAM('settings.cfg')

# Start the Process:
newSlam.Start()

# Gather the current pose, and print it:
keep_going = True
i_pict = 0

new_pose = []
while keep_going:
    new_pose = newSlam.GetPose()
    print('Pose {} : {:.2} {:.2} {:.2}'.format(i_pict, new_pose[0], new_pose[1], new_pose[2]))
    
    n_points = newSlam.GetCurrentPoints()
    print("Current points in the map : {}".format(n_points))

    time.sleep(1)
    i_pict += 1
    keep_going = (i_pict < 20)

del new_pose
print ('Ending the computations')



