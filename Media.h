#pragma once
#include <string>

class Media {
public:
   std::string getTitle();
   int getStock();
   int getReleaseDate();
   char getMedium();
   void setTitle(std::string);
   void setStock(int);
   void setReleaseDate(int);
   void setMedium(char);
   Media();
   ~Media();
private:
   std::string title;
   int stock;
   int releaseDate;
   char medium;
};
