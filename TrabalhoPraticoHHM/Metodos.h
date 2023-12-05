/*
* Autores:
*	- Hugo Especial / 27963 / a27963@aulunos.ipca.pt
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Pereira  / 27970 / a27970@alunos.ipca.pt
* Data: 26/11/2023
* Versão: 1.3 (Ultima vez modificado em 29/11/2023)
*/
#pragma once

#include <stdio.h>

#include "Structs.h"

// Outros Métodos
int contarLinhas(FILE* fp);

// Importa dados
int importaDadosPacientes(char nomeFicheiro[], Paciente p[], int maxPacientes);
int importaAlimentacaoPacientes(char nomeFicheiro[], Alimentacao ali[], int maxPacientes);
int importaDietaPacientes(char nomeFicheiro[], Dieta diet[], int maxPacientes);

// Guardar dados
bool guardaDadosPacientes(char nomeFicheiro[], Paciente p[], int n);
bool guardaDadosDieta(char nomeFicheiro[], Dieta d[], int n);
bool guardaDadosPlano(char nomeFicheiro[], Plano pl[], int n);

// Lê dados
int lerDadosPaciente(char nomeFicheiro[], Paciente p[]);
int lerDadosDieta(char nomeFicheiro[], Dieta d[]);
int lerDadosPlano(char nomeFicheiro[], Plano pl[]);