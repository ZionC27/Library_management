
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
void Library::addBook(item* bookPtr) {
    items.push_back(bookPtr);
}

//adding cd vector
void Library::addCD(const CD& cd) {
    cds.push_back(cd);
}


void Library::borrowBook(const std::string bookTitle)
{
    bool bookFound = false;
//    auto is showing item class in this case.
    for(const auto& itemPtr: items)
    {
        if(itemPtr->getTitle() == bookTitle)
        {
            std::cout << "You are borrowing " << itemPtr->getTitle();
            bookFound = true;
            itemPtr->setAvailability(false);
            bool result = itemPtr->getAvailability();
            std::cout << (result ? "Available" : "Unavailable") << std::endl;

//            itemPtr->setAvailability()
//            std::string itemId = book.getId();
//            std::string itemTitle;
//            std::string bookAuthor;
//            int bookPages;
//            bool isAvailable;
//            book.addHistoryEntry(itemId, itemTitle, bookAuthor, bookPages, isAvailable);
            break;
        }
    }
    if(!bookFound) {
        std::cout << bookTitle << " doesn't exists" << std::endl;
    }

}


void Library::showAvailableBooks() const {
    std::cout << "Available books:" << std::endl;
    for(const auto& itemPtr : items) {
        std::cout << "Id: " << itemPtr -> getId() << std::endl;
        std::cout << "Title: " << itemPtr->getTitle() << std::endl;
        std::cout << itemPtr->getDate() << std::endl;
        bool result = itemPtr->getAvailability();

        // Print "available" if result is true, otherwise print "unavailable"
        std::cout << (result ? "Available" : "Unavailable") << std::endl;
        Book* bookPtr = dynamic_cast<Book *>(itemPtr);
        if(bookPtr != nullptr){
            std::cout << "Author: " << bookPtr->getAuthor() << std::endl;
            std::cout << "Pages: " << bookPtr->getpage() << std::endl;
            std::cout << std::endl;
        }
    }
}


//void Library::printBooks() const {
//    for (const auto& book : books) {
//        book.print();
//    }
//}

void Library::printCD() const {
    for (const auto& cd : cds) {
        cd.print();
    }
}



Users Library::checkuser(const string entered) {
    for (const Users& user : usersList) {
        if (entered == user.getUsername() || entered == user.getUserID()) {
            return user;  // Return the user if found
        }
    }
    return Users();  // Return an empty Users object if no match is found
}