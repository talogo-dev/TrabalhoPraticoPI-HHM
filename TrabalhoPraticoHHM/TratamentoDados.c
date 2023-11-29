/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.5 (Ultima vez modificado em 29/11/2023)
* 
* 
* NOTA: Contem erros e algumas partes não funcionam
*	- GuardarDadosPacientes: Guardar em Binario
*	- GuardarDadosCaloriaDia: Ler o txt
*/

#include <stdio.h>
#include "Structs.h"

#pragma warning (disable: 4996)

// Esta a dar problema com o Main
int contarLinhas(FILE* fp)
{
	char c; 

	// 1 porque o contador de linhas só regista a quando encontrar um 'enter' e na primeira linha nao ha 'enter'
	int cont = 1;
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n') // Increment count if this character is newline
		{
			cont = cont + 1;
		}

	}
	return cont;
}

/// <summary>
/// Função para ler os Dados de um ficheiro csv (neste caso o ficheiro "DadosPacientes.csv")
/// </summary>
/// <param name="p"></param>
/// <param name="tam"></param>
/// <returns>Int quantidade de dados guardados</returns>

int LerDadosPacientes(char nomeFicheiro[], Paciente p[], int maxPacientes)
{
	FILE* fp;
	int i = 0;

	fp = fopen(nomeFicheiro, "r");
	if (fp == NULL)
		return -1;
	
	while (1)
	{
		fscanf(fp,"%d;%[^;];%s",
			&p[i].id, p[i].nome, p[i].telefone); 
		
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return i;
}

/// <summary>
/// Função para ler os Dados de um ficheiro csv (neste caso o ficheiro "Alimentacao.csv")
/// </summary>
/// <param name="p"></param>
/// <param name="tam"></param>
/// <returns>Int quantidade de dados guardados</returns>

// a dar erro ao ler 
// JA NAO DA ERRO O BINÃO RESOLVEU

int LerAlimentacaoPacientes(char nomeFicheiro[], Alimentacao ali[], int maxPacientes)
{
	FILE* fpAlPa;
	int i = 0;

	fpAlPa = fopen(nomeFicheiro, "r");
	if (fpAlPa == NULL)
		return -1;

	while (1)
	{
		fscanf(fpAlPa, "%d;%[^;];%[^;];%[^;];%s", &ali[i].id, ali[i].data, ali[i].tipoRefeicao, ali[i].alimento, ali[i].cal);

		if (feof(fpAlPa)) break;
		i++;
	}
	fclose(fpAlPa);
	return i;
}


/// <summary>
/// Função para ler os Dados de um ficheiro csv (neste caso o ficheiro "Dieta.csv")
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="ali"></param>
/// <param name="maxPacientes"></param>
/// <returns>quantidade de dietas i</returns>
int LerDietaPacientes(char nomeFicheiro[], Dieta diet[], int maxPacientes)
{
	FILE* fpAlPa;
	int i = 0;

	fpAlPa = fopen(nomeFicheiro, "r");
	if (fpAlPa == NULL)
		return -1;

	while (1)
	{
		fscanf(fpAlPa, "%d;%[^;];%[^;];%s", &diet[i].id, diet[i].data, diet[i].tipoRefeicao, diet[i].cal);

		i++;
		if (feof(fpAlPa)) break;
		
	}
	fclose(fpAlPa);
	return i;
}



