/*
* Autores:
*	- Marco Cardoso / 27969 / a27969@alunos.ipca.pt
*	- Hugo Especial /		/
*	- Hugo Pereira  /		/
* Data: 26/11/2023
* Versão: 1.3 (Ultima vez modificado em 26/11/2023)
*/
#pragma once

#include <stdio.h>

#include "Structs.h"

// Criação de Ficheiros
//void criarFicheiroDadosPacientes();
//void criarFicheiroCaloriaDia();
//void criarFicheiroCalAdmissiveis();

// Outros Métodos
int contarLinhas(FILE* fp);

// Guarda de Dados
int GuardarDadosPacientes(Paciente p[], int tam);
int GuardarDadosCaloriaDia(Paciente p[], int tam);

