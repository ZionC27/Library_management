#include <iostream>
#include <string>
#include "Users.h"
#include "Library.h"

void getUsers(Library& library) {
    std::string username, userID;
    std::cout << "Please enter your name: ";
    std::cin >> username;
    std::cout << "Enter userID: ";
    std::cin >> userID;
    library.addUser(username, userID);
}

int main() {
    Library library;

    getUsers(library);
    getUsers(library);

    library.displayUser("ken"); // Assuming you want to display user "John"

    return 0;
}