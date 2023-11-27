
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

void Library::displayUser(const std::string& username) {
    for (const Users& user : usersList) {
        if (username == user.getUsername()) {
            std::cout << "--------------" << std::endl;
            std::cout << "Username: " << user.getUsername() << std::endl;
            std::cout << "UserID: " << user.getUserID() << std::endl;
            std::cout << "--------------" << std::endl;
        }
    }
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addCD(const CD& cd) {
    cds.push_back(cd);
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