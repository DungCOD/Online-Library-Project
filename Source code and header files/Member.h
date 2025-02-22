#pragma once
#include "Library.h"
#include "Collection.h"
#include "RegisteredUser.h"

class Member : public RegisteredUser
{
private:
	string start;
	string end;
	vector<Book*> borrowedBooks;
	vector<Collection*> subscribedList;
	vector<bool> subscribeStatusList;
public:
	Member();
	Member(string, string, string, string, string, int);
	Member(string, string, string, string, string, int, int);
	~Member();
	void setStart(string s);
	string getStart();
	void setEnd(string e);
	string getEnd();

	// Member's specific
	void borrowBook(Book* b, Library* l);
	void returnBook(Book* b);
	void unsubscribe(Collection *c); // subscribe to a collection
	void subscribe(Collection *c); // unsubscribe to a collection

	bool isSubscribed(Collection* c);
	void showInfo();
	string getUsername();
	string getPassword();
	vector<Collection*> getSubscribedList();
	void showSubscribedList();
};