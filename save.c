#include "head.h"

void save()
{
        FILE *fp;

        fp=fopen("books.csv","w");

        if(fp==NULL)
        {
                pf("\nBOOK FILE OPEN FAILED!\n");
                return;
        }

        fprintf(fp,"BOOK_ID,TITLE,AUTHOR,QUANTITY\n");

        ptr=hptr;

        while(ptr)
        {
                fprintf(fp,"%d,%s,%s,%d\n",
                        ptr->book_id,
                        ptr->title,
                        ptr->author,
                        ptr->quantity);

                ptr=ptr->next;
        }

        fclose(fp);

        fp=fopen("issued_books.csv","w");

        if(fp==NULL)
        {
                pf("\nISSUE FILE OPEN FAILED!\n");
                return;
        }

        fprintf(fp,
        "ISSUE_ID,BOOK_ID,USER_ID,USER_NAME,ISSUE_DATE,DUE_DATE,RETURN_DATE\n");

        iptr=ihptr;

        while(iptr)
        {
                fprintf(fp,"%d,%d,%d,%s,%s,%s,%s\n",
                        iptr->issue_id,
                        iptr->book_id,
                        iptr->user_id,
                        iptr->user_name,
                        iptr->issue_date,
                        iptr->due_date,
                        iptr->return_date);

                iptr=iptr->next;
        }

        fclose(fp);

        pf("\nDATA SAVED SUCCESSFULLY!\n");
}

void load_data()
{
        FILE *fp;
        char buf[200];

        fp=fopen("books.csv","r");

        if(fp==NULL)
                return;

        fgets(buf,sizeof(buf),fp);

        while(1)
        {
                node=(bk *)malloc(sizeof(bk));

                if(fscanf(fp,"%d,%49[^,],%49[^,],%d\n",
                        &node->book_id,
                        node->title,
                        node->author,
                        &node->quantity)!=4)
                {
                        free(node);
                        break;
                }

                node->next=0;

                if(hptr==0)
                        hptr=temp=node;
                else
                {
                        temp->next=node;
                        temp=node;
                }
        }

        fclose(fp);
}
