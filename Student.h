/*
Header file for Student class
Purpose of class: to represent a Student object.

Relationship with other classes
1. Derived class of Person
2. Association with Course class
3. Composition in School class
*/

//inclusion guard
#ifndef STUDENT_H
#define STUDENT_H

//including libraries
#include "Person.h"
#include "fstream"

//inheriting person
class Student: public Person{

  private:
    //data fields
    string major, classification;
    vector<string> courses_taking;

  public:
    //constructor
    Student();

    //accessors
    string get_classification() const;
    string get_major() const;
    vector<string>& get_courses_taking();

    //mutators
    void set_classification(string& nClass);
    void set_major(string& nMajor);
    void add_to_course_taking(string& course_name);
    void erase_from_course_taking(string& course_name);

    //operator overloading
    friend ostream& operator << (ostream& out, Student& student);
    friend istream& operator >> (istream& inn, Student& student);
    
};

#endif
