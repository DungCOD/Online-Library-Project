#include "Collection.h"

Collection::Collection()
{
    ID = 0;
    name = "";
}

Collection::Collection(int id, string n)
{
    ID = id;
    name = n;
}

Collection::~Collection()
{
    for (int i = 0; i < bookListCollection.size(); i++) {
        if (bookListCollection[i]) delete bookListCollection[i];
    }
    bookListCollection.clear();
}

void Collection::setID(int id)
{
    ID = id;
}

int Collection::getID()
{
    return ID;
}

void Collection::setName(string n)
{
    name = n;
}

string Collection::getName()
{
    return name;
}

void Collection::displayCollection()
{
    for (int i = 0; i < bookListCollection.size();i++) {
        bookListCollection[i]->display();
        cout << endl;
    }
}





