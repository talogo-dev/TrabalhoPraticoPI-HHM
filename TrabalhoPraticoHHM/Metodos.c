/*
* 
*/
#include "Structs.h"

/// <summary>
/// 
/// </summary>
/// <param name="d"></param>
/// <param name="p"></param>
/// <param name="tamanhoDieta"></param>
/// <param name="tamanhoPlano"></param>
/// <returns></returns>

// Não funciona e falta implementar entre dois períodos
int pacientesUltrapassarCalorias(Dieta d[], Plano p[], int tamanhoDieta, int tamanhoPlano) {
	int contador = 0;
	int i = 0;

	for (int i = 0; i < tamanhoPlano; i++) {
		for (int j = 0; i < tamanhoDieta; j++) {
			if (p[i].id == d[i].id) {
				if (strcmp(p[i].tipoRefeicao, d[i].tipoRefeicao) == 0) {
					if (d[i].cal > p[i].calMaxPer) {
						contador += 1;
					}
				}
			}
		}
	}

	return contador;
}

/// <summary>
/// 
/// </summary>
/// <param name="pacienteId"></param>
/// <param name="tipoRefeicao"></param>
/// <param name="p"></param>
/// <param name="tamanhoPlano"></param>
/// <param name="dataInicio"></param>
/// <param name="dataFim"></param>
/// <returns></returns>
Plano listarPlanoNutricional(int pacienteId, char tipoRefeicao[], Plano p[], int tamanhoPlano, Data dataInicio, Data dataFim) {
	for (int i = 0; i < tamanhoPlano; i++) {
		if (p[i].id == pacienteId) {
			if (strcmp(p[i].tipoRefeicao, tipoRefeicao) == 0) {
				if (p[i].data.dia > dataInicio.dia && p[i].data.dia < dataFim.dia) {
					if (p[i].data.mes > dataInicio.mes && p[i].data.dia < dataFim.mes) {
						printf("%d", p[i].id);
					}
				}
			}
		}
	}
}