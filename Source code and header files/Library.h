#pragma once
#include "Book.h"
#include "Collection.h"
#include "vector"
using namespace std;

class Member;

class Library
{
private:
	vector <Book*> bookList;
	vector <Collection*> collectionList;	
	static Collection* sampleCollection;
public:
	Library();
	~Library();
	void addBook(Book *b); // Only use for testing

	void initializeSampleCollection();

	void displayAllBooks();
	void displaySampleCollection();
	Collection* getSampleCollection()  {
		initializeSampleCollection();
		return sampleCollection;
	}
	friend class User;
	friend class Collection;
	friend class Member;
	friend class Admin;
	friend class Guest;
	friend class RegisteredUser;
	friend class UserManager;

	// Function to search
	Book* searchByTitle(string title);
	Book* searchBySerial(int serial);
	Book* searchByTitleSample(string title);
	Book* searchBySerialSample(int serial);
	Collection* searchCollectionByID(int ID);
};

