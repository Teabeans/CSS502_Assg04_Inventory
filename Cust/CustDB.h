#pragma once
#include <string>
#include "Cust.h"
#include "../Trans/Trans.h"

class CustDB {
public:
   std::string toString();
   void display();
   Cust* getCustomerAt(int);
   void appendHistory(Trans);
   CustDB();
   ~CustDB();
private:
   Cust custTable[10000];
   bool isValid(std::string);
};
