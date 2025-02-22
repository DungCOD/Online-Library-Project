#include "Member.h"

Member::Member() : RegisteredUser()
{
	start = "";
	end = "";
}

Member::Member(string s, string e, string u, string p, string f, int ph) : RegisteredUser(u, p, f, ph, MEMBER)
{
	start = s;
	end = e;
}

Member::Member(string s, string e, string u, string p, string f, int ph, int id) : RegisteredUser(u, p, f, ph, id, MEMBER)
{
	start = s;
	end = e;
}

Member::~Member() {
	for (int i = 0; i < borrowedBooks.size(); i++) {
		if (borrowedBooks[i]) delete borrowedBooks[i];
	}
	borrowedBooks.clear();
	for (int i = 0; i < subscribedList.size(); i++) {
		if (subscribedList[i]) delete subscribedList[i];
	}
	subscribedList.clear();
	subscribeStatusList.clear();
}

void Member::setStart(string s)
{
	start = s;
}

string Member::getStart()
{
	return start;
}

void Member::setEnd(string e)
{
	end = e;
}

string Member::getEnd()
{
	return end;
}

void Member::borrowBook(Book* b, Library* l) {
	bool bookFound = false;
	for (int i = 0; i < l->bookList.size(); i++) {
		if (l->bookList[i]->getSerialNumber() == b->getSerialNumber()) {
			borrowedBooks.push_back(b);
			bookFound = true;
			cout << "Book with serial number " << b->getSerialNumber() << " is successfully borrowed." << endl;
		}
	}
	if (!bookFound) {

		cout << "The book with serial number " << b->getSerialNumber() << " not found in the library" << endl;
	}
}

void Member::returnBook(Book* b) {
	bool bookFound = false;
	for (int i = 0; i < borrowedBooks.size(); i++) {
		if (borrowedBooks[i]->getSerialNumber() == b->getSerialNumber()) {
			bookFound = true;
			borrowedBooks.erase(borrowedBooks.begin() + i);
			cout << "Book with serial number " << b->getSerialNumber() << " is successfully returned" << endl;
			break;
		}
	}
	if (!bookFound) {
		cout << "Error: Book not found in borrowed books list." << endl;
		return;
	}
}

void Member::subscribe(Collection* collection) {
	for (int i = 0; i < subscribedList.size(); i++) {
		if (subscribedList[i]->getID() == collection->getID()) {
			subscribeStatusList[i] = true;
			cout << "User has already subscribed to this collection" << endl;
			return; 
		}
	}
	subscribedList.push_back(collection);
	subscribeStatusList.push_back(true);
	cout << "Subscribe successfully" << endl;
}

void Member::unsubscribe(Collection* collection) {
	for (int i = 0; i < subscribedList.size(); i++) {
		if (subscribedList[i]->getID() == collection->getID()) {
			subscribedList.erase(subscribedList.begin() + i);
			subscribeStatusList.erase(subscribeStatusList.begin() + i);
			cout << "Unsubscribe successfully!" << endl;
			return;
		}
	}
}

string Member::getUsername()
{
	return RegisteredUser::getUsername();
}

string Member::getPassword()
{
	return RegisteredUser::getPassword();
}

void Member::showInfo() {
	cout << "Start membership: " << getStart() << endl;
	cout << "End membership: " << getEnd() << endl;
	cout << "Fullname: " << getFullname() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Phone: " << getPhone() << endl;
}

bool Member::isSubscribed(Collection* c) {
	for (int i = 0; i < subscribedList.size();i++) {
		if (subscribedList[i]->getID() == c->getID() && subscribeStatusList[i] == true) {
			cout << "User is subscribed to this collection! " << endl;
			return true;
			break;
		}
	}
	cout << "User is not subscribed to this collection! " << endl;
	return false;
}

vector <Collection*> Member::getSubscribedList() {
	return subscribedList;
}





