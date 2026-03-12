#include "User.h"

User::User(string name,string email,string role,string studentID,string passwordHash){

    this->name=name;
    this->email=email;
    this->role=role;
    this->studentID=studentID;
    this->passwordHash=passwordHash;

}

string User::getName(){ return name; }

string User::getEmail(){ return email; }

string User::getRole(){ return role; }

string User::getStudentID(){ return studentID; }

string User::getPasswordHash(){ return passwordHash; }