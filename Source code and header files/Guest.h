#pragma once
#include "User.h"
#include "Library.h"
#include "Collection.h"
class Guest :
	public User
{
private:
	int tempID;
	vector<Collection*> subscribedCollection;
	vector<bool>subscribeStatus;
public:
	static int temppID;
	Guest();
	Guest(int);
	~Guest();
	void subscribe();
	void read(string title, Library* l);
	void read(int ID, Library* l);
};

