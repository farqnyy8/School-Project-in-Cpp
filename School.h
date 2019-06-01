/*
Header file for Course class
Purpose of class: to represent a Course object.

Relationship with other classes
1. Association with Course, Teacher and Student class
*/

//inlusion guard
#ifndef SCHOOL_H
#define SCHOOL_H

//including header file
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

//declaring classes
/*
class Teacher;
class Student;
class Course;*/

class School{
  private:
    //data fields
    string name;
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;

  public:
    //constructors
    School();

    //behaviour that client doesn't need
    void remove_teacher_from_all_courses(vector<Course>& courses, Teacher& teacher);

    //behaviours that client needs
    void admit_student();
    void expel_student();
    void hire_teacher();
    void fire_teacher();
    void start_course();
    void stop_course();  
    void add_student_to_class();
    void remove_student_from_class();
    void assign_teacher_to_class();
    void remove_teacher_from_class();
    void view_course_details();
    void view_student_details();
    void view_teacher_details();
    void print_all_students();
    void print_all_teachers();
    void print_all_courses();
    void print();  
    friend istream& operator >> (istream& inn, School& school);
};

#endif
