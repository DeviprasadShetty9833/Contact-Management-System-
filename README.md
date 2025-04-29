# Contact-Management-System-
<br> 
<br> Author: Deviprasad Shetty
<br> 

# Overview
<br> 
<br> This is a simple yet effective Contact Management System built in C, focusing on practical use of File Handling.
<br> The system allows users to manage a contact list — add, view, delete contacts — while ensuring data is stored persistently in a file.
<br> 
<br> Additionally, it implements an Undo Last Deletion feature using a temporary backup mechanism to restore accidentally deleted contacts.
<br> 

# Key Features
<br> 
<br> 1. Add Contact
<br> Add new contacts (Name, Phone Number, Email, etc.) to the system.
<br> The contact data is saved persistently using text/binary file storage.
<br> 
<br> 2. View Contacts
<br> Display all saved contacts by reading from the file.
<br> Ensures that the latest state of the contact list is shown.
<br> 
<br> 3. Delete Contact
<br> Remove a contact based on a unique identifier (like name or phone number).
<br> Updates the file after deletion to maintain consistency.
<br> 
<br> 4. Undo Last Deleted Contact
<br> Before any delete operation, the deleted contact is temporarily stored.
<br> Allows restoring the last deleted contact with a simple undo operation.
<br> 

# Concepts Used
<br> 
<br> Programming Language: C (Standard C99)

<br> Core Concepts:
<br> File Handling (fopen, fread, fwrite, fseek, fprintf, fscanf)
<br> Temporary backup for Undo functionality
<br> Command Line Interface (CLI)
<br> Dynamic Memory Management (malloc, free)
<br> 

# File Format:
<br> Text File (.txt) or Binary File (.bin) for storing contact information persistently.

