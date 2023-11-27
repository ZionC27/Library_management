//
// Created by zion2 on 2023-11-20.
//

#ifndef LIBRARY_MANAGEMENT_ITEM_H
#define LIBRARY_MANAGEMENT_ITEM_H

#include <string>
#include <iostream>

using namespace std;

class item {
private:
    int id;
    string title;
    bool availability;

public:
    // Constructors
    item(); // Default constructor
    item(int itemId, const string& itemTitle, bool isAvailable);

    // Destructor
    ~item(); // Destructor declaration

    // Accessors and mutators (getters and setters)
    int getId() const;
    void setId(int itemId);

    string getTitle() const;
    void setTitle(const string& itemTitle);

    bool getAvailability() const;
    void setAvailability(bool isAvailable);

    virtual void print() const;
};

#endif //LIBRARY_MANAGEMENT_ITEM_H
