#include "Dashboard.h"
#include "PermissionEngine.h"

#include <iostream>
#include <vector>
using namespace std;

void Dashboard::show(User* user, string token) {

    PermissionEngine engine;

    while (true) {

        cout << "\n===== DASHBOARD =====\n";
        cout << "Role: " << user->getRole() << endl;

        vector<pair<int, string>> menu;
        int option = 1;

        if (engine.checkAccess(*user, "ADD_BOOK")) {
            cout << option << ". Add Book\n";
            menu.push_back({option++, "ADD_BOOK"});
        }

        if (engine.checkAccess(*user, "DELETE_BOOK")) {
            cout << option << ". Delete Book\n";
            menu.push_back({option++, "DELETE_BOOK"});
        }

        if (engine.checkAccess(*user, "UPDATE_BOOK")) {
            cout << option << ". Update Book\n";
            menu.push_back({option++, "UPDATE_BOOK"});
        }

        if (engine.checkAccess(*user, "ISSUE_BOOK")) {
            cout << option << ". Issue Book\n";
            menu.push_back({option++, "ISSUE_BOOK"});
        }

        if (engine.checkAccess(*user, "RETURN_BOOK")) {
            cout << option << ". Return Book\n";
            menu.push_back({option++, "RETURN_BOOK"});
        }

        if (engine.checkAccess(*user, "SEARCH_BOOK")) {
            cout << option << ". Search Book\n";
            menu.push_back({option++, "SEARCH_BOOK"});
        }

        if (engine.checkAccess(*user, "UPDATE_USER")) {
            cout << option << ". Update User\n";
            menu.push_back({option++, "UPDATE_USER"});
        }

        cout << "0. Exit\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        bool found = false;

        for (auto &item : menu) {
            if (item.first == choice) {

                found = true;
                string action = item.second;

                if (action == "ADD_BOOK") cout << "Book Added\n";
                else if (action == "DELETE_BOOK") cout << "Book Deleted\n";
                else if (action == "UPDATE_BOOK") cout << "Book Updated\n";
                else if (action == "ISSUE_BOOK") cout << "Book Issued\n";
                else if (action == "RETURN_BOOK") cout << "Book Returned\n";
                else if (action == "SEARCH_BOOK") cout << "Searching Book...\n";
                else if (action == "UPDATE_USER") cout << "User Updated\n";

                break;
            }
        }

        if (!found) {
            cout << "Invalid choice\n";
        }
    }
}