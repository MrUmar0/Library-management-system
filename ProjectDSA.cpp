#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
struct Admin {
  int admin_id;
  string name;
  string password;
  Admin* next;
};

struct Book {
  int book_id;
  string name;
  string author;
  int year;
  string subject;
  string category;
  Book* next;
};

struct Borrowing {
  int borrowing_id;
  int member_id;
  int book_id;
  string date;
  int duration;
  float fine;
  Borrowing* next;
};
struct Member {
  int member_id;
  string name;
  string membership_type;
  string date;
  string expire_date;
  Borrowing* borrowing; 
  Member* next;
};


// Linked List Heads
Admin* adminHead = NULL;
Book* bookHead = NULL;
Member* memberHead = NULL;
Borrowing* borrowingHead = NULL;

// Functions
void login();
void adminPortal();
void addBook();
void addBorrowing();
void addMember();
void memberPortal();
void viewBooks();
void viewMembers();
void viewBorrowings();
void searchBook();
void searchMember();
void deleteBook();
void deleteMember();
void deleteBorrowing();
void viewProfile();
void viewBorrowedBooks();
int main() {
  A: system("cls");
  login();
  
  int aa;
  cin>>aa;
  goto A;
  return 0;
}

void login() {
  cout << "Login as:\n1. Admin\n2. Member\n";
  int choice;
  cin >> choice;
  if (choice == 1) {
    adminPortal();
  } else if (choice == 2) {
    memberPortal();
  }
}

void adminPortal() {
  cout << "Admin Portal\n";
  cout << "1. Add Book\n2. Add Borrowing\n3. Add Member\n4. View Books\n5. View Members\n6. View Borrowings\n7. Search Book\n8. Search Member\n9. Delete Book\n10. Delete Member\n11. Delete Borrowing\n";
  int choice;
  cin >> choice;
  if (choice == 1) {
    addBook();
  } else if (choice == 2) {
    addBorrowing();
  } else if (choice == 3) {
    addMember();
  } else if (choice == 4) {
    viewBooks();
  } else if (choice == 5) {
    viewMembers();
  } else if (choice == 6) {
    viewBorrowings();
  } else if (choice == 7) {
    searchBook();
  } else if (choice == 8) {
    searchMember();
  } else if (choice == 9) {
    deleteBook();
  } else if (choice == 10) {
    deleteMember();
  } else if (choice == 11) {
    deleteBorrowing();
  }
}

void addBook() {
  Book* newBook = new Book();
  cout << "Enter book name: ";
  cin >> newBook->name;
  cout << "Enter author name: ";
  cin >> newBook->author;
  cout << "Enter year: ";
  cin >> newBook->year;
  cout << "Enter subject: ";
  cin >> newBook->subject;
  cout << "Enter category: ";
  cin >> newBook->category;
  newBook->next = bookHead;
  bookHead = newBook;
}

void addBorrowing() {
  Borrowing* newBorrowing = new Borrowing();
  cout << "Enter member ID: ";
  cin >> newBorrowing->member_id;
  cout << "Enter book ID: ";
  cin >> newBorrowing->book_id;
  cout << "Enter date: ";
  cin >> newBorrowing->date;
  cout << "Enter duration: ";
  cin >> newBorrowing->duration;
  newBorrowing->next = borrowingHead;
  borrowingHead = newBorrowing;
}

void addMember() {
  Member* newMember = new Member();
  cout << "Enter member name: ";
  cin >> newMember->name;
  cout << "Enter membership type: ";
  cin >> newMember->membership_type;
  cout << "Enter date: ";
  cin >> newMember->date;
  cout << "Enter expire date: ";
  cin >> newMember->expire_date;
  newMember->next = memberHead;
  memberHead = newMember;
}

void memberPortal() {
  cout << "Member Portal\n";
  cout << "1. View Borrowed Books\n2. View Profile\n";
  int choice;
  cin >> choice;
  if (choice == 1) {
   viewBorrowedBooks();    // View borrowed books logic
  } else if (choice == 2) {
    viewProfile();
  }
}


void viewBooks() {
  Book* current = bookHead;
  while (current != NULL) {
    cout << "Book ID: " << current->book_id << endl;
    cout << "Book Name: " << current->name << endl;
    cout << "Author: " << current->author << endl;
    cout << "Year: " << current->year << endl;
    cout << "Subject: " << current->subject << endl;
    cout << "Category: " << current->category << endl;
    current = current->next;
  }
}

void viewMembers() {
  Member* current = memberHead;
  while (current != NULL) {
    cout << "Member ID: " << current->member_id << endl;
    cout << "Member Name: " << current->name << endl;
    cout << "Membership Type: " << current->membership_type << endl;
    cout << "Date: " << current->date << endl;
    cout << "Expire Date: " << current->expire_date << endl;
    current = current->next;
  }
}

void viewBorrowings() {
  Borrowing* current = borrowingHead;
  while (current != NULL) {
    cout << "Borrowing ID: " << current->borrowing_id << endl;
    cout << "Member ID: " << current->member_id << endl;
    cout << "Book ID: " << current->book_id << endl;
    cout << "Date: " << current->date << endl;
    cout << "Duration: " << current->duration << endl;
    cout << "Fine: " << current->fine << endl;
    current = current->next;
  }
}

void searchBook() {
  int book_id;
  cout << "Enter book ID: ";
  cin >> book_id;
  Book* current = bookHead;
  while (current != NULL) {
    if (current->book_id == book_id) {
      cout << "Book Found!" << endl;
      cout << "Book Name: " << current->name << endl;
      cout << "Author: " << current->author << endl;
      cout << "Year: " << current->year << endl;
      cout << "Subject: " << current->subject << endl;
      cout << "Category: " << current->category << endl;
      return;
    }
    current = current->next;
  }
  cout << "Book not found!" << endl;
}

void searchMember() {
  int member_id;
  cout << "Enter member ID: ";
  cin >> member_id;
  Member* current = memberHead;
  while (current != NULL) {
    if (current->member_id == member_id) {
      cout << "Member Found!" << endl;
      cout << "Member Name: " << current->name << endl;
      cout << "Membership Type: " << current->membership_type << endl;
      cout << "Date: " << current->date << endl;
      cout << "Expire Date: " << current->expire_date << endl;
      return;
    }
    current = current->next;
  }
  cout << "Member not found!" << endl;
}

void deleteBook() {
  int book_id;
  cout << "Enter book ID: ";
  cin >> book_id;
  Book* current = bookHead;
  Book* previous = NULL;
  while (current != NULL) {
    if (current->book_id == book_id) {
      if (previous == NULL) {
        bookHead = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      cout << "Book deleted!" << endl;
      return;
    }
    previous = current;
    current = current->next;
  }
  cout << "Book not found!" << endl;
}

void deleteMember() {
  int member_id;
  cout << "Enter member ID: ";
  cin >> member_id;
  Member* current = memberHead;
  Member* previous = NULL;
  while (current != NULL) {
    if (current->member_id == member_id) {
      if (previous == NULL) {
        memberHead = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      cout << "Member deleted!" << endl;
      return;
    }
    previous = current;
    current = current->next;
  }
  cout << "Member not found!" << endl;
}

Book* getBookById(int book_id) {
  Book* current = bookHead;
  while (current != NULL) {
    if (current->book_id == book_id) {
      return current;
    }
    current = current->next;
  }
  return NULL; // Book not found
}


void deleteBorrowing() {
  int borrowing_id;
  cout << "Enter borrowing ID: ";
  cin >> borrowing_id;
  Borrowing* current = borrowingHead;
  Borrowing* previous = NULL;
  while (current != NULL) {
    if (current->borrowing_id == borrowing_id) {
      if (previous == NULL) {
        borrowingHead = current->next;
      } else {
        previous->next = current->next;
      }
      delete current;
      cout << "Borrowing deleted!" << endl;
      return;
    }
    previous = current;
    current = current->next;
  }
  cout << "Borrowing not found!" << endl;
}

void viewBorrowedBooks() {
  Member* current = memberHead;
  while (current != NULL) {
    Borrowing* borrowing = current->borrowing;
    while (borrowing != NULL) {
      Book* book = getBookById(borrowing->book_id);
      if (book != NULL) {
        cout << "Book Name: " << book->name << endl;
        cout << "Author: " << book->author << endl;
        cout << "Year: " << book->year << endl;
        cout << "Subject: " << book->subject << endl;
        cout << "Category: " << book->category << endl;
      }
      borrowing = borrowing->next;
    }
    current = current->next;
  }
}


void viewProfile() {
  Member* current = memberHead;
  while (current != NULL) {
    cout << "Member Name: " << current->name << endl;
    cout << "Membership Type: " << current->membership_type << endl;
    cout << "Date: " << current->date << endl;
    cout << "Expire Date: " << current->expire_date << endl;
    current = current->next;
  }
}