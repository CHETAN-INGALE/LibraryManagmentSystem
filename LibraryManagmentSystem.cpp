#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    bool available;

    Book(int id, string t, string a) : bookId(id), title(t), author(a), available(true) {}
};

class Member {
public:
    int memberId;
    string name;

    Member(int id, string n) : memberId(id), name(n) {}
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(int bookId, string title, string author) {
        Book book(bookId, title, author);
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    void addMember(int memberId, string name) {
        Member member(memberId, name);
        members.push_back(member);
        cout << "Member added successfully!" << endl;
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
        for (const auto& book : books) {
            cout << "Book ID: " << book.bookId << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Availability: " << (book.available ? "Available" : "Issued") << endl;
            cout << endl;
        }

        cout << "---- Members ----" << endl;
        for (const auto& member : members) {
            cout << "Member ID: " << member.memberId << endl;
            cout << "Name: " << member.name << endl;
            cout << endl;
        }
    }

private:
    Book* findBook(int bookId) {
        for (auto& book : books) {
            if (book.bookId == bookId) {
                return &book;
            }
        }
        return nullptr;
    }

    Member* findMember(int memberId) {
        for (auto& member : members) {
            if (member.memberId == memberId) {
                return &member;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library;

    library.addBook(1, "Applied Mathematics 1", "G.V. Kumbhojkar");
    library.addBook(2, "Engineering physics 2", "I. A. Saikh");
    library.addBook(3, "XII Computer Science Bifocal", "R. D. Supekar");

    library.addMember(1, "Himanshu Bhangale");
    library.addMember(2, "Chetan Ingale");

    library.issueBook(1, 1);
    library.issueBook(3, 2);

    library.returnBook(3);

    library.generateReport();

    return 0;
}
