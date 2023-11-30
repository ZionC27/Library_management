//
// Created by minim on 2023/11/27.
//

#ifndef LIBRARY_MANAGEMENT_HISTORY_H
#define LIBRARY_MANAGEMENT_HISTORY_H
#include <vector>
#include <string>
#include <iostream> // Include necessary header for cout

class history {
private:
    struct Record {
        std::string itemId;
        std::string itemType;
        bool availability;
        std::string date;
    };

    std::vector<Record*> historyList; // Vector of pointers to Record objects

public:
    // Constructor and destructor
    history(); // Constructor
    ~history(); // Destructor

    // Function to add a record of adding an item to history
    void addItem(const std::string& itemId, const std::string& itemType, bool availability, const std::string& date);

    // Function to display the history log
    void displayHistory() const;
};

#endif //LIBRARY_MANAGEMENT_HISTORY_H