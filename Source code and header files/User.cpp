#include "User.h"

int User::latestID = 10;

User::User()
{
    ID = latestID;
    latestID++;
    accessibilityLevel = GUEST;
}

User::User(aType aL) {
    ID = latestID;
    latestID++;
    accessibilityLevel = aL;
}

User::User(int id, aType aL)
{
    ID = id;
    accessibilityLevel = aL;
}

User::~User() {

}

void User::setID(int id)
{
    ID = id;
}

int User::getID()
{
    return ID;
}

void User::setAccessibilityLevel(aType aL)
{
    accessibilityLevel = aL;
}

aType User::getAccessibilityLevel()
{
    return accessibilityLevel;
}










