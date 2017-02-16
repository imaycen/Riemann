// Author         : Ivan de Jesus May-Cen
// Email          : imaycen@hotmail.com, imay@itsprogreso.edu.mx
// Language       : C++
// Environment    : Linux
// Compiler       : g++
// Revisions      :
//        Initial : 16.02.2017
//           Last : 

// Este programa compila en la consola de linux mediante la orde
// g++ main.cpp -o riemann
// "sumatoria" es el nombre del ejecutable

//Inclusion de librerias
#include <iostream>
#include <cmath>

//Declaracion de funciones
double funcion(double x, int opcion);
double suma_inferior_riemann( double a, double b, int n, int opcion );
double suma_superior_riemann( double a, double b, int n, int opcion );
double minimo( double a0, double b0, int opcion);
double maximo( double a0, double b0, int opcion);

using namespace std;

//Funcion principal
int main( )
{
double suma, a = 0.0, b = 1.0;
int n = 1000, opcion = 4;

//Llama a funcion que determina la suma de Riemann
suma = suma_inferior_riemann( a, b, n, opcion );

//Imprime resultados
cout << "La suma inferior es: " << suma << endl;

//Llama a funcion que determina la suma de Riemann
suma = suma_superior_riemann( a, b, n, opcion );

//Imprime resultados
cout << "La suma superior es: " << suma << endl;

return 0;
}
//********************************************************
// Se definen opciones para la funcion a evaluar
//
// Input   : indice i, opcion de funcion
// Output  : evaluacion de la funcion en x
//********************************************************
double funcion(double x, int opcion)
{
double valor;

if(opcion == 1)
 valor = x;
 else
 if(opcion == 2)
 valor = x*x;
 else
 if(opcion == 3)
 valor = 3-x*x;
 if(opcion == 4)
 valor = sqrt(x);



return valor;
}
//********************************************************
// Se definen opciones para suma inferior de Riemann
//
// Input   : intervalo [a,b], indice n, opcion
// Output  : evaluacion de la suma de Riemann en indice n
//********************************************************
double suma_inferior_riemann( double a, double b, int n, int opcion )
{
double dx, xi, a0, b0, fun_mi, suma = 0.0;
int i;

//Tamano de las bases
dx = (b - a) / n;

for( i = 1; i <= n; ++i )
 {
  a0 = a + (i-1)*dx;
  b0 = a + i*dx;
  //Minimo para suma inferior
  fun_mi = minimo(a0, b0, opcion);
  //Anade termino en suma de Riemann
  suma += fun_mi * dx;
 }

return suma;
}
//********************************************************
// Se definen opciones para suma superior de Riemann
//
// Input   : intervalo [a,b], indice n, opcion
// Output  : evaluacion de la suma de Riemann en indice n
//********************************************************
double suma_superior_riemann( double a, double b, int n, int opcion )
{
double dx, xi, a0, b0, fun_Mi, suma = 0.0;
int i;

//Tamano de las bases
dx = (b - a) / n;

for( i = 1; i <= n; ++i )
 {
  a0 = a + (i-1)*dx;
  b0 = a + i*dx;
  //Maximo para suma inferior
  fun_Mi = maximo(a0, b0, opcion);
  //Anade termino en suma de Riemann
  suma += fun_Mi * dx;
 }

return suma;
}
//********************************************************
// Funcion para calcular valor minimo de una funcion
//
// Input   : intervalos [a0, b0], opcion de funcion
// Output  : valor minimo
//********************************************************
double minimo( double a0, double b0, int opcion)
{
double min;
//Calcula el valor minimo
if( funcion(a0, opcion) <= funcion(b0, opcion) )
   min = funcion(a0, opcion);
  else
     min = funcion(b0, opcion);

return min;
}
//********************************************************
// Funcion para calcular valor maximo de una funcion
//
// Input   : intervalos [a0, b0], opcion de funcion
// Output  : valor maximo
//********************************************************
double maximo( double a0, double b0, int opcion)
{
double max;
//Calcula el valor minimo
if( funcion(a0, opcion) >= funcion(b0, opcion) )
   max = funcion(a0, opcion);
  else
     max = funcion(b0, opcion);

return max;
}










