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
   void adjustStock(Trans&);
   bool isLegal(std::string);
   bool contains(Film*);
   Film* retrieve(Film*);
   bool addFilm(Film*);

   InvDB();
   InvDB(std::ifstream&);
   ~InvDB();

private:
   std::vector<Film> comedies;
   std::vector<Film> dramas;
   std::vector<Film> classics;
   bool isValid(std::string);
   int hashTitle(std::string);
};