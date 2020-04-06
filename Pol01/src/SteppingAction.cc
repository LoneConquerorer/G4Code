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
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(DetectorConstruction* det,
                               PrimaryGeneratorAction* prim, RunAction* ruAct)
 : G4UserSteppingAction(),
   fDetector(det), fPrimary(prim), fRunAction(ruAct)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
  G4StepPoint* prePoint = aStep->GetPreStepPoint();
  G4StepPoint* endPoint = aStep->GetPostStepPoint();
  /*
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
    */
    
    G4LogicalVolume* lVolume = aStep->GetPreStepPoint()->GetTouchableHandle()
       ->GetVolume()->GetLogicalVolume();
    G4int iVol = 0;
    if (lVolume == fDetector->GetLogicLaBr(1))   iVol = 1;
    if (lVolume == fDetector->GetLogicLaBr(2))   iVol = 2;
    if (lVolume == fDetector->GetLogicNaI(1))    iVol = 3;
    if (lVolume == fDetector->GetLogicNaI(2))    iVol = 4;
    if (lVolume == fDetector->GetLogicNaI(3))    iVol = 5;
    if (lVolume == fDetector->GetLogicNaI(4))    iVol = 6;
    if (lVolume == fDetector->GetLogicNaI(5))    iVol = 7;
    if (lVolume == fDetector->GetLogicNaI(6))    iVol = 8;

    G4double edepStep = aStep->GetTotalEnergyDeposit();
    if (edepStep <= 0.) return;
    G4double time = aStep->GetPreStepPoint()->GetGlobalTime();
    fEventAction->AddEdep(iVol, edepStep, time);
    std::ofstream out_data;
    out_data.open("Step.txt", std::ios_base::app);

 //}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
