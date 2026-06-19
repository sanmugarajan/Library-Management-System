#include "head.h"
#include <time.h>

void breturn()
{
        int issue_id;

	pf("\n\n\n\n\n\n\n\n\n\n");

        if(ihptr==0)
        {
                pf("\nNO ISSUED BOOK RECORDS FOUND!\n");
                return;
        }

        pf("\nENTER ISSUE ID : ");
        sf("%d",&issue_id);

        iptr=ihptr;

        while(iptr)
        {
                if(iptr->issue_id==issue_id)
                {
                        if(strcmp(iptr->return_date,"NOT_RETURNED!")!=0)
                        {
                                pf("\nBOOK ALREADY RETURNED!\n");
                                return;
                        }

                        ptr=hptr;

                        while(ptr)
                        {
                                if(ptr->book_id==iptr->book_id)
                                {
                                        ptr->quantity++;
                                        break;
                                }

                                ptr=ptr->next;
                        }

			time_t t;
			struct tm *tm_info;

			time(&t);
			tm_info=localtime(&t);

			strftime(iptr->return_date,
		        sizeof(iptr->return_date),
		        "%d-%m-%Y %H:%M:%S",
			tm_info);

                        pf("\nBOOK RETURNED SUCCESSFULLY!\n");

                        return;
                }

                iptr=iptr->next;
        }

        pf("\nISSUE ID NOT FOUND!\n");
}
