/*Alarcón Guerrero Cesar Daniel
Juan Carlos Monroy Tovar*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
            int i;
            printf("Introduzca número del 1 al 7:");
    scanf("%d",&i);

    switch(i){
              case 1:
                   void crear(){
	char nombre[30],genero[30],director[30],rpt;

	if((fd=fopen("rlv.txt","wt"))==NULL){
		cout<<"No se púede crear el archivo";return;}

	do{
		fflush(stdin);
		cout<<"Nombre:";gets(nombre);
		cout<<"Genero:";gets(genero);
		cout<<"Director:";gets(director);
		fwrite(nombre,1,strlen(nombre),fd);
		fwrite(Delimc,1,1,fd);
		fwrite(genero,1,strlen(genero),fd);
		fwrite(Delimc,1,1,fd);
		fwrite(director,1,strlen(director),fd);
		fwrite(DelimR,1,1,fd);

		cout<<"\nDesea agregar mas registros [s/n]: ",cin>>rpt;
	}while(rpt=='s');
	fclose(fd);
}

void leer_todo(){
	char k;
	if((fd=fopen("rlv.txt","rt"))==NULL){
		return;}
		while(!feof(fd)){
		k = fgetc(fd);
		if(k==';'){
			cout<<" ";continue;
		}
		if(k=='^'){
			cout<<"\n";continue;
		}
		cout<<k;
	}
	fclose(fd);
}

void modificar(){
	char k, nom[20],nombre[30],genero[30],director[40];
	int c=0,x=0,y=0,z=0;
	if((fd1=fopen("rlv.txt","rt"))==NULL){return;}
	if((fd2=fopen("tmp.txt","wt"))==NULL){return;}
	fflush(stdin);
	cout<<"\nDigite un nombre: ";gets(nom);
	while(!feof(fd1)){
		k=fgetc(fd1);
		if(k==';'){c++;nombre[x]='\0';genero[y]='\0';continue;}
		if(k=='^'){c++;director[z]='\0';c=0;x=0;y=0;z=0;
		   if(strcmp(nom,nombre)==0){
		   	    cout<<"Digite nuevo director";gets(director);}
		fwrite(nombre,1,strlen(nombre),fd2);
		fwrite(Delimc,1,1,fd2);
		fwrite(genero,1,strlen(genero),fd2);
		fwrite(Delimc,1,1,fd2);
		fwrite(director,1,strlen(director),fd2);
		fwrite(DelimR,1,1,fd2);continue;
		   }


		if(c==0){nombre[x++]=k;}
		if(c==1){genero[y++]=k;}
		if(c==2){director[z++]=k;}
	}
	fclose(fd1);fclose(fd2);
	system("del rlv.txt");system("move tmp.txt rlv.txt");
}

void eliminar(){
	char k,nom[20],nombre[20],genero[30],director[30];
	int c=0,x=0,y=0,z=0;

	if((fd1=fopen("rlv.txt","rt"))==NULL){return;}
	if((fd2=fopen("tmp.txt","wt"))==NULL){return;}

	fflush(stdin);
	cout<<"\nIngrese un nombre a eliminar: ";gets(nom);

	while(!feof(fd1)){
		k=fgetc(fd1);
		if(k==';'){c++;k=fgetc(fd1);nombre[x]='\0';genero[y]='\0';continue;}
		if(k=='^'){k=fgetc(fd1);director[z]='\0';c=0;x=0;y=0;z=0;
		   if(strcmp(nom,nombre)==0){

		   }
		   else{
		   	fwrite(nombre,1,strlen(nombre),fd2);
		    fwrite(Delimc,1,1,fd2);
	       	fwrite(genero,1,strlen(genero),fd2);
	    	fwrite(Delimc,1,1,fd2);
	    	fwrite(director,1,strlen(director),fd2);
		    fwrite(DelimR,1,1,fd2);continue;
		   }
		}

		if(c==0){nombre[x++]=k;}
		if(c==1)
		if(c==2){genero[z++]=k;}
	}
	fclose(fd1);fclose(fd2);
	system("del rlv.txt");system("move tmp.txt rlv.txt");
}

int main(){
	int opc;

	do{
		  cout<<"-----------------------------------";
		  cout<<"\n \t MENU ";
		  cout<<"\n 1- Crear registro";
		  cout<<"\n 2. Leer todo";
		  cout<<"\n 3. Modificar registro";
          cout<<"\n 4. eliminar";
		  cout<<"\n 5. Salir";
		  cout<<"\n Opcion:   ";
		  cin>>opc;

		  switch(opc){
		  	            case 1: {crear();break;}
		  	            case 2: {leer_todo();break;}
		  	            case 3: {modificar();break;}
		  	            case 4: {eliminar();break;}



		  }

	}while(opc!=5);

system("pause");
return 0;
}
                   break;
              case 2:
                  using namespace std;


class series
{
    public:
        char nombre[20], descripcion[35], anio[15];

    void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void menu();
}pr;

int dim1, dim2, dim3, opc = 0;


void series::Agregar()
{
    cout<<"Ingrese el Nombre de la serie\n: ";
    cin.getline(nombre, 30);
    cin.getline(nombre, 30);
    cout<<"ESCRIBE LA DESCRIPCION: ";
    cin.getline(descripcion,35);
    cout<<"Escribe el anio de emision: ";
    cin.getline(anio,15);
    ofstream Archivo("Productos.txt",ios::app);
    dim1 = strlen(nombre);
    dim2 = strlen(descripcion);
    dim3 = strlen(anio);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&nombre, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&descripcion, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&anio, dim3);

    Archivo.close();

}
void series::Mostrar()
{
	system("cls");

    ifstream archivo("Productos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tamaï¿½o de la cadena que se quiere leer
			archivo.read((char*)&nombre, dim1);
			nombre[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&anio, dim3);
			anio[dim3] = '\0';
            cout << nombre << "  " << descripcion << "  " << anio << endl;
		}
	}
    archivo.close();
}


void series::Modificar()
{
    int band = 0;
    char codigo2[10];

	ifstream archivo("Productos.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "Escribe el nombre de la serie: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&anio, dim3);
            anio[dim3] = '\0';

            if(strcmp(codigo2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << anio << endl;
                band = 1;
                cout<<"¿Desea modificar el registro?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Productos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&anio, dim3);
            anio[dim3] = '\0';

            if(strcmp(codigo2, nombre) == 0)
            {
                cout<<"ingrese el nombre de la serie: ";
                cin.getline(nombre, 10);
                cin.getline(nombre, 10);
                cout<<"ESCRIBE LA DESCRIPCION: ";
                cin.getline(descripcion,35);
                cout<<"ESCRIBE EL año de emision: ";
                cin.getline(anio,15);
                dim1 = strlen(nombre);
                dim2 = strlen(descripcion);
                dim3 = strlen(anio);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&nombre, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&descripcion, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&anio, dim3);
        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Productos.txt");
	rename("temporal.txt", "Productos.txt");
	}//condicional de la opcion

    }// else

}

void series::Eliminar()
{
int band = 0;
    char codigo2[10];

	ifstream archivo("Productos.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "Nombre que quieres eliminar: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&anio, dim3);
            anio[dim3] = '\0';

            if(strcmp(codigo2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << anio << endl;
                band = 1;
                cout<<"Desead eliminar?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Productos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&anio, dim3);
            anio[dim3] = '\0';

            if(strcmp(codigo2, nombre) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&nombre, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&descripcion, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&anio, dim3);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Productos.txt");
	rename("temporal.txt", "Productos.txt");
	}//condicional de la opcion

    }//

}

void series::Buscar()
{
    char codigo2[10];
    int band = 0;
    system("cls");

    ifstream archivo("Productos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "escribe el nombre la serie  que desea buscar: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tamaï¿½o de la cadena que se quiere leer
			archivo.read((char*)&nombre, dim1);
			nombre[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&anio, dim3);
			anio[dim3] = '\0';
			if( strcmpi(codigo2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << anio << endl;
                band = 1;
            }
		}
		if (!band)
            cout << "No se encuentra la serie..." << endl;
	}
    archivo.close();
}
int main()
{

    cout<<"------------------------------------------------------------------------------------ \n";
	cout<<"\t\t MENU \n";
	cout<<"------------------------------------------------------------------------------------ \n";
	do{
		cout<<"SELECCIONE LA OPCION DESEADA:\n\n1.- AGREGAR\n2.- MOSTRAR\n3.- BUSCAR\n4.- MODIFICAR\n5.- ELIMINAR\n6.- SALIR\n>: ";
		cin>>opc;
		switch(opc) {
		  case 1:
			pr.Agregar();
			break;
		  case 2:
			pr.Mostrar();
			break;
          case 3:
			pr.Buscar();
			break;
		  case 4:
            pr.Modificar();
			//administrador1.Datos();
			break;
          case 5:
			pr.Eliminar();
			break;
          default:
            cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opc != 6);
}
                   break;
              case 3:

class reproduccion
{
    public:
    char codigo[14], nombre[35], genero[40],estreno[20],cantante[20],productora[20];
    int duracion;

    void capturar();
    void buscar();
    void mostrar();
    void Modificar();
    void Eliminar();
    void Mostrar_Indice();
    void Orden();
}x;

class Indice
{
    public:
    char rfc[14];
    long int pos;

}y;

void reproduccion::mostrar()
{
    ifstream a("datos.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&x,sizeof(x));
            if(a.eof())
                break;
            cout<<"codigo:"<<x.codigo<<endl<<"Nombre: "<<x.nombre<<endl<<"Genero: "<<x.genero<<endl<<"Banda:"<<x.estreno<<endl<<"Cantante:"<<x.cantante<<endl<<"Productora:"<<productora<<endl<<"Duracion:"<<duracion<<endl;
        }
    }
    a.close();
}

void reproduccion::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;
            cout<<"Codigo:"<<y.rfc<<endl<<endl;
        }
    }
    a.close();
}




void reproduccion::capturar()
{
    fflush(stdin);
    cout<<"Codigo:"<<endl;
    cin.getline(codigo,14);
    cout<<"Dame el nombre de la serie"<<endl;
    cin.getline(nombre,35);
    cout<<"Dame el genero "<<endl;
    cin.getline(genero,40);
    cout<<"Dame el nombre de la fecha de estreno"<<endl;
    cin.getline(estreno,20);
    cout<<"Dame el nombre del protagonista"<<endl;
    cin.getline(protagonist,20);
    fflush(stdin);
    cout<<"Dame el nombre de la productora"<<endl;
    cin.getline(productora,20);
    cout<<"Dame la duracion"<<endl;
    cin>>duracion;
    ofstream a("datos.txt",ios::app);
    a.write((char*)&x,sizeof(x));
    y.pos=a.tellp();
    y.pos-=sizeof(x);
    a.close();
    strcpy(y.rfc,codigo);
    ofstream b("indice.txt",ios::app);
    b.write((char*)&y,sizeof(y));
    b.close();
    orden++;
}

void reproduccion::buscar()
{
    char rfcbus[14];
    int band=0;

    ifstream b("indice.txt");
    if(!b.good()){
    cout<<"No existe el archivo";}
    else{
    cout<<"\nRFC a buscar!"<<endl;
    fflush(stdin);cin.getline(rfcbus,14);
    while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcbus)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&x,sizeof(x));
            cout<<"Codigo:"<<x.codigo<<endl<<"Nombre de la serie: "<<x.nombre<<endl<<"Genero: "<<x.genero<<endl<<"Fecha de estreno:"<<x.estreno<<endl<<"Nombre del protagonista:"<<x.protagonist<<endl<<"Productora:"<<productora<<endl<<"Duracion:"<<duracion<<endl;
            a.close();
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n NO EXISTE REGISTRO....."   ;
    }
    }
    b.close();

}

void reproduccion::Modificar()
{
     char rfcmod[15];
     int band=0;
     int opc;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\ncodigo a modificar!"<<endl;
     fflush(stdin);cin.getline(rfcmod,14);
     while(!b.eof())
    {   opc=0;
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcmod)==0 && band==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);

             a.read((char*)&x,sizeof(x));
             if(a.eof())   break;
            cout<<"Codigo:"<<x.codigo<<endl<<"Nombre de la serie: "<<x.nombre<<endl<<"Genero: "<<x.genero<<endl<<"Fecha de estreno:"<<x.estreno<<endl<<"Nombre del protagonista"<<x.protagonist<<endl<<"Productora:"<<productora<<endl<<"Duracion:"<<duracion;
            cout<<"Deseas modificarlo\n"<<"1.-Si   2.-No"; cin>>opc;
            band=1;
            a.close();
            break;
         }
         }
         b.close();
         if(opc==1)
{
    fflush(stdin);
    ifstream indice("indice.txt");
    ifstream datos("datos.txt");
          while(!indice.eof())
         {cout<<"entro al ciclo\n";
          indice.read((char*)&y,sizeof(y));
          cout<<"\nrfc:"<<y.rfc<<"\n";
          datos.read((char*)&x,sizeof(x));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcmod)==0)
        {
        cout<<"Codigo:"<<endl;
       cin.getline(codigo,14);
        cout<<"Dame el nombre de la serie"<<endl;
    cin.getline(nombre,35);
    cout<<"Dame el genero "<<endl;
    cin.getline(genero,40);
    cout<<"Dame la echa de estreno"<<endl;
    cin.getline(estreno,20);
    cout<<"Dame el Nombre del protagonista"<<endl;
    cin.getline(protagonist,20);
    fflush(stdin);
    cout<<"Dame la productora"<<endl;
    cin.getline(productora,20);
    cout<<"Dame la duracion"<<endl;
    cin>>duracion;

     }

          ofstream c("temp.txt",ios::app);
          c.write((char*)&x,sizeof(x));

        strcpy(y.rfc,codigo);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();

        }



}

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO."   ;}

    }


    remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");


}

void reproduccion::Eliminar()
{
 char rfceli[15];
     int band=0;
     int opc,cont=0,cont2=0;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nRFC a eliminar!"<<endl;
     fflush(stdin);cin.getline(rfceli,14);
     while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        cont++;
            cout<<"contador --"<<cont;
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfceli)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&x,sizeof(x));
             if(a.eof())   break;

           cout<<"Codigo:"<<x.codigo<<endl<<"Nombre de la serie: "<<x.nombre<<endl<<"Genero: "<<x.genero<<endl<<"Fecha de estreno:"<<x.estreno<<endl<<"Nombre del protaginista:"<<x.protagonist<<endl<<"Productora:"<<productora<<endl<<"Duracion:"<<duracion;
            cout<<"Deseas eliminar\n"<<"1.-Si   2.-No"; cin>>opc;
            band=1;
           a.close();
             break;
         }

         }
        b.close();
         cout<<"salio--";

         if(opc==1)
         {cout<<"entro al si\n";
          ifstream indice("indice.txt");
          ifstream datos("datos.txt");
          while(!indice.eof())
         {cout<<"entro al ciclo\n";
          indice.read((char*)&y,sizeof(y));
          cout<<"\nrfc:"<<y.rfc<<"\n";
          datos.read((char*)&x,sizeof(x));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfceli))
        {cont2++; cout<<"contador de if es "<<cont2;


          cout<<"nombre escrito es "<<x.nombre;
          ofstream c("temp.txt",ios::app);
          c.write((char*)&x,sizeof(x));

        strcpy(y.rfc,codigo);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();
        }
        }
       indice.close();
       datos.close();
       remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");
        }
        else
        {

        }

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }


}

void reproduccion::Orden()
{int i=0;
char indice[20][14];
char aux[20];

  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {cout<<"else";
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;

                char *cadena=y.rfc;
                strcpy(indice[i],cadena);

                i++;
        }
    }
    a.close();

    for(int i=0;i<orden-1;i++)
for(int j=i+1;j<orden;j++)
if(strcmp(indice[i],indice[j])>0)
{
strcpy(aux,indice[j]);
strcpy(indice[j],indice[i]);
strcpy(indice[i],aux);
system("cls");}
for(int i=0;i<orden;i++)
{

strcpy(y.rfc,indice[i]);

ofstream a("tempind.txt",ios::app);
a.write((char*)&y,sizeof(y));
a.close();
}

 remove("indice.txt");
 rename("tempind.txt","indice.txt");

}

int main()
{
    int opc;
    do{
    system("cls");
    cout<<"Selecciona una de la siguientes opciones:"<<endl<<"1.-Capturar"<<endl<<"2.-Buscar"<<endl<<"3.-Mostrar todos"<<endl<<"4.-Modificar"<<endl<<"5.-Eliminar"<<endl<<"6.-Mostrar Indice"<<endl<<"7-.Ordenar Indice\n"<<endl<<"INGRESE UNA OPCION:	\n";
    cin>>opc;
    switch(opc)
    {

        case 1:
        x.capturar();

        break;

        case 2:
        x.buscar();

        break;

        case 3:
        x.mostrar();
        break;

        case 4:
        x.Modificar();


        break;

        case 5:
             x.Eliminar();

             break;

        case 6:
        x.Mostrar_Indice(); break;

        case 7:x.Orden(); break;
    }
    getch();
    }while(opc!=9);
    return 0;
}
                   break;
              case 4:


template < typename E >
void mostrar( ListaLigada< E > &L );


class IndiceSecundario
{
	public:
		char nombre[ 35 ] ;
		int enlace;
};

class Ligada
{
	public:
		int id;
		int enlace;
};


ListaLigada< string > arregloIndices;
ListaLigada< int > nrrs;
ListaLigada< int > listaLigada;

class Administrador2
{
	private:
		char id[ 10 ];
		char nombre[ 35 ];
		char direccion[ 40 ];
		char ciudad[ 40 ];
		char sueldo[ 10 ];

		int buscarEnIndice( const string & );
		int existeId( const int );
		int buscarEnLigado( const int );
		Administrador2 eliminarEnArchDatos( const int );
		void eliminarEnNrrs( const int );
		void eliminarEnIndiceLigado( const int, const int );
		void eliminarEnIndiceEmpleados( const string & );
		Administrador2 modificarEnArchDatos( const int, const Administrador2 & );
		void modificarEnNrrs( const int, const int );
		void modificarEnIndiceEmpleados(  const string &nombreAnterior, const string &nuevoNombre, const int idViejo, const int nuevoId );
		void modificarEnIndiceLigado( const string &, const int );
	public:
		Administrador2( void ){}
		Administrador2( const Administrador2 & );
		void setNombre( const string & );
		void setDireccion( const string & );
		void setCiudad( const string & );
		void setSueldo( const string & );
		void setId( const string & );
		Administrador2 pedirRegistro( void );
		void agregar( const Administrador2 & );
		void mostrarTodo( void );
		void inicializar( void );
		void buscarPorNombre( const string & );
		void guardar( void );
		bool buscarId( const int, Administrador2 & );
        bool eliminar( const int, Administrador2 & );
        void modificar( const int, const Administrador2 & );
        friend ostream &operator<<( ostream &, const Administrador2 & );
        void mostrarLista( void );
};


void Administrador2::mostrarLista( void )
{
	mostrar( listaLigada );
	mostrar( nrrs );
	mostrar( arregloIndices );
}

Administrador2 Administrador2::pedirRegistro( void )
{
	string cadena;
	Administrador2 empleadoARetornar;

	cout << "Ingresa el ID: ";
	fflush( stdin );
	getline( cin, cadena );
	while( existeId( atoi( cadena.c_str() ) ) != -1 )
	{
		cout << "Ese ID ya existe Ingresa otro: ";
		fflush( stdin );
		getline( cin, cadena );
	}
	empleadoARetornar.setId( cadena );

	cout << "Ingrese el nombre del Administrador2: ";
    fflush( stdin );
    getline( cin, cadena );
    empleadoARetornar.setNombre( cadena );

    cout << "Ingrese la direccion: ";
    fflush( stdin );
    getline( cin, cadena );
    empleadoARetornar.setDireccion( cadena );

    cout << "Ingrese la ciudad: ";
    fflush( stdin );
    getline( cin, cadena );
    empleadoARetornar.setCiudad( cadena );

    cout << "Ingrese el sueldo del Administrador2: ";
    fflush( stdin );
    getline( cin, cadena );
    empleadoARetornar.setSueldo( cadena );

    return empleadoARetornar;
}

Administrador2::Administrador2( const Administrador2 &origen )
{
	strcpy( id, origen.id );
	strcpy( nombre, origen.nombre );
	strcpy( direccion, origen.direccion );
	strcpy( ciudad, origen.ciudad );
	strcpy( sueldo, origen.sueldo );
}

void Administrador2::setId( const string &valorId )
{
	int longitud = valorId.size();
	longitud = ( longitud < 10 ? longitud : 9 );
	valorId.copy( id, longitud );
	id[ longitud ] = '\0';
}

void Administrador2::setSueldo( const string &valorSueldo )
{
	int longitud = valorSueldo.size();
	longitud = ( longitud < 10 ? longitud : 9 );
	valorSueldo.copy( sueldo, longitud );
	sueldo[ longitud ] = '\0';
}

void Administrador2::setNombre( const string &valorNombre )
{
	int longitud = valorNombre.size();
	longitud = ( longitud < 35 ? longitud : 34 );
	valorNombre.copy( nombre, longitud );
	nombre[ longitud ] = '\0';
}

void Administrador2::setDireccion( const string &valorDireccion )
{
	int longitud = valorDireccion.size();
	longitud = ( longitud < 40 ? longitud : 39 );
	valorDireccion.copy( direccion, longitud );
	direccion[ longitud ] = '\0';
}

void Administrador2::setCiudad( const string &valorCiudad )
{
	int longitud = valorCiudad.size();
	longitud = ( longitud < 40 ? longitud : 39 );
	valorCiudad.copy( ciudad, longitud );
	ciudad[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Administrador2 &Administrador2 )
{
    salida << "ID:        "  << Administrador2.id << endl
           << "Nombre:    "  << Administrador2.nombre << endl
           << "Direccion: "  << Administrador2.direccion << endl
           << "Ciudad:    "  << Administrador2.ciudad << endl
           << "Sueldo:    "  << Administrador2.sueldo << endl;

    return salida;
}

void Administrador2::mostrarTodo( void )
{
	Administrador2 Administrador2;
	ifstream archivo( "empleados.txt", ios::in );
	if( !archivo )
		cout << "No existe el archivo" << endl;
	else
	{
		cout << endl;
		while( !archivo.eof() )
		{
			archivo.read( ( char * ) &Administrador2, sizeof( Administrador2 ) );
			if( !archivo.eof() )
				cout << Administrador2 << endl << endl;
		}
	}
	archivo.close();
}

int Administrador2::existeId( const int idABuscar )
{
	nrrs.irAlInicio();
	for( int i = 0; i < nrrs.obtenerTamanio(); i++ )
		if( nrrs.obtenerElemento() == idABuscar )
			return nrrs.obtenerEnlace();
		else
			nrrs.siguiente();
	return -1;
}

int Administrador2::buscarEnIndice( const string &nombreABuscar )
{
	arregloIndices.irAlInicio();
	for( int i = 0; i < arregloIndices.obtenerTamanio(); i++ )
		if( arregloIndices.obtenerElemento() == nombreABuscar )
			return arregloIndices.posicionActual();
		else
			arregloIndices.siguiente();
	return -1;
}

int Administrador2::buscarEnLigado( const int idABuscar )
{
	listaLigada.irAlInicio();
	for( int i = 0; i < listaLigada.obtenerTamanio(); i++ )
		if( listaLigada.obtenerElemento() == idABuscar )
			return listaLigada.posicionActual();
		else
			listaLigada.siguiente();
	return -1;
}

Administrador2 Administrador2::eliminarEnArchDatos( const int idAEliminar )
{
	ifstream datos( "empleados.txt", ios::in );
	ofstream temporal( "temporal.txt", ios::out );
	Administrador2 registro;
	Administrador2 registroARetornar;

	while( !datos.eof() )
	{
		datos.read( ( char * ) &registro, sizeof( Administrador2 ) );
		if( atoi( registro.id ) != idAEliminar )
			temporal.write( ( char * ) &registro, sizeof( Administrador2 ) );
		else
			registroARetornar = registro;
	}
	datos.close();
	temporal.close();
	remove( "empleados.txt" );
	rename( "temporal.txt", "empleados.txt" );

	return registroARetornar;
}

void Administrador2::eliminarEnNrrs( const int idAEliminar )
{
	int posicion = existeId( idAEliminar );
	nrrs.irAPosicion( posicion );
	//cout << "posicion = " << posicion << endl;
	nrrs.eliminar();
	for( int i = posicion; i < nrrs.obtenerTamanio(); i++ )
	{
		nrrs.modificar( nrrs.obtenerElemento(), nrrs.obtenerEnlace() - 1 );
		nrrs.siguiente();
	}
	//mostrar( nrrs );
}

void Administrador2::eliminarEnIndiceEmpleados( const string &nombreAEliminar )
{
	int posicion = buscarEnIndice( nombreAEliminar );
	arregloIndices.irAPosicion( posicion );
	listaLigada.irAPosicion( arregloIndices.obtenerEnlace() );
	if( listaLigada.obtenerEnlace() == -1 )
		arregloIndices.eliminar();
}

void Administrador2::eliminarEnIndiceLigado( const int idAEliminar, const int posDeRegistro )
{
	int posicion = buscarEnLigado( idAEliminar );
	listaLigada.irAPosicion( posicion );
	int aux = listaLigada.posicionActual();
	int posNueva = listaLigada.obtenerEnlace();
	arregloIndices.irAPosicion( posDeRegistro );
	if( listaLigada.obtenerEnlace() == -1 )
		listaLigada.modificar( -1, -1 );
	else
	{
		if( arregloIndices.obtenerEnlace() == listaLigada.posicionActual() )
		{
			arregloIndices.modificar( arregloIndices.obtenerElemento(), listaLigada.obtenerEnlace() );
			listaLigada.modificar( -1, -1 );
		}
		else
		{
			listaLigada.irAPosicion( arregloIndices.obtenerEnlace() );
			while( listaLigada.obtenerEnlace() != aux )
				listaLigada.irAPosicion( listaLigada.obtenerEnlace() );
			listaLigada.modificar( listaLigada.obtenerElemento(), posNueva );
			listaLigada.irAPosicion( posicion );
			listaLigada.modificar( -1, -1 );
		}
	}
}

bool Administrador2::eliminar( const int idAEliminar, Administrador2 &valor )
{
	string cadenaNombre;
	if( existeId( idAEliminar ) != -1 )
	{
		valor = eliminarEnArchDatos( idAEliminar );
		eliminarEnNrrs( idAEliminar );
		cadenaNombre = valor.nombre;
		eliminarEnIndiceEmpleados( cadenaNombre ); // debe ir antes que eliminarEnIndiceLigado
		eliminarEnIndiceLigado( idAEliminar, arregloIndices.posicionActual() );
		return true;
	}
	else
		cout << "El id no existe" << endl;
	return false;
}

bool Administrador2::buscarId( const int idABuscar, Administrador2 &resultado )
{
	long int posByte;
	ifstream datos( "empleados.txt", ios::in );

	if( !datos )
		cout << "No existe el archivo" << endl;
	else
	{
		nrrs.irAlInicio();
		for( int i = 0; i < nrrs.obtenerTamanio(); i++ )
		{
			if( nrrs.obtenerElemento() == idABuscar )
			{
				posByte = nrrs.obtenerEnlace() * sizeof( Administrador2 );
				datos.seekg( posByte, ios::beg );
				datos.read( ( char * ) &resultado, sizeof( Administrador2 ) );
				datos.close();
				return true;
			}
			nrrs.siguiente();
		}
	}
	datos.close();
	return false;
}

void Administrador2::buscarPorNombre( const string & nombreABuscar )
{
	ifstream datos( "empleados.txt", ios::in );
	int indiceRegistro;
	long int posByte;
	Administrador2 temporal;
	bool yaTermino = false;

	if( !datos )
		cout << "No existe el archivo" << endl;
	else
	{
		int posEncontrado = buscarEnIndice( nombreABuscar );
		if( !( posEncontrado == -1 ) )
		{
			cout << endl;
			arregloIndices.irAPosicion( posEncontrado );
			listaLigada.irAPosicion( arregloIndices.obtenerEnlace() );
			do
			{
				indiceRegistro = existeId( listaLigada.obtenerElemento() );
				posByte = indiceRegistro * sizeof( Administrador2 );
				datos.seekg( posByte, ios::beg );
				datos.read( ( char * ) &temporal, sizeof( temporal ) );
				cout << temporal << endl << endl;
				if( listaLigada.obtenerEnlace() == -1  )
					yaTermino = true;
				else
					listaLigada.irAPosicion( listaLigada.obtenerEnlace() );
			}while( yaTermino == false );
		}
		else
			cout << "No se encontraron resultados" << endl;
	}
	datos.close();
}

void Administrador2::agregar( const Administrador2 &nuevoValor )
{
	string cadenaNombre;

    ofstream archivo( "empleados.txt", ios::app );
    if( existeId( atoi( nuevoValor.id ) ) == -1 )
    {
	    archivo.write( ( char * ) &nuevoValor, sizeof( Administrador2 ) );
	    nrrs.ponAlFinal( atoi( nuevoValor.id ), nrrs.obtenerTamanio() );

	    cadenaNombre = nuevoValor.nombre;
	    int posEncontrado = buscarEnIndice( cadenaNombre );
	    if( posEncontrado != -1 ) // si ya existe el nombre
	    {
	    	arregloIndices.irAPosicion( posEncontrado );
	    	listaLigada.ponAlFinal( atoi( nuevoValor.id ), arregloIndices.obtenerEnlace() );
	    	arregloIndices.modificar( arregloIndices.obtenerElemento(), listaLigada.obtenerTamanio() - 1 );
	    }
	    else // si no existe el nombre
	    {
	    	listaLigada.ponAlFinal( atoi( nuevoValor.id ), -1 );
	    	arregloIndices.ponAlFinal( cadenaNombre, listaLigada.obtenerTamanio() - 1 );
	    }
	    mostrar( listaLigada );
	    mostrar( nrrs );
	    mostrar( arregloIndices );
	}
	else
		cout << "No se agrego, el ID ya existe" << endl;
    archivo.close();
}

void Administrador2::modificar( const int idAModificar, const Administrador2 &reemplazo )
{
	string cadenaNombre, cad;
	Administrador2 empleadoModificado;
	if( existeId( idAModificar ) != -1 && existeId( atoi( reemplazo.id ) ) == -1 ) // si existe el id
	{
		empleadoModificado = modificarEnArchDatos( idAModificar, reemplazo );
		modificarEnNrrs( idAModificar, atoi( reemplazo.id ) );
		cadenaNombre = reemplazo.nombre;
		cad = empleadoModificado.nombre;
		modificarEnIndiceEmpleados( cad, cadenaNombre, atoi( empleadoModificado.id ), atoi( reemplazo.id ) );
		cadenaNombre = empleadoModificado.nombre;
		if( !( strcmp( empleadoModificado.nombre, reemplazo.nombre ) == 0 ) )
			modificarEnIndiceLigado( cadenaNombre, atoi( empleadoModificado.id ) );
	}
	else
		cout << "El registro no existe o el id ya existe" << endl;

	mostrar( listaLigada );
	mostrar( nrrs );
	mostrar( arregloIndices );
}

void Administrador2::modificarEnIndiceLigado( const string &nombreAModificar, const int idViejo )
{
	int posicion = buscarEnIndice( nombreAModificar );
	int a, b, c;
	bool bandera = false;
	arregloIndices.irAPosicion( posicion );
	listaLigada.irAPosicion( arregloIndices.obtenerEnlace() );
	a = c = listaLigada.posicionActual();
	if( listaLigada.obtenerElemento() == idViejo && listaLigada.obtenerEnlace() == -1 )
	{
		arregloIndices.eliminar();
		listaLigada.modificar( -1, -1 );
	}
	else
	{
		while( listaLigada.obtenerElemento() != idViejo )
		{
			a = listaLigada.posicionActual();
			listaLigada.irAPosicion( listaLigada.obtenerEnlace() );
			c = listaLigada.posicionActual();
			bandera = true;
		}
		b = listaLigada.obtenerEnlace();
		if( bandera == true )
			arregloIndices.modificar( arregloIndices.obtenerElemento(), a );
		else
			arregloIndices.modificar( arregloIndices.obtenerElemento(), b );

		listaLigada.irAPosicion( a );
		listaLigada.modificar( listaLigada.obtenerElemento(), b );
		listaLigada.irAPosicion( c );
		listaLigada.modificar( -1, -1 );
	}
}

void Administrador2::modificarEnIndiceEmpleados( const string &nombreAnterior, const string &nuevoNombre, const int idViejo, const int nuevoId )
{
	int posicion = buscarEnIndice( nuevoNombre );
	if( posicion == -1 ) // si nuevoNombre NO existe en el archivo
	{
		listaLigada.ponAlFinal( nuevoId, -1 );
	    arregloIndices.ponAlFinal( nuevoNombre, listaLigada.obtenerTamanio() - 1 );
	}
	else // si nuevoNombre YA existe
	{
		if( nombreAnterior == nuevoNombre )
		{
			arregloIndices.irAPosicion( posicion );
			listaLigada.irAPosicion( arregloIndices.obtenerEnlace() );
			while( listaLigada.obtenerElemento() != idViejo )
				listaLigada.irAPosicion( listaLigada.obtenerEnlace() );
			listaLigada.modificar( nuevoId, listaLigada.obtenerEnlace() );
		}
		else
		{
			arregloIndices.irAPosicion( posicion );
	    	listaLigada.ponAlFinal( nuevoId, arregloIndices.obtenerEnlace() );
	    	arregloIndices.modificar( arregloIndices.obtenerElemento(), listaLigada.obtenerTamanio() - 1 );
	    }
	}
}

void Administrador2::modificarEnNrrs( const int idAModificar, const int nuevoID )
{
	int posicion = existeId( idAModificar );
	nrrs.irAPosicion( posicion );
	nrrs.modificar( nuevoID, nrrs.obtenerEnlace() );
}

Administrador2 Administrador2::modificarEnArchDatos( const int idAModificar, const Administrador2 &registroReemplazo )
{
	Administrador2 registroARetornar;
	fstream datos( "empleados.txt", ios::in | ios::out );
	if( datos )
	{
		int posDeRegistro = existeId( idAModificar );
		int posByte = posDeRegistro * sizeof( Administrador2 );
		datos.seekg( posByte, ios::beg );
		datos.read( ( char * ) &registroARetornar, sizeof( Administrador2 ) );
		datos.seekg( (long)datos.tellg() - sizeof( Administrador2 ), ios::beg );
		datos.write( ( char * ) &registroReemplazo, sizeof( Administrador2 ) );
	}
	else
		cout << "No existe el archivo" << endl;
	datos.close();
	return registroARetornar;
}

void Administrador2::inicializar( void )
{
	IndiceSecundario indiSecundario;
	Ligada liga;
	string cadenaNombre;
	ifstream indice( "indiceEmpleados.txt", ios::in );
	ifstream indiceLigado( "ligadoEmpleados.txt", ios::in );
	ifstream indiceNrr( "indiceNrr.txt", ios::in );

	if( !indice || !indiceLigado || !indiceNrr ) // si los archivos no existen los crea
	{
		ofstream indice( "indiceEmpleados.txt", ios::out );
		ofstream indiceLigado( "ligadoEmpleados.txt", ios::out );
		ofstream indiceNrr( "indiceNrr.txt", ios::out );
	}
	else
	{
		// archivo de Ã­ndices para el nombre
		arregloIndices.irAlInicio();
		while( !indice.eof() )
		{
			indice.read( ( char * ) &indiSecundario, sizeof( IndiceSecundario ) );
			if( !indice.eof() )
			{
				cadenaNombre = indiSecundario.nombre;
				arregloIndices.ponAlFinal( cadenaNombre, indiSecundario.enlace );
			}
			cadenaNombre.clear();
		}

		// archivo de indice ligado para nombre
		listaLigada.irAlInicio();
		while( !indiceLigado.eof() )
		{
			indiceLigado.read( ( char * ) &liga, sizeof( Ligada ) );
			if( !indiceLigado.eof() )
				listaLigada.ponAlFinal( liga.id, liga.enlace );
		}
		// archivo de inidice de nrr's para los datos de empleados
		nrrs.irAlInicio();
		while( !indiceNrr.eof() )
		{
			indiceNrr.read( ( char * ) &liga, sizeof( Ligada ) );
			if( !indiceNrr.eof() )
				nrrs.ponAlFinal( liga.id, liga.enlace );
		}
	}

	indice.close();
	indiceLigado.close();
	indiceNrr.close();
}

void Administrador2::guardar( void )
{
	ofstream indice( "indiceEmpleados.txt", ios::out );
	ofstream indiceLigado( "ligadoEmpleados.txt", ios::out );
	ofstream indiceNrr( "indiceNrr.txt", ios::out );

	IndiceSecundario contenedor;
	arregloIndices.irAlInicio();
	for( int i = 0; i < arregloIndices.obtenerTamanio(); i++ )
	{
		for( int j = 0; j < sizeof( contenedor.nombre ); contenedor.nombre[ j++ ] = '\0' );
		strcpy( contenedor.nombre, arregloIndices.obtenerElemento().c_str() );
		contenedor.enlace = arregloIndices.obtenerEnlace();
		indice.write( ( char * ) &contenedor, sizeof( IndiceSecundario ) );
		arregloIndices.siguiente();
	}

	Ligada liga;
	listaLigada.irAlInicio();
	for( int i = 0; i < listaLigada.obtenerTamanio(); i++ )
	{
		liga.id = listaLigada.obtenerElemento();
		liga.enlace = listaLigada.obtenerEnlace();
		indiceLigado.write( ( char * ) &liga, sizeof( Ligada ) );
		listaLigada.siguiente();
	}

	nrrs.irAlInicio();
	for( int i = 0; i < nrrs.obtenerTamanio(); i++ )
	{
		liga.id = nrrs.obtenerElemento();
		liga.enlace = nrrs.obtenerEnlace();
		indiceNrr.write( ( char * ) &liga, sizeof( Ligada ) );
		nrrs.siguiente();
	}

	indice.close();
	indiceLigado.close();
	indiceNrr.close();
}

int main( void )
{
	Administrador2 Administrador2, nuevo, empleadoBuscar, empleadoEliminado;
	string respuesta;
	char opcion;
	Administrador2.inicializar();
	do
    {
	    system("cls");
	    cout << "Seleccione una opcion" << endl;
	    cout << "1) Agregar Administrador2." << endl;
	    cout << "2) Mostrar todos los empleados." << endl;
	    cout << "3) Buscar Administrador2 por ID." << endl;
	    cout << "4) Buscar Administrador2 por Nombre" << endl;
        cout << "5) Modificar Administrador2." << endl;
        cout << "6) Eliminar Administrador2." << endl;
        cout << "7) Salir." << endl;
        cout << "8) mostrar listaLigada" << endl;
	    cin >> opcion;
	    switch( opcion )
	    {
	    	case '1': // agregar
	    		nuevo = Administrador2.pedirRegistro();
	    		Administrador2.agregar( nuevo );
	    		break;

	    	case '2': // mostrar
	    		Administrador2.mostrarTodo();
	    		break;

            case '3': // buscar
                cout << "Ingrese el ID a buscar: ";
                fflush( stdin );
                cin >> respuesta;
                if( Administrador2.buscarId( atoi( respuesta.c_str() ), empleadoBuscar ) )
                    cout << empleadoBuscar << endl << endl;
                else
                    cout << "El registro no existe" << endl;
                break;
            case '4':
            	cout << "Ingresa el nombre a buscar: ";
            	fflush( stdin );
            	getline( cin, respuesta );
            	Administrador2.buscarPorNombre( respuesta );
            	break;

            case '5': // modificar
                cout << "Ingrese el ID del Administrador2 a modificar: ";
                fflush( stdin );
                cin >> respuesta;
                if( Administrador2.buscarId( atoi( respuesta.c_str() ), empleadoBuscar ) )
                {
                	nuevo = Administrador2.pedirRegistro();
                	Administrador2.modificar( atoi( respuesta.c_str() ), nuevo );
                }
                else
                    cout << "No existe el Administrador2" << endl;
                break;

            case '6': // eliminar
                cout << "Ingrese el ID del Administrador2 a eliminar: ";
                fflush( stdin );
                cin >> respuesta;
                if( Administrador2.buscarId( atoi( respuesta.c_str() ), empleadoBuscar ) )
                {
	                if( Administrador2.eliminar( atoi( respuesta.c_str() ), empleadoEliminado ) )
	                {
	                	cout << empleadoEliminado << endl;
	                	cout << "EMPLEADO ELIMINADO CON EXITO" << endl;
	                }
	                else
	                    cout << "NO se elimino al Administrador2" << endl;
	            }
	            else
	            	cout << "No existe el Administrador2" << endl;
                break;
            case '8':
            	Administrador2.mostrarLista();
            	break;
	    }
        system( "pause" );

    }while( opcion != '7' );
	Administrador2.guardar();


	return 0;
}



template < typename E >
void mostrar( ListaLigada< E > &L )
{
	int posOriginal = L.posicionActual();
	L.irAlInicio();

	cout << "[";
	for( int i = 0; i < L.obtenerTamanio(); i++ )
	{
		cout << L.obtenerElemento() << "-> " << L.obtenerEnlace();
		if( !( i == ( L.obtenerTamanio() - 1 ) ) )
		{
			cout << ", ";
			L.siguiente();
		}
	}
	cout << "]" << endl;


}
                   break;
              case 5:
                   using namespace std;

class Historial
{
public:
    char numero_orden[4],fecha[30],nombre[35],articulo[25],busqueda[4],codigo[5];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} OrdCom;
void Historial ::Agregar()
{
    cout<<"GENERAR Historial "<<endl;
    cout<<"Numero de la busqueda: ";
    cin.getline(numero_orden,4);
    cin.getline(numero_orden,4);
    cout<<"Fecha: ";
    cin.getline(fecha,30);
    cout<<"nombre: ";
    cin.getline(nombre,35);
    cout<<"Articulo: ";
    cin.getline(articulo,25);
    cout<<"busqueda: ";
    cin.getline(busqueda,4);
    cout<<"codigo: ";
    cin.getline(codigo,5);
    ofstream archivo("historia.txt",ios::app);
    archivo.write((char*)&OrdCom,sizeof(OrdCom));
    archivo.close();
}
void Historial ::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("historia.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"Historial"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Numero de la busqueda: "<<numero_orden<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Articulo: "<<articulo<<endl;
            cout<<"busqueda: "<<busqueda<<endl;
            cout<<"codigo: $"<<codigo<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}
void Historial ::Modificar()
{
    char valor[4];
    ifstream archivo("historia.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"Modificar Orden de Busqueda"<<endl;
        cout<<"Ingrese el numero de busqueda a modificar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_orden,valor)==0)
            {
                cout<<""<<endl;
                cout<<"Nuevo numero de busqueda: ";
                cin.getline(numero_orden,4);
                cout<<"Nueva fecha: ";
                cin.getline(fecha,30);
                cout<<"Nuevo Nombre: ";
                cin.getline(nombre,35);
                cout<<"Nuevo Articulo: ";
                cin.getline(articulo,25);
                cout<<"Nueva Busqueda: ";
                cin.getline(busqueda,4);
                cout<<"Codigo: ";
                cin.getline(codigo,5);
                ofstream archivo("historia.txt",ios::app);
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }

        }
        archivo.close();
        archivo2.close();
        remove("historia.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="compras.txt";
        rename(oldname,newname);
    }
}
void Historial ::Eliminar()
{
    char valor[4];
    int opcion=0;
    ifstream archivo("historia.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"Eliminar Orden De Busqueda"<<endl;
        cout<<"Ingrese el numero de busqueda a eliminar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_orden,valor)==0)
            {
                cout<<"\tOrden Encontrada"<<endl;
                cout<<"Orden de Busqueda: "<<numero_orden<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Articulo: "<<articulo<<endl;
                cout<<"Busqueda: "<<busqueda<<endl;
                cout<<"Codigo: $"<<codigo<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&OrdCom,sizeof(OrdCom));
                }
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
        }
        archivo.close();
        archivo2.close();
        remove("historia.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="historia.txt";
        rename(oldname,newname);
    }

}
void Historial ::Buscar()
{
    char valor[4];
    ifstream archivo("historia.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"Buscar Oeden De Busqueda"<<endl;
        cout<<"Ingrese el numero de Busqueda a buscar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        archivo.read((char*)&OrdCom,sizeof(OrdCom));
        if(strcmp(numero_orden,valor)==0)
        {
            cout<<"\tOrden Encontrada"<<endl;
            cout<<"Orden de Busqueda: "<<numero_orden<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Articulo: "<<articulo<<endl;
            cout<<"Busqueda: "<<busqueda<<endl;
            cout<<"Codigo: $"<<codigo<<endl;
        }
        else
        {
            cout << "Orden no encontrada..." << endl;
        }
    }
    archivo.close();
}
void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}
int main()
{
    int op;
    do
    {
        system("cls");
        cout<<"1.-Capturar" <<endl;
        cout<<"2.-Imprimir todo" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            OrdCom.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            OrdCom.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            OrdCom.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            OrdCom.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            OrdCom.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}

                   break;
              default:
                   printf ("Opción no válida\n");
                   break;
    }

    system("PAUSE");
    return 0;
}
