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
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include <fstream>
#include <chrono>
#include <random>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(RunAction * ra) 
: G4UserEventAction(), 
  fRunAction(ra)
{
   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
   fEdepNaI1 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;


   fTimeLaBr1 = -1 * s;
   fTimeLaBr2 = -1 * s;
   fTimeNaI1 = -1 * s;
   fTimeNaI2 = -1 * s;
   fTimeNaI3 = -1 * s;
   fTimeNaI4 = -1 * s;
   fTimeNaI5 = -1 * s;
   fTimeNaI6 = -1 * s;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event*)
{
   fEdepLaBr1 = 0.;
   fEdepLaBr2 = 0.;
   fEdepNaI1 = 0.;
   fEdepNaI2 = 0.;
   fEdepNaI3 = 0.;
   fEdepNaI4 = 0.;
   fEdepNaI5 = 0.;
   fEdepNaI6 = 0.;

   fStartTime = -1 * s;

   fTimeLaBr1 = -1 * s;
   fTimeLaBr2 = -1 * s;
   fTimeNaI1 = 2088 * ns;
   fTimeNaI2 = 2088 * ns;
   fTimeNaI3 = 2088 * ns;
   fTimeNaI4 = 2088 * ns;
   fTimeNaI5 = 2088 * ns;
   fTimeNaI6 = 2088 * ns;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::AddEdep(G4int iVol, G4double edep, G4double time1)
{
   // initialize t0
   G4double relTime = -1 * s;
   if ((iVol == 1 || iVol == 2) && fStartTime < 0.)
   {
      fStartTime = time1;
      if (iVol == 1)
         fTimeLaBr1 = 0;
      else if (iVol == 2)
         fTimeLaBr2 = 0;
   }
   relTime = time1 - fStartTime;
   if (iVol == 1)
   {
      fEdepLaBr1 += edep;
      if (fTimeLaBr1 < 0.)
         fTimeLaBr1 = relTime;
   }
   if (iVol == 2)
   {
      fEdepLaBr2 += edep;
      if (fTimeLaBr2 < 0.)
         fTimeLaBr2 = relTime;
   }
   if (iVol == 3)
   {
      fEdepNaI1 += edep;
      if (fTimeNaI1 == 2088 * ns)
         fTimeNaI1 = relTime;
   }
   if (iVol == 4)
   {
      fEdepNaI2 += edep;
      if (fTimeNaI2 == 2088 * ns)
         fTimeNaI2 = relTime;
   }
   if (iVol == 5)
   {
      fEdepNaI3 += edep;
      if (fTimeNaI3 == 2088 * ns)
         fTimeNaI3 = relTime;
   }
   if (iVol == 6)
   {
      fEdepNaI4 += edep;
      if (fTimeNaI4 == 2088 * ns)
         fTimeNaI4 = relTime;
   }
   if (iVol == 7)
   {
      fEdepNaI5 += edep;
      if (fTimeNaI5 == 2088 * ns)
         fTimeNaI5 = relTime;
   }
   if (iVol == 8)
   {
      fEdepNaI6 += edep;
      if (fTimeNaI6 == 2088 * ns)
         fTimeNaI6 = relTime;
   }
   



}



   //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void EventAction::EndOfEventAction(const G4Event*)
{
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::default_random_engine generator(seed);
   std::normal_distribution<double> distribution(1.0, 0.05);
   G4double r = distribution(generator);

   fEdepNaI2 *= r; fEdepNaI3 *= r; fEdepNaI4 *= r; fEdepNaI5 *= r; fEdepNaI6 *= r;

   if (fEdepLaBr1 > 0. && fEdepLaBr2 > 0.)
   {
         std::ofstream out_data;
         out_data.open("Output_Test_Double.txt", std::ios_base::app);

         out_data << fEdepLaBr1 / keV << "\t"
                  << fEdepLaBr2 / keV << "\n";
   }


   if (fEdepLaBr1>0. && fEdepLaBr2> 0. && (fEdepNaI1> 0. || fEdepNaI2> 0. || fEdepNaI3> 0. ||
      fEdepNaI4> 0. || fEdepNaI5> 0. || fEdepNaI6> 0.))
   {


      if (fEdepNaI1> 0. && (fEdepNaI2> 0. || fEdepNaI3> 0. ||
         fEdepNaI4> 0. || fEdepNaI5> 0. || fEdepNaI6> 0.))
      {
         std::ofstream out_data;
         out_data.open("Output_Test_Quads.txt", std::ios_base::app);

         out_data << fEdepLaBr1 / keV << "\t"
            << fEdepLaBr2 / keV << "\t"
            << fEdepNaI1 / keV << "\t"
            << fEdepNaI2 / keV << "\t"
            << fEdepNaI3 / keV << "\t"
            << fEdepNaI4 / keV << "\t"
            << fEdepNaI5 / keV << "\t"
            << fEdepNaI6 / keV << "\n";
      }
      else
      {
         std::ofstream out_data;
         out_data.open("Output_Test_Triple.txt", std::ios_base::app);

         out_data << fEdepLaBr1 / keV << "\t"
            << fEdepLaBr2 / keV << "\t"
            << fEdepNaI1 / keV << "\t"
            << fEdepNaI2 / keV << "\t"
            << fEdepNaI3 / keV << "\t"
            << fEdepNaI4 / keV << "\t"
            << fEdepNaI5 / keV << "\t"
            << fEdepNaI6 / keV << "\n";
      }
   }
   
   
   
   fRunAction->EventFinished(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

