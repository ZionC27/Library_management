//
// Created by zion2 on 2023-11-20.
//
#include <iostream>
#include "item.h"

using namespace std;

item::item() {
    id = ""; // Default id
    title = ""; // Default title
    availability = false; // Default availability
    date = "";
}

// Parameterized constructor
item::item(string itemId, const std::string& itemTitle, bool isAvailable, const std::string itemDate) {
    id = itemId;
    title = itemTitle;
    availability = isAvailable;
    date = itemDate;
}

item::~item() {

}

string item::getId() const {
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


std::string item::getDate() const
{
    return date;
}

void item::print() const {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
}
