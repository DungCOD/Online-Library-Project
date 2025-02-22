#pragma once
#include "User.h"
#include "Library.h"
#include <iostream>
using namespace std;

class RegisteredUser : public User
{
private:
	string username;
	string password;
	string fullname;
	int phone;
public:
	RegisteredUser();
	RegisteredUser(string, string, string, int, aType);
	RegisteredUser(string, string, string, int, int, aType);
	~RegisteredUser();
	void setUsername(string);
	virtual string getUsername();
	void setPassword(string);
	virtual string getPassword();
	void setFullname(string);
	string getFullname();
	void setPhone(int);
	int getPhone();
	void read(string title, Library* l);
	void read(int ID, Library* l);
};
