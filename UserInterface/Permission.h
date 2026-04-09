#ifndef PERMISSION_H
#define PERMISSION_H

#include <string>
using namespace std;

class Permission {
public:
    string actionName;

    Permission() {}
    Permission(string action) : actionName(action) {}
};

#endif