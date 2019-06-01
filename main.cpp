//including School header file
#include "School.h"

//function declaration
int display();
void action(School& sch, int& x);

//main function
int main() 
{
	School sch;
	cin >> sch;
	int x;

	x = display();
	do
	{
		if(x >=1 && x <=14)
			action(sch, x);
		else if(x == 0)
			return 0; 

		//system("cls");
		x = display();

	}while(x != 0 || x == -1);

	return 0;
}

/*
Name: display(): int
Input -> none
Output -> choice: int
Purpose -> to display a menu and return the user's choice
*/
int display()
{
	int choice;
	string p;

	cout << endl << "1. Admit a Student to the School" << endl;
	cout << "2. Expel a Student from the School" << endl;
	cout << "3. Hire a teacher" << endl;
	cout << "4. Fire a teacher" << endl;
	cout << "5. Start a new Course" << endl;
	cout << "6. Stop a Course" << endl;
	cout << "7. Add a student to a class" << endl;
	cout << "8. Drop a student from a class" << endl;
	cout << "9. Assign a teacher to teach a class" << endl;
	cout << "10. Stop a teacher from teaching a class" << endl;
	cout << "11. View the details of a particular student" << endl;
	cout << "12. View the details of a particular teacher" << endl;
	cout << "13. View the details of a particular course" << endl;
	cout << "14. Print School Details." << endl;
	cout << "15. Quit program!!!" << endl;

	cout << endl << "Enter Choice of action: ";
	cin >> p;

	if(p.size() == 2)
	{
		choice = int(p[0]) - int('0');
		choice *= 10;
		choice += int(p[1]) - int('0');
	}
	else if (p.size() == 1)
	{
		choice = int(p[0]) - int('0');
	}

	//return
	if((isalpha(p[0]) || isalpha(p[1])))
	{
		cout << "Invalid Input!!!" << endl;
		return 16;
	}
	else if(choice == 15)
	{
		string sure;
		cout << "Are you sure you want to quit (Y or anything else): ";
		cin >> sure;

		if(sure == "Y" || sure == "y")
		{
			cout << "Bye...." << endl;
			return 0;
		}
		else
		{
			cout << "Continue....." << endl;
			return -1;
		}
	}
	else if(choice < 1 || choice > 15)
	{
		cout << "Invalid Input!!!" << endl;
		return 16;
	}
	return choice;
}

/*
Name: action(): void
Input -> sch: School&, x: int& 
Output -> none
Purpose -> to implement the user's choice
*/
void action(School& sch, int& x)
{
	cout << endl << endl << "********************************************" << endl;

	switch(x)
	{
		case 1: cout << "Student Admission" << endl; sch.admit_student(); break;
		case 2: cout << "Student Expulsion" << endl; sch.expel_student(); break;
		case 3: cout << "Teacher Employment" << endl; sch.hire_teacher(); break;
		case 4: cout << "Teacher Employment Termination" << endl; sch.fire_teacher(); break;
		case 5: cout << "Course Commencement" << endl;  sch.start_course(); break;
		case 6: cout << "Course Termination" << endl;  sch.stop_course(); break;
		case 7: cout << "Adding Student to Course" << endl; sch.add_student_to_class(); break;
		case 8: cout << "Dropping Student from Course" << endl; sch.remove_student_from_class(); break;
		case 9: cout << "Assigning Teacher to Course" << endl; sch.assign_teacher_to_class(); break;
		case 10: cout << "Removing Teacher from Course" << endl; sch.remove_teacher_from_class(); break;
		case 11: cout << "Student Details" << endl; sch.view_student_details(); break;
		case 12: cout << "Teacher Details" << endl;sch.view_teacher_details(); break;
		case 13: cout << "Course Details" << endl;sch.view_course_details(); break;
		case 14: cout << "School Details" << endl;sch.print(); break;
	}

	cout << "********************************************" << endl;
}
