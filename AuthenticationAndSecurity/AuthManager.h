#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <vector>
#include "User.h"

using namespace std;

class AuthManager{

private:

    vector<User> users;
    User* currentUser;

    vector<string> librarianEmails;
    vector<string> staffEmails;

    void saveUsers();
    void loadUsers();

    bool isValidStudentEmail(string email);   // ADD THIS LINE

public:

    AuthManager();

    void registerUser();

    bool login();

};

#endif