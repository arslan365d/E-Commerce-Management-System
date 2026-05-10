#include <iostream>
#include <vector>
#include <limits>
#include <windows.h>
#include <mmsystem.h>

// Custom Header Files
#include "./header/fileManager.h"
#include "./header/user.h"
#include "./header/product.h"
#include "./header/cart.h"
#include "./header/options.h"
#include "./header/voice.h"
#include "./header/utility.h"
#include "./header/admin.h"

using namespace std;

int Cart::noOfProducts = 0;

int main()
{
    vector<User> users;
    vector<Admin> admins;
    vector<Product> products;
    Cart cart;

    // Loading Data From Files
    FileManager::loadUsers(users);
    FileManager::loadProducts(products);
    FileManager::loadAdmins(admins);

    // Welcome Screen
    Voice::speak("Welcome to ONE STOP SHOP");

    cout << "\033[1;36m";
    cout << "\n=====================================================\n";
    cout << "                 ONE STOP SHOP                       \n";
    cout << "              Where You Come First                   \n";
    cout << "=====================================================\n";
    cout << "\033[0m";

    int choice;

    do
    {
        cout << "\n\033[1;34m";
        cout << "==================== MAIN MENU ====================\n";
        cout << "1) Login as Buyer\n";
        cout << "2) Login as Admin\n";
        cout << "3) Create an Account\n";
        cout << "4) Exit\n";
        cout << "===================================================\n";
        cout << "\033[0m";

        choice = Utility::input<int>("Enter Your Choice:");

        switch (choice)
        {

        // ================= BUYER LOGIN =================

        case 1:
        {
            string email, password;
            int found = -1;

            cout << "\nEnter Email: ";

            do
            {
                getline(cin, email);

                if (email.empty())
                {
                    cout << "Email cannot be empty. Enter again: ";
                }

            } while (email.empty());

            cout << "Enter Password: ";

            do
            {
                getline(cin, password);

                if (password.empty())
                {
                    cout << "Password cannot be empty. Enter again: ";
                }

            } while (password.empty());

            // Checking Credentials

            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].getEmail() == email &&
                    users[i].getPassword() == password)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
            {
                cout << "\n\033[32mLogin Successful!!!!\033[0m\n";

                Options::afterLoginOptions(
                    users[found],
                    cart,
                    products,
                    users);
            }
            else
            {
                PlaySound(TEXT("./sounds/fahh.wav"), NULL, SND_ASYNC);

                cout << "\033[31mInvalid Credentials!!!!\033[0m\n";
            }

            break;
        }

        // ================= ADMIN LOGIN =================

        case 2:
        {
            string email, password;
            int adminIndex = -1;

            cout << "\nEnter Email: ";

            do
            {
                getline(cin, email);

                if (email.empty())
                {
                    cout << "Email cannot be empty. Enter again: ";
                }

            } while (email.empty());

            cout << "Enter Password: ";

            do
            {
                getline(cin, password);

                if (password.empty())
                {
                    cout << "Password cannot be empty. Enter again: ";
                }

            } while (password.empty());

            // Checking Admin Credentials

            for (int i = 0; i < admins.size(); i++)
            {
                if (admins[i].getEmail() == email &&
                    admins[i].getPassword() == password)
                {
                    adminIndex = i;
                    break;
                }
            }

            if (adminIndex != -1)
            {
                cout << "\n\033[32mAdmin Login Successful!!!!\033[0m\n";

                int adminChoice;

                do
                {
                    cout << "\n\033[1;35m";
                    cout << "=================== ADMIN PANEL ===================\n";
                    cout << "1) View Users\n";
                    cout << "2) View Products\n";
                    cout << "3) Add Product\n";
                    cout << "4) Exit\n";
                    cout << "===================================================\n";
                    cout << "\033[0m";

                    adminChoice =
                        Utility::input<int>("Enter Choice:");

                    switch (adminChoice)
                    {
                    case 1:
                        Admin::viewUsers(users);
                        break;

                    case 2:
                        FileManager::viewAllProducts(products);
                        break;

                    case 3:
                        Product::addProduct(products);
                        FileManager::saveProducts(products);
                        break;

                    case 4:
                        cout << "\033[32mExiting Admin Panel...\033[0m\n";
                        break;

                    default:
                        PlaySound(TEXT("./sounds/fahh.wav"),
                                  NULL,
                                  SND_ASYNC);

                        cout << "\033[31mInvalid Choice!\033[0m\n";
                    }

                } while (adminChoice != 4);
            }
            else
            {
                PlaySound(TEXT("./sounds/fahh.wav"), NULL, SND_ASYNC);

                cout << "\033[31mInvalid Admin Credentials!!!!\033[0m\n";
            }

            break;
        }

        // ================= CREATE ACCOUNT =================

        case 3:
        {
            string name, email, password;
            double balance;

            cout << "\nEnter Name: ";

            do
            {
                getline(cin, name);

                if (name.empty())
                {
                    cout << "Name cannot be empty. Enter again: ";
                }

            } while (name.empty());

            cout << "Enter Email: ";

            do
            {
                getline(cin, email);

                if (email.empty())
                {
                    cout << "Email cannot be empty. Enter again: ";
                }
                else if (email.find('@') == string::npos)
                {
                    cout << "Invalid Email Format. Enter again: ";
                    email.clear();
                }

            } while (email.empty());

            cout << "Enter Password: ";

            do
            {
                getline(cin, password);

                if (password.empty())
                {
                    cout << "Password cannot be empty. Enter again: ";
                }

            } while (password.empty());

            balance =
                Utility::inputBalance("Enter New Balance: ");

            User newUser(name, email, password, balance);

            users.push_back(newUser);

            FileManager::saveUsers(users);

            cout << "\n\033[32mAccount Created Successfully!!!!\033[0m\n";

            Options::afterLoginOptions(
                newUser,
                cart,
                products,
                users);

            break;
        }

        // ================= EXIT =================

        case 4:

            Voice::speak("Thank you for visiting our store");

            cout << "\nExiting Program...\n";

            return 0;

        // ================= INVALID =================

        default:

            PlaySound(TEXT("./sounds/fahh.wav"),
                      NULL,
                      SND_ASYNC);

            cout << "\033[31mInvalid Choice!\033[0m\n";
        }

    } while (choice != 4);

    return 0;
}