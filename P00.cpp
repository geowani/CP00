#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombre_archivo= "registro.dat";

class Estudiante{
	private: int codigo,telefono;
			 char nombre[50];
			 char apellido [50];
			 char direccion [50];
	public:
		Estudiante();
		void ingresar_estudiante();
		void abrir_estudiante();
		void buscar_indice();
		void modificar();
		void eliminar();
		void Setestudiante(int,int,char,char,char);
		int Getcodigo();
		int Gettelefono();
		void Getnombre();
		void Getapellido();
		void Getdireccion();
		
		
};

Estudiante::Estudiante(){
	codigo=0;
	telefono=0;
	nombre[50]=nombre[50];
	apellido[50]=apellido[50];
	direccion[50]=direccion[50];
}

void Estudiante::ingresar_estudiante(){
	char continuar;
	FILE* archivo = fopen("registro.data","ab");
	
	Estudiante estudiante;
	string nombre, apellido, direccion;
	do{
		system ("cls");
		cout<<"--------------Nuevo Registro--------------"<<endl;
		fflush(stdin);
		cout<<"Ingrese el codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese el nombre:";
		getline(cin,nombre);
		strcpy(estudiante.nombre,nombre.c_str());
		cout<<"Ingrese el apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido,apellido.c_str());
		cout<<"Ingrese la direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion,direccion.c_str());
		cout<<"Ingrese el telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Quieres ingresar otro esstudiante (s/n):";
		cin>>continuar;
	}while((continuar=='s')||(continuar=='S'));
	system ("cls");
	fclose(archivo);
}

void Estudiante::abrir_estudiante(){
	system("cls");
	FILE* archivo= fopen("registro.data","rb");
	Estudiante estudiante;
	cout<<"--------------Registros Ingresados--------------"<<endl<<endl;
	if(!archivo){
		archivo=fopen("registro.data","w+b");
	}
	else{
		
		int registro=0;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Apellido"<<"|"<<"Direccion"<<"|"<<"Telefono"<<""<<endl;
		do{
			cout<<"__________________________________________________________________"<<endl;
			cout<<registro<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			fread(&estudiante,sizeof(Estudiante),1,archivo);
			registro +=1;
			
		}while(feof(archivo)==0);
		cout<<endl;
	}
	fclose(archivo);
	
}

void Estudiante::buscar_indice(){
	FILE* archivo=fopen("registro.data","rb");
	
	int pos=0;
	system ("cls");
	cout<<"--------------Busqueda De Registros--------------"<<endl;
	cout<<endl;
	cout<<"Ingrese el ID del registro que desea ver: "<<endl;
	cin>>pos;
	cout<<"-----------NO de ID: "<<pos<<"----------"<<endl;
	fseek(archivo,pos* sizeof(Estudiante),SEEK_SET);
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombre: "<<estudiante.nombre<<endl;
	cout<<"Apellido: "<<estudiante.apellido<<endl;
	cout<<"Direccion: "<<estudiante.direccion<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	cout<<endl;
	fclose(archivo);
}

void Estudiante::modificar(){
	FILE* archivo=fopen("registro.data","r+b");
	int id;
	system("cls");
	cout<<"--------------Modificar Registros--------------"<<endl;
	cout<<endl;
	string nombre, apellido, direccion;
	Estudiante estudiante;
	cout<<"Ingresa el ID que quieres cambiar:";
	cin>>id;
	fseek(archivo,id* sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el codigo:";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"Ingrese el nombre:";
	getline(cin,nombre);
	strcpy(estudiante.nombre,nombre.c_str());
	cout<<"Ingrese el apellido:";
	getline(cin,apellido);
	strcpy(estudiante.apellido,apellido.c_str());
	cout<<"Ingrese la direccion:";
	getline(cin,direccion);
	strcpy(estudiante.direccion,direccion.c_str());
	cout<<"Ingrese el telefono:";
	cin>>estudiante.telefono;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
}

void Estudiante::eliminar(){
		FILE *archivo;
	archivo=fopen("registro.data","rb");
	system("cls");
	cout<<"--------------Eliminar Registros--------------"<<endl;
	cout<<endl;
	if(archivo==NULL)
		exit(1);
	cout<<"Ingresa el codigo a eliminar:";
	int cod;
	cin>>cod;
	Estudiante estudiante;
	FILE* nuevo;
	nuevo=fopen("archivo.tmp","ab");
	if(archivo==NULL)
		exit(1);
	int existe=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	while(!feof(archivo)){
		if(cod==estudiante.codigo){
			cout<<"Registro seleccionado:"<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellido<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			cout<<endl;
			cout<<"Registro eliminado!"<<endl;
			cout<<endl;
			existe=1;
		}
		else{
			fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
	}
	if(existe==0)
		cout<<"No existe alumno"<<endl;
	fclose(archivo);
	fclose(nuevo);
	
	remove("registro.data");
	rename("aux.tmp","registro.data");
	
}

int main(){
	char eleccion;
	do{
		system("cls");
		fflush(stdin);
		Estudiante estudiante;
		int escoger=0;
		cout<<"---------Menu principal----------"<<endl<<endl;
    	cout<<endl;
	    cout<<"1. Agregar registros"<<endl;
	    cout<<"2. Ver registros"<<endl;
	    cout<<"3. Buscar registros"<<endl;
	    cout<<"4. Modificar registros"<<endl;
	    cout<<"5. Eliminar registros"<<endl;
	    cout<<"6. Salir"<<endl;
	    cout<<endl;
	    cout<<"Respuesta: ";
	    cout<<"Respuesta: ";
		cin>>escoger;
		if((escoger>6) || (escoger<=0)){
			cout<<"Respuesta invalida intenta de nuevo";
		}
		switch(escoger){
			case 1:
				estudiante.ingresar_estudiante();
				break;
			case 2:
				estudiante.abrir_estudiante();
				break;
			case 3:
				estudiante.buscar_indice();
				break;
			case 4:
				estudiante.modificar();
				break;
			case 5:
				estudiante.eliminar();
				break;
			case 6:
				break;
			
		}
		
		cout<<"Deseas regresar al menu (s/n):";
		cin>>eleccion;		
	}while((eleccion=='s')||(eleccion=='S'));
	return 0;
}
