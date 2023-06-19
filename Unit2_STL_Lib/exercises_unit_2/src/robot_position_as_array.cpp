#include "robot_commander/robot_commander.h"
#include "ros/ros.h"
#include "vector"
#include <array>
#include <iostream>
#include <string>
#include <unistd.h>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>

class Unit2Exercises {
    public:
        // Inherit RobotCommander class
        RobotCommander my_robot;

        // Would be in a header file normally. 
        // Exercise 2.1
        float pose[3] = {0.0,0.0,0.0};
        float* x = &pose[1];
        float* y = &pose[2];
        float* z = &pose[3];
        // Exercise 2.2, 2.3
        int header_values;
        // Exercise 2.5, 2.6
        float vert_x = 0.0;
        float vert_y = 0.0;
        float* vert_x_p = &vert_x;
        float* vert_y_p = &vert_y;

        std::string xy;

        // Call solutions to various exercises.
        void exercise_2_1();
        void exercise_2_2();
        void exercise_2_3();
        void exercise_2_4();
        void exercise_2_5();
        void exercise_2_6();
};

void Unit2Exercises::exercise_2_1(){
    *x = my_robot.get_x_position();
    *y = my_robot.get_y_position();
    *z = my_robot.get_z_position();
    ROS_INFO_STREAM("X,Y,Z of the robot are: " << *x << " | " << *y << " | " << *z);
}

void Unit2Exercises::exercise_2_2(){
    // Begin circle movement 
    my_robot.move_in_circles();
    // Get number of values looking for 
    std::cout << "Enter number of heading values wish to capture: ";
    std::cin >> header_values;

    // Retrieve the first heading in a vector 
    std::vector<float> heading;

    // Loop until retrieve values 
    int count = 0;
    while (count<=header_values){
        heading.push_back(my_robot.get_heading());
        ROS_INFO_STREAM("Robot heading is: "<< heading.at(count));
        count++;
        usleep(1000000);
    }
    // Print all values.
    std::cout << std::endl;
    ROS_INFO_STREAM("TOTAL Robot heading is: ");
    for (int i = 0; i<heading.size(); i++){
    std::cout << "Heading for " << i << " is: "<< heading.at(i)<<std::endl;
    }
}

void Unit2Exercises::exercise_2_3(){
    // Begin circle movement 
    my_robot.move_in_circles();
    // Get number of values looking for 
    std::cout << "Enter number of heading values wish to capture: ";
    std::cin >> header_values;

    // Retrieve the first heading in a vector 
    std::deque<float> heading;

    // Loop until retrieve values 
    int count = 0;
    while (count<=header_values){
        heading.push_front(my_robot.get_heading());
        ROS_INFO_STREAM("Robot heading is: "<< heading.at(count));
        count++;
        usleep(1000000);
    }
    // Print all values.
    std::cout << std::endl;
    ROS_INFO_STREAM("TOTAL Robot heading is: ");
    for (int i = 0; i<heading.size(); i++){
    std::cout << "Heading for " << i << " is: "<< heading.at(i)<<std::endl;
    }
}
void Unit2Exercises::exercise_2_4(){
    // List 
    std::list<std::string> laser{"range_max","range_min","angle_max","angle_min"};
    // Get first element. A pointer. 
    auto front = laser.begin();
    // Get third element. 
    advance(front,2);
    std::cout<<"The 3rd element is: " << *front << std::endl;
    // Get last element. A pointer. 1 past end index. 
    front = laser.end();
    // Get 2nd element 
    front = next(front,-3);
    std::cout<<"The 2nd element is: " << *front << std::endl;

    // Forward list 
    std::forward_list<std::string> laser_f{"range_max","range_min","angle_max","angle_min"};
    // Get first element. A pointer. 
    auto front_f = laser_f.begin();
    // Get third element. 
    advance(front_f,2);
    std::cout<<"The 3rd element is: " << *front << std::endl;
    // Cannot go backwards for forward lists. 
}

void Unit2Exercises::exercise_2_5(){
    std::set <std::string> vertices;

    int i = 1;
    while (i<=10){
        my_robot.move_forward(1);
        my_robot.turn(1.3,1);
        my_robot.stop_moving();
        *vert_x_p = my_robot.get_x_position();
        *vert_y_p = my_robot.get_y_position();
        xy = "("+std::to_string(*vert_x_p)+","+std::to_string(*vert_y_p)+")";
        vertices.insert(xy);
        i++;
    }

    std::set<std::string>::iterator it;
    std::cout << "The set vertices are : \n";
    for (it = vertices.begin() ; it != vertices.end() ; it++ ) 
    {
        std::cout << *it<<std::endl;
    }
}

void Unit2Exercises::exercise_2_6(){
    std::map <int,std::string> vertices;

    int i = 1;
    while (i<=10){
        my_robot.move_forward(1);
        my_robot.turn(1.3,1);
        my_robot.stop_moving();
        *vert_x_p = my_robot.get_x_position();
        *vert_y_p = my_robot.get_y_position();
        xy = "("+std::to_string(*vert_x_p)+","+std::to_string(*vert_y_p)+")";
        vertices.insert(std::pair<int,std::string>(i,xy));
        i++;
    }

    std::map<int,std::string>::iterator it;
    std::cout << "The map vertices are : \n";
    for (it = vertices.begin() ; it != vertices.end() ; it++ ) 
    {
        std::cout << it->first<< " | " << it->second << std::endl;
    }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "unit_2_exercises");

  Unit2Exercises robot;
  robot.exercise_2_6();

  return 0;
}