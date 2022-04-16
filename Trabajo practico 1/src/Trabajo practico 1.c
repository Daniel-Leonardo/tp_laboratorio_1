/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Daniel Escobar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
#include "ValidacionesMenu.h"


int main()
{
	int opcion;
	int vuelos;
	int kilometros = 0;
	float ingresarPrecioAero = 0;
	float ingresarPrecioLatam = 0;
	float totalPrecioAerolineas;
	float totalPrecioLatam;
	float btcAerolineas;
	float btcLatam;
	float btc;
	float unitarioLatam;
	float unitarioAerolineas;
	float descuentoDeb = 10;
	float descuentoDebitoAerolineas;
	float descuentoDebitoLatam;
	float aumentoCred = 25;
	float aumentoCreditoAerolineas;
	float aumentoCreditoLatam;
	float diferenciaValor;

	int banderaKilometrosIngresados = 0;
	int banderaVuelosOk = 0;
	int banderaPreciosOk= 0;

	int kilometrosHard = 7090;
	float aerolineasHard = 162965;
	float latamHard = 159339;

	btc = 4605810.53;

	char salir;

	//fflush(stdout);
	setbuf(stdout, NULL);


	do{
			opcion = menu(kilometros);
			switch(opcion){

			case 1:
					kilometros = kilometrosIngresados();
					banderaKilometrosIngresados = 1;
					break;
			case 2:
					vuelos = precioVuelos(ingresarPrecioAero , ingresarPrecioLatam);
					if(vuelos == 1){
						ingresarPrecioAero = precioOk(vuelos);
						banderaVuelosOk = 1;
					}else{
						ingresarPrecioLatam = precioOk(vuelos);
						banderaVuelosOk =2;
					}if(banderaVuelosOk == 1){
						ingresarPrecioAero = precioOk(1);
					}else{
						ingresarPrecioLatam = precioOk(2);
					}

					banderaPreciosOk = 1;
					break;
			case 3:
					if(banderaKilometrosIngresados == 1 && banderaPreciosOk == 1){
					totalPrecioAerolineas = calcularPrecio(&kilometros, &ingresarPrecioAero);
					totalPrecioLatam = calcularPrecio(&kilometros, &ingresarPrecioLatam);
					btcLatam = pesosAbtc(&totalPrecioLatam , &btc);
					btcAerolineas = pesosAbtc(&totalPrecioAerolineas , &btc);
					unitarioLatam = precioUnitario(&totalPrecioLatam , &kilometros);
					unitarioAerolineas = precioUnitario(&totalPrecioAerolineas , &kilometros);
					descuentoDebitoAerolineas = descuentoDebito(&totalPrecioAerolineas , &descuentoDeb);
					descuentoDebitoLatam = descuentoDebito(&totalPrecioLatam , &descuentoDeb);
					aumentoCreditoAerolineas = aumentoCredito(&totalPrecioAerolineas , &aumentoCred);
					aumentoCreditoLatam = aumentoCredito(&ingresarPrecioLatam , &aumentoCred);
					diferenciaValor = diferenciaPrecio(&totalPrecioAerolineas , &totalPrecioLatam);
					}else
						if(banderaPreciosOk == 1 && banderaKilometrosIngresados == 0){
							printf("No se han ingresado kilometros complete opcion 1");
						}else
							if(banderaPreciosOk == 0 && banderaKilometrosIngresados == 1){
								printf("No se han ingresado valores de vuelos complete opcion 2");
							}else{
								printf("No han ingresado datos complete opcion 1 y 2");
							}
					break;
			case 4:

					printf("Informar resultados\n\n");
					printf("Kms Ingresados: %d \n\n" , kilometros);
					printf("Precio Aerolineas: %.2f \n", totalPrecioAerolineas);
					printf("A) Precio con tarjeta de debito: %.2f \n" , descuentoDebitoAerolineas);
					printf("B) Precio con tarjeta de credito: %.2f \n" , aumentoCreditoAerolineas);
					printf("C) Precio pagando con Bitcoin: %.2f \n" , btcAerolineas);
					printf("D) Mostrar precio unitario: %.2f \n\n" , unitarioAerolineas);

					printf("Precio Latam: %.2f \n",totalPrecioLatam);
					printf("A) Precio con tarjeta de debito: %.2f \n" , descuentoDebitoLatam);
					printf("B) Precio con tarjeta de credito: %.2f \n" , aumentoCreditoLatam);
					printf("C) Precio pagando con Bitcoin: %.2f \n" , btcLatam);
					printf("D) Mostrar precio unitario: %.2f \n\n" , unitarioLatam);

					printf("La diferencia de precio es: %.2f \n" , diferenciaValor);

					break;
			case 5:
					printf("Carga forzada de datos\n");
					totalPrecioAerolineas = calcularPrecio(&kilometrosHard, &aerolineasHard);
					totalPrecioLatam = calcularPrecio(&kilometrosHard, &latamHard);
					btcLatam = pesosAbtc(&totalPrecioLatam , &btc);
					btcAerolineas = pesosAbtc(&totalPrecioAerolineas , &btc);
					unitarioLatam = precioUnitario(&totalPrecioLatam , &kilometrosHard);
					unitarioAerolineas = precioUnitario(&totalPrecioAerolineas , &kilometrosHard);
					descuentoDebitoAerolineas = descuentoDebito(&totalPrecioAerolineas , &descuentoDeb);
					descuentoDebitoLatam = descuentoDebito(&totalPrecioLatam , &descuentoDeb);
					aumentoCreditoAerolineas = aumentoCredito(&totalPrecioAerolineas , &aumentoCred);
					aumentoCreditoLatam = aumentoCredito(&ingresarPrecioLatam , &aumentoCred);
					diferenciaValor = diferenciaPrecio(&totalPrecioAerolineas , &totalPrecioLatam);
					printf("Informar resultados\n\n");
					printf("Kms Ingresados: %d \n\n" , kilometrosHard);
					printf("Precio Aerolineas: %.2f \n", totalPrecioAerolineas);
					printf("A) Precio con tarjeta de debito: %.2f \n" , descuentoDebitoAerolineas);
					printf("B) Precio con tarjeta de credito: %.2f \n" , aumentoCreditoAerolineas);
					printf("C) Precio pagando con Bitcoin: %.2f \n" , btcAerolineas);
					printf("D) Mostrar precio unitario: %.2f \n\n" , unitarioAerolineas);

					printf("Precio Latam: %.2f \n",totalPrecioLatam);
					printf("A) Precio con tarjeta de debito: %.2f \n" , descuentoDebitoLatam);
					printf("B) Precio con tarjeta de credito: %.2f \n" , aumentoCreditoLatam);
					printf("C) Precio pagando con Bitcoin: %.2f \n" , btcLatam);
					printf("D) Mostrar precio unitario: %.2f \n\n" , unitarioLatam);

					printf("La diferencia de precio es: %.2f \n" , diferenciaValor);
					break;
			case 6:
					printf("Desea realizar otra consulta?: S/N\n");
					fflush(stdin);
					scanf("%c", &salir);
					break;
			case 7:
					printf("Opcion invalida vuelva a seleccionar\n");
					break;
			default:
					printf("Eso no es un numero.\n");
			}
			fflush(stdin);

	}while(salir != 'n');

	return 0;
}












































