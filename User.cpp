#include "User.h"
#include <string>
#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <vector>
#include <string.h>
#include "ShoppingCart.h"
using namespace  std;


void User::setName(char* name){
    strcpy(UserName,name);
}

char* User::getName(){
    return UserName;
}

void User::setAddress(char* address){
    strcpy(UserAddress,address);
}
char* User::getAddress(){
    return UserAddress;
}


