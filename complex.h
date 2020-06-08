#ifndef _COMPLEX
#define _COMPLEX

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/**
* <h2>isValidFloat</h2>
* La funcion retorna un valor booleano que responde a si una cadena es un valor flotante valido 
* <p>
* La funcion evalua el parametro str para comprobar que cumple con una serie de caracteristicas
* que lo definen como un valor flotante
* </p>
* @author Luis Raul Chacon Munoz
* @param str Es un argumento de tipo string que sera evaluado
* @return valido Es una variable booleana que establece si el parametro str es un flotante valido
* @since 2020-05-21
*/
bool isValidFloat(std::string str){
    int inicio=0, i=0, t=0, contador=0;
    bool valido=true, signo=false;

    if(str.length() == 0)
        valido=false;

    if(str.length() == 1 && str.at(0) == '.') //cambiar la coma por punto
        valido = false;
        
    if(str.at(0) == '-' || str.at(0)=='+'){
        signo = true;
        inicio = 1;
    }
    if(signo && str.length()==1)
        valido=false;
    
    for(t=inicio;valido && t<int(str.length());t++){
        if(str.at(t) == '.') 
            contador++;
        if(contador>1){
            t=int(str.length());
                
            }
    }
    if(contador>1)
        valido=false;
        
    for(i=inicio; valido && i<int(str.length()); i++){
        if((str.at(i) == '.')){ 
            contador++;
            if(contador>1){
                t=int(str.length());
            }
        }else if(!isdigit(str.at(i)))
            valido=false;
    }
        
  return valido;
}

/**
* <h2>complex</h2>
* Es una estructura para el manejo de numeros complejos por la Calcumaster2000 
* <p>
* La estructura tiene un constructor que inicializa la parte real e imaginaria de un numero complejo. Ademas,
* sobrecarga los operadores de operaciones matematicas bA!sicas y de flujo para que puedan ser utilizados en
* los complejos. 
* </p>
* @author Omar Alonso Escapita Chacon
* @author Jose Carlos Chaparro Morales
* @since 2020-05-11
*/
struct complex{
    float real, imag;
    complex(float r=0, float i=0){
        real=r;
        imag=i;
    }
    complex operator + (complex const &obj){
		complex res(0,0);

		res.real=real+obj.real;
		res.imag=imag+obj.imag;

		return res;
	}
    complex operator - (complex const &obj){
		complex res(0,0);

		res.real=real-obj.real;
		res.imag=imag-obj.imag;

		return res;
	}
    complex operator * (complex const &obj){
		complex res(0,0);

		res.real=real*obj.real-imag*obj.imag;
        res.imag=real*obj.imag+obj.real*imag;

		return res;
	}
    complex operator / (complex &obj){
		complex res(0,0);
        
        int den = obj.real * obj.real + obj.imag * obj.imag;
        
        if(den!=0){
            obj.imag = -obj.imag;
            res.real = (real * obj.real - imag * obj.imag) / den;
            res.imag = (real  *obj.imag + obj.real * imag) / den;
        }
        else{
            throw "resultado indefinido, denominador = 0";
        }
        

		return res;
	}
    friend std::istream& operator >> (std::istream& in, complex& c){
        string reals, imaginarios;

        do{
            try{
                cout << "Ingrese la parte real: "<<endl;
                in >> reals;

                if( !isValidFloat(reals) )
                    throw "Número inválido, reingrese la parte real";

                c.real = stof(reals);
            }catch(const char* invalidnumber){
                cout<<invalidnumber<<endl;
            }
        }while( !isValidFloat(reals) );

        do{
            try{
                cout << "Ingrese la parte imaginaria: "<<endl;
                in >> imaginarios;

                if( !isValidFloat(imaginarios) )
                    throw "Número inválido, reingrese la parte imaginaria";

                c.imag = stof(imaginarios);


            }catch(const char* invalidnumber){
                cout<<invalidnumber<<endl;
            }
            
        }while( !isValidFloat(imaginarios) );

        return in;
    }

    friend std::ostream& operator << (std::ostream &os,complex &complx){
    
    if(complx.imag > 0)
        os<<complx.real<<"+"<<complx.imag<<"i"<<endl;
    else
        os<<complx.real<<""<<complx.imag<<"i"<<endl;

    return os;
    }
};

/**
* <h2>sumaCompejos</h2>
* El procedimiento suma dos numeros complejos. 
* <p>
* Se pide al usuario que ingrese dos numeros de tipo complex y luego se suman.
* </p>
* @author Omar Alonso Escapita Chacon
* @since 2020-05-11
*/
void sumaComplejos(){
    complex a, b, r;

    cout<<"Ingrese el complejo a"<<endl;
    cin>>a;
    cout<<"Ingrese el complejo b"<<endl;
    cin>>b;
    
    r = a + b;

    cout << "a + b = " <<r<<endl;
}

/**
* <h2>restaCompejos</h2>
* El procedimiento resta dos numeros complejos. 
* <p>
* Se pide al usuario que ingrese dos numeros de tipo complex y luego se realiza la resta.
* </p>
* @author Omar Alonso Escapita Chacon
* @since 2020-05-11
*/
void restaComplejos(){
    complex a , b , r;

    cout<<"Ingrese el complejo a"<<endl;
    cin>>a;
    cout<<"Ingrese el complejo b"<<endl;
    cin>>b;
    
    r = a - b;

    cout << "a - b = " << r;

}

/**
* <h2>multiplicacionCompejos</h2>
* El procedimiento multiplica dos numeros complejos. 
* <p>
* Se pide al usuario que ingrese dos numeros de tipo complex y luego se realiza la multiplicacion.
* </p>
* @author Omar Alonso Escapita Chacon
* @since 2020-05-11
*/
void multiplicacionComplejos(){
    complex a , b , r;

    cout<<"Ingrese el complejo a"<<endl;
    cin>>a;
    cout<<"Ingrese el complejo b"<<endl;
    cin>>b;
    
    r = a * b;

    cout << "a * b = " << r;
    
}

/**
* <h2>divisionCompejos</h2>
* El procedimiento divide dos numeros complejos. 
* <p>
* Se pide al usuario que ingrese dos numeros de tipo complex y luego se realiza la division.
* </p>
* @author Omar Alonso Escapita Chacon
* @author Jose Carlos Chaparro Morales
* @since 2020-05-11
*/
void divisionComplejos(){
    complex a , b , r;

    cout<<"Ingrese el complejo a"<<endl;
    cin>>a;
    cout<<"Ingrese el complejo b"<<endl;
    cin>>b;
    try{
        r = a / b;
        cout << "a / b = " << r;

    }catch(const char* denominadorCero){
        cout<<denominadorCero<<endl;
    }
}

#endif
