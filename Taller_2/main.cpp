#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include "Customer.h"
using namespace std;
int option;
string adminName = "javier", adminPass = "123hola";
queue<Customer*> totalCustomers, normalCustomers, preferredCustomers;

void addCustomerToQueue(Customer *customer){
    totalCustomers.push(customer);
}

string chooseType(){
    int option;
    string type;
    cout << "What type of preferred customer are you?\n";
    cout << "1) I'm a pregnant client\n";
    cout << "2) I'm an elderly customer\n";
    cout << "3) I'm a client with a disability\n";
    cin >> option;

    while(option < 1 || option > 3){
        chooseType();
    }
    
    if(option == 1){
        type = "pregnant";
        return type;
    }else if(option == 2){
        type = "third age";
        return type;
    }else{
        type = "disability";
        return type;
    }
    return "ERROR";
}

int deliverNumber(){
    return totalCustomers.size()+1;
}

void enterIntoQueue(){
    int option, turn;
    string type, rut;
    cout << "In order to assign a number, first select which group you belong to:\n";
    cout << "1. I'm a Normal Customer\n";
    cout << "2. I'm a Preferred Customer\n";    
    cin >> option;

    while(option < 1 || option > 2){
        cout << "ERROR, try again.\n";
        enterIntoQueue();
    }

    cout << "Please, enter your RUT:\n";
    cin >> rut;
    turn = deliverNumber();

    if(option == 1){
        type = "normal";
    } else {
        type = chooseType();
    }

    Customer *customer = new Customer(type, rut, turn); //Esta linea me tira un error de referencia :( 
    addCustomerToQueue(customer);
}

void callNextCustomer(){

}

void addProduct(){

}

void generateReceipts(){

}

void customerMenu(){
    int n;
    cout << "1. Deliver number.\n";
    cout << "2. Call to next customer.\n";
    cout << "3. Enter customer into queue correctly.\n";
    cout << "> ";
    cin >> n;

    while(n < 1 || n > 4){
        cout << "ERROR\n";
        cout << "Please, select an option:\n";
        cout << "1. Deliver number.\n";
        cout << "2. Call to next customer.\n";
        cout << "3. Enter customer into queue correctly.\n";
        cout << "4. close.\n";
        cout << "> ";
        cin >> n;
    }

    if(n == 1){
        deliverNumber();
        customerMenu();
    }else if(n == 2){
        callNextCustomer();
        customerMenu();
    }else if(n == 3){
        enterIntoQueue();
        customerMenu();
    }else{
        cout << "Good Bye!\n";
    }
}

bool access(){
    string name,password;
    bool checkname,checkpass;
    cout << "Enter your name:\n";
    cout << "> \n";
    cin >> name;
    cout << "Enter your password:\n";
    cout << "> \n";
    cin >> password;

    if(name == adminName){
        checkname = true;
    }else{
        checkname = false;
    }

    if(password == adminPass){
        checkpass = true;
    }else{
        checkpass = false;
    }

    if(checkname == true && checkpass == true){
        return true;
    } else {
        return false;
    }

}

void workerMenu(){
    int n;
    bool logIn = access();

    if(logIn){
        cout << "You have successfully started the session\n";
        cout << "1. Add products to the warehouse.\n";
        cout << "2. Generate receipts sale.\n";
        cout << "3. Deliver number.\n";
        cout << "4. Call to next customer.\n";
        cout << "5. Enter customer into queue correctly.\n";
        cout << "6. Close.\n";
        cout << "> ";
        cin >> n;

        while(n < 1 || n > 6){
            cout << "You have successfully started the session\n";
            cout << "1. Add products to the warehouse.\n";
            cout << "2. Generate receipts sale.\n";
            cout << "3. Deliver number.\n";
            cout << "4. Call to next customer.\n";
            cout << "5. Enter customer into queue correctly.\n";
            cout << "6. Close.\n";
            cout << "> ";
            cin >> n;
        }

        if(n == 1){
            addProduct();
            workerMenu();
        }else if( n == 2){
            generateReceipts();
            workerMenu();
        }else if(n == 3){
            deliverNumber();
            workerMenu();
        }else if(n == 4){
            callNextCustomer();
            workerMenu();
        }else if(n == 5){
            enterIntoQueue();
            workerMenu();
        }else if(n == 6){
            cout << "Good Bye!\n";
        }

    }else{
        cout << "Login Denied. try again.\n";
        workerMenu();
    }
}

void globalMenu(){
    int n;
    cout << "Welcome to the Pharmaceutical organization system\n";
    cout << "Please, select an option:\n";
    cout << "1. Im a customer\n";
    cout << "2. Im a worker\n";
    cin >> n;

    while ( n < 1 || n > 2){
        cout << "Please select a valid option\n";
        cout << "1. Im a customer\n";
        cout << "2. Im a worker\n";
        cin >> n;
    }

    if(n == 1){
        customerMenu();
    }else{
        workerMenu();
    }
}

int main(){
    globalMenu();
}