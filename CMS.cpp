//COURIER MANAGEMENT SYSTEM USING C++


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

// Structure for each shipment
struct ship {
    char sname[50];
    char rname[50];
    char sadd[50];
    char radd[50];
    float cost;
    float weight;
    int id;
    struct ship* next;  // Pointer to the next shipment
};

// Head of the linked list
struct ship* head = NULL;

// Function to create a new shipment record
struct ship* createRecord() {
    struct ship* newRecord = (struct ship*)malloc(sizeof(struct ship));
    if (newRecord == NULL) {
        cout << "Memory allocation failed!\n";
        exit(1);
    }
    return newRecord;
}

// Function to add a new shipment record
void addRecord() {
	system("cls");
    char another = 'y';

    while (another == 'y') {
        struct ship* newRecord = createRecord();

        cout << "\nEnter Sender Name: ";
        cin.ignore();
        cin.getline(newRecord->sname, 50);
        
        cout << "\nEnter Receiver Name: ";
        cin.getline(newRecord->rname, 50);
        
        cout << "\nEnter Sender Address: ";
        cin.getline(newRecord->sadd, 50);
        
        cout << "\nEnter Receiver Address: ";
        cin.getline(newRecord->radd, 50);
  
        cout << "\nEnter Expense: ";
        cin >> newRecord->cost;
        
        cout << "\nEnter Weight: ";
        cin >> newRecord->weight;
  
        cout << "\nEnter SHIPMENT-ID: ";
        cin >> newRecord->id;

        // Insert the new record at the beginning of the list
        newRecord->next = head;
        head = newRecord;

        cout << "\nWant to add another Shipment (Y/N): ";
        cin >> another;
    }
}

// Function to delete a shipment record by sender name
void deleteRecord() {
	system("cls");
    char sendname[50];
    char another = 'y';

    while (another == 'y') {
        cout << "\nEnter sender name to cancel shipment: ";
        cin.ignore();
        cin.getline(sendname, 50);

        struct ship* current = head;
        struct ship* previous = NULL;

        // Traverse the linked list to find the record to delete
        while (current != NULL) {
            if (strcmp(current->sname, sendname) == 0) {
                if (previous == NULL) { // Deleting the head
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                cout << "Shipment cancelled.\n";
                break;
            }
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "No shipment found with sender name: " << sendname << endl;
        }

        cout << "\nWant to delete another record (Y/N): ";
        cin >> another;
    }
}

// Function to display all shipment records
void displayRecord() {
	system("cls");
	
    cout << "\n==============================================================================";
    cout << "\nSENDER NAME\tRECEIVER NAME\tEXPENSE\tWEIGHT\tSHIPMENT ID";
    cout << "\n==============================================================================";

    struct ship* current = head;
    int record_count = 0;

    while (current != NULL) {
        cout << "\n" << left << setw(15) << current->sname 
             << "\t" << setw(15) << current->rname 
             << "\t$" << fixed << setprecision(2) << current->cost 
             << "\t" << fixed << setprecision(2) << current->weight 
             << "\t\t" << current->id;
        record_count++;
        current = current->next;
    }

    if (record_count == 0) {
        cout << "\nNo records found.\n";
    }

    cout << "\n\n\n\t";
    system("pause");
}

// Function to modify a shipment record
void modifyRecord() {
	system("cls");
    char sendername[50];
    char another = 'y';

    while (another == 'y') {
        cout << "\nEnter Sender name to modify: ";
        cin.ignore();
        cin.getline(sendername, 50);

        struct ship* current = head;

        // Traverse the linked list to find the record to modify
        while (current != NULL) {
            if (strcmp(current->sname, sendername) == 0) {
                cout << "\nEnter new sender name: ";
                cin.getline(current->sname, 50);
                cout << "\nEnter new Receiver name: ";
                cin.getline(current->rname, 50);
                cout << "\nEnter new Expense: ";
                cin >> current->cost;
                cout << "\nEnter new Weight: ";
                cin >> current->weight;
                cout << "\nEnter new Shipment-ID: ";
                cin >> current->id;
                cout << "Record modified.\n";
                break;
            }
            current = current->next;
        }

        if (current == NULL) {
            cout << "No shipment found with sender name: " << sendername << endl;
        }

        cout << "\nWant to modify another shipment (Y/N): ";
        cin >> another;
    }
}

// Main function
int main() {
    int choice;

    cout << "\n\n\n\n\t\t\t\t==============================";
    cout << "\n\t\t\t\t~~COURIER MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t==============================";
    cout << "\n\n\n\t\t\t\t\tDeveloper : @Aniket Kumar\n";
    system("pause");

    char password[50] = "aniket@55";
    char input_password[50];
    
    cout << "Enter password: ";
    cin >> input_password;
    
    if (strcmp(password, input_password) != 0) {
        cout << "Incorrect password. Exiting program...\n";
        return 0;
    }
  
    while (1) {
        system("cls");
        cout << "\n1. ADD NEW SHIPMENT\n";
        cout << "2. CANCEL SHIPMENT\n";
        cout << "3. VIEW SHIPMENT\n";
        cout << "4. UPDATE SHIPMENT\n";
        cout << "5. EXIT\n";
        cout << "\nENTER YOUR CHOICE...\n";
        fflush(stdin);
        cin >> choice;
  
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                displayRecord();
                break;
            case 4:
                modifyRecord();
                break;
            case 5:
                // Free memory before exiting
                while (head != NULL) {
                    struct ship* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                cout << "\nINVALID CHOICE...\n";
        }
    }
    
return 0;
}