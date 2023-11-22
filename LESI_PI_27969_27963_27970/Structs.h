/*
* 
*/

#pragma once
#include <stdio.h>

typedef struct Calorias
{
	int calMinAd;
	int calMaxPer;
} Calorias;

/// <summary>
/// Estrutura para guardar:
///		- Tipo de Refeição (Pequeno Almoço, Almoço, Jantar)
/// </summary>
typedef struct Alimentacao
{
	char tipoRefeicao[30];
	char alimento[20];
	char data[20];
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
	char nome[30];
	int telefone;
	struct Alimentacao ali;
} Paciente;



