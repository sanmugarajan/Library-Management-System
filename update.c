#include "head.h"

void update()
{
        char op;

        pf("\n\n\n\n\n\n\n\n\n\n");
        if(hptr==0)
        {
                pf("\nNO BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\t\t\t\t+---------------------------+\n");
        pf("\t\t\t\t|      UPDATE MENU          |\n");
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

                while(ptr)
                {
                        if(ptr->book_id==id)
                        {
                                pf("\nENTER NEW TITLE : ");
                                sf("%s",ptr->title);

                                pf("\nENTER NEW AUTHOR : ");
                                sf("%s",ptr->author);

                                pf("\nENTER NEW QUANTITY : ");
                                sf("%d",&ptr->quantity);

                                pf("\nBOOK UPDATED SUCCESSFULLY!\n");
                                return;
                        }

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

                while(ptr)
                {
                        if(strcmp(ptr->title,title)==0)
                        {
                                pf("\nENTER NEW TITLE : ");
                                sf("%s",ptr->title);

                                pf("\nENTER NEW AUTHOR : ");
                                sf("%s",ptr->author);

                                pf("\nENTER NEW QUANTITY : ");
                                sf("%d",&ptr->quantity);

                                pf("\nBOOK UPDATED SUCCESSFULLY!\n");
                                return;
                        }

                        ptr=ptr->next;
                }

                pf("\nBOOK NOT FOUND!\n");
        }

        else
        {
                pf("\nINVALID OPTION!\n");
        }
}
