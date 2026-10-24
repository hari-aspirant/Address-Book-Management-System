#include "addressbook.h"

void add_contact(struct AddressBook *addressBook)
{
    int flag=0;
    char mobile[11];
    char mail[25];
      
    printf("Enter the name: "); // save the name   
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    
    while(1)
    {
        printf("Enter the mobile number: ");
        scanf("%s",mobile);
        if(validate_phone(mobile,addressBook,flag)) //validate the phone number
        {
            // if the condition satisfies coppy the phone to address book contact -phone
            strcpy(addressBook->contacts[addressBook->contactCount].phone,mobile);
            break;
        }
    }
   
    while(1)
    {
        printf("Enter the email: ");
        scanf("%s",mail);
        if(validate_email(mail,addressBook,flag))  //validate the email id
        {
            // if the condition satisfies copy the mail to address book contact-email
            strcpy(addressBook->contacts[addressBook->contactCount].email,mail);
            break;
        }
    }

    (addressBook->contactCount)++; // increment the count value for every adding

}
void search_contact(struct AddressBook *addressBook)
{
    // if contact count is 0 then no contacts are available 
     if(addressBook->contactCount == 0)
    {
        printf("-----No contacts, add contacts to proceed-------\n");
    }
    else
    {
     addressBook->ir_size = 0;
     int option;
     int flag=1;
     char name[50];
     char mobile[10];
     char mail[25];
     // search by options
    printf("\nSearch by Menu:\n");
	printf("1. search by name\n");
	printf("2. Search by contact\n");
	printf("3. search by mail\n");
	printf("4. exit\n");
    printf("Enter the option: ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        {
            printf("Enter the name: ");
            scanf(" %[^\n]",name);
            search_by(name,addressBook,1); // declare the search by fuction depending upon the input parameter
            break;
        }
        case 2:
        {
            while(1)
            {
            printf("Enter the phone number: ");
            scanf(" %s",mobile);
            if(validate_phone(mobile,addressBook,flag)) //validate mobile again  
            break;
            }
            search_by(mobile,addressBook,2); // declare the search by fuction depending upon the input parameter
            break;
        }
        case 3:
        {
            while(1)
            {
            printf("Enter the Email address: ");
            scanf(" %s",mail);
            if(validate_email(mail,addressBook,flag)) //validate email again  
            break;
            }
            search_by(mail,addressBook,3); // declare the search by fuction depending upon the input parameter
            break;

        }
        case 4:
        break;
    }
}

}
void edit_contact(struct AddressBook *addressBook)
{ 
        if(addressBook->contactCount == 0)
        {
            printf("-----No contacts, add contacts to proceed-------\n");
        }
        else
        {
        search_contact(addressBook); // before editing search the name wheather its present or not 
        int contact_index;
        if(addressBook->ir_size!=0)
        {
            int index,option;
            printf("---------Contact Found---------\n");
            if(addressBook->ir_size > 1)
            {
            while(1)
                {
                    printf("Please select the particular contact:"); 
                    scanf("%d",&index);
                    if(index <= addressBook->ir_size && index > 0)
                    {
                     
                     index=index-1; // now change the index to store depending on the index (exp 1 means it stores in 0)
                     contact_index=addressBook->index_record[index]; // store the index value 
                     printcontact(addressBook, contact_index);
                     break;
                    }
                    else // if the index is outof bound then print invalid
                    {
                      printf("-----invaid index-----,try again--------\n");
                    }
                }
            }
            else
            {
            // if structure  has only one contact count, then dont as for contact index selection
            contact_index=addressBook->index_record[0];
            printcontact(addressBook, contact_index);
            }
            // if index count is copied ,do the operation "what to delete" by structure memebers 

            while(1)
            {
            printf("-----what to edit------\n");
            printf("1. name\n");
	        printf("2. contact\n");
	        printf("3. mail\n");
            printf("4. Exit\n");
            printf("Enter the option: ");
            scanf("%d",&option);
            int flag=0;
            switch(option)
            {
                case 1:
                {
                    // Enter the new name and store it in structure index
                    printf("Enter the new name: ");
                    scanf(" %[^\n]",addressBook->contacts[contact_index].name);
                    printf("---------Edited contact----------\n");
                    printcontact(addressBook,contact_index);
                    printf("---------Contact saved---------\n");
                    break;
                }
                case 2:
                {
                     while(1)
                     {
                        // Enter the new mobile and store it in strcture index
                        char mobile[50];
                        printf("Enter the new mobile number: ");
                        scanf("%s",mobile);
                        if(validate_phone(mobile,addressBook,flag))
                        {
                        // if the condition satisfies copy the phone to address book contact -phone
                            strcpy(addressBook->contacts[contact_index].phone,mobile);
                            break;
                        }
                    }
                    printf("---------Edited contact----------\n");
                    printcontact(addressBook,contact_index);
                    printf("---------Contact saved---------\n");
                    break;

                }
                case 3:
                {
                     while(1)
                     {
                        // Enter the new mail and store it in strcture index
                        char mail[50];
                        printf("Enter the new email: ");
                        scanf("%s",mail);
                        // if the condition satisfies copy the mail to address book contact-email
                        if(validate_email(mail,addressBook,flag))
                        {
                            strcpy(addressBook->contacts[contact_index].email,mail);
                            break;
                        }
                    }
                    printf("---------Edited contact----------\n");
                    printcontact(addressBook,contact_index);
                    printf("---------Contact saved---------\n");
        
                    break;

                }
                case 4:
                break; // if the option is 4 exit switch case
               
            }
            if(option==4)
            break;  //break the loop
           
        }
     }
        else
        {
            printf("--------------Contact not found-----------\n\n"); // if the parameterrs not matched 
        }
    }
}


void delete_contact(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("-----No contacts, add contacts to proceed-------\n"); //if no contacts are there ..then print no contacts
    }
    else
    {
     search_contact(addressBook); // search contact to find the contact is present in the list or not 
        int contact_index;
        if(addressBook->ir_size!=0)
        {
            int index,option;
            printf("---------Contact Found-------\n");
            if(addressBook->ir_size > 1)
            {
            while(1)
                {
                    // if more than 1 contact having same name , then implement operation to select particular index
                    printf("Please select the particular contact:");
                    scanf("%d",&index);
                    if(index <= addressBook->ir_size && index > 0)
                    {
                     
                     index=index-1;
                     contact_index=addressBook->index_record[index];
                     printcontact(addressBook, contact_index);
                     break;
                    }
                    else
                    {
                        printf("---invaid index--,try again--------\n"); // if index is not found , print invalid and ask the index again
                    }
                }
            }
            else
            {
                //if only one contact is there, you can directly use that index
            contact_index=addressBook->index_record[0];
            printcontact(addressBook, contact_index);
            }
    
            char a;
            printf("Do you want to delete : y or n:");
            scanf(" %c",&a);
            // Get permissiion from the user before deleting the contact
            if(a == 'y')
            {
            //Left shift the index to shift to the contact contact
            for(int i=contact_index;i<addressBook->contactCount;i++)
            {
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--; // Decrement the contact count after deleting the contact
            printf("--------contact deleted sucessfully----------\n");
            }
            else
            {
                printf("-----------Contact retrived-----------\n"); // Else dont delete the contact go back to menu
            }
        }
    }
}
void list_contacts(struct AddressBook *addressBook)
{
    if((addressBook->contactCount)==0) // if contact count is zero , then no contact is added in side the function
    {
        printf("---No Contacts entered - Add some contacts to list it up----\n\n");
    }
    else
    {
    // Listing the contacts saved inside the structure content by accessing the member functions
    printf("-----------------------------------------------------------------------------------------\n");
    printf( "%-10s%-20s%-20s%-20s\n","S.No","Name","Mobile.No","Email Address");
    printf("-----------------------------------------------------------------------------------------\n");
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        printf("%-10d%-20s%-20s%-20s\n",i+1,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("-----------------------------------------------------------------------------------------\n");

    }
    }

}
// Validate the user entered mobile number
int validate_phone(char mobile[],struct AddressBook *addressBook,int flag)
{
    if(strlen(mobile)!=10) // Check for length of mobile number
    {
        printf("~ Error !: The size of number is not 10.\n");
        return 0;
    }
    for(int i=0;mobile[i]!='\0';i++) // check whether each character is a digit character or not
    {
        if(!isdigit(mobile[i]))
        {
            printf("~ Error !: The number contains alphabet character.\n");
            return 0;
        }
    }
    if(!(mobile[0]>='6' && mobile[0]<= '9')) // Mobile number should be based in india
    {
        printf("~ Error !: The number should be started with 6 - 9\n");
        return 0;
    }
    if(flag==0) // Usage of flag (only for add contact, to chack duplication)
    {
    for(int i=0;i<(addressBook->contactCount);i++) // check for duplicate contact only for add_contact function
    { 
        if(strcmp(mobile,addressBook->contacts[i].phone)==0)
        {
            printf("~ Error !: The number is already existed\n");
            return 0;
        }
    }
    }
    return 1;   // if all condtions are satisfied , return 1

}
// Validate the user entered email

int validate_email(char mail[],struct AddressBook *addressBook,int flag)
{
    int pos,count=0;
    for(int i=0;mail[i]!='\0';i++)
    {
        if(mail[0]=='@' || mail[strlen(mail)-1]=='@') // Checking  @ - as a last or a first character
        {
            printf("~ Error !: invalid-mail should not start or end with @\n");
            return 0;
        }
        if(!isalpha(mail[0])) // To validate the first char as alphabet
        {
            printf("~ Error !: invalid-mail should not start with numbers or special chars\n");
            return 0;
        }

        if(mail[i]=='@') 
        {
            pos = i; // To find the position of @
            count++; // to find number of @
        }
    
    }
    if(count==0) // To check the presence of @ in email
    {
        printf("~ Error !: invalid- mail not having @\n");
        return 0;
    }
    if(count>1) // If the @ as more than one count , then its invalid
    {
        printf("~ Error !: invalid- mail having more than one @\n");
        return 0;
    }
    char *last4char=mail+(strlen(mail)-4);
    if(strcmp(last4char,".com")!=0) // check the last 4 character as a .com or not
    {
        printf("~ Error !: invalid- mail not having .com at end\n");
        return 0;
    }
    char *last5char=mail+(strlen(mail)-5);
    if(strcmp(last5char,"@.com")==0) // check the last 5 character as @.com(invalid)
    {
        printf("~ Error !: invalid- mail not having any type of domains\n");
        return 0;
    }

    for(int i=0;mail[i]!='\0';i++)
    {
        if(isalpha(mail[i])) // If the user enters the alphabet in upper case, it will change in to lower case
        {
            mail[i]=tolower(mail[i]);
        }
    }
    if(flag==0)  // Usage of flag (only for add contact, to chack duplication)
    {
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(mail,addressBook->contacts[i].email)==0) // check for duplicate contact only for add_contact function
        {
            printf("~ Error !: invalid- mail already exists\n");
            return 0;
        }
    }
    }
    return 1; // if all condtions are satisfied , return 1
}

void search_by(char data[], struct AddressBook *addressBook, int type)
{
    int k=1;
    int option;
    int flag = 0;
    char *compare;

    for(int i=0; i<addressBook->contactCount; i++)
    { 
        if(type==1) // option 1 for comparing the name
            compare = addressBook->contacts[i].name;
        else if(type==2)  // option 2 for comparing phone
            compare = addressBook->contacts[i].phone;
        else if(type==3) // option 3 for comparing email
            compare = addressBook->contacts[i].email;

        if(strcmp(data,compare) == 0)
            {
                // print the contacts which are matched to the data
                flag = 1;
                addressBook->index_record[addressBook->ir_size]=i;
                printf("-----------------------------------------------------------------------------------------\n");
                printf("%-10d%-20s%-20s%-20s\n",k,addressBook->contacts[i].name,addressBook->contacts[i].phone,
                       addressBook->contacts[i].email);
                (addressBook->ir_size)++;
                k++;
            }
            
        }
        printf("-----------------------------------------------------------------------------------------\n");
        if(flag == 0)
        {
            printf("---- Not matched, No contacts found----\n"); // if no contacts are matched, print no contacts are matched
        }
}
void printcontact(struct AddressBook *addressBook, int i)
{
    // print the particular contact which index
    printf("-----------------------------------------------------------------------------------------\n");
    printf( "%-10s%-20s%-20s%-20s\n","S.No","Name","Mobile.No","Email Address");
    printf("-----------------------------------------------------------------------------------------\n");
        printf("%-10d%-20s%-20s%-20s\n",i+1,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("-----------------------------------------------------------------------------------------\n");

    }
void files_saving(struct AddressBook *addressBook) // save the contents to csv file before exiting 
{
    FILE *fp;
    fp = fopen("database.csv", "wb"); // open the file
    if(fp == NULL) // if the file is not present , it points to NULL
    {
        printf("File opening failed\n");
        return;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email); // print in to file(fprintf)

    fclose(fp); // close the file.
}
void load_contacts(struct AddressBook *addressBook) // Before asking the menu , load the contacts in to the structure variable
{
    FILE *fp;
    fp = fopen("database.csv", "r"); // open the file
    if(fp == NULL) // if the file is not present , it points to NULL
    {
        addressBook->contactCount = 0;
        return;
    }
    while(fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[addressBook->contactCount].name,
        addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email)!=EOF)
    {
        (addressBook->contactCount)++; // increment the contact count after loading the contact in to the structure varaiable
    }
    fclose(fp); // close the file
}




