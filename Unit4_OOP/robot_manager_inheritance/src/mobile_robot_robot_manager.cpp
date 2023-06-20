#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/ros.h"

RobotManagerMobile::RobotManagerMobile(ros::NodeHandle *node_handle){
// Use inherited methods and variables.
nh = node_handle;
init_config_output_srv();
init_odom_subscriber();
}

void RobotManagerMobile::init_odom_subscriber(){
odom_subscriber = nh->subscribe(odometry_topic, 1000,&RobotManagerMobile::odom_callback,this);
ROS_INFO("Odom subscriber made.");
}

void RobotManagerMobile::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
    if (output_enabled){
    x_pose = msg->pose.pose.position.x;
    y_pose = msg->pose.pose.position.y;
    ROS_INFO("Position (x,y): %lf , %lf", x_pose,
             y_pose);
    }
}

// Exercise 4.4
void RobotManagerMobile::displayRobotDetails(){
    ROS_INFO("Robot name is %s",robot_name.c_str());
    ROS_INFO("Robot location is %s",robot_location.c_str());
    ROS_INFO("Robot battery type is %s",type_of_battery.c_str());
    ROS_INFO("Robot battery charge level is %lf",battery_charge_level);
}