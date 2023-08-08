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
#include <sstream>
#include <thread>
#include <sys/sysinfo.h>

using namespace std;

#ifdef _WIN32
const char* clearScreen = "CLS"; // Sistema Windows
#else
const char* clearScreen = "clear"; // Sistema Unix/Linux
#endif


void pause() {
    cout << "Presiona Enter para continuar...\n";
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
	cout<<"\n\t\tUsuario:";
	cin>>username;
	cout<<"\n\t\tContrasena :";
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
		cout<<"Cargando.."<<i;

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
	char welcome[50]="BIENVENIDO";char welcome2[50]=" A";char welcome3[50]=" FARMACIA LÍNEA DE VIDA";
	char welcome4[50]="SISTEMA DE VENTAS";
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
    string medicineName[10]={"Probióticos", "Vitamina C (500 mg)", "Acid free C (500 mg)", "Multivate for women", "Marino Tablet", "Maxi Cal Tablet",
"Zinc Amino Tablet", "Burnex", "Fabuloss 5", "Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 
}*q, *temp;	

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;       

int numCompras=0;
///
double obtenerUsoCPU() {
    std::ifstream statFile("/proc/stat");
    std::string line;
    
    if (!statFile) {
        return 0.0; // Error al leer el archivo
    }

    std::getline(statFile, line);
    statFile.close();

    long user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(line.c_str(), "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    long totalIdle = idle + iowait;
    long totalNonIdle = user + nice + sys + irq + softirq + steal + guest + guest_nice;
    long total = totalIdle + totalNonIdle;

    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Esperar un momento para calcular la diferencia
    std::ifstream statFile2("/proc/stat");
    std::string line2;
    std::getline(statFile2, line2);
    statFile2.close();

    long user2, nice2, sys2, idle2, iowait2, irq2, softirq2, steal2, guest2, guest_nice2;
    sscanf(line2.c_str(), "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", &user2, &nice2, &sys2, &idle2, &iowait2, &irq2, &softirq2, &steal2, &guest2, &guest_nice2);

    long totalIdle2 = idle2 + iowait2;
    long totalNonIdle2 = user2 + nice2 + sys2 + irq2 + softirq2 + steal2 + guest2 + guest_nice2;
    long total2 = totalIdle2 + totalNonIdle2;

    double cpuPercentage = (1.0 - (static_cast<double>(totalIdle2 - totalIdle) / (total2 - total))) * 100.0;
    return cpuPercentage;
};

double obtenerUsoMemoria() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    long long totalMem = 0, freeMem = 0, buffers = 0, cached = 0;

    if (!meminfo) {
        return 0.0; // Error al leer el archivo
    }

    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal:") == 0) {
            std::istringstream iss(line);
            iss >> line >> totalMem;
        } else if (line.find("MemFree:") == 0) {
            std::istringstream iss(line);
            iss >> line >> freeMem;
        } else if (line.find("Buffers:") == 0) {
            std::istringstream iss(line);
            iss >> line >> buffers;
        } else if (line.find("Cached:") == 0) {
            std::istringstream iss(line);
            iss >> line >> cached;
            break; // Detener el ciclo después de leer la memoria caché
        }
    }

    meminfo.close();

    long long usedMem = totalMem - (freeMem + buffers + cached);

    double memoryPercentage = (static_cast<double>(usedMem) / totalMem) * 100.0;
    return memoryPercentage;
}

// generar archivo csv para estadisticas
void generarArchivoCSV(double cpuUsage, double memoryUsage, double tiempoTranscurrido) {
    ofstream archivo("estadisticas.csv", ios::app);
    if (archivo.is_open()) {
        archivo << numCompras << ","<< tiempoTranscurrido << "," << cpuUsage << "," << memoryUsage << endl;
        archivo.close();

        cout << "Estadisticas registradas en 'estadisticas.csv'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar las estadisticas." << endl;
    }
}

//generar grafica
void generarGrafica() {
    ofstream script("grafica_script.gp");
    if (script.is_open()) {
        script << "set datafile separator ','\n";
        script << "set terminal png\n";
        script << "set output 'grafica.png'\n";
        script << "plot 'estadisticas.csv' using 1:3 title 'Uso de CPU' with lines, '' using 1:4 title 'Uso de Memoria' with lines , '' using 1:2 title 'Uso de tiempo' with lines\n";
        script.close();
    } else {
        cout << "No se pudo abrir el archivo de script de Gnuplot." << endl;
    }
};

int main(){

	//system("mode 160");
	//a://goto
	system("color f4");
	double cpuUsageCompra, memoryUsageCompra, tiempoTranscurridoCompra;
    summary medi;
	medi.loadingbar();
	int choice;
	cout<<"\n\n\t\t\t\t======BIENVENIDO======"<<endl;
	cout<<"\n\n\t\t\t\t====INICIA SESION===="<<endl;
	cout<<"\n\t\t\t************************\n";
	cout<<"\n\t\t\t1: Registro\n\n\t\t\t2: Iniciar Sesion\n\n\t\t\tSelecciona Opcion:";cin >> choice;
	system(clearScreen);
	cout<<"\n\t\t\t************************\n";
	
	if(choice == 1){
		string username,password;
		cout<<"\n\tSelecciona un usuario: ";cin>>username;
		cout<<"\n\tSelecciona una contrasena: ";cin>>password;
		ofstream file;
		file.open("login.txt");
		file << username << endl << password;
		file.close();
		main();
	}

	else if(choice == 2){
		bool status = medi.loggedin();
		if(!status){
			cout<<"\n\t\tFalso Login!"<<endl;
			pause();
			return 0;
		}
		else{
			cout<<"\n\t\tSe ha identificado correctamente!"<<endl;
			pause();	
			system(clearScreen);		
		}
	}

	//medi.loadingbar();
	medi.pwelcom();
	//medi.loadingbar();
	int menu;
	do{
		system(clearScreen);
		cout<<"\n\t\t================================================\n\n";
		cout<<"\t\t\t    Sistema de Ventas de farmacia \n\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t1. Nueva venta  \t\t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t2. Borrar una venta\t\t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t3. Modificar detalle de Venta \t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t4. Factura y realice el pago\t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t5. Resumen diario de Ventas\t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t||\t6. Salir\t\t\t\t||\n";
		cout<<"\t\t__________________________________________________\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Introduce una opcion: ";

		cin>>menu;
		if (cin.fail()) {
			cout << "Entrada invalida. Debe ingresar un numero." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }

		try{
			switch (menu){

				case 1:{
					std::chrono::high_resolution_clock::time_point startTime;
					startTime = std::chrono::high_resolution_clock::now();
					
					system(clearScreen);
					medi.take_order();

					auto endTime = std::chrono::high_resolution_clock::now();
       				std::chrono::duration<double> duration = endTime - startTime;
					tiempoTranscurridoCompra = duration.count();

					cpuUsageCompra = obtenerUsoCPU(); // DebesCompramentar esta función para medir el uso de CPU
                    memoryUsageCompra = obtenerUsoMemoria(); // Debes implementar esta función para medir el uso de memoria
				
                    generarArchivoCSV(cpuUsageCompra, memoryUsageCompra, tiempoTranscurridoCompra); 
					numCompras = 0;
					//medi.loadingbar();	//funcion add
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
					break;
				}	//end case 6

				default:{
					cout<<"Ha introducido datos no válidos, vuelva a introducirlos\n"<<endl;
					break;
				}//end defeault
			}//end Switch

		}catch (const exception& e) {
            cout << "Error: " << e.what() << ". Saliendo..." << endl;
            //break;

        }catch (...) {
            cout << "Error desconocido. Saliendo..." << endl;
            //break;
        }
		
	}while(menu!=6);//end do
	
	generarGrafica();
    system("gnuplot grafica_script.gp");
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
	cout<<"DRUGS ID"<<"\tTIPO"<<"   \t\tNOMBRE"<<"           PRECIO($)"<<endl;
	cout <<"**************************************************************************\n";
    cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probióticos"<<"			$ 2.00"<<endl;
    cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamina C (500 mg)"<<"		$ 3.00"<<endl;
    cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		$ 1.00"<<endl;
    cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Multivate for women"<<"		$ 4.00"<<endl;
    cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	$ 1.00"<<endl;
    cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		$ 5.00"<<endl;
    cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		$ 7.00"<<endl;
    cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			$ 4.00"<<endl;
    cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			$ 3.00"<<endl;
    cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		$ 5.00"<<endl;
    cout<<" "<<endl;

    temp = new node;
    
	cout<<"\n\t\tEscriba el numero de Venta.";
    cin >> temp->recipt_number;
	cout<< "\n\t\tIngrese el nombre del cliente: ";
	cin>> temp->coustumername;
	cout<<"\n\t\tIngresa la fecha: ";
	cin>>temp->date;
	cout << "\n\t\t¿Cuántos medicamentos desea pedir?:"<< endl;
	cout<<"\n\t\t(Máximo 10 pedidos por transacción) \n";
	cout << "\t\t" ;
	cin >> temp->x;
	if (temp->x >10){
		cout << "\n\t\tLos medicamentos pedidos superan la cantidad máxima del pedido!";
		pause();
	}
	else{
			
		numCompras = temp->x;

		for (i=0; i<temp->x; i++){
			
			cout << "\n\t\tSeleccione un medicamento: ";
			cin>> temp->menu2[i];
			cout<< "\n\t\tNombre del medicamento: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
			cout << "\n\t\tCuántas unidades desea: ";
			cin >> temp->quantity[i];
			temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
			cout << "\n\t\tLa cantidad que debe pagar es: " << temp->amount[i]<<" $"<<endl;
			//pause();
						
		}
		
		cout<<"==========================================================================="<<endl;
		cout << "\n\t\tPedido realizado correctamente"<<endl;
		cout<<"==========================================================================="<<endl;
		cout << "\n\t\tIr al menú para pagar la factura"<<endl;
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
	
	cout<<"\n\t\t Introduzca el número de factura para imprimir: ";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\n\t\tEsta es la lista de pedidos\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Código de recibo no válido
	{
		cout << "\n\t\t\tNo hay ningún pedido que mostrar\n\t\t\tLa lista está vacía\n\n\n";
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
		cout <<"\n\t\tNúmero de Recibo : "<<temp->recipt_number;
		cout <<"\n";
		cout<<"\n\t\tNombre del cliente: "<<temp->coustumername<<endl;
				
		cout<<"\n\t\tFecha del pedido : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "| Tipo Medicina |  Nombre del medicamento      |  Cantidad   | Precio Total  |" << endl;
		cout << "================+==============================+=============+===============+=" << endl;
		for (i=0;i<temp->x;i++){
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<<" $"<<temp->amount[i]<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
		+temp->amount[8]+temp->amount[9];
		cout<<"La factura total es : "<<temp->total;
		cout<<"\n";
		do{
			cout << "Escriba la cantidad exacta que debe pagar: ";
    		cin >> num;
			if(num<temp->total){
				cout << "La cantidad es menor al monto a pagar!: \n";
			}
		}while(num<temp->total);

		if(num>temp->total){
			cout << "Monto devuelto: $"<<num-temp->total<<endl;
		}

		cout <<"\n\n";
		cout <<"\n_________________________________________________________________________________\n";
		cout<<"PAGO REALIZADO \nGRACIAS\n";
		cout <<"\n_______________________________________________________________________________\n";
		}
	}
}
void  order::delete_order()	// función para borrar_orden
{
	system(clearScreen);
	int i, num, count;
    cout<<"\n\t\tIntroduzca el numero de Venta que desea eliminar \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"\n\t\tNo se puede borrar de una lista vacía.\n";
	else{
		
		if(start_ptr->recipt_number == num){
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"\n\t\tLa factura se ha borrado correctamente"<<endl;
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
				cout<<"\n\t\tEl recibo se ha borrado correctamente"<<endl;
			}
			else
				cout<<"\n\t\tEl dato a borrar no está en la lista."<<endl;
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
	cout<<"\n\t\tIntroduzca el número de recibo a modificar: ";
	cin>>sid;
	if (temp==NULL && sid==0){
		cout<<"\n\t\tNO HAY REGISTRO QUE MODIFICAR..!"<<endl;
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
				cout << "\n\t\tCambio numero de venta: ";
				cin >> temp->recipt_number;
				cout<< "\n\t\tCambio Nombre de Cliente: ";
				cin>> temp->coustumername;
				cout<<"\n\t\tCambio Fecha: ";
				cin>>temp->date;
				cout << "\n\t\t¿Cuántos nuevos medicamentos desea modificar?:"<< endl;
				cout<<"\n\t\t( Máximo 10 pedidos por transacción ) \n";
				cout << "\t\t" ;
				cin >> temp->x;

				if (temp->x >10){
					cout << "\n\t\tLos medicamentos que ha pedido superan la cantidad máxima del pedido !";
					pause();
				}
				else{
					for (i=0; i<temp->x; i++){
						cout << "\n\t\tIngrese su selección para cambiar: "<<endl;
						cin>> temp->menu2[i];
						cout<< "\n\t\tCambio medicamento: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
						cout << "\n\t\tCuantas unidades deseas?: ";
						cin >> temp->quantity[i];
						temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
						cout << "\n\t\tLa cantidad que debe pagar después de la modificación es: " << temp->amount[i]<<" $"<<endl;
						pause();
					}
					temp = temp->next;
					system(clearScreen);
				}
				
				cout<<"\n\t\tREGISTRO MODIFICADO....!"<<endl;
			}
			else {
				if(temp != NULL && temp->recipt_number != sid){
					cout<<"\n\t\tNúmero de recibo inválido!"<<endl;
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
		cout << "\t\t\tNo hay Venta que mostrar\n\t\t\tLa lista está vacía\n\n\n";
	}
	else{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tEste es el resumen diario de todos los pedidos \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL){
		
			cout <<"Número de Recibo : "<<temp->recipt_number;
			cout <<"\n";
			cout<<"Nombre del cliente: "<<temp->coustumername<<endl;
			
			cout<<"Fecha del Pedido : "<<temp->date<<endl;
			
			cout<<"____________________________________________________________________________"<<endl;
		
			cout << "==========================================================================" << endl;
			cout << "| Tipo  |  Nombre del medicamento          |  	Cantidad   | Precio Total |" << endl;
			cout << "========+==================================+==============+==============" << endl;
			
			for (i=0;i<temp->x;i++){
				cout << temp->type <<"\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t\t";
				cout<<temp->quantity[i] <<"\t";
				cout<<" $"<<temp->amount[i]<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];

			cout<<"Total Factura es: "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}
void summary ::exit() //Funcion para salir
{
	cout<<"\nGracias por su Visita!\n"<<endl;
}	






