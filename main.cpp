#include <iostream>
#include <string>
#include "Users.h" // Assuming Users class declaration is in Users.h
using namespace std;

void getUsers(Users& users) {
    string username, userID;
    cout << "Please put your name: ";
    cin >> username;
    cout << "Enter userID: ";
    cin >> userID;
    users.createUsers(username, userID);
}

int main() {
    Users users;
    getUsers(users);
    getUsers(users);
    users.displayUser("zion");
    return 0;
}