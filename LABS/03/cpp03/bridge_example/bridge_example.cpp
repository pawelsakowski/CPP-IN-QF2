#include <iostream>

class Student{
 public:
     Student(std::string, int);
     Student * clone();
     std::string name;
     int age;
};


class Bridge{
 public:
    Bridge(Student innerStudent);
    ~Bridge();
    Student* studentPtr;
};

void PrintStudent(Bridge arg);


/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){

 Student student1("Adam", 21);
 Student student2("John", 22);

 std::cout << "The name of student1: " << student1.name << ", and age: " << student1.age << "\n";
 std::cout << "The name of student2: " << student2.name << ", and age: " << student2.age << "\n";

 // passing argument via Bridge class
 PrintStudent(student1);
 PrintStudent(student2);

 // creating an object of class Bridge
 Bridge student3(student1);
 std::cout << "The name of student3: " << student3.studentPtr->name << ", and age: " << student3.studentPtr->age << "\n";
 
 return 0;
}

//////////////////////////////////////////////////
// definitions of methods
Student::Student(std::string name_, int age_){
 name = name_;
 age  = age_;
}

Student* Student::clone(){
 return new Student(*this);
}


Bridge::Bridge(Student innerStudent){
    studentPtr = innerStudent.clone();
}

Bridge::~Bridge(){
 delete studentPtr;
}

void PrintStudent(Bridge arg){
 std::cout << "We have a student with the name: " << (*arg.studentPtr).name << ", and age: " << (*arg.studentPtr).age << ".\n";
}
