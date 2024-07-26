/*Subproblems

    Define the Contact Data Structure
        Define a structure to hold the contact information (first name, last name, and telephone number).

    Initialize the Contact List
        Initialize a list or array to hold up to 12 contacts.

    Add a Person
        Implement a function to add a new contact to the list.

    Delete a Person
        Implement a function to delete a contact from the list.

    Update a Person’s Information
        Implement a function to update the information for an existing contact.

    Display All Contacts
        Implement a function to display all current contact information.

Order of Implementation

    Define the Contact Data Structure
        Define a structure or class for storing individual contact information.
        Testing: Verify that instances of the structure/class can be created and accessed correctly.

    Initialize the Contact List
        Create a list or array to store the contacts.
        Testing: Verify that the list can hold up to 12 contacts and handle empty or partially filled states.

    Add a Person
        Implement the function to add a contact.
        Testing: Verify that new contacts are added correctly and that the list does not exceed 12 entries. Check edge cases, such as adding to a full list.

    Delete a Person
        Implement the function to delete a contact based on an identifier (e.g., index or name).
        Testing: Verify that contacts can be deleted correctly, ensuring the list updates properly. Check edge cases, such as deleting from an empty list or a contact that does not exist.

    Update a Person’s Information
        Implement the function to update an existing contact’s information.
        Testing: Verify that contact information is updated correctly. Check edge cases, such as updating a non-existent contact.

    Display All Contacts
        Implement the function to display all contacts.
        Testing: Verify that all contacts are displayed correctly, including when the list is empty, partially filled, or full.*/

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 12

struct Contact {
  char name[50];
  long long phoneNumber;
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
  if (numContacts >= MAX_CONTACTS) {
    printf("Contact list is full!\n");
    return;
  }
  printf("Enter name: ");
  fgets(contacts[numContacts].name, sizeof(contacts[numContacts].name), stdin);
  contacts[numContacts].name[strcspn(contacts[numContacts].name, "\n")] = '\0';
  printf("Enter phone number: ");
  scanf("%lld", &contacts[numContacts].phoneNumber);
  getchar(); // Consume remaining newline character
  numContacts++;
  printf("Contact added!\n");
}

void deleteContact() {
  if (numContacts == 0) {
    printf("Contact list is empty!\n");
    return;
  }
  printf("Enter index of contact to delete (0-%d): ", numContacts - 1);
  int index;
  scanf("%d", &index);
  getchar(); // Consume remaining newline character
  if (index < 0 || index >= numContacts) {
    printf("Invalid index!\n");
    return;
  }
  // Shift elements to remove the deleted contact
  for (int i = index; i < numContacts - 1; i++) {
    contacts[i] = contacts[i + 1];
  }
  numContacts--;
  printf("Contact deleted!\n");
}

void displayContacts() {
  if (numContacts == 0) {
    printf("No contacts found!\n");
    return;
  }
  printf("\nContacts:\n");
  for (int i = 0; i < numContacts; i++) {
    printf("%s - %lld\n", contacts[i].name, contacts[i].phoneNumber);
  }
}

int main() {
  int choice;

  while (1) {
    printf("\n1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Display Contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume remaining newline character

    switch (choice) {
      case 1:
        addContact();
        break;
      case 2:
        deleteContact();
        break;
      case 3:
        displayContacts();
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
