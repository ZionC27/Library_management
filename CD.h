//
// Created by zion2 on 2023-11-27.
//

#ifndef LIBRARY_MANAGEMENT_CD_H
#define LIBRARY_MANAGEMENT_CD_H
#include "Item.h" // Include the base class header
#include <iostream>

using namespace std;


class CD : public item {
private:
    string director;
    int runtime;

public:
    // Constructors
    CD(); // Default constructor
    CD(string itemId, const string &itemTitle, const string &CDDirector, int CDRuntime, bool isAvailable, const string itemDate);
    ~CD();

    // Accessors and mutators (getters and setters) for author
    string getDirector() const;
    void setDirector(const string& CDDirector);

    string getruntime() const;
    void setruntime(const int& CDRuntime);

    // functions that override item class function
    void print() const override;
    void showDetails() const override;
    void availableItems() const override;
};


#endif //LIBRARY_MANAGEMENT_CD_H
