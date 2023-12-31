#ifndef USERS_H
#define USERS_H

#include <string>
#include "Book.h"

using namespace std;

class Users {
private:
    string username;
    string userID;

public:
    //Constructors
    Users();
    Users(const string& uname, const string& UID);

    // Getter and setter
    string getUsername() const;
    void setUsername(const string& uname);

    string getUserID() const;
    void setUserID(const string& UID);

    void printuser() const;
};

#endif // USERS_H
