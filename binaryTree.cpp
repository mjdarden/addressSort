#include <fstream>
#include <iostream>
#include <string>
#include "binaryTree.h"
using namespace std;

binaryTree::binaryTree()
{
	Root = NULL;
}

void binaryTree::DestroyHelper(Node* Tree)
{
	if (Tree != NULL)
	{
		DestroyHelper(Tree->Left);
		DestroyHelper(Tree->Right);
		delete Tree;
	}
}

binaryTree::~binaryTree()
{
	DestroyHelper(Root);
}

bool binaryTree::SearchHelper(string SearchKey, Node* Tree)
{
	if (Tree == NULL) {
		return false;
	}
	if (Tree->searchKey == SearchKey) {
		return true;
	}
	if (Tree->searchKey > SearchKey) {
		SearchHelper(SearchKey, Tree->Left);
	}
	else {
		SearchHelper(SearchKey, Tree->Right);
	}
}

bool binaryTree::Search(string SearchKey)
{
	return SearchHelper(SearchKey, Root);
}

bool binaryTree::InsertHelper(
	int HouseNumber, 
	string StreetName, 
	string City, 
	string State, 
	int ZipCode,
	string SearchKey,
	Node*& Tree)
{
	if (Tree == NULL)
	{
		Tree = new Node;
		Tree->houseNumber = HouseNumber;
		Tree->streetName = StreetName;
		Tree->city = City;
		Tree->state = State;
		Tree->zipCode = ZipCode;
		Tree->searchKey = SearchKey;
		Tree->Left = NULL;
		Tree->Right = NULL;
		return true;
	}

	else if (Tree->searchKey > SearchKey)
		return (InsertHelper(
			HouseNumber,
			StreetName,
			City,
			State,
			ZipCode,
			SearchKey,
			Tree->Left));
	else
		return (InsertHelper(
			HouseNumber,
			StreetName,
			City,
			State,
			ZipCode,
			SearchKey,
			Tree->Right));
}

bool binaryTree::Insert(
	int HouseNumber,
	string StreetName,
	string City,
	string State,
	int ZipCode,
	string SearchKey)
{
	return InsertHelper(
		HouseNumber,
		StreetName,
		City,
		State,
		ZipCode,
		SearchKey,
		Root);
}

void binaryTree::PrintHelper(Node* Tree)
{
	if (Tree != NULL)
	{
		PrintHelper(Tree->Left);
		dout <<
			Tree->houseNumber << " " <<
			Tree->streetName << endl <<
			Tree->city << ", " <<
			Tree->state << " " <<
			Tree->zipCode << endl;
		PrintHelper(Tree->Right);
	}
}

void binaryTree::Print()
{
	dout.open("sorted_address.txt");
	PrintHelper(Root);
	dout.close();
}

int binaryTree::findHeightHelper(Node* Tree) 
{
	if (Tree == NULL) {
		return 0;
	}
	else {
		int leftDepth = findHeightHelper(Tree->Left);
		int rightDepth = findHeightHelper(Tree->Right);
		if (leftDepth > rightDepth) {
			return leftDepth + 1;
		}
		else {
			return rightDepth + 1;
		}
	}
}

int binaryTree::findHeight()
{
	return findHeightHelper(Root);
}
