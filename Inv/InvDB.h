#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Trans/Trans.h"
#include "Film.h"
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"

class InvDB {
public:
   std::string toString();
   void display();
   void adjustStock(Trans&);
   bool isLegal(std::string);
   bool contains(Film*);
   Film* retrieve(Film*);
   bool addComedy(Comedy*);
   bool addDrama(Drama*);
   bool addClassic(Classic*);

   InvDB();
   InvDB(std::ifstream&);
   ~InvDB();

private:
   std::vector<Comedy> comedies;
   std::vector<Drama> dramas;
   std::vector<Classic> classics;
   bool isValid(std::string);
   int hashTitle(std::string);
};