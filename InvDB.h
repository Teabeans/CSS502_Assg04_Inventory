#pragma once

#include <iostream>
#include <string>
#include "Trans.h"
#include "Film.h"

class InvDB {
public:
   std::string toString();
   void display();
   void adjustStock(Trans);
   InvDB();
   ~InvDB();
private:
   Film invTable[];
   bool isValid(std::string);
   int hashTitle(std::string);
};
