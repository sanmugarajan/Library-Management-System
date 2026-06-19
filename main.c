#include "head.h"

bk *node,*temp,*ptr,*prev,*hptr=0;
is *inode,*itemp,*iptr,*ihptr=0;

int main()
{
        load_data();

menu:
        system("clear");

        pf("\n\n\n");
        pf("\t\t\t|--------------------------------------|\n");
        pf("\t\t\t|                                      |\n");
        pf("\t\t\t|   *** LIBRARY MANAGEMENT SYSTEM ***  |\n");
        pf("\t\t\t|                                      |\n");
        pf("\t\t\t|        1. ADD NEW BOOK               |\n");
        pf("\t\t\t|        2. UPDATE BOOK DETAILS        |\n");
        pf("\t\t\t|        3. REMOVE BOOK                |\n");
        pf("\t\t\t|        4. SEARCH BOOK                |\n");
        pf("\t\t\t|        5. VIEW ALL BOOKS             |\n");
        pf("\t\t\t|        6. ISSUE BOOK                 |\n");
        pf("\t\t\t|        7. RETURN BOOK                |\n");
        pf("\t\t\t|        8. LIST ISSUED BOOKS          |\n");
        pf("\t\t\t|        9. SAVE                       |\n");
        pf("\t\t\t|        10. EXIT                      |\n");
        pf("\t\t\t|                                      |\n");
        pf("\t\t\t|--------------------------------------|\n");

        int op;

        pf("\nENTER YOUR CHOICE : ");
        sf("%d",&op);

        switch(op)
        {
                case 1:
			system("clear");
                        add();
        		sleep(1);
                        break;

                case 2:
			system("clear");
                        update();
			printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 3:
			system("clear");
                        bremove();
                        printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 4:
			system("clear");
                        search();
			printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 5:
			system("clear");
                        view();
			printf("\nPress Enter to return to menu...");
			getchar();
			getchar();
                        break;

                case 6:
			system("clear");
                        issue();
			printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 7:
			system("clear");
                        breturn();
			printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 8:
			system("clear");
                        list();
			printf("\nPress Enter to return to menu...");
                        getchar();
                        getchar();
                        break;

                case 9:
                        save();
			sleep(1);
                        break;

                case 10:
                        save();
                        bexit();
                        break;

                default:
                        pf("\nINVALID OPTION\n");
        }

	system("clear");
        goto menu;
}
