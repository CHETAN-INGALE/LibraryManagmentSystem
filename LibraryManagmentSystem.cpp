#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    bool available;

    Book() : bookId(0), title(""), author(""), available(true) {}

    Book(int id, const string& t, const string& a) : bookId(id), title(t), author(a), available(true) {}
};

class Member {
public:
    int memberId;
    string name;

    Member() : memberId(0), name("") {}

    Member(int id, const string& n) : memberId(id), name(n) {}
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    static const int MAX_MEMBERS = 100;

    Book books[MAX_BOOKS];
    Member members[MAX_MEMBERS];
    int bookCount;
    int memberCount;

public:
    Library() : bookCount(0), memberCount(0) {}

    void addBook(int bookId, const string& title, const string& author) {
        if (bookCount < MAX_BOOKS) {
            Book book(bookId, title, author);
            books[bookCount++] = book;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Maximum book capacity reached!" << endl;
        }
    }

    void addMember(int memberId, const string& name) {
        if (memberCount < MAX_MEMBERS) {
            Member member(memberId, name);
            members[memberCount++] = member;
            cout << "Member added successfully!" << endl;
        } else {
            cout << "Maximum member capacity reached!" << endl;
        }
    }

    void issueBook(int bookId, int memberId) {
        Book* book = findBook(bookId);
        Member* member = findMember(memberId);

        if (book && member) {
            if (book->available) {
                book->available = false;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Book is not available." << endl;
            }
        } else {
            cout << "Invalid book or member ID." << endl;
        }
    }

    void returnBook(int bookId) {
        Book* book = findBook(bookId);

        if (book) {
            if (!book->available) {
                book->available = true;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book is already available." << endl;
            }
        } else {
            cout << "Invalid book ID." << endl;
        }
    }

    void generateReport() {
        cout << "---- Books ----" << endl;
        for (int i = 0; i < bookCount; ++i) {
            const Book& book = books[i];
            cout << "Book ID: " << book.bookId << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Availability: " << (book.available ? "Available" : "Issued") << endl;
            cout << endl;
        }

        cout << "---- Members ----" << endl;
        for (int i = 0; i < memberCount; ++i) {
            const Member& member = members[i];
            cout << "Member ID: " << member.memberId << endl;
            cout << "Name: " << member.name << endl;
            cout << endl;
        }
    }

private:
    Book* findBook(int bookId) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].bookId == bookId) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Member* findMember(int memberId) {
        for (int i = 0; i < memberCount; ++i) {
            if (members[i].memberId == memberId) {
                return &members[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;

    cout << "Welcome to the Library Management System!" << endl;

    while (true) {
        cout << "\nPlease select an option:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Add a member" << endl;
        cout << "3. Issue a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Generate report" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            int bookId;
            string title, author;

            cout << "Enter book ID: ";
            cin >> bookId;
            cin.ignore();

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter book author: ";
            getline(cin, author);

            library.addBook(bookId, title, author);
        } else if (choice == 2) {
            int memberId;
            string name;

            cout << "Enter member ID: ";
            cin >> memberId;
            cin.ignore();

            cout << "Enter member name: ";
            getline(cin, name);

            library.addMember(memberId, name);
        } else if (choice == 3) {
            int bookId, memberId;

            cout << "Enter book ID: ";
            cin >> bookId;

            cout << "Enter member ID: ";
            cin >> memberId;

            library.issueBook(bookId, memberId);
        } else if (choice == 4) {
            int bookId;

            cout << "Enter book ID: ";
            cin >> bookId;

            library.returnBook(bookId);
        } else if (choice == 5) {
            library.generateReport();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Thank you for using the Library Management System. Goodbye!" << endl;

    return 0;
}
