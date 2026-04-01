#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "../AuthenticationAndSecurity/User.h"

class Dashboard {
public:
    static void show(User* user, string token);
};

#endif