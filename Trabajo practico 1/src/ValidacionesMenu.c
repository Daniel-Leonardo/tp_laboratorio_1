/*
 * ValidacionesMenu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Daniel
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int menu(int kilometros){
	int opcion;
	int cant;

				printf("... Menu de opciones...\n\n");
				printf("1- Ingrese kilometros: KM %d\n\n" , kilometros);
				printf("2- Ingrese precio de vuelos:\n\n");
				printf("3- Calcular todos los costos\n\n");
				printf("4- Informe de resultados\n\n");
				printf("5- Carga forzada de datos\n\n");
				printf("6- Salir\n");

				printf("Ingrese opcion: ");
				fflush(stdin);
				cant = scanf("%d", &opcion);
				if(cant == 0){
					opcion = 7;
				}
				return opcion;
	}

float kilometrosIngresados(){

	int kilometrosIng;
	int kmIng;

	printf("Ingrese kilometros: \n");
	kmIng = scanf("%d", &kilometrosIng);

	while(kilometrosIng <=0 || kmIng ==0){
		fflush(stdin);
		printf("Kilometros ingresados incorrectos, intente nuevamente\n");
		scanf("%d" , &kilometrosIng);
		kmIng = kilometrosIng;
	}
	return kilometrosIng;

}

int precioVuelos(float pAero ,float pLatam){

			int empresa;

			printf("Ingresar precio de vuelos: Aerolineas: %.2f , Latam: %.2f\n" , pAero , pLatam);
			printf("1) Ingrese precio Aerolineas: \n");
			//pAero = scanf("%d", &pAero);
			printf("2) Ingrese precio Latam: \n");
			//pLatam = scanf("%d", &pLatam);
			printf("Seleccionar empresa; ");
			scanf("%d" , &empresa);


			return empresa;


}

int precioOk(int vuelo){

	int precio;
		if(vuelo == 1){
			printf("Ingrese precio de Aerolineas:");
			scanf("%d" , &precio);

		}else{
			printf("ingrese precio Latam:");
			scanf("%d" , &precio);
		}
		while(precio <=0){

			printf("Error ingrese precio correcto:");
			scanf("%d" , &precio);

		}
		return precio;

}
