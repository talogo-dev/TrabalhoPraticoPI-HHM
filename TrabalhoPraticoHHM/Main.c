/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial /		/ 
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.2 (Ultima vez modificado em 26/11/2023)
*/

#include <stdio.h>
#include <locale.h>

#include "Metodos.h";
#include "Structs.h"

#pragma warning (disable: 4996)

int main()
{
	setlocale(LC_ALL, "Portuguese");

	Paciente p[4];
	int res1 = 0, res2 = 0;
	
	res1 = GuardarDadosPacientes(p,3);
	res2 = GuardarDadosCaloriaDia(p,4);
	
	if (res1 == 1) 
	{
		printf("Dados Guardados - Dados Pacientes\n");
	}

	if (res2 == 1)
	{
		printf("Dados Guardados - Dados Caloria Dia\n");
	}

}