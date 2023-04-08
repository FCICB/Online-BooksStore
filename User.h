#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include "Book.h"
#include <vector>
#include "ShoppingCart.h"

using namespace  std;

class User
{
    public:
        void setName(char* name);
        char* getName();
        void setAddress(char* address);
        char* getAddress();

    private:
        char UserName[30];
        char UserAddress[30];
};

#endif 
