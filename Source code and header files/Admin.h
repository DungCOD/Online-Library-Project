#pragma once
#include "Library.h"
#include "RegisteredUser.h"
#include "Collection.h"

class Admin : public RegisteredUser
{
private:

public:
	Admin();
	Admin(string u, string p, string f, int ph);
	Admin(string u, string p, string f, int ph, int id);
	
	void addBook(Book* b, Library* l);
	void showBook(Book* b);
	void hideBook(Book* b);
	void removeBook(Book* b, Library *l);
	void addBookToCollection(Book* b, Collection* c, Library* l);
	void removeBookFromCollection(Book* b, Collection* c);
	void addCollection(Collection* c, Library *l); // add a Collection to the Library
	void removeCollection(Collection* c, Library *l); // remove a Collection from the Library

	void editBook(Book* b);
	void editCollection(Collection* c);

	void showInfo();
		
	string getUsername();
	string getPassword();
};

