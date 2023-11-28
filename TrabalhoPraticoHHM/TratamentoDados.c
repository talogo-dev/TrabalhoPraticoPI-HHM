/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial /		/
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.5 (Ultima vez modificado em 26/11/2023)
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
		i++;
		if (feof(fp)) break;
	}
	fclose(fp);
	return i;
}

/// <summary>
/// Função para ler os Dados de um ficheiro csv (neste caso o ficheiro "CaloriaDia.csv")
/// </summary>
/// <param name="p"></param>
/// <param name="tam"></param>
/// <returns>Int quantidade de dados guardados</returns>

// a dar erro ao ler
int LerAlimentacaoPacientes(char nomeFicheiro[], Paciente p[], int maxPacientes)
{
	FILE *fpAlPa;
	int i = 0;

	fpAlPa = fopen(nomeFicheiro, "r");
	if (fpAlPa == NULL)
		return -1;

	while (1)
	{

		fscanf(fpAlPa, "%d;%[^;];%[^;];%[^;];%s",
					&p[i].id, //int
					p[i].ali.data, //char
					p[i].ali.tipoRefeicao, //char
					p[i].ali.alimento, //char
					p[i].ali.cal.calInstante //char
			  );

		i++;
		if(feof(fpAlPa)) break;
	}
	fclose(fpAlPa);
	return i;
}