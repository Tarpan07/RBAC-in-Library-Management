#include "AuthManager.h"
#include "PasswordUtil.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <limits>

AuthManager::AuthManager()
{

    currentUser = nullptr;

    librarianEmails = {"librarian@university.edu"};
    staffEmails = {"staff@university.edu"};

    loadUsers();
}

void AuthManager::saveUsers()
{

    ofstream file("users.txt");

    for (auto &u : users)
    {

        file << u.getName() << ","
             << u.getEmail() << ","
             << u.getRole() << ","
             << u.getStudentID() << ","
             << u.getPasswordHash()
             << endl;
    }

    file.close();
}

void AuthManager::loadUsers()
{

    ifstream file("users.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {

        stringstream ss(line);

        string name, email, role, studentID, password;

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, role, ',');
        getline(ss, studentID, ',');
        getline(ss, password);

        users.push_back(User(name, email, role, studentID, password));
    }

    file.close();
}

bool AuthManager::isValidStudentEmail(string email)
{

    string domain = "nits.ac.in";

    if (email.length() >= domain.length() &&
        email.substr(email.length() - domain.length()) == domain)
    {

        return true;
    }

    return false;
}

void AuthManager::registerUser()
{

    int roleChoice;

    cout << "\nSelect Role\n";
    cout << "1 Student\n";
    cout << "2 Faculty\n";
    cout << "3 Librarian\n";
    cout << "4 Staff\n";

    cin >> roleChoice;

    string name, email, password, confirmPassword, studentID, role;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Name: ";
    getline(cin, name);

    cout << "Email: ";
    getline(cin, email);

    if (roleChoice == 1)
    {

        role = "STUDENT";

        while (!isValidStudentEmail(email))
        {

            cout << "Only institute email is allowed\n";

            cout << "Enter Institute Email: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, email);
        }

        cout << "Student ID: ";
        cin >> studentID;
    }
    else if (roleChoice == 2)
    {

        role = "FACULTY";

        if (email.find("@faculty.edu") == string::npos)
        {
            cout << "Invalid faculty email\n";
            return;
        }

        studentID = "NA";
    }

    else if (roleChoice == 3)
    {

        role = "LIBRARIAN";

        bool authorized = false;

        for (string e : librarianEmails)
        {
            if (e == email)
            {
                authorized = true;
                break;
            }
        }

        if (!authorized)
        {
            cout << "Unauthorized librarian email\n";
            return;
        }

        studentID = "NA";
    }

    else if (roleChoice == 4)
    {

        role = "STAFF";

        bool authorized = false;

        for (string e : staffEmails)
        {
            if (e == email)
            {
                authorized = true;
                break;
            }
        }

        if (!authorized)
        {
            cout << "Unauthorized staff email\n";
            return;
        }

        studentID = "NA";
    }

    while (true)
    {

        cout << "Password: ";
        getline(cin, password);

        if (!PasswordUtil::validatePassword(password))
        {

            cout << "\nPassword must contain:\n";
            cout << "Minimum 8 characters\n";
            cout << "At least 1 uppercase letter\n";
            cout << "At least 1 lowercase letter\n";
            cout << "At least 1 digit\n";
            cout << "At least 1 special character\n\n";

            continue;
        }

        break;
    }

    while (true)
    {
        cout << "Confirm Password: ";
        getline(cin, confirmPassword);

        if (confirmPassword != password)
        {

            cout << "Passwords do not match. Please enter the same password again.\n";
            continue;
        }

        break;
    }
    string hashed = PasswordUtil::hashPassword(password);

    users.push_back(User(name, email, role, studentID, hashed));

    saveUsers();

    cout << "Registration successful\n";
}

bool AuthManager::login()
{
    string name, studentID, password, role;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nLogin\n";

    cout << "Name: ";
    getline(cin, name);

    int roleChoice;

    cout << "Select Role:\n";
    cout << "1 STUDENT\n";
    cout << "2 FACULTY\n";
    cout << "3 LIBRARIAN\n";
    cout << "4 STAFF\n";
    cout << "Enter choice: ";
    cin >> roleChoice;

    // clear buffer before getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // map choice to role
    if (roleChoice == 1)
        role = "STUDENT";
    else if (roleChoice == 2)
        role = "FACULTY";
    else if (roleChoice == 3)
        role = "LIBRARIAN";
    else if (roleChoice == 4)
        role = "STAFF";
    else
    {
        cout << "Invalid role\n";
        return false;
    }

    if (role == "STUDENT")
    {
        cout << "Student ID: ";
        getline(cin, studentID);
    }
    else
    {

        studentID = "NA";
    }
    cout << "Password: ";
    getline(cin, password);

    for (auto &u : users)
    {
        if (u.getName() == name &&
            u.getRole() == role &&
            u.getStudentID() == studentID &&
            PasswordUtil::verifyPassword(password, u.getPasswordHash()))
        {
            currentUser = &u;

            // 🔥 TOKEN GENERATION HERE
            currentToken = tokenManager.generateToken(u.getEmail());

            cout << "\nLogin successful\n";
            cout << "Welcome " << u.getName() << endl;
            cout << "Role: " << u.getRole() << endl;
            cout << "Session Token: " << currentToken << endl;

            return true;
        }
    }

    cout << "Invalid credentials\n";

    return false;
}

void AuthManager::logout()
{

    tokenManager.invalidateToken(currentToken);

    currentUser = nullptr;
    currentToken = "";

    cout << "Logged out successfully\n";
}