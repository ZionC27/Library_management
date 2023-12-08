//
// Created by zion2 on 2023-11-20.
//

#include "Book.h"
#include <iostream>

using namespace std;
// Default constructor
Book::Book() : item() {

    author = ""; // Default author
    int pages = 0;
}

// Parameterized constructor
Book::Book(string itemId, const std::string& itemTitle, const std::string& bookAuthor, int bookPages, bool isAvailable, const string itemDate)
        : item(itemId, itemTitle, isAvailable,itemDate), author(bookAuthor), pages(bookPages){
}

Book::~Book() {}



// Getter and setter implementations for author
string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string& bookAuthor) {
    author = bookAuthor;
}

int Book::getpage() const {
    return pages;
}

void Book::setpage(const int &page) {
    pages = page;
}


void Book::print() const {
    item::print();
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
    cout << endl;
}

//override the showDetails function from Item
void Book::showDetails() const {
    std::cout << "Book Details:" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Date: " << getDate() << std::endl;
    std::cout << "Availability: " << (getAvailability() ? "Available" : "Unavailable") << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Pages: " << pages << std::endl;
    std::cout << std::endl;
}

//override the availableItems function from Item
void Book::availableItems() const {
    std::cout << "Book Title: " << getTitle();
    bool result = getAvailability();

    // Print "available" if result is true, otherwise print "unavailable"
    std::cout << (result ? "(Available)" : "(Unavailable)") << std::endl;
}
