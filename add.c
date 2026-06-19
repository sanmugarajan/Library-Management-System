#include "head.h"

void add()
{
        node=(bk *)malloc(sizeof(bk));

	pf("\n\n\n\n\n\n\n\n\n\n\n");

        if(node==NULL)
        {
                pf("\nMEMORY ALLOCATION FAILED!\n");
                return;
        }

	pf("ENTER THE BOOK DETAILS:-\n");
        node->book_id=get_bookid();

        pf("\nBOOK ID : %d\n",node->book_id);

        pf("\nENTER BOOK TITLE : ");
        sf("%s",node->title);

        pf("\nENTER AUTHOR NAME : ");
        sf("%s",node->author);

        pf("\nENTER QUANTITY : ");
        sf("%d",&node->quantity);

        node->next=0;

        if(hptr==0)
                hptr=temp=node;
        else
        {
                temp->next=node;
                temp=node;
        }

        pf("\nBOOK ADDED SUCCESSFULLY!\n");
}

int get_bookid()
{
        int id=1;

        ptr=hptr;

        while(ptr)
        {
                if(ptr->book_id==id)
                        id++;

                ptr=ptr->next;
        }

        return id;
}
