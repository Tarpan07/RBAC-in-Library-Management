#ifndef PASSWORDUTIL_H
#define PASSWORDUTIL_H

#include <string>

using namespace std;

class PasswordUtil{

public:

    static string hashPassword(string password);

    static bool validatePassword(string password);

};

#endif