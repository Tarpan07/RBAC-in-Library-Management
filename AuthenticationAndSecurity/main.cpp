#include <iostream>
#include "AuthManager.h"
#include "../UserInterface/Dashboard.h"

using namespace std;

int main()
{

    AuthManager auth;
    int choice;

    while (true)
    {

        // 🔹 NOT LOGGED IN → Show Auth Menu
        if (!auth.isLoggedIn())
        {

            cout << "\n===== Library System =====\n";
            cout << "1. Login\n";
            cout << "2. Sign Up\n";
            cout << "3. Exit\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                auth.login();
                break;

            case 2:
                auth.registerUser();
                break;

            case 3:
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
            }
        }

        // 🔹 LOGGED IN → Show Dashboard
        else
        {

            // 🔥 RBAC is handled INSIDE Dashboard
            Dashboard::show(auth.getCurrentUser(), auth.getToken());

            cout << "\n1. Logout\n";
            cout << "2. Exit\n";

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                auth.logout();
                cout << "Logged out successfully\n";
                break;

            case 2:
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
            }
        }
    }
}