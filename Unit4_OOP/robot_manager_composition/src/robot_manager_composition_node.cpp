#include "robot_manager_composition/robot_manager_composition.h"
#include "robot_manager_composition/system_information.h"
#include "ros/node_handle.h"

int main(int argc, char **argv){
ros::init(argc,argv,"robot_composition_manager");
ros::NodeHandle nh;
ComputerUnit comp1;
RobotManagerComposition rm = RobotManagerComposition(&nh,comp1);
ros::spin();
}