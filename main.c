#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

typedef struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    struct Patient* next;  // porer patient input
} Patient;

typedef struct Doctor {
    int id;
    char name[50];
    char specialty[50];
    int availableSlots;   // doctor er koyta avaiableslots ase
    struct Doctor* next;  // porer doctor er pointer
} Doctor;

Patient* patientHead = NULL;
Doctor* doctorHead = NULL;
void menu();
void login();
void returnlanding();

void slowTxt(char* str) {
    system("CLS");
    printf("\n\n");
    printf("\t=============================================\n");
    Sleep(20);
    printf("\n\t    Student Information Management System\n\n");
    Sleep(20);
    printf("\t=============================================\n");
    Sleep(20);
    printf("\n\n\t");
    int x = strlen(str);
    for (int i = 0; i < x; i++) {
        printf("%c", str[i]);
        Sleep(20);
    }
    printf("\n\n");
}

void addPatient(int id, const char* name, int age, const char* gender, const char* disease) {  // patient add er function
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->gender, gender);
    strcpy(newPatient->disease, disease);
    newPatient->next = NULL;

    if (patientHead == NULL) {
        patientHead = newPatient;
    } else {
        Patient* temp = patientHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
}

void addDoctor(int id, const char* name, const char* specialty, int availableSlots) {  // doctor er function
    Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
    newDoctor->id = id;
    strcpy(newDoctor->name, name);
    strcpy(newDoctor->specialty, specialty);
    newDoctor->availableSlots = availableSlots;
    newDoctor->next = NULL;

    if (doctorHead == NULL) {
        doctorHead = newDoctor;
    } else {
        Doctor* temp = doctorHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDoctor;
    }
}

void displayPatients() {
    Patient* temp = patientHead;
    char ar[] = "Patient List:";
    printf("\t");
    for (int i = 0; i < sizeof(ar) - 1; i++) {
        Sleep(25);
        printf("%c", ar[i]);
    }
    printf("\n");
    while (temp != NULL) {
        printf("\t\tID: %d, Name: %s, Age: %d, Gender: %s, Disease: %s\n", temp->id, temp->name, temp->age, temp->gender, temp->disease);
        temp = temp->next;
    }
    printf("\n");
}

void displayDoctors() {
    Doctor* temp = doctorHead;
    char ar[] = "Doctor List:";
    printf("\t");
    for (int i = 0; i < sizeof(ar) - 1; i++) {
        Sleep(25);
        printf("%c", ar[i]);
    }
    printf("\n");
    while (temp != NULL) {
        printf("\t\tID: %d, Name: %s, Specialty: %s, Available Slots: %d\n", temp->id, temp->name, temp->specialty, temp->availableSlots);
        temp = temp->next;
    }
    printf("\n");
}

void firstinterface() {
    char ab[] = "||||||||||||||||||||||||||||||||||||";
    char ar[] = "||||   Welcome to our project   ||||";
    printf("\n\n\t%s\n", ab);
    printf("\t");
    for (int i = 0; i < sizeof(ar) - 1; i++) {
        Sleep(25);
        printf("\033[1m%c", ar[i]);
    }
    printf("\033[0m\n");
    printf("\t%s\n", ab);
    printf("\n\n");
}

void inputPatientData() {
    int id, age;
    char name[50], gender[10], disease[50];
    char s[] = "You wanted to add a new Patient. \n\tPlease enter his/her detailed information";
    slowTxt(s);

    printf("\t=============================================\n");
    printf("\n");
    printf("\tEnter Patient ID: ");
    scanf("%d", &id);

    printf("\tEnter Patient Name: ");
    scanf(" %[^\n]s", name);  // Using " %[^\n]s" to read a full line with spaces

    printf("\tEnter Patient Age: ");
    scanf("%d", &age);

    printf("\tEnter Patient Gender: ");
    scanf(" %[^\n]s", gender);

    printf("\tEnter Patient Disease: ");
    scanf(" %[^\n]s", disease);

    addPatient(id, name, age, gender, disease);  // Call the addPatient function
    printf("\tPatient details added successfully!\n\n");
    printf("\t=============================================\n");
}

void admin() {
    login();
}

int main() {
    system("cls");
    // firstinterface();
    admin();
    system("cls");
    // Sleep(5000);
    // system("color 0C");
    // system("cls");
    return 0;
}

void menu() {
    int choice;
    printf("\n\n");
    printf("\t=============================================\n");
    printf("\n");
    printf("\t[1] Add New Patient\n");
    printf("\t[2] Display Patients\n");
    printf("\t[3] Return to Home\n");
    printf("\t[4] Exit\n\n");
    printf("\t=============================================\n\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            inputPatientData();
            break;
        case 2:
            displayPatients();
            break;
        case 3:
            login();
            break;
        case 4:
            printf("Exiting...\n");
            return;
        default:
            printf("\tInvalid choice! Please try again.\n");
    }
    returnlanding();
}

void login() {
    int j;
    printf("\n\n\t\t\t1. Admin Login\n\n");
    printf("\t\t\t2. User Login\n\n");

    int x;
    printf("Enter Your Choice :");
    scanf("%d", &x);
    if (x == 1) {
        int pass = 1234, pas;

        printf(" \n                       Username       : Admin");

        printf(" \n                       ENTER PASSWORD : ");

        scanf("%d", &pas);

        if (pass == pas) {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
            system("cls");
            // system("color 8f");
            printf("\n\n\n\n\n\n");
            printf("                                                           \n");
            printf("                                                           \n");
            printf("                      \t  Please Wait...\n\n\n\n\n");
            printf("                     ______________ _____________               \n");
            printf("                    /                             \\          \n");
            printf("                   |     Loading.............      |           \n");
            printf("\t\t   |\t");
            for (j = 0; j < 24; j++) {
                printf("%c", 219);
                Sleep(50);
            }
            printf("   |\n                    \\______________ ______________/           \n");
            printf("                                                           \n");
            printf("\n\n\n");
            // system("pause");
            Sleep(1000);
            system("cls");
            system("color 0f");
            menu();
        } else {
            printf("Invalid Password !\n\n");
            Sleep(40);
            login();
        }
    }

    // if (x == 2) {
    //     system("CLS");
    //     FILE* ptr;
    //     int test = 0;
    //     int choice;
    //     char tmpUserName[200];
    //     char tmpPassword[200];

    //     char name[200], id[200];

    //     int x1 = 0;
    //     while (x1 == 0) {
    //         printf(" \n                       Username       : ");
    //         scanf("%s", &name);

    //         ptr = fopen("record.dat", "r");

    //         printf(" \n                       ENTER PASSWORD : ");
    //         scanf("%s", check.hostel_id);
    //         while (fscanf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
    //             if (strcmp(add.hostel_id, check.hostel_id) == 0) {
    //                 test = 1;

    //                 // printf("\nhostel_id:%s\nName: %s", add.hostel_id, add.name);
    //                 strcpy(tmpUserName, add.name);
    //                 strcpy(tmpPassword, add.hostel_id);
    //                 // printf("%s", tmpUserName);
    //             }
    //         }
    //         // printf("%d", test);

    //         if (test == 1 && strcmp(tmpUserName, name) == 0) {
    //             reg_user();
    //             x1 = 1;
    //         } else {
    //             printf("%s", "Invalid username or password!");
    //         }
    //     }

    //     // scanf("%s", &id);

    //     // reg_user();
    // }
}

void returnlanding() {
    printf("\n\tTo return Home[H]\n\tTo return to Main Menu[M]\n\tTo Close the Programme[0]\n\tEnter your choice: ");
    char x;
    scanf(" %c", &x);
    if (x == '0') {
        return;
    } else if (x == 'M' || x == 'm') {
        menu();
        return;
    } else {
        login();
        return;
    }
}