#pragma once

#include <iostream>
#include <string>
#include "../Trans/Trans.h"
#include "Film.h"

class InvDB {
public:
   std::string toString();
   void display();
   void adjustStock(Trans*);
   bool isLegal(std::string);
   bool addFilm(Film*);
   InvDB();
   InvDB(int);
   ~InvDB();
private:
   Film* invTable = nullptr;
   bool isValid(std::string);
   int hashTitle(std::string);
};