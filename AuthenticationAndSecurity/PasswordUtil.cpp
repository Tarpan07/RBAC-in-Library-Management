#include "PasswordUtil.h"
#include <functional>
#include <cctype>

string PasswordUtil::hashPassword(string password){

    hash<string> hasher;
    size_t hashed = hasher(password);

    return to_string(hashed);
}

bool PasswordUtil::validatePassword(string password){

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    if(password.length() < 8)
        return false;

    for(char c : password){

        if(isupper(c))
            hasUpper = true;

        else if(islower(c))
            hasLower = true;

        else if(isdigit(c))
            hasDigit = true;

        else
            hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}