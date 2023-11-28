
#include "Library.h"

Library::Library() : nextUserID(1){}

// increment everytime attached with C
std::string Library::getNextUserID() {
    std::string userID = "U" + std::to_string(nextUserID);
    nextUserID++;
    return userID;
}

void Library::addUser(const std::string& username, const std::string& userID) {
    Users newUser(username, userID);
    usersList.push_back(newUser);
}

void Library::displayUserbyName(const std::string& username) {
    for (const Users& user : usersList) {
        if (username == user.getUsername()) {
            std::cout << "--------------" << std::endl;
            std::cout << "Username: " << user.getUsername() << std::endl;
            std::cout << "UserID: " << user.getUserID() << std::endl;
            std::cout << "--------------" << std::endl;
        }
    }
}

void Library::displayUserbyID(const std::string& id) {
    for (const Users& user : usersList) {
        if (id == user.getUserID()) {
            std::cout << "--------------" << std::endl;
            std::cout << "Username: " << user.getUsername() << std::endl;
            std::cout << "UserID: " << user.getUserID() << std::endl;
            std::cout << "--------------" << std::endl;
        }
    }
}

void Library::displayAllUser() {
    for (const Users& user : usersList) {
        user.printuser();
    }
}

//adding book vector
void Library::addBook(const Book& book) {
    books.push_back(book);
}

//adding cd vector
void Library::addCD(const CD& cd) {
    cds.push_back(cd);
}


void Library::retrieveBook(const std::string bookTitle)
{
    for(const auto& book : books)
    {
        if(book.getTitle() == bookTitle)
        {
            std::cout << book.getTitle() << " exists" << std::endl;

            std::string itemId = book.getId();
            std::string itemTitle;
            std::string bookAuthor;
            int bookPages;
            bool isAvailable;
//            book.addHistoryEntry(itemId, itemTitle, bookAuthor, bookPages, isAvailable);
            break;
        }
    }
}


void Library::showAvailableBooks() const {
    std::cout << "Available books:" << std::endl;
    for(const auto& book : books) {
        std::cout << "Id: " << book.getId() << std::endl;
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Pages: " << book.getpage() << std::endl;
        std::cout << std::endl;
    }
}


void Library::printBooks() const {
    for (const auto& book : books) {
        book.print();
    }
}

void Library::printCD() const {
    for (const auto& cd : cds) {
        cd.print();
    }
}

Users Library::checkuser(const string entered){
    for(const Users& user : usersList)
    {
        if (entered == user.getUsername() || entered == user.getUserID()) {
            return user;
        }
        else{
            return Users();
        }
    }
}