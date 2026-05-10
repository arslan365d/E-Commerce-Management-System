#pragma once

#include<iostream>
#include<vector>
#include<limits>


using namespace std;


class Product
{
public:
   int id;
   string name, company, type;
   float rating, price;

public:
   Product() {}

   Product(int id, string name, string company, string type, float rating, float price)
   {
      this->id = id;
      this->name = name;
      this->company = company;
      this->type = type;
      this->rating = rating;
      this->price = price;
   }

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
   static bool isIdExists(vector<Product>& products, int id)
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

static void addProduct(vector<Product>& products)
{
    int id;
    string name, company, type;
    float rating;
    double price;

    cin.ignore();

    // ================= PRODUCT ID =================
    cout << "Enter Product Id: ";

    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid ID! Enter numeric value: ";
    }

    if (isIdExists(products, id))
    {
        cout << "\033[31mError: Product ID already exists!\033[0m\n";
        return;
    }

    cin.ignore();

    // ================= NAME =================
    cout << "Enter Product Name: ";
    getline(cin, name);

    if (name.empty())
    {
        cout << "\033[31mError: Name cannot be empty!\033[0m\n";
        return;
    }

    // ================= COMPANY =================
    cout << "Enter Product Company: ";
    getline(cin, company);

    if (company.empty())
    {
        cout << "\033[31mError: Company cannot be empty!\033[0m\n";
        return;
    }

    // ================= TYPE =================
    cout << "Enter Product Type: ";
    getline(cin, type);

    if (type.empty())
    {
        cout << "\033[31mError: Type cannot be empty!\033[0m\n";
        return;
    }

    // ================= RATING =================
    cout << "Enter Product Rating (0 - 5): ";

    while (!(cin >> rating) || rating < 0 || rating > 5)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Rating! Enter value between 0 to 5: ";
    }

    // ================= PRICE =================
    cout << "Enter Product Price: ";

    while (!(cin >> price) || price <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Price! Enter positive value: ";
    }

    // ================= ADD PRODUCT =================
    products.push_back(Product(id, name, company, type, rating, price));

    cout << "\033[32mProduct Added Successfully!\033[0m\n";
}

   // static void addProduct(vector<Product>& products){
   //      int id;
   //          string name,company,type;
   //          float rating;
   //          double price;
   //          cin.ignore();

   //          cout << "Enter Product Id: ";
   //          cin >> id;
            
   //          cin.ignore();
   //          cout << "Enter Product Name: ";
   //          getline(cin, name);

   //          cout << "Enter Produt Company: ";
   //          cin >> company;

   //          cout << "Enter Product Type: ";
   //          cin >> type;

   //          cout << "Enter Product Rating: ";
   //          cin >> rating;

   //          cout << "Enter Product Price: ";
   //          cin >> price;

   //          products.push_back(Product(id,name,company,type,rating,price));

   //          FileManager::saveProducts(products);

   //          cout << "Product Added!\n";
   // }
};