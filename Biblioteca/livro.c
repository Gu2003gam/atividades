#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned short int ID;
    unsigned short int pages;
    unsigned short int year;
    unsigned int amount;

    char *title;
    char *type;
    char *publisher;
    char *author;
} Book;

typedef struct {
    unsigned short int pages;
    unsigned short int year;
    unsigned int amount;

    char *title;
    char *type;
    char *publisher;
    char *author;
} Temp_book;

static char *read_string(void) {

  char *text = NULL;
  size_t capacity = 0;

  ssize_t length = getline(&text, &capacity, stdin);

  if (length < 0) {
    free(text);
    return NULL;
  }

  if (length > 0 && text[length - 1] == '\n') {
    text[length - 1] = '\0';
  }
  return text;
}

static void book_destroy(Book *book) {
  if (book == NULL) {return;}

  free(book->title);
  free(book->type);
  free(book->publisher);
  free(book->author);

  free(book);
}
static void temp_book_destroy(Temp_book *book) {
  if (book == NULL) {return;}

  free(book->title);
  free(book->type);
  free(book->publisher);
  free(book->author);

  free(book);
}

static void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static short int add_book(Book *books) {
    FILE *file = fopen("book.txt", "a");
    if (file == NULL) {return -1;}
    fprintf(file, " %hu;%hu;%hu;%u;%s;%s;%s;%s\n ", books->ID, books->pages, books->year,books->amount,
        books->title, books->type, books->publisher, books->author);
    fclose(file);
    return 0;
}

static short int edit_book(const unsigned short int ID, Temp_book *temporary_book) {
    FILE *file = fopen("book.txt", "r");
    FILE *temp_file = fopen("temporary.txt", "w");
    if (file == NULL || temp_file == NULL) {return -1;}

    bool found = false;
    char row[256];
    char id_row[100];
    snprintf(id_row, sizeof(id_row), "%hu", ID);

    while(fgets(row, sizeof(row), file) != NULL) {
      char copy[sizeof(row)];
      strcpy(copy, row);
      char *token = strtok(copy, ";");

      if (token != NULL && strtoul(token, NULL, 10) == ID) {
          fprintf(temp_file, "%hu;%hu;%hu;%u;%s;%s;%s;%s\n", ID, temporary_book->pages, temporary_book->year, temporary_book->amount,
            temporary_book->title, temporary_book->type, temporary_book->publisher, temporary_book->author); found = true;}
      else {fputs(row, temp_file);}
    }
    if (!found) {printf("Não foi possível editar o livro"); return -1;}
    fclose(file);
    fclose(temp_file);
    remove("book.txt");
    rename("temporary.txt", "book.txt");
    return 0;
}
static short int delete_book(const unsigned short int ID) {
    FILE *file = fopen("book.txt", "r");
    FILE *temp_file = fopen("temporary.txt", "w");
    if (file == NULL || temp_file == NULL) {return -1;}
    char row[256];
    char id_row[100];
    snprintf(id_row, sizeof(id_row), "%hu", ID);
    while (fgets(row, sizeof(row), file) != NULL) {
      char copy[sizeof(row)];
      strcpy(copy, row);
      char *token = strtok(copy, ";");
        if (!(token != NULL && strtoul(token, NULL, 10) == ID)) {fputs(row, temp_file);}
    }
    fclose(file);
    fclose(temp_file);
    remove("book.txt");
    rename("temporary.txt", "book.txt");
    return 0;
}
static short int show_book(void) {
  FILE *file = fopen("book.txt", "r");
  if (file == NULL) {return -1;}
  char row[256];
    while(fgets(row, sizeof(row), file) != NULL) {
      printf("%s", row);
    }
    printf("\n");
    fclose(file);
    return 0;  
}
int main(int argc, char **argv) {
    /*
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

    /* printf("Digite o ID do livro que você deseja editar: \n");
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
    */
}