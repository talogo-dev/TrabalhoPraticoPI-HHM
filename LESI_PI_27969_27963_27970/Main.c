/*
* 
*/

#include <stdio.h>
#include <locale.h>

#include "Metodos.h";
#include "Structs.h"

#pragma warning (disable: 4996)

int main()
{
	setlocale(LC_ALL, "Portuguese");

	FILE* fp;
	Paciente p[3];
	int contLinhas = 0;

	#pragma region Criação dos Ficheiros

	criarFicheiroDadosPacientes();
	criarFicheiroCaloriaDia();
	criarFicheiroCalAdmissiveis();
	
	#pragma endregion

	fp = fopen("DadosPacientes.txt", "r");

	if (fp == NULL)
		printf("ERRO AO ABRIR O FICHEIRO!!");
	else
	{
		//Contar as linhas do ficheiro
		//contLinhas = contarLinhas(fp);

		int i = 0;
		// Aqui uso o ciclo while ( devia usar o for ) para ler todas as linhas ( meti 3 porque sei que sao 3 )
		// FUTURO: Em vez de 3 linhas, coloco ate chegar ao fim do ficheiro

		//[^;] = Le tudo exceto o ';'
		while (i < 3)
		{
			fscanf(fp, "%d;%[^;];%d", &p[i].id, p[i].nome, &p[i].telefone); i++;
		}
			
	}
	
	int j = 0;
	// Ciclo while para imprimir tudo que li acima  ( devia usar o for )
	while (j < 3)
	{
		printf("\nDados de %s\n", p[j].nome);
		printf("ID: %d\nNome: %s\nTelefone: %d\n", p[j].id, p[j].nome, p[j].telefone);
		j++;
	}

	fclose(fp);

}