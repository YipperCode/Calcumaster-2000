#ifndef _FRACTIONS
#define _FRACTIONS

#include <locale.h>
#include <iostream>
#include <string>

using namespace std;

/**
* <h2>isValidInt</h2>
* Esta funciÃ³n determina si el valor introducido es un entero válido y regresa una variable boolean dependiendo de la condición anterior.
* <p>
* Esta función permite saber si un caracter es un entero válido, ya sea negativo, 0 o positivo.
* </p>
* @author Raymundo Cornejo García
* @param numeroEnCadena Es el caracter el cuál se va a determinar si es un entero válido, debe usarse una variable string.
* @return bool isValidInt Regresa un valor booleano que determina si el caracter es un entero válido.
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
* La estructura tiene un constructor que inicializa el numerador y el denominador de una fracción. Además,
* sobrecarga los operadores de operaciones matemáticas básicas y de flujo para que puedan ser utilizados en
* las fracciones. 
* </p>
* @author Juan Luis Del Valle Sotelo
* @author José Carlos Chaparro Morales
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
            cout<<"0";

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
                cout<<"Error, el nÃºmero ingresado debe ser un numero entero \n";
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

                if (excDivCeroInt==4) cout<<"Error, el nÃºmero ingresado debe ser diferente de cero, reingrese el denominador \n";
                if (excDivCeroInt==1) cout<<"Error, el nÃºmero ingresado debe ser entero, reingrese el denominador\n";
            
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
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnión para así sumarlas mediante la
* carga de operadores en la estructura fracción, para así poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void sumaFraccion(){

    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fracciÃ³n a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fracciÃ³n b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 + fraccion2;

    cout<<"a + b = "<<fraccionr<<endl;
}

/**
* <h2>restaFraccion</h2>
* Este procedimiento imprime la resta de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnión para así restarlas mediante la
* carga de operadores en la estructura fracción, para así poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void restaFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fraccion a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fraccion b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 - fraccion2;

    cout<<"a - b = "<<fraccionr<<endl;
}  

/**
* <h2>multiplicacionFraccion</h2>
* Este procedimiento imprime la multiplicación de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnión para así multiplicarlas mediante la
* carga de operadores en la estructura fracción, para así poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void multiplicacionFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fraccion a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fraccion b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 * fraccion2;

    cout<<"a * b = "<<fraccionr<<endl;
}

/**
* <h2>divisionFraccion</h2>
* Este procedimiento imprime la división de dos fracciones.
* <p>
* Procedimiento que pide dos fracciones, es decir el numerador y denominador de cada fucnión para así dividirlas mediante la
* carga de operadores en la estructura fracción, para así poder imprimir dicho resultado.
* </p>
* @author Juan Luis Del Valle Sotelo
* @author Oscar Ariel Quintana Merino
* @since 2020-05-18
*/
void divisionFraccion(){
    fraccion fraccion1, fraccion2,fraccionr;
    
    cout<<"Ingrese la fraccion a"<<endl;
    cin>>fraccion1;
    cout<<"Ingrese la fraccion b"<<endl;
    cin>>fraccion2;

    fraccionr = fraccion1 / fraccion2;

    cout<<"a / b = "<<fraccionr<<endl;
}

#endif
