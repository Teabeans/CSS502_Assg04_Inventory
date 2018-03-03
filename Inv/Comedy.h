#pragma once

#include <string>
#include "Film.h"

class Comedy : public Film {
public:
   // char getGenre();
   // void setGenre(char);
   Comedy();
   Comedy(std::string);
   ~Comedy();
private:
};
