//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file polarisation/Pol01/src/EventAction.cc
/// \brief Implementation of the EventAction class
//
// $Id: EventAction.cc 98772 2016-08-09 14:25:31Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "EventAction.hh"
#include "RunAction.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <chrono>
#include <fstream>
#include <random>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction * ra)
   : G4UserEventAction(),
   fRunAction(ra)
{
   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
  // fEdepNaI1 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;
   fEdepNaI7 = 0.;
   fEdepNaI8 = 0.;
   fEdepNaI9 = 0.;

   fEdepNaI12 = 0.;
   fEdepNaI13 = 0.;
   fEdepNaI14 = 0.;
   fEdepNaI15 = 0.;
   fEdepNaI16 = 0.;
   fEdepNaI17 = 0.;
   fEdepNaI18 = 0.;
   fEdepNaI19 = 0.;

   LoopCounter = 12;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event*)
{

   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
  // fEdepNaI1 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;
   fEdepNaI7 = 0.;
   fEdepNaI8 = 0.;
   fEdepNaI9 = 0.;

   fEdepNaI12 = 0.;
   fEdepNaI13 = 0.;
   fEdepNaI14 = 0.;
   fEdepNaI15 = 0.;
   fEdepNaI16 = 0.;
   fEdepNaI17 = 0.;
   fEdepNaI18 = 0.;
   fEdepNaI19 = 0.;
  }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::AddEdep(G4int iVol, G4double edep)
{
   if (iVol == 1)
   {
      fEdepLaBr1 += edep;
   }
   else if (iVol == 2)
   {
      fEdepLaBr2 += edep;
   }


   //else if (iVol == 3)
   //{
   //   fEdepNaI1 += edep;
   //}


   else if (iVol == 4)
   {
      fEdepNaI2 += edep;
   }
   else if (iVol == 5)
   {
      fEdepNaI3 += edep;
   }
   else if (iVol == 6)
   {
      fEdepNaI4 += edep;
   }
   else if (iVol == 7)
   {
      fEdepNaI5 += edep;
   }
   else if (iVol == 8)
   {
      fEdepNaI6 += edep;
   }
   else if (iVol == 9)
   {
      fEdepNaI7 += edep;
   }
   else if (iVol == 10)
   {
      fEdepNaI8 += edep;
   }
   else if (iVol == 11)
   {
      fEdepNaI9 += edep;
   }



   else if (iVol == 12)
   {
      fEdepNaI12 += edep;
   }
   else if (iVol == 13)
   {
      fEdepNaI13 += edep;
   }
   else if (iVol == 14)
   {
      fEdepNaI14 += edep;
   }
   else if (iVol == 15)
   {
      fEdepNaI15 += edep;
   }
   else if (iVol == 16)
   {
      fEdepNaI16 += edep;
   }
   else if (iVol == 17)
   {
      fEdepNaI17 += edep;
   }
   else if (iVol == 18)
   {
      fEdepNaI18 += edep;
   }
   else if (iVol == 19)
   {
      fEdepNaI19 += edep;
   }

}
void EventAction::Reset()
{
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::default_random_engine generator(seed);
   std::normal_distribution<double> distribution(1.0, 0.05);
   G4double r = distribution(generator);

   fEdepNaI2 *= r; fEdepNaI3 *= r; fEdepNaI4 *= r; fEdepNaI5 *= r; fEdepNaI6 *= r; 
   fEdepNaI7 *= r; fEdepNaI8 *= r; fEdepNaI8 *= r;

   if (fEdepLaBr1>0. && fEdepLaBr2> 0. && (fEdepNaI2> 0. || fEdepNaI3> 0. ||
      fEdepNaI4> 0. || fEdepNaI5> 0. || fEdepNaI6> 0. || fEdepNaI7> 0. || fEdepNaI8> 0. || fEdepNaI9> 0.))
   {

      if (fEdepNaI12 > 0.)
      {

         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI2 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI5 = 0.0;
         if (r > 1.01 || r < 0.99)
            fEdepNaI6 = 0.0;
         fRunAction->output_to_file_Quad_Only_12(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI12, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9);
      }
      else if (fEdepNaI13 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI3 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI6 = 0.0;
         if (r > 1.01 || r < 0.99)
            fEdepNaI7 = 0.0;
         fRunAction->output_to_file_Quad_Only_13(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI13,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9, fEdepNaI2);
      }
      else if (fEdepNaI14 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI4 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI7 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI8 = 0.0;
         fRunAction->output_to_file_Quad_Only_14(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI14, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3);
      }
      else if (fEdepNaI15 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI5 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI8 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI9 = 0.0;
         fRunAction->output_to_file_Quad_Only_15(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI15,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3, fEdepNaI4);
      }
      else if (fEdepNaI16 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI6 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI9 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI2 = 0.0;
         fRunAction->output_to_file_Quad_Only_16(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI16, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5);
      }
      else if (fEdepNaI17 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI7 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI2 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI3 = 0.0;
         fRunAction->output_to_file_Quad_Only_17(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI17,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6);
      }
      else if (fEdepNaI18 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI8 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI3 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI4 = 0.0;
         fRunAction->output_to_file_Quad_Only_18(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI18, fEdepNaI8,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7);
      }
      else if (fEdepNaI19 > 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI9 = 0.0;
         if (r > 1.03 || r < 0.97)
            fEdepNaI4 = 0.0;
         if (r > 1.02 || r < 0.98)
            fEdepNaI5 = 0.0;
         fRunAction->output_to_file_Quad_Only_19(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI19,
            fEdepNaI9, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8);
      }
      else
      {
         fRunAction->output_to_file_Triple_Only(fEdepLaBr1, fEdepLaBr2,
            0, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6,
            fEdepNaI7, fEdepNaI8,
            fEdepNaI9);
      }
   }
   

   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
  // fEdepNaI1 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;
   fEdepNaI7 = 0.;
   fEdepNaI8 = 0.;
   fEdepNaI9 = 0.;
    
    
   fEdepNaI12 = 0.;
   fEdepNaI13 = 0.;
   fEdepNaI14 = 0.;
   fEdepNaI15 = 0.;
   fEdepNaI16 = 0.;
   fEdepNaI17 = 0.;
   fEdepNaI18 = 0.;
   fEdepNaI19 = 0.;
/*
   if (LoopCounter >= 19)
      LoopCounter = 12;
   else
      LoopCounter++;
*/
}

void EventAction::EndOfEventAction(const G4Event*)
{
   fRunAction->EventFinished(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

