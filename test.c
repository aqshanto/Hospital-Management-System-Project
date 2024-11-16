#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addPatient() {
    FILE *file = fopen("patients.txt", "a");  // Open file in append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char name[100];
    int id;
    char disease[50];

    printf("Enter Patient ID: ");
    scanf("%d", &id);
    getchar();  // Consume the newline left by scanf
    printf("Enter Patient Name: ");
    fgets(name, sizeof(name), stdin);  // Use fgets for multi-word input
    name[strcspn(name, "\n")] = 0;     // Remove trailing newline character
    printf("Enter Disease: ");
    scanf("%s", disease);
    getchar();

    fprintf(file, "%d\t%s\t%s\n", id, name, disease);  // Write data to the file
    fclose(file);
    printf("Patient added successfully!\n");
}

void viewPatients() {
    FILE *file = fopen("patients.txt", "r");  // Open file in read mode
    if (file == NULL) {
        printf("No patient records found!\n");
        return;
    }

    int id;
    char name[100];
    char disease[50];

    printf("Patient Records:\n");
    printf("ID   Name                 Disease\n");
    printf("---------------------------------------\n");
    while (fscanf(file, "%d\t%[^\t]\t%[^\n]", &id, name, disease) != EOF) {  // Corrected format specifier
        printf("%-5d %-20s %-20s\n", id, name, disease);
    }

    fclose(file);
}

void clearRecords() {
    FILE *file = fopen("patients.txt", "w");  // Open file in write mode
    if (file == NULL) {
        printf("Error clearing records!\n");
        return;
    }

    fclose(file);
    printf("All patient records cleared!\n");
}

int main() {
    while (1) {
        printf("\n1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Clear Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int x;
        scanf("%d", &x);
        getchar();  // Consume the newline character

        if (x == 1) {
            addPatient();
        } else if (x == 2) {
            viewPatients();
        } else if (x == 3) {
            clearRecords();
        } else if (x == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}