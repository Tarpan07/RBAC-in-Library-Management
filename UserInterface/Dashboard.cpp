#include "Dashboard.h"
#include <iostream>

using namespace std;

void Dashboard::show(User* user, string token) {

    cout << "\n===== USER DASHBOARD =====\n";

    cout << "Welcome: " << user->getName() << endl;
    cout << "Role: " << user->getRole() << endl;

    cout << "Session Token: " << token << endl;

    cout << "\n(Features will be added here...)\n";
}