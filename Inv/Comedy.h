#pragma once
#include "Film.h"

class Comedy : public Film {
public:
   char getGenre();
   void setGenre(char);
   Comedy();
   ~Comedy();
private:
};
