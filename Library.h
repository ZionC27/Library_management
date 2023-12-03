
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Users.h"
#include <vector>
#include <iostream>
#include "Book.h"
#include "CD.h"
#include "history.h"

class Library {
private:
//    vectors
    std::vector<Users> usersList;
    std::vector<item*> items; // Vector to store Book objects
    std::vector<CD> cds;
    int nextUserID;
    history history;


public:
    // Constructor and Deconstructor
    Library();
    ~Library();
    std::string getNextUserID();
    // To add new user
    void addUser(const std::string& username, const std::string& userID);
    // get user info by with username
    void displayUserbyName(const std::string& username);
    void addItem(item* bookPtr);
    void addCD(const CD& cd);
    // void printBooks() const;
    void printCD() const;
    // to ask Which one do you want to select? Book or CD
    std::string borrowSelection()const;
    // to perform the borrow action
    void borrowItem(const std::string book, const std::string username);
    // to show borrow and return history
    void userHistory(std::string username) const;
    // to show available item to borrow
    void showAvailableItems(std::string selection) const;
    // show all items and the details
    void showItemDetails(std::string selection) const;

    void displayAllUser();

    void displayUserbyID(const string &id);
    Users checkuser(const string entered);
    // to perform returning of items
    void returnItem(const string itemId, const string username);

};

#endif // LIBRARY_H