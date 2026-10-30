#ifndef BOOK_H
#define BOOK_H

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

char *read_string(void);
void temp_book_destroy(Temp_book *book);
void book_destroy(Book *book);
void clear_buffer(void);

short int add_book(Book *books);
short int edit_book(const unsigned short int ID, Temp_book *temporary_book);
short int delete_book(const unsigned short int);
short int show_book(void);

#endif
