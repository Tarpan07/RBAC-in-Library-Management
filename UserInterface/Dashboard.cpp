#include "Dashboard.h"
#include "PermissionEngine.h"

#include <iostream>
using namespace std;

void Dashboard::show(User *user, string token)
{

    PermissionEngine engine;
    int choice;

    while (true)
    {
        cout << "\n===== DASHBOARD =====\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Update Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book\n";
        cout << "7. Update User\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {

        case 1:
            if (engine.checkAccess(*user, "ADD_BOOK"))
                cout << "Book Added\n";
            else
                cout << "Access Denied\n";
            break;

        case 2:
            if (engine.checkAccess(*user, "DELETE_BOOK"))
                cout << "Book Deleted\n";
            else
                cout << "Access Denied\n";
            break;

        case 3:
            if (engine.checkAccess(*user, "UPDATE_BOOK"))
                cout << "Book Updated\n";
            else
                cout << "Access Denied\n";
            break;

        case 4:
            if (engine.checkAccess(*user, "ISSUE_BOOK"))
                cout << "Book Issued\n";
            else
                cout << "Access Denied\n";
            break;

        case 5:
            if (engine.checkAccess(*user, "RETURN_BOOK"))
                cout << "Book Returned\n";
            else
                cout << "Access Denied\n";
            break;

        case 6:
            if (engine.checkAccess(*user, "SEARCH_BOOK"))
                cout << "Searching Book...\n";
            else
                cout << "Access Denied\n";
            break;

        case 7:
            if (engine.checkAccess(*user, "UPDATE_USER"))
                cout << "User Updated\n";
            else
                cout << "Access Denied\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
}