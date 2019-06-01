/*
Header file for Person class
Purpose of class: to represent a Person (in a school) object.

Relationship with other classes
1. Base class for Student
2. Base class for Teacher
*/

//inclusion guard
#ifndef PERSON_H
#define PERSON_H

//libraries
#include <iostream>
#include <string>
#include <vector>

//std namespace
using namespace std;

class Person{

  protected:
    //data fields
    string name, address, phone, email; 
    static short id_gen;
    short id_num;
  
  public:
    //constructor
    Person();

    //accessors
    string get_name() const;
    short get_id() const;
    string get_phone() const;
    string get_email() const;

    //mutators
    void set_name(string& nName);
    void set_phone(string& nPhone);
    void set_email(string& nEmail);
    void add_course(vector<string>& type, string& name);
    void remove_course(vector<string>& type, string& name);

    //others
    void enter();
    void print();
};

#endif
