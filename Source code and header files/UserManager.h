#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Admin.h"
#include "Member.h"
#include "Guest.h"
#include "RegisteredUser.h"
using namespace std;

class UserManager {
public:
    UserManager();
    ~UserManager();
    void addGuest(Guest* guest);
    void addAdmin(Admin* admin);
    void removeAdmin(Admin* admin);
    void addMember(Member* member);
    void removeMember(Member* member);
    void registerAsMember();
    friend class Member;
    friend class Admin;

    Member* getCurrentMember();
    Admin* getCurrentAdmin();
    bool login();
    void logout();
private:
    vector<Guest*> guestList;
    vector<Admin*> adminList;
    vector<Member*> memberList;
    Member* currentMember;
    Admin* currentAdmin;
};