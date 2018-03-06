#pragma once

#include <iostream>
#include <string>
#include <vector>
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
   vector<Film> invTable;
   bool isValid(std::string);
   int hashTitle(std::string);
};