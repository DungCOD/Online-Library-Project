#pragma once
#include "Book.h"
#include "Library.h"
#include <string>
#include <iostream>

enum aType {
	GUEST = 0,
	MEMBER = 1,
	ADMIN = 2,
};

class User
{
private:
	int ID;
	aType accessibilityLevel;
public:
	static int latestID;
	User();
	User(aType);
	User(int, aType);
	~User();
	void setID(int id);
	virtual int getID();
	void setAccessibilityLevel(aType aL);
	aType getAccessibilityLevel();
	virtual void read(string title, Library* l) = 0;
	virtual void read(int ID, Library* l) = 0;
};

