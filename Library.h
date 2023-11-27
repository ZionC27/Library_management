
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Users.h"
#include <vector>
#include <iostream>
#include "Book.h"
#include "CD.h"

class Library {
private:
    std::vector<Users> usersList;
    std::vector<Book> books; // Vector to store Book objects
    std::vector<CD> cds;
    int nextUserID;

public:
    Library();
    std::string getNextUserID();
    void addUser(const std::string& username, const std::string& userID);
    void displayUser(const std::string& username);
    void addBook(const Book& book);
    void addCD(const CD& cd);
    void printBooks() const;
    void printCD() const;
};

#endif // LIBRARY_H