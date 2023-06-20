#include<iostream>

class GrandDad{
    int age;
    protected:
      void run();
    public:
      void walk();
};

class Father: private GrandDad{
    int height;
    public:
      void sleep();
      void wake();
};
    
class You : public Father{
    int weight;
    public:
      void eat();
      void dance();
};

//1) What is the type of inheritance is involved
// when you initialize an object of class You?
// Inherit Father and Granddad -> Multilevel Inheritance

//2) Write names of all the members, which are directly accessible 
//by the member function wake() of class Father.
// Data: height. Functions: run(),walk(),sleep(),wake()

//3) Write names of all the members who are directly accessible by 
//the member function dance() of class You.
// Data: weight. Functions: eat(),dance(),sleep(),wake()

//4) Write the names of all the members who are directly accessible
// by the object Tom of class You declared in main().
// eat(),dance(),sleep(),wake()
