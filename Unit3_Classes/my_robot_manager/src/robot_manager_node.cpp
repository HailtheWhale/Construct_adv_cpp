#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
//
int main(int argc, char **argv){
// Exercise 3.1
/*
    ros::init(argc, argv, "robot_manager");
    Ex1RobotManager manager;
    manager.robot_model = "Turtlebot3";
    manager.robot_name="robot";
    manager.print_specifications();
    return 0;
*/
// Exercise 3.2
/*
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    Ex2RobotManager manager(&nh,"/robot1/odom","robot1","Turtlebot3");
    manager.print_specifications();
    ros::spin();
}*/
// Exercise 3.3, 3.4
/*
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    // robot 1
    Ex3RobotManager manager1(&nh,"/robot1/odom","robot1","Turtlebot3");
    manager1.print_specifications();
    // robot 2
    Ex3RobotManager manager2(&nh,"/robot2/odom","robot2","Turtlebot3");
    manager2.print_specifications();
    ros::spin();
}*/
// Exercise 3.5
    ros::init(argc, argv, "robot_manager");
    ros::NodeHandle nh;
    // robot 1
    Ex5RobotManager manager1(&nh,"/robot1/odom","robot1","Turtlebot3");
    manager1.print_specifications();
    // robot 2
    Ex5RobotManager manager2(&nh,"/robot2/odom","robot2","Turtlebot3");
    manager2.print_specifications();
    ros::spin();
}