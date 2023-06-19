#include "my_robot_manager/robot_manager.h"

// Class functions 
// Exercise 3.1
/*
void Ex1RobotManager::print_specifications(){
// Logs parameters to terminal. 
ROS_INFO("Robot Name: %s", robot_name.c_str());
ROS_INFO("Robot Model: %s", robot_model.c_str());
ROS_INFO("Robot Battery Capacity (kwh): %.2f", battery_capacity_kwh);
ROS_INFO("Robot operation hours: %d", total_operation_hours);
}*/

// Exercise 3.2
/*
Ex2RobotManager::Ex2RobotManager(ros::NodeHandle *nh,string topic,string name,string model){
    odometry_topic = topic;
    robot_name = name;
    robot_model = model;
    odom_subscriber = nh->subscribe(odometry_topic, 1000, &Ex2RobotManager::odom_callback, this);
}

void Ex2RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
    ROS_INFO("%s position in x,y is: %lf, %lf",robot_name.c_str(),msg->pose.pose.position.x,msg->pose.pose.position.y);
}

void Ex2RobotManager::print_specifications(){
// Logs parameters to terminal. 
ROS_INFO("Robot Name: %s", robot_name.c_str());
ROS_INFO("Robot Model: %s", robot_model.c_str());
ROS_INFO("Robot Battery Capacity (kwh): %.2f", battery_capacity_kwh);
ROS_INFO("Robot operation hours: %d", total_operation_hours);
}*/

// Exercise 3.3, 3.4
/*
// Initialize static variable.
int Ex3RobotManager::robot_count = 0;

Ex3RobotManager::Ex3RobotManager(ros::NodeHandle *nh,string topic,string name,string model){
    odometry_topic = topic;
    robot_name = name;
    robot_model = model;
    odom_subscriber = nh->subscribe(odometry_topic, 1000, &Ex3RobotManager::odom_callback, this);
    // Increase static var
    robot_count++;
}

void Ex3RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
    ROS_INFO("%s position in x,y is: %lf, %lf",robot_name.c_str(),msg->pose.pose.position.x,msg->pose.pose.position.y);
}

void Ex3RobotManager::print_specifications() const{
// Logs parameters to terminal. 
ROS_INFO("Robot Name: %s", robot_name.c_str());
ROS_INFO("Robot Model: %s", robot_model.c_str());
ROS_INFO("Robot Battery Capacity (kwh): %.2f", battery_capacity_kwh);
ROS_INFO("Robot operation hours: %d", total_operation_hours);
}*/

// Exercise 3.5

// Initialize static variable.
int Ex5RobotManager::robot_count = 0;

Ex5RobotManager::Ex5RobotManager(ros::NodeHandle *nh,string topic,string name,string model){
    odometry_topic = topic;
    robot_name = name;
    robot_model = model;
    // subscriber 
    odom_subscriber = nh->subscribe(odometry_topic, 1000, &Ex5RobotManager::odom_callback, this);
    // Increase static var
    robot_count++;
    ROS_INFO("%d robots made.",robot_count);

    // service 
    trigger_srv = nh->advertiseService(robot_name + "/log_current_position",&Ex5RobotManager::trigger_srv_callback, this);
}

void Ex5RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
    current_x_position = msg->pose.pose.position.x;
    current_y_position = msg->pose.pose.position.y;
}

bool Ex5RobotManager::trigger_srv_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res){
      ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(),
           this->current_x_position, this->current_y_position);

    res.success = true;
    res.message = "X, Y Position logged.";
    return true;
}

void Ex5RobotManager::print_specifications() const{
// Logs parameters to terminal. 
ROS_INFO("Robot Name: %s", robot_name.c_str());
ROS_INFO("Robot Model: %s", robot_model.c_str());
ROS_INFO("Robot Battery Capacity (kwh): %.2f", battery_capacity_kwh);
ROS_INFO("Robot operation hours: %d", total_operation_hours);
}