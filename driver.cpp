//-------|---------|---------|---------|---------|---------|---------|---------|
//
// UW CSS 502A - Assignment 4 - Inventory Management
// Driver.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Matt Gross & Tim Lum
// mattgrosspersonal@gmail.com + twhlum@gmail.com
// Created:  2018.03.03
// Modified: 2018.03.--
// For the University of Washington Bothell, CSS 502A
// Winter 2018, Graduate Certificate in Software Design & Development (GCSDD)
//

//-----------------------------------------------------------------------------|
// File Description
//-----------------------------------------------------------------------------|
//
// An inventory control system. Utilizes InvDB and CustDB classes to manage a
// database of film objects, generating and directing transactions created from
// a set of bulk command documents.
//

//-----------------------------------------------------------------------------|
// Package Files
//-----------------------------------------------------------------------------|
//
// See Github repository
// https://github.com/Teabeans/CSS502_Assg04_Inventory
//

//-------------------------------------|
// Begin Student Code
//-------------------------------------|

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Necessary for string operations
#include <string>

// Necessary for file stream object handling
#include <fstream>

// Necessary for input-output stream operations
#include <iostream>

// Necessary for stream operations
#include <sstream>

// Necessary for stream output manipulations
#include <iomanip>

// Necessary for transaction objects
#include "Trans.h"

// Necessary for film objects
#include "Film.h"
#include "FilmComedy.h"
#include "FilmDrama.h"
#include "FilmClassic.h"

// Necessary for customer objects
#include "Cust.h"

// Necessary for database objects
#include "InvDB.h"
#include "CustDB.h"



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       METHOD DECLARATIONS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Bulk reader - Customers
void bulkReadCust(std::ifstream& custtxt, CustDB& tgtDB);

// Bulk reader - Inventory
void bulkReadInv(std::ifstream& invtxt, InvDB& tgtDB);

// Bulk reader - Transactions
void bulkReadTrans(std::ifstream& transtxt, CustDB& tgtCustDB, InvDB& tgtInvDB);

// Legality check - Customer commands
bool isLegalCustCmd(std::string command, CustDB& tgtDB);

// Legality check - Inventory commands
bool isLegalInvCmd(std::string command, InvDB& tgtDB);

// Legality check - Transaction commands
bool isLegalTransCmd(std::string command, CustDB& tgtDB, InvDB& tgtInvDB);

// Appends missing information to a transaction
void padOut(Trans* transPtr, InvDB& tgtInvDB);


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       MAIN()
//
//-------|---------|---------|---------|---------|---------|---------|---------|

int main() {



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       TRANS CLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (1.0) BEGIN TRANS CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (1.1) Creating a default Transaction... ---" << std::endl << std::endl;
      Trans testTrans;

      std::cout << "--- (1.2) Test of Trans::debug() and Trans::toString(): ---" << std::endl << std::endl;
      std::cout << "toString(): " << testTrans.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans.debug();

      std::cout << "--- (1.3) Partially create a Drama transaction by string... ---" << std::endl << std::endl;
      Trans testTrans2("B 1111 D D Phillippe De Broca, King of Hearts,");
      std::cout << "toString(): " << testTrans2.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans2.debug();

      std::cout << "--- (1.4) Partially create a Comedy transaction by string... ---" << std::endl << std::endl;
      Trans testTrans3("R 2222 D F You've Got Mail, 1998");
      std::cout << "toString(): " << testTrans3.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans3.debug();

      std::cout << "--- (1.5) Partially create a Classic transaction by string... ---" << std::endl << std::endl;
      Trans testTrans4("B 3333 D C 3 1971 Ruth Gordon");
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.6) Append title to transaction: ---" << std::endl << std::endl;
      testTrans4.setTitle("<Title pulled from database>");
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.7) Append year to transaction: ---" << std::endl << std::endl;
      testTrans2.setReleaseYear(2000);
      std::cout << "toString(): " << testTrans4.toString() << std::endl;
      std::cout << "debug():" << std::endl;
      testTrans4.debug();

      std::cout << "--- (1.8) Final transaction states: ---" << std::endl << std::endl;
      std::cout << testTrans4.toString() << std::endl;
      std::cout << testTrans2.toString() << std::endl;
      std::cout << testTrans3.toString() << std::endl;
      std::cout << std::endl;

      std::cout << "--- END FILM CLASS TESTS ---" << std::endl << std::endl;

   } // END TRANS CLASS TESTS

   
   
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       FILM CLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (2.0) BEGIN FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (2.1) Creating a default Film... ---" << std::endl << std::endl;
      // default constructor
      Film filmA;

      std::cout << "--- (2.2) Test of Film Setters/Getters... ---" << std::endl << std::endl;

      filmA.setTitle("Testing Film");
      filmA.setStock(20);
      filmA.setReleaseYear(1995);
      filmA.setGenre('X');
      filmA.setDirector("Antonio Testing");
      filmA.setActor("Bob Benson");

      std::cout << "Title:       " << filmA.getTitle() << std::endl;
      std::cout << "Stock:       " << filmA.getStock() << std::endl;
      std::cout << "ReleaseYear: " << filmA.getReleaseYear() << std::endl;
      std::cout << "Genre:       " << filmA.getGenre() << std::endl;
      std::cout << "Director:    " << filmA.getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.3) Creating a Film from string ('D, 10, Jonathan Demme, Silence of the Lambs, 1991')... ---" << std::endl << std::endl;
      // string constructor
      Film filmB("D, 10, Jonathan Demme, Silence of the Lambs, 1991");

      std::cout << "Title:       " << filmB.getTitle() << std::endl;
      std::cout << "Stock:       " << filmB.getStock() << std::endl;
      std::cout << "ReleaseYear: " << filmB.getReleaseYear() << std::endl;
      std::cout << "Genre:       " << filmB.getGenre() << std::endl;
      std::cout << "Director:    " << filmB.getDirector() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.4) Test of Film comparison operators (by title, then year) ---" << std::endl << std::endl;
      // operators
      std::cout << "(" << filmA.getTitle() << ":" << filmA.getReleaseYear() << ") vs (" << filmB.getTitle() << ":" << filmB.getReleaseYear() << ")" << std::endl;
      std::cout << "FilmA == FilmB: " << (filmA == filmB) << " (0 expected)" << std::endl;
      std::cout << "FilmA >  FilmB: " << (filmA >  filmB) << " (1 expected)" << std::endl;
      std::cout << "FilmA <  FilmB: " << (filmA <  filmB) << " (0 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (2.5) Test of Film comparison operators (by title, then year) ---" << std::endl << std::endl;

      Film filmC("D, 100, Jonathan Demme, Silence of the Lambs, 1991");
      std::cout << "(" << filmC.getTitle() << ":" << filmC.getReleaseYear() << ") vs (" << filmB.getTitle() << ":" << filmB.getReleaseYear() << ")" << std::endl;
      std::cout << "FilmC == FilmB: " << (filmC == filmB) <<  " (1 expected)" << std::endl;
      std::cout << "FilmC >  FilmB: " << (filmC >  filmB) <<  " (0 expected)" << std::endl;
      std::cout << "FilmC <  FilmB: " << (filmC <  filmB) <<  " (0 expected)" << std::endl;
      
      std::cout << std::endl;

      std::cout << "--- END FILM CLASS TESTS ---" << std::endl << std::endl;

   } // END FILM CLASS TESTS

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASSIC FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {
      std::cout << "--- (3.0) BEGIN CLASSIC FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (3.1) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Langrid Bergman 11 1942') ---" << std::endl << std::endl;
      Film* cTestFilm1 = new Classic("C, 10, Michael Curtiz, Casablanca, Langrid Bergman 11 1942");
      std::cout << "Title:        " << cTestFilm1->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm1->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm1->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm1->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm1->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm1->getDirector() << std::endl;
      std::cout << "Actor:        " << cTestFilm1->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.2) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1942') ---" << std::endl << std::endl;

      Film* cTestFilm2 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1942");
      std::cout << "Title:        " << cTestFilm2->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm2->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm2->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm2->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm2->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm2->getDirector() << std::endl;
      std::cout << "Actor:        " << cTestFilm2->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.3) Test of Classic Film comparison operators (by year, then month, then actor) ---" << std::endl << std::endl;

      std::cout << "(" << cTestFilm1->getReleaseYear() << ":" << cTestFilm1->getReleaseMonth() << ":" << cTestFilm1->getActor() <<
              ") vs (" << cTestFilm2->getReleaseYear() << ":" << cTestFilm2->getReleaseMonth() << ":" << cTestFilm2->getActor() <<
              ")" << std::endl;
      std::cout << "CFilm1 == CFilm2: " << (*cTestFilm1 == *cTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "CFilm1 >  CFilm2: " << (*cTestFilm1 >  *cTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "CFilm1 <  CFilm2: " << (*cTestFilm1 <  *cTestFilm2) <<  " (1 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.4) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Dangrid Bergman 8 1942') ---" << std::endl << std::endl;
      Film* cTestFilm3 = new Classic("C, 10, Michael Curtiz, Casablanca, Dangrid Bergman 8 1942");

      std::cout << "--- (3.5) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 8 1942') ---" << std::endl << std::endl;
      Film* cTestFilm4 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 8 1942");

      std::cout << "--- (3.6) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Cangrid Bergman 11 1940') ---" << std::endl << std::endl;
      Film* cTestFilm5 = new Classic("C, 10, Michael Curtiz, Casablanca, Cangrid Bergman 11 1940");

      std::cout << "--- (3.7) Creating a Classic Film by string ('C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940') ---" << std::endl << std::endl;
      Film* cTestFilm6 = new Classic("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940");

      std::cout << "--- (3.8) Test of Classic Film comparison operators (by year, then month, then actor) ---" << std::endl << std::endl;

      std::cout << "CFilm6 <  CFilm5: " << (*cTestFilm6 <  *cTestFilm5) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Cangrid')" << std::endl;
      std::cout << "CFilm5 <  CFilm4: " << (*cTestFilm5 <  *cTestFilm4) <<  " (1 expected - 1940 < 1942)" << std::endl;
      std::cout << "CFilm4 <  CFilm3: " << (*cTestFilm4 <  *cTestFilm3) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Dangrid')" << std::endl;
      std::cout << "CFilm3 <  CFilm2: " << (*cTestFilm3 <  *cTestFilm2) <<  " (1 expected - Year==, 8 < 11)" << std::endl;
      std::cout << "CFilm2 <  CFilm1: " << (*cTestFilm2 <  *cTestFilm1) <<  " (1 expected - Year==, Month==, 'Bonna' < 'Langrid')" << std::endl;
      std::cout << "CFilm1 <  CFilm6: " << (*cTestFilm1 <  *cTestFilm6) <<  " (0 expected - 1940 !< 1942)" << std::endl;
      std::cout << std::endl;

      delete cTestFilm1;
      delete cTestFilm2;
      delete cTestFilm3;
      delete cTestFilm4;
      delete cTestFilm5;
      delete cTestFilm6;

      std::cout << "--- (3.9) Test of Classic Film factory construction ---" << std::endl << std::endl;

      // TODO: High chance of memory leak in this area of code
      Film* cTestFilm7 = nullptr;
      cTestFilm7 = cTestFilm7->makeFilm("C, 10, Michael Curtiz, Casablanca, Bonna Beed 11 1940");
      std::cout << "Title:        " << cTestFilm7->getTitle() << std::endl;
      std::cout << "Stock:        " << cTestFilm7->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << cTestFilm7->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << cTestFilm7->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << cTestFilm7->getGenre() << std::endl;
      std::cout << "Director:     " << cTestFilm7->getDirector() << std::endl;
      std::cout << "Actor:        " << cTestFilm7->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (3.10) Test of factory-built method calls ---" << std::endl << std::endl;

      std::cout << "CFilm7 == CFilm7: " << (*cTestFilm7 ==  *cTestFilm7) <<  " (1 expected - should utilize Classic::operator==() )" << std::endl;

      delete cTestFilm7;

      std::cout << std::endl;

      std::cout << std::endl;

      std::cout << "--- END CLASSIC FILM CLASS TESTS ---" << std::endl << std::endl;
   } // END CLASSIC FILM SUBCLASS TESTS


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       DRAMA FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {
      std::cout << "--- (4.0) BEGIN DRAMA FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (4.1) Creating a Drama Film by string ('D, 10, Blint Eastwood, Funforgiven, 1992') ---" << std::endl << std::endl;
      Film* dTestFilm1 = new Drama("D, 10, Blint Eastwood, Funforgiven, 1992");
      std::cout << "Title:        " << dTestFilm1->getTitle() << std::endl;
      std::cout << "Stock:        " << dTestFilm1->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << dTestFilm1->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << dTestFilm1->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << dTestFilm1->getGenre() << std::endl;
      std::cout << "Director:     " << dTestFilm1->getDirector() << std::endl;
      std::cout << "Actor:        " << dTestFilm1->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (4.2) Creating a Drama Film by string ('D, 10, Blint Eastwood, Unforgiven, 1992') ---" << std::endl << std::endl;

      Film* dTestFilm2 = new Drama("D, 10, Blint Eastwood, Unforgiven, 1992");
      std::cout << "Title:        " << dTestFilm2->getTitle() << std::endl;
      std::cout << "Stock:        " << dTestFilm2->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << dTestFilm2->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << dTestFilm2->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << dTestFilm2->getGenre() << std::endl;
      std::cout << "Director:     " << dTestFilm2->getDirector() << std::endl;
      std::cout << "Actor:        " << dTestFilm2->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (4.3) Test of Drama Film comparison operators (by Director, then Title) ---" << std::endl << std::endl;

      std::cout << "(" << dTestFilm1->getDirector() << ":" << dTestFilm1->getTitle() <<
              ") vs (" << dTestFilm2->getDirector() << ":" << dTestFilm2->getTitle() <<
              ")" << std::endl;
      std::cout << "DFilm1 == DFilm2: " << (*dTestFilm1 == *dTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "DFilm1 >  DFilm2: " << (*dTestFilm1 >  *dTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "DFilm1 <  DFilm2: " << (*dTestFilm1 <  *dTestFilm2) <<  " (1 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (4.4) Creating a Drama Film by string ('D, 10, Clint Eastwood, Funforgiven, 1992') ---" << std::endl << std::endl;
      Film* dTestFilm3 = new Drama("D, 10, Clint Eastwood, Funforgiven, 1992");

      std::cout << "--- (4.5) Creating a Drama Film by string ('D, 10, Clint Eastwood, Unforgiven, 1992') ---" << std::endl << std::endl;
      Film* dTestFilm4 = new Drama("D, 10, Clint Eastwood, Unforgiven, 1992");

      std::cout << "--- (4.6) Test of Drama Film comparison operators (by director, then title) ---" << std::endl << std::endl;

      std::cout << "DFilm4 >  DFilm3: " << (*dTestFilm4 >  *dTestFilm3) <<  " (1 expected - 'Clint' == 'Clint', 'Unforgiven' > 'Funforgiven')" << std::endl;
      std::cout << "DFilm3 >  DFilm2: " << (*dTestFilm3 >  *dTestFilm2) <<  " (1 expected - 'Clint' > 'Blint')" << std::endl;
      std::cout << "DFilm2 >  DFilm1: " << (*dTestFilm2 >  *dTestFilm1) <<  " (1 expected - 'Clint' == 'Clint', 'Unforgiven' > 'Funforgiven')" << std::endl;
      std::cout << "DFilm1 >  DFilm4: " << (*dTestFilm1 >  *dTestFilm4) <<  " (0 expected - 'Blint' !> 'Clint')" << std::endl;
      std::cout << std::endl;

      delete dTestFilm1;
      delete dTestFilm2;
      delete dTestFilm3;
      delete dTestFilm4;

      std::cout << "--- (4.7) Test of Drama Film factory construction ---" << std::endl << std::endl;

      // TODO: High chance of memory leak in this area of code
      Film* dTestFilm7 = nullptr;
      dTestFilm7 = dTestFilm7->makeFilm("D, 10, Clint Eastwood, Unforgiven, 1992");
      std::cout << "Title:        " << dTestFilm7->getTitle() << std::endl;
      std::cout << "Stock:        " << dTestFilm7->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << dTestFilm7->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << dTestFilm7->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << dTestFilm7->getGenre() << std::endl;
      std::cout << "Director:     " << dTestFilm7->getDirector() << std::endl;
      std::cout << "Actor:        " << dTestFilm7->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (4.8) Test of factory-built method calls ---" << std::endl << std::endl;

      std::cout << "DFilm7 == DFilm7: " << (*dTestFilm7 ==  *dTestFilm7) <<  " (1 expected - should utilize Drama::operator==() )" << std::endl;

      delete dTestFilm7;

      std::cout << std::endl;

      std::cout << "--- END DRAMA FILM CLASS TESTS ---" << std::endl << std::endl;

   } // END DRAMA FILM SUBCLASS TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       COMEDY FILM SUBCLASS TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   // Note: Sort by Title, then Year
   if (false) {

      std::cout << "--- (5.0) BEGIN COMEDY FILM CLASS TESTS ---" << std::endl << std::endl;

      std::cout << "--- (5.1) Creating a Comedy Film by string ('F, 10, Nora Ephron, You've Got Mail, 1998') ---" << std::endl << std::endl;
      Film* fTestFilm1 = new Comedy("F, 10, Nora Ephron, You've Got Mail, 1998");
      std::cout << "Title:        " << fTestFilm1->getTitle() << std::endl;
      std::cout << "Stock:        " << fTestFilm1->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << fTestFilm1->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << fTestFilm1->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << fTestFilm1->getGenre() << std::endl;
      std::cout << "Director:     " << fTestFilm1->getDirector() << std::endl;
      std::cout << "Actor:        " << fTestFilm1->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (5.2) Creating a Comedy Film by string ('F, 10, Nora Ephron, You've Got Mail, 2000') ---" << std::endl << std::endl;

      Film* fTestFilm2 = new Comedy("F, 10, Nora Ephron, You've Got Mail, 2000");
      std::cout << "Title:        " << fTestFilm2->getTitle() << std::endl;
      std::cout << "Stock:        " << fTestFilm2->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << fTestFilm2->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << fTestFilm2->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << fTestFilm2->getGenre() << std::endl;
      std::cout << "Director:     " << fTestFilm2->getDirector() << std::endl;
      std::cout << "Actor:        " << fTestFilm2->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (5.3) Test of Comedy Film comparison operators (by Title, then Year) ---" << std::endl << std::endl;

      std::cout << "(" << fTestFilm1->getDirector() << ":" << fTestFilm1->getTitle() <<
              ") vs (" << fTestFilm2->getDirector() << ":" << fTestFilm2->getTitle() <<
              ")" << std::endl;
      std::cout << "FFilm1 == FFilm2: " << (*fTestFilm1 == *fTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "FFilm1 >  FFilm2: " << (*fTestFilm1 >  *fTestFilm2) <<  " (0 expected)" << std::endl;
      std::cout << "FFilm1 <  FFilm2: " << (*fTestFilm1 <  *fTestFilm2) <<  " (1 expected)" << std::endl;
      std::cout << std::endl;

      std::cout << "--- (5.4) Creating a Comedy Film by string ('F, 10, Quora Ephron, Zooz Got Mail, 1998') ---" << std::endl << std::endl;
      Film* fTestFilm3 = new Comedy("F, 10, Quora Ephron, Zooz Got Mail, 1998");

      std::cout << "--- (5.5) Creating a Comedy Film by string ('F, 10, Quora Ephron, Zooz Got Mail, 2000') ---" << std::endl << std::endl;
      Film* fTestFilm4 = new Comedy("F, 10, Quora Ephron, Zooz Got Mail, 2000");

      std::cout << "--- (5.6) Test of Comedy Film comparison operators (by title, then year) ---" << std::endl << std::endl;

      std::cout << "FFilm4 >  FFilm3: " << (*fTestFilm4 >  *fTestFilm3) <<  " (1 expected - 'Zooz' == 'Zooz', 2000 > 1998)" << std::endl;
      std::cout << "FFilm3 >  FFilm2: " << (*fTestFilm3 >  *fTestFilm2) <<  " (1 expected - 'Zooz' > 'You've')" << std::endl;
      std::cout << "FFilm2 >  FFilm1: " << (*fTestFilm2 >  *fTestFilm1) <<  " (1 expected - 'You've' == 'You've', 2000 > 1998)" << std::endl;
      std::cout << "FFilm1 >  FFilm4: " << (*fTestFilm1 >  *fTestFilm4) <<  " (0 expected - 'You've' !> 'Zooz')" << std::endl;
      std::cout << std::endl;

      delete fTestFilm1;
      delete fTestFilm2;
      delete fTestFilm3;
      delete fTestFilm4;

      std::cout << "--- (5.7) Test of Comedy Film factory construction ---" << std::endl << std::endl;

      // TODO: High chance of memory leak in this area of code
      Film* fTestFilm7 = nullptr;
      fTestFilm7 = fTestFilm7->makeFilm("F, 10, Nora Ephron, You've Got Mail, 1998");
      std::cout << "Title:        " << fTestFilm7->getTitle() << std::endl;
      std::cout << "Stock:        " << fTestFilm7->getStock() << std::endl;
      std::cout << "ReleaseMonth: " << fTestFilm7->getReleaseMonth() << std::endl;
      std::cout << "ReleaseYear:  " << fTestFilm7->getReleaseYear() << std::endl;
      std::cout << "Genre:        " << fTestFilm7->getGenre() << std::endl;
      std::cout << "Director:     " << fTestFilm7->getDirector() << std::endl;
      std::cout << "Actor:        " << fTestFilm7->getActor() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (5.8) Test of factory-built method calls ---" << std::endl << std::endl;

      std::cout << "FFilm7 == FFilm7: " << (*fTestFilm7 ==  *fTestFilm7) <<  " (1 expected - should utilize Comedy::operator==() )" << std::endl;

      delete fTestFilm7;

      std::cout << std::endl;


      std::cout << "--- END COMEDY FILM CLASS TESTS ---" << std::endl << std::endl;
   } // END COMEDY FILM SUBCLASS TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CUSTOMER DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (6.0) START CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

      std::cout << "--- (6.1) Creating a default CustDB... ---" << std::endl << std::endl;

      CustDB testCustDB = CustDB();

      std::cout << "--- (6.2) Creating a transaction from string 'B 1111 D F Ferries and You: A Primer, 2018'... ---" << std::endl << std::endl;

      Trans testBorrow = Trans("B 111 D F Ferries and You: A Primer, 2018");
      Trans testReturn = Trans("R 111 D F Ferries and You: A Primer, 2018");

      std::cout << "--- (6.3) Creating two new customers... ---" << std::endl << std::endl;
      // 1111 Jane Doe
      // 9000 Boaty McBoatface
      Cust* testCustomer1 = new Cust("Jane", "Doe", 111);
      Cust* testCustomer2 = new Cust("Boaty", "McBoatface", 9000);

      std::cout << "--- (6.4) Customer 1 & 2 constructor results: ---" << std::endl << std::endl;

      std::cout << testCustomer1->toString() << std::endl;
      std::cout << testCustomer2->toString() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (6.5) Testing appendHistory(string)... ---" << std::endl << std::endl;

      testCustomer1->appendHistory(testBorrow.toString(), testBorrow.getType(), testBorrow.getTitle());
      std::cout << "testBorrow.toString(): " << testBorrow.toString() << std::endl;
      std::cout << "testBorrow.getType() : " << testBorrow.getType() << std::endl;
      std::cout << "testBorrow.getTitle(): " << testBorrow.getTitle() << std::endl;
      std::cout << std::endl;

      std::cout << "--- (6.6) Checking the history of Cust1 after appendHistory(): ---" << std::endl << std::endl;

      std::cout << testCustomer1->getHistory() << std::endl;

      std::cout << "--- (6.7) Test if Cust1 has a copy of 'Ferries and You: A Primer': ---" << std::endl << std::endl;

      std::cout << testCustomer1->isCheckedOut("Ferries and You: A Primer") << " ('1' expected)" << std::endl << std::endl;

      std::cout << "--- (6.8) Test if Cust1 has a copy of 'Jurassic Park': ---" << std::endl << std::endl;

      std::cout << testCustomer1->isCheckedOut("Jurassic Park") << " ('0' expected)" << std::endl << std::endl;

      std::cout << "--- (6.9) Execute a return transaction via Cust::appendHistory()... ---" << std::endl << std::endl;

      testCustomer1->appendHistory(testReturn.toString(), testReturn.getType(), testReturn.getTitle());

      std::cout << "--- (6.10) Test if Cust1 has a copy of 'Ferries and You: A Primer': ---" << std::endl << std::endl;

      std::cout << testCustomer1->isCheckedOut("Ferries and You: A Primer") << " ('0' expected)" << std::endl << std::endl;

      std::cout << "--- (6.11) Test if Cust1 has a copy of 'Jurassic Park': ---" << std::endl << std::endl;

      std::cout << testCustomer1->isCheckedOut("Jurassic Park") << " ('0' expected)" << std::endl << std::endl;

      std::cout << "--- (6.12) Inserting Cust1 and Cust2 to database... ---" << std::endl << std::endl;

      testCustDB.insertCustomer(testCustomer1);
      testCustDB.insertCustomer(testCustomer2);

      std::cout << "--- (6.13) Checking insertion results: ---" << std::endl << std::endl;

      std::cout << testCustDB.toString() << std::endl;

      std::cout << "--- (6.14) Acquire customer history @ 111: ---" << std::endl << std::endl;

      Cust* tgtCust = testCustDB.getCustomerAt(111);
      std::cout << tgtCust->getHistory() << std::endl;

      std::cout << "--- END CUSTOMER DATABASE TESTS ---" << std::endl << std::endl;

   } // END CUSTOMER DATABASE TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INV DATABASE TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (7.0) START INVENTORY DATABASE TESTS ---" << std::endl << std::endl;

      // Create a new inventory database object
      std::cout << "--- (7.1) Creating an empty InvDB object... ---" << std::endl << std::endl;
      InvDB testInvDB;

      std::cout << "--- (7.2) Create an InvDB object from bulk input... ---" << std::endl << std::endl;
      std::ifstream inventoryFile("data4movies.txt");
      InvDB testInvDBBulk(inventoryFile);


      // Create three new films
      std::cout << "--- (7.3) Creating three new films... ---" << std::endl << std::endl;

      // Attempt to add these films to the inventory database
      std::cout << "--- (7.4) Adding films to the testInvDB... ---" << std::endl << std::endl;
      testInvDB.addFilm("F, 10, Nora Ephron, Sleepless in Seattle, 1993");
      testInvDB.addFilm("D, 10, Barry Levinson, Good Morning Vietnam, 1997");
      testInvDB.addFilm("D, 10, Jonathan Demme, Silence of the Lambs, 1991");
      testInvDB.addFilm("C, 10, Jonathan Demme, Something Different, Bill Frank 2 1991");
      testInvDB.addFilm("C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939");
   
      // Test Display method
      std::cout << std::endl;
      std::cout << "--- (7.6) State of testInvDBBulk: ---" << std::endl;
      testInvDBBulk.display();
      std::cout << std::endl;

      std::cout << "--- (7.5) State of testInvDB: ---" << std::endl;
      testInvDB.display();
      std::cout << std::endl;

      testInvDB.addFilm("C, 10, Victor Fleming, The Wizard of Oz, Bob Barker 7 1939");
   
      // Create borrow transactions
      std::cout << "--- (7.7) Test Transactions ---" << std::endl << std::endl;

      // Basic borrow and return test
      std::cout << "--- Borrow and Return: Comedies" << std:: endl;
      Trans BTestF = Trans("B 2000 D F Sleepless in Seattle, 1993");
      testInvDB.adjustStock(BTestF);

      std::cout << "--- After one borrow ---" << std:: endl;
      testInvDB.display();
      std::cout << std::endl;

      Trans RTestF = Trans("R 2000 D F Sleepless in Seattle, 1993");
      testInvDB.adjustStock(RTestF);

      std::cout << "--- After one return ---" << std:: endl;
      testInvDB.display();
      std::cout << std::endl;

      // Borrow past stock value
      std::cout << "--- Borrow past inventory limit: Dramas" << std:: endl;
      Trans BTestD = Trans("B 1000 D D Barry Levinson, Good Morning Vietnam,");
      // borrow 9 copies of this movie
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);
      testInvDB.adjustStock(BTestD);

      std::cout << "--- DB after 10th borrow (stock should be 0) ---" << std::endl;
      testInvDB.adjustStock(BTestD);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- DB after 11th borrow --- (should throw stock error)" << std::endl;
      testInvDB.adjustStock(BTestD);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- DB after 10th borrow and 1 return --- (stock should be 1)" << std::endl;
      Trans RTestD = Trans("R 1000 D D Barry Levinson, Good Morning Vietnam,");
      testInvDB.adjustStock(RTestD);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- Borrow past inventory limit: Classics" << std:: endl;
      Trans BTestC = Trans("B 1000 D C 7 1939 Bob Barker");
      // borrow 9 copies of this movie
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);
      testInvDB.adjustStock(BTestC);

      std::cout << "--- DB after 10th borrow (stock should be 0) ---" << std::endl;
      testInvDB.adjustStock(BTestC);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- DB after 11th borrow --- (should borrow from Judy Garland 7 1939)" << std::endl;
      testInvDB.adjustStock(BTestC);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- DB after 11th borrow and 1 return --- (stock should be 1, Judy Garland should be 9)" << std::endl;
      Trans RTestC = Trans("R 1000 D C 7 1939 Bob Barker");
      testInvDB.adjustStock(RTestC);

      testInvDB.display();
      std::cout << std::endl;

      std::cout << "--- (7.8) Test getCTitleByTuple ---" << std::endl << std::endl;
      std::string test = testInvDB.getCTitleByTuple(7, 1939, "Judy Garland");
      std::cout << "Test Title: '"<< test << "' ('The Wizard of Oz' expected)" << std::endl;
      std::string test2 = testInvDB.getCTitleByTuple(7, 1939, "Bob Barker");
      std::cout << "Test Title: '"<< test2 << "' ('The Wizard of Oz' expected)" << std::endl;

      std::cout << "--- END INVENTORY DATABASE TESTS ---" << std::endl << std::endl;

   } // END INVENTORY DATABASE TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK CUSTOMERDB INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (8.0) START BULK CUSTOMERDB INPUT TESTS ---" << std::endl << std::endl;

      std::cout << "--- (8.1) Testing customerDB bulk inputs... ---" << std::endl << std::endl;

      std::cout << "--- (8.2) Create an empty CustDB object ---" << std::endl << std::endl;

      CustDB custDB;

      std::cout << "--- (8.3) Capture bulk input to fileStream ---" << std::endl << std::endl;

      std::ifstream customerFile("data4customers.txt");

      std::cout << "--- (8.4) Sending bulk commands to CustDB object... ---" << std::endl << std::endl;

      bulkReadCust(customerFile, custDB);

      std::cout << "--- (8.7) Check state of CustDB after bulk input: ---" << std::endl << std::endl;

      std::cout << custDB.toString() << std::endl;

      std::cout << "--- END BULK CUSTOMERDB INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK CUSTOMERDB INPUT TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK INVENTORYDB INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (9.0) START BULK INVENTORYDB INPUT TESTS ---" << std::endl << std::endl;

      std::cout << "--- (9.1) Testing inventoryDB bulk inputs... ---" << std::endl << std::endl;

      std::cout << "--- (9.2) Create an empty InvDB object ---" << std::endl << std::endl;

      InvDB invDB;

      std::cout << "--- (9.3) Capture bulk input to fileStream ---" << std::endl << std::endl;

      std::ifstream inventoryFile("data4movies.txt");

      std::cout << "--- (9.4) Sending bulk commands to InvDB object... ---" << std::endl << std::endl;

      bulkReadInv(inventoryFile, invDB);

      std::cout << "--- (9.5) Check state of InvDB after bulk input: ---" << std::endl << std::endl;

      std::cout << invDB.toString() << std::endl;

      std::cout << "--- END BULK INVENTORYDB INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK INVENTORYDB INPUT TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       BULK COMMAND INPUT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (false) {

      std::cout << "--- (10.0) START BULK TRANSACTION INPUT TESTS ---" << std::endl << std::endl;

      std::cout << "--- (10.1) Testing Transaction bulk inputs... ---" << std::endl << std::endl;

      std::cout << "--- (10.2) Create empty CustDB and InvDB objects ---" << std::endl << std::endl;

      CustDB custDB;
      InvDB invDB;

      std::cout << "--- (10.3) Capture bulk inputs to fileStream ---" << std::endl << std::endl;

      std::ifstream customerFile("data4customers.txt");
      std::ifstream inventoryFile("data4movies.txt");
      std::ifstream transactionFile("data4commands.txt");

      std::cout << "--- (10.4) Sending bulk commands to CustDB and InvDB objects ---" << std::endl << std::endl;

      bulkReadCust(customerFile, custDB);
      bulkReadInv(inventoryFile, invDB);

      std::cout << "--- (10.5) Check state of InvDB and CustDB after bulk input: ---" << std::endl << std::endl;

      std::cout << invDB.toString() << std::endl << std::endl;
      std::cout << custDB.toString() << std::endl << std::endl;

      std::cout << "--- (10.6) Process bulk transactions ---" << std::endl << std::endl;

      bulkReadTrans(transactionFile, custDB, invDB);

      std::cout << "--- (10.5) Check state of InvDB and CustDB after bulk transactions: ---" << std::endl << std::endl;

      std::cout << invDB.toString() << std::endl << std::endl;
      std::cout << custDB.toString() << std::endl << std::endl;

      std::cout << "--- END BULK INVENTORYDB INPUT TESTS ---" << std::endl << std::endl;

   } // END BULK COMMAND INPUT TESTS



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       FOR REALSIES EXECUTION
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   if (true) {

      // Acquire the relevant files
      std::ifstream commandFile("data4commands.txt");
      std::ifstream customerFile("data4customers.txt");
      std::ifstream inventoryFile("data4movies.txt");

     // Create a customer database
      CustDB custDB;
      // Read all customer commands into it
      bulkReadCust(customerFile, custDB);

      // Create an inventory database
      InvDB invDB;
      // Read all inventory commands into it
      bulkReadInv(inventoryFile, invDB);

      // Read, parse, verify, and forward all transaction commands to the databases
      bulkReadTrans(commandFile, custDB, invDB);

   } // Closing if - End of for realsies execution "unit test"

   return (0);
} // Closing main()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       METHOD IMPLEMENTATIONS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #bulkReadCust(ifstream&, CustDB)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted customer command file
// Params:  ifstream& arg1 - The target text file containing customer commands
//          CustDB arg2 - The receiving Customer database
// PreCons: A valid CustDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target CustDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalCustCmd() - Verifies all legality checks of the command
void bulkReadCust(std::ifstream& custFile, CustDB& tgtDB) {
   while (!custFile.eof()) {
      // Get a line of text (one command)

      std::string command;
      std::getline(custFile, command);

      // If the command is legal...
      if (isLegalCustCmd(command, tgtDB)) {
         // Acquire info by...
         // Sample input
         // 1111 Mouse Mickey
         // Prepare variables
         int custID;
         std::string nameL;
         std::string nameF;

         // Encapsulate string in a stringstream
         std::stringstream stream(command);

         // Parse stream to variables
         stream >> custID;
         stream >> nameL;
         stream >> nameF;

         // Make a customer from variables
         Cust* newCust = new Cust(nameF, nameL, custID);

         // Send customer to the Inventory Database
         tgtDB.insertCustomer(newCust);

      } // Closing if - Legal inventory command sent

      // Otherwise, command was not legal, so do nothing
      // Repeat

   } // Closing while - All lines of input consumed
} // Closing bulkReadCust()

// (+) --------------------------------|
// #bulkReadInv(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted inventory command file
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The receiving Inventory database
// PreCons: A valid InvDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target InvDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalInvCmd() - Verifies all legality checks of the command
void bulkReadInv(std::ifstream& invFile, InvDB& tgtDB) {
   // While there is still filestream to read
   while (!invFile.eof()) {
      // Get a line of text (one command)

      std::string command;
      std::getline(invFile, command);

      // If the command is legal...
      if (isLegalInvCmd(command, tgtDB)) {

         // Send it to the Inventory Database
         tgtDB.addFilm(command);

      } // Closing if - Legal inventory command sent
   } // Closing while - All lines of input consumed
} // Closing bulkReadInv()

// (+) --------------------------------|
// #bulkReadTrans(ifstream&, CustDB&, InvDB&)
//-------------------------------------|
// Desc:    Bulk reader of a correctly formatted inventory command file
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The receiving Inventory database
// PreCons: A valid InvDB object must exist.
// PosCons: The ifstream has been consumed
//          All valid commands have been sent to the target InvDB
//          Does not guarantee correct handling of commands at destination DB
//          Does not handle any error reporting
// RetVal:  None
// MetCall: isLegalInvCmd() - Verifies all legality checks of the command
void bulkReadTrans(std::ifstream& commandFile, CustDB& tgtCustDB, InvDB& tgtInvDB) {
   // Generate Transactions from the CommandFile and send Transaction impacts to the appropriate locations
   int counter = 1;
   while (!commandFile.eof()) {
      // Read the next relevant line of command
      std::string command;
      std::getline(commandFile, command);

      counter++;

      // I and H cases
      // If the command is an 'I'
      if (command[0] == 'I') {
         // Ping invDB for execution
         tgtInvDB.display();
         std::cout << std::endl;
      }

      // If the command is an 'H'
      else if (command[0] == 'H') {
         // Convert the command line to a string stream
         std::stringstream stream;
         stream << command;
         // Discard leading character
         char temp;
         stream >> temp;
         // Capture the int
         int custID;
         stream >> custID;
         // If the custID is out of range, halt
         if (custID < 0 || custID > 9999) {
            std::cout << "History Command error: Customer ID out of range (0-9999)" << std::endl;
         }
         // If the custDB does not have this customer...
         else if (!tgtCustDB.doesContain(custID)) {
            std::cout << "History Command error: No such Customer" << std::endl;
         }
         // Otherwise...
         else {
            // Output the history of the customer at this position
            std::cout << tgtCustDB.getCustomerAt(custID)->getHistory() << std::endl << std::endl;
         }
      } // Closing if - 'H' condition handled

      else {// Prepare to hold a transaction
         Trans* currTrans = nullptr;
         // If the command is legal (based on the command and DB states)
         if (isLegalTransCmd(command, tgtCustDB, tgtInvDB)) {
            // Create a transaction from it
            currTrans = new Trans(command);
            // Aggregate inventory information from the databases to add needed info to the transaction
            padOut(currTrans, tgtInvDB);
            // currTrans->debug(); // DEBUG
            // Send the Transaction to the Databases for execution
            tgtInvDB.adjustStock(*currTrans);
            tgtCustDB.appendHistory(*currTrans);
         }
         else {
            std::cout << std::endl;
         }


         // deallocate current transaction now that it's been used
         if (currTrans != nullptr) {
            delete currTrans;
         }
         std::cout << ""; // DEBUG
      }
   } // Closing while - All lines of command read from file / filestream
   std::cout << "--- All command lines parsed ---" << std::endl << std::endl;

} // Closing bulkReadTrans()

// (+) --------------------------------|
// #isLegalCustCmd(ifstream&, CustDB&)
//-------------------------------------|
// Desc:    Verifies the legality of a customer command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          CustDB arg2 - The database to query
// PreCons: A valid CustDB object must exist.
// PosCons: Both the CustDB and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DB
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are reported
//          bool false - At least one illegal condition was detected
// MetCall: CustDB::isValid() - Verifies all legality checks within the database
bool isLegalCustCmd(std::string command, CustDB& tgtDB) {
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";

   // Initialize field variables
   int custID = 1234512345;
   std::string nameL = "";
   std::string nameF = "";

   // Parse fields
   std::stringstream stream(command);
   stream >> custID;
   stream >> nameL;
   stream >> nameF;

   // Verify that field1 is within expected value range
   if (custID == 1234512345) {
      // If not, append report
      errorLog = errorLog + "   - No customer ID entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that the customerID is within range
   if (custID != 1234512345 && (custID < 0 || custID > 9999)) {
      // If not, append report
      errorLog = errorLog + "   - Invalid customer ID entered (out of range)" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Check if both the first name and last name were entered
   if (nameF == "" || nameL == "") {
      // If not, append report
      errorLog = errorLog + "   - No first or last name entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Any other ways a customer command can be invalid?

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Customer Command error ('" << command << "'):" << std::endl;
      std::cout << errorLog << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = tgtDB.isValid(command);
   // Note: tgtDB.isLegal() handles its own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalCustCmd()

// (+) --------------------------------|
// #isLegalInvCmd(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Verifies the legality of an inventory command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          InvDB arg2 - The database to query
// PreCons: A valid InvDB object must exist.
// PosCons: Both the InvDB and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DB
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are reported
//          bool false - At least one illegal condition was detected
// MetCall: InvDB::isValid() - Verifies all legality checks within the database
bool isLegalInvCmd(std::string command, InvDB& tgtDB) {
   std::string origCommand = command;
   // Set flag
   bool isLegal = true;
   // Begin error log
   std::string errorLog = "";
   int currentYear = 2018;

   // Parse command data
   std::string delim = ", ";
   std::string cmdData[5];

   // Get each term from the string
   for (int i = 0; i < 5; i++) {
      cmdData[i] = command.substr(0, command.find(delim));
      command.erase(0, command.find(delim) + delim.length());
   }

   // Test if genre is within range first
   char genre = cmdData[0][0];
   if (genre != 'C' && genre != 'F' && genre != 'D') {
      std::cout << "Inventory Command error ('" << origCommand << "'):" << std::endl;
      std::cout <<"   - Invalid genre: '" << genre << "'" << std::endl << std::endl;
      return(false);
   }

   // Verify that quantity is non-zero
   int stock = std::stoi(cmdData[1]);
   if (stock <= 0) {
      // If not, append report
      errorLog = errorLog + "   - Zero quantity (non-inventory)" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that a director is entered
   std::string director = cmdData[2];
   if (director == "") {
      // If not, append report
      errorLog = errorLog + "   - No director specified" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Verify that a film name is entered
   std::string title = cmdData[3];
   if (title == "") {
      // If not, append report
      errorLog = errorLog + "   - No film title entered" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // In the case of classic films only, verify that an actor is specified
   if (genre == 'C') {

      // split the last two items by spaces to incorprate the major actor and date
      delim = " ";

      for (int i = 0; i < 4; i++) {
         cmdData[i] = command.substr(0, command.find(delim));
         command.erase(0, command.find(delim) + delim.length());
      }

      std::string actor = cmdData[0] + " " + cmdData[1]; // strings: firstName lastName
      int releaseMonth = std::stoi(cmdData[2]); // int
      int releaseYear = std::stoi(cmdData[3]); // int

      if (actor == "") {
         // If not, append report
         errorLog = errorLog + "   - No actor/actress specified" + "\n";
         // And toggle the flag
         isLegal = false;
      }

      // In the case of classic films only, verify that a release month is specified
      if (releaseMonth < 1 || releaseMonth > 12) {
         // If not, append report
         errorLog = errorLog + "   - Release month not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      if (releaseYear < 1880 || releaseYear > 2018) {
         // If not, append report
         errorLog = errorLog + "   - Release year not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }
   // if this isn't a classic, check the year normally
   else {
      int releaseYear = std::stoi(cmdData[4]);
      if (releaseYear < 1880 || releaseYear > currentYear) {
         // If not, append report
         errorLog = errorLog + "   - Release year not properly entered" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Inventory Command error ('" << origCommand << "'):" << std::endl;
      std::cout << errorLog << std::endl << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database state, so check that
   isLegal = tgtDB.isLegal(origCommand);
   // Note: tgtDB.isLegal() handles its own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalInvCmd()

// (+) --------------------------------|
// #trim(std::string)
//-------------------------------------|
// Desc:    Trims whitespace from the end of a string
// Params:  string by reference
// PreCons: NULL
// PosCons: NULL
// RetVal:  NULL
// MetCall: NULL
void trim(std::string& str) {
   std::string whitespaces(" \t\f\v\n\r");
   int pos = str.find_last_not_of(whitespaces);
   if (pos != std::string::npos) {
      str.erase(pos + 1);
   }
}

// (+) --------------------------------|
// #isLegalTransCmd(ifstream&, CustDB&, InvDB&)
//-------------------------------------|
// Desc:    Verifies the legality of a transaction command line
// Params:  ifstream& arg1 - The target text file containing inventory commands
//          InvDB arg2 - The customer database to query
//          InvDB arg3 - The inventory database to query
// PreCons: A valid InvDB object must exist
//          A valid CustDB object must exist
// PosCons: Both databases and this method have examined the command for legality
//          Does not guarantee correct handling of legality at destination DBs
//          All errors have been reported
// RetVal:  bool true - No illegal conditions are identified
//          bool false - At least one illegal condition was detected
// MetCall: CustDB::isValid() - Verifies all legality checks within the customer DB
//          InvDB::isValid() - Verifies all legality checks within the inventory DB
bool isLegalTransCmd(std::string command, CustDB& tgtCustDB, InvDB& tgtInvDB) {
   // Set flag
   bool isLegal = true;

   // Begin error log
   std::string errorLog = "";

   // Store command as a stream
   std::stringstream stream;
   stream << command;
   trim(command);

   int currentYear = 2018;

   // Initialize field variables
   char commandType = NULL;
   int custID = 1234512345;
   char format = NULL; // 'D' for DVD on all titles
   char genre = NULL;
   int releaseMonth = 0; // (in case of Classic)
   int releaseYear = 0;
   std::string director = "";
   std::string title = "";
   std::string actor = ""; // (in case of Classic)

   // Sample input: B 1000 D D Barry Levinson, Good Morning Vietnam,
   // Parse command type off string
   stream >> commandType;

   // Test if the commandType is within range first
   if ((commandType != 'I') && (commandType != 'H') && (commandType != 'B') && (commandType != 'R')) {

      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;

      std::cout << "   - Invalid command type: ('" << commandType << "'), discarding..." << std::endl;
      return(false);
   }

   // Finish testing for an 'I' (inventory query) command
   if (commandType == 'I' && command.size() > 2) { // If there's anything after the I...
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << "   - Invalid length of 'I' (inventory) command, halting." << std::endl;
      std::cout << "Command length: " << command.size() << std::endl;
      return(false);
   }

   // All legality checks for an 'I' command complete, so exit
   if (commandType == 'I') {
      return(isLegal);
   }

   // Parse customerID
   stream >> custID; // VERIFIED
   // std::cout << custID << "!!!";

   // Test if customerID is within range
   if (custID < 0 || custID > 9999) {
      // Append the error log
      errorLog = errorLog + "   - Customer ID out of range" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Test if customer is in the database
   if (!tgtCustDB.doesContain(custID)) {
      // Append the error log
      errorLog = errorLog + "   - Non-existent customer" + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Parse format
   stream >> format; // VERIFIED
   // std::cout << format << "!!!";

   // Test if format is within range
   if (format != 'D') {
      // Append the error log
      errorLog = errorLog + "   - Invalid media format." + "\n";
      // And toggle the flag
      isLegal = false;
   }

   // Sample input: B 1000 D D Barry Levinson, Good Morning Vietnam,
   // Parse genre
   stream >> genre; // VERIFIED
   // std::cout << "'" << genre << "' !!!";

   // Test if genre is within range
   if ((genre != 'C') && (genre != 'F') && (genre != 'D')) {
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << "   - Invalid genre, halting." << std::endl;
      std::cout << errorLog << std::endl;
      return(false);
   }

   // CLASSIC BEHAVIOR
   if (genre == 'C') {
      // Parse releaseMonth
      stream >> releaseMonth; // VERIFIED
      // Parse releaseYear
      stream >> releaseYear; // VERIFIED
      // Parse actor
      char temp = NULL;
      stream >> temp;
      stream << std::noskipws;
      while (!stream.eof()) {
         actor += temp;
         stream >> temp;
      }
      trim(actor);
      // Actor parsed - VERIFIED

      // std::cout << "(CisLegalCmd):" << actor << ":" << releaseMonth << ":" << releaseYear << ")"; // DEBUG

      // Information in hand, perform all legality checks for Classics

      // Verify that releaseMonth is within range
      if ((releaseMonth < 1) || (releaseMonth > 12)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid month (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      // Verify that releaseYear is within range
      if ((releaseYear < 1888) || (releaseYear > currentYear)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid year (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      // Verify that an actor is provided
      if (actor == "") {
         // Append the error log
         errorLog = errorLog + "   - No actor provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }


      if (isLegal) {
         // NOTE!!! CLASSIC BEHAVIOR MUST GO TO THE INVDB AND ATTEMPT TO RETRIEVE A TITLE AT THIS POINT
         // Not necessary if any tests were failed here, as the legality calls will terminate
         title = tgtInvDB.getCTitleByTuple(releaseMonth, releaseYear, actor);

         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }
   } // Classic legality tests complete


   // DRAMA BEHAVIOR
   if (genre == 'D') {

      // Sample input: B 1000 D D Gus Van Sant, Good Will Hunting,
      // Parse director
      char temp = NULL;
      stream >> temp;
      stream << std::noskipws;
      while (temp != ',') {
         director += temp;
         stream >> temp;
      } // Director parsed

      // Advance
      stream >> temp;
      stream >> temp;
      // Parse title
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Title parsed

      if (title == "") {
         // Append the error log
         errorLog = errorLog + "   - No title provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      else {
         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }

      // Information in hand, perform legality checks for Dramas
      // Verify that a director is provided
      if (director == "") {
         // Append the error log
         errorLog = errorLog + "   - No director provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   }

   // COMEDY BEHAVIOR
   if (genre == 'F') {
      // Parse title

      char temp = NULL;
      stream >> temp;
      stream << std::noskipws;
      while (temp != ',') {
         title += temp;
         stream >> temp;
      } // Title parsed

      stream >> temp;

      // Parse releaseYear
      stream >> releaseYear;

      // std::cout << "(" << title << ":" << releaseYear << ")"; // DEBUG

      // Verify that a title is provided
      if (title == "") {
         // Append the error log
         errorLog = errorLog + "   - No title provided" + "\n";
         // And toggle the flag
         isLegal = false;
      }
      else {
         // if this is a Return, check if this customer has 
         // this film currently checked out
         if (commandType == 'R' 
             && !tgtCustDB.getCustomerAt(custID)->isCheckedOut(title)) {
            // Append the error log
            errorLog = errorLog + "   - Customer has not borrowed this film" + "\n";
            // And toggle the flag
            isLegal = false;
         }
      }

      // Verify that releaseYear is within range
      if ((releaseYear < 1888) || (releaseYear > currentYear)) {
         // Append the error log
         errorLog = errorLog + "   - Invalid year (out of range)" + "\n";
         // And toggle the flag
         isLegal = false;
      }
   } // Closing Comedy behavior

   // If any test has failed, do not forward to database
   if (isLegal == false) {
      std::cout << "Transaction Command error ('" << command << "'):" << std::endl;
      std::cout << errorLog << std::endl;
      return(isLegal);
   }
   // Otherwise, this is a correctly formatted command
   // But it may still be in conflict with the database states, so check those
   if (!tgtCustDB.isValidTransCmd(custID, title, commandType) || !tgtInvDB.isValidTransCmd(command)) {
      isLegal = false;
   }
   // Note: Target databases handle their own error reporting to cout
   // Return whether the database confirmed legality or not
   return(isLegal);
} // Closing isLegalTransCmd()

// (+) --------------------------------|
// #padOut(ifstream&, InvDB&)
//-------------------------------------|
// Desc:    Acquires and appends missing information for a transaction
// Params:  transPtr* arg1 - 
//          InvDB arg2 - 
// PreCons: A valid InvDB object must exist
//          A valid transaction constructed from a legal command must exist
// PosCons: Sufficient data has been appended to the transaction to allow for proper output
// RetVal:  None
// MetCall: NULL
void padOut(Trans* transPtr, InvDB& tgtInvDB) {
   // Sample inputs:
   // B 4444 D C 2 1971 Malcolm McDowell
   // B 1000 D D Gus Van Sant, Good Will Hunting,
   // B 8000 D F You've Got Mail, 1998

   // Fields needed:
   // TYPESTRING - Got it
   // GENRESTRING - Got it
   // TITLE - Classics only
   // RELEASEMONTH - Got it, if applicable
   // RELEASEYEAR - Dramas only

   // Classics
   if (transPtr->getGenre() == 'C') {
      // TITLE -  Get the film title out of the InvDB based on director/title
      std::string title = tgtInvDB.getCTitleByTuple(transPtr->getReleaseMonth(), transPtr->getReleaseYear(), transPtr->getActor());
      transPtr->setTitle(title);
   }

   // Drama
   if (transPtr->getGenre() == 'D') {
      // RELEASEYEAR -  Get the release date out of the InvDB based on director/title
      int year = tgtInvDB.getDYearByTuple(transPtr->getDirector(), transPtr->getTitle());
      transPtr->setReleaseYear(year);
   }

   // Transaction holds sufficient data for CustDB to process
}

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - driver.cpp
