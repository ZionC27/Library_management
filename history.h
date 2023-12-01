//
// Created by minim on 2023/11/27.
//

#ifndef LIBRARY_MANAGEMENT_HISTORY_H
#define LIBRARY_MANAGEMENT_HISTORY_H
#include <vector>
#include <string>
#include <iostream> // Include necessary header for cout


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
    history();

    void addItem(const std::string username, const std::string& itemId, const std::string& itemType, bool availability, const std::string& date);

    std::vector<Record*> searchItemsById(const std::string& searchId) const;

    void displayRecords(const std::vector<Record*>& records) const;

    ~history();
};

#endif //LIBRARY_MANAGEMENT_HISTORY_H