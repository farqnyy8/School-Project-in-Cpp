/*
Header file for Course class
Purpose of class: to represent a Course object.

Relationship with other classes
1. Association with Teacher and Student class
2. Composition in School class
*/

//inclusion guard
#ifndef COURSE_H
#define COURSE_H

//inluding libraries
#include "Student.h"
#include "Teacher.h"

//declare Student and Teacher Classes
class Student;
class Teacher;

class Course{
  private:
  //data fields
    string name, instructor;
    vector<string> course_takers;
    int max; 

    //private function
    int search(vector<string>& type, string& name);

  public:
    //constructors
    Course();

    //accessors
    string get_name() const;
    string get_instructor() const;    
    
    //mutators
    void add_student(Student& student);
    void drop_student(Student& student);
    void assign_teacher(Teacher& teacher);
    void remove_teacher(Teacher& teacher);
    
    //others
    void print();

    //operator overloading
    friend ostream& operator << (ostream& out, Course& course);
    friend istream& operator >> (istream& inn, Course& course);

};

#endif
