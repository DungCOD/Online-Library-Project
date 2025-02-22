#ifndef LIBRARYMENU_H
#define LIBRARYMENU_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LibraryMenu
{
private:
	string name;
	string description;
	vector<LibraryMenu*> subMenu;
	int action;
public:
	LibraryMenu();
	LibraryMenu(string name, string description, int action = -1);
	~LibraryMenu();

	string getName();
	void setName(string s);

	string getDescription();
	void setDescription(string);

	int getAction();
	void setAction(int a);

	void addSubMenu(LibraryMenu* m);
	LibraryMenu* getSubMenu(int index);

	void displayMenu();
	int pickOption();
};


#endif