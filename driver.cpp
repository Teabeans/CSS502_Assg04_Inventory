/**
 * CSS502 Assignment 4: Matt Gross & Tim Lum - Group 7
 * File: Inventory Controller
 * Description: Holds the core business logic to manage two inventory databases
 * and process a list of transactions
**/

// Necessary for file stream object handling
#include <fstream>

// Necessary for input-output stream operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for database objects
#include "Inv/InvDB.h"
// #include "CustDB.h"

// Necessary for transaction objects
#include "Trans/Trans.h"
#include "Trans/Borrow.h"
#include "Trans/Return.h"

// Necessary for film objects
#include "Inv/Film.h"
#include "Inv/Comedy.h"
#include "Inv/Drama.h"
#include "Inv/Classic.h"

void readInv(std::ifstream& data, InvDB& invDB) {

   int filmID = 0;
   while (!data.eof()) {
      // Read the next relevant line of command
      std::string filmData;
      std::getline(data, filmData);

      if (filmData.length() >= 1) {
         // create borrow object and run transaction
         if (filmData.at(0) == 'F') {
            invDB.addFilm(new Comedy(filmData));
            std::cerr << " Comedy" << std::endl;
         }

         // create return object and run transaction
         else if (filmData.at(0) == 'D') {
            invDB.addFilm(new Drama(filmData));
            std::cerr << " Drama" << std::endl;
         }

         // check customer and display history
         else if (filmData.at(0) == 'C') {
            invDB.addFilm(new Classic(filmData));
            std::cerr << " Classic" << std::endl;
         }

         // otherwise, this is an invalid film type
         else {
            std::cerr << "Invalid film type: " << filmData.at(0) << std::endl;
         }
      }


      filmID++;
   }
}

// void readCust(std::ifstream& dataFile) {

// }

// int estimate(std::ifstream& dataFile){
//    int retEstimate = 0;
//    // for (;;) {
//    //    // Exit condition
//    //    if (dataFile.eof()) {
//    //       break;
//    //    }
//    //    //Otherwise, just keep drawing lines
//    //    // TODO
//    //    retEstimate++;
//    // }
//    // retEstimate = retEstimate*2;
//    // Now compare against the list of primes until the prime exceeds retEstimate
//    // TODO
//    // Assign this prime to retEstimate
//    // TODO
//    return(10067);
//    // 2x the number of newline characters
//    // Just make a list of prime numbers
// } // Closing estimate()

int main() {

// Begin program
   // Acquire the relevant files

   std::ifstream commandFile("data4commands.txt");
   // std::ifstream customerFile("data4customers.txt");
   std::ifstream inventoryFile("data4movies.txt");
   // std::ifstream sacrificialFile("data4movies.txt");

   // Determine the size of the inventory
   // int entries = estimate(sacrificialFile);

   // Create an InventoryDatabase of size 'entries'
   InvDB invDB(10067);

   // Create a CustomerDatabase of size 10000
   // CustDB custDB(10000);

   // Load the InventoryDatabase using the InventoryFile
   readInv(inventoryFile, invDB);

   // Load the CustomerDatabase using the CustomerFile
   // readCust(customerFile);


   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);


      // create a transaction and check for transaction legality
      Trans* currTrans = nullptr;

      // make sure the line contains data
      if (command.length() >= 1) {
         // create borrow object and run transaction
         if (command.at(0) == 'B') {
            currTrans = new Borrow(command);
            std::cerr << " Borrow" << std::endl;
         }

         // create return object and run transaction
         else if (command.at(0) == 'R') {
            currTrans = new Return(command);
            std::cerr << " Return" << std::endl;
         }

         // check customer and display history
         else if (command.at(0) == 'H') {
            std::cerr << " H" << std::endl;
            // TODO check whether customer is valid
            // TODO output customer history
         }

         // otherwise, this is an invalid command
         else {
            std::cerr << "Invalid command: " << command.at(0) << std::endl;
         }
      }

      // Queries isLegal() in Transactions, invDB, and custDB
      if (invDB.isLegal(command) /* && custDB.isLegal(command)*/ ) {

         // Send the Transaction to the Databases for execution
         invDB.adjustStock(currTrans);
         // custDB.appendHistory(currTrans);
      }

      // deallocate current transaction now that it's been used
      if (currTrans != nullptr) {
         delete currTrans;
      }
   }

// End program

   return (0);
}

