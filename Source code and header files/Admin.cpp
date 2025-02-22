#include "Admin.h"

Admin::Admin() : RegisteredUser()
{

}

Admin::Admin(string u, string p, string f, int ph) : RegisteredUser(u, p, f, ph, ADMIN)
{

}

Admin::Admin(string u, string p, string f, int ph, int id) : RegisteredUser(u, p, f, ph, id, ADMIN)
{

}

void Admin::addBook(Book* b, Library* l) {
    l->bookList.push_back(b);
    cout << "Book named " << b->getTitle() << " added to the library." << endl;
}

void Admin::showBook(Book* b) {
    b->setVisibility(1);
    cout << "Book named " << b->getTitle() << " is now visible." << endl;
}

void Admin::hideBook(Book* b) {
    b->setVisibility(0);
    cout << "Book named " << b->getTitle() << "is now hidden." << endl;
}

void Admin::removeBook(Book* b, Library* l) {
    bool bookFound = false;
    for (int i = 0; i < l->bookList.size(); i++) {
        if (l->bookList[i]->getTitle() == b->getTitle()) {
            delete b;
            l->bookList.erase(l->bookList.begin() + i);
            bookFound = true;
            cout << "Book removed from the library." << endl;
            break;
        }
    }
    if (!bookFound) {
        cout << "Error: Book not found in the library." << endl;
    }
}

void Admin::addBookToCollection(Book* b, Collection* c, Library* l) {
    bool bookFound = false;
    for (int i = 0; i < l->bookList.size(); i++) {
        if (l->bookList[i]->getTitle() == b->getTitle()) {
            c->bookListCollection.push_back(b);
            bookFound = true;
            cout << "Book added to the collection." << endl;
            break;
        }
    }
    if (!bookFound) {
        cout << "Error: Book not found in the library." << endl;
    }
}

void Admin::removeBookFromCollection(Book* b, Collection* c) {
    bool bookFound = false;
    for (int i = 0; i < c->bookListCollection.size(); i++) {
        if (c->bookListCollection[i]->getTitle() == b->getTitle()) {
            c->bookListCollection.erase(c->bookListCollection.begin() + i);
            bookFound = true;
            cout << "Book removed from the collection." << endl;
            break;
        }
    }
    if (!bookFound) {
        cout << "Error: Book not found in the collection." << endl;
    }
}

void Admin::addCollection(Collection* c, Library* l) {
    l->collectionList.push_back(c);

    cout << "The collection has been added successfully!\n";
}

void Admin::removeCollection(Collection* c, Library* l) {
    bool collectionFound = false;
    for (int i = 0; i < l->collectionList.size(); i++) {
        if (l->collectionList[i]->getName() == c->getName()) {
            collectionFound = true;
            delete l->collectionList[i];
            l->collectionList.erase(l->collectionList.begin() + i);
            cout << "The collection has been removed successfully!\n";
            return;
        }
    }
    if (!collectionFound) {
        cout << "Collection not found in the library.\n";
    }
}

string Admin::getUsername()
{
    return RegisteredUser::getUsername();
}

string Admin::getPassword()
{
    return RegisteredUser::getPassword();
}

void Admin::editBook(Book* b) {
    int opt, id, pCount, fPage, sNum, visi;
    string tit, aut, cat;
    string op = "y";
    while (op == "y") {
        cout << endl;
        cout << "1. ID" << endl;
        cout << "2. Title" << endl;
        cout << "3. Author" << endl;
        cout << "4. Page count" << endl;
        cout << "5. Free page" << endl;
        cout << "6. Serial number" << endl;
        cout << "7. Category" << endl;
        cout << "8. Visibility" << endl;
        cout << "Which do you like to change: ";
        cin >> opt;
        switch (opt) {
        case 1:
            cout << "New ID: ";
            cin >> id;
            b->setID(id);
            break;

        case 2:
            cout << "Change book title: ";
            cin.ignore();
            getline(cin, tit);
            b->setTitle(tit);
            break;

        case 3:
            cout << "Change author name: ";
            cin.ignore();
            getline(cin, aut);
            b->setAuthor(aut);
            break;

        case 4:
            cout << "Change bpage count: ";
            cin >> pCount;
            b->setPageCount(pCount);
            break;

        case 5:
            cout << "Change free page: ";
            cin >> fPage;
            b->setFreePage(fPage);
            break;

        case 6:
            cout << "Change serial number: ";
            cin >> sNum;
            b->setSerialNumber(sNum);
            break;

        case 7:
            cout << "Change category: ";
            cin.ignore();
            getline(cin, cat);
            b->setCategory(cat);
            break;

        case 8:
            cout << "Change visibility: ";
            cin >> visi;
            b->setVisibility(visi);
            break;
        }
        cout << "Do you want to countinue changing( y for yes, press anything else to escape): ";
        cin.ignore();
        getline(cin, op);
    }
}

void Admin::editCollection(Collection* c) {
    string op = "y";
    while (op == "y") {
        cout << endl;
        cout << "1. Colection ID" << endl;
        cout << "2. Collection name" << endl;
        int opt;
        cout << "What you like to change: ";
        cin >> opt;
        switch (opt) {
        case 1:
            int id;
            cout << "Change ID: ";
            cin >> id;
            c->setID(id);
            break;

        case 2:
            string n;
            cout << "Change name: ";
            cin.ignore();
            getline(cin, n);
            c->setName(n);
            break;
        }
        cout << "Do you want to countinue changing( y for yes, press anything else to escape): ";
        cin.ignore();
        getline(cin, op);
    }
}

void Admin::showInfo() {
    cout << "------Admin information-----" << endl;
    cout << "Fullname: " << getFullname() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Phone: " << getPhone() << endl;
    cout << endl;
}