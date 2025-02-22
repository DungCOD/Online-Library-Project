#include "Library.h"

Collection* Library::sampleCollection = new Collection();

Library::Library() {
    initializeSampleCollection();
}

Library::~Library() {
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i]) delete bookList[i];
    }
    bookList.clear();

    for (int i = 0; i < collectionList.size(); i++) {
        if (collectionList[i]) delete collectionList[i];
    }
    collectionList.clear();
    delete[] sampleCollection;
}

void Library::addBook(Book* b) {
    bookList.push_back(b);
}

void Library::initializeSampleCollection() {
    // Create some sample books
    Book* book1 = new Book(0, "a", "b", 1, 2, 3, "c", 4);
    Book* book2 = new Book(1, "b", "c", 2, 3, 4, "d", 5);
    Book* book3 = new Book(2, "c", "d", 3, 4, 5, "e", 6);

    // Add the books to the sample collection
    sampleCollection->bookListCollection.push_back(book1);
    sampleCollection->bookListCollection.push_back(book2);
    sampleCollection->bookListCollection.push_back(book3);

    // Add the books to the library
    bookList.push_back(book1);
    bookList.push_back(book2);
    bookList.push_back(book3);
}

void Library::displayAllBooks() {
    cout << "All books in the library:" << endl;
    for (int i = 0; i < bookList.size(); i++) {
        bookList[i]->display();
        cout << endl;
    }
}

void Library::displaySampleCollection() {
    cout << "All books in the sample collection:" << endl;
    for (int i = 0; i < sampleCollection->bookListCollection.size(); i++) {
        sampleCollection->bookListCollection[i]->display();
        cout << endl;
    }
}

Book* Library::searchByTitle(string title)
{
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i]->getTitle() == title) {
            return bookList[i];
        }
    }
    cout << "Book not found!" << endl;
    return nullptr;
}

Book* Library::searchBySerial(int serial)
{
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i]->getSerialNumber() == serial) {
            return bookList[i];
        }
    }
    cout << "Book not found!" << endl;
    return nullptr;
}

Book* Library::searchByTitleSample(string title)
{
    for (int i = 0; i < sampleCollection->bookListCollection.size(); i++) {
        if (sampleCollection->bookListCollection[i]->getTitle() == title) {
            return sampleCollection->bookListCollection[i];
        }
    }
    cout << "Book not found in the sample collection!" << endl;
    return nullptr;
}

Book* Library::searchBySerialSample(int serial)
{
    for (int i = 0; i < sampleCollection->bookListCollection.size(); i++) {
        if (sampleCollection->bookListCollection[i]->getSerialNumber() == serial) {
            return sampleCollection->bookListCollection[i];
        }
    }
    cout << "Book not found in the sample collection!" << endl;
    return nullptr;
}

Collection* Library::searchCollectionByID(int ID) {
    for (int i = 0; i < collectionList.size(); i++) {
        if (collectionList[i]->getID() == ID) {
            return collectionList[i];
        }
    }
    cout << "Collection not found in the library!" << endl;
    return nullptr;
}


