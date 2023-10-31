#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <ctime>
#define MAX 50
using namespace std;

class SENSOR
{
	private :
		char MarcaSensor[MAX];
		char TipoSensor[MAX];
		char UnidadMedida[MAX];
	public : 
		void Setter_MarcaSensor(char *A)
		{
			strcpy(MarcaSensor,A);	
		}
	
		void Setter_TipoSensor(char *A)
		{
			strcpy(TipoSensor,A);	
		}
	
		void Setter_UnidadDeMedida(char *A)
		{
			strcpy(UnidadMedida,A);	
		}
		
		char *Getter_MarcaSensor()
		{
			return(MarcaSensor);
		}
		
		char *Getter_TipoSensor()
		{
			return(TipoSensor);
		}
		
		char *Getter_UnidadDeMedida()
		{
			return(UnidadMedida);
		}

};
class MEDICION
{
	private :
		time_t FechaRealizada;
		tm* TiemposDescompuestos;
		char Comentarios[150];
		float ValorMedido;
		
	public :
		int Ocultador;
		SENSOR SensorDeMedicion;
		void Setter_Comentarios(char *A)
		{
			strcpy(Comentarios,A);	
		}
		void Setter_FechaRealizada()
		{
			FechaRealizada=time(NULL);
		}
		void Setter_ValorMedido(float Valor)
		{
			ValorMedido=Valor;	
		}
		
		char *Getter_Comentarios()
		{
			return(Comentarios);
		}
		
		float Getter_ValorMedido()
		{
			return(ValorMedido);
		}
		int Getter_Dia()
		{
			TiemposDescompuestos=localtime(&FechaRealizada);
			return(TiemposDescompuestos->tm_mday);
		}
		int Getter_Mes()
		{
			TiemposDescompuestos=localtime(&FechaRealizada);
			return(TiemposDescompuestos->tm_mon+1);
		}
		int Getter_Anio()
		{
			TiemposDescompuestos=localtime(&FechaRealizada);
			return(TiemposDescompuestos->tm_year+1900);
		}
};
void MostarBaseDeDatos(SENSOR Sensores[]);
void CargarBaseDeDatosSensor(SENSOR Sensores[]);
void MostrarDatosMedidos(MEDICION Mediciones [],int i);
void EliminarMedicionesRealizadas(MEDICION Mediciones [],int i);
void Gurdar_Archivo_Mediciones(FILE *Archivo, MEDICION Mediciones[], int cantidad);
int main(int argc, char *argv[])
{
	FILE *GuardadoDeArchivo;
	int Salir=0;
	int i=0,MedicionABorrar=0;
	int Selecionador,Selecionador2;
	float ValorMedido;
	char AuxCad[MAX];
	SENSOR Sensores[3];
	MEDICION Mediciones[MAX];
	
	CargarBaseDeDatosSensor(Sensores);

	while(Salir !=1)
	{
			
		printf("\n =====MENU PRINCIPAL===== \n 1-Agregar Medicion \n 2-Mostrar Mediciones\n 3-Eliminar \n 4-Guardar en archivo \n 5-Salir\n");
		
		scanf("%d",&Selecionador);
		switch(Selecionador){
			
			case 1:
				printf("\n Ingrese el sensor utilizado \n");
				MostarBaseDeDatos(Sensores);
				
				scanf("%d",&Selecionador2);
				switch(Selecionador2)
				{
					case 1:
						Mediciones[i].SensorDeMedicion=Sensores[0];
						break;
					case 2:
						Mediciones[i].SensorDeMedicion=Sensores[1];
						break;
					case 3:
						Mediciones[i].SensorDeMedicion=Sensores[2];
						break;
					default :
						break;
				}
				printf("Ingrese el valor medido: ");
				scanf("%f",&ValorMedido);
				fflush(stdin);
				Mediciones[i].Setter_ValorMedido(ValorMedido);
				printf("Ingrese comentarios: ");
				gets(AuxCad);
				Mediciones[i].Setter_Comentarios(AuxCad);
				Mediciones[i].Setter_FechaRealizada();
				Mediciones[i].Ocultador=0;
				i++;
				break;
			case 2:
			    system("cls");
				MostrarDatosMedidos(Mediciones,i);
				system("pause");
				break;
			case 3:
				system("cls");
				MostrarDatosMedidos(Mediciones,i);
				printf("\nQue medicion desea borrar ?\n");
				scanf("%d",&MedicionABorrar);
				fflush(stdin);
				EliminarMedicionesRealizadas(Mediciones,MedicionABorrar);
				break;
			case 4: 
				Gurdar_Archivo_Mediciones(GuardadoDeArchivo,Mediciones,i);
				break;
			case 5: Salir=1;
				break;
			default : 
				break;
		}
	}
	return 0;
}
void MostrarDatosMedidos(MEDICION Mediciones [],int i)
{
	printf("\n Encontro: ");
	for (int j=0;j<i;j++)
	{
		if(Mediciones[j].Ocultador==0)
		{
		printf("\n ===== MEDICION %i =====\n",j+1);
		printf("\nMarca: %s",Mediciones[j].SensorDeMedicion.Getter_MarcaSensor());
		printf("\nTipo: %s",Mediciones[j].SensorDeMedicion.Getter_TipoSensor());
		printf("\nUnidad de Medida: %s",Mediciones[j].SensorDeMedicion.Getter_UnidadDeMedida());
		printf("\nValor medido: %f",Mediciones[j].Getter_ValorMedido());
		printf("\nComentarios: %s",Mediciones[j].Getter_Comentarios());
		printf("\nFecha: %d / %d / %d\n",Mediciones[j].Getter_Dia(),Mediciones[j].Getter_Mes(),Mediciones[j].Getter_Anio());
		}
	}
}
void CargarBaseDeDatosSensor(SENSOR Sensores[])
{
	char Sensor1Ma[MAX]="Sony";char Sensor1Me[MAX]="Kilometros";char Sensor1T[MAX]="JJP";
	char Sensor2Ma[MAX]="Lilliana";char Sensor2Me[MAX]="Milimetros";char Sensor2T[MAX]="HLP";
	char Sensor3Ma[MAX]="Samsung";char Sensor3Me[MAX]="Metros";char Sensor3T[MAX]="SNP";
	
	Sensores[0].Setter_MarcaSensor(Sensor1Ma);
	Sensores[0].Setter_TipoSensor(Sensor1T);
	Sensores[0].Setter_UnidadDeMedida(Sensor1Me);
	
	Sensores[1].Setter_MarcaSensor(Sensor2Ma);
	Sensores[1].Setter_TipoSensor(Sensor2T);
	Sensores[1].Setter_UnidadDeMedida(Sensor2Me);
	
	
	Sensores[2].Setter_MarcaSensor(Sensor3Ma);
	Sensores[2].Setter_TipoSensor(Sensor3T);
	Sensores[2].Setter_UnidadDeMedida(Sensor3Me);
}
void MostarBaseDeDatos( SENSOR Sensores[] )
{
	printf("\nSENSOR 1\n");
	printf("Marca: %s",Sensores[0].Getter_MarcaSensor());
	printf("\nTipo: %s",Sensores[0].Getter_TipoSensor());
	printf("\nUnidad de Medida: %s\n",Sensores[0].Getter_UnidadDeMedida());
	fflush(stdin);
	printf("\nSENSOR 2\n");
	printf("Marca del sensor: %s\n",Sensores[1].Getter_MarcaSensor());
	printf("Tipo: %s\n",Sensores[1].Getter_TipoSensor());
	printf("Unidad de Medida: %s\n",Sensores[1].Getter_UnidadDeMedida());
	fflush(stdin);
	printf("\nSENSOR 3\n");
	printf("Marca del sensor: ");
	printf("Marca del sensor: %s\n",Sensores[2].Getter_MarcaSensor());
	printf("Tipo: %s\n",Sensores[2].Getter_TipoSensor());
	printf("Unidad de Medida: %s\n",Sensores[2].Getter_UnidadDeMedida());
}
void EliminarMedicionesRealizadas( MEDICION Mediciones [], int i)
{
	char Aux[5]="";
	float ValorEliminado=0;
	Mediciones[i-1].Setter_Comentarios(Aux);
	Mediciones[i-1].Setter_ValorMedido(ValorEliminado);
	Mediciones[i-1].SensorDeMedicion.Setter_MarcaSensor(Aux);
	Mediciones[i-1].SensorDeMedicion.Setter_TipoSensor(Aux);
	Mediciones[i-1].SensorDeMedicion.Setter_UnidadDeMedida(Aux);
	Mediciones[i-1].Ocultador=1;

}
void Gurdar_Archivo_Mediciones(FILE *Archivo, MEDICION Mediciones[], int cantidad)
{
	int i;
	if((Archivo=fopen("RegistroDeMediciones.txt","wb+"))!=NULL)
	{
		for (i=0;i<cantidad;i++)
		{
			fwrite(&Mediciones[i],sizeof(MEDICION),1,Archivo);
		}
	}
	else
	{
		printf("\n Error al abrir el archivio \n");
	}
}
