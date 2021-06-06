#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include"funcoes.h"
#include"btree.h"

int inserir_elemento (FILE *fd, FILE *fi, FILE *fl){  
    
    assert(printf("Função de inserção\n"));
    tKey insert_key, promo_key;
    int propo_r_child, i;
    
    int error, elemento_encontrado, chave_busca, retorno_RRN, retorno_posicao;
    
    char buffer[MAX_BUFFER_SIZE],
        buffer_size,
        aux_clear;
         
    tRegistro novo_registro;
    tHeader header;    

    /*************LEITURA DOS DADOS******************/
    printf("Elemento: ");
    for(int j = 0; j < 1000; j++){
        novo_registro.elemento[j] = rand() % 1000;
        sprintf(buffer, "%d", novo_registro.elemento[j]);
        buffer_size = strlen(buffer);
        assert(buffer != NULL);
    }
    
    //Limpar buffer de entrada
    while ((aux_clear = getchar()) != '\n' && aux_clear != EOF);   
    
    /*************COMPOSICAO DO REGISTRO******************/
    for(int j = 0; j < 1000; j++){
        sprintf(buffer, "%d", novo_registro.elemento[j]);
        buffer_size = strlen(buffer);
        assert(buffer != NULL);
        
    }    
    
    /*************OPERAÇÃO DE INSERÇÃO******************/
    //Registro de operação no arquivo de Log
    for(int j = 0; j < 1000; j++){
        fprintf (fl, "Execucao de operacao de INSERCAO de %d.\n",novo_registro.elemento[j]);
        header = read_header(fi);
    }

    //Primeira inserção
    if(header.root_RRN == -1)
        elemento_encontrado = 0;
    else{
        //Verifica se não há duplicação da chave
        for (i = 0; i <= header.pages; ++i)
        {
            for(int j = 0; j < 1000; j++){               
                fprintf (fl, "Execucao de operacao de INSERCAO de %d.\n",novo_registro.elemento[j]);
                elemento_encontrado = search_btree(fi, i, novo_registro.elemento[j], &retorno_RRN, &retorno_posicao);
            }
            if (elemento_encontrado)
                break;
        }
    }
    
    assert(printf("ENCONTRADO:%d\n", elemento_encontrado));

    if (elemento_encontrado > 0){
        for(int j = 0; j < 1000; j++){
            fprintf (fl, "  Chave %d duplicada.\n",novo_registro.elemento[j]);
        }
    }
    //AQUI QUE ESTÁ O ERRO:
    else if(elemento_encontrado == 0){
        /*************ESCRITA NO ARQUIVO DE DADOS******************/
        fseek(fd,0,SEEK_END);
        for(int j = 0; j < 1000; j++){
            fseek(fd,0,SEEK_END);
            insert_key.key = novo_registro.elemento[j];
            printf("INSERT KEY: %d",insert_key.key);
            insert_key.offset = ftell(fd);
            assert(printf("Inserindo:%d\nOffset:%ld\n", insert_key.key, insert_key.offset));    
            assert(fd != NULL);
            fwrite(&buffer_size,sizeof(buffer_size),i,fd);
            fwrite(buffer,buffer_size,i,fd);          
        }     
        
        set_header_update(fi,0);        //Indice desatualizado
        
        assert(printf("rootRRN: %d\n", get_root_RRN(fi)));
        
        error = insert_btree(fi,fl, get_root_RRN(fi), insert_key, &promo_key, &propo_r_child);

        if(error == 0){
            for(int j = 0; j < 1000; j++){
                fprintf (fl, "  Chave %d inserida com sucesso.\n",novo_registro.elemento[j]); 
                assert(printf("Atualiza indice\n"));
                set_header_update(fi,1);        //Indice atualizado
            }
        }else{
            printf("Error during the insertion\n");
            exit(0);
        }
    }    

    puts("");
    return 0;
} 