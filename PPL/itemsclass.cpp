#include<iostream>

using namespace std;

class cart{

	int count;
	int code[50];
	float quantity[50];
	//del
	float price[50];
	
	float total[50];
	float gtotal;
	
	public:
		int rcode[100]={151,45,65,89,45,21};
	    float rprice[100]={200,45,900,80,20,100};
		void cntzero()
		{
			count=0;
		}
		
		void get_items()
		{
			cout<<"Enter number of items to add : ";
			cin>>count;
		
			for(int i=0;i<count;i++)
			{
				cout<<"Enter item code for item "<<i+1<<": ";
				cin>>code[i];
				
				cout<<"Enter item quantity for item "<<i+1<<": ";
				cin>>quantity[i];
				
				for(int j=0;j<6;j++)
				{
					if(rcode[j]==code[i])
					{
						price[i]=rprice[j];
					}
				}

			}
			
		}
		
		void total_pq()
		{
			gtotal=0;
			for(int i=0;i<count;i++)
			{
				total[i]=0;
				total[i]=quantity[i]*price[i];
				gtotal+=total[i];
			}
		}
		
		void delete_item()
		{
			int dcode;
			//Delete all things assosciated with item
			cout<<"Enter item code to delete : ";
			cin>>dcode;
			int i;
			for(i=0;i<count;i++)
			{
				if(code[i]==dcode)
				{
					break;
				}
			}
			if(i<count)
			{
				count=count-1;
				gtotal=gtotal-total[i];
				for(int j=i;j<count;j++)
				{
					//Shifting array element to previous location
					code[j]=code[j+1];
					quantity[j]=quantity[j+1];
					price[j]=price[j+1];
					total[j]=total[j+1];
				}
			}
		}
		
		void display()
		{
			cout<<"\n\nITEM LIST";
			cout<<"\n\nCode\tQuantity\tPrice\tTotal\n\n";
			for(int i=0;i<count;i++)
			{
				cout<<code[i]<<"\t"<<quantity[i]<<"\t\t"<<price[i]<<"\t"<<total[i]<<"\n";
			}
			cout<<"Grand Total : "<<gtotal<<endl;
		}
};



int main()
{
	int opt=0;
	
	while(opt!=4)
	{
		//Menu
		cout<<"\nMENU\nEnter 1 to Add Item info\n";
		cout<<"Enter 2 to Delete Item info\n";
		cout<<"Enter 3 to Display all items\n";
		cout<<"Enter 4 to Exit\n";
		
		cout<<"Enter option : ";
		cin>>opt;
		
		cart item;
		switch(opt)
		{
			case 1:
				cout<<"Code\tPrice\n";
				for(int i=0;i<6;i++)
				{	
					cout<<item.rcode[i]<<"\t"<<item.rprice[i]<<"\n";
				}
				item.get_items();
				item.total_pq();
				break;
			case 2:
				item.delete_item();
				break;
			case 3:
				item.display();
				break;
			case 4:
				break;
			default:
				cout<<"Enter valid option";
		}
	}
	cout<<"\nExited!!"<<endl;
	
}
