#pragma once

#include <string>
#include <vector>

class Film {

public:

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

   // title
   std::string getTitle();
   void setTitle(std::string);

   // stock
   int getStock();
   void setStock(int);

   // release date
   int getReleaseDate();
   void setReleaseDate(int);

   // genre
   char getGenre();
   void setGenre(char);

   // director
   std::string getDirector();
   void setDirector(std::string);

   // actor(s)
   bool hasActor(std::string);
   void appendActor(std::string);


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
   virtual bool operator==(Film&);

   /**
    * <= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   virtual bool operator<=(Film&);
   virtual bool operator<(Film&);

   /**
    * >= operator
    * Desc: compares two films based on title & release date
    * Pre: assumes title and release data are populated
   **/
   virtual bool operator>=(Film&);
   virtual bool operator>(Film&);

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
