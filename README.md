
Library Management System Overview

 Purpose
This C++ program is designed to manage a library system. It includes functionalities for administrators and members to handle books, borrowings, and member information. The program uses a console-based interface for user interaction.

 Key Components

1. Data Structures
   - Structs: The program defines several structures (`structs`) to represent the different entities in the library system.
     - `Admin`: Represents an administrator with fields for ID, name, password, and a pointer to the next admin.
     - `Book`: Represents a book with fields for book ID, name, author, year, subject, category, and a pointer to the next book.
     - `Borrowing`: Represents a borrowing record with fields for borrowing ID, member ID, book ID, date, duration, fine, and a pointer to the next borrowing.
     - `Member`: Represents a library member with fields for member ID, name, membership type, date, expire date, a pointer to borrowings, and a pointer to the next member.

2. Linked Lists
   - The program uses linked lists to manage collections of admins, books, borrowings, and members. Each list is tracked by a head pointer (`adminHead`, `bookHead`, `memberHead`, `borrowingHead`).

 Main Functionalities

1. Login and Portal Navigation
   - Login Function: Allows users to log in as either an admin or a member and navigates them to the respective portal.
   - Admin Portal: Provides admin-specific functionalities like adding books, borrowings, members, viewing books, members, borrowings, searching books and members, and deleting books, members, and borrowings.
   - Member Portal: Provides member-specific functionalities like viewing borrowed books and viewing their profile.

2. CRUD Operations
   - Add Operations: Functions to add new books, borrowings, and members to their respective linked lists.
   - View Operations: Functions to view all books, members, and borrowings.
   - Search Operations: Functions to search for specific books and members by their IDs.
   - Delete Operations: Functions to delete books, members, and borrowings from their respective linked lists.

3. Utility Functions
   - Get Book by ID: A helper function to retrieve a book from the list by its ID, used in viewing borrowed books.
   - View Borrowed Books: Allows members to see which books they have borrowed.
   - View Profile: Allows members to view their profile information.

 Program Flow
- The program starts with a login prompt where users choose to log in as either an admin or a member.
- Based on the login choice, the user is directed to the respective portal.
- In the admin portal, various management tasks can be performed, while in the member portal, users can view their borrowed books and profile.
- The program continues in a loop, allowing multiple operations until it is terminated.

