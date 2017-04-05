#include "funciones.h"

float suma(float x,float y)
{
    return x+y;
}

float resta(float x,float y)
{
    return x-y;
}

float division(float x,float y)
{
    return (float)x/y;
}

float multiplicacion(float x,float y)
{
    return x*y;
}

float factorial(float x)
{
    float contador;
    float factorialX=1;
    float aux;
    aux=(int)x;
    if((x-aux)==0)
    {
        for(contador=x;contador>0;contador--)
        {
            factorialX*=contador;
        }
    }
    else{
        return 0;
    }
    return factorialX;
}

