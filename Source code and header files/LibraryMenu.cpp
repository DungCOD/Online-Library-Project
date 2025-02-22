#include "LibraryMenu.h"

LibraryMenu::LibraryMenu()
{
	name = "";
	description = "";
	action = -1;
	subMenu.clear();
}

LibraryMenu::LibraryMenu(string name, string description, int action)
{
	this->name = name;
	this->description = description;
	this->action = action;
	subMenu.clear();
}

LibraryMenu::~LibraryMenu()
{
	if (subMenu.size() > 0) {
		for (int i = 0; i < subMenu.size(); i++) {
			if (subMenu[i]) delete subMenu[i];
		}
		subMenu.clear();
	}
}

string LibraryMenu::getName()
{
	return this->name;
}

void LibraryMenu::setName(string s)
{
	this->name = s;
}

string LibraryMenu::getDescription() {
	return this->description;
}
void LibraryMenu::setDescription(string description) {
	this->description = description;
}

int LibraryMenu::getAction()
{
	return action;
}

void LibraryMenu::setAction(int a)
{
	this->action = a;
}

void LibraryMenu::addSubMenu(LibraryMenu* m)
{
	this->subMenu.push_back(m);
	m->subMenu.push_back(this);
}

LibraryMenu* LibraryMenu::getSubMenu(int index)
{
	if (index >= 0 && index < subMenu.size())
		return subMenu[index];
	else
		return nullptr;
}

void LibraryMenu::displayMenu()
{
	//system("cls");
	cout << endl;
	cout << "=====" << this->name << "=====" << endl;
	cout << getDescription() << endl;
	for (int i = 0; i < subMenu.size(); i++) {
		cout << i + 1 << ". " << subMenu[i]->getName() << endl;
	}
}

int LibraryMenu::pickOption()
{
	while (true) {
		cout << "Pick an Option: ";
		int opt;
		cin >> opt;
		try {
			if (cin.fail()) {
				throw "Invalid input";
			}
			else if (opt < 1 || opt > subMenu.size()) {
				throw "Out of range";
			}
			else {
				return opt;
			}
		}
		catch (const char* mess) {
			cin.clear();
			cin.ignore();
			cout << "Error: " << mess << endl;
		}
	}
}
