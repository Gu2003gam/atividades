#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "book.h"

extern char *read_string(void) {

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

extern void book_destroy(Book *book) {
  if (book == NULL) {return;}

  free(book->title);
  free(book->type);
  free(book->publisher);
  free(book->author);

  free(book);
}
extern void temp_book_destroy(Temp_book *book) {
  if (book == NULL) {return;}

  free(book->title);
  free(book->type);
  free(book->publisher);
  free(book->author);

  free(book);
}

extern void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

extern short int add_book(Book *books) {
    FILE *file = fopen("book.txt", "a");
    if (file == NULL) {return -1;}
    fprintf(file, "%hu;%hu;%hu;%u;%s;%s;%s;%s\n", books->ID, books->pages, books->year,books->amount,
        books->title, books->type, books->publisher, books->author);
    fclose(file);
    return 0;
}

extern short int edit_book(const unsigned short int ID, Temp_book *temporary_book) {
    FILE *file = fopen("book.txt", "r");
    FILE *temp_file = fopen("temporary.txt", "w");
    if (file == NULL || temp_file == NULL) {return -1;}

    bool found = false;
    char row[256];

    while(fgets(row, sizeof(row), file) != NULL) {
      char copy[sizeof(row)];
      strcpy(copy, row);
      char *token = strtok(copy, ";");

      if (token != NULL && strtoul(token, NULL, 10) == ID) {
          fprintf(temp_file, "%hu;%hu;%hu;%u;%s;%s;%s;%s\n", ID, temporary_book->pages, temporary_book->year, temporary_book->amount,
            temporary_book->title, temporary_book->type, temporary_book->publisher, temporary_book->author); found = true;}
      else {fputs(row, temp_file);}
    }
    if (!found) { 
      printf("Não foi possível editar o livro");
      fclose(file);
      fclose(temp_file);
      return -1;
    }
    remove("book.txt");
    rename("temporary.txt", "book.txt");
    return 0;
}
extern short int delete_book(const unsigned short int ID) {
    FILE *file = fopen("book.txt", "r");
    FILE *temp_file = fopen("temporary.txt", "w");
    if (file == NULL || temp_file == NULL) {
      if (file != NULL) {fclose(file);}
      if (temp_file != NULL) {fclose(temp_file);}
      return -1;
    }
    char row[256];
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
extern short int show_book(void) {
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
