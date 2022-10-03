#include<iostream>
using namespace std;
class Seller{
public:
    int locate=0;
    int currentID=0;
    string susername[100];
    string spassword[100];
    Seller(){
    cout<<"welcome to our Shop!"<<endl;
    }
    int reGister();
    //int login();
    int allInfo();
    //int mainMenu();

};
int Seller::reGister(){
    string name;
    string password;
    string password2;
    cout<<"This is from registration"<<endl;
    cout<<"Enter your name to register:"<<endl;
    cin>>name;
    cout<<"Enter your password to register:"<<endl;
    cin>>password;
    cout<<"Confirm password to register:"<<endl;
    cin>>password2;
    if(password==password2){
        susername[locate]=name;
        spassword[locate]=password;

        cout<<"Registration success!;"<<endl;
        locate++;
        allInfo();

         }else{
         cout<<"Invalid! please check your password."<<endl;
         }
}


int Seller::allInfo(){
    cout<<"User name"<<endl;
    for(int i=0;i<=locate;i++){
        cout<<"  "<<susername[i]<<endl;
    }
     cout<<"Password"<<endl;
    for(int i=0;i<=locate;i++){
        cout<<"  "<<spassword[i]<<endl;
    }

}

class ItemStore:public Seller{
public:
    int locate1=0;
    string itemName[100];
    int itemPrice[100];
    int quantity[100];


    ItemStore(){
    cout<<"Welcome to Item Store!"<<endl;
    }
    int itemRecord();
    int allItemInfo();
    int itemMenu();
    int mainMenu();
    int login();

};
int ItemStore::itemRecord(){
    string name;
    int price;
    int quan;
    cout<<"This is record item page"<<endl;
    cout<<"Enter item name :"<<endl;
    cin>>name;
    cout<<"Enter item price :"<<endl;
    cin>>price;
    cout<<"Enter item quantity :"<<endl;
    cin>>quan;
    if(name!=" " && quan !=0){
        itemName[locate1]=name;
        itemPrice[locate1]=price;
        quantity[locate1]=quan;
        cout<<"Registration Success!"<<endl;
        locate1++;
        allItemInfo();

    }

}
int ItemStore::login(){
    string lusername;
    string lpassword;
    cout<<"This is from login"<<endl;
    cout<<"Enter username to login:";
    cin>>lusername;
    cout<<"Enter password to login for"<<lusername<<endl;
    cin>>lpassword;
    for(int i=0;i<=locate;i++){
        if(lusername==susername[i]&&lpassword==spassword[i]){
                //currentID=i;
            cout<<"Login Success"<<endl;
            return 0;
        }else if((lusername!=susername[i]&&lpassword!=spassword[i])){
            cout<<"Invalid login! Try again!"<<endl;
            login();
        }

   }

}
int ItemStore::mainMenu(){
    int option=10;
    while(true){
        cout<<"Press 1 to Register:"<<endl;
        cout<<"Press 2 to Login:"<<endl;
        cout<<"Press 3 to Quit:"<<endl;
        cin>>option;
        if(option==1){
            reGister();

        }else if(option==2){
            //login
            int status=login();

            if(status==0){
                itemMenu();
            }
        }
        else{
            cout<<"bye bye"<<endl;
            return 0;
        }
    }

}
int ItemStore::allItemInfo(){
    cout<<"Item Name"<<endl;
    for(int i=0;i<=locate1;i++){
        cout<<"  "<<itemName[i]<<endl;
    }
     cout<<"Item Price"<<endl;
    for(int i=0;i<locate1;i++){
        cout<<"  "<<itemPrice[i]<<endl;
    }
    cout<<"Item Quantity"<<endl;
    for(int i=0;i<locate1;i++){
        cout<<quantity[i]<<endl;
    }

}
int ItemStore::itemMenu(){
    int option=10;
    while(true){
        cout<<"Press 1 to add item list:"<<endl;
        cout<<"Press 2 to update item list:"<<endl;
        cout<<"Press 3 to Quit:"<<endl;
        cin>>option;
        if(option==1){
            itemRecord();

        }else if(option==2){
            //item update
        }
        else{
            cout<<"bye bye"<<endl;
            return 0;
        }
    }
}
class Buyer{
public:
    int loc=0;
    string busername[100];
    string bpassword[100];
    int amount[100];
    Buyer(){
    cout<<"Welcome to buyer page"<<endl;
    }
    int bRegister();
    int bLogin();
    int bMainMenu();
};
int Buyer::bRegister(){
    string name;
    string password;
    string password2;
    int money;
    cout<<"This is registration page"<<endl;
    cout<<"Enter your name to register:"<<endl;
    cin>>name;
    cout<<"Enter your password to register:"<<endl;
    cin>>password;
    cout<<"Confirm your password to register:"<<endl;
    cin>>password2;
    if (password==password2){
        busername[loc]=name;
        bpassword[loc]=password;
        amount[loc]=money;
        cout<<"Registration success for buyer:"<<endl;
        loc++;
    }
}
int Buyer::bLogin(){
    string lusername;
    string lpassword;
    cout<<"This is from login for buyer"<<endl;
    cout<<"Enter username to login:";
    cin>>lusername;
    cout<<"Enter password to login for"<<lusername<<endl;
    cin>>lpassword;
    for(int i=0;i<=loc;i++){
        if(lusername==susername[i]&&lpassword==spassword[i]){
                //currentID=i;
            cout<<"Login Success for buyer"<<endl;
            return 0;
        }else if((lusername!=susername[i]&&lpassword!=spassword[i])){
            cout<<"Invalid login! Try again!"<<endl;
            bLogin();
        }

   }

}
int Buyer::bMainMenu(){
    int option=10;
    while(true){
        cout<<"Press 1 to Register:"<<endl;
        cout<<"Press 2 to Login:"<<endl;
        cout<<"Press 3 to Quit:"<<endl;
        cin>>option;
        if(option==1){
            bRegister();

        }else if(option==2){
            //login
            int status=bLogin();

            if(status==0){
                itemMenu();
            }
        }
        else{
            cout<<"bye bye"<<endl;
            return 0;
        }

    }
}

int main(){
    ItemStore _item;
    int ex=_item.mainMenu();
    if(ex==0){
        exit(1);
    }


}
