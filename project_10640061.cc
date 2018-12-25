#include <iostream>
#include <string>

using namespace std;


struct courseInfo{
	string courseName;
	string courseGrade;
	struct courseInfo *next;
};
struct studentData{
	string firstName;
	string lastName;
	int admNo;
	string grade;
	struct studentData *next;
};

struct staffData {
	string firstName;
	string lastName;
	string exp;
	string phone;
	struct staffData *next;
};

struct courseInfo *insertCourse(struct courseInfo *root){
	struct courseInfo *temp = new struct courseInfo;
	cout<<"Enter the name of the course: "<<endl;
	cin>>temp->courseName;
	cout<<"Enter the grade of the course: "<<endl;
	cin>>temp->courseGrade;
	temp->next=NULL;
	if(root==NULL)
		root=temp;
	else
		temp->next=root;
		root=temp;
	cout<<endl;
	return root;
}

struct studentData *insertStudent(struct studentData *root){
	struct studentData *temp = new struct studentData;
	cout<<"Enter the first name of student: "<<endl;
	cin>>temp->firstName;
	cout<<"Enter the last name of student: "<<endl;
	cin>>temp->lastName;
	cout<<"Enter admission no: "<<endl;
	cin>>temp->admNo;
	temp->next=NULL;
	if(root==NULL)
		root=temp;
	else
		temp->next=root;
		root=temp;
	cout<<endl;
	return root;
}

struct staffData *insertStaff(struct staffData *root){
	struct staffData *temp = new struct staffData;
	cout<<"Enter the first name of staff: "<<endl;
	cin>>temp->firstName;
	cout<<"Enter the last name of staff: "<<endl;
	cin>>temp->lastName;
	cout<<"Enter the staff phone number: "<<endl;
	cin>>temp->phone;
	temp->next=NULL;
	if(root==NULL)
		root=temp;
	else
		temp->next=root;
		root=temp;
	cout<<endl;
	return root;
}

void deleteCourseInfo(struct courseInfo *root){
	string courseName;
	struct courseInfo *temp=NULL;
	struct courseInfo *prevTemp=NULL;
	cout<<"Enter the name of the course you want to delete: ";
	cin>>courseName;


	while(root!=NULL){
		if(root->courseName==courseName){
			temp=root;
			break;
		}
		else{
			prevTemp=root;
			root=root->next;
		}
	}
	prevTemp->next=temp->next;
	delete(temp);
}
void deleteStudentData(struct studentData *root){
	string firstName;
	struct studentData *temp=NULL;
	struct studentData *prevTemp=NULL;
	cout<<"Enter the First name of student you want to delete: ";
	cin>>firstName;


	while(root!=NULL){
		if(root->firstName==firstName){
			temp=root;
			break;
		}
		else{
			prevTemp=root;
			root=root->next;
		}
	}
	prevTemp->next=temp->next;
	delete(temp);
}
void deleteStaffData(struct staffData *root){
	string firstName;
	struct staffData *temp=NULL;
	struct staffData *prevTemp=NULL;
	cout<<"Enter the First name of staff you want to delete: ";
	cin>>firstName;

	while(root!=NULL){
		if(root->firstName==firstName){
			temp=root;
			break;
		}
		else{
			prevTemp=root;
			root=root->next;
		}
	}
	prevTemp->next=temp->next;
	delete(temp);
}

void displayCourse(struct courseInfo *root){
	cout<<endl;
	cout<<"\t**\tCourse Details\t**\t"<<endl;
	while(root!=NULL){
		cout<<root->courseName<<" "<<root->courseGrade<<" "<<endl;
		root=root->next;
	}
	cout<<endl;
}

void displayStudent(struct studentData *root){
	cout<<endl;
	cout<<"\t**\tStudent Details\t**\t"<<endl;
	while(root!=NULL){
		cout<<root->firstName<<" "<<root->lastName<<" "<<root->admNo<<" "<<endl;
		root=root->next;
	}
	cout<<endl;
}
void displayStaff(struct staffData *root){
	cout<<endl;
	cout<<"\t**\tStaff Details\t**\t"<<endl;
	while(root!=NULL){
		cout<<root->firstName<<"\t"<<root->lastName<<"\t"<<root->phone<<"\t"<<endl;
		root=root->next;
	}
	cout<<endl;
}
int main() {
	struct courseInfo *courseHead = NULL;
	struct studentData *studentHead = NULL;
	struct staffData *staffHead = NULL;
	cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout<<"\n\n\t\t\tSCHOOL MANAGEMENT PROGRAM\n\n";
	cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout<<"\n\n\t\t\tMAIN SCREEN\n\n";
	cout<<"Enter your choice: "<<endl;
	cout<<"1 to Add or Delete course"<<endl;
	cout<<"2 to Add or Delete student"<<endl;
	cout<<"3 to Add or Delete staff"<<endl;
	cout<<"4 to Print academic record"<<endl;
	cout<<"5 to exit"<<endl<<endl;
	int choice;
	cin>>choice;
	while(choice!=5) {
		if(choice==1) {
			int option;
			cout<<"\t1 to Add course"<<endl;
			cout<<"\t2 to Delete courseInfo"<<endl;
			cin>>option;
			if(option==1)
				courseHead = insertCourse(courseHead);
			else if(option==2)
				deleteCourseInfo(courseHead);
			else
				cout<<"Invalid Input"<<endl;

		}
		if(choice==2) {
			int option;
			cout<<"\t1 to Add student"<<endl;
			cout<<"\t2 to Delete student"<<endl;
			cin>>option;
			if(option==1)
				studentHead = insertStudent(studentHead);
			else if(option==2)
				deleteStudentData(studentHead);
			else
				cout<<"Invalid Input"<<endl;


		}
		if(choice==3) {
			int option;
			cout<<"\t1 to Add staff"<<endl;
			cout<<"\t2 to Delete staff"<<endl;
			cin>>option;
			if(option==1)
					staffHead = insertStaff(staffHead);
			else if(option==2)
				deleteStaffData(staffHead);
			else
				cout<<"Invalid Input"<<endl;



		if(choice==4) {
			int option;
			cout<<"\t1 to display course info"<<endl;
			cout<<"\t2 to diaplay student data"<<endl;
			cout<<"\t3 to diaplay staff data"<<endl;
			cin>>option;
			if(option==1)
				displayCourse(courseHead);
			else if(option==2)
				displayStudent(studentHead);
			else if(option==3)
				displayStaff(staffHead);
			else
				cout<<"Invalid Input"<<endl;

		}

		}
		cout<<"Enter your choice: "<<endl;
		cout<<"1 to Add or Delete course"<<endl;
		cout<<"2 to Add or Delete student"<<endl;
		cout<<"3 to Add or Delete staff"<<endl;
		cout<<"4 to Print academic record"<<endl<<endl;
		cout<<"5 to exit"<<endl;
		cin>>choice;
	}
	cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout<<"\n\n\t\t\tTHANK FOR!\t\t\t\n\n";
	cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout<<endl;

	return 0;
}
