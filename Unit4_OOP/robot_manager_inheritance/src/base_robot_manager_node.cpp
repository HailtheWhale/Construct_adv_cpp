#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"

int main(int argc, char **argv){
ros::init(argc,argv,"robot_inheritance_manager");
ros::NodeHandle nh;
RobotManagerBase rm = RobotManagerBase(&nh);
ros::spin();
}