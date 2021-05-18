#include"btree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"
#include <assert.h>

int main(void){

    FILE *fd = NULL,
         *fi = NULL,
         *fl = NULL;

    assert(printf("Ordem: %d\n", ORDER));
    assert(printf("Chaves: %d\n", N_KEYS));

    init(&fd,&fi,&fl);

    int escolha = 0,
        i;

    char *menu[] = {"Criar indice", "Inserir Aluno", "Pesquisar aluno por numUSP", "Remover aluno por numUSP(Não implementada)", "Mostrar arvore-B(Encerrar)", "Fechar"};
    //
    int (*func[])(FILE *fd, FILE *fi, FILE *fl) = {inserir_elemento};
    //int (*func[])(FILE *fd, FILE *fi, FILE *fl) = {dados_random,pesquisar_elemento,remover_elemento,mostrar_btree};
    while(1){
        printf("Escolha uma opcao:\n");

      //  for(i = 0; i < MENU_SIZE; i++)
        for(i = 0; i < 6; i++)
            printf("%d - %s\n", i+1, menu[i]);

        printf("> ");
        scanf("%d",&escolha);

        if(escolha > 6 || escolha < 1)
            printf("\nOpcao Invalida\n");
            //5 MENU_SIZE
        else if(escolha == 5)           //Última opção é sempre para fechar
            break;
        else if(escolha == 1){
            criar_indice(fd, &fi, fl);
        }
        else
            (*func[escolha-2])(fd,fi,fl);

    }

    fclose(fd);
    fclose(fi);
    fclose(fl);
}
