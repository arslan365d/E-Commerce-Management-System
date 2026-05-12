#pragma once

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Product
{
public:

    int id;
    string name;
    string company;
    string type;

    float rating;
    double price;

public:

    Product() {}

    Product(int id,string name,string company,string type,float rating,double price)
    {
        this->id = id;
        this->name = name;
        this->company = company;
        this->type = type;
        this->rating = rating;
        this->price = price;
    }

    // ================= GETTERS =================

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    string getCompany() const
    {
        return company;
    }

    string getType() const
    {
        return type;
    }

    float getRating() const
    {
        return rating;
    }

    double getPrice() const
    {
        return price;
    }

    // ================= CHECK ID =================

    static bool isIdExists( vector<Product>& products,int id)
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getId() == id)
            {
                return true;
            }
        }

        return false;
    }

    // ================= ADD PRODUCT =================

    static void addProduct(vector<Product>& products)
    {
        int id;
        string name;
        string company;
        string type;

        float rating;
        double price;

        cout << "\n\033[1;35m";
        cout << "================= ADD PRODUCT =================\n";
        cout << "\033[0m";

        // Product ID

        cout << "Enter Product ID: ";

        while (!(cin >> id))
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            cout << "Invalid ID! Enter numeric value: ";
        }

        if (isIdExists(products, id))
        {
            cout << "\033[31mProduct ID already exists!\033[0m\n";
            return;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n');

        // Product Name

        cout << "Enter Product Name: ";

        do
        {
            getline(cin, name);

            if (name.empty())
            {
                cout << "Name cannot be empty. Enter again: ";
            }

        } while (name.empty());

        // Company

        cout << "Enter Company Name: ";

        do
        {
            getline(cin, company);

            if (company.empty())
            {
                cout << "Company cannot be empty. Enter again: ";
            }

        } while (company.empty());

        // Type

        cout << "Enter Product Type: ";

        do
        {
            getline(cin, type);

            if (type.empty())
            {
                cout << "Type cannot be empty. Enter again: ";
            }

        } while (type.empty());

        // Rating

        cout << "Enter Product Rating (0-5): ";

        while (!(cin >> rating) ||
               rating < 0 ||
               rating > 5)
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            cout << "Invalid Rating! Enter between 0-5: ";
        }

        // Price

        cout << "Enter Product Price: ";

        while (!(cin >> price) ||
               price <= 0)
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            cout << "Invalid Price! Enter positive value: ";
        }

        products.push_back(
            Product(
                id,
                name,
                company,
                type,
                rating,
                price));

        cout << "\n\033[32mProduct Added Successfully!\033[0m\n";
    }
};