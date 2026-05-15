#pragma once

#include <iostream>
#include <vector>

#include "product.h"
#include "user.h"
#include "cart.h"
#include "fileManager.h"

#include "voice.h"
#include "utility.h"

using namespace std;

class Options
{
public:
   static void afterLoginOptions(User &user, Cart &cart, vector<Product> &products, vector<User> &users)
   {
      Voice::speak("Welcome" + user.getName());
      int choice;
      cout << "\n\t\033[36mWelcome " << user.getName() << "\033[0m" << endl;
      do
      {
         cout << "\n\n1)Go to Shopping.\n2)Account Settings.\n3)Logout\n"
              << endl;
         choice = Utility::input<int>("Enter your Choice: ");

         switch (choice)
         {
         case 1:
            shoppingOptions(cart, user, products, users);
            break;

         case 2:
            accountOptions(user, users);
            break;

         case 3:
            cart.emptyCart();

            cout << "\033[32mLogout Successful!!!\033[0m" << endl;
            break;
         default:
            cout << "\033[31mInvalid Choice!\033[0m" << endl;
         }
      } while (choice != 3);
   }

   static void shoppingOptions(Cart &cart, User &user, vector<Product> &products, vector<User> &users)
   {
      int choice;
      do
      {
         cout << "\n\n1)View Products.\n2)Add to Cart.\n3)Remove from Cart.\n4)View Cart\n5)Checkout\n6)Back\n"
              << endl;
         choice = Utility::input<int>("Enter your Choice: ");

         switch (choice)
         {
         case 1:
            FileManager::viewAllProducts(products);
            break;

         case 2:
            FileManager::viewAllProducts(products);

            char choice;
            do
            {
               int productId;
               int productQuantity;

               cout << "\nEnter Product ID: ";
               cin >> productId;
               cout << "Enter Product Quantity: ";
               cin >> productQuantity;

               int found = -1;
               for (int i = 0; i < products.size(); i++)
               {
                  if (productId == products[i].id)
                  {
                     found = i;
                     break;
                  }
               }

               if (found != -1)
               {
                  cart.addProduct(products[found], productQuantity);
               }
               else
               {
                  cout << "\n\033[32mInvalid Product ID......\033[0m";
               }

               choice = Utility::input<char>("If you Want to add more Products in Cart. Press [Y/N]: ");

            } while (choice == 'y' || choice == 'Y');
            break;

         case 3:
         {
            char choice;
            do
            {
               int productId;
               int productQuantity;

               cout << "\nEnter Product ID: ";
               cin >> productId;
               cout << "Enter Product Quantity: ";
               cin >> productQuantity;

               int found = -1;
               for (int i = 0; i < products.size(); i++)
               {
                  if (productId == products[i].id)
                  {
                     found = i;
                     break;
                  }
               }

               if (found != -1)
               {
                  cart.removeProduct(products[found], productQuantity);
               }
               else
               {
                  cout << "\n\033[32mInvalid Product ID......\033[0m";
               }

               choice = Utility::input<char>("If you Want to remove more Products in Cart. Press [Y/N]: ");

            } while (choice == 'y' || choice == 'Y');
            break;
         }   

         case 4:
            cart.viewCart();
            break;
         case 5:
         {
            cout << "\n\033[1;34m==========================CHECKOUT==========================\033[0m" << endl;
            cout << "\nNo Of Products:  " << cart.noOfProducts << endl
                 << "Total Price: " << cart.totalPrice << endl
                 << "Press Enter to proceed to Payment....";

            cin.ignore();
            cin.get();

            double balance = user.getBalance();
            if (balance >= cart.totalPrice)
            {
               user.setBalance(balance - cart.totalPrice);
               FileManager::saveUsers(users);
               cout << "\n\033[32mPayment Done Successfull!!!!\033[0m" << endl;

               cout << "\nCash Recieved: " << balance << endl
                    << "Cash Returned: " << user.getBalance() << endl;

                    cart.emptyCart();
            }
            else
            {
               cout << "\n\033[31mInsuffiencet Balance!!!!!\033[0m" << endl;
            }
            break;
         }
         case 6:
            break;
         default:
            cout << "\033[31mInvalid Choice!\033[0m" << endl;
         }
      } while (choice != 6);
   }

   static void accountOptions(User &user, vector<User> &users)
   {
      int choice;
      do
      {
         cout << "\n\n1)View Profile.\n2)Change Password.\n3)Update Balance\n4)Back\n"
              << endl;
         choice = Utility::input<int>("Enter your Choice: ");

         switch (choice)
         {
         case 1:
            user.getPerson();
            break;

         case 2:
         {
            string password;
            cout << "Enter New Password: ";
            cin >> password;
            user.setPassword(password);
            FileManager::saveUsers(users);
            cout << "Password Updated Successfully!!!" << endl;
            break;
         }

         case 3:
         {
            double newBalance, previousBalance = user.getBalance();

            newBalance = Utility::inputBalance("Enter New Balance: ");
            user.setBalance(previousBalance + newBalance);
            FileManager::saveUsers(users);

            cout << "Previous Balance: " << previousBalance << endl
                 << "New Balance: " << user.getBalance() << endl
                 << "\n\033[32mBalance Updated Successfully!!!\033[0m" << endl;
            break;
         }

         case 4:
            break;
         default:
            cout << "\033[31mInvalid Choice!\033[0m" << endl;
         }
      } while (choice != 4);
   }
};