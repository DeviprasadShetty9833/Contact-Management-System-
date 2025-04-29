#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.txt"
#define TEMP_FILE "temp.txt"
#define BACKUP_FILE "backup.txt"

void addContact(){
    int ch;
    char name[50], phone[15];
    FILE *file;

    do{
        printf("\n Do want to delete previous contact details (Y:1, N:0) : ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            file = fopen(FILE_NAME, "w");
            if (!file){
                printf("\n Error opening file!\n");
                return;
            }
            fclose(file);

        case 0:
            file = fopen(FILE_NAME, "a");
            if (!file) {
                printf("\n Error opening file!\n");
                return;
            }
            break;

        default: printf("\n Invalid Choice!!! Please Try again...\n");
        }

    }while((ch != 1) && (ch != 0));

    printf("\n Enter Name: ");
    scanf(" %[^\n]", name);
    printf(" Enter Phone: ");
    scanf("%s", phone);

    fprintf(file, "%s %s\n", name, phone);
    printf("\n Contact saved successfully!\n");

    fclose(file);
}

void viewContacts() {
    char name[50], phone[15];
    FILE *file = fopen(FILE_NAME, "r");

    if (!file) {
        printf("\n No contacts found.\n");
        return;
    }

    printf("\n=======( Contact List )=======\n\n");
    while (fscanf(file, "%s %s", name, phone) != EOF) {
        printf("Name: %s | Phone: %s\n", name, phone);
    }
    printf("\n----- End of Contact List ----\n");

    fclose(file);
}

void deleteContact() {
    char name[50], phone[15], delName[50];
    FILE *file = fopen(FILE_NAME, "r");

    if (!file) {
        printf("\n No contacts found to delete.\n");
        return;
    }

    // Backup current contacts before deletion (for undo)
    FILE *backup = fopen(BACKUP_FILE, "w");
    FILE *tempFile = fopen(TEMP_FILE, "w");

    printf("\n Enter the name to delete: ");
    scanf(" %[^\n]", delName);

    int found = 0;
    while (fscanf(file, "%s %s", name, phone) != EOF) {
        fprintf(backup, "%s %s\n", name, phone); // Backup all contacts
        if (strcmp(name, delName) != 0) {
            fprintf(tempFile, "%s %s\n", name, phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    fclose(backup);

    remove(FILE_NAME);
    rename(TEMP_FILE, FILE_NAME);

    if (found)
        printf("\n Contact deleted successfully! You can undo this.\n");
    else
        printf("\n Contact not found!\n");
}

void undoDelete() {
    char name[50], phone[15];
    FILE *backup = fopen(BACKUP_FILE, "r");

    if (!backup) {
        printf("\n No backup found. Undo not possible.\n");
        return;
    }

    FILE *file = fopen(FILE_NAME, "w");

    while (fscanf(backup, "%s %s", name, phone) != EOF) {
        fprintf(file, "%s %s\n", name, phone);
    }

    fclose(backup);
    fclose(file);

    printf("\n Undo successful! Deleted contacts are restored.\n");
}

int main() {
    int choice;

    printf("WELCOME TO, \n");
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Undo Last Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1: addContact();
                    break;
            case 2: viewContacts();
                    break;
            case 3: deleteContact();
                    break;
            case 4: undoDelete();
                    break;
            case 5: printf("Exiting...\n");
                    break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
