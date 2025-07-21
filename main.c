#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "configration.h"
#include "interfaces.h"
#include<windows.h>
int main()
{
    u8 Mood,Check,Option,Correct_Flag=UNCORRECT,choose,User_Correct_Flag=UNCORRECT;
    u8*Slots[NumberOfSlots]= {"2pm to 2:30pm","2:30pm to 3pm","3pm to 3:30pm","4pm to 4:30pm","4:30pm to 5pm"};
    u8*ReservedSlots;
    while (1)
    {
        CMD_ColorText (Grean);
        printf("*********************************************\n");
        printf ("****       Welcome to our Clinc        *****\n");
        printf("*********************************************\n\n");
        CMD_ColorText (Grean);
        printf("            ******************\n");
         printf("            *");
        printf(" Choose Ur Mood ");
        CMD_ColorText (Grean);
        printf("*\n");
         printf("            ******************\n");
        CMD_ColorText (Grean);
        printf("\n\n*********************************************\n");
        printf("**********");
        CMD_ColorText (blue);
        printf(" (1)") ;
        CMD_ColorText (White);
        printf(" ------> Admin Mode");
        CMD_ColorText (Grean);
        printf("  **********\n");
        printf("**********");
        CMD_ColorText (blue);
        printf(" (2)") ;
        CMD_ColorText (White);
        printf(" ------> User Mode ");
        CMD_ColorText (Grean);
        printf("  **********\n");
        CMD_ColorText (Grean);
        printf("*********************************************\n\n\n");
        CMD_ColorText (White);


        printf ("Please Choose The Number of The Mood : ");
        CMD_ColorText (Grean);
        fflush(stdin);
        scanf("%c",&Mood);
        system("cls");
        if ( Mood == '1')
        {
            /**********Admin Mode**********/
            Check=CheckPassword();
            if (Check==UNCORRECT)
            {
                break;
            }
            system("cls");
            CMD_ColorText (Grean);
            Correct_Flag=UNCORRECT;
            while ( Correct_Flag==UNCORRECT)
            {
                printf("*********************************************\n");
                printf("**** ");
                CMD_ColorText (White);
                printf("(1) Add new patient record");
                CMD_ColorText (Grean);
                printf(" *************\n\n");
                printf("**** ");
                CMD_ColorText (White);
                printf("(2) Edit patient record");
                CMD_ColorText (Grean);
                printf(" ****************\n\n");
                printf("**** ");
                CMD_ColorText (White);
                printf("(3) Reserve a slot with the doctor");
                CMD_ColorText (Grean);
                printf(" *****\n\n");
                printf("**** ");
                CMD_ColorText (White);
                printf("(4) Cancel reservation");
                CMD_ColorText (Grean);
                printf(" *****************\n\n");
                printf("*********************************************\n\n");
                CMD_ColorText (read);
                printf("          To Return  Press 0 \n");
                CMD_ColorText (Grean);
                printf("\n*********************************************\n\n");
                CMD_ColorText (White);
                printf("Choose Number Of Option You want :   ");
                CMD_ColorText (Grean);
                fflush(stdin);
                scanf("%c",&Option);

                switch (Option)
                {
                case '0' :
                    Correct_Flag=CORRECT ;
                    system("cls");       ;
                    break;
                case '1' :
                    Add_Patient()                                    ;
                    break;
                case '2' :
                    Edit_Patient()                                   ;
                    break;
                case '3' :
                    ReservedSlots=Reserve_Slot (Slots,NumberOfSlots) ;
                    break;
                case '4' :
                    Cancel_Reservation(ReservedSlots)                ;
                    break;
                default  :
                    system("cls");
                    Correct_Flag=UNCORRECT;
                    fflush(stdin);
                    CMD_ColorText (read);
                    printf("           Errorr!!!\n");
                    printf("Please Enter Only From 1 to 4 \n");
                    CMD_ColorText (Grean);

                }
            }




        }
        else if (Mood == '2')
        {
            /**********User Mode**********/

            User_Correct_Flag=UNCORRECT;
            system("cls");
            while (User_Correct_Flag==UNCORRECT)
            {
            CMD_ColorText (Grean);
            printf("*********************************************\n");
            printf("**** ");
            CMD_ColorText (White);
            printf("(1) View patient Record");
            CMD_ColorText (Grean);
            printf(" ****************\n\n");
            printf("**** ");
            CMD_ColorText (White);
            printf("(2) View today  reservations");
            CMD_ColorText (Grean);
            printf(" ***********\n\n");
            printf("*********************************************\n\n");
                CMD_ColorText (read);
                printf("          To Return  Press 0 \n");
                CMD_ColorText (Grean);
                printf("\n*********************************************\n\n");
            CMD_ColorText (White);
            printf("Choose Number Of Option You want :   ");
            CMD_ColorText (Grean);
             fflush(stdin);scanf("%c",&choose);

            switch (choose)
            {
                case '0': User_Correct_Flag=CORRECT; system("cls"); break;
                case '1': View_patient_Record (Slots); break;
                case '2': View_today_reservations (Slots,NumberOfSlots,ReservedSlots); break;
                default :
                    system("cls");
                    CMD_ColorText (read);
                    printf("\n           ERRORR!!!!\n");
                    printf("    Please Choose 1 OR 2 Only\n\n");
            }
            }


        }
    }
    return 0;
}



