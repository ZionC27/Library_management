#ifndef LIBRARY_MANAGEMENT_USERS_H
#define LIBRARY_MANAGEMENT_USERS_H
#include <iostream>
#include <string>
#include <vector>


class Users {
private:
    std::string username;
    std::string userID;
//vector
    std::vector<Users> usersList;

public:
    Users();
    Users(std::string uname, std::string UID);
    void createUsers(std::string username, std::string userID);
    void displayUser(std::string username);
    std::string getUsername();
    std::string getuserID();

};

#endif