#include "PermissionEngine.h"

PermissionEngine::PermissionEngine() {
    roleManager.initializeRoles();
}

bool PermissionEngine::checkAccess(const User& user, string action) {
    string roleName = user.getRole();
    Role* role = roleManager.getRole(roleName);

    if (role == nullptr) return false;

    return role->hasPermission(action);
}