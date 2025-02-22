#pragma once
#include "Book.h"
#include <vector>
#include <iostream>
//#include "Member.h"
using namespace std;

class Collection
{
private:
	int ID;
	string name;
	vector <Book*> bookListCollection;
public:
	Collection();
	Collection(int, string);
	~Collection();

	void setID(int id);
	int getID();

	void setName(string name);
	string getName();

	void displayCollection();
	friend class Guest;
	friend class Member;
	friend class Admin;
	friend class Library;
	friend class User;
};
