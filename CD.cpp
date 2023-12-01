//
// Created by zion2 on 2023-11-27.
//

#include "CD.h"
#include <iostream>

using namespace std;


CD::CD(): item()  {
    director = "";
    runtime = 0;
}

CD::CD(string itemId, const string &itemTitle, const string &CDDirector, int CDRuntime, bool isAvailable, const string itemDate)
        : item(itemId, itemTitle, isAvailable, itemDate) {
    director = CDDirector;
    runtime = CDRuntime;
}

CD::~CD() {

}

string CD::getDirector() const {
    return std::string();
}

void CD::setDirector(const string &CDDirector) {
    director = CDDirector;
}

string CD::getruntime() const {
    return std::string();
}

void CD::setruntime(const int &CDRuntime) {
    runtime = CDRuntime;
}

void CD::print() const {
    item::print();
    cout << "Director: " << director << endl;
    cout << "Runtime: " << runtime << endl;
    cout << endl;
}

void CD::showDetails() const {
    std::cout << "CD Details:" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Date: " << getDate() << std::endl;
    std::cout << (getAvailability() ? "Available" : "Unavailable") << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Runtime: " << runtime << std::endl;
    std::cout << std::endl;
}

void CD::availableItems() const {
    std::cout << "CD Title: " << getTitle() << std::endl;
    bool result = getAvailability();

    // Print "available" if result is true, otherwise print "unavailable"
    std::cout << (result ? "Available" : "Unavailable") << std::endl;
}