#pragma once
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_server.h"
#include "std_srvs/SetBool.h"
#include "std_srvs/SetBoolRequest.h"
#include <string>

// Exercise 4.3
/*
class RobotManagerBase {
    public:
        RobotManagerBase(){};
        RobotManagerBase(ros::NodeHandle *node_handle);

    protected:
        ros::NodeHandle *nh;
        bool output_enabled = false;
        void init_config_output_srv();

    private:
        ros::ServiceServer config_output_srv;
        bool config_output_srv_callback(std_srvs::SetBool::Request &req,
                                        std_srvs::SetBool::Response &res);
};*/
// Exercise 4.4
class RobotManagerBase {
    public:
        RobotManagerBase(){};
        RobotManagerBase(ros::NodeHandle *node_handle);

    protected:
        void init_config_output_srv();
        // Exercise 4.4
        //virtual void displayRobotDetails();
        // Exercise 4.5
        virtual void displayRobotDetails() = 0;
        ros::NodeHandle *nh;
        bool output_enabled = false;
        std::string robot_name = "Robert";
        std::string robot_location = "MiddleOfNowhere";

    private:
        ros::ServiceServer config_output_srv;
        bool config_output_srv_callback(std_srvs::SetBool::Request &req,
                                        std_srvs::SetBool::Response &res);
};