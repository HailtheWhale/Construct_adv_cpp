#pragma once
#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

// Inherit from the RobotManagerBase.
// Exercise 4.3
/*
class RobotManagerMobile : public RobotManagerBase {
    public:
        RobotManagerMobile(ros::NodeHandle *node_handle);
        void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

    private:
        void init_odom_subscriber();
        float x_pose;
        float y_pose;
        std::string odometry_topic = "/robot1/odom";
        ros::Subscriber odom_subscriber;
};*/
// Exercise 4.3
class RobotManagerMobile : public RobotManagerBase {
    public:
        RobotManagerMobile(ros::NodeHandle *node_handle);
        void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

    private:
        void displayRobotDetails();
        void init_odom_subscriber();
        float x_pose;
        float y_pose;
        std::string odometry_topic = "/robot1/odom";
        ros::Subscriber odom_subscriber;
        float battery_charge_level = 0.55;
        std::string type_of_battery = "Lead acid batteries";
};