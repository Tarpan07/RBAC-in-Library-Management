#include <iostream>
#include "AuthManager.h"

using namespace std;

int main(){

    AuthManager auth;

    int choice;

    while(true){

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

}