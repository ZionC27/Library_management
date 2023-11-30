//
// Created by minim on 2023/11/27.
//
#include "history.h"

// Constructor
history::history() {}

// Function to add a record of adding an item to history
void history::addItem(const std::string& itemId, const std::string& itemType, bool availability, const std::string& date) {
    Record* newRecord = new Record{itemId, itemType, availability, date};
    historyList.push_back(newRecord);
}

// Function to display the history log
void history::displayHistory() const {
    for (const auto& recordPtr : historyList) {
        std::cout << "Item ID: " << recordPtr->itemId << ", Item Type: " << recordPtr->itemType
                  << ", Availability: " << (recordPtr->availability ? "Available" : "Unavailable")
                  << ", Date: " << recordPtr->date << std::endl;
    }
}

// Destructor
history::~history() {
    for (auto& recordPtr : historyList) {
        delete recordPtr; // Deallocate memory for each Record
    }
}