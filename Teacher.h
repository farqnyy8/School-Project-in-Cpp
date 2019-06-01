/*
Header file for Teacher class
Purpose of class: to represent a Teacher object.

Relationship with other classes
1. Derived class of Person
2. Association with Course class
3. Composition in School class
*/

//inclusion guard
#ifndef TEACHER_H
#define TEACHER_H

//including libraries
#include "Person.h"

//inheriting Person
class Teacher: public Person{

  private:
  //data fields
    string field, rank;
    vector<string> courses_teaching;

  public:
   //constructors
   Teacher();

   //accessors
   string get_field() const;
   string get_rank() const;
   vector<string>& get_courses_teaching();

   //mutator
   void set_field(string& nField);
   void set_rank(string& nRank);
   void add_to_course_teaching(string& course_name);
   void erase_from_course_teaching(string& course_name);

   //operator overloading
   friend ostream& operator << (ostream& out, Teacher& teacher);
    friend istream& operator >> (istream& inn, Teacher& teacher);

};

#endif
