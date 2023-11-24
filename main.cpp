#include <iostream>
#include <string>
#include "Users.h"
#include "Library.h"

void createUsers(Library& library) {
    std::string username, userID;
    std::cout << "Please enter your name:";
    std::cin >> username;
    userID = library.getNextUserID();
    library.addUser(username, userID);
    library.displayUser(username);
}

//user prompt
bool continueCreatingAccounts(Library& library, std::string option) {
    do {
        std::cout << "Do you want to create an account(Create)" << std::endl;
        cin >> option;
        if (option != "Create" && option != "create") {
            return false;
        }
        createUsers(library);
    }while(true);
    return true;
}

int main() {
    Library library;
    std::string option;

    do {
        createUsers(library);
    } while (continueCreatingAccounts(library, option));

    return 0;
}

//Please put your name
//        (UserInput)Kenichi
//
//--------
//ID: U1
//        Username: Kenichi
//--------
//
//Do you want to update the existing account?
//Do you want to create an account?
//Do you want to borrow a book?
//Do you want to return a book?
//Do you want to see borrowing and returning history of your account?
//(YES/NO)
//
//
//(UserInput)Borrow
//
//        Which book do you want to borrow?
//1.	Book1
//2.	Book2
//3.	Book3
//4.	Book4
//5.	Book5
//6.	Book6
//7.	Book7
//8.	Book8
//9.	Book9
//10.	Book10
//
//(UserInput) 2
//
//You borrow Book2
//        Your returning date is 11/30
//
//
//
//Do you want to update the existing account?
//Do you want to create an account?
//Do you want to borrow a book?
//Do you want to return a book?
//Do you want to see borrowing and returning history of your account?
//(YES/NO)
//
//
//