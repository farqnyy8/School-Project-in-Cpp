//including the header file
#include "Teacher.h"

/*
Type -> No-arguments constructor
Input -> none
Output -> none
Purpose -> to initialise variables
*/
Teacher::Teacher()
{
  rank = field = "empty";
}

/*
Type -> accessor
Input -> none
Output -> field: string
Purpose -> to return the teacher's field
*/
string Teacher::get_field() const
{
  return field;
}

/*
Type -> accessor
Input -> none
Output -> rank: string
Purpose -> to return the teacher's rank
*/
string Teacher::get_rank() const
{
  return field;
}

/*
Type -> accessor
Input -> none
Output -> courses_teaching: vector<string>&
Purpose -> to return the list of courses the teacher is teaching
*/
vector<string>& Teacher::get_courses_teaching()
{
  return courses_teaching;
}

/*
Type -> mutator
Input -> nField: string& 
Output -> none
Purpose -> to change the teacher's field
*/
void Teacher::set_field(string& nField)
{
  field = nField;
}

/*
Type -> mutator
Input -> nRank: string& 
Output -> none
Purpose -> to change the teacher's rank
*/
void Teacher::set_rank(string& nRank)
{
  rank = nRank;
}

/*
Type -> operator overloading
Input -> out: ostream&, teacher: Teacher&
Output -> out: ostream& 
Purpose -> to allow the use of cout
*/
ostream& operator << (ostream& out, Teacher& teacher)
{
	teacher.print();
	out << "Field: " << teacher.field << endl;
	out << "Rank: " << teacher.rank << endl;
	
	if(teacher.courses_teaching.size() > 0)
	{
		for(int i = 0; i < teacher.courses_teaching.size(); i++)
			out << "\tCourse " << i + 1 << ": " << teacher.courses_teaching[i] << endl;
	}
	else
		out << teacher.get_name() << " is not teaching any course/class yet." << endl;

	return out;
}

/*
Type -> operator overloading
Input -> inn: istream&, teacher: Teacher&
Output -> inn: istream& 
Purpose -> to allow the use of cin
*/
istream& operator >> (istream& inn, Teacher& teacher)
{
  teacher.enter();
  
  cout << "Enter Field: ";
  getline(inn, teacher.field);

  cout << "Enter Rank (Advisor/Professor): ";
  inn >> teacher.rank;

  return inn;
}

/*
Type -> mutators 
Input -> course_name: string& 
Output -> none
Purpose -> to add to course_name to course_teaching
*/
void Teacher::add_to_course_teaching(string& course_name)
{
	cout << name << " is now teaching " << course_name << endl;
	//function in Person class
  	add_course(courses_teaching, course_name);
}

/*
Type -> mutators 
Input -> course_name: string& 
Output -> none
Purpose -> to remove to course_name from course_teaching
*/
void Teacher::erase_from_course_teaching(string& course_name)
{
	cout << name << " is not more teaching " << course_name << endl;
	//function in Person class
  	remove_course(courses_teaching, course_name);
}
