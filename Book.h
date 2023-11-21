//
// Created by zion2 on 2023-11-20.
//

#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H
#include "Item.h" // Include the base class header

using namespace std;

class Book : public item {
private:
    string author;
    int pages;

public:
    // Constructors
    Book(); // Default constructor
    Book(int itemId, const std::string& itemTitle, const std::string& bookAuthor, int bookPages, bool isAvailable);


    // Accessors and mutators (getters and setters) for author
    std::string getAuthor() const;
    void setAuthor(const std::string& bookAuthor);
};

#endif //LIBRARY_MANAGEMENT_BOOK_H
