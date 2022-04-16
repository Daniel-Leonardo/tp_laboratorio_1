/*
 * Funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Daniel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float calcularPrecio(int* kilometros, float* precio);

float pesosAbtc(float* precio, float* btc);

float precioUnitario(float* precio, int* kilometros);

float diferenciaPrecio(float* precioAero, float* precioLatam);

float descuentoDebito(float* precio , float* descuento);

float aumentoCredito(float* precio , float* aumento);



#endif /* FUNCIONES_H_ */
