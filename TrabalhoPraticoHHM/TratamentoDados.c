/*
* Autores:
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Pereira  / 27970 / a27970@alunos.ipca.pt
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

#pragma region Importação de dados
/// <summary>
/// Função para ler os Dados de um ficheiro csv (neste caso o ficheiro "DadosPacientes.csv")
/// </summary>
/// <param name="p"></param>
/// <param name="tam"></param>
/// <returns>Int quantidade de dados guardados</returns>

int importaDadosPacientes(char nomeFicheiro[], Paciente p[], int maxPacientes)
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

int importaAlimentacaoPacientes(char nomeFicheiro[], Alimentacao ali[], int maxPacientes)
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
int importaDietaPacientes(char nomeFicheiro[], Dieta diet[], int maxPacientes)
{
	FILE* fpAlPa;
	int i = 0;

	fpAlPa = fopen(nomeFicheiro, "r");

	if (fpAlPa == NULL)
		return -1;

	while (1)
	{
		fscanf(fpAlPa, "%d;%[^;];%[^;];%s", &diet[i].id, diet[i].data, diet[i].tipoRefeicao, diet[i].cal);
		if (feof(fpAlPa)) break;
		i++;
		
	}
	fclose(fpAlPa);
	return i;
}
#pragma endregion

#pragma region Guarda dados
/// <summary>
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="p"></param>
/// <param name="n"></param>
/// <returns></returns>
bool guardaDadosPacientes(char nomeFicheiro[], Paciente p[], int n) {
	FILE* ficheiro = fopen(nomeFicheiro, "wb");

	if (ficheiro == NULL) return false;

	for (int i = 0; i < n; i++) {
		fwrite(&p[i], 1, sizeof(Paciente), ficheiro);
	}

	fclose(ficheiro);

	return true;
}

/// <summary>
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="d"></param>
/// <param name="n"></param>
/// <returns></returns>
bool guardaDadosDieta(char nomeFicheiro[], Dieta d[], int n) {
	FILE* ficheiro = fopen(nomeFicheiro, "wb");

	if (ficheiro == NULL) return false;

	for (int i = 0; i < n; i++) {
		fwrite(&d[i], 1, sizeof(Dieta), ficheiro);
	}

	fclose(ficheiro);

	return true;
}

/// <summary>
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="pl"></param>
/// <param name="n"></param>
/// <returns></returns>
bool guardaDadosPlano(char nomeFicheiro[], Plano pl[], int n) {
	FILE* ficheiro = fopen(nomeFicheiro, "wb");

	if (ficheiro == NULL) return false;

	for (int i = 0; i < n; i++) {
		fwrite(&pl[i], 1, sizeof(Plano), ficheiro);
	}

	fclose(ficheiro);

	return true;
}
#pragma endregion

#pragma region Lê dados
/// <summary>
/// 
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="p"></param>
/// <returns></returns>
int lerDadosPaciente(char nomeFicheiro[], Paciente p[]) {
	FILE* ficheiro = fopen(nomeFicheiro, "rb");

	if (ficheiro == NULL) return -1;

	int i = 0;

	while (fread(&p[i], 1, sizeof(Paciente), ficheiro)) {
		i++;
	}

	fclose(ficheiro);

	return i;
}

/// <summary>
/// 
/// </summary>
/// <param name="nomeFicheiro"></param>
/// <param name="d"></param>
/// <returns></returns>
int lerDadosDieta(char nomeFicheiro[], Dieta d[]) {
	FILE* ficheiro = fopen(nomeFicheiro, "rb");

	if (ficheiro == NULL) return -1;

	int i = 0;

	while (fread(&d[i], 1, sizeof(Dieta), ficheiro)) {
		i++;
	}

	fclose(ficheiro);

	return i;
}

int lerDadosPlano(char nomeFicheiro[], Plano pl[]) {
	FILE* ficheiro = fopen(nomeFicheiro, "rb");

	if (ficheiro == NULL) return -1;

	int i = 0;

	while (fread(&pl[i], 1, sizeof(Plano), ficheiro)) {
		i++;
	}

	fclose(ficheiro);

	return i;
}
#pragma endregion
