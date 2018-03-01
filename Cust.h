#pragma once
#include <string>
#include "Person.h"
#include "Trans.h"

class Customer : public Person {
public:
   int getID();
   std::string getHistory;
   void setID();
   void appendHistory(Trans);
   Customer();
   ~Customer();
private:
   int custID;
   std::string history;
};
