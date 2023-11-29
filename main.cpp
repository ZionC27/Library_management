#include <iostream>
#include <string>
#include <limits>
#include "Users.h"
#include "Library.h"
#include "CD.h"

using namespace std;

void createUsers(Library& library) {
    std::string username, userID;
    std::cout << "Please enter your name:";
    std::cin >> username;
    userID = library.getNextUserID();
    library.addUser(username, userID);
    library.displayUserbyName(username);
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

int actions() {
    int action_number;
    bool validInput = false;

    while (!validInput) {
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Do you want to create an account?" << endl;
        cout << "2. Do you want to borrow a book?" << endl;
        cout << "3. Do you want to return a book?" << endl;
        cout << "4. Do you want to see borrowing and returning history of your account?" << endl;
        cout << "5. Do you want to exit?" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter action number: " << endl;

        cin >> action_number;

        if (action_number >= 1 && action_number <= 5) {
            validInput = true;
        } else {
            cout << "Please enter a number between 1 and 5." << endl;
            // Clear the input buffer to prevent an infinite loop in case of non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return action_number;
}

int main() {


    Library l;
    l.addUser("a", "1");
    l.addUser("b", "2");
    l.addUser("c", "3");
    l.addUser("d", "4");

    // tester for check user
    Users acsessuser = l.checkuser("c");
//    if (acsessuser.getUsername().empty()){
//        cout << "No such user " << endl;
//    }
//    else{
//        cout << acsessuser.getUsername() << endl;
//    }
//    Users acsessuser2 = l.checkuser("a");
//    if (acsessuser2.getUsername().empty()){
//        cout << "No such user " << endl;
//    }
//    else{
//        cout << acsessuser.getUsername() << endl;
//    }




    //  class tester
    Users u("asdas", "123");
    u.printuser();
    item* first = new Book("12", "firstBook", "firstAuthor", 120, true);


    item* second = new Book("2", "secondBook", "secondAuthor", 120, true);


    CD c("131","asdf", "dasdas",134, false);


    Library library;
    std::string option;

    library.addBook(first);
    library.addBook(second);


    int act = 0;
    string bookName;

    while (act != 5) {
        act = actions();
        std::cout << "Action chosen is: " << act << std::endl;

        switch (act) {
            case 1:
                createUsers(library);
                break;
            case 2: {
                std::string userInput;
                std::cout << "What is your ID or name? " << std::endl;
                std::cin >> userInput;
                Users accessedUser  = l.checkuser(userInput);
                //print name and id
                accessedUser.printuser();
                if (accessedUser.getUsername().empty()) {
                    std::cout << "No such user" << std::endl;
                } else {
                    accessedUser.printuser();
                    std::cout << "Select which book you want to borrow" << std::endl;
                    library.showAvailableBooks();
                    std::string bookName;
                    std::cout << "Enter the book name: " << std::endl;
                    std::cin >> bookName;
//                    library.retrieveBook(bookName);
                }
                break;
            }
            case 3:
                std::cout << "You entered 3" << std::endl;
                break;
            case 4:
                std::cout << "You entered 4" << std::endl;
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid input or out of range" << std::endl;
                break;
        }
    }

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