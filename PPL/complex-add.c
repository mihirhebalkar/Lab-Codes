#include<iostream>
using namespace std;

class complex{
	float real,imag;
	
	public:
		void getdata();
        
        //
		complex()
		{
			real=0;
			imag=0;
		}
		
		//parameterized
		complex(float r)
		{
			real=r;
			imag=r;
		}
		
		complex(float r, float i)
		{
			real=r;
			imag=i;
		}
		
		
		//Copy Constructor
		complex(complex &c)
		{
			real=c.real;
			imag=c.imag;
		}
		
		friend complex add(complex, complex);
		
		void display_sum(complex sum);
		 	
};
void complex :: getdata()
{
	cout<<"Enter real part of number : ";
	cin>>real;
	cout<<"Enter imaginary part of number : ";
	cin>>imag;
}

void complex :: display_sum(complex sum)
{
	if(sum.imag>=0)
	{
		cout<<"\nSum: "<<sum.real<<"+ "<<sum.imag<<" i\n"<<endl;
	}
	else
	{
		cout<<"\nSum: "<<sum.real<<" "<<sum.imag<<" i\n\n";
	}
}
complex add(complex c1, complex c2)
{
	complex sum;
	sum.real=c1.real+c2.real;
	sum.imag=c1.imag+c2.imag;
	return sum;
}

int main()
{
	complex n3,summ;
	int opt=0;
	while(opt!=4)
	{
		cout<<"Option 1: Using constructor\nOption 2: Using parameterized constructor\nOption 3: Using friend functions\nOption 4: Exit";
		cout<<"\nEnter option : ";
		cin>>opt;
		switch(opt)
		{
			case 1:{
				
				complex n1(3);
				complex n2(4);
				n3=add(n1,n2);
				summ.display_sum(n3);
				break;
			}
			case 2:{
				complex n1(3.2,4.1);
				complex n2(8.5,4.8);
				n3=add(n1,n2);
				summ.display_sum(n3);
				break;}
				
			case 3:{
				complex n1,n2;
				n1.getdata();
				n2.getdata();
				n3=add(n1,n2);
				summ.display_sum(n3);
				break;
			}
			
			case 4:
				break;
				
			default:
				cout<<"No such option!";
				break;
		}
		cout<<"\n\nExited";
	
	}
}
