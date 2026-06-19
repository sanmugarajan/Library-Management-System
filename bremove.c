#include "head.h"

void bremove()
{
        char op;

        pf("\n\n\n\n\n\n\n\n\n\n");
        if(hptr==0)
        {
                pf("\nNO BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\t\t\t\t+---------------------------+\n");
        pf("\t\t\t\t|      REMOVE MENU          |\n");
        pf("\t\t\t\t+---------------------------+\n");
        pf("\t\t\t\t| A/a : BY BOOK ID          |\n");
        pf("\t\t\t\t| B/b : BY BOOK TITLE       |\n");
        pf("\t\t\t\t+---------------------------+\n");

        pf("\nENTER YOUR CHOICE : ");
        sf(" %c",&op);

        if(op=='a'||op=='A')
        {
                int id;

                pf("\nENTER BOOK ID : ");
                sf("%d",&id);

                ptr=hptr;
                prev=0;

                while(ptr)
                {
                        if(ptr->book_id==id)
                        {
                                if(ptr==hptr)
                                {
                                        hptr=hptr->next;

                                        if(ptr==temp)
                                                temp=hptr;
                                }
                                else
                                {
                                        prev->next=ptr->next;

                                        if(ptr==temp)
                                                temp=prev;
                                }

                                free(ptr);

                                pf("\nBOOK REMOVED SUCCESSFULLY!\n");
                                return;
                        }

                        prev=ptr;
                        ptr=ptr->next;
                }

                pf("\nBOOK NOT FOUND!\n");
        }

        else if(op=='b'||op=='B')
        {
                char title[50];

                pf("\nENTER BOOK TITLE : ");
                sf("%s",title);

                ptr=hptr;
                prev=0;

                while(ptr)
                {
                        if(strcmp(ptr->title,title)==0)
                        {
                                if(ptr==hptr)
                                {
                                        hptr=hptr->next;

                                        if(ptr==temp)
                                                temp=hptr;
                                }
                                else
                                {
                                        prev->next=ptr->next;

                                        if(ptr==temp)
                                                temp=prev;
                                }

                                free(ptr);

                                pf("\nBOOK REMOVED SUCCESSFULLY!\n");
                                return;
                        }

                        prev=ptr;
                        ptr=ptr->next;
                }

                pf("\nBOOK NOT FOUND!\n");
        }

        else
        {
                pf("\nINVALID OPTION!\n");
        }
}
