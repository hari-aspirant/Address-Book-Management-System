#ifndef CONTACT_H
#define CONTACT_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


struct Contact{
    // structure members
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100]; // calling structure(contact) inside a structure(addressbook)
    int contactCount;
    int index_record[100];
    int ir_size;
};
// initialize the functions and its arguments
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);
int validate_phone(char mobile[], struct AddressBook *addressBook, int flag);
int validate_email(char mail[], struct AddressBook *addressBook, int flag);
void search_by(char data[], struct AddressBook *addressBook, int type);
void printcontact(struct AddressBook *addressBook, int i);
void files_saving(struct AddressBook *addressBook);
void load_contacts(struct AddressBook *addressBook);

#endif
