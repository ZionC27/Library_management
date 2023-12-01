//
// Created by minim on 2023/11/27.
//
#include "history.h"


history::history() {}


void history::addItem(const std::string username, const std::string& itemId, const std::string& itemType, bool availability, const std::string& date) {
    Record* newRecord = new Record{username, itemId, itemType, availability, date};
    historyList.push_back(newRecord);
}

std::vector<history::Record*> history::searchItemsById(const std::string& searchId) const {
    std::vector<Record*> foundRecords;
    for (const auto& recordPtr : historyList) {
        if (recordPtr->username == searchId) {
            foundRecords.push_back(recordPtr);
        }
    }
    return foundRecords;
}

void history::displayRecords(const std::vector<Record*>& records) const {
    if (records.empty()) {
        std::cout << "No records found for the given itemId." << std::endl;
    } else {
        std::cout << "Records found for the given itemId:" << std::endl;
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