//
// Created by minim on 2023/11/27.
//
#include "history.h"


history::history() {}

//adding Item to the historyList vector
void history::addItem(const std::string username, const std::string& itemId, const std::string& itemType, bool availability, const std::string& date) {
    Record* newRecord = new Record{username, itemId, itemType, availability, date};
    historyList.push_back(newRecord);
}

//searching item borrowed and returned history from username using pointer.
std::vector<history::Record*> history::searchItemsByUsername(const std::string& searchId) const {
    std::vector<Record*> foundRecords;
    for (const auto& recordPtr : historyList) {
        if (recordPtr->username == searchId) {
            foundRecords.push_back(recordPtr);
        }
    }
    return foundRecords;
}

//access members of a Book and CD class through a pointer.
void history::displayRecords(const std::vector<Record*>& records) const {
    if (records.empty()) {
        std::cout << "No records found for the given username." << std::endl;
    } else {
        std::cout << "Records found for the given username:" << std::endl;
        for (const auto& recordPtr : records) {
            std::cout << "Item ID: " << recordPtr->itemId << ", Item Type: " << recordPtr->itemType
                      << ", Availability: " << (recordPtr->availability ? "Available" : "Unavailable")
                      << ", Date: " << recordPtr->date << std::endl;
        }
    }
}

history::~history() {
    for (auto& recordPtr : historyList) {
        delete recordPtr; // Deallocate memory for each Record
    }
}