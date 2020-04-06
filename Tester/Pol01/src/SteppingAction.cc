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
/// \file polarisation/Pol01/src/SteppingAction.cc
/// \brief Implementation of the SteppingAction class
//
// $Id: SteppingAction.cc 98772 2016-08-09 14:25:31Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

#include "G4RunManager.hh"
#include "G4PolarizationHelper.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*SteppingAction::SteppingAction(DetectorConstruction* det,
                               PrimaryGeneratorAction* prim, RunAction* ruAct)
 : G4UserSteppingAction(),
   fDetector(det), fPrimary(prim), fRunAction(ruAct)*/ 
SteppingAction::SteppingAction(DetectorConstruction* det, EventAction* event)
: G4UserSteppingAction(), fDetector(det), fEventAction(event)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  /*
   G4StepPoint* prePoint = aStep->GetPreStepPoint();
  G4StepPoint* endPoint = aStep->GetPostStepPoint();
  
  G4String procName = endPoint->GetProcessDefinedStep()->GetProcessName();
  fRunAction->CountProcesses(procName);

  if (prePoint->GetTouchableHandle()->GetVolume()==fDetector->GetBox() &&
      endPoint->GetTouchableHandle()->GetVolume()==fDetector->GetWorld()) {
    G4Track* aTrack = aStep->GetTrack();   
    const G4ParticleDefinition* part = 
      aTrack->GetDynamicParticle()->GetDefinition();
    //    G4cout<<"a "<<particleName<<" left the Box \n";
    G4ThreeVector position  = endPoint->GetPosition();
    G4ThreeVector direction = endPoint->GetMomentumDirection();
    G4double kinEnergy = endPoint->GetKineticEnergy();

    G4ThreeVector beamDirection = 
      fPrimary->GetParticleGun()->GetParticleMomentumDirection();
    G4double polZ = endPoint->GetPolarization().z();

    G4double costheta = direction*beamDirection;

    G4double xdir =
      direction*G4PolarizationHelper::GetParticleFrameX(beamDirection);
    G4double ydir =
      direction*G4PolarizationHelper::GetParticleFrameY(beamDirection);

    G4double phi=std::atan2(ydir,xdir);
    fRunAction->FillData(part,kinEnergy,costheta,phi,polZ);

  }
  */
  G4VPhysicalVolume* lVolume = aStep->GetPreStepPoint()->GetTouchableHandle()
     ->GetVolume();
  G4int iVol = 0;
  if (lVolume == fDetector->GetLaBr1())   iVol = 1;
  else if (lVolume == fDetector->GetLaBr2())   iVol = 2;
  //else if (lVolume == fDetector->GetNaI1())    iVol = 3;
  else if (lVolume == fDetector->GetNaI2())    iVol = 4;
  else if (lVolume == fDetector->GetNaI3())    iVol = 5;
  else if (lVolume == fDetector->GetNaI4())    iVol = 6;
  else if (lVolume == fDetector->GetNaI5())    iVol = 7;
  else if (lVolume == fDetector->GetNaI6())    iVol = 8;
  else if (lVolume == fDetector->GetNaI7())    iVol = 9;
  else if (lVolume == fDetector->GetNaI8())    iVol = 10;
  else if (lVolume == fDetector->GetNaI9())    iVol = 11;

  else if (lVolume == fDetector->GetNaI12())    iVol = 12;
  else if (lVolume == fDetector->GetNaI13())    iVol = 13;
  else if (lVolume == fDetector->GetNaI14())    iVol = 14;
  else if (lVolume == fDetector->GetNaI15())    iVol = 15;
  else if (lVolume == fDetector->GetNaI16())    iVol = 16;
  else if (lVolume == fDetector->GetNaI17())    iVol = 17;
  else if (lVolume == fDetector->GetNaI18())    iVol = 18;
  else if (lVolume == fDetector->GetNaI19())    iVol = 19;

  G4double edepStep = aStep->GetTotalEnergyDeposit();
  if (edepStep <= 0.) return;
  if (iVol <= 0.) return;
  fEventAction->AddEdep(iVol, edepStep);
  

  /*
  if (prePoint->GetTouchableHandle()->GetVolume() == fDetector->GetLaBr1() || prePoint->GetTouchableHandle()->GetVolume() == fDetector->GetLaBr2()|| prePoint->GetTouchableHandle()->GetVolume() == fDetector->GetNaI1())
  {
     G4double edepStep = aStep->GetTotalEnergyDeposit();
  //   if (edepStep <= 0.) return;
     std::ofstream out_data;
     out_data.open("OutputEnergy.txt", std::ios_base::app);

     if(prePoint->GetTouchableHandle()->GetVolume() == fDetector->GetLaBr1())
      out_data << "LaBr1: " <<edepStep/keV <<G4endl;
     else if (prePoint->GetTouchableHandle()->GetVolume() == fDetector->GetNaI1())
        out_data << "NaI1: " << edepStep / keV << G4endl;
     else
        out_data << "LaBr2: " << edepStep/keV << G4endl;

  }
  */



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
