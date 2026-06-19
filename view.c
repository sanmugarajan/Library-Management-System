#include "head.h"

void view()
{
        ptr=hptr;

        pf("\n\n\n\n\n\n\n\n\n");
        if(hptr==0)
        {
                pf("\nNO BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\t+--------+----------------------+----------------------+----------+\n");
        pf("\t|BOOK ID |TITLE                 |AUTHOR                |QUANTITY  |\n");
        pf("\t+--------+----------------------+----------------------+----------+\n");

        while(ptr)
        {
                pf("\t|%-8d|%-22s|%-22s|%-10d|\n",
                        ptr->book_id,
                        ptr->title,
                        ptr->author,
                        ptr->quantity);

                ptr=ptr->next;
        }

        pf("\t+--------+----------------------+----------------------+----------+\n");
}
