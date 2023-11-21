//
// Created by zion2 on 2023-11-20.
//

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

}

std::string item::getTitle() const {
    return title;
}

void item::setTitle(const string &itemTitle) {

}

bool item::getAvailability() const {
    return availability;
}

void item::setAvailability(bool isAvailable) {

}
