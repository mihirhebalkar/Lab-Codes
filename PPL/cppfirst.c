#include<iostream>
#include<stdlib.h>
using namespace std;

class student{
	
	public:
		char name[100];
		int prn;
	    float marks[5];
	    float per;
		float perc(){
		   int i;
		   float sum=0;
		   for(i=0;i<5;i++)
		   {
		       cout<<"Enter marks of subject "<<i+1<<": ";
		       cin>>marks[i];
		       sum+=marks[i];
		   }
		   per=sum/5;
		   return per;
		}
		char* Name(){
			cout<<"Enter name : ";
			cin>>name;
			return name;
		}
		
		int Prn(){
			cout<<"Enter PRN : ";
			cin>>prn;
			return prn;
		}
		
		void table(){
			cout<<name<<"\t"<<prn<<"\t"<<per<< endl;
		}
}s1,s2,s3,s4,s5;

int main()
{
	cout<<"Enter details of student 1"<<endl;
    s1.Name();
	s1.Prn();
	s1.perc();
	
	cout<<"Enter details of student 2"<<endl;
	s2.Name();
	s2.Prn();
	s2.perc();
	
	cout<<"Enter details of student 3"<<endl;
	s3.Name();
	s3.Prn();
	s3.perc();
	
	cout<<"Enter details of student 4"<<endl;
	s4.Name();
	s4.Prn();
	s4.perc();
	
	cout<<"Enter details of student 5"<<endl;
	s5.Name();
	s5.Prn();
	s5.perc();
	
	system("cls");
	
    cout<<"Name\tPRN\tPercentage"<<endl;
	s1.table();
	s2.table();
	s3.table();
	s4.table();
	s5.table();
	
	return 0;
}
