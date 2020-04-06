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

  const G4VPhysicalVolume* GetLaBr1() { return fPhysLaBr1; };
  const G4VPhysicalVolume* GetLaBr2() { return fPhysLaBr2; };

  const G4VPhysicalVolume* GetNaI12() { return fPhysNaI12; };
  const G4VPhysicalVolume* GetNaI13() { return fPhysNaI13; };
  const G4VPhysicalVolume* GetNaI14() { return fPhysNaI14; };
  const G4VPhysicalVolume* GetNaI15() { return fPhysNaI15; };
  const G4VPhysicalVolume* GetNaI16() { return fPhysNaI16; };
  const G4VPhysicalVolume* GetNaI17() { return fPhysNaI17; };
  const G4VPhysicalVolume* GetNaI18() { return fPhysNaI18; };
  const G4VPhysicalVolume* GetNaI19() { return fPhysNaI19; };

  const G4VPhysicalVolume* GetNaI2() { return fPhysNaI2; };
  const G4VPhysicalVolume* GetNaI3() { return fPhysNaI3; };
  const G4VPhysicalVolume* GetNaI4() { return fPhysNaI4; };
  const G4VPhysicalVolume* GetNaI5() { return fPhysNaI5; };
  const G4VPhysicalVolume* GetNaI6() { return fPhysNaI6; };
  const G4VPhysicalVolume* GetNaI7() { return fPhysNaI7; };
  const G4VPhysicalVolume* GetNaI8() { return fPhysNaI8; };
  const G4VPhysicalVolume* GetNaI9() { return fPhysNaI9; };
                     
  G4double           GetWorldSize()  {return fWorldSize;};                          
  G4double           GetBoxSizeXY()  {return fBoxSizeXY;};
  G4double           GetBoxSizeZ()   {return fBoxSizeZ;};
  G4Material*        GetMaterial()   {return fTargetMaterial;};
     
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
  G4VPhysicalVolume* fPhysLaBr1;

  G4double           fLengthLaBr2;
  G4double           fRadiusLaBr2;
  G4Material*        fMaterLaBr2;
  G4LogicalVolume*   fLogicLaBr2;
  G4VPhysicalVolume* fPhysLaBr2;

  //G4double           fLengthNaI1;//3"
  //G4double           fRadiusNaI1;//1"
  //G4Material*        fMaterNaI1;
  //G4LogicalVolume*   fLogicNaI1;
  //G4VPhysicalVolume* fPhysNaI1;
  
  
  ///Polarizer

  G4double           fLengthNaI12;
  G4double           fRadiusNaI12;
  G4Material*        fMaterNaI12;
  G4LogicalVolume*   fLogicNaI12;
  G4VPhysicalVolume* fPhysNaI12;


  G4double           fLengthNaI13;
  G4double           fRadiusNaI13;
  G4Material*        fMaterNaI13;
  G4LogicalVolume*   fLogicNaI13;
  G4VPhysicalVolume* fPhysNaI13;

  G4double           fLengthNaI14;
  G4double           fRadiusNaI14;
  G4Material*        fMaterNaI14;
  G4LogicalVolume*   fLogicNaI14;
  G4VPhysicalVolume* fPhysNaI14;

  G4double           fLengthNaI15;
  G4double           fRadiusNaI15;
  G4Material*        fMaterNaI15;
  G4LogicalVolume*   fLogicNaI15;
  G4VPhysicalVolume* fPhysNaI15;

  G4double           fLengthNaI16;
  G4double           fRadiusNaI16;
  G4Material*        fMaterNaI16;
  G4LogicalVolume*   fLogicNaI16;
  G4VPhysicalVolume* fPhysNaI16;

  G4double           fLengthNaI17;
  G4double           fRadiusNaI17;
  G4Material*        fMaterNaI17;
  G4LogicalVolume*   fLogicNaI17;
  G4VPhysicalVolume* fPhysNaI17;


  G4double           fLengthNaI18;
  G4double           fRadiusNaI18;
  G4Material*        fMaterNaI18;
  G4LogicalVolume*   fLogicNaI18;
  G4VPhysicalVolume* fPhysNaI18;


  G4double           fLengthNaI19;
  G4double           fRadiusNaI19;
  G4Material*        fMaterNaI19;
  G4LogicalVolume*   fLogicNaI19;
  G4VPhysicalVolume* fPhysNaI19;




 /// Analyzer


  G4double           fLengthNaI2;
  G4double           fRadiusNaI2;
  G4Material*        fMaterNaI2;
  G4LogicalVolume*   fLogicNaI2;
  G4VPhysicalVolume* fPhysNaI2;


  G4double           fLengthNaI3;
  G4double           fRadiusNaI3;
  G4Material*        fMaterNaI3;
  G4LogicalVolume*   fLogicNaI3;
  G4VPhysicalVolume* fPhysNaI3;

  G4double           fLengthNaI4;
  G4double           fRadiusNaI4;
  G4Material*        fMaterNaI4;
  G4LogicalVolume*   fLogicNaI4;
  G4VPhysicalVolume* fPhysNaI4;

  G4double           fLengthNaI5;
  G4double           fRadiusNaI5;
  G4Material*        fMaterNaI5;
  G4LogicalVolume*   fLogicNaI5;
  G4VPhysicalVolume* fPhysNaI5;

  G4double           fLengthNaI6;
  G4double           fRadiusNaI6;
  G4Material*        fMaterNaI6;
  G4LogicalVolume*   fLogicNaI6;
  G4VPhysicalVolume* fPhysNaI6;


  G4double           fLengthNaI7;
  G4double           fRadiusNaI7;
  G4Material*        fMaterNaI7;
  G4LogicalVolume*   fLogicNaI7;
  G4VPhysicalVolume* fPhysNaI7;


  G4double           fLengthNaI8;
  G4double           fRadiusNaI8;
  G4Material*        fMaterNaI8;
  G4LogicalVolume*   fLogicNaI8;
  G4VPhysicalVolume* fPhysNaI8;


  G4double           fLengthNaI9;
  G4double           fRadiusNaI9;
  G4Material*        fMaterNaI9;
  G4LogicalVolume*   fLogicNaI9;
  G4VPhysicalVolume* fPhysNaI9;

  G4Material*        Pb;
  G4Material*        Al;

  void               DefineMaterials();
  DetectorMessenger* fMessenger;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
