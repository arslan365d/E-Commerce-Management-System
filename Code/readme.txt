# 🛒 ONE STOP SHOP - E-Commerce Management System

A console-based E-Commerce Management System developed in **C++** using **Object-Oriented Programming (OOP)** concepts and **File Handling**.

The project simulates an online shopping platform where users can create accounts, login, browse products, add items to cart, and checkout. It also provides an admin panel for product and user management.

---

# ⚙️ How to Compile & Run

## Compile

Using g++ compiler:
g++ main.cpp -o main -lwinmm

run:
./main

# 📌 Problem Domain

This project solves the problem of managing a small-scale online shopping system through a console application.

The system allows:
- Customers to shop online
- Admins to manage products
- Data to be stored permanently using files

The project demonstrates how real-world e-commerce systems work internally using C++ and OOP principles.

---

# ✨ Features

## 👤 User Features
- Create Account
- User Login
- View Products
- Add Products to Cart
- View Shopping Cart
- Checkout System
- Update Account Balance
- Change Password
- Logout

---

## 🛠️ Admin Features
- Admin Login
- View All Users
- View All Products
- Add New Products

---

## 🔊 Additional Features
- Voice Welcome System
- Sound Effects
- Input Validation
- File Handling
- Console-Based UI
- Cart Management
- Balance Management

---

# 🧠 OOP Features Implemented

## ✅ Encapsulation
Data members and methods are wrapped inside classes.

## ✅ Inheritance
`User` and `Admin` classes inherit from the `Person` base class.

## ✅ Polymorphism
Virtual function `getPerson()` is overridden in derived classes.

## ✅ Abstraction
Complex functionalities are hidden inside classes such as:
- FileManager
- Utility
- Cart

## ✅ Composition
`Cart` contains multiple `CartItem` objects.

## ✅ Modular Programming
The project is divided into multiple header files for better organization.