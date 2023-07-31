// standard libraries
#include <iostream>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
//#include<windows.h>
#include<time.h>
#include <thread>
#include <chrono>

using namespace std;

#ifdef _WIN32
const char* clearScreen = "CLS"; // Sistema Windows
#else
const char* clearScreen = "clear"; // Sistema Unix/Linux
#endif

void pause() {
    cout << "Press Enter to continue...\n";
	cin.ignore();
    string line;
    getline(cin, line); // Leer una línea del usuario (pausa en cualquier sistema)
}

class logged_IN{//clase base
	public:
	void loadingbar(void);//para hacer la barra de carga
	void pwelcom();//para hacer la página de bienvenida
	bool loggedin();//para iniciar sesión
};

class order : public logged_IN{
	public:
	void take_order();//realizar una orden
	void order_list();//para mostrar el orden
	void delete_order();//para eliminar el pedido
	void modify(); //para modificar el pedido
};	
class summary : public order{
	public:
	void daily_summary(); //para mostrar el resumen diario
	void exit(); 
};

bool logged_IN :: loggedin(){
	string username,password,un,pw;
	cout<<"\n\t\tEnter username :";
	cin>>username;
	cout<<"\n\t\tEnter password :";
	cin>>password;
	ifstream read ("login.txt");
	getline(read,un);
	getline(read,pw);

	if(un == username && pw == password){
		return true;
	}
	else{
		return false;
	}
}

void logged_IN  :: loadingbar(void){

	for (int i=15;i<=100;i+=5){

		system(clearScreen);

		cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<"Loading..."<<i;

		cout<<"";

		for (int j=0; j<i;j+=2){

			cout<<" ";
			
		}
		this_thread::sleep_for(chrono::milliseconds(100));
		//if(i==90 || i==50 || i==96 || i==83){
		//	this_thread::sleep_for(chrono::milliseconds(100));
		//}

	}
	system(clearScreen);


}
void logged_IN :: pwelcom(){
	char welcome[50]="WELCOME";char welcome2[50]=" TO";char welcome3[50]=" LIFE LINE PHARMACY";
	char welcome4[50]=" MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n\n\t\t\t";
	for(int wlc=0; wlc<strlen(welcome);wlc++){
		cout<<welcome[wlc];
		//this_thread::sleep_for(chrono::milliseconds(100));
	}
	
	cout<<"\n\n\t\t\t\t ";
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
		cout<<welcome2[wlc2];
		//this_thread::sleep_for(chrono::milliseconds(100));
	}
	
	cout<<"\n\n\n\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){
			cout<<welcome3[wlc3];
		}
		else{
			cout<<welcome3[wlc3];
		}

		//this_thread::sleep_for(chrono::milliseconds(100));
	}

	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
			cout<<welcome4[wlc3];
		}
		else{
			cout<<welcome4[wlc3];
		}
		//this_thread::sleep_for(chrono::milliseconds(100));
	}
	cout<<"\n\n\t\t";
	pause();
}
struct node  //link list
{
	int recipt_number;
	string coustumername;
	string date;
	int quantity[10];
	string type={"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 
}*q, *temp;	

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;       

int main(){

	//system("mode 160");
	//a://goto
	system("color f4");
    summary medi;
	medi.loadingbar();
	int choice;
	cout<<"\n\n\t\t\t\t======WELCOME======"<<endl;
	cout<<"\n\n\t\t\t\t====PLEASE LOGIN===="<<endl;
	cout<<"\n\t\t\t************************\n";
	cout<<"\n\t\t\t1: Register\n\n\t\t\t2: login\n\n\t\t\tYour choice:";cin >> choice;
	system(clearScreen);
	cout<<"\n\t\t\t************************\n";
	
	if(choice == 1){
		string username,password;
		cout<<"\n\tSelect a username: ";cin>>username;
		cout<<"\n\tSelect a password: ";cin>>password;
		ofstream file;
		file.open("login.txt");
		file << username << endl << password;
		file.close();
		main();
	}

	else if(choice == 2){
		bool status = medi.loggedin();
		if(!status){
			cout<<"\n\t\tFalse Login!"<<endl;
			pause();
			return 0;
		}
		else{
			cout<<"\n\t\tSuccessfully logged in !"<<endl;
			pause();			
		}
	}

	medi.loadingbar();
	medi.pwelcom();
	medi.loadingbar();
	int menu;
	do{
		system(clearScreen);
		cout<<"\t\t================================================\n\n";
		cout<<"\t\t\t    Pharmacy Management System \n\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu){

			case 1:{
				system(clearScreen);
				medi.take_order();
				medi.loadingbar();	//funcion add
				break;
			}	//end case 1
		
			case 2:{
				medi.delete_order();	//funcion delete
				pause();
				break;
			}	//end case 2
				
			case 3:{
				medi.modify();	//funcion modify
				pause();
				break;
			}	//end case 3

			case 4:{
				medi.order_list();	//funcion order
				pause();
				break;
			}	//end case 4
			case 5:{
				medi.daily_summary();	//funcion daily_summary
				pause();
				break;
			}	//end case 5
			case 6:{
				medi.exit();	//funcion exit
				//goto a;
				return 0;
				break;
			}	//end case 6

			default:{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch

	}while(menu!=6);//end do
	
	cout<<"thank you"<<endl;
	pause();
	return 0;
}


void  order:: take_order(){

	int i;
	int choice, quantity, price,None;
	
	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";
	node *temp;
    temp=new node;
	cout <<"**************************************************************************\n";
	cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(RM)"<<endl;
	cout <<"**************************************************************************\n";
    cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			RM 2.00"<<endl;
    cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RM 3.00"<<endl;
    cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		RM 1.00"<<endl;
    cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		RM 4.00"<<endl;
    cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	RM 1.00"<<endl;
    cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
    cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 7.00"<<endl;
    cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			RM 4.00"<<endl;
    cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
    cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
    cout<<" "<<endl;

    temp = new node;
    
	cout<<"\n\t\tType oder no.";
    cin >> temp->recipt_number;
	cout<< "\n\t\tEnter Customer Name: ";
	cin>> temp->coustumername;
	cout<<"\n\t\tEnter Date : ";
	cin>>temp->date;
	cout << "\n\t\tHow many Medicine would you like to order:"<< endl;
	cout<<"\n\t\t( Maximum is 10 order for each transaction ) \n";
	cout << "\t\t" ;
	cin >> temp->x;
	if (temp->x >10){
		cout << "\n\t\tThe Medicine you order is exceed the maximum amount of order !";
		pause();
	}
	else{

		for (i=0; i<temp->x; i++){
			
			cout << "\n\t\tPlease enter your selection : ";
			cin>> temp->menu2[i];
			cout<< "\n\t\tMedicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
			cout << "\n\t\tHow many medicine do you want: ";
			cin >> temp->quantity[i];
			temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
			cout << "\n\t\tThe amount You need to pay is: " << temp->amount[i]<<" RM"<<endl;
			//pause();
						
		}
		
		cout<<"==========================================================================="<<endl;
		cout << "\n\t\tOrder Taken Successfully"<<endl;
		cout<<"==========================================================================="<<endl;
		cout << "\n\t\tGo to Reciept Menu to Pay The Bill"<<endl;
		cout<<"==========================================================================="<<endl;
		pause();

		temp->next=NULL;
		if(start_ptr!=NULL){
			temp->next=start_ptr;
		}
		start_ptr=temp;
		system(clearScreen);
	}

}
void  order :: order_list(){

	int i, num, num2;	
	bool found;			//variable a buscar
	system(clearScreen);
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<"\n\t\t Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\n\t\tHere is the Order list\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Código de recibo no válido
	{
		cout << "\n\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found){
		if (temp->recipt_number==num2){
			found = true;
		}
		else{
			temp = temp -> next;
		}
        if (found)	//imprimimos el recibo
        {
		cout <<"\n\t\tReciept Number : "<<temp->recipt_number;
		cout <<"\n";
		cout<<"\n\t\tCustomer Name: "<<temp->coustumername<<endl;
				
		cout<<"\n\t\tOrder Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=================+======================+===================+================+=" << endl;
		for (i=0;i<temp->x;i++){
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" RM"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
		+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n\n";
		cout <<"\n_________________________________________________________________________________\n";
		cout<<"PAYMENT DONE \nTHANK YOU\n";
		cout <<"\n_______________________________________________________________________________\n";
		}
	}
}
void  order::delete_order()	// función para borrar_orden
{
	system(clearScreen);
	int i, num, count;
    cout<<"\n\t\tEnter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"\n\t\tCan not delete from an empty list.\n";
	else{
		
		if(start_ptr->recipt_number == num){
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"\n\t\tThe Reciept is Deleted Successfully"<<endl;
		}
		else{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
			while((!found) && (q != NULL)){
				if(q->recipt_number != num) {
					temp = q;
					q = q-> next;
				}
				else
					found = true;
			}

			if(found){
				temp->next = q->next;
				count--;
				if(last == q) 
				last = temp;
				delete q;
				cout<<"\n\t\tThe Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"\n\t\tItem to be deleted is not in the list."<<endl;
		}
	} 
}
void  order::modify()   //funcion para modificar orden
{
	system(clearScreen);
	int i, ch, sid;
	bool found;
	found = false;
	temp = start_ptr;
	cout<<"\n\t\tEnter Receipt Number To Modify: ";
	cin>>sid;
	if (temp==NULL && sid==0){
		cout<<"\n\t\tNO RECORD TO MODIFY..!"<<endl;
	}
	else{
		while(temp !=NULL && !found){

			if (temp->recipt_number==sid){
				found = true;
			}
			else{
				temp = temp -> next;
			}

			if (found){
				cout << "\n\t\tChange  Order Number: ";
				cin >> temp->recipt_number;
				cout<< "\n\t\tChange Customer Name: ";
				cin>> temp->coustumername;
				cout<<"\n\t\tChange Date : ";
				cin>>temp->date;
				cout << "\n\t\tHow many New Medicine would you like to Change:"<< endl;
				cout<<"\n\t\t( Maximum is 10 order for each transaction ) \n";
				cout << "  " ;
				cin >> temp->x;

				if (temp->x >10){
					cout << "\n\t\tThe Medicine you order is exceed the maximum amount of order !";
					pause();
				}
				else{
					for (i=0; i<temp->x; i++){
						cout << "\n\t\tPlease enter your selection to Change: "<<endl;
						cin>> temp->menu2[i];
						cout<< "\n\t\tChange Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
						cout << "\n\t\tHow many New medicine do you want: ";
						cin >> temp->quantity[i];
						temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
						cout << "\n\t\tThe amount You need to pay After Modify  is: " << temp->amount[i]<<" RM"<<endl;
						pause();
					}
					temp = temp->next;
					system(clearScreen);
				}
				
				cout<<"\n\t\tRECORD MODIFIED....!"<<endl;
			}
			else {
				if(temp != NULL && temp->recipt_number != sid){
					cout<<"\n\t\tInvalid Reciept Number...!"<<endl;
				}
			}
		}
	}
}
void summary::daily_summary() //Función para mostrar el resumen diario
{
	int i,num;
	system(clearScreen);
	node *temp ;

	temp=start_ptr;


	if(temp == NULL){
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL){
		
			cout <<"Reciept Number : "<<temp->recipt_number;
			cout <<"\n";
			cout<<"Customer Name: "<<temp->coustumername<<endl;
			
			cout<<"Order Date : "<<temp->date<<endl;
			
			cout<<"____________________________________________________________________________"<<endl;
		
			cout << "==========================================================================" << endl;
			cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++==========" << endl;
			
			for (i=0;i<temp->x;i++){
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RM"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];

			cout<<"Total Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}
void summary ::exit() //Funcion para salir
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	






