#pragma once

#include <string>
#include <queue>
#include "Media.h"

class Film {
public:
   // std::string getTitle();
   // int getStock();
   // int getReleaseDate();
   // void setTitle(std::string);
   // void setStock(int);
   // void setReleaseDate(int);
   // void setGenre(char);
   // std::string getDirector();
   // bool doesFeatureActor(std::string);
   // void setDirector(std::string);
   // void appendActor(std::string);
   Film();
   Film(std::string);
   ~Film();
private:
   std::string title;
   int stock;
   int releaseDate;
   std::string director;
   std::queue<std::string> actors;
   char genre;
};
