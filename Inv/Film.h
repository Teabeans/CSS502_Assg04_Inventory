#pragma once

#include <string>
#include <vector>
#include "Drama.h"

class Film {

public:
   // get/set methods
   std::string getTitle();
   int getStock();
   int getReleaseDate();
   char getGenre();
   std::string getDirector();
   void setTitle(std::string);
   void setStock(int);
   void setReleaseDate(int);
   void setGenre(char);
   void setDirector(std::string);
   bool hasActor(std::string);
   void appendActor(std::string);

   friend class Drama;


   //-------|---------|---------|---------|---------|---------|---------|---------|
   //
   //       OPERATORS
   //
   //-------|---------|---------|---------|---------|---------|---------|---------|

   /**
    * == operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator==(Film&);

   /**
    * <= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator<=(Film&);
   bool operator<(Film&);

   /**
    * >= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   bool operator>=(Film&);
   bool operator>(Film&);

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
   char genre;
   std::vector<std::string> actors;
};
