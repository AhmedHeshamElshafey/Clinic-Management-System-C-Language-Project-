# 👨‍⚕️ Clinic Management System C Language Project 
## 🩺 Overview :
A simple terminal-based Clinic Management System written in C, offering two main modes:

#### . 👨‍⚕️ Admin Mode: Add/edit patients, reserve or cancel appointment slots.

#### . 🧑‍💻 User Mode: View patient records and today’s reservations.

#### This project demonstrates strong fundamentals in:

- Structuring C programs

- Working with pointers and arrays

- Command-line interface design

- System calls (e.g., system("cls"))

- State machines and mode switching

## 📽️ Demos:

#### ✅ Full Start Menu Demo
```
*********************************************
****       Welcome to our Clinic        *****
*********************************************

            ******************
            * Choose Ur Mood *
            ******************

*********************************************
********** (1) -> Admin Mode   **********
********** (2) -> User Mode    **********
*********************************************

Please Choose The Number of The Mood :

```
#### 🔐 Admin Mode Menu
```
*********************************************
**** (1) Add new patient record      *************

**** (2) Edit patient record         ****************

**** (3) Reserve a slot with doctor  *****

**** (4) Cancel reservation          *****************

*********************************************

          To Return  Press 0

*********************************************

Choose Number Of Option You want :
```
#### 👥 User Mode Menu
```
*********************************************
**** (1) View patient Record        ****************

**** (2) View today reservations    ***********

*********************************************

          To Return  Press 0

*********************************************

Choose Number Of Option You want :
```
#### 📅 Reservation Slots Display
```
Available Slots:
[0] 2pm to 2:30pm
[1] 2:30pm to 3pm
[2] 3pm to 3:30pm
[3] 4pm to 4:30pm
[4] 4:30pm to 5pm

Choose a slot number to reserve:
```
#### ⚠️ Error Example
```
ERRORR!!!!
Please Choose 1 OR 2 Only
```
## ⚙️ Features:
### 🔐 Admin Mode
- ✅ Add new patient records

- 📝 Edit patient information

- 📅 Reserve appointment slots

- ❌ Cancel existing reservations

### 👤 User Mode
-  🔍 View a specific patient’s record

- 📋 Display today’s reservations

### 🧠 Technologies Used:

```
Tool/IDE               Purpose
Code::Blocks           Development & debugging
Windows Console        Terminal output and UI
```

### 📁 File Structure:
📦 ClinicSystem/ <br>
 ┣ 📄 main.c <br>
 ┣ 📄 std_types.h <br>
 ┣ 📄 configuration.h <br>
 ┣ 📄 interfaces.h <br>
 ┗ 📄 README.md <br>

### 🔒 Admin Access:
- To simulate login security, the Admin Mode checks for a correct password before access is granted.

### 🎨 Console Color Functions:
Using CMD_ColorText(Color) to give CLI output rich formatting and better UX:
- **Green**:  for titles & borders
- **White**:  for options
- **Red**  :  for errors

### 📌 Slot Management:
```
u8* Slots[NumberOfSlots] = {
  "2pm to 2:30pm",
  "2:30pm to 3pm",
  "3pm to 3:30pm",
  "4pm to 4:30pm",
  "4:30pm to 5pm"
};
```
- Efficient slot selection and reservation through a well-structured array of strings.

## 👨‍🎓 Author
**Ahmed Hesham Abdelhamed** <br>
🚀 Passionate about Embedded Systems, RTOS, and AUTOSAR.<br>

## 🏷️ Tags
**C** , **Clinic Management** , **Admin System** , **Embedded Friendly** , **Code::Blocks** 
