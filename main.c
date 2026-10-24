/*
Project Number : Project Number 1
Name of the project : Address Book
Name of the author : Hari Hara Ganesh A
Submission Date : 26-09-2026
*/
#include "addressbook.h"
int main() 
{
    int choice;

    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;
	load_contacts(&addressBook); //Load before calling menu
    do 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6.  save & Exit\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);
	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook); // Create contact
		break;
	    case 2:
		search_contact(&addressBook); // Search contact
		break;
	    case 3:
		edit_contact(&addressBook); // Edit contact
		break;
	    case 4:
		delete_contact(&addressBook); // Delete contact
		break;
	    case 5:
		list_contacts(&addressBook); // Display contact
		break;
	    case 6:
		files_saving(&addressBook); // save the contents to csv file and exit
		printf("Saving and Exiting...\n");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
		break;
	}
    } while (choice != 6);

    return 0;
}
