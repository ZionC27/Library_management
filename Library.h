
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Users.h"
#include <vector>
#include <iostream>
#include "Book.h"
#include "CD.h"

class Library {
private:
//    vectors
    std::vector<Users> usersList;
    std::vector<Book> books; // Vector to store Book objects
    std::vector<CD> cds;
    int nextUserID;

public:
    Library();
    std::string getNextUserID();
    void addUser(const std::string& username, const std::string& userID);
    void displayUserbyName(const std::string& username);
    void addBook(const Book& book);
    void addCD(const CD& cd);
    void printBooks() const;
    void printCD() const;
    void retrieveBook(const std::string book);
    void showAvailableBooks() const;

    void displayAllUser();

    void displayUserbyID(const string &id);
};

#endif // LIBRARY_H