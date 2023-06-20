#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "ros/ros.h"

int main(int argc, char **argv){
ros::init(argc,argv,"mobile_robot_inheritance_manager");
ros::NodeHandle nh;
RobotManagerMobile rmm = RobotManagerMobile(&nh);
ros::spin();
}