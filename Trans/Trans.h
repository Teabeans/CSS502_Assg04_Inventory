#pragma once
#include <string>

class Trans {
public:
   // std::string toString();
   // char getType();
   // std::string getInvID();
   // int getCustID();
   // int getQty();
   // void setInvID(std::string);
   // void setCustID(int);
   // void setQty(int);
   Trans();
   Trans(std::string);
   ~Trans();
private:
   char type; // The transaction type
   std::string invID; // The thing transacted
   int customerID; // To whom it was transacted
   int qty; // And the quantity of the transaction
   std::string identifier1; //first identifier (eg. title or major actor)
   std::string identifier2; //second identifier (eg. year or release date)
};
