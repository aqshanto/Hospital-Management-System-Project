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
    int availableSlots;
    struct Doctor* next;
} Doctor;

// Global head pointer for the linked list of doctors
Doctor* doctorHead = NULL;

typedef struct Appointment {
    int patientID;
    int doctorID;
    struct Appointment* next;
} Appointment;

Appointment* appointmentFront = NULL;  // Queue front
Appointment* appointmentRear = NULL;   // Queue rear

Patient* patientHead = NULL;
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

// void addDoctor(int id, const char* name, const char* specialty, int availableSlots) {  // doctor er function
//     Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
//     newDoctor->id = id;
//     strcpy(newDoctor->name, name);
//     strcpy(newDoctor->specialty, specialty);
//     newDoctor->availableSlots = availableSlots;
//     newDoctor->next = NULL;

//     if (doctorHead == NULL) {
//         doctorHead = newDoctor;
//     } else {
//         Doctor* temp = doctorHead;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newDoctor;
//     }
// }

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

// void displayDoctors() {
//     Doctor* temp = doctorHead;
//     char ar[] = "Doctor List:";
//     printf("\t");
//     for (int i = 0; i < sizeof(ar) - 1; i++) {
//         Sleep(25);
//         printf("%c", ar[i]);
//     }
//     printf("\n");
//     while (temp != NULL) {
//         printf("\t\tID: %d, Name: %s, Specialty: %s, Available Slots: %d\n", temp->id, temp->name, temp->specialty, temp->availableSlots);
//         temp = temp->next;
//     }
//     printf("\n");
// }

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

// void inputDoctorData() {
//     int id, availableSlots;
//     char name[50], specialty[50];

//     char s[] = "You wanted to add a new doctor. \n\tPlease enter his/her detailed information";
//     slowTxt(s);

//     printf("\t=============================================\n");
//     printf("\n");
//     printf("\tEnter Doctor ID: ");
//     scanf("%d", &id);

//     printf("\tEnter Doctor Name: ");
//     scanf(" %[^\n]s", name);

//     printf("\tEnter Doctor Specialty: ");
//     scanf(" %[^\n]s", specialty);

//     printf("\tEnter Available Slots: ");
//     scanf("%d", &availableSlots);

//     addDoctor(id, name, specialty, availableSlots);
//     printf("\tDoctor added successfully!\n\n");
//     printf("\t=============================================\n");
// }

Patient* searchPatientByID(int id) {
    Patient* temp = patientHead;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Return NULL if the patient is not found
}

// Doctor* searchDoctorByID(int id) {
//     Doctor* temp = doctorHead;
//     while (temp != NULL) {
//         if (temp->id == id) {
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;  // Return NULL if the doctor is not found
// }

void updatePatient(int id) {
    Patient* patient = searchPatientByID(id);
    if (patient == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

    printf("Enter New Patient Name: ");
    scanf(" %[^\n]s", patient->name);
    printf("Enter New Patient Age: ");
    scanf("%d", &patient->age);
    printf("Enter New Patient Gender: ");
    scanf(" %[^\n]s", patient->gender);
    printf("Enter New Patient Disease: ");
    scanf(" %[^\n]s", patient->disease);

    printf("Patient information updated successfully!\n");
}

// void updateDoctor(int id) {
//     Doctor* doctor = searchDoctorByID(id);
//     if (doctor == NULL) {
//         printf("Doctor with ID %d not found.\n", id);
//         return;
//     }

//     printf("Enter New Doctor Name: ");
//     scanf(" %[^\n]s", doctor->name);
//     printf("Enter New Doctor Specialty: ");
//     scanf(" %[^\n]s", doctor->specialty);
//     printf("Enter New Available Slots: ");
//     scanf("%d", &doctor->availableSlots);

//     printf("Doctor information updated successfully!\n");
// }

void deletePatient(int id) {
    Patient *temp = patientHead, *prev = NULL;

    // Check if the head node contains the patient
    if (temp != NULL && temp->id == id) {
        patientHead = temp->next;  // Move head to the next node
        free(temp);                // Free the old head
        printf("Patient with ID %d deleted successfully.\n", id);
        return;
    }

    // Traverse the list to find the patient
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If patient not found
    if (temp == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

    // Remove the patient from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Patient with ID %d deleted successfully.\n", id);
}

// void deleteDoctor(int id) {
//     Doctor *temp = doctorHead, *prev = NULL;

//     // Check if the head node contains the doctor
//     if (temp != NULL && temp->id == id) {
//         doctorHead = temp->next;  // Move head to the next node
//         free(temp);               // Free the old head
//         printf("Doctor with ID %d deleted successfully.\n", id);
//         return;
//     }

//     // Traverse the list to find the doctor
//     while (temp != NULL && temp->id != id) {
//         prev = temp;
//         temp = temp->next;
//     }

//     // If doctor not found
//     if (temp == NULL) {
//         printf("Doctor with ID %d not found.\n", id);
//         return;
//     }

//     // Remove the doctor from the linked list
//     prev->next = temp->next;
//     free(temp);
//     printf("Doctor with ID %d deleted successfully.\n", id);
// }

void admin() {
    login();
}

void initializeDoctors() {
    doctorHead = NULL;  // Initialize the head of the linked list

    // Specialties
    char specialties[5][50] = {
        "Cardiology", "Orthopedics", "Dermatology", "Pediatrics", "Neurology"};

    // Doctor names for each specialty
    char doctorNames[5][5][50] = {
        {"Dr. Alice Smith", "Dr. John Doe", "Dr. Clara Brown", "Dr. Max Payne", "Dr. Lisa Ray"},
        {"Dr. Bob Johnson", "Dr. Megan Clark", "Dr. George White", "Dr. Sarah Hill", "Dr. Chris Evans"},
        {"Dr. Charlie Lee", "Dr. Emily Stone", "Dr. Kevin Green", "Dr. Nina Scott", "Dr. Oliver Blue"},
        {"Dr. Diana Martinez", "Dr. Bruce Wayne", "Dr. Rachel Grey", "Dr. Tony Stark", "Dr. Natasha Romanoff"},
        {"Dr. Edward Black", "Dr. Laura White", "Dr. Henry Gold", "Dr. Fiona Red", "Dr. Victor Grey"}};

    // Slots available for each doctor
    int slots[5][5] = {
        {3, 5, 4, 2, 6},
        {4, 3, 5, 2, 1},
        {6, 4, 3, 2, 5},
        {2, 3, 5, 6, 4},
        {5, 6, 4, 3, 2}};

    // Populate the doctor list
    Doctor* temp = NULL;

    for (int i = 0; i < 5; i++) {      // Loop through specialties
        for (int j = 0; j < 5; j++) {  // Loop through doctors in each specialty
            Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
            newDoctor->id = i * 5 + j + 1;  // Generate unique IDs
            strcpy(newDoctor->name, doctorNames[i][j]);
            strcpy(newDoctor->specialty, specialties[i]);
            newDoctor->availableSlots = slots[i][j];
            newDoctor->next = NULL;

            if (doctorHead == NULL) {
                doctorHead = newDoctor;
                temp = doctorHead;
            } else {
                temp->next = newDoctor;
                temp = newDoctor;
            }
        }
    }

    // printf("Doctors initialized successfully.\n");
}

Doctor* searchDoctorByID(int id) {
    Doctor* temp = doctorHead;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Doctor not found
}

void makeAppointment(char patientName[], int doctorID) {
    Doctor* doctor = searchDoctorByID(doctorID);

    if (doctor == NULL) {
        printf("Doctor with ID %d not found.\n", doctorID);
        return;
    }

    if (doctor->availableSlots <= 0) {
        printf("No slots available for Doctor ID %d (%s).\n", doctorID, doctor->name);
        return;
    }

    // Reduce the available slots and schedule the appointment
    doctor->availableSlots--;

    printf("Appointment confirmed for Patient: %s with Doctor ID %d (%s).\n",
           patientName, doctorID, doctor->name);
    printf("Your slot number is %d.\n", doctor->availableSlots + 1);

    returnlanding();
}

void browseDoctorsBySpecialty() {
    Doctor* temp = doctorHead;
    char specialties[10][50];  // Assuming a maximum of 10 specialties
    int specialtyCount = 0;

    // Step 1: Extract unique specialties
    while (temp != NULL) {
        int found = 0;
        for (int i = 0; i < specialtyCount; i++) {
            if (strcmp(specialties[i], temp->specialty) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(specialties[specialtyCount], temp->specialty);
            specialtyCount++;
        }
        temp = temp->next;
    }

    // Step 2: Display specialties
    printf("\nAvailable Specialties:\n");
    for (int i = 0; i < specialtyCount; i++) {
        printf("%d. %s\n", i + 1, specialties[i]);
    }

    printf("Enter the number of the specialty you want to browse: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > specialtyCount) {
        printf("Invalid choice! Returning to Patient Menu.\n");
        return;
    }

    // Step 3: Show doctors in the selected specialty
    char selectedSpecialty[50];
    strcpy(selectedSpecialty, specialties[choice - 1]);
    temp = doctorHead;

    printf("\nDoctors in Specialty: %s\n", selectedSpecialty);
    int doctorFound = 0;
    while (temp != NULL) {
        if (strcmp(temp->specialty, selectedSpecialty) == 0) {
            printf("Doctor ID: %d, Name: %s, Slots Available: %d\n",
                   temp->id, temp->name, temp->availableSlots);
            doctorFound = 1;
        }
        temp = temp->next;
    }

    if (!doctorFound) {
        printf("No doctors available for this specialty.\n");
        return;
    }

    // Step 4: Allow patient to make an appointment
    char patientName[50];
    int doctorID;

    printf("\nEnter your name: ");
    scanf(" %[^\n]s", patientName);

    printf("Enter the Doctor ID to make an appointment: ");
    scanf("%d", &doctorID);

    makeAppointment(patientName, doctorID);
    returnlanding();
}

int main() {
    system("cls");
    initializeDoctors();
    // firstinterface();
    admin();
    system("cls");
    // Sleep(5000);
    // system("color 0C");
    // system("cls");
    return 0;
}

void menu() {
    int choice, id;
    printf("\n\n");
    printf("\t=============================================\n");
    printf("\n");
    printf("\t[1] Add New Patient\n");
    printf("\t[2] Display Patients\n");
    printf("\t[3] Search Patient by ID\n");
    printf("\t[4] Update Patient Information\n");
    printf("\t[5] Delete Patient by ID\n");
    printf("\t[6] Return to Home\n");
    printf("\t[7] Exit\n\n");
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
            printf("\tEnter Patient ID to search: ");
            scanf("%d", &id);
            Patient* patient = searchPatientByID(id);
            if (patient) {
                printf("\tPatient Found: ID: %d, Name: %s, Age: %d, Gender: %s, Disease: %s\n",
                       patient->id, patient->name, patient->age, patient->gender, patient->disease);
            } else {
                printf("\tPatient not found.\n");
            }
            break;
        case 4:
            printf("\tEnter Patient ID to update: ");
            scanf("%d", &id);
            updatePatient(id);
            break;
        case 5:
            printf("\tEnter Patient ID to delete: ");
            scanf("%d", &id);
            deletePatient(id);
            break;
        case 6:
            login();
            break;
        case 7:
            printf("\tExiting...\n");
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

    if (x == 2) {
        printf("\n\n\t\t\t1. Our Services.\n");
        printf("\t\t\t2. Make Appointment.\n\n");
        int a;
        printf("\tEnter your Choice: ");
        scanf("%d", &a);
        if (a == 1) {
        } else if (a == 2) {
            browseDoctorsBySpecialty();
        }
    }
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