/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial /		/
*	- Hugo Pereira  /		/
* Data: 20/11/2023
* Versão: 1.0 (Ultima vez modificado em 20/11/2023)
*/

#pragma once
#include <stdio.h>

#define N 30

typedef struct Calorias
{
	char calInstante[N];
	char calMinAd[N];
	char calMaxPer[N];
} Calorias;

/// <summary>
/// Estrutura para guardar:
///		- Tipo de Refeição (Pequeno Almoço, Almoço, Jantar)
/// </summary>
typedef struct Alimentacao
{
	int id;
	char tipoRefeicao[N];
	char alimento[N];
	char data[N];
	//struct Calorias cal[N]; // Apenas para teste
	struct Calorias cal;
} Alimentacao;

/// <summary>
/// Estrutura para guardar:
///		- Identificação de 4 dígitos
///		- Nome do Paciente
///		- Telefone
/// </summary>
typedef struct Paciente
{
	int id;
	char nome[N];
	char telefone[N];
	//struct Alimentacao ali[N]; // Apenas para teste
	struct Alimentacao ali;
} Paciente;



