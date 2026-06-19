#include "head.h"

void search()
{
        char op;

        pf("\n\n\n\n\n\n\n\n\n\n");
        if(hptr==0)
        {
                pf("\nNO BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\t\t\t\t+---------------------------+\n");
        pf("\t\t\t\t|      SEARCH MENU          |\n");
        pf("\t\t\t\t+---------------------------+\n");
        pf("\t\t\t\t|    A/a : BY BOOK ID       |\n");
        pf("\t\t\t\t|    B/b : BY BOOK TITLE    |\n");
        pf("\t\t\t\t|    C/c : BY AUTHOR NAME   |\n");
        pf("\t\t\t\t+---------------------------+\n");

        pf("\nENTER YOUR CHOICE : ");
        sf(" %c",&op);

        ptr=hptr;

        if(op=='a'||op=='A')
        {
                int id;

                pf("\nENTER BOOK ID : ");
                sf("%d",&id);

                while(ptr)
                {
                        if(ptr->book_id==id)
                        {
                                pf("\nBOOK FOUND\n");

                                pf("\nBOOK ID   : %d",ptr->book_id);
                                pf("\nTITLE     : %s",ptr->title);
                                pf("\nAUTHOR    : %s",ptr->author);
                                pf("\nQUANTITY  : %d\n",ptr->quantity);

                                return;
                        }

                        ptr=ptr->next;
                }

                pf("\nBOOK NOT FOUND!\n");
        }

        else if(op=='b'||op=='B')
        {
                char title[50];
                int found=0;

                pf("\nENTER BOOK TITLE : ");
                sf("%s",title);

                while(ptr)
                {
                        if(strcmp(ptr->title,title)==0)
                        {
                                found=1;

                                pf("\nBOOK ID   : %d",ptr->book_id);
                                pf("\nTITLE     : %s",ptr->title);
                                pf("\nAUTHOR    : %s",ptr->author);
                                pf("\nQUANTITY  : %d\n",ptr->quantity);
                        }

                        ptr=ptr->next;
                }

                if(found==0)
                        pf("\nBOOK NOT FOUND!\n");
        }

        else if(op=='c'||op=='C')
        {
                char author[50];
                int found=0;

                pf("\nENTER AUTHOR NAME : ");
                sf("%s",author);

                while(ptr)
                {
                        if(strcmp(ptr->author,author)==0)
                        {
                                found=1;

                                pf("\nBOOK ID   : %d",ptr->book_id);
                                pf("\nTITLE     : %s",ptr->title);
                                pf("\nAUTHOR    : %s",ptr->author);
                                pf("\nQUANTITY  : %d\n",ptr->quantity);
                        }

                        ptr=ptr->next;
                }

                if(found==0)
                        pf("\nBOOK NOT FOUND!\n");
        }

        else
        {
                pf("\nINVALID OPTION!\n");
        }
}
