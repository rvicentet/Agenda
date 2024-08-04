#include <iostream>
using namespace std;

//Creado por Renzo Julian Vicente Ticona

int main(){
	int n; //Longitud actual de la lista
	int selec; //Valor para la seleccion de una opcion
	string bus; //string de busqueda para la lista
	int busresa; //int para comparar la busqueda a une elemento en la lista
	int busresb;
	int enumer; //enumera la lista
	string edit;
	int proce; //variable de proceso
	struct DatosPersona {
		bool escrito;
		string nombre;
		string genero;
		int edad;
		string correo;
		string codigo;
		
		DatosPersona():escrito(false),nombre("Vacio"),genero("Vacio"),edad(0),correo("Vacio"),codigo("Vacio")
		{}
	};
	
	DatosPersona persona[50];
	
	while(true){
		cout<<" "<<endl;
		cout<<"1-	Ver lista de registrados"<<endl;
		cout<<"2-	Anadir persona"<<endl;
		cout<<"3-	Borrar persona"<<endl;
		cout<<"4-	Editar persona"<<endl;
		cout<<"5-	Buscar persona"<<endl;
		cout<<"6-	Cerrar programa"<<endl;
		cout<<" "<<endl;
		cin>>selec;
		switch(selec){
		//Ver lista
		case 1:
			enumer=0;
			for(int i=0; i<50; i++){
				if(persona[i].escrito==true){
					enumer++;
					cout<<" "<<endl;
					cout<<enumer<<"	"<<"Nombre:	"<<persona[i].nombre<<"	"<<"Genero:	"<<persona[i].genero<<"	"<<"Edad:	"<<persona[i].edad<<endl;
					cout<<"	"<<"Correo:	"<<persona[i].correo<<endl;
					cout<<"	"<<"Codigo:	"<<persona[i].codigo<<endl;
					cout<<" "<<endl;
				}
			}
		break;
		//Añadir
		case 2:
			for(int i=0; i<50; i++){
				if(persona[i].escrito==false){
					persona[i].escrito=true;
				cout<<"Ingrese el nombre de la persona"<<endl;
				cin>>persona[i].nombre;
				cout<<"Ingrese el genero"<<endl;
				cin>>persona[i].genero;
				cout<<"Ingrese la edad"<<endl;
				cin>>persona[i].edad;
				cout<<"Ingrese el correo"<<endl;
				cin>>persona[i].correo;
				cout<<"Ingrese el codigo universitario"<<endl;
				cin>>persona[i].codigo;
				cout<<" "<<endl;
				break;
				}
			}
		break;
		//Borrar
		case 3:
			cout<<"Que entrada en la lista quiere borrar?"<<endl;
			cin>>proce;
			//proce=proce-1;
			enumer=0;
			for(int i=0; i<50; i++){
				if(persona[i].escrito==true){
					enumer++;
					if(enumer==proce){
						persona[i].escrito=false;
					}
				}
			}
		break;
		//Editar
		case 4:
			cout<<"Que entrada en la lista quiere editar?"<<endl;
			cin>>proce;
			//proce=proce-1;
			enumer=0;
			for(int i=0; i<50; i++){
				if(persona[i].escrito==true){
					enumer++;
					if(enumer==proce){
					cout<<"Ingrese el nombre de la persona"<<endl;
					cin>>persona[i].nombre;
					cout<<"Ingrese el genero"<<endl;
					cin>>persona[i].genero;
					cout<<"Ingrese la edad"<<endl;
					cin>>persona[i].edad;
					cout<<"Ingrese el correo"<<endl;
					cin>>persona[i].correo;
					cout<<"Ingrese el codigo universitario"<<endl;
					cin>>persona[i].codigo;
					cout<<" "<<endl;
					}
				}
			}
		break;
		//Buscar
		case 5:
			cout<<"Ingrese un nombre o codigo universitario: "<<endl;
			cin>>bus;
			for(int i=0; i<50; i++){
				int busresa = bus.compare(persona[i].nombre);
				int busresb = bus.compare(persona[i].codigo);
				if(persona[i].escrito==true){
					if(busresa==0||busresb==0){
						cout<<" "<<endl;
						cout<<enumer<<"	"<<"Nombre:	"<<persona[i].nombre<<"	"<<"Genero:	"<<persona[i].genero<<"	"<<"Edad:	"<<persona[i].edad<<endl;
						cout<<"	"<<"Correo:	"<<persona[i].correo<<endl;
						cout<<"	"<<"Codigo:	"<<persona[i].codigo<<endl;
						cout<<" "<<endl;
						}else{
							cout<<"No se encontro el resultado"<<endl;
						}
					}
				}
		break;
		//Cerrar
		case 6:
			return 0;
		break;
		//default
		default:
		cout<<" "<<endl;
		cout<<"Intente de nuevo"<<endl;
		cout<<" "<<endl;
		break;
		}
	}
}
