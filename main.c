#include"lib.h"

void main()
{
  while(1)
  {
    int tam, opcao;
    printf("Tamanho (0 para sair): ");
    scanf("%d", &tam);
   
    if(tam == 0) break;
    
    Vetor *vet = criar_vet(tam);
     
    preencher_rand(vet);
    
    calc_tempo(vet, insert_sort, &vet->time_insert);
    calc_tempo(vet, select_sort, &vet->time_select);
    calc_tempo(vet, shell_sort, &vet->time_shell);
   
    print_tempo(vet);
    free(vet->info);
    free(vet);
    printf("\n");
  }
  printf("Programa finalizado.\n");
}
