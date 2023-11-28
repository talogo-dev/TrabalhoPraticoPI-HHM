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

#include "Metodos.h"
#include "Structs.h"

#define K 10

#pragma warning (disable: 4996)

int main()
{
	setlocale(LC_ALL, "Portuguese");

	Paciente p[K];
	int qtdDadosPaciente = 0, qtdAlimentacao = 0;
	
	qtdDadosPaciente = LerDadosPacientes("Pessoas.csv", p, K);
	qtdAlimentacao = LerAlimentacaoPacientes("Alimentacao.txt", p, K);

	printf("Numero de Dados de Pacientes: %d\n", qtdDadosPaciente);
	printf("%d", qtdAlimentacao);

}