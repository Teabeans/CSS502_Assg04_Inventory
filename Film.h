#pragma once

#include <string>
#include <queue>
#include "Media.h"

class Film : public Media {
public:
   void setGenre(char);
   std::string getDirector();
   bool doesFeatureActor(std::string);
   void setDirector(std::string);
   void appendActor(std::string);
   Film();
   ~Film();
private:
   std::string director;
   std::queue<std::string> actors;
   char genre;
};
