
#include "Users.h"

Users::Users() {}

Users::Users(const std::string& uname, const std::string& UID) : username(uname), userID(UID) {}

std::string Users::getUsername() const {
    return username;
}

std::string Users::getUserID() const {
    return userID;
}

void Users::setUsername(const string &uname) {
    username = uname;
}

void Users::setUserID(const string &UID) {
    userID = UID;
}

