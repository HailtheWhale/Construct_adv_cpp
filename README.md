# Based on theContruct's Advanced C++ for Robotics Course
Meaning, that you'd need their Web Environment to easily reuse what is here.
- Completed by Donovan Gegg (WIP)

## Dependencies (WIP)
- RobotCommander Object: https://bitbucket.org/theconstructcore/modern_cpp_course.git
- ...

## Notes
- Packages were divided by Units for organization.
- Credit was given to theConstruct for code when it was provided. 
- Exercises were done *independently*. Demonstrations shown utilize these. 

## Repo Structure 
1. What was taught. 
2. Notes on what an exercise asked for. Changes, to that, if applicable. 
3. Video Demonstrations. 

## What was taught
1. The compilation stack for compiled languages. Basic build system processes. Clang was used in this course (more info here[https://clang.llvm.org/docs/CommandGuide/clang.html])
2. C++ data structures (arrays, vectors, mutisets, iterators, etc.)
3. What structures are. How to make better C++ classes (access specifiers, constructors, destructors, the `this` pointer, static variables and functions).
4. Object Oriented Programming concepts (Composition, inheritance, virtual functions, function overload, polymorphism). Introduction to interfaces and type casting.

## Exercise Requirements and Modifications 
- Exercise 1.1 
    - Requirements: Make a library or change one of the demo ones to display the robot's velocity. 
    - Changes: None. 
- Exercise 2.1
    - Requirements: Make a library. Call the `RobotCommander` Object. Display the robot's x,y,z coordinates in the terminal through **arrays**. 
    - Changes: Created class `Unit2Exercises`. Made exercise a method call. Used pointers for all variables. 
- Exercise 2.2
    - Requirements: Retrieve the robot's current heading. Add this to a **vector**. Print each collected value as it is collected. Print all values when the a specified number of values is reached. 
    - Changes: Made exercise a method call. Used pointers for all variables. Modified provided base code to be used in method. 
- Exercise 2.3
    - Requirements: Same as Exercise 2.2, but use a **deque** as the container. Add headings to the front of the container. 
    - Changes: Same as Exercise 2.2. 
- Exercise 2.4
    - Requirements: Make a **list** and **forward list** of strings. Access specified elements them.
    - Changes: Made exercise a method call.
- Exercise 2.5
    - Requirements: Make the robot move in a polygon of choice. Record the x,y values at each vertext, and attach to a set. Loop through the set to print the vertices. 
    - Changes: Made exercise a method call. Used pointers for all variables. Assumed wanted casting of x,y to strings for insertion into set because no solution was provided. 
- Exercise 2.6
    - Requirements: Do Exercise 2.5 again but with a map. 
    - Changes: Same as Exercise 2.5. 

*Note: From Unit 3 onwards, no changes were made to exercise requirements since they already involved classes and pointers.*

*Note: For Unit 3: Associated files: robot_manager_node.cpp, robot_manager.cpp, robot_manager.h*

- Exercise 3.1
    - Requirements: Make a ROS package. Make a class, but separate things into a header, main, and node file. Initialize values in the header. 
- Exercise 3.2
    - Requirements: Add nav_msgs as a dependency to the previously made package. Declare all variables as private. Add a constructor that takes a pointer and 3 strings as args. Add a ros::subscriber variable. Keep the node running with ros::spin().
- Exercise 3.3 
    - Requirements: Add a static variable. Increase it whenever an object is made. Add another instance of class. 
- Exercise 3.4
    - Requirements: Add const references to code. 
- Exercise 3.5
    - Requirements: Add 2 private params for x and y positions. Assign values to these from the odom callback. Add a service call that logs the current robot coordinates. 
- Exercise 4.1
    - Requirements: Make 3 files, a header, main, and node. Make a class, `robot_manager_composition`, with a boolean called `output_enabled`. Make a boolean service which updates `output_enabled` if appropriate when called. In the constructor, save a premade `ComputerUnit` class. Call the `ComputerUnit` class' print method when `output_enabled` is true. 
    - Associated files: In the `robot_manager_composition` pkg.
- Exercise 4.2
    - Requirements: Provided with various levels of inheritance, answer some questions. In `~unit4exercises/exercise_4_2`.
- Exercise 4.3
    - Requirements: Redo Exercise 4.1, but in a different package, `robot_manager_inheritance`, minus the `ComputerUnit` functions. The new files have the base name `base_robot_manager`. Make a new set of header, main, and node files with the base name `mobile_mobile_robot_manager`. Make a new class which inherits from the remade class and reuses its service. Add an odometry subscriber which prints the location of the given topic when output is enabled. 
    - Associated Files: In `robot_manager_inheritance` package.
- Exercise 4.4 
    - Requirements: Build off Exercise 4.3. Add a virtual method to the base class which prints strings. In the child class, override the function to print extra contents. 
    - Associated Files: In `robot_manager_inheritance` package.
- Exercise 4.5 
    - Requirements: Build off Exercise 4.4. Make the parent class' virtual function a pure virtual function.

## Demonstrations
