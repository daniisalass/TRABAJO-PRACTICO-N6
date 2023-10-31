#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50 
using namespace std;
class CADENA
{
	public: 
		char cad[MAX];
		CADENA()
		{
			strcpy(cad,"");
		}
		CADENA(char *A)
		{
			strcpy(cad,A);
		}
		void ImprimirCadena();
		int Longitud_Cadena();
		void Concatenar_Cadenas(char *A,char *B);
		void Copiar_Cadena(char *A,char *B);
		void BuscarCaracter(char );
		int CadenaABuscarCaracter(char *A,char *B);
};
void CADENA:: ImprimirCadena()
{
	puts(cad) ;
}
int CADENA:: Longitud_Cadena()
{
	char *A=&cad[0];
	int Largo=0;
	while(*A!='\0')
	{
		Largo++;
		A++;
	}
	return(Largo);
}
void CADENA:: Concatenar_Cadenas(char *A, char *B)
{
	strcat(A,B);
	
}
void CADENA:: Copiar_Cadena(char *A,char *B)
{
	strcpy(A,B);
}
int CADENA:: CadenaABuscarCaracter(char *A,char *B)
{
	int EncontroCaracter=0;
	if (strstr(A,B)!=NULL)
	{
		EncontroCaracter=1;
	}
	return(EncontroCaracter);
}
int main(int argc, char *argv[])
{
	int Selecionador, Selecionador2;
	int Salir=0;
	char AuxCad[MAX];
	char AuxCopy[MAX];

	
		printf("Ingrese las cadenas a trabajar\nPrimer Cadena:");
		gets(AuxCad);
		CADENA Daniel(AuxCad);
		printf("\nSegunda Cadena:");
		gets(AuxCad);
		CADENA Alvaro(AuxCad);
//			Alvaro.Concatenar_Cadenas(Daniel.cad,Alvaro.cad);
//			printf("\nLa cadena concatenada es: ");
//			Daniel.ImprimirCadena();
	while(Salir!=1)
	{
		printf("\nIngrese: \n 1-Copiar cadena \n 2-Longitud de la cadea: \n 3-Cadenas concatenadas \n 4-Buscar caracter o cadena \n 5-Salir \n");
		scanf("%d",&Selecionador);
		fflush(stdin);
			switch(Selecionador)
			{
				case 1:
					Alvaro.Copiar_Cadena(Daniel.cad,Alvaro.cad);
					printf("\nLa cadena copiada es: ");
					Daniel.ImprimirCadena();
					printf("\n");
					system("pause");
					system("cls");
					break;
				case 2:
					printf("\nLongitud de la Cadena 1:%d",Daniel.Longitud_Cadena());
					printf("\nLongitud de la Cadena 2:%d\n",Alvaro.Longitud_Cadena());
					system("pause");
					system("cls");
					break;
				case 3:
					Alvaro.Concatenar_Cadenas(Daniel.cad,Alvaro.cad);
					printf("\nLa cadena concatenada es: ");
					Daniel.ImprimirCadena();
					printf("\n");
					system("pause");
					system("cls");
					break;
				case 4:
					printf("\nIngrese la cadena o carcater a buscar: ");
					gets(AuxCopy);
					printf("Que cadena desea analizar: \n 1- Cadena 1 \n 2- Cadena 2\n");
					scanf("%d",&Selecionador2);
					fflush(stdin);
					switch(Selecionador2)
					{
					case 1:
						if( (Daniel.CadenaABuscarCaracter(Daniel.cad,AuxCopy)) == 1)
						{
							printf("Encontro la palabra: %s",AuxCopy);
							printf("\nEn la oracion: %s",Daniel.cad);
						}
						break;
					case 2:
						if( (Alvaro.CadenaABuscarCaracter(Alvaro.cad,AuxCopy)) == 1)
						{
							printf("Encontro la palabra: %s",AuxCopy);
							printf("\nEn la oracion: %s",Alvaro.cad);
						}
						break;
					default :
						break;
					}
					break;
				case 5:
					Salir=1;
					break;
					default : break; 
				
			}
	}
	return 0;
}

//void ConcatenarCadenas(char *A,char *B, int largoA,int largoB)
//{
//	int i;
//	char cadena[largoA+largoB];
//	char *pcadena;
//	pcadena=cadena;
//	for(i=0;i<largoA;i++)
//	{
//		*pcadena=*A;
//		pcadena++;
//		A++;
//	}
//	for(i=largoA;i<largoA+largoB;i++)
//	{
//		*pcadena=*B;
//		pcadena++;
//		B++;
//	}
//	*pcadena='\0'; //Coloco esto porque si lo imprimo con puts necesito tener un fin de cadena en el ultimo puntero de fin de linea asi no imprime basura 
//	fflush(stdin);
//	puts(cadena);
//	puts("");
//	/*	for(i=0;i<largoA+largoB;i++)*/
//	/*	{*/
//	/*		printf("%c",cadena[i]);*/
//	/*	}*/
//}
