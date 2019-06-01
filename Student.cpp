//including the header file
#include "Student.h"


/*
Type -> No-arguments constructor
Input -> none
Output -> none
Purpose -> to initialise variables
*/
Student::Student()
{
	major = classification = "empty";
}

/*
Type -> accessors
Input -> none
Output -> classification: string
Purpose -> to return student's classification
*/
string Student::get_classification() const
{
	return classification;
}

/*
Type -> accessors
Input -> none
Output -> major: string
Purpose -> to return student's major
*/
string Student::get_major() const
{
	return major;
}

/*
Type -> accessors
Input -> none
Output -> courses_taking: vector<string>&
Purpose -> to return the list of courses the student is taking
*/
vector<string>& Student::get_courses_taking()
{
  return courses_taking;
}

/*
Type -> mutators
Input -> nClass: string&
Output -> none
Purpose -> to change student's classification
*/
void Student::set_classification(string& nClass)
{
  classification = nClass;
}

/*
Type -> mutators
Input -> nClass: string&
Output -> none
Purpose -> to change student's major
*/
void Student::set_major(string& nMajor)
{
  major = nMajor;
}

/*
Type -> operator overloading
Input -> out: ostream&, student: Student&
Output -> out: ostream& 
Purpose -> to allow the use of cout
*/
ostream& operator << (ostream& out, Student& student)
{
	student.print();
	out << "Major: " << student.major << endl;
	out << "Classification: " << student.classification << endl;

	if(student.courses_taking.size()>0)
	{
		for(int i = 0; i < student.courses_taking.size(); i++)
			out << "\tCourse " << i + 1 << ": " << student.courses_taking[i] << endl;
	}
	else
		out << student.get_name() << " is not taking any course/class yet." << endl;
	return out;
}

/*
Type -> operator overloading
Input -> inn: istream&, student: Student&
Output -> inn: istream& 
Purpose -> to allow the use of cin
*/
istream& operator >> (istream& inn, Student& student)
{
  student.enter();
  
  cout << "Enter Major: ";
  getline(inn, student.major);

  cout << "Enter Classification (Fr/So/Jr/Sr): ";
  inn >> student.classification;
  
  return inn;
}

/*
Type -> mutators 
Input -> course_name: string& 
Output -> none
Purpose -> to add to course_name to course_taking
*/
void Student::add_to_course_taking(string& course_name)
{
	cout << name << " is now taking " << course_name << endl;
	//function in Person class
  	add_course(courses_taking, course_name);
}

/*
Type -> mutators 
Input -> course_name: string& 
Output -> none
Purpose -> to remove course_name from course_taking
*/
void Student::erase_from_course_taking(string& course_name)
{
	cout << name << " is not more taking " << course_name << endl;
	//function in Person class
  	remove_course(courses_taking, course_name);
}
