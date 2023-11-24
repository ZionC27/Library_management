#ifndef USERS_H
#define USERS_H

#include <string>
#include "Book.h"

class Users {
private:
    std::string username;
    std::string userID;

public:
    Users();
    Users(const std::string& uname, const std::string& UID);

    std::string getUsername() const;
    std::string getUserID() const;
};

#endif // USERS_H
