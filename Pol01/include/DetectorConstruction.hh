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
/// \file polarisation/Pol01/include/DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 98772 2016-08-09 14:25:31Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4LogicalVolume;
class G4Material;
class DetectorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  
  DetectorConstruction();
  ~DetectorConstruction();

public:
  
  G4VPhysicalVolume* Construct();
     
  void SetSizeXY   (G4double);
  void SetSizeZ    (G4double);              
  void SetTargetMaterial (G4String);            
  void SetWorldMaterial (G4String);            

  void UpdateGeometry();
     
public:
  
  const G4VPhysicalVolume* GetWorld()      {return fWorld;};
  const G4VPhysicalVolume* GetBox()        {return fBox;};
                     
  G4double           GetWorldSize()  {return fWorldSize;};                          
  G4double           GetBoxSizeXY()  {return fBoxSizeXY;};
  G4double           GetBoxSizeZ()   {return fBoxSizeZ;};
  G4Material*        GetMaterial()   {return fTargetMaterial;};

  G4double GetLengthLaBr(G4int);
  G4double GetRadiusLaBr(G4int);
  G4Material* GetMaterialLaBr(G4int);
  G4LogicalVolume* GetLogicLaBr(G4int);

  G4double GetLengthNaI(G4int);
  G4double GetRadiusNaI(G4int);
  G4Material* GetMaterialNaI(G4int);
  G4LogicalVolume* GetLogicNaI(G4int);

     
  void               PrintParameters();
                       
private:
  
  G4VPhysicalVolume*    fWorld;  
  G4VPhysicalVolume*    fBox;
     
  G4double              fBoxSizeXY;
  G4double              fBoxSizeZ;
  G4double              fWorldSize;
  G4Material*           fTargetMaterial;
  G4Material*           fWorldMaterial;  


  G4double           fWorldLength;
  G4double           fWorldRadius;
  G4Material*        fWorldMater;
  G4VPhysicalVolume* fPhysiWorld;

  G4double           fLengthLaBr1; //1"
  G4double           fRadiusLaBr1;//0.5"
  G4Material*        fMaterLaBr1;
  G4LogicalVolume*   fLogicLaBr1;

  G4double           fLengthLaBr2;
  G4double           fRadiusLaBr2;
  G4Material*        fMaterLaBr2;
  G4LogicalVolume*   fLogicLaBr2;

  G4double           fLengthNaI1;//3"
  G4double           fRadiusNaI1;//1"
  G4Material*        fMaterNaI1;
  G4LogicalVolume*   fLogicNaI1;

  G4double           fLengthNaI2;
  G4double           fRadiusNaI2;
  G4Material*        fMaterNaI2;
  G4LogicalVolume*   fLogicNaI2;

  G4double           fLengthNaI3;
  G4double           fRadiusNaI3;
  G4Material*        fMaterNaI3;
  G4LogicalVolume*   fLogicNaI3;

  G4double           fLengthNaI4;
  G4double           fRadiusNaI4;
  G4Material*        fMaterNaI4;
  G4LogicalVolume*   fLogicNaI4;

  G4double           fLengthNaI5;
  G4double           fRadiusNaI5;
  G4Material*        fMaterNaI5;
  G4LogicalVolume*   fLogicNaI5;

  G4double           fLengthNaI6;
  G4double           fRadiusNaI6;
  G4Material*        fMaterNaI6;
  G4LogicalVolume*   fLogicNaI6;

  G4Material*        Pb;
  G4Material*        Al;


  void               DefineMaterials();
  DetectorMessenger* fMessenger;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
