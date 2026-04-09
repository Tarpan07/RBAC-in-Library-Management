#ifndef PERMISSION_ENGINE_H
#define PERMISSION_ENGINE_H

#include "../AuthenticationAndSecurity/User.h"
#include "RoleManager.h"

class PermissionEngine {
private:
    RoleManager roleManager;

public:
    PermissionEngine();
    bool checkAccess(const User& user, string action);
};

#endif