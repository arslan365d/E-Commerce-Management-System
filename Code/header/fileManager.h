#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "user.h"
#include "product.h"
#include "admin.h"

using namespace std;

class FileManager
{
public:

    // ================= SAVE USERS =================

    static void saveUsers(vector<User>& users)
    {
        ofstream file("./data/users.txt");

        for (int i = 0; i < users.size(); i++)
        {
            file << users[i].getName() << "|"
                 << users[i].getEmail() << "|"
                 << users[i].getPassword() << "|"
                 << users[i].getBalance()
                 << endl;
        }

        file.close();
    }

    // ================= LOAD USERS =================

    static void loadUsers(vector<User>& users)
    {
        ifstream inFile("./data/users.txt");
        string line;

        while (getline(inFile, line))
        {
            stringstream ss(line);

            string name, email, password, balanceStr;

            getline(ss, name, '|');
            getline(ss, email, '|');
            getline(ss, password, '|');
            getline(ss, balanceStr, '|');

            double balance = stod(balanceStr);

            User u;
            u.setData(name, email, password, balance);

            users.push_back(u);
        }

        inFile.close();
    }

    // ================= SAVE PRODUCTS =================

    static void saveProducts(vector<Product>& products)
    {
        ofstream file("./data/products.txt");

        for (int i = 0; i < products.size(); i++)
        {
            file << products[i].getId() << "|"
                 << products[i].getName() << "|"
                 << products[i].getCompany() << "|"
                 << products[i].getType() << "|"
                 << products[i].getRating() << "|"
                 << products[i].getPrice()
                 << endl;
        }

        file.close();
    }

    // ================= LOAD PRODUCTS =================

    static void loadProducts(vector<Product>& products)
    {
        ifstream inFile("./data/products.txt");
        string line;

        while (getline(inFile, line))
        {
            stringstream ss(line);

            string idStr, name, company, type, ratingStr, priceStr;

            getline(ss, idStr, '|');
            getline(ss, name, '|');
            getline(ss, company, '|');
            getline(ss, type, '|');
            getline(ss, ratingStr, '|');
            getline(ss, priceStr, '|');

            Product p;

            p.id = stoi(idStr);
            p.name = name;
            p.company = company;
            p.type = type;
            p.rating = stof(ratingStr);
            p.price = stod(priceStr);

            products.push_back(p);
        }

        inFile.close();
    }

    // ================= VIEW PRODUCTS =================

    static void viewAllProducts(vector<Product>& products)
    {
        if (products.empty())
        {
            cout << "\033[31mNo Products Available!\033[0m\n";
            return;
        }

        cout << "\n\033[1;36m";
        cout << "=====================================================\n";
        cout << "                    ALL PRODUCTS                     \n";
        cout << "=====================================================\n";
        cout << "\033[0m";

        for (int i = 0; i < products.size(); i++)
        {
            cout << "\nID      : " << products[i].getId() << endl;
            cout << "Name    : " << products[i].getName() << endl;
            cout << "Company : " << products[i].getCompany() << endl;
            cout << "Type    : " << products[i].getType() << endl;
            cout << "Rating  : " << products[i].getRating() << endl;
            cout << "Price   : Rs. " << products[i].getPrice() << endl;

            cout << "-----------------------------------------------------\n";
        }
    }

    // ================= LOAD ADMINS =================

    static void loadAdmins(vector<Admin>& admins)
    {
        ifstream file("./data/admins.txt");

        string line;

        while (getline(file, line))
        {
            stringstream ss(line);

            string name, email, password;

            getline(ss, name, '|');
            getline(ss, email, '|');
            getline(ss, password, '|');

            admins.push_back(Admin(name, email, password));
        }

        file.close();
    }
};