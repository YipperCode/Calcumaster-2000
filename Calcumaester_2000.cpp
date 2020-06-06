/**
* <meta charset="UTF-8">
* <h1>Calcumaster 2000</h1>
* Este programa permite calcular diferentes tipos de operaciones.
* <p>
* Esta calcumaster realiza una gran variedad de operaciones, desde operaciones simples como lo son
* las sumas o las restas hasta operaciones como sumas, restas, o divisiones con n�meros complejos.
* </p>
* @author Luis Ra�l Chac�n Mu�oz
* @author Jos� Carlos Chaparro Morales
* @author Juan Luis Del Valle Sotelo
* @author Omar Alonso Esc�pita Chac�n
* @author Johann Lozano Enr�quez 
* @author Oscar Ariel Quintana Merino
* @return una experiencia inolvidable, como ir al six flags, pero en cuarentena
* @since 2020-05-10
*/

//Proyecto Chido
//TODO: EVITAR OVERFLOW

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
void seno(double &argumentoacalcular);
void coseno(double &argumentoacalcular);
void tangente(double &argumentoacalcular);
void secante(double &argumentoacalcular);
void cosecante(double &argumentoacalcular);
void cotangente(double &argumentoacalcular);
void seninv(double &argumentoacalcular);
void cosinv(double &argumentoacalcular);
void taninv(double &argumentoacalcular);

/**
* <h2>Main</h2>
Llamadas a las funciones para resolver las operaciones matem�ticas, 
<p>
* Descricpi�n m�s espec�fica de lo que hace la funci�n
* @author gamertag
* @exception
* @param name descricpi�n breve
* @return tipo de dato descricpi�n de lo que regresa
* @since 2020-mm-dd
*/

int main(){

    setlocale(LC_ALL, "spanish");
    //locale::global(std::locale("spanish"));

    void (*ptrfunmenus[4])(void) = {displayMenuSimple, displayMenuComplejos, displaymenuFracciones, displayMenuTrigonometricas};
    
    string opcionmenu1, opcionmenusimple, opcionmenucomplejo, opcionmenufrac, opcionmenutri, simple, factoria;
    int iopcionmenu1, iopcionmenusimple, iopcionmenucomplejo, iopcionmenufrac, iopcionmenutri, isimple;
    bool bopcionmenu1 = true, bopcionmenusimple = false, bopcionmenucomplejo = false, bopcionmenufrac = false, bopcionmenutri = false, bsimple=false;

    cout << "Calculmaster v2000.2"<< endl;

    do{
        try{
            displayMenuTipo();

            cin >> opcionmenu1;
            
            if (!isValidInt(opcionmenu1))				
                throw "Ingrese una opci�n v�lida";

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
* @author Luis Chac�n
* @since 2020-13-05
*/

void displayMenuTipo(){
    cout<< "\n \tMEN� PRINCIPAL\n" << endl;

    cout<< "Seleccione el tipo de operaci�n: " << endl
        << "1.- Operaciones simples" << endl
        << "2.- Operaciones con n�meros complejos" << endl
        << "3.- Operaciones con fracciones" << endl
        << "4.- Funciones trigonom�tricas" << endl
        << "5.- SALIR" << endl
        << "Opci�n: " <<endl;
}

/**
* <h2>displayMenuSimple</h2>
<p>
* Este procedimiento despliega el men� de las 9 operaciones simples que se pueden seleccionar en la consola
</p>
* @author Luis Chac�n
* @since 2020-05-13
*/
void displayMenuSimple(){
    void (*ptrfuncsimp[9])(void) = {sumaSimple, restaSimple, multiplicacionSimple, divisionSimple, exponente, raiz, invofact, doublelog, natlog};
    string opcionmenusimple;
    int iopcionmenusimple;
    bool novalidopcionmenusimple = true;
    
    do{
    cout<< "\n\tOPERACIONES SIMPLES\n" << endl
        << "Seleccione el tipo de operaci�n SIMPLE:" << endl
        << "1.- Suma" << endl
        << "2.- Resta" << endl
        << "3.- Multiplicaci�n" << endl
        << "4.- Divisi�n" << endl
        << "5.- Potencia" << endl
        << "6.- Ra�z"<< endl
        << "7.- Factorial" << endl
        << "8.- Logaritmo" <<endl
        << "9.- Logaritmo natural"<<endl
        <<"10.- REGRESAR"<<endl
        <<"Opci�n: ";

        do{
            try{
            cin >> opcionmenusimple;
                        
            if (isValidInt(opcionmenusimple) && (stoi(opcionmenusimple)>=1 || stoi(opcionmenusimple)<=10)){
                novalidopcionmenusimple = false;
                iopcionmenusimple = stoi(opcionmenusimple);
            }
            else
                throw "Ingrese un caracter v�lido";
            
            
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
* @author Jos� Chaparro
* @since 2020-05-13
*/
void displayMenuComplejos(void){
    void (*ptrcomp[4])(void) = {sumaComplejos, restaComplejos, multiplicacionComplejos, divisionComplejos};
    string opcionscomp;
    int opcioncom;
    bool novalidocom = true;
    
    do{
        cout<< "OERACIONES CON COMPLEJOS\n" << endl
            << "1.- Suma de Complejos" << endl
            << "2.- Resta de Complejos" << endl
            << "3.- Multiplicaci�n de Complejos" << endl
            << "4.- Divisi�n de Complejos" << endl
            << "5.- REGRESAR" << endl
            << "Opci�n: ";

        do{
            cin >> opcionscomp;

            if(isValidInt(opcionscomp) && (stoi(opcionscomp) >= 1 && stoi(opcionscomp) <= 5 )){
                novalidocom = false;
                opcioncom = stoi(opcionscomp);
                if(opcioncom != 5)
                    (*ptrcomp[opcioncom-1])();
                    
            }else{
                cout<<"Reingrese la opci�n";
            }
            
        }while(novalidocom);

    }while(opcioncom != 5);
}
  //  cout<<"5.- REGRESAR"<<endl;


/**
* <h2>displayMenuFracciones</h2>
<p>
* Este procedimiento despliega el men� de las 4 operaciones que se pueden realizar con fracciones
* para que el usuario seleccione la que quiere llevar a cabo
</p>
* @author Jos� Chaparro
* @since 2020-05-13
*/
void displaymenuFracciones(void){
    void (*ptrfracc[4])(void) = {sumaFraccion, restaFraccion, multiplicacionFraccion, divisionFraccion};
    string opcions;
    int opcion;
    bool novalidop = true;
    do{
        cout<< "OERACIONES CON FRACCIONES\n" << endl
            << "1.- Suma de Fracciones" << endl
            << "2.- Resta de Fracciones" << endl
            << "3.- Multiplicaci�n de Fracciones" << endl
            << "4.- Divisi�n de Fraccinoes" << endl
            << "5.- REGRESAR" << endl
            << "Opci�n: ";

        do{
            cin >> opcions;

            if(isValidInt(opcions) && (stoi(opcions) >= 1 && stoi(opcions) <= 5 )){
                novalidop = false;
                opcion = stoi(opcions);
                if(opcion != 5)
                    (*ptrfracc[opcion-1])();
                    
            }else{
                cout<<"Reingrese la opci�n";
            }
            
        }while(novalidop);

    }while(opcion !=5);
}

/**
* <h2>displayMenuTrigonometricas</h2>
* <p>
* Este procedimiento muestra las 9 opciones dentro del men� de las funciones trigonom�tricas
* para que seleccione una opcion y proceda a elaborarla
* Cuando ya escogi�, le pregunta si usar� radianes o grados y luego ya calcula la funcion que ingresemos
* </p>
* @author Jos� Chaparro
* @author Luis Chac�n
* @since 2020-05-13
*/
void displayMenuTrigonometricas(void){
    void (*ptrtrig[9])(double&) = {seno, coseno,tangente,cotangente,secante,cosecante,seninv,cosinv,taninv};
    string opcionts, radograd, argumentos;
    int opciont;
    double argumento = 1;
    bool novalidot = true, bradograd = true, novalidarg = true;

    do{
        cout<< "FUNCIONES TRIGONOM�TRICAS\n"<<endl;

        cout<< "1.- Seno" << endl
            << "2.- Coseno" << endl
            << "3.- Tangente" << endl
            << "4.- Cotangente" << endl
            << "5.- Secante" << endl
            << "6.- Cosecante" << endl
            << "7.- Sen inverso" << endl
            << "8.- Cos inverso" << endl
            << "9.- Tan inversa" << endl
            <<"10.- REGRESAR"<<endl;
            << "Opci�n: ";

        do{

            cin >> opcionts;

            if(isValidInt(opcionts) && (stoi(opcionts) >= 1 && stoi(opcionts) <= 10 )){
                novalidot = false;
                opciont = stoi(opcionts);
                
                if(opciont != 10){
                    cout << "�Con qu� vas a trabajar?" << endl
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

                            if(stoi(radograd) == 1){
                                
                                argumento *= (M_PI / 180);
                            }

                            (*ptrtrig[opciont-1])(argumento);

                        }else{
                            cout << "Reingrese la opci�n" << endl;
                        }
                
                        
                    
                    }while(bradograd);

                }
            
            }

        }while(novalidot);
    
    }while(opciont != 10);

}

void seno(double &argumentoacalcular){

    cout << "sen(" << argumentoacalcular << ") = " << sin(argumentoacalcular) << endl;
}

void coseno(double &argumentoacalcular){
    cout << "cos(" << argumentoacalcular << ") = " << cos(argumentoacalcular) << endl;
}

void tangente(double &argumentoacalcular){
    cout << "tan(" << argumentoacalcular << ") = " << tan(argumentoacalcular) << endl;
}

void cotangente(double &argumentoacalcular){
    cout << "sen(" << argumentoacalcular << ") = " << (1.0/tan(argumentoacalcular)) << endl;
}

void secante(double &argumentoacalcular){
    cout << "sen(" << argumentoacalcular << ") = " << (1.0/cos(argumentoacalcular)) << endl;
}

void cosecante(double &argumentoacalcular){
    cout << "sen(" << argumentoacalcular << ") = " << (1.0/sin(argumentoacalcular)) << endl;
}

void seninv(double &argumentoacalcular){
    cout<<"arcsen("<<argumentoacalcular<<") = "<<asin(argumentoacalcular) << endl;
}

void cosinv(double &argumentoacalcular){
    cout<<"arccos("<<argumentoacalcular<<") = "<<acos(argumentoacalcular) << endl;
}

void taninv(double &argumentoacalcular){
    cout<<"arctan("<<argumentoacalcular<<") = "<<atan(argumentoacalcular) << endl;
}
/**
* <h2>crearArreglo</h2>
* Esta funci�n regresa un arreglo din�mico de n�meros flotantes.
* <p>
* La funci�n permite crear un arreglo de los n�meros que se van a sumar, restar o multiplicar, esto se logra
* pidiendo la cantidad de n�meros a usar y verifica si este n�mero ingraso es un entero v�lido, para que no
* haya problema a la hora de crear el arreglo din�mico, adem'as de modificar una variable que recibe como par�metro
* por referencia, el cual es la cantidad de n�meros a utilizar o el tama�o del arreglo.
* </p>
* @author Juan Luis Del Valle Sotelo
* @exception excepcionEnteroNoValido Esta excepci�n se lanza cuando un entero no es v�lido, ya sea que es menor a uno o no sea un caracter num�rico
* @param stroperaci�n Es el tipo de operaci�n que se va a realizar, es una cariable de tipo string que permite mostrar
* al usuario qu� operaci�n est� a punto de realizar.
* @param nValida Es la cantidad de de n�meros o elementos que va a tener el arreglo din�mico, al ser un par�metro por
* referencia, permite saber el n�mero de elementos inclusive en la funci�n que invoca est funci�n.
* @return float *crearArreglo Regresa un arreglo din�mico de n�meros flotantes, que fueron introducidos por el usuario.
* @since 2020-05-13
*/
float *crearArreglo(string stroperacion, int &nValida){

    string n, valor;
    float *arreglo=NULL;
    //int nValida;
    
    
    do{
        try {
            cout << "Dame la cantidad de n�meros a " << stroperacion <<": ";
            cin >> n;
            if (!isValidInt(n))
				throw 1;
			if ((stoi(n))<1)
				throw 2;
        }

        catch(int excepcionEnteroNoValido){
			if (excepcionEnteroNoValido == 2) cout << "Error, el n�mero ingresado debe ser positivo \n";
			if (excepcionEnteroNoValido == 1) cout << "Error, el n�mero ingresado debe ser entero \n";
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
            cout << "Ingresa el valor del n�mero " << i+1 << ": ";
            cin >> valor;
            if (!isValidFloat(valor)) throw 3;
            arreglo[i]=stof(valor);
            
        }
        catch(...){
            cout << "Error, el n�mero ingresado debe ser v�lido \n";
            i--;
        }
    }

    return arreglo;
}


/**
* <h2>sumaSimple</h2>
 <p>
* El procedimiento suma los n valores introducidos en el apuntador float *sumandos por la funci�n crearArreglo
* utilizando la variable suma para acumular la sumatoria de los elementos en sumandos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enr�quez
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
* El procedimiento resta los n valores introducidos en el apuntador float *restandos por la funci�n 
* crearArreglo utilizando la variable resta para acumular el resultado de las operaciones en los elementos
* de restandos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enr�quez
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
* El procedimiento multiplica los n valores introducidos en el apuntador float *multiplos por la funci�n 
* crearArreglo utilizando la variable multiplicaci�n para acumular el resultado de las operaciones en los
* elementos de multiplos
 </p> 
* @author Juan Luis Del Valle Sotelo
* @author Johann Lozano Enr�quez
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
* Utiliza un ciclo para asegurarse de que las variables reciban valores v�lidos.
 </p> 
* @exception excepcionNumerador  Esta excepci�n es lanzada siempre que el numerador recibe un caracter no num�rico
* @exception excepcionDenominador Esta excepci�n es lanzada siempre que el denominador recibe un caracter no num�rico
*                                 o es 0
* @author Omar Alonso Esc�pita Chac�n
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
            cout << "Error, valor " << excepcionNumerador << " inv�lido." << endl;
            
            cout << "Vuelve a ingresar el numerador: ";
            continue;
        }
    }


    cout << "Ingrese el denominador: ";

    while(denominador==0){
        try{

            cin >> denominadors;
            
            if (!isValidFloat(denominadors) || stof(denominadors) == 0) throw denominadors;
            
            denominador = stof(denominadors);

        }catch(string excepcionDenominador){
            cout << "Error, divisi�n entre " << excepcionDenominador << " inv�lida." << endl;
            denominador=0;
            cout << "Vuelve a ingresar el denominador: ";
            continue;
        }
        
    }
    cout << "Resultado " << numerador << "/" << denominador << " = " <<numerador/denominador << endl;
}
/**
* <h2>exponente</h2>
* Este procedimiento se encarga de elevar un n�mero ingresado por el usuario, a otro igualmente ingresado por el usuario
* <p>
* El procedimiento evita que el usuario ingrese caracteres invalidos tanto para el coeficiente, como para el exponente de la funci�n.
* finalmente despliega el resultado en pantalla
* </p>
* @author Jos� Chaparro
* @since 2020-05-13
*/
void exponente(void){
    float coeficiente, exponente;
    string coeficientes, exponentes;
    bool novalidcoef = true , novalidexp = true;
    
    do{
        cout << "Ingrese el n�mero al cual le quiere aplicar potencia: ";
        cin >> coeficientes;
            
        if(isValidFloat(coeficientes)){
            novalidcoef = false;
            coeficiente = stof(coeficientes);
        }else{
            cout << "argumento a calcular no v�lido, reingrese el coeficiente" << endl;
        }

    }while(novalidcoef);

    do{
            cout << "Ingrese el exponente: ";
            cin >> exponentes;
            

            if(isValidFloat(exponentes)){
                novalidexp = false;
                exponente = stof(exponentes);
            }else{
                cout << "argumento a calcular no v�lido, reingrese el exponente" << endl;
            }
                

            
    }while(novalidexp);
            
    cout << coeficiente << "^"<<exponente<<" = " << pow(coeficiente,exponente) << endl;

}

/**
* <h2>raiz</h2>
* Este procedimiento se encarga de calcular la ra�z n de cualquier n�mero
* <p>
* El procedimiento evita que el usuario ingrese caracteres inv�lidos tanto para el coeficiente,
* como para la ra�z de la funci�n. Finalmente despliega el resultado en pantalla
* </p>
* @author Jos� Chaparro
* @since 2020-05-13
*/
void raiz(void){
    string coeficientes, raizs;
    double coeficiente, raiz;
    bool novalidroot = true, novalidcoef = true;
    
    do{
        cout << "Ingrese el n�mero al cual le quiere sacar ra�z: ";
        cin >> coeficientes;

        if(isValidFloat(coeficientes) && stof(coeficientes) >= 0){
            novalidcoef = false;
            coeficiente = stof(coeficientes);
        }else{
            cout << "argumento a calcular no v�lido, reingrese el coeficiente" << endl;
        }
        
    }while(novalidcoef);

    do{
        cout << "Ingrese el n�mero de la ra�z: ";
        cin >> raizs;

        if(isValidFloat(raizs) && stof(raizs) != 0){
            novalidroot = false;
            raiz = stof(raizs);
        }else{
            cout << "argumento a calcular no v�lido, reingrese la ra�z" << endl;
        }
        
    }while(novalidroot);
    
    cout << "ra�z "<< raiz << " de "<<coeficiente<< " = " << pow(coeficiente, (1/raiz)) << endl;
}
/**
* <h2>factorial</h2>
* En caso de que el parametro n sea 0, devolver� 1, si no, la funci�n se llama a s� misma
* <p>
* Esta funci�n implementa la recursividad utilizando al mismo tiempo el operador condicional ?:
* que se encarga de devolver el resultado 1 cuando n sea igual a 0 y de llamarse a s� misma
* para as� multiplicarse por s� misma
* </p>
* @author Jos� Chaparro
* @param n es el n�mero entero del cual se quiere obtener el factorial
* @return int una vez la recursividad termina, se regresa el valor total de las multiplicaciones realizadas con recursividad 
* @since 2020-05-12
*/
long double factorial(int n){
    return n==0 ? 1 : n*factorial(n-1);
    //TODO: EVITAR OVERFLOW
}
void invofact(void){
    string factoria;
    int factorialValido=0;
    do{
        try {
            cout << "Dame el n�mero del cual quieres su factorial \n";
            cin >> factoria;
            if (!isValidInt(factoria))
                throw 1;
        }

        catch(int excepcionNumInvlaido){
            if (excepcionNumInvlaido == 1) cout << "Error, el n�mero ingresado debe ser entero positivo \n";
        }

    }while(!isValidInt(factoria));
    
    factorialValido=stoi(factoria);
    
    cout << factorialValido << "! = " << factorial(factorialValido) << endl;
}

void doublelog(void){
    double base,x;
    cout << "Ingrese la base" << endl;
    cin >> base;
    cout << "Ingrese el numero al que quiere calcular el logaritmo" << endl;
    cin >> x;
    cout << "log base " << base << " de " << x << " = " << (double)(log(x) / log(base)) << endl;
}

void natlog(void){
    double x;
    cout << "Ingrese el numero para calcular el logaritmo natural" << endl;
    cin >> x;
    cout << "Ln("<<x<<") = " << log(x) << endl;
}

void formulaGeneral(){
    //Se pedir� los valores de la f�rmula:
    //ax² + bx + c;
    //Y despu�s se utilizar� la f�rmula general
    
    int ax, bx, c, colchon,colchon2;
    do{
        try{
        cout << "Ingrese aX" << endl;
        cin >> ax;
        
        if (ax==0){
            throw "Ingrese un n�mero diferente de cero";
        }
        }catch(...){
            
        }
        cout << "Ingrese bX" << endl;
        cin >> bx;
        cout << "Ingrese cX" << endl;
        //try{
            //dentro de la ra�z
            colchon= pow(bx,2) - (4*ax*c);
            if (colchon<0){
                cout << "(" << -bx << "+sqrt" << colchon << ")/" << 2*ax << endl;
                cout << "(" << -bx << "-sqrt" << colchon << ")/" << 2*ax << endl;
            }
            colchon= sqrt(colchon);
            
        //}


    }while(true);
    
    
}
