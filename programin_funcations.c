#include"interfaces.h"
#include "configration.h"
#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
/***********************CONSOLE FUNCTION****************************/
void CMD_ColorText (int CodeColor)
{
  HANDLE hc =GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hc,CodeColor);
}
/**********************HelpFull Funcation******************************/
u8 CheckPassword (void)
{
    u8 Trails=Initilization ,FaultFlag=UNCORRECT;
    u32 Password;
    while (FaultFlag==UNCORRECT&&(Trails<SecondTrails))
    {
        CMD_ColorText (White);
        printf("\n\n\n\n\n                              Please Enter The password : ");
        CMD_ColorText (Grean);
        fflush(stdin);scanf("%d",&Password);
        if (Password!=DefualtPass)
        {
            Trails++;
            CMD_ColorText (read);
            printf ("\n                               UNCORRECT  ERROR!!!!!!!!\n");
            printf("                    You Have Also %d Tries Please Enter The Correct one\n\n",(Tries-Trails));

        }
        else
        {
            FaultFlag=CORRECT;
        }

    }

    if ((FaultFlag==UNCORRECT)&&(Trails<ThirdTrails))
    {
        CMD_ColorText (White);
       printf("\n\n\n\n\n                              Please Enter The password : ");
        CMD_ColorText (Grean);
        fflush(stdin);scanf("%d",&Password);
        if (Password!=DefualtPass)
        {
            return UNCORRECT;
        }
    }
    return CORRECT;
}

                /**********************************************************/


u8 Same_Check (u8*String1,u8*String2)
{
    char c=1;

    for(u8 Iteration=Start_Iteration; String1[Iteration]||String2[Iteration]; Iteration++)
    {
        if ((String1[Iteration]>='A')&&(String1[Iteration]<='Z'))
        {
            String1[Iteration]=String1[Iteration]-'A'+'a';
        }


        if (String1[Iteration]!=String2[Iteration])
        {

            return Diffrent ;
        }

    }

    return Same;

}

/**************************************ADMIN MODE Function*********************************/
static Patient PatientInformation[NumberOfPatient];

void Add_Patient (void)
{
    static u8 iteration=Start_Iteration ;
    u32 ID,Flag_Unique=Common;
     system("cls");
     CMD_ColorText (Grean);
            printf("          <Add new patient record Icon>\n\n\n");

CMD_ColorText (White);
    printf("Enter First Two Names Of The Patient:   ");
    fflush(stdin);
    CMD_ColorText (Grean);
    gets(PatientInformation[iteration].Name);
    CMD_ColorText (White);
    printf("\nEnter Patient Age:    ");
    CMD_ColorText (Grean);
    scanf("%d",&PatientInformation[iteration].age);
    CMD_ColorText (White);
    printf("\nEnter Patient Gender ");
    CMD_ColorText (Grean);
    printf( "(Male OR Female)");
    CMD_ColorText (White);
    printf(" :   ");
     CMD_ColorText (Grean);
    scanf("%s",&PatientInformation[iteration].Gender);
    while (Flag_Unique==Common)
    {
        Flag_Unique=Unique;
        CMD_ColorText (White);
        printf("\nEnter Patient ID:   ");
        CMD_ColorText (Grean);
        scanf("%d",&ID);
        for (int Iteration=Start_Iteration; Iteration<NumberOfPatient; Iteration++)
        {
            if (ID==(PatientInformation[Iteration].Id))
            {
                Flag_Unique=Common;
                CMD_ColorText (read);
                printf("\nThis is Id Is Taken Please Enter  Unique ID\n");
                break;
            }
        }
    }
    PatientInformation[iteration++].Id=ID;
    system("cls");
}

              /****************************************************************/


void Edit_Patient(void)
{
    u8 ID,Found_Flag=Not_Found,ID_Index,Select[Select_Size]= {0},Same_Flag=Error_Select;
     system("cls");
      CMD_ColorText (Grean);
            printf("           <Edit patient record Icon>\n\n\n");
    while (Found_Flag==Not_Found)

    {
        CMD_ColorText (White);
        printf("Please Enter Patient ID :");
      CMD_ColorText (Grean);
        scanf ("%d",&ID);

        for (int Iteration=Start_Iteration; Iteration<NumberOfPatient; Iteration++)
        {
            if (ID==PatientInformation[Iteration].Id)
            {
                Found_Flag =Found ;
                ID_Index = Iteration;
                break;
            }
        }
        if (Found_Flag==Not_Found)
        {
             CMD_ColorText (read);
            printf("please Reenter Valid Taken ID For The Patient\n");
        }
    }
    system("cls");
    if (Found_Flag==Found)
    {
        CMD_ColorText (Grean);
        printf("****************************************\n");
         CMD_ColorText (White);
        printf ("\nPatient Name   :           ");
         CMD_ColorText (Grean);
         printf("%s\n",PatientInformation[ID_Index].Name);
         CMD_ColorText (White);
        printf ("Patient Age    :           ");
        CMD_ColorText (Grean);
        printf("%d\n",PatientInformation[ID_Index].age);
        CMD_ColorText (White);
        printf ("Patient Gender :           ");
        CMD_ColorText (Grean);
         printf("%s\n\n\n",PatientInformation[ID_Index].Gender);
         printf("****************************************\n\n");
        while(Same_Flag==Error_Select)
        {
            CMD_ColorText (White);
            printf ("Any Information You Want : ");
            CMD_ColorText (Grean);
            scanf ("%s",Select);
            Same_Flag=Same_Check(Select,"name")+Same_Check(Select,"gender")+Same_Check(Select,"age");
            if (Same_Flag==Error_Select)
            {
                CMD_ColorText (read);

                printf("\n\nPlease Select From Name , Age , Gender only \n\n\n");
            }
        }
        switch (Select[0])
        {
        case 'n':
            CMD_ColorText (White);
            printf("Enter New Name :    ");
            CMD_ColorText (Grean);
            scanf ("%s",PatientInformation[ID_Index].Name);
            break;
        case 'a':
             CMD_ColorText (White);
            printf("Enter New Age :     ");
            CMD_ColorText (Grean);
            scanf ("%d",&PatientInformation[ID_Index].age);
            break;
        case 'g':
            CMD_ColorText (White);
            printf("Enter New Gender :      ");
             CMD_ColorText (Grean);
            scanf ("%s",PatientInformation[ID_Index].Gender);
            break;
        }
    }
    else
    {
         CMD_ColorText (read);
        printf("Incorrect ID Message");
    }
    system("cls");
}
             /******************************************************************/


u8* Reserve_Slot(u8**Slots,u8 SlotsNumber)
{
     system("cls");
    u32 ID,NumberOfSlot,Found_Flag=Not_Found,Rserved_Flag=Reservedd;
    static u8 ReservedSlots[NumberOfSlots]= {Avilable};
    CMD_ColorText (Grean);
            printf("           < Reserve a slot with the doctor Icon >\n\n\n");
    while (Found_Flag==Not_Found)
    {
        CMD_ColorText (White);
        printf("Please Enter Patient ID :   ");
        CMD_ColorText (Grean);
        scanf ("%d",&ID);

        for (int Iteration=Start_Iteration; Iteration<NumberOfPatient; Iteration++)
        {
            if (ID==PatientInformation[Iteration].Id)
            {
                Found_Flag =Found ;
                break;
            }
        }
        if (Found_Flag==Not_Found)
        {
            CMD_ColorText (read);
            printf("\nNOT FOUND ID !!!!!!!!!!! RENTER AVAILABLE ONE PLEASE\n\n");
        }

    }
    system("cls");
    CMD_ColorText (Grean);
        printf("******************************************\n");

    for(u8 Iteration=Start_Iteration; Iteration<SlotsNumber; Iteration++)
    {
        CMD_ColorText (Grean);
        printf("\n(%d)      ",Iteration+1);
        CMD_ColorText (White);
        printf("%s",Slots[Iteration]);

        if (ReservedSlots[Iteration]==Avilable)
        {
            CMD_ColorText (Grean);
            printf ("       available slots");
        }
        else
        {

        CMD_ColorText (read);
            printf("       Reserved Slots");
        }

    }
    CMD_ColorText (Grean);
        printf("\n\n\n******************************************\n\n");

    while(Rserved_Flag==Reservedd )
    {
        CMD_ColorText (White);
     printf("choose Number of Slot patient want to reserve :    ");
     CMD_ColorText (Grean);
    scanf("%d",&NumberOfSlot);
    Rserved_Flag=Avilable;

    if (ReservedSlots [NumberOfSlot-1]==Reservedd)
    {
        CMD_ColorText (read);
        printf("This Slots IS Reserved Please Choose another Availble one \n");
        Rserved_Flag=Reservedd;
    }
    }
    for(u8 Iteration=Start_Iteration; Iteration<SlotsNumber; Iteration++)
    {
        if(ID==PatientInformation[Iteration].Id)
        {
            PatientInformation[Iteration].IndexOfSlotsList=NumberOfSlot-1;
            ReservedSlots [NumberOfSlot-1]=Reservedd;
        }
    }
    system("cls");

return ReservedSlots;
}


               /**************************************************/


void Cancel_Reservation(u8*ReservedSlots)
{
    u8 Found_Flag=Not_Found,ReservedSlots_Index;
    u32 ID;
     system("cls");
      CMD_ColorText (Grean);
            printf("          < Cancel reservation Icon >");

     while (Found_Flag==Not_Found)
    {
        CMD_ColorText (White);
        printf("Please Enter Patient ID :    ");
        CMD_ColorText (Grean);
        scanf ("%d",&ID);

        for (int Iteration=Start_Iteration; Iteration<NumberOfPatient; Iteration++)
        {
            if (ID==PatientInformation[Iteration].Id)
            {
                Found_Flag =Found ;
                ReservedSlots_Index=Iteration;
                break;
            }
        }
        CMD_ColorText (read);
            printf("\nNOT FOUND ID !!!!!!!!!!! RENTER AVAILABLE ONE PLEASE\n\n");

    }
    ReservedSlots[ReservedSlots_Index]=Avilable;
}

 /*************************************USER FUNCATION************************************/
void View_patient_Record(u8** Slots)
{
    u32 ID,Back_Flag;
    u8 Found_Flag=Not_Found,ID_Index;
    system("cls");
    printf ("                      <View patient Record Icon > \n\n");
   while (Found_Flag==Not_Found)

    {
        CMD_ColorText (White);
        printf("Please Enter Ur ID :  ");
      CMD_ColorText (Grean);
        scanf ("%d",&ID);

        for (int Iteration=Start_Iteration; Iteration<NumberOfPatient; Iteration++)
        {
            if (ID==PatientInformation[Iteration].Id)
            {
                Found_Flag =Found ;
                ID_Index = Iteration;
                break;
            }
        }
        if (Found_Flag==Not_Found)
        {
             CMD_ColorText (read);
            printf("please Reenter Valid Taken ID For The Patient\n");
        }
    }
    CMD_ColorText (Grean);
        printf("****************************************\n");
         CMD_ColorText (White);
        printf ("\nPatient Name   :           ");
         CMD_ColorText (Grean);
         printf("%s\n",PatientInformation[ID_Index].Name);
         CMD_ColorText (White);
        printf ("Patient Age    :           ");
        CMD_ColorText (Grean);
        printf("%d\n",PatientInformation[ID_Index].age);
        CMD_ColorText (White);
        printf ("Patient Gender :           ");
        CMD_ColorText (Grean);
         printf("%s\n",PatientInformation[ID_Index].Gender);
         CMD_ColorText (blue);
         printf("Reserved slot ----------->  ");
         printf("%s\n",Slots[PatientInformation[ID_Index].IndexOfSlotsList]);
         CMD_ColorText (Grean);
         printf("****************************************\n");
          Back_Flag=continuee;
        while (Back_Flag==continuee)
        {
        CMD_ColorText (read);
        printf("\n                To Back Enter 0 \n\n");
        CMD_ColorText (Grean);
        printf("****************************************\n\n");
        fflush(stdin);
        scanf("%d",&Back_Flag);
        fflush(stdin);
        if (Back_Flag!=Back)
        {
            Back_Flag=continuee;
        }
        }
        system("cls");
}


                    /******************************************************/


void View_today_reservations (u8** Slots,u8 SlotsNumber,u8*ReservedSlots)
{
    u32 Index,Back_Flag;
    system("cls");
    CMD_ColorText (Grean);
        printf("*******************************************************************************************\n");
        CMD_ColorText (White);
        printf("Slot Num        slots               states           Patient ID           Patient Name\n");

    for(u8 Iteration=Start_Iteration; Iteration<SlotsNumber; Iteration++)
    {
        CMD_ColorText (Grean);
        printf("\n  (%d)      ",Iteration+1);
        CMD_ColorText (White);
        printf("%s",Slots[Iteration]);

        if (ReservedSlots[Iteration]==Avilable)
        {
            CMD_ColorText (Grean);
            printf ("       available slots");
            CMD_ColorText (White);
            printf ("       ----------           ------------");
        }
        else if (ReservedSlots[Iteration]==Reservedd)
        {

        CMD_ColorText (read);
            printf("       Reserved Slots");
            Index=Start_Iteration;
            for (Index=Start_Iteration;PatientInformation[Index].IndexOfSlotsList!=Iteration;Index);
            CMD_ColorText (Grean);
            printf ("            %d                  %s",PatientInformation[Index].Id,PatientInformation[Index].Name);

        }
        else
            {
            CMD_ColorText (Grean);
            printf ("       available slots");
            CMD_ColorText (White);
            printf ("       ----------           ------------");
            }


    }
    CMD_ColorText (Grean);

        printf("\n\n\n******************************************************************************************\n");
        Back_Flag=continuee;
        while (Back_Flag==continuee)
        {
        CMD_ColorText (read);
        printf("\n                               To Back Enter 0 \n");
        CMD_ColorText (Grean);
        printf("\n******************************************************************************************\n");
        fflush(stdin);
        scanf("%d",&Back_Flag);
        fflush(stdin);
        if (Back_Flag!=Back)
        {
            Back_Flag=continuee;
        }
        }
        system("cls");




}





