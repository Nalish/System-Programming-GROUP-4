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
