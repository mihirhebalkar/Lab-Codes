#include<iostream>

using namespace std;

class complex{
	int real, img;
	
	public:
		
		void display()
		{
			if(img>=0)
			{
				cout<<"\n"<<real<<"+"<<img<<"i";
		    }
		    else
		    {
		    	cout<<"\n"<<real<<" "<<img<<"i";
			}
		}
		void get_data()
		{
			cout<<"Enter number (a+bi): ";
			cin>>real>>img;
		}
		
		
		void operator ++()
		{
			++real;
			++img;
		}

		
		bool operator <(complex d)
		{
			if(real<d.real)
			{
				return true;
			}
			if(real==d.real && img<d.img)
			{
				return true;
			}
			return false;
		}
		
		bool operator >(complex d)
		{
			if(real>d.real)
			{
				return true;
			}
			if(real==d.real && img>d.img)
			{
				return true;
			}
			return false;
		}
		
		complex operator +(complex m)
		{
			complex temp;
			temp.real=m.real+real;
			temp.img=m.img+img;
			return temp;
		}
		
		void operator --()
		{
			real--;
			img--;
		}
	
		
};
int main()
{
	int choice=0;
	
	while(choice!=5)
	{
		cout<<"\nMenu"<<endl;
		cout<<"Enter 1 to increment complex number"<<endl;
		cout<<"Enter 2 to decrement complex number"<<endl;
		cout<<"Enter 3 to compare two complex numbers"<<endl;
		cout<<"Enter 4 to add two complex numbers"<<endl;
		cout<<"Enter 5 to exit"<<endl;
		
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:{
				complex c;
				c.get_data();

				cout<<"\nBefore incrementing : ";
				c.display();
				cout<<"\nAfter incrementing : ";
				++c;
				c.display();
				break;
			}
			
			case 2:{
				complex c;
				c.get_data();

				cout<<"\nBefore decrementing : ";
				c.display();
				cout<<"\nAfter decrementing : ";
				--c;
				c.display();
				break;
			}
			
			case 3:{
				complex c1,c2;
				cout<<"Enter data for 1st complex number : "<<endl;
				c1.get_data();
				cout<<"Enter data for 2nd complex number : "<<endl;
				c2.get_data();
				cout<<"Greater number is : ";
				if(c1>c2)
				{
					c1.display();
				}
				if(c2>c1)
				{
					c2.display();
				}
				else
				{
					cout<<"\nBoth numbers are equal";
				}
				
				break;
			}
			
			case 4:{
				complex c1,c2,c3;
				cout<<"Enter data for first number"<<endl;
				c1.get_data();
				cout<<"Enter data for second number"<<endl;
				c2.get_data();	
				
				//Overloading
				c3=c1+c2;
				cout<<"The sum is : ";	
				c3.display();		
				break;
			}
			
			case 5:{
				break;
			}			
			
		}
	}
	cout<<"\nExited";
	return 0;
}
