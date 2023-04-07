#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "Book.h"
#include <vector>
class ShoppingCart
{
    public:
        void addBookToCart();
        void displayUserCart();
        void removeBookFromUserCart();
        vector<Book> getCart();
    private:
        vector<Book>cart;
        //double totalPrice;

};

#endif // SHOPPINGCART_H
