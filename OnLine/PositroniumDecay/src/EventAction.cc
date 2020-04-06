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
}

G4double EventAction::GetfEdepLaBr1()
{
   return fEdepLaBr1;
}
float GaussianDistributionValue(float seed, float mean, float standardderivation)
{
   static const float inv_sqrt_2pi = 0.3989422804014327;
   float a = (seed - mean) / standardderivation;

   return inv_sqrt_2pi / standardderivation * std::exp(-0.5f * a * a);
}
void EventAction::Reset()
{
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::default_random_engine generator(seed);
   std::normal_distribution<double> distribution(1.0, 0.05);
   G4double r = distribution(generator);

   fEdepNaI2 *= r; fEdepNaI3 *= r; fEdepNaI4 *= r; fEdepNaI5 *= r; fEdepNaI6 *= r; 

   if (fEdepLaBr1>0. && fEdepLaBr2> 0. && (fEdepNaI2> 0. || fEdepNaI3> 0. ||
      fEdepNaI4> 0. || fEdepNaI5> 0. || fEdepNaI6> 0.))
   {
      if (fEdepNaI12> 0.)
      {
         //if (r > 1.02 || r < 0.98)
         //   fEdepNaI2 = 0.0;
         //if (r > 1.03 || r < 0.97)
         //   fEdepNaI5 = 0.0;
         //if (r > 1.01 || r < 0.99)
            //fEdepNaI6 = 0.0;
         fRunAction->output_to_file_Quad_Only(fEdepLaBr1, fEdepLaBr2,
            fEdepNaI12, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6);
      }
      else
      {
         fRunAction->output_to_file_Triple_Only(fEdepLaBr1, fEdepLaBr2,
            0.0, fEdepNaI2,
            fEdepNaI3, fEdepNaI4,
            fEdepNaI5, fEdepNaI6);
      }
   }
   

   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
   fEdepNaI12 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
   fRunAction->EventFinished(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
