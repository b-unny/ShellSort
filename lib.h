#ifndef LIB_H
#define LIBH

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct vetor
{
  int *info; // info é o vet[]
  int tam;
  double time_insert, time_select, time_shell; 
} Vetor;


Vetor *criar_vet(int tam);
int *copiar_vet(Vetor *vet);
void preencher_rand(Vetor *vet);
void calc_tempo(Vetor *vet, void(*algoritmo)(int*, int), double *tempo);
void print_tempo(Vetor *vet);
void print_erro();
void swap(int *a, int *b);

void insert_sort(int *vet, int tam);
void select_sort(int *vet, int tam);
void shell_sort(int *vet, int tam);

#endif
