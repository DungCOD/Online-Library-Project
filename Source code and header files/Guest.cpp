#include "Guest.h"

int Guest::temppID = 0;

Guest::Guest() : User() {
    tempID = temppID;
    subscribe();
}

Guest::Guest(int temp) : User(0, GUEST) {
    subscribe();
}

Guest::~Guest() {
    for (int i = 0; i < subscribedCollection.size(); i++) {
        if (subscribedCollection[i]) delete subscribedCollection[i];
    }
    subscribedCollection.clear();
    subscribeStatus.clear();
}

void Guest::read(string title, Library* l) {
    if (l->searchByTitleSample(title)->getVisibility() == 0) {
        cout << "Book is hidden, can't read" << endl;
    }
    else {
        cout << "Guest reading book named " << l->searchByTitleSample(title)->getTitle() << "..." << endl;
        cout << "You can only read " << l->searchByTitleSample(title)->getFreePage() << " pages of this book" << endl;
    }
}

void Guest::read(int ID, Library* l) {
    if (l->searchBySerialSample(ID)->getVisibility() == 0) {
        cout << "Book is hidden, can't read" << endl;
    }
    else {
        cout << "Guest reading book with serial number: " << l->searchBySerialSample(ID)->getSerialNumber() << "..." << endl;
        cout << "You can only read " << l->searchBySerialSample(ID)->getFreePage() << " pages of this book" << endl;
    }
}

void Guest::subscribe() {
    subscribedCollection.push_back(Library::sampleCollection);
    subscribeStatus.push_back(true);
}
