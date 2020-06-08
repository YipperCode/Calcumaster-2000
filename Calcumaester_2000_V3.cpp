/**
* <meta charset="UTF-8">
* <h1>Calcumaster 2000</h1>
* Este programa permite calcular diferentes tipos de operaciones.
* <p>
* Esta calcumaster realiza una gran variedad de operaciones, desde operaciones simples como lo son
* las sumas o las restas hasta operaciones como sumas, restas, o divisiones con numeros complejos.
* </p>
* @author Luis Raul Chacon Munoz
* @author Jose Carlos Chaparro Morales
* @author Juan Luis Del Valle Sotelo
* @author Omar Alonso Escapita Chacon
* @author Johann Lozano Enriquez 
* @author Oscar Ariel Quintana Merino
* @return una experiencia inolvidable, como ir al six flags, pero en cuarentena
* @since 2020-05-10
*/


//#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <clocale>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include "complex.h"
#include "fracciones.h"

using namespace std;

void displayMenuTipo();
void displayMenuSimple();
void displayMenuComplejos();
void displaymenuFracciones();
void sumaSimple();
void restaSimple();
void multiplicacionSimple();
void divisionSimple();
void pedirFracciones(int &a, int &b, int &c, int &d, bool e=false);
float *crearArreglo(string stroperacion, int &nValida);
void displayMenuTrigonometricas(void);
void doublelog(void);
void natlog(void);
void exponente(void);
void raiz(void);
long double factorial(int);
void invofact(void);
void seno(double argumentoacalcular, string & argumentos, bool rad);
void coseno(double argumentoacalcular, string & argumentos, bool rad);
void tangente(double argumentoacalcular, string & argumentos, bool rad);
void secante(double argumentoacalcular, string & argumentos, bool rad);
void cosecante(double argumentoacalcular, string & argumentos, bool rad);
void cotangente(double argumentoacalcular, string & argumentos, bool rad);
void seninv(double argumentoacalcular, string & argumentos, bool rad);
void cosinv(double argumentoacalcular, string & argumentos, bool rad);
void taninv(double argumentoacalcular, string & argumentos, bool rad);

/**
* <h2>Main</h2>
Llamadas a las funciones para resolver las operaciones matematicas, 
<p>
* Descricpion mas especifica de lo que hace la funcion
* @author gamertag
* @exception
* @param name descricpion breve
* @return tipo de dato descricpion de lo que regresa
* @since 2020-mm-dd
*/

int main(){

    setlocale(LC_CTYPE, "spanish");
    //locale::global(std::locale("spanish"));

    void (*ptrfunmenus[4])(void) = {displayMenuSimple, displayMenuComplejos, displaymenuFracciones, displayMenuTrigonometricas};
    
    string opcionmenu1;
    int iopcionmenu1;
    bool bopcionmenu1 = true;

    cout << "Calculmaster 2000 V3"<< endl;

    do{
        try{
            displayMenuTipo();

            cin >> opcionmenu1;
            
            if (!isValidInt(opcionmenu1))			
                throw "Ingrese una opción válida";
            if ((stoi(opcionmenu1))<1 || (stoi(opcionmenu1))>5)
            	throw "Ingrese un número válido";

            iopcionmenu1=stoi(opcionmenu1);
            bopcionmenu1=false;
            
            }catch(const char *errmenu){
                cout << errmenu << endl;
            }

        //do{
            switch(iopcionmenu1){
                //Menu simple
                case 1:
                    (*ptrfunmenus[0])();
                break;
                //Menu numeros complejos
                case 2:
                    (*ptrfunmenus[1])();
                break;

                //Menu fracciones
                case 3:
                    (*ptrfunmenus[2])();
                break;

                //Menu trigonometricas
                case 4:
                    (*ptrfunmenus[3])();
                break;                

                case 5:
                    cout << "Gracias por usar la Calculmaster 2000" << endl;
                break;
            }
        //}while(iopcionmenu1!=5);

    }while(bopcionmenu1 || (iopcionmenu1 != 5));

    return 0;
}

/**
* <h2>displayMenuTipo</h2>
<p>
* Este procedimiento muestra al usuario, las opciones principales de la Calcumaster2000,
* presentandole los diferentes menus a los que puede acceder
* @author Luis Chacon
* @since 2020-13-05
*/

void displayMenuTipo(){
    cout<< "\n \tMENU PRINCIPAL\n" << endl;

    cout<< "Seleccione el tipo de operación: " << endl
        << "1.- Operaciones simples" << endl
        << "2.- Operaciones con números complejos" << endl
        << "3.- Operaciones con fracciones" << endl
        << "4.- Funciones trigonométricas" << endl
        << "5.- SALIR" << endl
        << "Opción: " <<endl;
}

/**
* <h2>displayMenuSimple</h2>
<p>
* Este procedimiento despliega el menu de las 9 operaciones simples que se pueden seleccionar en la consola
</p>
* @author Luis Chacon
* @since 2020-05-13
*/
void displayMenuSimple(){
    void (*ptrfuncsimp[9])(void) = {sumaSimple, restaSimple, multiplicacionSimple, divisionSimple, exponente, raiz, invofact, doublelog, natlog};
    string opcionmenusimple;
    int iopcionmenusimple;
    bool novalidopcionmenusimple = true;
    
    do{
    cout<< "\n\tOPERACIONES SIMPLES\n" << endl
        << "Seleccione el tipo de operación SIMPLE:" << endl
        << "1.- Suma" << endl
        << "2.- Resta" << endl
        << "3.- Multiplicación" << endl
        << "4.- División" << endl
        << "5.- Potencia" << endl
        << "6.- Raíz"<< endl
        << "7.- Factorial" << endl
        << "8.- Logaritmo" <<endl
        << "9.- Logaritmo natural"<<endl
        <<"10.- REGRESAR"<<endl
        <<"Opción: ";

        do{
            try{
            cin >> opcionmenusimple;
                        
            if (isValidInt(opcionmenusimple) && (stoi(opcionmenusimple)>=1 && stoi(opcionmenusimple)<=10)){
                novalidopcionmenusimple = false;
                iopcionmenusimple = stoi(opcionmenusimple);
            }
            else
                throw "Ingrese un caracter válido";
            
            
            }catch(const char *errmenu1){
                cout << errmenu1 << endl;
            }

        }while(novalidopcionmenusimple);

        if(iopcionmenusimple != 10)
            (*ptrfuncsimp[iopcionmenusimple-1])();

    }while(iopcionmenusimple != 10);
}

/**
* <h2>displayMenuComplejos</h2>
<p>
* Este procedeimiento despliega el menu de las 4 operaciones que se pueden realizar con los numeros complejos
* para que el usuario seleccione la que quiere llevar a cabo
* @author Jose Chaparro
* @since 2020-05-13
*/
void displayMenuComplejos(void){
    void (*ptrcomp[4])(void) = {sumaComplejos, restaComplejos, multiplicacionComplejos, divisionComplejos};
    string opcionscomp;
    int opcioncom;
    bool novalidocom = true;
    
    do{
        cout<< "\n \tOPERACIONES CON COMPLEJOS\n" << endl
            << "1.- Suma de Complejos" << endl
            << "2.- Resta de Complejos" << endl
            << "3.- Multiplicación de Complejos" << endl
            << "4.- División de Complejos" << endl
            << "5.- REGRESAR" << endl
            << "Opción: ";

        do{
            cin >> opcionscomp;

            if(isValidInt(opcionscomp) && (stoi(opcionscomp) >= 1 && stoi(opcionscomp) <= 5 )){
                novalidocom = false;
                opcioncom = stoi(opcionscomp);
                if(opcioncom != 5)
                    (*ptrcomp[opcioncom-1])();
                    
            }else{
                cout<<"Reingrese la opción: ";
            }
            
        }while(novalidocom);

    }while(opcioncom != 5);
}
  //  cout<<"5.- REGRESAR"<<endl;


/**
* <h2>displayMenuFracciones</h2>
<p>
* Este procedimiento despliega el menu de las 4 operaciones que se pueden realizar con fracciones
* para que el usuario seleccione la que quiere llevar a cabo
</p>
* @author Jose Chaparro
* @since 2020-05-13
*/
void displaymenuFracciones(void){
    void (*ptrfracc[4])(void) = {sumaFraccion, restaFraccion, multiplicacionFraccion, divisionFraccion};
    string opcions;
    int opcion;
    bool novalidop = true;
    do{
        cout<< "\n \tOPERACIONES CON FRACCIONES\n" << endl
            << "1.- Suma de Fracciones" << endl
            << "2.- Resta de Fracciones" << endl
            << "3.- Multiplicación de Fracciones" << endl
            << "4.- División de Fraccinoes" << endl
            << "5.- REGRESAR" << endl
            << "Opción: ";

        do{
            cin >> opcions;

            if(isValidInt(opcions) && (stoi(opcions) >= 1 && stoi(opcions) <= 5 )){
                novalidop = false;
                opcion = stoi(opcions);
                if(opcion != 5)
                    (*ptrfracc[opcion-1])();
                    
            }else{
                cout<<"Reingrese la opción: ";
            }
            
        }while(novalidop);

    }while(opcion !=5);
}

/**
* <h2>displayMenuTrigonometricas</h2>
* <p>
* Este procedimiento muestra las 9 opciones dentro del menu de las funciones trigonometricas
* para que seleccione una opcion y proceda a elaborarla
* Cuando ya escogio, le pregunta si usara radianes o grados y luego ya calcula la funcion que ingresemos
* </p>
* @author Jose Chaparro
* @author Luis Chacon
* @since 2020-05-13
*/
void displayMenuTrigonometricas(void){
    void (*ptrtrig[9])(double, string &, bool) = {seno, coseno,tangente,cotangente,secante,cosecante,seninv,cosinv,taninv};
    string opcionts, radograd, argumentos;
    int opciont;
    double argumento = 1;
    bool novalidot = true, bradograd = true, novalidarg = true, radbool=true;

    do{
        cout<< "\n \tFUNCIONES TRIGONOMÉTRICAS\n"<<endl;

        cout<< "1.- Seno" << endl
            << "2.- Coseno" << endl
            << "3.- Tangente" << endl
            << "4.- Cotangente" << endl
            << "5.- Secante" << endl
            << "6.- Cosecante" << endl
            << "7.- Sen inverso" << endl
            << "8.- Cos inverso" << endl
            << "9.- Tan inversa" << endl
            <<"10.- REGRESAR"<<endl
            << "Opción: ";

        do{

            cin >> opcionts;
            if(isValidInt(opcionts) && (stoi(opcionts) >= 1 && stoi(opcionts) <= 10 )){
                novalidot = false;
                opciont = stoi(opcionts);
                
                if(opciont != 10){
                    cout << "¿Con qué vas a trabajar?" << endl
                    << "Ingrese 1 para leer el dato en grados" << endl
                    << "Ingrese 2 para leer el dato en radianes" << endl;

                    do{
                        cin >> radograd;
                        
                        
                        if(isValidInt(radograd) && (stoi(radograd) == 1 || stoi(radograd) == 2 )){
                            
                            bradograd = false;

                            do{
                            
                                cout << "Ingrese el argumento: ";

                                cin >> argumentos;
                            
                                if( isValidFloat(argumentos)){
                                    novalidarg = false;
                                    argumento = stof(argumentos);
                                }
                            
                            }while(novalidarg);
							radbool=true;
                            if(stoi(radograd) == 1){
                                radbool=false;
                                if (opciont<7)
                                	argumento *= (M_PI/180);
                            }
                            (*ptrtrig[opciont-1])(argumento, argumentos, radbool);

                        }else{
                            cout << "Reingrese la opción: " << endl;
                        }
                
                        
                    
                    }while(bradograd);

                }
            
            }
            else cout << "Reingresa la opción: ";

        }while(novalidot);
    
    }while(opciont != 10);

}

void seno(double argumentoacalcular, string & argumentos, bool rad){

    cout << "sen(" << argumentos << ") = " << sin(argumentoacalcular) << endl;
}

void coseno(double argumentoacalcular, string & argumentos, bool rad){
    cout << "cos(" << argumentos << ") = " << cos(argumentoacalcular) << endl;
}

void tangente(double argumentoacalcular, string & argumentos, bool rad){
	int argumento;
	if (rad) {
		argumento=stof(argumentos)*180/M_PI;
		if ((argumento+1)%90==0) argumento++;
		if ((argumento-1)%90==0) argumento--;
		//cout << "Argumento transformado " << argumento << endl;
	}
	else {
		argumento=stoi(argumentos);
	}
	if ((argumento%90==0 && argumento%180!=0))
		cout << "tan(" << argumentos << ") tiende a infinito";
	else
    	cout << "tan(" << argumentos << ") = " << tan(argumentoacalcular) << endl;
}

void cotangente(double argumentoacalcular, string & argumentos, bool rad){
	int argumento;
	if (rad) {
		argumento=stof(argumentos)*180/M_PI;
		if ((argumento+1)%90==0) argumento++;
		if ((argumento-1)%90==0) argumento--;
	}
	else {
		argumento=stoi(argumentos);
	}
	if ((argumento%180==0 || argumento==0))
		cout << "cot(" << argumentos << ") tiende a infinito";
	//if (stoi(argumentos)%180==0 || stoi(argumentos)==0)
	//	cout << "cot(" << argumentos << ") tiende a infinito";
	else
    	cout << "cot(" << argumentos << ") = " << (1.0/tan(argumentoacalcular)) << endl;
}

void secante(double argumentoacalcular, string & argumentos, bool rad){
	int argumento;
	if (rad) {
		argumento=stof(argumentos)*180/M_PI;
		if ((argumento+1)%90==0) argumento++;
		if ((argumento-1)%90==0) argumento--;
	}
	else {
		argumento=stoi(argumentos);
	}
	if ((argumento%90==0 && argumento%180!=0))
		cout << "sec(" << argumentos << ") tiende a infinito";
	else
    	cout << "sec(" << argumentos << ") = " << (1.0/cos(argumentoacalcular)) << endl;
}

void cosecante(double argumentoacalcular, string & argumentos, bool rad){
	int argumento;
	if (rad) {
		argumento=stof(argumentos)*180/M_PI;
		if ((argumento+1)%90==0) argumento++;
		if ((argumento-1)%90==0) argumento--;
	}
	else {
		argumento=stoi(argumentos);
	}
	if ((argumento%180==0 || argumento==0))
		cout << "csc(" << argumentos << ") tiende a infinito";
//	if (stoi(argumentos)%180==0 || stoi(argumentos)==0)
//		cout << "csc(" << argumentos << ") tiende a infinito";
	else
    	cout << "csc(" << argumentos << ") = " << (1.0/sin(argumentoacalcular)) << endl;
}

void seninv(double argumentoacalcular, string & argumentos, bool rad){
	//cout << "bool "<<rad<<endl;
	if (argumentoacalcular > 1 || argumentoacalcular < -1)
		cout<<"arcsen("<<argumentos<<") No está definido";
	else{
		if (!rad) cout << "arcsen("<<argumentos<<") = " << asin(argumentoacalcular)*180/M_PI <<"°" << endl;
    	else
    		cout<<"arcsen(" << argumentos << ") = " << asin(argumentoacalcular) <<" rad" << endl;
	}	
}

void cosinv(double argumentoacalcular, string & argumentos, bool rad){
	if (argumentoacalcular > 1 || argumentoacalcular < -1)
		cout<<"arccos("<<argumentos<<") No está definido";
	else{
		if (!rad) cout << "arccos("<<argumentos<<") = " << acos(argumentoacalcular)*180/M_PI <<"°" << endl;
    	else
    		cout<<"arccos(" << argumentos << ") = " << acos(argumentoacalcular) <<" rad" << endl;
}
}

void taninv(double argumentoacalcular, string & argumentos, bool rad){
    if (!rad) cout << "arctan("<<argumentos<<") = " << atan(argumentoacalcular)*180/M_PI <<"°" << endl;
    	else
    		cout<<"arctan(" << argumentos << ") = " << atan(argumentoacalcular) <<" rad" << endl;
}
/**
* <h2>crearArreglo</h2>
* Esta funcion regresa un arreglo dinamico de numeros flotantes.
* <p>
* La funcion permite crear un arreglo de los numeros que se van a sumar, restar o multiplicar, esto se logra
* pidiendo la cantidad de numeros a usar y verifica si este numero ingraso es un entero valido, para que no
* haya problema a la hora de crear el arreglo dinamico, adem'as de modificar una variable que recibe como parametro
* por referencia, el cual es la cantidad de numeros a utilizar o el tamano del arreglo.
* </p>
* @author Juan Luis Del Valle Sotelo
* @exception excepcionEnteroNoValido Esta excepcion se lanza cuando un entero no es valido, ya sea que es menor a uno o no sea un caracter numerico
* @param stroperacion Es el tipo de operacion que se va a realizar, es una cariable de tipo string que permite mostrar
* al usuario que operacion esta a punto de realizar.
* @param nValida Es la cantidad de de numeros o elementos que va a tener el arreglo dinamico, al ser un parametro por
* referencia, permite saber el numero de elementos inclusive en la funcion que invoca est funcion.
* @return float *crearArreglo Regresa un arreglo dinamico de numeros flotantes, que fueron introducidos por el usuario.
* @since 2020-05-13
*/
float *crearArreglo(string stroperacion, int &nValida){

    string n, valor;
    float *arreglo=NULL;
    
    do{
        try {
            cout << "Dame la cantidad de números a " << stroperacion <<": ";
            cin >> n;
            if (!isValidInt(n))
		throw 1;
	    if ((stoi(n))<1)
		throw 2;
        }

        catch(int excepcionEnteroNoValido){
			if (excepcionEnteroNoValido == 2) cout << "Error, el número ingresado debe ser positivo \n";
			if (excepcionEnteroNoValido == 1) cout << "Error, el número ingresado debe ser entero \n";
		}

    }while(!isValidInt(n)||(stoi(n))<1);
    
    nValida=stoi(n);
    //cout  << "nvalida " << nValida << "\n";

    try{
        arreglo = new float[nValida];
    }
    catch (...){
        cout << "No se pudo asignar memoria";
		exit(-1);
    }

    for (int i=0; i<nValida; i++){
        try{
            cout << "Ingresa el valor del número " << i+1 << ": ";
            cin >> valor;
            if (!isValidFloat(valor)) throw 3;
            arreglo[i]=stof(valor);
            
        }
        catch(...){
            cout << "Error, el número ingresado debe ser válido \n";
            i--;
        }
    }

    return arreglo;
}


/**
* <h2>sumaSimple</h2>
 <p>
* El procedimiento suma los n valores introducidos en el apuntador float *sumandos por la funcion crearArreglo
* utilizando la variable suma para acumular la sumatoria de los elementos en sumandos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enriquez
* @since 2020-05-13
*/
void sumaSimple(){
    
    int n=0;
    float *sumandos, suma = 0;
    
    sumandos = crearArreglo("sumar", n);
    
    for(int i = 0; i<(n); i++){
        //cout << "numero" << sumandos[i];
        suma += sumandos[i];
        
    }
    
    cout << "El resultado es: " << suma << endl;
    
}

/**
* <h2>restaSimple</h2>
 <p>
* El procedimiento resta los n valores introducidos en el apuntador float *restandos por la funcion 
* crearArreglo utilizando la variable resta para acumular el resultado de las operaciones en los elementos
* de restandos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enriquez
* @since 2020-05-13
*/
void restaSimple(){
    int n = 0;
    float *restandos, resta=0;

    restandos = crearArreglo("restar", n);
    resta = restandos[0];

    for(int i = 1; i < n; i++){
        resta -= restandos[i];
    }
    
    cout << "El resultado es: " << resta << endl;
}

/**
* <h2>multiplicacionSimple</h2>
 <p>
* El procedimiento multiplica los n valores introducidos en el apuntador float *multiplos por la funcion 
* crearArreglo utilizando la variable multiplicacion para acumular el resultado de las operaciones en los
* elementos de multiplos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enriquez
* @since 2020-05-13
*/
void multiplicacionSimple(){
    int n = 0;
    float *multiplos, multiplicacion=1;
    multiplos = crearArreglo("multiplicar", n);
    
    for(int i = 0; i<n; i++){
        multiplicacion*=multiplos[i];
    }
    cout << "El resultado es: " << multiplicacion << endl;
}

/**
* <h2>divisionSimple</h2>
 <p>
* El procedimiento divide los dos valores introducidos en las variables float numerador y denominador.
* Utiliza un ciclo para asegurarse de que las variables reciban valores validos.
 </p> 
* @exception excepcionNumerador  Esta excepcion es lanzada siempre que el numerador recibe un caracter no numerico
* @exception excepcionDenominador Esta excepcion es lanzada siempre que el denominador recibe un caracter no numerico
*                                 o es 0
* @author Omar Alonso Escápita Chacón
* @since 2020-05-13
*/
void divisionSimple(){
    string numeradors, denominadors;
    float numerador=0, denominador=0;
    bool novalidnumerador = true;
    
    cout << "Ingrese el numerador: ";
    while(novalidnumerador){
        try{

            cin>>numeradors;

            if(!isValidFloat(numeradors)) throw numeradors;

            novalidnumerador = false;
            numerador = stof(numeradors);
            
        }catch(string excepcionNumerador){
            cout << "Error, valor " << excepcionNumerador << " inválido." << endl;
            
            cout << "Vuelve a ingresar el numerador: ";
        }
    }


    cout << "Ingrese el denominador: ";

    while(denominador==0){
        try{

            cin >> denominadors;
            
            if (!isValidFloat(denominadors) || stof(denominadors) == 0) throw denominadors;
            
            denominador = stof(denominadors);

        }catch(string excepcionDenominador){
            cout << "Error, división entre " << excepcionDenominador << " inválida." << endl;
            denominador=0;
            cout << "Vuelve a ingresar el denominador: ";
        }
        
    }
    cout << "Resultado " << numerador << "/" << denominador << " = " <<numerador/denominador << endl;
}
/**
* <h2>exponente</h2>
* Este procedimiento se encarga de elevar un numero ingresado por el usuario, a otro igualmente ingresado por el usuario
* <p>
* El procedimiento evita que el usuario ingrese caracteres invalidos tanto para el coeficiente, como para el exponente de la funcion.
* finalmente despliega el resultado en pantalla
* </p>
* @author Jose Chaparro
* @since 2020-05-13
*/
void exponente(void){
    float coeficiente;
    int exponente;
    string coeficientes, exponentes;
    bool novalidcoef = true , novalidexp = true;
    
    do{
        cout << "Ingrese el número al cual le quiere aplicar potencia: ";
        cin >> coeficientes;
            
        if(isValidFloat(coeficientes)){
            novalidcoef = false;
            coeficiente = stof(coeficientes);
        }else{
            cout << "argumento a calcular no válido, reingrese el coeficiente: " << endl;
        }

    }while(novalidcoef);

    do{
            cout << "Ingrese el exponente: ";
            cin >> exponentes;
            

            if(isValidInt(exponentes)){
                novalidexp = false;
                exponente = stoi(exponentes);
            }else{
                cout << "exponente no válido, reingrese el exponente: " << endl;
            }
                

            
    }while(novalidexp);
    cout << coeficiente << "^"<<exponente<<" = " << pow(coeficiente,exponente) << endl;
	/*try{
		if (((exponente%1) !=0) &&  ((exponente%0.5)==0) && ((coeficiente)<0))
			throw "Error: no se pueden calcular raíces pares en números negativos";
		cout << coeficiente << "^"<<exponente<<" = " << pow(coeficiente,exponente) << endl;
	}
    catch (const char *exceptionRaizNeg) {
    	cout << exceptionRaizNeg << "\n ";
	}
	*/
}

/**
* <h2>raiz</h2>
* Este procedimiento se encarga de calcular la raiz n de cualquier numero
* <p>
* El procedimiento evita que el usuario ingrese caracteres invalidos tanto para el coeficiente,
* como para la raiz de la funcion. Finalmente despliega el resultado en pantalla
* </p>
* @author Jose Chaparro
* @since 2020-05-13
*/
void raiz(void){
    string coeficientes, raizs;
    double coeficiente, raiz;
    bool novalidroot = true, novalidcoef = true;
    
    do{
        cout << "Ingrese el número al cual le quiere sacar raíz: ";
        cin >> coeficientes;

        if(isValidFloat(coeficientes) && stof(coeficientes) >= 0){
            novalidcoef = false;
            coeficiente = stof(coeficientes);
        }else{
            cout << "argumento a calcular no válido, reingrese el coeficiente: " << endl;
        }
        
    }while(novalidcoef);

    do{
        cout << "Ingrese el número de la raíz: ";
        cin >> raizs;

        if(isValidFloat(raizs) && stof(raizs) != 0){
            novalidroot = false;
            raiz = stof(raizs);
        }else{
            cout << "argumento a calcular no válido, reingrese la raíz: " << endl;
        }
        
    }while(novalidroot);
    
    try{
    	if (coeficiente==0 && raiz<0)
    		throw "No se pueden calcular raíces negativas de cero";
    	cout << "raíz "<< raiz << " de "<<coeficiente<< " = " << pow(coeficiente, (1/raiz)) << endl;
	}
	catch (const char *exceptionRaizNeg){
		cout << exceptionRaizNeg << "\n";
	}
    
}
/**
* <h2>factorial</h2>
* En caso de que el parametro n sea 0, devolvera 1, si no, la funcion se llama a si misma
* <p>
* Esta funcion implementa la recursividad utilizando al mismo tiempo el operador condicional ?:
* que se encarga de devolver el resultado 1 cuando n sea igual a 0 y de llamarse a si misma
* para asi multiplicarse por si misma
* </p>
* @author Jose Chaparro
* @param n es el numero entero del cual se quiere obtener el factorial
* @return int una vez la recursividad termina, se regresa el valor total de las multiplicaciones realizadas con recursividad 
* @since 2020-05-12
*/
long double factorial(int n){
    return n==0 ? 1 : n*factorial(n-1);
}
/**
* <h2>factorial</h2>
* Esta procedimiento se verifica el párametro pasado a la función factorial y la invoca
* <p>
* Esta se verifica mediante el manejo de excepciones que el párametro pasado a la función factorial sea válido
* </p>
* @author Jose Chaparro
* @since 2020-05-12
*/
void invofact(void){
    string factoria;
    int factorialValido=0;
    do{
        try {
            cout << "Dame el número del cual quieres su factorial \n";
            cin >> factoria;
            if (!isValidInt(factoria) || stoi(factoria)<0)
                throw 1;
                
            factorialValido=stoi(factoria);
    
   			cout << factorialValido << "! = " << factorial(factorialValido) << endl;
        }

        catch(int excepcionNumInvalido){
            if (excepcionNumInvalido == 1) cout << "Error, el número ingresado debe ser entero positivo \n";
        }

    }while(!isValidInt(factoria) || stoi(factoria)<0);
    
}

/**
* <h2>factorial</h2>
* Este procedimiento calcula el logaritmo base n de x y lo muestra en pantalla
* <p>
* Esta se verifica mediante el manejo de excepciones que los valores ingresados sean
* correctos y se calcula el logaritmo base n de x y lo muestra en pantalla
* </p>
* @author Jose Chaparro
* @author Juan Luis Del Valle Sotelo
* @since 2020-05-12
*/
void doublelog(void){
    float base, x;
    string bases, xs;
    
    cout << "Ingrese la base " << endl;
    
    do {
    	cin >> bases;
    	try {
    		if (!isValidFloat(bases) || (stof(bases)<=0) || (stof(bases)==1))
    			throw "Ingrese un número válido, no están definidos valores negativos, el cero, ni el uno como bases";
    		base=stof(bases);
		}
		catch (const char *exceptionNumInvalido) {
			cout << exceptionNumInvalido << "\n";
		}	
	}
	while (!isValidFloat(bases) || (stof(bases)<=0) || (stof(bases)==1));
    cout << "Ingrese el número al que quiere calcular el logaritmo" << endl;
    
    do {
    	cin >> xs;
    	try {
    		if (!isValidFloat(xs) || (stof(xs)<=0)){
    			throw "Ingrese un número válido, no están definidos logaritmos para valores iguales o menores a cero";
				}
    		x=std::stof(xs);
		}
		catch (const char *exceptionNumInvalido) {
			cout << exceptionNumInvalido << "\n";
		}
	}
	while (!isValidFloat(xs) || std::stof(xs)<=0);
    cout << "log base " << base << " de " << x << " = " << (float)(log(x) / log(base)) << endl;
}

/**
* <h2>factorial</h2>
* Este procedimiento calcula el logaritmo natural de x y lo muestra en pantalla
* <p>
* Esta se verifica mediante el manejo de excepciones que los valores ingresados sean
* correctos y se calcula el logaritmo natural x y lo muestra en pantalla
* </p>
* @author Jose Chaparro
* @author Juan Luis Del Valle Sotelo
* @since 2020-05-12
*/
void natlog(void){
    double x;
    string xs;
    cout << "Ingrese el número para calcular el logaritmo natural" << endl;
    
    do {
    	cin >> xs;
    	try {
    		if (!isValidFloat(xs) || (stof(xs)<=0))
    			throw "Ingrese un número válido, no están definidos logaritmos naturales para valores iguales o menores a cero";
    		x=stod(xs);
		}
		catch (const char *exceptionNumInvalido) {
			cout << exceptionNumInvalido << "\n";
		}
    	
	}
	while (!isValidFloat(xs) || (stof(xs)<=0));
    cout << "Ln("<<x<<") = " << log(x) << endl;
}

/*void formulaGeneral(){
    //Se pedira los valores de la formula:
    //axA2 + bx + c;
    //Y despues se utilizara la formula general
    
    int ax, bx, c, colchon,colchon2;
    do{
        try{
        cout << "Ingrese aX" << endl;
        cin >> ax;
        
        if (ax==0){
            throw "Ingrese un número diferente de cero";
        }
        }catch(...){
            
        }
        cout << "Ingrese bX" << endl;
        cin >> bx;
        cout << "Ingrese cX" << endl;
        //try{
            //dentro de la raiz
            colchon= pow(bx,2) - (4*ax*c);
            if (colchon<0){
                cout << "(" << -bx << "+sqrt" << colchon << ")/" << 2*ax << endl;
                cout << "(" << -bx << "-sqrt" << colchon << ")/" << 2*ax << endl;
            }
            colchon= sqrt(colchon);
            
        //}


    }while(true);
    
    
}*/
