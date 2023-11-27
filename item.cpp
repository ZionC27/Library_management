//
// Created by zion2 on 2023-11-20.
//
#include <iostream>
#include "item.h"

using namespace std;

item::item() {
    id = 0; // Default id
    title = ""; // Default title
    availability = false; // Default availability
}

// Parameterized constructor
item::item(int itemId, const std::string& itemTitle, bool isAvailable) {
    id = itemId;
    title = itemTitle;
    availability = isAvailable;
}

item::~item() {

}



int item::getId() const {
    return id;
}

void item::setId(int itemId) {
    id = itemId;
}

std::string item::getTitle() const {
    return title;
}

void item::setTitle(const string &itemTitle) {
    title = itemTitle;
}

bool item::getAvailability() const {
    return availability;
}

void item::setAvailability(bool isAvailable) {
    availability = isAvailable;
}

void item::print() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
}
