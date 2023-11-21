//
// Created by zion2 on 2023-11-20.
//

#include "Book.h"

using namespace std;
// Default constructor
Book::Book() : item() {
    author = ""; // Default author
    int pages = 0;
}

// Parameterized constructor
Book::Book(int itemId, const std::string& itemTitle, const std::string& bookAuthor, int bookPages, bool isAvailable)
        : item(itemId, itemTitle, isAvailable) {
    author = bookAuthor;
    pages = bookPages;
}

// Getter and setter implementations for author
string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string& bookAuthor) {
    author = bookAuthor;
}