#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"

RobotManagerBase::RobotManagerBase(ros::NodeHandle *nodehandle){
nh = nodehandle;
init_config_output_srv();
}

void RobotManagerBase::init_config_output_srv(){
config_output_srv = nh->advertiseService("robot_manager_output", &RobotManagerBase::config_output_srv_callback,this);
ROS_INFO("Enable Output service made.");
}

bool RobotManagerBase::config_output_srv_callback(std_srvs::SetBool::Request &req,
                                        std_srvs::SetBool::Response &res){
bool request = req.data;
 
// Call robot details (Exercise 4.4)
displayRobotDetails();

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
}else{
    res.message = "Console output DISABLED.";
    ROS_INFO("Robot Manager console output DISABLED.");
}
return true;
}

// Exercise 4.4
/*
void RobotManagerBase::displayRobotDetails(){
    ROS_INFO("Robot name is %s",robot_name.c_str());
    ROS_INFO("Robot location is %s",robot_location.c_str());
}*/