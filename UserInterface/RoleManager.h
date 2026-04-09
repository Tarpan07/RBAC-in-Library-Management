#ifndef ROLE_MANAGER_H
#define ROLE_MANAGER_H

#include <map>
#include "Role.h"
using namespace std;

class RoleManager {
private:
    map<string, Role> roleMap;

public:
    void initializeRoles();
    Role* getRole(string roleName);
};

#endif