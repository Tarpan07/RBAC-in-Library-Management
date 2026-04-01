#include <iostream>
#include "AuthManager.h"
#include "../UserInterface/Dashboard.h"

using namespace std;

int main(){

    AuthManager auth;
    int choice;

    while(true){

        // 🔥 IF NOT LOGGED IN → show login/signup menu
        if(!auth.isLoggedIn()){

            cout<<"\n===== Library System =====\n";

            cout<<"1 Login\n";
            cout<<"2 Sign Up\n";
            cout<<"3 Exit\n";

            cin>>choice;

            if(choice==1){
                auth.login();
            }

            else if(choice==2){
                auth.registerUser();
            }

            else if(choice==3){
                cout<<"Exiting system\n";
                break;
            }

            else{
                cout<<"Invalid choice\n";
            }
        }

        else{

            Dashboard::show(auth.getCurrentUser(), auth.getToken());

            cout<<"\n1 Logout\n";
            cout<<"2 Exit\n";

            cin>>choice;

            if(choice==1){
                auth.logout();
            }

            else if(choice==2){
                cout<<"Exiting system\n";
                break;
            }

            else{
                cout<<"Invalid choice\n";
            }
        }
    }
}