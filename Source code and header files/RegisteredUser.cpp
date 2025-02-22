#include "RegisteredUser.h"

RegisteredUser::RegisteredUser() {
	username = " ";
	password = " ";
	fullname = " ";
	phone = 0;
}

RegisteredUser::RegisteredUser(string u, string p, string f, int ph, aType aL) : User(aL) {
	username = u;
	password = p;
	fullname = f;
	phone = ph;
}

RegisteredUser::RegisteredUser(string u, string p, string f, int ph, int id, aType aL) : User(id, aL) {
	username = u;
	password = p;
	fullname = f;
	phone = ph;
}

RegisteredUser::~RegisteredUser() {

}

void RegisteredUser::setUsername(string u) {
	username = u;
}

string RegisteredUser::getUsername() {
	return username;
}

void RegisteredUser::setPassword(string p) {
	password = p;
}

string RegisteredUser::getPassword() {
	return password;
}

void RegisteredUser::setFullname(string f) {
	fullname = f;
}

string RegisteredUser::getFullname() {
	return fullname;
}

void RegisteredUser::setPhone(int ph) {
	phone = ph;
}

int RegisteredUser::getPhone() {
	return phone;
}

void RegisteredUser::read(string title, Library* l) {
	if (l->searchByTitle(title)->getVisibility() == 0) {
		cout << "Book is hidden, can't read" << endl;
	}
	else {
		cout << "Reading book named " << l->searchByTitle(title)->getTitle() << "..." << endl;
	}
}

void RegisteredUser::read(int ID, Library* l) {
	if (l->searchBySerial(ID)->getVisibility() == 0) {
		cout << "Book is hidden, can't read" << endl;
	}
	else {
		cout << "Reading book with serial number " << l->searchBySerial(ID)->getSerialNumber() << "..." << endl;
	}
}

