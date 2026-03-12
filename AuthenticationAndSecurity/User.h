#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {

private:

    string name;
    string email;
    string role;
    string studentID;
    string passwordHash;

public:

    User(string name,string email,string role,string studentID,string passwordHash);

    string getName();
    string getEmail();
    string getRole();
    string getStudentID();
    string getPasswordHash();

};

#endif