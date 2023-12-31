//
// Created by zion2 on 2023-11-20.
//

#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H
#include "Item.h" // Include the base class header
#include <iostream>

using namespace std;

class Book : public item {
private:
    string author;
    int pages;

public:
    // Constructors
    Book(); // Default constructor
    Book(string itemId, const string& itemTitle, const string& bookAuthor, int bookPages, bool isAvailable, const string itemDate);
    ~Book();


    // Accessors and mutators (getters and setters) for author and page
    string getAuthor() const;
    void setAuthor(const string& bookAuthor);

    int getpage() const;
    void setpage(const int& page);

    // functions that override item class function
    void print() const override;
    void availableItems() const override;
    void showDetails() const override;

};

#endif //LIBRARY_MANAGEMENT_BOOK_H
