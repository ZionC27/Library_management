
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Users.h"
#include <vector>
#include <iostream>

class Library {
private:
    std::vector<Users> usersList;
    int nextUserID;

public:
    Library();
    std::string getNextUserID();
    void addUser(const std::string& username, const std::string& userID);
    void displayUser(const std::string& username);
};

#endif // LIBRARY_H