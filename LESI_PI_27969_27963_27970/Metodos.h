/*
* 
*/

#pragma once

#include <stdio.h>

#include "Structs.h"

// Criação de Ficheiros
void criarFicheiroDadosPacientes();
void criarFicheiroCaloriaDia();
void criarFicheiroCalAdmissiveis();

// Outros Métodos
int contarLinhas(FILE* fp);

