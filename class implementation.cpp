#include<iostream>
using namespace std;

class student
{
	private:
		char name[100];
		int rollno;
		float cgpi;
        int sem;
	public:
        student(){}
		void input();
		void display();
		void filter(float );
};
void student::input()
{
	cout<<"Enter Name:";
	cin>>name;
	cout<<"Enter Roll No.:";
	cin>>rollno;
	cout<<"Enter CGPI:";
	cin>>cgpi;
	cout<<"Enter Semester:";
	cin>>sem;
}
void student::display()
{
	cout<<"Name :"<<name<<endl;
	cout<<"Roll No. :"<<rollno<<endl;
	cout<<"CGPI :"<<cgpi<<endl;
	cout<<"Semester :"<<sem<<endl;
}

void student:: filter(float reqcgpi)
{
       if(cgpi>=reqcgpi)
       student::display();
}

int main()
{
    int n;
    cout<<"Enter the no of students :";
    cin>>n;
    student s[n];
    float cg;
    for(int i =0; i < n; i++)
    {
        cout<<"Enter details of student " << i+1 << ":" <<endl;
        s[i].input();
        cout<<endl;
    }

    for(int i = 0; i < n; i++){
        cout<<"Details of student " << (i+1) << endl;
        s[i].display();
        cout<<endl;
    }
    cout<<"What is the minimum CGPI criteria?"<<endl;
    cin>>cg;
    cout<<"List of students having the required CGPI.";
    for(int i=0 ; i < n; i++){
        s[i].filter(cg);
        cout<<endl;
    }
    return 0;
}