#include<stdio.h>
#include<stdlib.h>

#ifndef _funcoes_h
#define _funcoes_h

#define MENU_SIZE 6
#define MAX_BUFFER_SIZE 100
#define TAM 16

#define NOME_DADOS "dados.dad"
#define NOME_INDICE "index.dat"
#define NOME_LOG "log_X.txt"//Arquivo de operações de acordo com os dados inseridos.

#include"btree.h"

typedef int tipoChave;

typedef struct {
	tipoChave numUSP;
	char nome[TAM];
	char sobrenome[TAM];
	char curso[TAM];
	float nota;
} aluno;

//int binarysearch (int *array, int size, int key);
//int init (FILE **fd, FILE **fi, FILE **fl);
int criar_indice (FILE *fd, FILE **fi, FILE *fl);
//int dados_random(FILE *fd, FILE *fi, FILE *fl);
//int get_free_RRN(FILE *fi);
//int get_root_RRN(FILE *fi);
//int init (FILE **fd, FILE **fi, FILE **fl);
int inserir_elemento (FILE *fd, FILE *fi, FILE *fl);
//int insert_btree(FILE *fi, FILE *fl, int RRN, tKey key, tKey *propo_key, int *propo_r_child);
//int mostrar_btree (FILE *fd, FILE *fi, FILE *fl);
tPage new_page();
//int pesquisar_elemento (FILE *fd, FILE *fi, FILE *fl);
//tHeader read_header(FILE *fi);
//tPage read_page(FILE *fi, int RRN);
//int remover_elemento (FILE *fd, FILE *fi, FILE *fl);
//int search_btree(FILE *fi, int RRN, int key, int *found_RRN, int *found_position);
//int set_header_update(FILE *fi, int status);
//int set_update_pages(FILE *fi, int RRN);
//int sort_keys(tKey *key_array, int size_key, int *children_array);
//int split(FILE *fi, tPage *page, int RRN, tKey key, int r_child_connect, tKey *propo_key, int *propo_r_child);
//int update_free_slot(FILE *fi, int new_slot);
//int update_root(FILE *fi, int new_root);
int write_header(FILE *fi, tHeader header);
int write_page(FILE *fi, tPage actual_page, int RRN);


#endif
