#include <fstream>
#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Menu::Menu() 
{
    Quit = false;
}

void Menu::userMenu()
{
    while (!Quit) {
        cout << "\nPlaese choose an option from the list:\n" <<
            "1. Insert address's from a text file\n" <<
            "2. Insert a single address\n" <<
            "3. Search for an address in database\n" <<
            "4. Print all address's to a text file\n" <<
            "5. Find the height of the tree\n" <<
            "6. Quit program\n";
        getline(cin, choice);
        bool letterInput = false;
        for (int i = 0; i < choice.length(); i++) {
            if (isalpha(choice[i])) {
                letterInput = true;
            }
        }
        if (letterInput) {
            choice = "0";
        }
        switch (stoi(choice))
        {
        case 1:
            Insert_Adresses_From_File(BT);
            break;
        case 2:
            Insert_Adresses_From_User(BT);
            break;
        case 3:
            Search(BT);
            break;
        case 4:
            Print(BT);
            break;
        case 5:
            Height(BT);
            break;
        case 6:
            Quit = true;
            break;
        default:
            cout << "Invalid choice, please enter the number of the option you want\n";
            break;
        }
    }
}

void Menu::convertFormat(string inputFile)
{
    ifstream din;
    din.open(inputFile);
    ofstream dout;
    dout.open("address.txt");
    if (!din.fail()) {
        string number;
        string street;
        string city;
        string state;
        string zip;

        while (din >> number)
        {
            getline(din, street);
            int pos = 0;
            while (pos < street.length() && street[pos] == ' ')
                pos++;
            street = street.substr(pos);

            getline(din, city);
            pos = city.find(", ");
            if (pos > 0)
            {
                state = city.substr(pos + 2);
                city.erase(pos);
                pos = state.find(' ');
                if (pos > 0)
                {
                    zip = state.substr(pos + 1);
                    state.erase(pos);
                }
            }

            dout << number << endl;
            dout << street << endl;
            dout << city << endl;
            dout << state << endl;
            dout << zip << endl;
            dout << endl;
        }
    }
    else {
        cout << "File was not able to be opened\n";
    }

    din.close();
    dout.close();
}

void Menu::Insert_Adresses_From_File(binaryTree& BT) 
{
    string inputFile = "";
    int count = 1;
    cout << "Enter the name of the file you would like to input:\n" <<
        "File format must be:\n" <<
        "Street Number Street Name\n" <<
        "City, State Zip code\n" <<
        "ex:\n" <<
        "1234 Example Ave.\n" <<
        "Dallas, TX 12345\n";
    getline(cin, inputFile);
    convertFormat(inputFile);
    ifstream din;
    din.open("address.txt");
    if (!din.fail()) {
        cout << "Inserting from a file...\n";
        while (!din.eof()) {
            getline(din, houseNumber);
            getline(din, streetName);
            getline(din, City);
            getline(din, State);
            getline(din, zipCode);
            searchKey = streetName + City + houseNumber;
            if (isdigit(houseNumber[0])) {
                BT.Insert(stoi(houseNumber), streetName, City, State, stoi(zipCode), searchKey);
            }
            getline(din, blank);
        }
        cout << "Done!\n";
    }
    else {
        cout << "File was not able to be opened\n";
    }
    din.close();
}

void Menu::Insert_Adresses_From_User(binaryTree& BT) 
{
    cout << "To enter a single address, plaese enter the following information:\n";
    cout << "What is the house number?\n";
    getline(cin, houseNumber);
    cout << "What is the street name?\n";
    getline(cin, streetName);
    cout << "What is the city?\n";
    getline(cin, City);
    cout << "What is the state? (use abbreviation ex: Texas is TX)\n";
    getline(cin, State);
    cout << "What is the zip code?\n";
    getline(cin, zipCode);
    searchKey = streetName + City + houseNumber;
    BT.Insert(stoi(houseNumber), streetName, City, State, stoi(zipCode), searchKey);
    cout << "Done!\n";
}

void Menu::Search(binaryTree& BT)
{
    cout << "To search for an address, plaese enter the following information:\n";
    cout << "What is the house number?\n";
    getline(cin, houseNumber);
    cout << "What is the street name?\n";
    getline(cin, streetName);
    cout << "What is the city?\n";
    getline(cin, City);
    searchKey = streetName + City + houseNumber;
    if (BT.Search(searchKey)) {
        cout << "FOUND!\n";
    }
    else {
        cout << "NOT FOUND!\n";
    }
}

void Menu::Print(binaryTree& BT)
{
    cout << "Printing to sorted_address.txt...\n";
    BT.Print();
    cout << "Done!\n";
}

void Menu::Height(binaryTree& BT)
{
    cout << "The height of the tree is:\n" <<
        BT.findHeight() << endl;
}

