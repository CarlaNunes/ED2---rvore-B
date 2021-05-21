#include<stdio.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int main(void){
    clock_t t; //variável para armazenar tempo
  
    FILE *fd = NULL,
         *fi = NULL,
         *fl = NULL;
    
    assert(printf("Ordem: %d\n", ORDER));
    assert(printf("Chaves: %d\n", N_KEYS));
    
    init(&fd,&fi,&fl);
    
    int escolha = 0,
        i;
    
    char *menu[] = {"Criar indice", "Inserir", "Pesquisar", "Fechar"};
    int (*func[])(FILE *fd, FILE *fi, FILE *fl) = {inserir_elemento,pesquisar_elemento};
    t = clock(); //armazena tempo
  
    while(1){
        printf("Escolha uma opcao:\n");
        
        for(i = 0; i < 4; i++)
            printf("%d - %s\n", i+1, menu[i]);
        
        printf("> ");
        scanf("%d",&escolha);
        
        if(escolha > 4 || escolha < 1){
            printf("\nOpcao Invalida\n");
        }
        else if(escolha == 4){
            break;
        }         
            
        else if(escolha == 1){
            criar_indice(fd, &fi, fl);
            t = clock() - t; //tempo final - tempo inicial
            printf("\n Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para doubl
  
        }
        else{
            (*func[escolha-2])(fd,fi,fl);
            t = clock() - t; //tempo final - tempo inicial
            printf("\n Tempo de execucao: %lf \n ", ((double)t)/((CLOCKS_PER_SEC/1000))*0.001); //conversão para doubl
            printf("\n");
        }
        
    }
    
    fclose(fd);
    fclose(fi);
    fclose(fl);
}