#ifndef  interfaces
#define  interfaces
#include "std_types.h"
/*******************************ColorCode*******************************************/
#define Grean       0x02
#define blue         0x3
#define read        0x4
#define White       0x07
/***********************************************************************************/
#define Initilization   0
#define SecondTrails    2
#define ThirdTrails     3
#define UNCORRECT       1
#define CORRECT         0
#define NameSize        50
#define GenderSize      10
#define IDsize          5
#define Unique          1
#define Common          0
#define Start_Iteration 0
#define Not_Found       0
#define Found           1
#define Select_Size     10
#define Diffrent        1
#define Same            0
#define Error_Select    3
#define Reservedd       1
#define Avilable        0
#define continuee       1
#define Back            0
/********************************patient data***************************************/
typedef struct{
    u8 Name[NameSize];
    u32 age;
    u8 Gender[GenderSize];
    u32 Id ;
    u32 IndexOfSlotsList ;
} Patient ;
/*********************************FUNCATIONS****************************************/
void CMD_ColorText (int CodeColor);
u8 CheckPassword (void);
void Add_Patient (void);
void Edit_Patient(void);
u8 Same_Check (u8*String1,u8*String2);
u8* Reserve_Slot(u8**Slots,u8 SlotsNumber);
void Cancel_Reservation(u8*ReservedSlots);
void View_patient_Record(u8** Slots);
void View_today_reservations (u8** Slots,u8 SlotsNumber,u8*ReservedSlots);
#endif // interfaces
