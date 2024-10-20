#include <iostream>
#include <vector>
#include <string>

class Book {
private:
std::string title;
std::string author;
public:
Book(std::string t, std::string a) : title(t), author(a) {}
std::string getTitle() { return title; }
std::string getAuthor() { return author; }
};

class User {
private:
std::string ID;
public:
User(std::string id) : ID(id) {}
std::string getID() { return ID; }
    virtual void borrowBook(Book* book) = 0;
};

class Librarian : public User {
public:
Librarian(std::string id) : User(id) {}
    void borrowBook(Book* book) override {
std::cout<< "Borrowing book: " << book->getTitle() << " by " << book->getAuthor() <<std::endl;
    }
};

class Library {
private:
std::vector<Book> books;
public:
    void addBook(Book book) {
books.push_back(book);
    }
    Book* searchBook(std::string title) {
for(auto& book : books) {
            if(book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
};

intmain() {
    Library library;
    Librarian librarian("L001");

intnumBooks;
std::cout<< "How many books would you like to add? ";
std::cin>>numBooks;
std::cin.ignore();  // Ignore newline character after entering the number

    for (inti = 0; i<numBooks; ++i) {
std::string title, author;
std::cout<< "Enter title of book " <<i + 1 << ": ";
std::getline(std::cin, title);
std::cout<< "Enter author of book " <<i + 1 << ": ";
std::getline(std::cin, author);
library.addBook(Book(title, author));
    }

std::string searchTitle;
std::cout<< "Enter the title of the book you want to search: ";
std::getline(std::cin, searchTitle);

    Book* foundBook = library.searchBook(searchTitle);
    if (foundBook != nullptr) {
librarian.borrowBook(foundBook);
    } else {
std::cout<< "Book not found" <<std::endl;
    }

    return 0;
}
