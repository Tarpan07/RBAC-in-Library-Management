#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <vector>
#include <string>
#include "User.h"
#include "TokenManager.h"

using namespace std;

class AuthManager {

private:
    vector<User> users;
    User* currentUser;

    vector<string> librarianEmails;
    vector<string> staffEmails;

    TokenManager tokenManager;   // ✅ added here
    string currentToken;         // ✅ added here

    void saveUsers();
    void loadUsers();

    bool isValidStudentEmail(string email);

public:
    AuthManager();

    void registerUser();
    bool login();

    void logout();   // optional but recommended
};

#endif