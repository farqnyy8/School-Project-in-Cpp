//including the header file
#include "School.h"

/*
Type -> No-arguments constructor
Input -> none
Output -> none
Purpose -> to initialise variables
*/
School::School()
{
	name = "empty";
}

/*
Type -> non member function
Input -> courses: vector<Course>&, student: Student& 
Output -> none
Purpose -> to remove student from all the classes
*/
void remove_student_from_all_courses(vector<Course>& courses, Student& student)
{
	//get the courses the student is taking
	vector<string> temp = student.get_courses_taking();

	for(int i = 0; i < courses.size(); i++)
	{
		for(int j = 0; i < temp.size(); i++)
    	{
      		if(courses[i].get_name() == temp[j])
	  		//drop student from course
        	courses[i].drop_student(student);
    	}
  	}
}

/*
Type -> private member function 
Input -> courses: vector<Course>&, teacher: Teacher& 
Output -> none
Purpose -> to remove teacher from all the classes
*/
void School::remove_teacher_from_all_courses(vector<Course>& courses, Teacher& teacher)
{
	//get the courses the teacher is teaching
	vector<string> temp = teacher.get_courses_teaching();

	for(int j = 0; j < temp.size(); j++)
    {
		//remove teacher from all courses
		if(courses[j].get_name() == temp[j])
			courses[j].remove_teacher(teacher);

		//block of code to ask user to assign new teacher	
		{
			string assign;
			cout << "Do you want to assign a new teacher now (Y or anything else): ";
			getline(cin, assign);

			if(assign == "Y" || assign == "y")
			{
				cout << "Continue by assign a teacher to this class......" << endl;
				assign_teacher_to_class();
			}
			else
			cout <<"Don't forget to assign a teacher later -> the students would be missing out."<< endl;
		}
	}
	
}

/*
Type -> non-member function 
Input -> temp: vector<string>&, name: string& 
Output -> temp: bool
Purpose -> to search for name in temp
*/
bool check_student_course(vector<string>& temp, string& name)
{
	for(int i = 0; i < temp.size(); i++)
	{
    	if(temp[i] == name)
      	return true;
  	}
  	return false;
}


/*
Type -> non-member function 
Input -> students: vector<Student>&, teachers: vector<Teacher>&, course: Course& 
Output -> none
Purpose -> to remove course from all teachers and students
*/
void remove_course_from_students_teachers(vector<Student>& students, vector<Teacher>& teachers, Course& course)
{
	//get course name
  	string s = course.get_name();

	//to prevent re-writing code, use the higher number between teachers.size() and students.size()
  	for(int i = 0; i < teachers.size() && i < students.size(); i++)
  	{
    	//teachers
    	if(i < teachers.size())
		{
      		if(course.get_instructor() == teachers[i].get_name())
      		{
		  		//erase course from teacher
        		teachers[i].erase_from_course_teaching(s);
      		}
    	}
    	//students
    	if(i < students.size())
    	{
			//get the student's list of courses
      		vector<string> temp = students[i].get_courses_taking();
      		bool check = check_student_course(temp, s);
	  		//erase course from student
      		if(check == true)
        	students[i].erase_from_course_taking(s);
    	}
  	}

}

/*
Type -> non-member function 
Input -> students: vector<Student>&, name: string& 
Output -> i: int
Purpose -> to search for name in students
*/
int search_student(vector<Student>& students, string& name)
{
  for(int i = 0; i < students.size(); i++)
  {
    if(students[i].get_name() == name)
      return i;
  }
  return -1;
}

/*
Type -> non-member function 
Input -> teachers: vector<Teacher>&, name: string& 
Output -> i: int
Purpose -> to search for name in teachers
*/
int search_teacher(vector<Teacher>& teachers, string &name)
{
  for(int i = 0; i < teachers.size(); i++)
  {
    if(teachers[i].get_name() == name)
      return i;
  }
  return -1;
}

/*
Type -> non-member function 
Input -> courses: vector<Course>&, name: string& 
Output -> i: int
Purpose -> to search for name in courses
*/
int search_course(vector<Course>& courses, string &name)
{
  for(int i = 0; i < courses.size(); i++)
  {
    if(courses[i].get_name() == name)
      return i;
  }
  return -1;
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to add a Student to students
*/
void School::admit_student()
{
  if(students.size() == 0)
  {
    Student temp;
    cin >> temp;
    students.push_back(temp);
	cout << temp.get_name() << " has been admitted to " << name << endl;
  }
  else
  {
    string temp_name;
    cout << "Enter Student Name to be admitted: ";
	cin.ignore();
    getline(cin, temp_name);
    int find = search_student(students, temp_name);

    if(find == -1)
    {
		cout << "Press Enter to Continue...."<< endl;
      Student temp;
      cin >> temp;
      students.push_back(temp);
	  cout << temp.get_name() << "has been admitted to " << name << endl;
    }
    else
      cout << temp_name << " has already been admitted." << endl;
  }
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to remove a Student from students
*/
void School::expel_student()
{
  if(students.size() == 0)
  {
    cout << "There is no student in the School yet." << endl;
  }
  else
  {
    cin.ignore();
    string temp_name;
	print_all_students();
    cout << "Enter Student name to be expelled: ";
    getline(cin, temp_name);

    int find = search_student(students, temp_name);

    if(find == -1)
    {
      cout << temp_name << " does not exist." << endl;
    }
    else
    {
		//removing student from all courses
      remove_student_from_all_courses(courses, students[find]);

      students.erase(students.begin() + find);
	  cout << temp_name << " has been expelled." << endl;
    }
  }
}

/*
Type -> behaviour
Input -> none
Output -> none
Purpose -> to add a Teacher to teachers
*/
void School::hire_teacher()
{
  if(teachers.size() == 0)
  {
    Teacher temp;
    cin >> temp;
    teachers.push_back(temp);
	cout << temp.get_name() << " has been hired to work at " << name << endl;
  }
  else
  {
    cin.ignore();
    string temp_name;
    cout << "Enter Teacher Name to be hired: ";
    getline(cin, temp_name);

    int find = search_teacher(teachers, temp_name);
    if(find == -1)
    {
		cout << "Press Enter to Continue...."<< endl;
      Teacher temp;
      cin >> temp;
      teachers.push_back(temp);
	  cout << temp.get_name() << " has been hired to work at " << name << endl;
    }
    else
      cout << temp_name << " has already been hired." << endl;
  }
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to remove a Teacher from teachers
*/
void School::fire_teacher()
{
  if(teachers.size() == 0)
  {
    cout << "There is no teacher in the School yet." << endl;
  }
  else
  {
    cin.ignore();
    string temp_name;
	print_all_teachers();
    cout << "Enter Teacher name to be fired: ";
    getline(cin, temp_name);

    int find = search_teacher(teachers, temp_name);
    
    if(find == -1)
    {
      cout << temp_name << " does not exist." << endl;
    }
    else
    {
		//removing teacher from all courses
      remove_teacher_from_all_courses(courses, teachers[find]);

      cout << temp_name << " as been fired."<< endl;
      teachers.erase(teachers.begin() + find);
    }
  }
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to add Course to courses
*/
void School::start_course()
{
  if(courses.size() == 0)
  {
    Course temp;
    cin >> temp;
    courses.push_back(temp);
	cout << temp.get_name() << " has been started in " << name << endl;
  }
  else
  {
    string temp_name;
    cout << "Enter Course Name to be started: ";
    getline(cin, temp_name);

    int find = search_course(courses, temp_name);
    if(find == -1)
    {
		cout << "Press Enter to Continue...."<< endl;
      Course temp;
      cin >> temp;
      courses.push_back(temp);
	  cout << temp_name << " has been started in " << name << endl;
    }
    else
      cout << temp_name << " has already been started." << endl;
  }
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to remove a Course from courses
*/
void School::stop_course()
{
  if(courses.size() == 0)
  {
    cout << "No course has been started in the School yet." << endl;
  }
  else
  {
	cin.ignore();
    string temp_name;
	print_all_courses();
    cout << "Enter Course name to be stopped: ";
    getline(cin, temp_name);

    int find = search_course(courses, temp_name);

    if(find == -1)
    {
      cout << temp_name << " does not exist." << endl;
    }
    else
    {
		//remove course from all students and teachers
      remove_course_from_students_teachers(students, teachers, courses[find]);

      cout << temp_name << " has been stopped in " << name << endl;
      courses.erase(courses.begin() + find);
    }
  }
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to display school details
*/
void School::print()
{
  cout << "School Name: " << name << endl;
  cout << "Number of Students: " << students.size() << endl;
  cout << "Number of Teachers: " << teachers.size() << endl;
  cout << "Number of Courses: " << courses.size() << endl;
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to add a student to a course
*/
void School::add_student_to_class()
{
if(students.size() == 0 || courses.size() == 0)
{
	cout << "There are no Classes or Students in " << name << " yet. Add some." << endl;
}
else{
  
  string student_name, class_name;
  int find_s, find_c;

	print_all_students();
	//getting student

	cout << "Enter the name of the student to be added or Q to quit action: ";
	cin.ignore();
    getline(cin, student_name);
    find_s = search_student(students, student_name);
  while(find_s == -1 && !(student_name == "Q" || student_name == "q"))
  {
	cout << "Student not found" << endl;
    cout << "Enter the name of the student to be added or Q to quit action: ";
    getline(cin, student_name);
    find_s = search_student(students, student_name);
  }

	if(!(student_name == "Q" || student_name == "q")){
		print_all_courses();
	//getting course
	cout << "Enter the name of the class  or Q to quit action: ";
    getline(cin, class_name);
    find_c = search_course(courses, class_name);

	while(find_c == -1 && !(class_name == "Q" || class_name == "q"))
	{
		cout << "Class not found" << endl;
		cout << "Enter the name of the class  or Q to quit action: ";
    	getline(cin, class_name);
    	find_c = search_course(courses, class_name);
	}
    
  //add the student to the course
  courses[find_c].add_student(students[find_s]);
}
}
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to remove a student from a course
*/
void School::remove_student_from_class()
{
if(students.size() == 0 || courses.size() == 0)
{
	cout << "There are no Classes or Students in " << name << " yet. Add some." << endl;
}
else{
  string student_name, class_name;
  int find_s, find_c;

	//getting student
	print_all_students();
	cout << "Enter the name of the student to be dropped or Q to quit action: ";
	cin.ignore();
    getline(cin, student_name);
    find_s = search_student(students, student_name);

  while(find_s == -1 && !(student_name == "Q" || student_name == "q"))
  {
	cout << "Student not found" << endl;
    cout << "Enter the name of the student to be dropped or Q to quit action: ";
    getline(cin, student_name);
    find_s = search_student(students, student_name);
  }

	if(!(student_name == "Q" || student_name == "q")){
		print_all_courses();
		//getting class/course
	cout << "Enter the name of the class  or Q to quit action: ";
    getline(cin, class_name);
    find_c = search_course(courses, class_name);

	while(find_c == -1 && !(class_name == "Q" || class_name == "q"))
	{
		cout << "Class not found" << endl;
		cout << "Enter the name of the class  or Q to quit action: ";
    	getline(cin, class_name);
    	find_c = search_course(courses, class_name);
	}
    //drop the student from the course
  courses[find_c].drop_student(students[find_s]);
	}
}
}


/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to assign a teacher to a course
*/
void School::assign_teacher_to_class()
{

if(teachers.size() == 0 || courses.size() == 0)
{
	cout << "There are no Classes or Teachers in " << name << " yet. Add some." << endl;
}
else
{
	string teacher_name, class_name;
  	int find_t, find_c;
	print_all_courses();
	//getting class
	cout << "Enter the class you want to assign a teacher to or Q to quit action: ";
	cin.ignore();
	getline(cin, class_name);
	find_c = search_course(courses, class_name);

	while(find_c == -1 && !(class_name == "Q" || class_name == "q"))
	{
		cout << "Enter the class you want to assign a teacher to or Q to quit action: ";
		getline(cin, class_name);
		find_c = search_course(courses, class_name);
	}

	if(!(class_name == "Q" || class_name == "q")){
		print_all_teachers();
	//getting teacher
	cout << "Enter the teacher you want to assign or Q to quit action: ";
	getline(cin, teacher_name);
	find_t = search_teacher(teachers, teacher_name);
	
	while(find_t == -1 && !(teacher_name == "Q" || teacher_name == "q"))
	{
		cout << "Enter the teacher you want to assign or Q to quit action: ";
		getline(cin, teacher_name);
		find_t = search_teacher(teachers, teacher_name);
	}

	//assign the teacher to the class
	courses[find_c].assign_teacher(teachers[find_t]);
	}
}
}

/*
Type -> mutator
Input -> none
Output -> none
Purpose -> to remove a teacher from a course
*/
void School::remove_teacher_from_class()
{
if(teachers.size() == 0 || courses.size() == 0)
{
	cout << "There are no Classes or Teachers in " << name << " yet. Add some." << endl;
}
else{
	string teacher_name, class_name;
  	int find_t, find_c;
	  print_all_courses();
	//getting class
	cout << "Enter the class you want to remove a teacher from or Q to quit action: ";
	getline(cin, class_name);
	find_c = search_course(courses, class_name);

	while(find_c == -1 && !(class_name == "Q" || class_name == "q"))
	{
		cout << "Enter the class you want to remove a teacher from or Q to quit action: ";
		getline(cin, class_name);
		find_c = search_course(courses, class_name);
	}

	if(courses[find_c].get_instructor() == "empty")
	{
		cout << "There is no teacher teaching this class yet " << endl;
	}
	else if(!(class_name == "Q" || class_name == "q")){
		print_all_teachers();
		//getting teacher
	teacher_name = courses[find_c].get_instructor();
	find_t = search_teacher(teachers, teacher_name);

	
	//removing teacher form course
	courses[find_c].remove_teacher(teachers[find_t]);

	//choice to assign a new teacher
	string assign;
	cout << "Do you want to assign a new teacher now (Y or anything else): ";
	getline(cin, assign);

	if(assign == "Y" || assign == "y")
	{
		cout << "Continue by assign a teacher to this class......" << endl;
		assign_teacher_to_class();
	}
	else
		cout <<"Don't forget to assign a teacher later -> the students would be missing out."<< endl;
	}
}
}

/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print a course
*/
void School::view_course_details()
{
	if(courses.size() == 0)
		cout << "There are no courses yet." << endl;
	else if(courses.size() > 0)
	{
		string name;

		cin.ignore();
		print_all_courses();
		cout << "Enter the name of the Course you want to display: ";
		getline(cin, name);

		int find = search_course(courses, name);

		if(find == -1)
			cout << name << " does not exist." << endl;
		else
			cout << courses[find];
	}
}


/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print a student
*/
void School::view_student_details()
{
	if(students.size() == 0)
		cout << "There are no students yet." << endl;
	else if(students.size() > 0)
	{
		string name;

		cin.ignore();
		print_all_students();
		cout << "Enter the name of the Student you want to display: ";
		getline(cin, name);

		int find = search_student(students, name);

		if(find == -1)
			cout << name << " does not exist." << endl;
		else
			cout << students[find];
	}
}

/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print a teacher
*/
void School::view_teacher_details()
{
	if(teachers.size() == 0)
		cout << "There are no teachers yet." << endl;
	else if(teachers.size() > 0)
	{
		string name;

		cin.ignore();
		print_all_teachers();
		cout << "Enter the name of the Teacher you want to display: ";
		getline(cin, name);

		int find = search_teacher(teachers, name);

		if(find == -1)
			cout << name << " does not exist." << endl;
		else
			cout << teachers[find];
	}
}

/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print all students
*/
void School::print_all_students()
{
	if(students.size() == 0)
	{
		cout << "There are no students yet. Add some." << endl;
	}
	else
	{
		cout << endl;
		cout << "List of Students." << endl;
		for(int i = 0; i < students.size(); i++)
			cout << "\tStudent " << i + 1 << ": " <<  students[i].get_name() << endl;
		cout << endl;
	}
}

/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print all teachers
*/
void School::print_all_teachers()
{
	if(teachers.size() == 0)
	{
		cout << "There are no teachers yet. Add some." << endl;
	}
	else
	{
		cout << endl;
		cout << "List of Teachers." << endl;
		for(int i = 0; i < teachers.size(); i++)
			cout << "\tTeacher " << i + 1 << ": " << teachers[i].get_name() << endl;
		cout << endl;
	}
}

/*
Type -> viewer
Input -> none
Output -> none
Purpose -> to print all courses
*/
void School::print_all_courses()
{
	if(courses.size() == 0)
	{
		cout << "There are no students yet. Add some." << endl;
	}
	else
	{
		cout << endl;
		cout << "List of Courses." << endl;
		for(int i = 0; i < courses.size(); i++)
			cout << "\tCourse " << i + 1 << ": " << courses[i].get_name() << endl;
		cout << endl;
	}
}

/*
Type -> operator overloading
Input -> inn: istream&, school: School&
Output -> inn: istream& 
Purpose -> to allow the use of cin
*/
istream& operator >> (istream& inn, School& school)
{
  cout << "Enter School Name: ";
  getline(inn, school.name);
  
  return inn;
}
