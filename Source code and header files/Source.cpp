	#include <iostream>
	#include <string>
	#include "Library.h"
	#include "User.h"
	#include "Collection.h"
	#include "Guest.h"
	#include "Admin.h"
	#include "Member.h"
	#include "Book.h"
	#include "UserManager.h"
	using namespace std;

	void guestMenu(Library* L, UserManager *UM)
	{
		while (true)
		{
			cout << endl;
			cout << "1. Search a book" << endl;
			cout << "2. Read a book from the sample collection" << endl;
			cout << "3. Subcribe as a new member" << endl;
			cout << "4. Log out" << endl;
			cout << "Your option: ";
			int option;
			cin >> option;

			string title;
			int serial;
			int answer;
			string fullname, username, password, startYear, endYear;
			int phone = 0;
			Guest* g = new Guest();
			Member* mem;
			Book* b = new Book();
			switch (option)
			{
			case 1:
				L->displayAllBooks();
				cout << "1. Search the book by title." << endl;
				cout << "2. Search the book by serial number." << endl;
				cout << "Your option: ";
				cin >> answer;
				if (answer == 1)
				{
					cout << "Enter title of the title: ";
					cin >> title;
					b = L->searchByTitle(title);
					if (b) { 
						cout << "Found the book with serial number: " << b->getTitle() << endl;
						b->display();
					}
				}
				else
				{
					cout << "Enter serial number of the book: ";
					cin >> serial;
					b = L->searchBySerial(serial);
					if (b) {
						cout << "Found the book with title: " << b->getSerialNumber() << endl;
						b->display();
					}
				}
				break;
			case 2:
				cout << "You are currently a guest. Therefore, you can only read books in the sample collection!" << endl;
				L->displaySampleCollection();
				cout << "Enter the title of the book that you want to read: ";
				cin >> title;
				b = L->searchByTitleSample(title);
				if (b) {
					g->read(title, L);
				}
				break;
			case 3:
				cout << "Registering as a new member....." << endl;
				cout << "Enter your new account's username: "; 
				cin >> username;
				cout << "Enter your new account's password: "; 
				cin >> password;
				cout << "Enter your fullname: "; 
				cin >> fullname;
				cout << "Enter your phone number: "; 
				cin >> phone;
				cout << "Enter your starting year of membership: "; 
				cin >> startYear;
				cout << "Enter your ending year of membership: "; 
				cin >> endYear;
				mem = new Member(startYear, endYear, username, password, fullname, phone);
				UM->addMember(mem);
				cout << "Register successfully!" << endl;
				return;
				break;
			case 4:
				return;
				break;
			}
		}
	}

	void memberMenu(Library* L, UserManager *UM) 
	{
		bool isLoginned = false;
		cout << "1. Register." << endl;
		cout << "2. Sign in." << endl;
		cout << "Your option: ";
		int option;
		cin >> option;
		if (option == 2)
		{
			isLoginned = UM->login();
			if (!isLoginned) return;
		}
		else if (option == 1)
		{
			UM->registerAsMember();
			cout << "Welcome to the library new member" << endl;
		}
		Member* currentMem = UM->getCurrentMember();
		while (currentMem) {
			cout << endl;
			cout << "1. Show member infomation" << endl;
			cout << "2. Borrow a book" << endl;
			cout << "3. Return a book" << endl;
			cout << "4. Subcribe to a collection" << endl;
			cout << "5. Unsubcribe to a collection" << endl;
			cout << "6. Choose a book to read" << endl;
			cout << "7. Ask for the list of book from a collection" << endl;
			cout << "8. Log out" << endl;
			cout << "Your option: ";
			int option;
			string titleBook;
			int serial;
			int IDC;
			Book* b;
			Collection* c;
			vector <Collection*> subList;

			bool isSub;
			cin >> option;
			switch (option) {
			case 1:
				currentMem->showInfo();
				break;
			case 2:
				cout << "Enter the name of the book that you want to borrow: ";
				cin >> titleBook;
				b = L->searchByTitle(titleBook);
				if (b) { 
					currentMem->borrowBook(b, L); 
				}
				break;
			case 3:
				cout << "Enter the title of the book to return: ";
				cin >> titleBook;
				b = L->searchByTitle(titleBook);
				if (b) {
					currentMem->returnBook(b);
				}
				break;
			case 4:
				cout << "Enter the ID of the collection to subcribe:";
				cin >> IDC;
				c = L->searchCollectionByID(IDC);
				if (c) {
					currentMem->subscribe(c);
				}
				break;
			case 5:
				cout << "Enter the ID of the collection to unsubcribe: ";
				cin >> IDC;
				c = L->searchCollectionByID(IDC);
				if (c) {
					currentMem->unsubscribe(c);
				}
				break;
			case 6:
				cout << "1. Search the book by serial number" << '\n';
				cout << "2. Search the book by title";
				cout << "Your option: ";
				int opt;
				cin >> opt;
				if (opt == 1)
				{
					cout << "Enter the serial number of the book that you want to read: ";
					cin >> serial;
					b = L->searchBySerial(serial);
					if (b) {
						currentMem->read(serial, L);
					}
				}
				else
				{
					cout << "Enter the title of the book that you want to read: ";
					cin >> titleBook;
					b = L->searchByTitle(titleBook);
					if (b) {
						currentMem->read(titleBook, L);
					}
				}
				break;
			case 7:
				cout << "Enter the ID of the collection to see the list of book of it: ";
				cin >> IDC;
				c = L->searchCollectionByID(IDC);
				isSub = currentMem->isSubscribed(c);
				if (c != nullptr && isSub == true) {
					c->displayCollection();
				}
				break;
			case 8:
				UM->logout();
				return;
			}
		}
	};

	void adminMenu(Library* L, UserManager* UM)
	{
		bool isLoggined = false;
		cout << "Welcome to the Admin Menu! There is only one account for an admin." << endl;
		cout << "If you enter username/password wrong 3 times. You will be shot to death by the laser in the system!" << endl;
		cout << "1. Sign in." << endl;
		cout << "Your option: ";
		int option;
		cin >> option;
		if (option == 1) {
			isLoggined = UM->login();
			if (!isLoggined) return;
		}
		else {
			cout << "Invalid option. Please try again!" << endl;
		}
		Admin* currentAd = UM->getCurrentAdmin();
		while (currentAd) {
			cout << endl;
			cout << "1. Show admin information" << endl;
			cout << "2. Edit a collection in library" << endl;
			cout << "3. Add a new collection to library" << endl;
			cout << "4. Remove an existed collection from library" << endl;
			cout << "5. Edit a book in library" << endl;
			cout << "6. Add a book to library" << endl;
			cout << "7. Remove a book from library" << endl;
			cout << "8. Read a book" << endl;
			cout << "9. Log out" << endl;
			cout << "Your option: ";
			int option;
			cin >> option;
			string name;
			int serialnum;
			int id;

			string title;
			Book* b = new Book();
			Collection* c = new Collection();
			switch (option) {
			case 1:
				currentAd->showInfo();
				break;
			case 2:
				cout << "Enter the ID of the collection in the library: ";
				cin >> id;
				c = L->searchCollectionByID(id);
				if (c) {
					currentAd->editCollection(c);
				}
				else {
					cout << "Collection not found in the library" << endl;
				}
			case 3:
				cout << "Enter the ID of the new collection in the library: ";
				cin >> id;
				cout << "Enter the name of the new collection in the library: ";
				cin >> name;
				c = new Collection(id, name);
				currentAd->addCollection(c, L);
				break;
			case 4:
				cout << "Enter the ID of collection to delete from the library: ";
				cin >> id;
				c = L->searchCollectionByID(id);
				if (c) {
					currentAd->removeCollection(c, L);
				}
				break;
			case 5:
				cout << "Enter the serial of the book to edit:";
				cin >> serialnum;
				b = L->searchBySerial(serialnum);
				if (b) {
					currentAd->editBook(b);
				}
				else {
					cout << "Book not found in the library!" << endl;
				}
				break;
			case 6:
				cout << "Enter the serial of the book to add into the library: ";
				cin >> serialnum;
				cout << "Enter the title of the book to add into the library: ";
				cin >> title;
				b = new Book(serialnum, title);
				currentAd->addBook(b, L);
				break;
			case 7:
				cout << "Enter the serial number of the book to remove from the library";
				cin >> serialnum;
				b = L->searchBySerial(serialnum);
				if (b) {
					currentAd->removeBook(b, L);
				}
				else if (b == nullptr) {
					return;
				}
				break;
			case 8:
				cout << "Enter the serial of the book to read:";
				cin >> serialnum;
				b = L->searchBySerial(serialnum);
				if (b) {
					currentAd->read(serialnum, L);
				}
				break;
			case 9:
				UM->logout();
				return;
			}
		}
	}




	int main() {
		Library *L = new Library();
		UserManager* UM = new UserManager();
		Book* b = new Book(1, "b", "a", 3, 4, 100007, "d", 6);
		Guest* g = new Guest();
		Member* m1 = new Member("08/2022", "08/2023", "c", "d", "e", 1);
		Member* m2 = new Member("09/2022", "09/2023", "d", "e", "f", 2);
		Member* m3 = new Member("10/2022", "10/2023", "e", "f", "g", 3);
		Admin* a = new Admin("a", "b", "c", 4);
		Collection* c = new Collection(10, "Bruh");

		UM->addGuest(g);
		UM->addMember(m1);
		UM->addMember(m2);
		UM->addMember(m3);
		UM->addAdmin(a);
		a->addBook(b, L);
		a->addCollection(c, L);
		a->addBookToCollection(b, c, L);
		while (true)
		{
			cout << endl;
			cout << "Welcome to the library, enter as: " << endl;
			cout << "1. Guest" << endl;
			cout << "2. Member" << endl;
			cout << "3. Admin" << endl;
			cout << "4. Exit the program" << endl;
			cout << "Enter your choice: ";
			int option;
			cin >> option;
			switch (option)
			{
			case 1:
				guestMenu(L, UM);
				break;
			case 2:
				memberMenu(L, UM);
				break;
			case 3:
				adminMenu(L, UM);
				break;
			case 4:
				exit(0);
			}
		}
		return 0;
	}
	
