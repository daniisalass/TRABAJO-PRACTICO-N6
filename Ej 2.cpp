#include <stdio.h>
#include <ctime>
#include <iostream>
#define MAX 50 
using namespace std;
class RELOJ
{
	public :
		int Estado;
	
		RELOJ (int Segundos)
		{
			DuracionTemporizador=Segundos;
		}
		void IniciarTemporizador()
		{
			InicioTemporizador=time(NULL); // Inicializo el tiempo real en el que se encuentra en el inicio 
/*			Inicio=time(NULL);
*/		}
		void IniciarCronometro()
		{
			InicioCronometro=time(NULL); // Inicializo el tiempo real en el que se encuentra en el inicio 
/*			Inicio=time(NULL);
*/		}

		int StopTemporizador()
		{
			time_t TiempoActual;
			TiempoActual=time(NULL); // Voy preguntando mi tiempo actual con el que guarde en inicio 
			if((TiempoActual - InicioTemporizador)>=DuracionTemporizador) // Resta ambos tiempos hasta llegar al valor 
			{
				Estado=0;
			}
			else
			{
				Estado=1;
			}
			return(Estado);
		}
		int TCronometro()
		{
			time_t TiempoActualAux;
			TiempoActualAux=time(NULL);
			TiempoCronometro=TiempoActualAux-InicioCronometro;
			return(TiempoCronometro);
		}
		void StopCronometro()
		{
			
		}
//		int TiempoTranscurridoCronometro()
//		{
//		}
	private :
		time_t InicioCronometro;
		time_t InicioTemporizador;
		time_t Fin;
		int DuracionTemporizador;
		int TiempoCronometro;
};

int main(int argc, char *argv[]) {
	int Tiempo,Selecionador,Selecionador2;
	int Bandera=1;
	int Salir=0;
	int Salir2=0;
	RELOJ Temporizador(0);
	RELOJ Cronometro(0);
	while(Salir!=1)
	{
		printf("\n   ¿ Que desea hacer ? \n\n -1- Iniciar un temporizador \n -2- Cronometro \n -3- Salir del programa \n");
		scanf("%d",&Selecionador);
		fflush(stdin);
			switch(Selecionador)
			{
				case 1:
						printf("Ingrese el tiempo en segundos a temporizar:");
						scanf("%d",&Tiempo);
						fflush(stdin);
						Temporizador = RELOJ(Tiempo);
						Temporizador.IniciarTemporizador();
							while((Temporizador.StopTemporizador())!=0)
							{
							}
						system("cls");
						printf("\nEl Tiempo transcurrido es %d (seg)\a\n", Tiempo);
						system("pause");

				break;
				case 2:
					Salir2 =0;
					while(Salir2!=1)
					{
						printf("\n -1- Inicializar Cronometro \n -2- Tiempo transcurrido del Cronometro \n -3- Salir \n");
						scanf("%d",&Selecionador2);
						fflush(stdin);
						switch(Selecionador2)
						{
							case 1:
							Cronometro.IniciarCronometro();
							system("cls");
							printf("Se inicio Cronometro\a\n");
							system("pause");
							
							break;
							case 2:
							system("cls");
							printf("Transcurrio: %d Seg \a\n",Cronometro.TCronometro());
							system("pause");
							break;
							case 3:
							Salir2 =1;
							break;
							default : break;
						}
					}
				break;
				case 3:
						Salir=1;
				break;
				default :
				break;
			}
	}
	return 0;
}
