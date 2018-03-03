#pragma once
#include <string>
#include "../Trans/Trans.h"

class Cust {
public:
   std::string toString();
   std::string getFirstName();
   std::string getLastName();
   void setFirstName(std::string);
   void setLastName(std::string);
   int getID();
   std::string getHistory;
   void setID();
   void appendHistory(Trans);
   Cust();
   ~Cust();
private:
   std::string firstName;
   std::string lastName;
   int custID;
   std::string history;
};
