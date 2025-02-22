#include "UserManager.h"

UserManager::UserManager() {
    currentMember = nullptr;
    currentAdmin = nullptr;
}

UserManager::~UserManager() {
    for (int i = 0; i < guestList.size();i++) {
        if (guestList[i]) delete guestList[i];
    }
    guestList.clear();
    for (int i = 0; i < adminList.size(); i++) {
        if (adminList[i]) delete adminList[i];
    }
    adminList.clear();
    for (int i = 0; i < memberList.size();i++) {
        if (memberList[i]) delete memberList[i];
    }
    memberList.clear();
    delete[] currentMember;
    delete[] currentAdmin;
}

void UserManager::addGuest(Guest* guest) {
    guestList.push_back(guest);
    guest->subscribe();
}

void UserManager::addAdmin(Admin* admin) {
    adminList.push_back(admin);
}

void UserManager::removeAdmin(Admin* admin) {
    for (int i = 0; i < adminList.size(); i++) {
        if (adminList[i]->getID() == admin->getID()) {
            adminList.erase(adminList.begin() + i);
            break;
        }
    }
}

void UserManager::addMember(Member* member) {
    memberList.push_back(member);
    member->subscribe(Library::sampleCollection);
}

void UserManager::removeMember(Member* member) {
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i]->getID() == member->getID()) {
            memberList.erase(memberList.begin() + i);
            break;
        }
    }
}

void UserManager::registerAsMember() {
    string username, password, fullname, start, end;
    int phone = 0, id = 0;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your full name: ";
    cin >> fullname;
    cout << "Enter your phone: ";
    cin >> phone;
    cout << "Enter your ID: ";
    cin >> id;
    Member* m = new Member("27/8/2003", "27/8/2009", username, password, fullname, id, phone);
    addMember(m);
}

bool UserManager::login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < adminList.size(); i++) {
        if (adminList[i]->getUsername() == username && adminList[i]->getPassword() == password) {
            currentAdmin = adminList[i];
            break;
        }
    }
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i]->getUsername() == username && memberList[i]->getPassword() == password) {
            currentMember = memberList[i];
            break;
        }
    }
    if (currentMember != nullptr) {
        cout << "Welcome, " << currentMember->getFullname() << "!\n";
        currentMember->setID(currentMember->getID());
        currentMember->setAccessibilityLevel(MEMBER);
        return true;
    }
    else if (currentAdmin != nullptr) {
        cout << "Welcome, " << currentAdmin->getFullname() << "!\n";
        currentAdmin->setID(currentAdmin->getID());
        currentAdmin->setAccessibilityLevel(ADMIN);
        return true;
    }
    else {
        cout << "Invalid username or password" << endl;
        return false;
    }
    cin.clear();
}

void UserManager::logout() {
    if (currentMember != nullptr) {
        currentMember->setID(0);
        currentMember->setAccessibilityLevel(GUEST);
        currentMember = nullptr;
    }
    else if (currentAdmin != nullptr) {
        currentAdmin->setID(0);
        currentAdmin->setAccessibilityLevel(GUEST);
        currentAdmin = nullptr;
    }
    cout << "Log out successfully!" << endl;
}

Member* UserManager::getCurrentMember() {
    return currentMember;
}

Admin* UserManager::getCurrentAdmin() {
    return currentAdmin;
}


