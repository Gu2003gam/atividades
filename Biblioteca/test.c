#include "book.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    
    Book *book = calloc(1,sizeof(*book));
    Temp_book *temp_book = calloc(1, sizeof(*book));
    if (book == NULL) {return 1;}
    printf("ID: ");
    scanf("%hu", &book->ID);
    clear_buffer();

    printf("paginas: ");
    scanf("%hu", &book->pages);
    clear_buffer();

    printf("quantidade: ");
    scanf("%u", &book->amount);
    clear_buffer();

    printf("ano: ");
    scanf("%hu", &book->year);
    clear_buffer();

    printf("titulo: ");
    book->title = read_string();
    if (book->title == NULL) {free(book->title); return 1;}

    printf("tipo: ");
    book->type = read_string();
    if (book->type == NULL) {free(book->type); return 1;}
    
    printf("editora: ");
    book->publisher = read_string();
    if (book->publisher == NULL) {free(book->publisher); return 1;}

     printf("autor: ");
    book->author = read_string();
    if (book->author == NULL) {free(book->author); return 1;}

    add_book(book);

    unsigned short int ID;

    printf("Digite o ID do livro que você deseja editar: \n");
    printf(">>> ");
    scanf("%hu%*c", &ID);

    printf("Digite as informações do livro: \n");

     printf("paginas: ");
    scanf("%hu", &temp_book->pages);
    clear_buffer();

    printf("quantidade: ");
    scanf("%u", &temp_book->amount);
    clear_buffer();

    printf("ano: ");
    scanf("%hu", &temp_book->year);
    clear_buffer();

    printf("titulo: ");
    temp_book->title = read_string();
    if (temp_book->title == NULL) {free(temp_book->title); return 1;}

    printf("tipo: ");
    temp_book->type = read_string();
    if (temp_book->type == NULL) {free(temp_book->type); return 1;}
    
    printf("editora: ");
    temp_book->publisher = read_string();
    if (temp_book->publisher == NULL) {free(temp_book->publisher); return 1;}

     printf("autor: ");
    temp_book->author = read_string();
    if (temp_book->author == NULL) {free(temp_book->author); return 1;}

    edit_book(ID, temp_book);
    
    show_book();
    printf("Digite o ID do livro que deseja deletar: \n");
    printf(">>> ");
    scanf("%hu%*c",&ID);
    delete_book(ID);
    show_book();
    

    temp_book_destroy(temp_book);
    book_destroy(book);
    book = NULL;
}
