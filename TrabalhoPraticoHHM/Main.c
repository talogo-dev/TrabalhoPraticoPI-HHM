/*
* Autores:
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Pereira  / 27970 / a27970@alunos.ipca.pt
* Data: 26/11/2023
* Versão: 1.2 (Ultima vez modificado em 29/11/2023)
*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#include "Metodos.h"
#include "Structs.h"

#define K 10

#pragma warning (disable: 4996)

int main()
{
	setlocale(LC_ALL, "Portuguese"); 

	// Variaveis
	Paciente p[K];
	Dieta diet[K];
	Plano pl[K];
	int qtdDadosPaciente = 0, qtdDieta = 0, qtdPlano = 0;
	
	qtdDadosPaciente = importarDadosPacientes("Paciente.csv", p, K);
	qtdDieta = importarDadosDieta("Dieta.csv", diet, K);
	qtdPlano = importarDadosPlano("Plano.csv", pl, K);

	bool guardar1 = guardarDadosPacientes("Paciente.dat", p, qtdDadosPaciente);
	bool guardar2 = guardarDadosDieta("Dieta.dat", diet, qtdDieta);
	bool guardar3 = guardarDadosPlano("Plano.dat", pl, qtdPlano);

	printf("Número de Dados de Pacientes: %d\n", qtdDadosPaciente);

	printf("Número de Dietas dos Pacientes: %d\n", qtdDieta);

	printf("Número de Planos dos Pacientes: %d\n\n", qtdPlano);


}