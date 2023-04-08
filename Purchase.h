#ifndef PURCHASE_H
#define PURCHASE_H
#include <ctime>
#include "User.h"
#include "Book.h"
#include "ShoppingCart.h"
class Purchase
{
    public:
        void checkout(User user,ShoppingCart shoppingCart);
        double getTotalPrice(ShoppingCart);
        void addPurchaseToPurchaseHistory();
        void displayEntirePurchaseHistory();
        void displayPurchaseDetails();

    private:
        char userName[40];
        char userAddrees[40];
         char date[40];
        double totalPrice;
};

#endif // PURCHASE_H
