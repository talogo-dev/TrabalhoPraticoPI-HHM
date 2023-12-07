/*
* Autores:
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Pereira  / 27970 / a27970@alunos.ipca.pt
* Data: 05/12/2023
* Versão: 2.3 (Ultima vez modificado em 05/12/2023)
*/

#pragma once
#include <stdio.h>
#include <time.h>

#define N 30

#pragma region Outras Structs

/// <summary>
///		Serve para guardar datas
/// </summary>
typedef struct Data
{
	int dia;
	int mes;
	int ano;
} Data;

#pragma endregion


#pragma region Relativo aos Pacientes

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
} Paciente;

/// <summary>
///		Estrutura para guardar a Dieta
/// </summary>
typedef struct Dieta
{
	int id;
	Data data;
	char tipoRefeicao[N];
	char alimento[N];
	char cal[N];
} Dieta;

/// <summary>
///		Estrutura para guardar o plano nutricional
/// </summary>
typedef struct Plano
{
	int id;
	Data data;
	char tipoRefeicao[N];
	char calMinAd[N];
	char calMaxPer[N];
} Plano;

#pragma endregion





