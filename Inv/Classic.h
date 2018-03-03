#pragma once

#include <string>
#include "Film.h"

class Classic : public Film {
public:
   // char getGenre();
   // std::string getReleaseDate(); // Override Media::getReleaseDate()
   // void setGenre(char);
   // void setReleaseMonth(int);
   Classic();
   Classic(std::string);
   ~Classic();
private:
   int releaseMonth;
};
