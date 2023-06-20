#pragma once
#include "robot_manager_composition/system_information.h"
#include "robot_manager_composition/system_information.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "std_srvs/SetBool.h"

class RobotManagerComposition{

public:
    RobotManagerComposition();
    RobotManagerComposition(ros::NodeHandle *node_handle, ComputerUnit computer_unit);
    
protected:
    ros::NodeHandle *nh;
    void init_config_output_srv();
    bool output_enabled;

private:
    ros::ServiceServer config_output_srv;
    bool config_output_srv_callback(std_srvs::SetBool::Request &req,
                        std_srvs::SetBool::Response &res);
    ComputerUnit computer_unit;
};