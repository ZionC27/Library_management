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

item::item(int itemId, const std::string &itemTitle, bool isAvailable) {

}

item::~item() {

}

int item::getId() const {
    return 0;
}

void item::setId(int itemId) {

}

std::string item::getTitle() const {
    return string();
}

void item::setTitle(const string &itemTitle) {

}

bool item::getAvailability() const {
    return false;
}

void item::setAvailability(bool isAvailable) {

}
