#include "head.h"

void list()
{
        iptr=ihptr;

        pf("\n\n\n\n\n\n\n\n\n");

        if(ihptr==0)
        {
                pf("\nNO ISSUED BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\t+----------+----------+----------+----------------+---------------------+---------------------+\n");
        pf("\t|ISSUE ID  |BOOK ID   |USER ID   |USER NAME       |ISSUE DATE           |RETURN DATE          |\n");
        pf("\t+----------+----------+----------+----------------+---------------------+---------------------+\n");

        while(iptr)
        {
                pf("\t|%-10d|%-10d|%-10d|%-16s|%-21s|%-21s|\n",
                        iptr->issue_id,
                        iptr->book_id,
                        iptr->user_id,
                        iptr->user_name,
                        iptr->issue_date,
                        iptr->return_date);

                iptr=iptr->next;
        }

        pf("\t+----------+----------+----------+----------------+---------------------+---------------------+\n\n");
}
