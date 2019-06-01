//including the header file
#include "Course.h"

/*
Type -> No-arguments constructor
Input -> none
Output -> none
Purpose -> to initialise variables
*/
Course::Course()
{
  name = instructor = "empty";
  max = 10;
}

/*
Type -> Special
Input -> type: vector<string>&, name: string& 
Output -> i: int
Purpose -> to search for name in type and return -1 if it is not found
*/
int Course::search(vector<string>& type, string& name)
{
  for(int i = 0 ; i < type.size(); i++){
    if(type[i] == name)
      return i;
  }
  return -1;
}

/*
Type -> accessors
Input -> none
Output -> name: string
Purpose -> to return the course's name
*/
string Course::get_name() const
{
  return name;
}

/*
Type -> accessors
Input -> none
Output -> instructor: string
Purpose -> to return the course's instructor
*/
string Course::get_instructor() const
{
  return instructor;
}    
    
/*
Type -> mutators
Input -> student: Student&
Output -> none
Purpose -> to add a student to the course
*/
void Course::add_student(Student& student)
{
  string temp = student.get_name();
  int find = search(course_takers, temp);

  if(find == -1 && course_takers.size() < max)
  {
    course_takers.push_back(temp);
	cout << student.get_name() << " has been added to " << name << endl;
	//add the course's name to the student's list of courses
    student.add_to_course_taking(name);
  }
  else if(find == -1 && course_takers.size() == max)
    cout << "Course capacity is already exhausted." << endl;
  else
    cout << name << " is already taking this class" << endl;

}

/*
Type -> mutators
Input -> student: Student&
Output -> none
Purpose -> to drop a student from the course
*/
void Course::drop_student(Student& student)
{
  string temp = student.get_name();
  int find = search(course_takers, temp);

  if(find == -1)
    cout << temp << " was not taking this class." << endl;
  else
  {
    course_takers.erase(course_takers.begin() + find);
	cout << student.get_name() << "has been dropped from " << name << endl;
	//remove the course's name from the student's list of courses
    student.erase_from_course_taking(name);
  }
}

/*
Type -> mutators
Input -> teacher: Teacher&
Output -> none
Purpose -> to assign a teacher to the course
*/
void Course::assign_teacher(Teacher& teacher)
{
  if(instructor == "empty")
  {
	  instructor = teacher.get_name();
  	cout << teacher.get_name() << " has been assigned to "<< name << endl;
  	//add the course's name to the teacher's list of courses
  	teacher.add_to_course_teaching(name);
  }
  else 
	{
		cout << "There is already a teacher for this class. \nTo assign another, follow due protocol by removing the former one first before assigning a new one.";
	}
}

/*
Type -> mutators
Input -> teacher: Teacher&
Output -> none
Purpose -> to remove a teacher from the course
*/
void Course::remove_teacher(Teacher& teacher)
{
	cout << teacher.get_name() << " has been removed from "<< name << endl;
	//remove the course's name from the teacher's list of courses
	instructor = "empty";
	teacher.erase_from_course_teaching(name);
}
    
/*
Type -> Special
Input -> none
Output -> none
Purpose -> to print all the course details
*/
void Course::print()
{
  cout << "Course Name: " << name << endl;
  cout << "Course Instructor Name: " << instructor << endl;
  cout << "Number of Students in Class: " << course_takers.size() << endl;
  cout << "Students in class: "<< endl;
  for(int i = 0; i < course_takers.size(); i++)
    cout << "Student " << i << ": " << course_takers[i] << endl;
}

/*
Type -> operator overloading
Input -> out: ostream&, course: Course&
Output -> out: ostream& 
Purpose -> to allow the use of cout
*/
ostream& operator << (ostream& out, Course& course)
{
  out << "Course Name: " << course.name << endl;
  out << "Course Instructor Name: " << course.instructor << endl;

	if(course.course_takers.size() > 0)
	{
		for(int i = 0; i < course.course_takers.size(); i++)
			out << "\tStudent " << i + 1 << ": " << course.course_takers[i] << endl;
	}
	else
		out << "There is no student "<< course.get_name() << " yet." << endl;
	return out;
}

/*
Type -> operator overloading
Input -> inn: istream&, teacher: Teacher&
Output -> inn: istream& 
Purpose -> to allow the use of cin
*/
istream& operator >> (istream& inn, Course& course)
{
  cin.ignore();
  cout << "Enter Course Name: ";
  getline(inn, course.name);
  return inn;
}
