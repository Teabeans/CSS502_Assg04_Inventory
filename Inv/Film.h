#pragma once

#include <string>
#include <vector>
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

   /**
    * == operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator==(Film&);

   /**
    * Constructors
   **/
   Film();
   Film(std::string);
   ~Film();

protected:
   std::string title;
   int stock;
   int releaseDate;
   std::string director;
   std::vector<std::string> actors;
   char genre;
};
