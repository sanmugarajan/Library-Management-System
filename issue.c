#include "head.h"
#include <time.h>
int get_issueid()
{
        static int id=1;

        return id++;
}

void issue()
{
        int id;

	pf("\n\n\n\n\n\n\n\n\n\n");

        if(hptr==0)
        {
                pf("\nNO BOOKS AVAILABLE!\n");
                return;
        }

        pf("\nENTER BOOK ID : ");
        sf("%d",&id);

        ptr=hptr;

        while(ptr)
        {
                if(ptr->book_id==id)
                {
                        if(ptr->quantity<=0)
                        {
                                pf("\nBOOK NOT AVAILABLE!\n");
                                return;
                        }

                        inode=(is *)malloc(sizeof(is));

                        if(inode==0)
                        {
                                pf("\nMEMORY ALLOCATION FAILED!\n");
                                return;
                        }

                        inode->issue_id=get_issueid();

                        inode->book_id=ptr->book_id;

                        pf("\nENTER USER ID : ");
                        sf("%d",&inode->user_id);

                        pf("\nENTER USER NAME : ");
                        sf("%s",inode->user_name);

			time_t t;
			struct tm *tm_info;

			time(&t);
			tm_info=localtime(&t);

			strftime(inode->issue_date,
         		sizeof(inode->issue_date),
         		"%d-%m-%Y %H:%M:%S",
         		tm_info);

			strcpy(inode->due_date,"NA");

			strcpy(inode->return_date,"NOT_RETURNED!");
                        inode->next=0;

                        if(ihptr==0)
                                ihptr=itemp=inode;
                        else
                        {
                                itemp->next=inode;
                                itemp=inode;
                        }

                        ptr->quantity--;

                        pf("\nBOOK ISSUED SUCCESSFULLY!\n");

                        return;
                }

                ptr=ptr->next;
        }

        pf("\nBOOK ID NOT FOUND!\n");
}
