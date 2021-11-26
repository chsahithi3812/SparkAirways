#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<string>
#include "sparkairways.h"
using namespace std;
int reserve = 999;
#define size 100
int seat[size];
void seat_fill()
{
	for (int i = 0; i < size; i++)
	{
		seat[i] = 0;
	}
}

bool taken=false;
void seat_no(int y)
{

        for (int i = 0; i < size; i++ )
        {
                if( seat[i] == -1 )
                {
				taken=true;
  	                 cout << "oops!looks like the seat was booked already \n";
                        cout << "Please choose another seat number from below."<<endl;

				int j = 1;
				while ( j < size+1 )
				{
					if ( seat[j-1] == -1)
					j++;
					else
					{
						cout <<"|" << j << "|";
						if ( j%10 == 0 )
						cout << endl;
						j++;
					}

                		}
		}
        }
		
}

void menu()
{
int choice;

do{
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [1]Make Reservation";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [2]Cancel Reservation";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [3]Search Passenger";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [4]Change Reservation";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [5]Print a list";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [6]Print status Report ";
cout<<"\n   ----------------------------------------------"<<endl;
cout <<"\t [7]Quit ";
cout<<"\n   ----------------------------------------------"<<endl;
cout<<"\n   -------------------------------------------------------------------------------------------"<<endl;

cout <<"  Enter your choice : ";

	cin >> choice;

	switch (choice)
	{
	case 1: system("CLS"); sparkairways.make_reservation();
					break;
	case 2: system("CLS"); sparkairways.cancel_reservation();
					break;
	case 3: system("CLS"); sparkairways.search_passenger();
					break;
	case 4: system("CLS"); sparkairways.change_reservation();
					break;
	case 5: system("CLS"); sparkairways.print_list();
					break;
	case 6: system("CLS"); sparkairways.print_report();
					break;
	case 7: cout << "\n\nThank you come again\n\n\n";
					break;

	default: cout<<"YOU DESERVE TO FLY HIGH!!\n\n";
		break;


	}	


	cout<<"\nPROCESS COMPLETED.PRESS ENTER TO SEE THE MENU\n\n";

	cin.get();
	if(cin.get()=='\n')
		system("CLS");


	cout<<"\n   -------------------------------------------------------------------------------------------"<<endl;
	cout << "\t SPARKAIRWAYS--AIRLINE RESERVATION SYSTEM \n";
	cout<<"\n   -------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n   -------------------------------------------------------------------------------------------"<<endl;

 }while(choice != 7 );

}
airlines::airlines()
{
	start = NULL;
}

void airlines:: make_reservation()
{
	int meal_choice, x,a,b,stat,found=0,asize=5;
	string org;
	string dest;
	string local_des[5]={"HYDERABAD","KOLKATA","GWALIOR","DELHI","MUMBAI"};
	string inter_des[5]={"USA","PARIS","DUBAI","LAS VEGAS","LONDON"};


	temp = new node;

	cout<<"\n\n   Enter First Name of person: ";
	cin>>temp->fname;
	cout<<"   Enter Last Name of Person: ";
	cin>>temp->lname;
	cout<<"   Enter ID of the person: ";
	cin>>temp->ID;
	cout<<"   Enter Phone Number of Person: ";
	cin>>temp->phone_num;
	do{
	cout << "Please Enter the Seat Number You want to book: ";

		cin>>x;
		while(x>size){
		cout<<"   Try again:: ";
		cin >>x;
		}

		if((seat[x-1])>-1)
		taken = false;
		else
		seat_no(x);
	seat[x-1] = -1;
	temp->seat_num = x;

	}while(taken==true);
		cout << "   Please Enter Your Menu Preference from below: \n\n";
		cout << "      Veg     ..... '1'\n";
		cout << "      Non-Veg ..... '2'\n";
		cout << "      No meal ..... '3'\n\n";

		cout <<"   Your Choice :: ";
		cin >> meal_choice;

		while(meal_choice>3 || meal_choice<1){
		cout<<"   Try Again:: ";
		cin>>meal_choice;
		}

		if (meal_choice == 1)
		temp->menu = "veg";

		else if (meal_choice == 2)
		temp->menu = "Non-Veg";

		else
		temp->menu = "No meal";




	reserve++;
	temp->reserve_num=reserve;
	cout <<"   YOUR RESERVATION NUMBER IS :: " << reserve << "\n";
    char option;
    cout<<"\n   ----------------------------------------------"<<endl;
	cout<<"\nPlease select your origin type:\n";
	cout<<"1.Local Origins\n";
	cout<<"2.International Origins\n";
	cout<<"\nENTER YOUR CHOICE(1 or 2)\n";
	cin>>option;
    stat=0;
	switch(option){
		case '1':
	    for(a=0;a<asize;a++){
			cout<<local_des[a]<<"\n";
		}
		cout<<"Now Enter Your origin(IN BLOCK LETTERS):";
		cin.ignore();
		getline(cin,org);
		 
		 
		for(int i=0;i<asize;i++){
			if(org==local_des[i]){
				for(int j=i; j<(asize-1); j++)
                local_des[j] = local_des[j+1];
               found++;
                i--;
                asize--;
			if(found==0){
				cout<<"INVALID ORIGIN";
			}
			else{
			   cout<<"Your destinations are: \n";
			   for(int y=0;y<asize;y++){
				   cout<<local_des[y]<<"\n";
			   }
			   cout<<"Enter your destination(IN BLOCK LETTERS):";
			    cin>>dest;
			   for(int z=0;z<asize;z++){
				   if(dest==local_des[z]){
						cout<<"ORIGIN AND DESTINATION CONFIRMED!\n";
                    }
			   }	
			}
			stat=1;
			break;

			}
			else{
				stat=0;
			}
		
		}
		if(stat==1){
			 cout<<"TICKET BOOKED SUCCESSFULLY!\n";
			temp->from=org;
			temp->to=dest;
		}	
		else{
           cout<<"INVALID DESTINATION\n";
		}
		break;


		case '2':
		for(b=0;b<asize;b++){
			cout<<inter_des[b]<<"\n";
		}
		cout<<"Now Enter Your origin(IN BLOCK LETTERS):";
		cin.ignore();
		getline(cin,org);
		 
		 
		for(int i=0;i<asize;i++){
			if(org==inter_des[i]){
				for(int j=i; j<(asize-1); j++)
                inter_des[j] = inter_des[j+1];
               found++;
                i--;
                asize--;
			if(found==0){
				cout<<"INVALID ORIGIN";
			}
			else{
			   cout<<"Your destinations are: \n";
			   for(int y=0;y<asize;y++){
				   cout<<inter_des[y]<<"\n";
			   }
			   cout<<"Enter your destination(IN BLOCK LETTERS):";
			   cin>>dest;
			   for(int z=0;z<asize;z++){
				   if(dest==inter_des[z]){
						cout<<"ORIGIN AND DESTINATION CONFIRMED!\n";
                    }
			   }	
			}
			stat=1;
			break;

			}
			else{
				stat=0;
			}
		
		}
		if(stat==1){
			cout<<"TICKET BOOKED SUCCESSFULLY!\n";
			temp->from=org;
			temp->to=dest;
			 
		}	
		else{
           cout<<"INVALID DESTINATION\n";
		}
		 
        break;

		default:
		cout<<"INVALID OPTION";
	} 
	temp->next = NULL;

	if(start == NULL)
		start = temp;
	else
	{
		temp2 = start;
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
	}
int cancel=0;
void airlines:: cancel_reservation()
{	int num;
	cout << "Please Enter your reservation Number here: ";
	cin >> num;

		node *cur = start;
		if(cur!=NULL)
		{

		if ( start->reserve_num == num )
		{
			node *del = start;
			start = start->next;
			delete del;
			seat[0] = 0;
			cancel++;
			return;
		}
		else
		{
			node *pre, *cur;
			pre = start;
			cur = start->next;
			while(cur != NULL)
			{
				if ( cur->reserve_num == num )
						break;
				pre = cur;
				cur = cur->next;
			}
			seat[cur->seat_num-1] = 0;
			if (cur != NULL )
			pre->next = cur->next;

		}

	cancel++;

		}
		else
		{
		cout<<"!!! *** Nothing to delete or invalid entry *** !!! \n"<<endl;
		}

}
void airlines:: search_passenger()
{
		string fakename;
		cout << "Please enter your first name here: ";
		cin >> fakename;

		node *cur = start;
		while (cur != NULL)
		{
			if (cur->fname == fakename)
			{
				cout << "First Name : " << cur->fname << endl;
				cout << "Last Name : " << cur->lname << endl;
				cout << "ID " << cur->ID << endl;
				cout << "Phone number: " << cur->phone_num << endl;
				cout << "Seat Number: " << cur->seat_num << endl;
				cout << "Reservation No. " << cur->reserve_num<< endl;
				cout<<"From: "<<cur->from<<endl;
				cout<<"To: "<<cur->to<<endl;
				return;
			}	cur = cur->next;
		}	cout << " Sorry!!! NOT FOUND \n\n";

}
void airlines:: change_reservation()

{
	int option , next_seat;
	cout << " Please enter your seat number: ";
	cin >> option;
	node *cur;
	cur = start;

	while(cur != NULL)
	{
		if ( cur->seat_num == option )
			break;
		cur = cur->next;
	}
	cout << "Please choose another seat number from below.";
		int j = 1;
		while ( j < size+1 )
		{
			if ( seat[j-1] == -1)
			j++;
			else
			{
			cout <<"| " << j << "|";
			if ( j%10 == 0 )
			cout << endl;
			j++;
			}
		}
	cin >> next_seat;
	seat[cur->seat_num-1]=0;
	cur->seat_num = next_seat;
	seat[next_seat-1] = -1;

}
void airlines:: print_list()
{
	temp=start;
	if(temp == NULL)
	cout<<" End of lists"<<endl;
	else
	{	int cnt = 1;
		cout << "\tNumber\t First Name\t Last Name\t ID\t";
		cout << "Phone Number\t Seat Number\t Reservation No\t\t From\t\t To \t\t\tMenu\n";

		while(temp != NULL)
		{
			cout << "\t" << cnt<<setw(15);
			cout << temp->fname <<setw(15) ;
			cout << temp->lname <<setw(15) ;
			cout << temp->ID <<setw(15) ;
			cout << temp->phone_num <<setw(15) ;
			cout << temp->seat_num <<setw(15) ;
			cout << temp->reserve_num <<setw(15) ;
			cout<<temp->from<< setw(15);
			cout<<temp->to<<setw(15) ;
			cout << temp->menu << "\n";

			temp=temp->next;
			cnt++;
		}
		cout << "\n\n";

	}
}
void airlines:: print_report()
{	int count = 0;
	for (int i =0; i < size; i++ )
	{
		if (seat[i] == -1)
			count++;
	}
	cout<<"The number of reserved seats are: " << count <<endl;
	cout<<"The number of cancellations are: " << cancel <<endl;
}




