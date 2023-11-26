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

/*/// <summary>
/// Um procedimento para criar o Ficheiro "DadosPacientes.txt"
/// </summary>
void criarFicheiroDadosPacientes()
{
	FILE* fp;

	fp = fopen("DadosPacientes.txt", "w");

	fprintf(fp,
		"0001;Paulo;123456789\n0003;Maria;96543210\n0002;João;123321123"
	);

	fclose(fp);
}

/// <summary>
/// Um procedimento para criar o Ficheiro "CaloriaDia.txt"
/// </summary>
void criarFicheiroCaloriaDia()
{
	FILE* fp;

	fp = fopen("CaloriaDia.txt", "w");

	fprintf(fp, 
		"0001;01-01-2023;pequeno almoço;pão;60 cal\n0003;14 - 02 - 2023;almoço; sopa;120 cal\n0002;23 - 05 - 2023;jantar;prato de carne;1200 cal\n0001;01 - 01 - 2023;pequeno almoço;banana;120 cal"
	);

	fclose(fp);
}

/// <summary>
/// Um procedimento para criar o Ficheiro "CaloriaAdmissivel.txt"
/// </summary>
void criarFicheiroCalAdmissiveis()
{
	FILE* fp;

	fp = fopen("CaloriaAdmissivel.txt", "w");

	fprintf(fp, 
		"0001;01-01-2023;pequeno almoço;300 Cal, 400 Cal\n0001;01 - 01 - 2023;jantar;500 Cal, 600 Cal\n0003;21 - 03 - 2023;almoço;500 Cal, 600 Cal"
	);

	fclose(fp);
}*/
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

int GuardarDadosPacientes(Paciente p[], int tam)
{
	FILE* fpDadosPacientes, * fpDadosPacientesSaved;
	int contLinhas = 0;
	char buffer[100];

	fpDadosPacientes = fopen("DadosPacientes.txt", "r");

	if (fpDadosPacientes == NULL)
	{
		printf("ERRO AO ABRIR O FICHEIRO!!"); return 0;
	}
	else
	{
		int i = 0;
		while (i < tam)
		{
			fscanf(fpDadosPacientes, "%d;%[^;];%d", &p[i].id, p[i].nome, &p[i].telefone); i++;
		}

	}
	/*int i = 0;
	while (i < 3)
	{
		printf("\nID: %d,Nome: %s,  Telefone %d", p[i].id, p[i].nome, p[i].telefone); i++;
	}*/

	// Verificar se nao existe nenhum ficheiro binario que ja tenhas as informações dos Pacientes
	fpDadosPacientesSaved = fopen("DadosPacientes1.bin", "wb");

	if (fpDadosPacientesSaved == NULL || fpDadosPacientes == NULL)
	{
		printf("Erro na abertura de algum dos Ficheiros"); return 0;
	}
	else
	{	// Tou com problemas na parte de guardar em binario
		fwrite(p, sizeof(p), 1, fpDadosPacientesSaved);
	}

	//fseek(fpDadosPacientesSaved, 0, SEEK_SET);
	//fread(buffer, sizeof(p) + 1, tam, fpDadosPacientesSaved);
	//printf("P: %s\n", buffer);

	fclose(fpDadosPacientes);
	fclose(fpDadosPacientesSaved);
	return 1;
}

int GuardarDadosCaloriaDia(Paciente p[], int tam)
{
	FILE *fpDadosCalDia;

	fpDadosCalDia = fopen("CaloriaDia.txt", "r");

	if (fpDadosCalDia == NULL)
	{
		printf("ERRO AO ABRIR O FICHEIRO!!"); return 0;
	}
	else
	{
		int i = 0;
		while (i < tam)
		{
			// Nao ta a ler tudo
			fscanf(fpDadosCalDia, "%d;%[^;];%[^;];%[^;];%[^;]", 
				&p[i].id, p[i].ali.data, p[i].ali.tipoRefeicao,p[i].ali.alimento, p[i].ali.cal.calInstante); i++;
		}

	}
	int i = 0;
	while (i < tam)
	{
		printf("\n\nID: %d\nData: %s\nTipo Refeicao %s\nAlimento: %s\nCaloria: %s", p[i].id, p[i].ali.data, p[i].ali.tipoRefeicao, p[i].ali.alimento, p[i].ali.cal.calInstante); i++;
	}

	// Verificar se nao existe nenhum ficheiro binario que ja tenhas as informações dos Pacientes
	//fpDadosPacientesSaved = fopen("DadosPacientes1.bin", "wb");

	//if (fpDadosPacientesSaved == NULL || fpDadosPacientes == NULL)
	//{
	//	printf("Erro na abertura de algum dos Ficheiros"); return 0;
	//}
	//else
	//{	// Tou com problemas na parte de guardar em binario
	//	fwrite(p, sizeof(p), 1, fpDadosPacientesSaved);
	//}

	//fseek(fpDadosPacientesSaved, 0, SEEK_SET);
	//fread(buffer, sizeof(p) + 1, tam, fpDadosPacientesSaved);
	//printf("P: %s\n", buffer);

	fclose(fpDadosCalDia);
	//fclose(fpDadosCalDiaSaved);
	return 1;
}