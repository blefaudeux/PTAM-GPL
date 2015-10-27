#!/usr/bin/python
import libpyPTAM
import time

## Try the more detailled pyPTAM interface :
Slam = libpyPTAM.pyPTAM('microsoft.cfg', False)

# Load the 3D Model
Slam.LoadARModel('Lego.3ds')

# Start the Process:
Slam.Start()

# Gather the current pose, and print it:
keep_going = True
i_pict = 0

new_pose = []
while keep_going:
    new_pose = Slam.GetPose()
    print('Pose {} : {:.2} {:.2} {:.2}'.format(i_pict, new_pose[0], new_pose[1], new_pose[2]))
    
    n_points = Slam.GetCurrentPoints()
    print("Current points in the map : {}".format(n_points))

    time.sleep(1)
    i_pict += 1
    keep_going = ((i_pict < 200) and Slam.IsAlive())

del new_pose
print ('Bye bye, good seeing you around')
