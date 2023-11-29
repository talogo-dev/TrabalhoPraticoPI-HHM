/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.2 (Ultima vez modificado em 29/11/2023)
*/

#include <stdio.h>
#include <locale.h>

#include "Metodos.h"
#include "Structs.h"

#define K 10

#pragma warning (disable: 4996)

int main()
{
	setlocale(LC_ALL, "Portuguese"); 

	Paciente p[K];
	Alimentacao ali[K];
	Dieta diet[K];

	int qtdDadosPaciente = 0, qtdAlimentacao = 0, qtdDieta = 0;
	
	qtdDadosPaciente = LerDadosPacientes("Pessoas.csv", p, K);
	qtdAlimentacao = LerAlimentacaoPacientes("Alimentacao.csv", ali, K);
	qtdDieta = LerDietaPacientes("Dieta.csv", diet, K);

	printf("Número de Dados de Pacientes: %d\n", qtdDadosPaciente);

	printf("Número de Alimentos dos Pacientes: %d\n", qtdAlimentacao);

	printf("Número de Dietas dos Pacientes: %d\n\n", qtdDieta);

}