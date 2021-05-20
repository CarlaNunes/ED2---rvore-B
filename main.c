#include<stdio.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int main(void){

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
        }
        else{
            (*func[escolha-2])(fd,fi,fl);
        }
        
    }
    
    fclose(fd);
    fclose(fi);
    fclose(fl);
}