# Address Book Management System in C

## Overview

Managing contact details becomes difficult when information is scattered across different places. The Address Book Management System is a menu-driven C application developed to make contact management simple, organized, and easy to use.

The project focuses on applying fundamental C programming concepts to a practical problem. It uses structured programming to organize contact-related operations and file handling to work with stored contact information.

Rather than building a graphical interface, this project focuses on the core logic behind a contact management application, including input handling, searching, updating records, and managing data.

## Objectives

- Develop a menu-driven application using C.
- Organize contact information using appropriate data structures.
- Implement contact management operations through separate functions.
- Apply file handling for storing and retrieving contact records, where implemented.
- Improve understanding of modular programming, conditional statements, loops, and record management.

## Features

- *Add Contact:* Enter and store a contact's details.
- *Search Contact:* Find a contact using the supported search criteria.
- *Edit Contact:* Update the details of an existing contact.
- *Delete Contact:* Remove a selected contact record.
- *View Contacts:* Display stored contacts, if supported by the program.
- *Data Management:* Use file handling to retain and retrieve contact information, if enabled in the implementation.

*Note: The feature list should match the operations implemented in the source code.*

## Technologies and Concepts Used

- Programming Language: C
- Data Organization: Structures ('struct'), if used in the implementation
- Functions: Modular program design
- File Handling: Reading and writing contact records
- Control Statements: Loops, conditional statements, and switch-case menus
- Input Handling: Accepting and validating user input

## Program Workflow

The application follows a simple menu-driven approach. The user selects an operation, the program processes the request, and the result is displayed before returning to the menu.

### Algorithm

1. Start the program.
2. Initialize the address book and load existing records if file storage is implemented.
3. Display the available operations.
4. Read the user's menu choice.
5. Execute the selected operation:
   - Add a new contact.
   - Search for an existing contact.
   - Edit the details of a contact.
   - Delete a contact.
   - Display contacts, if supported.
6. Handle invalid choices or unsuccessful operations appropriately.
7. Return to the menu if the user has not selected Exit.
8. Save any pending changes if required by the implementation.
9. Terminate the program.

## Pseudocode

BEGIN

    INITIALIZE ADDRESS BOOK

    WHILE user has not selected EXIT

        DISPLAY MENU
        READ choice

        SWITCH choice

            CASE ADD:
                READ contact details
                VALIDATE details
                STORE contact
                DISPLAY result
                BREAK

            CASE SEARCH:
                READ search key
                FIND matching contact
                DISPLAY result
                BREAK

            CASE EDIT:
                IDENTIFY existing contact
                IF contact exists
                    UPDATE contact details
                    SAVE changes if required
                ELSE
                    DISPLAY "Contact not found"
                END IF
                BREAK

            CASE DELETE:
                IDENTIFY contact to remove
                IF contact exists
                    REMOVE contact
                    SAVE changes if required
                ELSE
                    DISPLAY "Contact not found"
                END IF
                BREAK

            CASE EXIT:
                SAVE pending changes if required
                TERMINATE LOOP
                BREAK

            DEFAULT:
                DISPLAY "Invalid choice"

        END SWITCH

    END WHILE

END



## Compilation and Execution

Make sure you have GCC installed and open a terminal in the project directory.

### Compile

//bash
gcc main.c addressbook.c -o addressbook

### Run on Linux

//bash
./addressbook


### Run on Windows

//bash
addressbook.exe


If your source files require additional .c files, include them in the compilation command.

## Learning Outcomes

Working on this project helped me connect C programming fundamentals with a practical application. It gave me experience in organizing program logic, separating operations into functions, handling user input, and working with contact records.

It also helped me understand how a menu-driven application manages different operations while maintaining a clear program flow.

## Future Improvements

- Strengthen input validation and error handling.
- Improve search efficiency for larger contact lists.
- Add duplicate-contact detection.
- Improve data integrity and file-operation error handling.
- Expand contact fields and introduce additional search options.

## Repository Contents

- "main.c" — Main program entry point and menu control.
- "addressbook.c" — Address book operation implementations.
- "addressbook.h" — Header declarations for the address book module.


*Project:* Address Book Management System  
*Language:* C  
*Focus:* Structured Programming, Functions, and File Handling
