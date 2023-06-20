#include "robot_manager_composition/robot_manager_composition.h"
#include "robot_manager_composition/system_information.h"
#include "ros/node_handle.h"

// Exercise 4.1.
// Constructor
RobotManagerComposition::RobotManagerComposition(ros::NodeHandle *node_handle, ComputerUnit computer_unit){
// Need independent node handler.
nh = node_handle;
computer_unit = computer_unit;
init_config_output_srv();
}

void RobotManagerComposition::init_config_output_srv(){
config_output_srv = nh->advertiseService("robot_manager_output",&RobotManagerComposition::config_output_srv_callback,this);
ROS_INFO("Enable Output service made.");
}

// request handler Service 
bool RobotManagerComposition::config_output_srv_callback(std_srvs::SetBool::Request &req, 
                                                std_srvs::SetBool::Response &res){
// request may be true or false. Need to retrieve. 
bool request = req.data;

// If same as output config, notify and don't change anything. 
if (request == output_enabled){
    res.success = false;
    res.message = "Output config request is the same as what is set.";
    return true;
}
// Else do the updates
output_enabled = request;
res.success = true;
if (output_enabled == true){
    res.message = "Console output ENABLED.";
    ROS_INFO("Robot Manager console output ENABLED.");
    computer_unit.print_info();
}else{
    res.message = "Console output DISABLED.";
    ROS_INFO("Robot Manager console output DISABLED.");
}
return true;
}