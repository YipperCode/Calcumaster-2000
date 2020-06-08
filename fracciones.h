#ifndef _FRACTIONS
#define _FRACTIONS

#include <locale.h>
#include <iostream>
#include <string>

using namespace std;

/**
* <h2>isValidInt</h2>
* Esta funciA3n determina si el valor introducido es un entero valido y regresa una variable boolean dependiendo de la condicion anterior.
* <p>
* Esta funcion permite saber si un caracter es un entero valido, ya sea negativo, 0 o positivo.
* </p>
* @author Raymundo Cornejo Garcia
* @param numeroEnCadena Es el caracter el cual se va a determinar si es un entero valido, debe usarse una variable string.
* @return bool isValidInt Regresa un valor booleano que determina si el caracter es un entero valido.
* @since 2020-04-28
*/
bool isValidInt(string numeroEnCadena){
	int inicio = 0;
	int i=0;
	bool valido = true;
	bool signo = false;
	
	int tamanioDeCadena = numeroEnCadena.size();
	
	if(tamanioDeCadena == 0)
		valido = 0;
	if(numeroEnCadena.at(0)=='-' || numeroEnCadena.at(0)=='+'){
		inicio=1;
		signo = true;
	}
	if(signo && tamanioDeCadena ==1)
		valido = false;
	
	for(i=inicio; valido && i<tamanioDeCadena; i++){
		if(!isdigit(numeroEnCadena.at(i)))
			valido = false;
	}
	
	return valido;

}

/**
* <h2>fraccion</h2>
* Es una estructura para el manejo de fracciones por la Calcumaster2000 
* <p>
* La estructura tiene un constructor que inicializa el numerador y el denominador de una fraccion. Ademas,
* sobrecarga los operadores de operaciones matematicas basicas y de flujo para que puedan ser utilizados en
* las fracciones. 
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Jose Carlos Chaparro Morales
* @since 2020-05-11
*/
struct fraccion{
	int up, down;

	fraccion(int a=0, int b=0){

		up=a; down=b;
	}

	fraccion operator + (fraccion const &obj){

		fraccion res(0,0);

		if (down==obj.down){
		    res.up=up+obj.up;
		    res.down=down;
		}
		else{
		    res.up=up*obj.down+obj.up*down;
	    	res.down=down*obj.down;
		}
        
		return res;
	}

	fraccion operator - (fraccion const &obj){
        
		fraccion res(0,0);

		if (down==obj.down){
		    res.up=up-obj.up;
		    res.down=down;
		}
		else{
		    res.up=up*obj.down-obj.up*down;
	    	res.down=down*obj.down;
		}

		return res;
	}

	fraccion operator * (fraccion const &obj){

		fraccion res(0,0);
        
		res.up=up*obj.up;
		res.down=down*obj.down;
        
		return res;
	}

	fraccion operator / (fraccion const &obj){

		fraccion res(0,0);

		res.up=up*obj.down;
		res.down=down*obj.up;
        
		return res;
	}
 
	friend std::ostream& operator << (std::ostream& os,fraccion& obj){
        
        if(obj.up == 0 )
            cout<<"0\n";

        else
            cout<<obj.up<<"/"<<obj.down<<endl;
        
    return os;
    }
    
    friend std::istream& operator >> (std::istream& is,fraccion& obj){
        string numeradors,denominadors;
        
        do{
            try{
                cout<<endl<<"Ingrese el numerador: ";
                cin>>numeradors;
                if (!isValidInt(numeradors)) throw 1;

                obj.up = stoi(numeradors);
            }
            catch (int &numerador_invalido){
                cout<<"Error, el número ingresado debe ser un número entero \n";
            }
        }
        while (!isValidInt(numeradors));
        
        do{
            try{
                
                cout<<endl<<"Ingrese el denominador: ";

                cin>>denominadors;

                if (!isValidInt(denominadors)) throw 1;

                obj.down = stoi(denominadors);

                if (obj.down == 0) throw 4;
                
            }catch (int excDivCeroInt){

                if (excDivCeroInt==4) cout<<"Error, el número ingresado debe ser diferente de cero, reingrese el denominador \n";
                if (excDivCeroInt==1) cout<<"Error, el número ingresado debe ser entero, reingrese el denominador\n";
            
            }
        }
        while (!isValidInt(denominadors) || obj.down == 0 );

        return is;
    }
};

/**
* <h2>sumaFraccion</h2>
* Este procedimiento imprime la suma de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnion para asi sumarlas mediante la
* carga de operadores en la estructura fraccion, para asi poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void sumaFraccion(){

    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fracción a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fracción b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 + fraccion2;

    cout<<"a + b = "<<fraccionr<<"Lo que es equivalente a: "<< (double)fraccionr.up/(double)fraccionr.down << endl;
}

/**
* <h2>restaFraccion</h2>
* Este procedimiento imprime la resta de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnion para asi restarlas mediante la
* carga de operadores en la estructura fraccion, para asi poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void restaFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fracción a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fracción b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 - fraccion2;

    cout<<"a - b = "<<fraccionr<<"Lo que es equivalente a: "<< (double)fraccionr.up/(double)fraccionr.down << endl;
}  

/**
* <h2>multiplicacionFraccion</h2>
* Este procedimiento imprime la multiplicacion de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnion para asi multiplicarlas mediante la
* carga de operadores en la estructura fraccion, para asi poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void multiplicacionFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fracción a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fracción b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 * fraccion2;

    cout<<"a * b = "<<fraccionr<<"Lo que es equivalente a: "<< (double)fraccionr.up/(double)fraccionr.down << endl;
}

/**
* <h2>divisionFraccion</h2>
* Este procedimiento imprime la division de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnion para asi dividirlas mediante la
* carga de operadores en la estructura fraccion, para asi poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void divisionFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    cout<<"Ingrese la fracción a"<<endl;
    cin>>fraccion1;
    do{
    cout<<"Ingrese la fracción b"<<endl;
    cin>>fraccion2;
    if (fraccion2.up==0) cout << "Operación no definida, división entre cero\n";
	}while (fraccion2.up==0);
    fraccionr = fraccion1 / fraccion2;

    cout<<"a / b = "<<fraccionr<<"Lo que es equivalente a: "<< (double)fraccionr.up/(double)fraccionr.down << endl;
}

#endif
