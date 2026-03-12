#include "AuthManager.h"
#include "PasswordUtil.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

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
        getline(ss, password, ',');

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

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Email: ";
    cin.ignore();
    getline(cin, email);

    if (roleChoice == 1)
    {

        role = "STUDENT";

        while (!isValidStudentEmail(email))
        {

            cout << "Only institute email is allowed\n";

            cout << "Enter Institute Email: ";
            cin >> email;
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
        cin.ignore();
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
        cin.ignore();
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

    cout << "\nLogin\n";

    cout << "Name: ";
    cin >> name;

    cout << "Role: ";
    cin >> role;

    if (role == "STUDENT")
    {

        cout << "Student ID: ";
        cin >> studentID;
    }
    else
    {

        studentID = "NA";
    }

    cout << "Password: ";
    cin >> password;

    string hashed = PasswordUtil::hashPassword(password);

    for (auto &u : users)
    {

        if (u.getName() == name &&
            u.getRole() == role &&
            u.getStudentID() == studentID &&
            u.getPasswordHash() == hashed)
        {

            currentUser = &u;

            cout << "\nLogin successful\n";
            cout << "Welcome " << u.getName() << endl;
            cout << "Role: " << u.getRole() << endl;

            return true;
        }
    }

    cout << "Invalid credentials\n";

    return false;
}