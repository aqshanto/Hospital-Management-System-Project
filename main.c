#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int i, j, main_exit;
void welcome_message();
void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void closer();
void PP();

void reg_user();
void search();
void rules();
void food_menu();
void maintenance();
void maintenance_view();
void u_see();

struct date {
    int month, day, year;
};
struct
{
    char name[120];
    int age;
    char city[120];
    char mail_id[60];
    char room_no[8];
    char father_name[60];
    int father_phone_no[11];
    int phone_no[11];
    char hostel_name[6];
    char hostel_id[10];
    struct date dob;
    int rent_paid;
} add, upd, check, rem, sort;

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    // while (goal > clock());
}

void pass(void) {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    system("cls");
    system("color 0f");
    int i1, j, l, l1;
    char name[50] = "\n\n\n\n\t\t\t  WELCOME TO OUR PROJECT\n\n";
    printf("\t\n");
    for (i1 = 0; i1 < 50; i1++) {
        printf("%c", name[i1]);
        delay(60);
    }

    delay(1000);
    printf("\n\n");
    system("CLS");
    system("color 1f");
    printf("\n\n\n");

    printf("\n");
    system("pause");
    system("CLS");
    system("color 0f");
    printf("\n\n\n\n\n\n");
    welcome_message();
    printf("\n");
    char nam[] = "\n\n Residential Hall Management System   \n";
    printf("\t\n");
    for (l = 0; l < 40; l++) {
        printf("%c", nam[l]);
        delay(40);
    }
}

int main() {
    system("color 0c");
    pass();
    PP();
    return 0;
}

void welcome_message() {
    printf("\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\xB2                                                          \xB2\n");
    printf("\t\t\t\xB2      Welcome to Residential Hall Management System       \xB2\n");
    printf("\t\t\t\xB2                                                          \xB2\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n");
}
void menu() {
    system("cls");
    int choice;
    system("color 07");
    printf("\n\n\t\t\t\tRESIDENTIAL HALL MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [1] Enter new Student  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [2] Update student information  \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [3] Check student details       \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [4] View all Students           \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [5] Remove existing Student     \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [6] View all students list   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  [7] View request maintenance    \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n \t\t Today is: ");
    tm();  // time call
    printf("\n\t\t Please Enter Your Choice(0 to exit): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls");
            system("color 0f");
            new_entry();
            break;
        case 2:
            system("cls");
            system("color 0f");
            edit();
            break;
        case 3:
            see();
            break;
        case 4:
            sorter();
            break;
        case 5:
            erase();
            break;
        case 6:
            view_list();
            break;
        case 7:
            maintenance_view();
            break;

        case 0:
            closer();
        default:
            printf("Wrong Choice! \a");
            delay(100);
            menu();
    }
}

int tm() {
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
    return 0;
}
void sorter() {
    system("CLS");
    int test = 0;

    FILE *fp, *hostel;

    hostel = fopen("record.dat", "r");
    printf("\n\tHOSTEL ID.\t     NAME\t   ROOM NO.\n");

    while (fscanf(hostel, "%s\n", check.hostel_id) != EOF) {
        fp = fopen("record.dat", "r");
        while (fscanf(fp, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", sort.hostel_id, sort.name, &sort.dob.month, &sort.dob.day, &sort.dob.year, &sort.age, sort.city, &sort.phone_no, sort.mail_id, sort.father_name, &sort.father_phone_no, sort.room_no, sort.hostel_name, &sort.rent_paid) != EOF) {
            if (strcmp(check.hostel_id, sort.hostel_id) == 0) {
                printf("\n\t%8s\t   %8s\t   %s", sort.hostel_id, sort.name, sort.room_no);
                test++;
            }
        }
    }
    fclose(fp);
    if (test == 0)
        printf("\nNO RECORDS!!\n");
sort_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        closer();
    else {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }
}
void new_entry() {
    system("CLS");
    int choice;
    FILE *ptr, *hostel;
    ptr = fopen("record.dat", "a+");
hostel_id:
    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your hostel_id:");
    scanf("%s", check.hostel_id);
    while (fscanf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        if (strcmp(check.hostel_id, add.hostel_id) == 0) {
            printf("Students hostel_id already in use!");
            goto hostel_id;
        }
    }
    strcpy(add.hostel_id, check.hostel_id);
    printf("\nEnter the name:");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the city:");
    scanf("%s", add.city);
    printf("\nEnter the phone number:");
    scanf("%s", &add.phone_no);
    printf("\n Enter your email id :");
    scanf("%s", add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s", add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%s", &add.father_phone_no);
    printf("\n --------------------------Each Hostel has 100 rooms------------------------!!!!");
    printf("\n Enter your room no.:");
    scanf("%s", add.room_no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s", add.hostel_name);
    printf("\n Total rent is:5000");
    printf("\n Amount of rent paid: ");
    scanf("%d", &add.rent_paid);
    fprintf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
    if (strcmp(add.hostel_name, "BH-1") == 0) {
        hostel = fopen("BH-1.dat", "a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    } else if (strcmp(add.hostel_name, "BH-2") == 0) {
        hostel = fopen("BH-2.dat", "[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    } else if (strcmp(add.hostel_name, "BH-3") == 0) {
        hostel = fopen("BH-3.dat", "a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    } else if (strcmp(add.hostel_name, "GH-1") == 0) {
        hostel = fopen("GH-1.dat", "[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
    }
    fclose(ptr);
    printf("\nStudent added successfully!");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        closer();
    else {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}
void view_list() {
    system("CLS");
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    printf("\nHOSTEL_ID\tNAME\t\t\tCity\t\t\tRENT PAID\t\t\tROOM ALLOTED\n");
    while (fscanf(view, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        printf("\n%8s\t %10s\t\t\t %10s\t\t %d\t\t\t %s", add.hostel_id, add.name, add.city, add.rent_paid, add.room_no);
        test++;
    }
    fclose(view);
    if (test == 0) {
        printf("\nNO RECORDS!!\n");
    }
view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 0)
        closer();
    else {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}
void u_see() {
    system("CLS");
    FILE *ptr;
    int test = 0;
    int choice;
    ptr = fopen("record.dat", "r");

    printf("\n\nEnter the hostel id:");
    scanf("%s", check.hostel_id);
    while (fscanf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        if (strcmp(add.hostel_id, check.hostel_id) == 0) {
            test = 1;
            printf("\nhostel_id:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%s \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%s \nRoom No:%s \nHostel:%s \nAdd.rent_paid :%d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);

            // printf("\nhostel_id:%s\nName: %s", add.hostel_id, add.name);
        }
    }
}
void see() {
    system("CLS");
    FILE *ptr;
    int test = 0;
    int choice;
    ptr = fopen("record.dat", "r");

    printf("\n\nEnter the hostel id:");
    scanf("%s", check.hostel_id);
    while (fscanf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        if (strcmp(add.hostel_id, check.hostel_id) == 0) {
            test = 1;
            printf("\nhostel_id:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%s \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%s \nRoom No:%s \nHostel:%s \nAdd.rent_paid :%d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);

            // printf("\nhostel_id:%s\nName: %s", add.hostel_id, add.name);
        }
    }

    fclose(ptr);
    if (test != 1)
        printf("\nRecord not found!!\a\a\a");
see_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        closer();
    else if (main_exit == 0)
        erase();

    else {
        printf("\nInvalid!\a");
        goto see_invalid;
    }
}
void edit() {
    system("CLS");
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\nEnter the hostel id of the student whose info you want to change:");
    scanf("%s", upd.hostel_id);
    while (fscanf(old, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        if (strcmp(add.hostel_id, upd.hostel_id) == 0) {
            test = 1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Enter the new room no.:");
                scanf("%s", upd.room_no);
                fprintf(newrec, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no, add.hostel_name, add.rent_paid);
                printf("Changes saved!");
            } else if (choice == 2) {
                printf("Enter the new phone number:");
                scanf("%d", &upd.phone_no);
                fprintf(newrec, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
                printf("Changes saved!");
            }
        } else
            fprintf(newrec, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
        printf("\nRecord not found!!\a\a\a");
edit_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        closer();
    else if (main_exit == 0)
        edit();
    else {
        printf("\nInvalid!\a");
        goto edit_invalid;
    }
}
void erase() {
    system("CLS");
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("Enter the Hostel_id of student whose data you want to delete:");
    scanf("%s", rem.hostel_id);
    while (fscanf(old, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
        if (strcmp(add.hostel_id, rem.hostel_id) != 0)
            fprintf(newrec, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
        else {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
        printf("\nRecord not found!!\a\a\a");
erase_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu();
    else if (main_exit == 2)
        closer();
    else if (main_exit == 0)
        erase();
    else {
        printf("\nInvalid!\a");
        goto erase_invalid;
    }
}
void closer() {
    system("CLS");
    printf("\n\n\n*THANK YOU FOR USING THE SYSTEM*\n\n");
}
void maintenance() {
    printf(" Enter your ID & Room number : \n");

    FILE *filePointer;
    char data[1000];

    filePointer = fopen("maintenance.txt", "a");

    printf("Enter data to write into the file (Enter 'exit' to stop):\n");

    while (1) {
        fgets(data, sizeof(data), stdin);

        if (strcmp(data, "exit\n") == 0)
            break;

        fprintf(filePointer, data);
    }

    printf("Data has been written to the file.\n");

    fclose(filePointer);

    reg_user();
}

void PP() {
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
            system("color 1f");
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
                delay(50);
            }
            printf("   |\n                    \\______________ ______________/           \n");
            printf("                                                           \n");
            printf("\n\n\n");
            // system("pause");
            delay(1000);

            menu();
        } else {
            printf("Invalid Password !\n\n");
            delay(40);
            PP();
        }
    }

    if (x == 2) {
        system("CLS");
        FILE *ptr;
        int test = 0;
        int choice;
        char tmpUserName[200];
        char tmpPassword[200];

        char name[200], id[200];

        int x1 = 0;
        while (x1 == 0) {
            printf(" \n                       Username       : ");
            scanf("%s", &name);

            ptr = fopen("record.dat", "r");

            printf(" \n                       ENTER PASSWORD : ");
            scanf("%s", check.hostel_id);
            while (fscanf(ptr, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid) != EOF) {
                if (strcmp(add.hostel_id, check.hostel_id) == 0) {
                    test = 1;

                    // printf("\nhostel_id:%s\nName: %s", add.hostel_id, add.name);
                    strcpy(tmpUserName, add.name);
                    strcpy(tmpPassword, add.hostel_id);
                    // printf("%s", tmpUserName);
                }
            }
            // printf("%d", test);

            if (test == 1 && strcmp(tmpUserName, name) == 0) {
                reg_user();
                x1 = 1;
            } else {
                printf("%s", "Invalid username or password!");
            }
        }

        // scanf("%s", &id);

        // reg_user();
    }
}

void reg_user() {
    printf("\n\n\t\t\t******************************************\n");
    printf("\t\t\t***    press 1 for own information         ***\n");
    printf("\t\t\t***    press 2 for hostel rule regulation  ***\n");
    printf("\t\t\t***    press 3 for food menu               ***\n");
    printf("\t\t\t***    press 4 for request maintenance     ***\n");
    printf("\t\t\t***    press 5 for main menu               ***\n");
    printf("\t\t\t**********************************************\n");
    printf("\n\nEnter your choice: ");
    scanf("%d", &i);
    if (i == 1) {
        u_see();
        printf("\n\n");
        reg_user();
    } else if (i == 2) {
        rules();
        printf("\n\n");
        reg_user();
    } else if (i == 3) {
        food_menu();
        printf("\n\n");
        reg_user();
    } else if (i == 4) {
        maintenance();
        printf("\n\n");
    } else if (i == 5) {
        pass();
        PP();
    } else {
        printf("Invalid Input\n");
        printf("Try again\n");
        reg_user();
    }
}

void rules() {
    printf("\n\t1.you have to pay hostel charge every month within first 10 days.\n  ");
    printf("\tafter 10 day you have to pay 20tk for each day & 200tk for each month.\n");
    printf("\t2.you have to back in hostel in due time. \n\t\t\tsummer: last time 7.00pm\n\t\t\twinter: last time 6.00pm \n");
    printf("\t3.before 6 month you cant leave the hostel.\n");
    printf("\t4.if you want to leave this hostel you have to inform the hostel \n\tauthority before 2 month.\n");
    printf("\t5.if you have computer or laptop, we have to pay 100tk as fee.\n");
    printf("\t6.only your two local guardian can come to meet with you\n");
}

void food_menu() {
    printf("\n\n");
    printf("| Day |     Breakfast    |        lunch        |            Dinner          |\n");
    printf("=============================================================================\n");
    printf("| sat |   ruti,vegetable | rice,chicken,lentil | rice,vegetable,vorta,lentil|\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| sun |  rice, vegetable | rice,fish,lentil    |  rice,vegetable,egg,lentil |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| mon |     ruti,egg     | rice,chicken,lentil |  rice,fish,lentil          |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| tue |  khichuri,egg    | rice,meat,lentil    |  rice,fish,lentil          |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| wed |   rice, vorta    | rice,chicken,lentil |  rice,egg,lentil           |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| thu |  ruti, vegetable | rice,fish,lentil    |  rice,vegetable,egg,lentil |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| fri |    khichuri,egg  | rice,chicken,lentil |  rice,fish,lentil          |\n");
    printf("=============================================================================\n");
}

void maintenance_view() {
    FILE *filePointer;
    char data[100];

    // Open file in read mode
    filePointer = fopen("maintenance.txt", "r");

    if (filePointer == NULL) {
        printf("File does not exist or could not be opened.\n");
        return;
    }

    printf("Data read from the file:\n");

    // Read and print data line by line until end of file
    while (fgets(data, sizeof(data), filePointer) != NULL) {
        printf("%s", data);
    }

    // Close file
    fclose(filePointer);
}
