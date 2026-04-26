#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
using namespace std;

class User{
public:
  string name,email,password;
  double salary;

  public:
   User(string name,string email,string password,double balance){
     this->name = name;       
     this->email = email;       
     this->password = password;       
     this->salary = balance;       
   }
   User(){}

   string getName(){
    return name;
   }

   string getEmail(){
    return email;
   }

   string getPassword(){
    return password;
   }
   double getBalance(){
     return salary;
   }

   void setBalance(double balance){
       this->salary= balance;
   }
};

int main() {
  ifstream inFile("users.txt");

    string line;
    vector<User> users;

    while (getline(inFile, line)) {
        stringstream ss(line);
        User u;

        getline(ss, u.name, '|');
        getline(ss, u.email, '|');
        getline(ss, u.password, '|');

        string salaryStr;
        getline(ss, salaryStr, '|');
        u.salary = stod(salaryStr);

        users.push_back(u);
    }

 
    inFile.close();
    
    cout << "\t\tABC STORE"<<endl;
    cout<<"\tWhere You come first"<<endl;

    int choice,found=-1;
    

    do{
        cout <<"\n\n1)Login.\n2)Create an Account.\n3)Exit\n"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice){
             case 1:{
               string email,password;
               cout<<"\nEnter your Email: ";
               cin>> email;
               cout<<"Enter your Password: ";
               cin>> password;
              
               for(int i=0;i<users.size();i++){
                  if((users[i].getEmail() == email) && (users[i].getPassword()==password)){
                     found = i;
                     break;
                  }
               }

               if(found !=-1){
                  cout << "\nLogin Successful!!!!"<<endl;
               }
               else{
                cout << "Invalid Credentials!!!!"<<endl;
               }
               break;
            }
            case 2:{
               string name,email,password;
               float salary;
               cout<<"\nEnter your Name: ";
               cin>> name;
               cout<<"Enter your Email: ";
               cin>> email;
               cout<<"Enter your Password: ";
               cin>> password;
               cout<<"Enter your Salary: ";
               cin>> salary;

               users.push_back(User(name,email,password,salary));

               
            ofstream file("users.txt");
               
               for(int i=0;i<users.size();i++){
                   file << users[i].getName()<<"|"<< users[i].getEmail()<<"|"<< users[i].getPassword()<<"|"<< users[i].getBalance()<<endl;
                }
                
                cout <<"\nAccount Created Successfully!!!!\n";

             break;
            }
            case 3: {
              cout<<"Exiting Program";
              break;
            }
            case 4:{
               cout << "Users...."<<endl;
                for(int i=0;i<users.size();i++){
                   cout << users[i].getName()  <<  users[i].getEmail() << " " << users[i].getPassword()<<endl;
                }
                
               break;
            }
            default:{
             cout <<"Invalid Choice....";  
            }       
        }

    }while(choice !=3);

    return 0;
}