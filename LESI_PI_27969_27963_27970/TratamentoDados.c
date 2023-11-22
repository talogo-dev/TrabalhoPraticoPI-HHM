/*
* 
*/

#include <stdio.h>
#include "Structs.h"

#pragma warning (disable: 4996)

/// <summary>
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
}
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