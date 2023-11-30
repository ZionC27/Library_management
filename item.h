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
    string id;
    string title;
    bool availability;
    string date;

public:
    // Constructors
    item(); // Default constructor
    item(string itemId, const string& itemTitle, bool isAvailable, const string itemDate);

    // Destructor
    ~item(); // Destructor declaration

    // Accessors and mutators (getters and setters)
    string getId() const;
    void setId(int itemId);

    string getTitle() const;
    void setTitle(const string& itemTitle);

    bool getAvailability() const;
    void setAvailability(bool isAvailable);
    string getDate() const;

    virtual void print() const;
    virtual void showDetails() const = 0;
};

#endif //LIBRARY_MANAGEMENT_ITEM_H
