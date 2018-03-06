#pragma once

#include <string>
#include <vector>
#include "Film.h"

class Classic : public Film {
public:
   std::string getReleaseDate(); // Override Film::getReleaseDate()
   void setReleaseMonth(int);

   Classic();
   Classic(std::string);
   ~Classic();
private:
   int releaseMonth;
};
