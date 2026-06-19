#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define pf printf
#define sf scanf

typedef struct book
{
        int book_id;
        char title[50];
        char author[50];
        int quantity;
        struct book *next;
}bk;

typedef struct issue_book
{
        int issue_id;
        int book_id;
        int user_id;
        char user_name[50];
        char issue_date[30];
        char due_date[30];
        char return_date[30];

        struct issue_book *next;
}is;

extern bk *node;
extern bk *temp;
extern bk *ptr;
extern bk *prev;
extern bk *hptr;

extern is *inode;
extern is *itemp;
extern is *iptr;
extern is *ihptr;

void add();
int get_bookid();

void update();

void bremove();

void search();

void view();

void issue();
int get_issueid();

void breturn();

void list();

void save();
void load_data();

void bexit();

#endif
