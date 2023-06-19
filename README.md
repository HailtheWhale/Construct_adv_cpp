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
2. C++ data structures (Arrays, Vectors, mutisets, iterators, etc.)
3. ...

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

## Demonstrations
