#pragma once
#include "binaryTree.h"

class Menu
{
public:
    Menu();
    void userMenu();
    void convertFormat(string inputFile);
	void Insert_Adresses_From_File(binaryTree& BT);
	void Insert_Adresses_From_User(binaryTree& BT);
	void Search(binaryTree& BT);
	void Print(binaryTree& BT);
    void Height(binaryTree& BT);
private:
    binaryTree BT;
    string houseNumber;
    string streetName;
    string City;
    string State;
    string zipCode;
    string blank;
    string searchKey;
    string choice;
    bool Quit;
};

