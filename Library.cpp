
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

std::string Library::borrowSelection() const
{
    do
    {
        std::cout << "Which one do you want to select? Book or CD" << std::endl;
        std::string selection;
        cin >> selection;
        if (selection == "cd" || selection == "CD") {
            return "CD";
        } else if (selection == "book" || selection == "Book") {
            return "Book";
        }
        cout << "Invalid selection choose CD or Book again" << endl;
    } while(true);
}

void Library::borrowBook(const std::string bookTitle)
{
    bool bookFound = false;
//    auto is showing item class in this case.
    for(const auto& itemPtr: items)
    {
        if(itemPtr->getTitle() == bookTitle)
        {
            std::string itemID, itemType, itemDate;
            bool availability;
            itemID = itemPtr->getId();
            itemType = "Book";
            itemPtr->setAvailability(false);
            availability = itemPtr->getAvailability();
            itemDate = itemPtr->getDate();
            std::cout << "You are borrowing " << itemPtr->getTitle() << endl;
            bookFound = true;
            history.addItem(itemID, itemType, availability, itemDate);
            std::string id;
            cout << "select an id" << endl;
            cin >> id;
            std::vector<history::Record*> foundRecords = history.searchItemsById(id);
            history.displayRecords(foundRecords);
            break;
        }
    }
    if(!bookFound) {
        std::cout << bookTitle << " doesn't exists" << std::endl;
    }
}

void Library::showAvailableItems(std::string selection) const {
    std::cout << "Available items:" << std::endl;
    for (const auto &itemPtr: items) {
        if (selection == "CD") {
            if(CD *cdPtr = dynamic_cast<CD *>(itemPtr)) {
                cdPtr->availableItems();
            } else {
                continue;
            }

        } else if (selection == "Book") {
            if (auto bookPtr = dynamic_cast<Book *>(itemPtr)) {
                bookPtr->availableItems();
            } else {
                continue;
            }
        }
    }
}

//void Library::showAvailableBooks() const {
//    std::cout << "Available books:" << std::endl;
//    for(const auto& itemPtr : items) {
//        std::cout << "Id: " << itemPtr -> getId() << std::endl;
//        std::cout << "Title: " << itemPtr->getTitle() << std::endl;
//        std::cout << itemPtr->getDate() << std::endl;
//        bool result = itemPtr->getAvailability();
//
//        // Print "available" if result is true, otherwise print "unavailable"
//        std::cout << (result ? "Available" : "Unavailable") << std::endl;
//        Book* bookPtr = dynamic_cast<Book *>(itemPtr);
//        if(bookPtr != nullptr){
//            std::cout << "Author: " << bookPtr->getAuthor() << std::endl;
//            std::cout << "Pages: " << bookPtr->getpage() << std::endl;
//            std::cout << std::endl;
//        }
//    }
//}
//

void Library::showItemDetails(std::string selection) const {
    std::cout << "Available items:" << std::endl;
    for (const auto &itemPtr: items) {
        if (selection == "CD") {
            if(CD *cdPtr = dynamic_cast<CD *>(itemPtr)) {
                cdPtr->showDetails();
            } else {
                continue;
            }

        } else if (selection == "Book") {
            if (auto bookPtr = dynamic_cast<Book *>(itemPtr)) {
                bookPtr->showDetails();
            } else {
                continue;
            }
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