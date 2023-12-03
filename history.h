//
// Created by minim on 2023/11/27.
//

#ifndef LIBRARY_MANAGEMENT_HISTORY_H
#define LIBRARY_MANAGEMENT_HISTORY_H
#include <vector>
#include <string>
#include <iostream> // Include necessary header for cout
using namespace std;

class history {
public:
    struct Record {
        std::string username;
        std::string itemId;
        std::string itemType;
        bool availability;
        std::string date;
    };

private:
    std::vector<Record*> historyList; // Store pointers to Record objects

public:
    // Constructors / Deconstructor
    history();
    ~history();
    void addItem(const std::string username, const std::string& itemId, const std::string& itemType, bool availability, const std::string& date);
    // to get all borrowed item from a user
    vector<Record*> searchItemsByUsername(const std::string& searchId) const;
    // display all borrow and return records
    void displayRecords(const std::vector<Record*>& records) const;

};

#endif //LIBRARY_MANAGEMENT_HISTORY_H