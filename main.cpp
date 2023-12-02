#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
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


int actions() {
    int action_number;
    bool validInput = false;

    while (!validInput) {
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Do you want to create an account?" << endl;
        cout << "2. Do you want to borrow a book or CD?" << endl;
        cout << "3. Do you want to return a book or CD?" << endl;
        cout << "4 Do you want to see item details?" << endl;
        cout << "5. Do you want to see borrowing and returning history of your account?" << endl;
        cout << "6. Do you want to exit?" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter action number: " << endl;

        cin >> action_number;

        if (action_number >= 1 && action_number <= 6) {
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

std::string currentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Function to check if a user exists and print their details
std::string checkAndPrintUser(Library& library) {
    std::string userInput;
    std::cout << "What is your ID or name? " << std::endl;
    std::cin >> userInput;

    Users accessedUser = library.checkuser(userInput);
    std::string username = accessedUser.getUsername();
    if (!username.empty()) {
        accessedUser.printuser();
        return username; // Return username if user is found
    } else {
        std::cout << "No such user" << std::endl;
        return ""; // Return empty string if user is not found
    }
}



int main() {
    Library library;
    library.addUser("a", "1");
    library.addUser("b", "2");
    library.addUser("c", "3");
    library.addUser("d", "4");

    // tester for check user
    Users acsessuser = library.checkuser("c");
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
    std::string date = currentDate();
    item* first = new Book("12", "firstBook", "firstAuthor", 120, true, date);
    item* second = new Book("2", "secondBook", "secondAuthor", 100, true, date);
    item* third = new CD("2", "ThirdCD", "CDDirector", 111, true, date);



    library.addBook(first);
    library.addBook(second);
    library.addBook(third);

    int act = 0;
    string bookName;

    while (act != 6) {
        act = actions();
        std::cout << "Action chosen is: " << act << std::endl;

        switch (act) {
            case 1:
                createUsers(library);
                break;
            case 2: {
                std::string username = checkAndPrintUser(library);
                if(username == ""){
                } else {
                    std::string selection;
                    selection = library.borrowSelection();
                    library.showAvailableItems(selection);
                    std::string bookName;
                    std::cout << "Enter the item name: " << std::endl;
                    std::cin >> bookName;
                    library.borrowItem(bookName,username);
                }
                break;
            }
            case 3:{
                string username = checkAndPrintUser(library);
                if (username == ""){}
                else {
                    cout << "Enter the item ID: " << std::endl;
                    string ItemId;
                    cin >> ItemId;
                    library.returnItem(ItemId, username);
                }
                break;
            }

            case 4: {
                std::string selection;
                selection = library.borrowSelection();
                library.showItemDetails(selection);
                break;
            }
            case 5: {
                std::string username;
                username = checkAndPrintUser(library);
                if(username == ""){
                }
                else{
                    library.userHistory(username);
                }
                break;
            }
            case 6:
                std::cout << "Exit..." << std::endl;
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