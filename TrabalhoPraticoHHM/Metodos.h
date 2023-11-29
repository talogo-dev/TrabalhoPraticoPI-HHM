/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.3 (Ultima vez modificado em 29/11/2023)
*/
#pragma once

#include <stdio.h>

#include "Structs.h"

// Outros Métodos
int contarLinhas(FILE* fp);

// Ler de Dados
int LerDadosPacientes(char nomeFicheiro[], Paciente p[], int maxPacientes);
int LerAlimentacaoPacientes(char nomeFicheiro[], Alimentacao ali[], int maxPacientes);