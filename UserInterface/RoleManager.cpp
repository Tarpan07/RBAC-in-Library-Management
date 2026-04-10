#include "RoleManager.h"

void RoleManager::initializeRoles()
{

    Role student("STUDENT");
    student.addPermission(Permission("SEARCH_BOOK"));
    student.addPermission(Permission("VIEW_ALL_BOOKS"));
    student.addPermission(Permission("ISSUE_BOOK"));
    student.addPermission(Permission("RETURN_BOOK"));

    Role faculty = student;

    Role staff("STAFF");
    staff.addPermission(Permission("SEARCH_BOOK"));
    staff.addPermission(Permission("VIEW_ALL_BOOKS"));
    staff.addPermission(Permission("ISSUE_BOOK"));
    staff.addPermission(Permission("RETURN_BOOK"));
    staff.addPermission(Permission("UPDATE_BOOK"));

    Role librarian("LIBRARIAN");
    librarian.addPermission(Permission("ADD_BOOK"));
    librarian.addPermission(Permission("DELETE_BOOK"));
    librarian.addPermission(Permission("UPDATE_BOOK"));
    librarian.addPermission(Permission("SEARCH_BOOK"));
    librarian.addPermission(Permission("VIEW_ALL_BOOKS"));
    librarian.addPermission(Permission("ISSUE_BOOK"));
    librarian.addPermission(Permission("RETURN_BOOK"));
    librarian.addPermission(Permission("UPDATE_USER"));

    roleMap["STUDENT"] = student;
    roleMap["FACULTY"] = faculty;
    roleMap["STAFF"] = staff;
    roleMap["LIBRARIAN"] = librarian;
}

Role *RoleManager::getRole(string roleName)
{
    if (roleMap.find(roleName) != roleMap.end())
        return &roleMap[roleName];
    return nullptr;
}