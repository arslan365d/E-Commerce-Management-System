#pragma once

#include <iostream>
#include <vector>

#include "product.h"

using namespace std;

class CartItem
{
public:

    Product product;
    int quantity;

    CartItem(Product product, int quantity)
    {
        this->product = product;
        this->quantity = quantity;
    }
    CartItem(){}
};

class Cart
{
public:

    vector<CartItem> cart;

    static int noOfProducts;

    double totalPrice = 0;

    // ================= ADD PRODUCT =================

    void addProduct(Product& p, int quantity)
    {
        int found = -1;

        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i].product.id == p.id)
            {
                cart[i].quantity += quantity;

                totalPrice += p.price * quantity;

                noOfProducts += quantity;

                found = i;

                break;
            }
        }

        // Product Not Found In Cart

        if (found == -1)
        {
            cart.push_back(
                CartItem(p, quantity));

            totalPrice += p.price * quantity;

            noOfProducts += quantity;
        }

        cout << "\033[32mProduct Added To Cart Successfully!\033[0m\n";
    }

    // ================= VIEW CART =================

    void viewCart()
    {
        if (cart.empty())
        {
            cout << "\n\033[31mYour Cart Is Empty!\033[0m\n";
            return;
        }

        cout << "\n\033[1;36m";
        cout << "=====================================================\n";
        cout << "                     YOUR CART                       \n";
        cout << "=====================================================\n";
        cout << "\033[0m";

        for (int i = 0; i < cart.size(); i++)
        {
            cout << "\nProduct #" << i + 1 << endl;
            cout << "--------------------------------------\n";

            cout << "Name     : "
                 << cart[i].product.name << endl;

            cout << "Type     : "
                 << cart[i].product.type << endl;

            cout << "Price    : Rs. "
                 << cart[i].product.price << endl;

            cout << "Quantity : "
                 << cart[i].quantity << endl;
        }

        cout << "\n--------------------------------------\n";

        cout << "Total Products : "
             << noOfProducts << endl;

        cout << "Total Price    : Rs. "
             << totalPrice << endl;

        cout << "=====================================================\n";
    }

    // ================= EMPTY CART =================

    void emptyCart()
    {
        cart.clear();

        totalPrice = 0;

        noOfProducts = 0;

        cout << "\033[32mCart Emptied Successfully!\033[0m\n";
    }
};