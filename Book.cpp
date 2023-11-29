//
// Created by zion2 on 2023-11-20.
//

#include "Book.h"
#include <iostream>

using namespace std;
// Default constructor
Book::Book() : item() {
    title = "";
    author = ""; // Default author
    int pages = 0;
}

// Parameterized constructor
Book::Book(string itemId, const std::string& itemTitle, const std::string& bookAuthor, int bookPages, bool isAvailable, const string itemDate)
        : item(itemId, itemTitle, isAvailable,itemDate), pages(bookPages){
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
