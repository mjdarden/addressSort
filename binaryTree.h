#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int houseNumber;
	string streetName;
	string city;
	string state;
	int zipCode;
	string searchKey;
	Node* Left;
	Node* Right;
};
class binaryTree
{
public:
	// Constructor functions
	binaryTree();
	~binaryTree();

	// General binary tree operations
	bool Search(string SearchKey);
	bool Insert(
		int HouseNumber, 
		string StreetName, 
		string City, 
		string State, 
		int ZipCode,
		string SearchKey);
	void Print();
	int findHeight();

private:
	// Helper functions
	void DestroyHelper(Node* Tree);
	bool SearchHelper(string SearchKey, Node* Tree);
	bool InsertHelper(
		int HouseNumber,
		string StreetName,
		string City,
		string State,
		int ZipCode,
		string SearchKey,
		Node*& Tree);
	void PrintHelper(Node* Tree);
	int findHeightHelper(Node* Tree);

	// Tree pointer
	Node* Root;
	ofstream dout;
};

