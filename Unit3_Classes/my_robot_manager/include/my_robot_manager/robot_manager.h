#pragma once
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "std_srvs/Trigger.h"
using namespace std;

// Exercise 3.1
/*
class Ex1RobotManager{
public:
    string robot_name, robot_model;
    float battery_capacity_kwh = 125.0;
    int total_operation_hours = 5;

    void print_specifications();
};*/

// Exercise 3.2
/*
class Ex2RobotManager{
public:
    Ex2RobotManager(ros::NodeHandle *nh,string topic,string name,string model);
    void print_specifications();
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

private:
    ros::Subscriber odom_subscriber;
    string odometry_topic = "/odom";
    string robot_name, robot_model;
    float battery_capacity_kwh = 125.0;
    int total_operation_hours = 5;
};*/

// Exercise 3.3, 3.4
/*
class Ex3RobotManager{
public:
    static int robot_count;
    Ex3RobotManager(ros::NodeHandle *nh,string topic,string name,string model);
    void print_specifications() const;
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

private:
    ros::Subscriber odom_subscriber;
    string odometry_topic = "/odom";
    string robot_name, robot_model;
    float battery_capacity_kwh = 125.0;
    int total_operation_hours = 5;
};*/
// Exercise 3.5
class Ex5RobotManager{
public:
    static int robot_count;
    Ex5RobotManager(ros::NodeHandle *nh,string topic,string name,string model);
    void print_specifications() const;
    void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
    bool trigger_srv_callback(std_srvs::Trigger::Request &req,
                              std_srvs::Trigger::Response &res);

private:
    string odometry_topic = "/odom";
    string robot_name, robot_model;
    float battery_capacity_kwh = 125.0;
    int total_operation_hours = 5;
    float current_x_position, current_y_position;
    ros::Subscriber odom_subscriber;
    ros::ServiceServer trigger_srv;
};