#include"lib.h"

Vetor *criar_vet(int tam)
{
  Vetor *v = (Vetor*)malloc(sizeof(Vetor));
  if(v==NULL) print_erro();
  v->tam = tam;
  v->info = (int*)malloc(tam * sizeof(int));
  if(v->info == NULL)
  {
    free(v);
    print_erro();
  }
  return v;
}

int *copiar_vet(Vetor *vet)
{
  int *copia = (int*)malloc(vet->tam * sizeof(int));
  if(copia == NULL) print_erro();
  for(int i=0; i<vet->tam; i++)
    copia[i] = vet->info[i];
  return copia;
}

void preencher_rand(Vetor *vet)
{
srand(time(NULL));
  for(int i=0; i < vet->tam; i++)
    vet->info[i] = rand()%1000;
}

void calc_tempo(Vetor *vet, void(*algoritmo)(int*, int), double *time)
{
  int *copia = copiar_vet(vet);
  clock_t ini = clock();
  algoritmo(copia, vet->tam);
  clock_t fim = clock();
  *time = ((double)(fim - ini)) / CLOCKS_PER_SEC;
}

void print_tempo(Vetor *vet)
{
  printf("Tempos de Ordenacao:\n");
  printf("Insert sort: %.5fs\n", vet->time_insert);
  printf("Select sort: %.5fs\n", vet->time_select);
  printf("Shell sort: %.5fs\n", vet->time_shell);
}


void print_erro()
{
  printf("Erro de alocacao de memoria.\n");
  exit(1);
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

//===== Metodos de Ordenacao =====

void insert_sort(int *vet, int tam)
{
  int i, j, chave;

  for(i=1; i < tam-1; i++)
  {
    chave = vet[i];
    for(j=i-1; j>=0; j--)
    {
      if(chave < vet[j])
        vet[j+1] = vet[j];
    }
    vet[j+1] = chave; 
  }
}

void select_sort(int *vet, int tam)
{
  for(int i = 0; i < tam-1; i++)
  {
    int min = i;
    for(int j = i+1; j < tam; j++)
    {
      if(vet[j] < vet[min])
        min = j;
    }
    swap(&vet[i], &vet[min]);
  }
}

void shell_sort(int *vet, int tam)
{
  //dist (intervalo) é a distancia entre os elementos a comparar
  //começamos com um intervalo grande e vamos diminuindo pela metade
  for(int dist=tam/2; dist>0; dist/=2)
  {
    // percorremos o vetor a partir do idx igual ao intervalo até o final
    for(int i=dist; i<tam; i++)
    {
      int j, atual = vet[i];
      // pegamos o valor do atua a ser posicionado
      // reposicionamos o valor atual na posição correa dentro do subvetor
      for(j=i; j>=dist && vet[j-dist]>atual; j-=dist)
        vet[j] = vet[j-dist];
      // inserimos o valor do atual na posição correta
      vet[j] = atual;
    }
  }
}

