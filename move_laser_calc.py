from time import sleep
from robot_control_class import RobotControl

rc = RobotControl(robot_name= "summit")

def moves(secs):
    rc.move_straight()
    sleep(secs)
    rc.stop_robot()

def glaser(f,d,g):
   
    r1 = rc.get_laser_summit(f)
    r2 = rc.get_laser_summit(d)
    r3 = rc.get_laser_summit(g)
    
    return [r1,r2,r3]
l = []
for i in range(3):
    en = int(input("enter any value from 0 - 719: "))
    l.append(en)
fn = glaser(l[0],l[1],l[2])

moves(5)
#print(fn)
for i,n in zip(l,fn):
    print(f"Reading {i} is {n}")
