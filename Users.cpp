#include "Users.h"

using namespace std;

Users::Users(){}

Users::Users(string uname, string UID) : username(uname), userID(UID){}

void Users::createUsers(string username, string userID)
{
    Users newUser(username, userID);
    usersList.push_back(newUser);
}

void Users::displayUser(string username)
{
    for(Users& user : usersList)
    {
        if(username == user.getUsername())
        {
            cout << user.getUsername() << endl;
            cout << user.getuserID() << endl;
        }
    }
}

string Users::getUsername()
{
    return  username;
}

string Users::getuserID()
{
    return userID;
}

