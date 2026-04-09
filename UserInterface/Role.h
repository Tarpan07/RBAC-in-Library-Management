#ifndef ROLE_H
#define ROLE_H

#include <vector>
#include <string>
#include "Permission.h"
using namespace std;

class Role {
private:
    string roleName;
    vector<Permission> permissions;

public:
    Role() {}
    Role(string name) : roleName(name) {}

    void addPermission(const Permission& p) {
        permissions.push_back(p);
    }

    bool hasPermission(string action) {
        for (auto &p : permissions) {
            if (p.actionName == action)
                return true;
        }
        return false;
    }
};

#endif