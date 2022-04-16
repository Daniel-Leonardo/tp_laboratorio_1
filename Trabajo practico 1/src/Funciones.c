/*
 * Funciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Daniel
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

float calcularPrecio(int* kilometros, float* precio){

	float totalPrecio;

	totalPrecio = (*kilometros) * (*precio);

	return totalPrecio;
}

float pesosAbtc(float* precio, float* btc){

	float precioBtc;

	precioBtc = ((*precio) * 100) / (*btc);

	return precioBtc;
}

float precioUnitario(float* precio, int* kilometros){

	float precioKilometro;

	precioKilometro = *precio / *kilometros ;

	return precioKilometro;
}

float diferenciaPrecio(float* precioAero, float* precioLatam){

	float diferenciaPrecio;

	diferenciaPrecio = (*precioAero) - (*precioLatam);

	return diferenciaPrecio;
}

float descuentoDebito(float* precio , float* descuento){

	float descuentoDeb;
	float totalDebito;

	descuentoDeb = (*precio) * (*descuento) / 100;

	totalDebito = (*precio) - (descuentoDeb);

	return totalDebito;
}

float aumentoCredito(float* precio , float* aumento){

	float aumentoCred;
	float totalCredito;

	aumentoCred = (*precio) * (*aumento) / 100;

	totalCredito = (*precio) + aumentoCred;

	return totalCredito;
}
