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
/// \file polarisation/Pol01/src/DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 98772 2016-08-09 14:25:31Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4SubtractionSolid.hh"

#include "G4UnitsTable.hh"

#include "G4PolarizationManager.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fWorld(0), fBox(0), fTargetMaterial(0), fWorldMaterial(0)
{
   fBoxSizeXY = 10*mm; //50*mm;
  fBoxSizeZ = .5*mm;//5*mm;
  fWorldSize = 1.*m;
  SetTargetMaterial("G4_Al");  
  SetWorldMaterial("G4_Galactic");  
  fMessenger = new DetectorMessenger(this);

  fMaterLaBr1 = 0;
  fLogicLaBr1 = 0;
  fMaterLaBr2 = 0;
  fLogicLaBr2 = 0;
 // fMaterNaI1 = 0;
 // fLogicNaI1 = 0;
  fMaterNaI12 = 0;
  fLogicNaI12 = 0;
  fMaterNaI13 = 0;
  fLogicNaI13 = 0;
  fMaterNaI14 = 0;
  fLogicNaI14 = 0;
  fMaterNaI15 = 0;
  fLogicNaI15 = 0;
  fMaterNaI16 = 0;
  fLogicNaI16 = 0;
  fMaterNaI17 = 0;
  fLogicNaI17 = 0;
  fMaterNaI18 = 0;
  fLogicNaI18 = 0;
  fMaterNaI19 = 0;
  fLogicNaI19 = 0;


  fMaterNaI2 = 0;
  fLogicNaI2 = 0;
  fMaterNaI3 = 0;
  fLogicNaI3 = 0;
  fMaterNaI4 = 0;
  fLogicNaI4 = 0;
  fMaterNaI5 = 0;
  fLogicNaI5 = 0;
  fMaterNaI6 = 0;
  fLogicNaI6 = 0;
  fMaterNaI7 = 0;
  fLogicNaI7 = 0;
  fMaterNaI8 = 0;
  fLogicNaI8 = 0;
  fMaterNaI9 = 0;
  fLogicNaI9 = 0;

  fLengthLaBr1 = 2.54*cm;
  fRadiusLaBr1 = 1.27*cm;

  fLengthLaBr2 = 2.54*cm;
  fRadiusLaBr2 = 1.27*cm;

 // fLengthNaI1 = 7.62*cm;
 // fRadiusNaI1 = 2.54*cm;

  fLengthNaI12 = 7.62*cm;
  fRadiusNaI12 = 2.54*cm;

  fLengthNaI13 = 7.62*cm;
  fRadiusNaI13 = 2.54*cm;

  fLengthNaI14 = 7.62*cm;
  fRadiusNaI14 = 2.54*cm;

  fLengthNaI15 = 7.62*cm;
  fRadiusNaI15 = 2.54*cm;

  fLengthNaI16 = 7.62*cm;
  fRadiusNaI16 = 2.54*cm;

  fLengthNaI17 = 7.62*cm;
  fRadiusNaI17 = 2.54*cm;

  fLengthNaI18 = 7.62*cm;
  fRadiusNaI18 = 2.54*cm;

  fLengthNaI19 = 7.62*cm;
  fRadiusNaI19 = 2.54*cm;


  fLengthNaI2 = 7.62*cm;
  fRadiusNaI2 = 2.54*cm;

  fLengthNaI3 = 7.62*cm;
  fRadiusNaI3 = 2.54*cm;

  fLengthNaI4 = 7.62*cm;
  fRadiusNaI4 = 2.54*cm;

  fLengthNaI5 = 7.62*cm;
  fRadiusNaI5 = 2.54*cm;

  fLengthNaI6 = 7.62*cm;
  fRadiusNaI6 = 2.54*cm;

  fLengthNaI7 = 7.62*cm;
  fRadiusNaI7 = 2.54*cm;

  fLengthNaI8 = 7.62*cm;
  fRadiusNaI8 = 2.54*cm;

  fLengthNaI9 = 7.62*cm;
  fRadiusNaI9 = 2.54*cm;

  DefineMaterials();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ 
  delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void DetectorConstruction::DefineMaterials()
{
   // build materials
   //
   //  fDetectorMater =
   //  new G4Material("Germanium", 32, 72.61*g/mole, 5.323*g/cm3);

   
   G4Element* N = new G4Element("Nitrogen", "N", 7, 14.01*g / mole);
   G4Element* O = new G4Element("Oxygen", "O", 8, 16.00*g / mole);
   //
   G4int ncomponents; G4double fractionmass;
   G4Material* Air20 = new G4Material("Air", 1.205*mg / cm3, ncomponents = 2,
      kStateGas, 293.*kelvin, 1.*atmosphere);
   Air20->AddElement(N, fractionmass = 0.7);
   Air20->AddElement(O, fractionmass = 0.3);
   //
   fWorldMater = Air20;

   // or use G4 materials data base
   //
   //  G4NistManager* man = G4NistManager::Instance();
   //  fTargetMater = man->FindOrBuildMaterial("G4_CESIUM_IODIDE");



   ///G4cout << *(G4Material::GetMaterialTable()) << G4endl;

   G4double z, a, density;
   G4String name, symbol;
   G4int natoms;
   a = 138.90547*g / mole;
   G4Element* elLanthanum = new G4Element(name = "Lanthanum", symbol = "La", z = 57., a);

   a = 79.904*g / mole;
   G4Element* elBromine = new G4Element(name = "Bromine", symbol = "Br", z = 35., a);
   density = 5.06*g / cm3;
   G4Material* LaBr = new G4Material(name = "Lanthanum_Bromide", density, ncomponents = 2);
   LaBr->AddElement(elLanthanum, natoms = 1);
   LaBr->AddElement(elBromine, natoms = 3);

   fMaterLaBr1 = LaBr;
   fMaterLaBr2 = LaBr;

   G4NistManager* nist = G4NistManager::Instance();

   G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
   G4Material* Aluminum = nist->FindOrBuildMaterial("G4_Al");

   Pb = Lead;
   Al = Aluminum;

   G4Material* NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");

 //  fMaterNaI1 = NaI;

   fMaterNaI12 = NaI;
   fMaterNaI13 = NaI;
   fMaterNaI14 = NaI;
   fMaterNaI15 = NaI;
   fMaterNaI16 = NaI;
   fMaterNaI17 = NaI;
   fMaterNaI18 = NaI;
   fMaterNaI19 = NaI;

   fMaterNaI2 = NaI;
   fMaterNaI3 = NaI;
   fMaterNaI4 = NaI;
   fMaterNaI5 = NaI;
   fMaterNaI6 = NaI;
   fMaterNaI7 = NaI;
   fMaterNaI8 = NaI;
   fMaterNaI9 = NaI;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Cleanup old geometry
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();
  
  G4PolarizationManager::GetInstance()->Clean();

  G4bool checkOverlaps = true;
  G4double M_PI = 3.141592653589793238462643383279502884;
  G4double twopi = 2 * M_PI;

  // World
  //
  G4Box*
  sWorld = new G4Box("World",                            //name
                   fWorldSize/2,fWorldSize/2,fWorldSize/2); //dimensions

  G4LogicalVolume*                                                                 
  lWorld = new G4LogicalVolume(sWorld,                   //shape
                               fWorldMaterial,           //material
                              "World");                  //name

  fWorld = new G4PVPlacement(0,                          //no rotation
                             G4ThreeVector(),            //at (0,0,0)
                             lWorld,                     //logical volume
                             "World",                    //name
                             0,                          //mother volume
                             false,                      //no boolean operation
                             0);                         //copy number
                                                      
  // Box
  //                           
  G4Box*
  sBox = new G4Box("Container",                           //its name
                   fBoxSizeZ/2.,fBoxSizeXY/2.,fBoxSizeXY/2.);//its dimensions
                   
  G4LogicalVolume*
  lBox = new G4LogicalVolume(sBox,                        //its shape
                             fTargetMaterial,             //its material
                             "theBox");                   //its name

  fBox = new G4PVPlacement(0,                             //no rotation
                           G4ThreeVector(),               //at (0,0,0)
                           lBox,                          //its logical volume
                           fTargetMaterial->GetName(),    //its name
                           lWorld,                        //its mother  volume
                           false,                         //no boolean operation
                           0);                            //copy number

  // register logical Volume in PolarizationManager with zero polarization
  G4PolarizationManager * polMgr = G4PolarizationManager::GetInstance();
  polMgr->SetVolumePolarization(lBox,G4ThreeVector(0.,0.,0.));
                     
  //
  //LaBr1
  //
  
  G4ThreeVector LaBrpos1 = G4ThreeVector(16.27*cm, 0, 0);

  G4Tubs* solidLaBr1 =
     new G4Tubs("LaBr1",
        0., fRadiusLaBr1, 0.5*fLengthLaBr1, 0., twopi);

  fLogicLaBr1 =
     new G4LogicalVolume(solidLaBr1,         //its solid
        fMaterLaBr1,          //its material
        "LaBr1");           //its name

  G4RotationMatrix* yRotLaBr1 = new G4RotationMatrix; // Rotates X and Z axes only
  yRotLaBr1->rotateY(M_PI / 2.*rad);

  fPhysLaBr1 = new G4PVPlacement(yRotLaBr1,                       //no rotation
     LaBrpos1,                    //at position
     fLogicLaBr1,             //its logical volume
     "LaBr1",                //its name
     lWorld,                //its mother  volume
     false,                   //no boolean operation
     0,                       //copy number
     checkOverlaps);          //overlaps checking

     
   //
   // LaBr2
   //
  G4ThreeVector LaBrpos2 = G4ThreeVector(-16.27*cm, 0, 0);

  G4Tubs* solidLaBr2 = new G4Tubs("LaBr2",
     0., fRadiusLaBr2, 0.5*fLengthLaBr2, 0., twopi);

  fLogicLaBr2 = new G4LogicalVolume(solidLaBr2,         //its solid
     fMaterLaBr2,          //its material
     "LaBr2");           //its name

  G4RotationMatrix* yRotLaBr2 = new G4RotationMatrix; // Rotates X and Z axes only
  yRotLaBr2->rotateY(M_PI / 2.*rad);

  fPhysLaBr2 = new G4PVPlacement(yRotLaBr2,                       //no rotation
     LaBrpos2,                    //at position
     fLogicLaBr2,             //its logical volume
     "LaBr2",                //its name
     lWorld,                //its mother  volume
     false,                   //no boolean operation
     0,                       //copy number
     checkOverlaps);          //overlaps checking

   //
   // Detector12
   //
  G4ThreeVector pos12 = G4ThreeVector(16.27*cm, 0, 11.61*cm);

  G4Tubs* solidDetector12 = new G4Tubs("NaI12",
                                       0., fRadiusNaI12, 0.5*fLengthNaI12, 0., twopi);

  fLogicNaI12 = new G4LogicalVolume
                                   (solidDetector12,         //its solid
                                      fMaterNaI12,          //its material
                                      "NaI12");           //its name

 // G4RotationMatrix* xRot12 = new G4RotationMatrix; // Rotates Y and Z axes only
 // xRot12->rotateX(0);


  fPhysNaI12 = new G4PVPlacement(0,                       //no rotation
                                pos12,                    //at position
                                fLogicNaI12,             //its logical volume
                                "NaI12",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 12
   //
   G4Tubs* PbShield_12 = new G4Tubs("PbShield_12",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_12 =
                    new G4LogicalVolume(PbShield_12,       //shape
                                        Pb,            //material
                                        "PbShield_12");               //name

              new G4PVPlacement(0,                         //no rotation
                              pos12,             //at (0,0,0)
                              logicPbShield_12,              //logical volume
                              "PbShield_12",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);


   //
   // Detector13
   //
  G4ThreeVector pos13 = G4ThreeVector(16.27*cm, 11.61 / std::sqrt(2)*cm, 11.61 / std::sqrt(2)*cm);

  G4Tubs* solidDetector13 = new G4Tubs("NaI13",
                                       0., fRadiusNaI13, 0.5*fLengthNaI13, 0., twopi);

  fLogicNaI13 = new G4LogicalVolume
                                   (solidDetector13,         //its solid
                                      fMaterNaI13,          //its material
                                      "NaI13");           //its name

  G4RotationMatrix* xRot13 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot13->rotateX(M_PI / 4.*rad);


  fPhysNaI13 = new G4PVPlacement(xRot13,                       //no rotation
                                pos13,                    //at position
                                fLogicNaI13,             //its logical volume
                                "NaI13",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 13
   //
   G4Tubs* PbShield_13 = new G4Tubs("PbShield_13",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_13 =
                    new G4LogicalVolume(PbShield_13,       //shape
                                        Pb,            //material
                                        "PbShield_13");               //name

         new G4PVPlacement(xRot13,                         //no rotation
                              pos13,             //at (0,0,0)
                              logicPbShield_13,              //logical volume
                              "PbShield_13",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

      //
   // Detector14
   //
  G4ThreeVector pos14 = G4ThreeVector(16.27*cm, 11.61*cm, 0);

  G4Tubs* solidDetector14 = new G4Tubs("NaI14",
                                       0., fRadiusNaI14, 0.5*fLengthNaI14, 0., twopi);

  fLogicNaI14 = new G4LogicalVolume
                                   (solidDetector14,         //its solid
                                      fMaterNaI14,          //its material
                                      "NaI14");           //its name

  G4RotationMatrix* xRot14 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot14->rotateX(M_PI / 2.*rad);


  fPhysNaI14 = new G4PVPlacement(xRot14,                       //no rotation
                                pos14,                    //at position
                                fLogicNaI14,             //its logical volume
                                "NaI14",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 14
   //
   G4Tubs* PbShield_14 = new G4Tubs("PbShield_14",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_14 =
                    new G4LogicalVolume(PbShield_14,       //shape
                                        Pb,            //material
                                        "PbShield_14");               //name

            new G4PVPlacement(xRot14,                         //no rotation
                              pos14,             //at (0,0,0)
                              logicPbShield_14,              //logical volume
                              "PbShield_14",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);


      //
   // Detector15
   //
  G4ThreeVector pos15 = G4ThreeVector(16.27*cm, 11.61 / std::sqrt(2)*cm, -11.61 / std::sqrt(2)*cm);

  G4Tubs* solidDetector15 = new G4Tubs("NaI15",
                                       0., fRadiusNaI15, 0.5*fLengthNaI15, 0., twopi);

  fLogicNaI15 = new G4LogicalVolume
                                   (solidDetector15,         //its solid
                                      fMaterNaI15,          //its material
                                      "NaI15");           //its name

  G4RotationMatrix* xRot15 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot15->rotateX(-M_PI / 4.*rad);


  fPhysNaI15 = new G4PVPlacement(xRot15,                       //no rotation
                                pos15,                    //at position
                                fLogicNaI15,             //its logical volume
                                "NaI15",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 15
   //
   G4Tubs* PbShield_15 = new G4Tubs("PbShield_15",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_15 =
                    new G4LogicalVolume(PbShield_15,       //shape
                                        Pb,            //material
                                        "PbShield_15");               //name

              new G4PVPlacement(xRot15,                         //no rotation
                              pos15,             //at (0,0,0)
                              logicPbShield_15,              //logical volume
                              "PbShield_15",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

      //
   // Detector16
   //
  G4ThreeVector pos16 = G4ThreeVector(16.27*cm, 0, -11.61 *cm);

  G4Tubs* solidDetector16 = new G4Tubs("NaI16",
                                       0., fRadiusNaI16, 0.5*fLengthNaI16, 0., twopi);

  fLogicNaI16 = new G4LogicalVolume
                                   (solidDetector16,         //its solid
                                      fMaterNaI16,          //its material
                                      "NaI16");           //its name

 // G4RotationMatrix* xRot16 = new G4RotationMatrix; // Rotates Y and Z axes only
 // xRot16->rotateX(-M_PI / 4.*rad);


  fPhysNaI16 = new G4PVPlacement(0,                       //no rotation
                                pos16,                    //at position
                                fLogicNaI16,             //its logical volume
                                "NaI16",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
     // Lead Shield 16
     //
     G4Tubs* PbShield_16 = new G4Tubs("PbShield_16",
                   2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
     G4LogicalVolume* logicPbShield_16 =
                      new G4LogicalVolume(PbShield_16,       //shape
                                          Pb,            //material
                                          "PbShield_16");               //name

                new G4PVPlacement(0,                         //no rotation
                                pos16,             //at (0,0,0)
                                logicPbShield_16,              //logical volume
                                "PbShield_16",                  //name
                                lWorld,                      //mother  volume
                                false,                       //no boolean operation
                                0);



      //
   // Detector17
   //
  G4ThreeVector pos17 = G4ThreeVector(16.27*cm, -11.61 / std::sqrt(2)*cm, -11.61 / std::sqrt(2)*cm);

  G4Tubs* solidDetector17 = new G4Tubs("NaI17",
                                       0., fRadiusNaI17, 0.5*fLengthNaI17, 0., twopi);

  fLogicNaI17 = new G4LogicalVolume
                                   (solidDetector17,         //its solid
                                      fMaterNaI17,          //its material
                                      "NaI17");           //its name

  G4RotationMatrix* xRot17 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot17->rotateX(M_PI / 4.*rad);


  fPhysNaI17 = new G4PVPlacement(xRot17,                       //no rotation
                                pos17,                    //at position
                                fLogicNaI17,             //its logical volume
                                "NaI17",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 17
   //
   G4Tubs* PbShield_17 = new G4Tubs("PbShield_17",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_17 =
                    new G4LogicalVolume(PbShield_17,       //shape
                                        Pb,            //material
                                        "PbShield_17");               //name

         new G4PVPlacement(xRot17,                         //no rotation
                              pos17,             //at (0,0,0)
                              logicPbShield_17,              //logical volume
                              "PbShield_17",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);



      //
   // Detector18
   //
  G4ThreeVector pos18 = G4ThreeVector(16.27*cm, -11.61*cm, 0);

  G4Tubs* solidDetector18 = new G4Tubs("NaI18",
                                       0., fRadiusNaI18, 0.5*fLengthNaI18, 0., twopi);

  fLogicNaI18 = new G4LogicalVolume
                                   (solidDetector18,         //its solid
                                      fMaterNaI18,          //its material
                                      "NaI18");           //its name

  G4RotationMatrix* xRot18 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot18->rotateX(M_PI / 2.*rad);


  fPhysNaI18 = new G4PVPlacement(xRot18,                       //no rotation
                                pos18,                    //at position
                                fLogicNaI18,             //its logical volume
                                "NaI18",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

  //
   // Lead Shield 18
   //
   G4Tubs* PbShield_18 = new G4Tubs("PbShield_18",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_18 =
                    new G4LogicalVolume(PbShield_18,       //shape
                                        Pb,            //material
                                        "PbShield_18");               //name

            new G4PVPlacement(xRot18,                         //no rotation
                              pos18,             //at (0,0,0)
                              logicPbShield_18,              //logical volume
                              "PbShield_18",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

      //
   // Detector19
   //
  G4ThreeVector pos19 = G4ThreeVector(16.27*cm, -11.61 / std::sqrt(2)*cm, 11.61 / std::sqrt(2)*cm);

  G4Tubs* solidDetector19 = new G4Tubs("NaI19",
                                       0., fRadiusNaI19, 0.5*fLengthNaI19, 0., twopi);

  fLogicNaI19 = new G4LogicalVolume
                                   (solidDetector19,         //its solid
                                      fMaterNaI19,          //its material
                                      "NaI19");           //its name

  G4RotationMatrix* xRot19 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot19->rotateX(-M_PI / 4.*rad);


  fPhysNaI19 = new G4PVPlacement(xRot19,                       //no rotation
                                pos19,                    //at position
                                fLogicNaI19,             //its logical volume
                                "NaI19",                //its name
                                lWorld,                //its mother  volume
                                false,                   //no boolean operation
                                0,                       //copy number
                                checkOverlaps);          //overlaps checking

       //
   // Lead Shield 19
   //
   G4Tubs* PbShield_19 = new G4Tubs("PbShield_19",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_19 =
                    new G4LogicalVolume(PbShield_19,       //shape
                                        Pb,            //material
                                        "PbShield_19");               //name

              new G4PVPlacement(xRot19,                         //no rotation
                              pos19,             //at (0,0,0)
                              logicPbShield_19,              //logical volume
                              "PbShield_19",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);


   //
   // Detector 2
   //
  G4ThreeVector pos2 = G4ThreeVector(-16.27*cm, 0, 11.61*cm);

  G4Tubs* solidDetector2 =new G4Tubs("NaI2",
         0., fRadiusNaI2, 0.5*fLengthNaI2, 0., twopi);

   fLogicNaI2 = new G4LogicalVolume
                         (solidDetector2,         //its solid
                         fMaterNaI2,          //its material
                         "NaI2");           //its name

  fPhysNaI2 =  new G4PVPlacement(0,                       //no rotation
                     pos2,                    //at position
                     fLogicNaI2,             //its logical volume
                     "NaI2",                //its name
                     lWorld,                //its mother  volume
                     false,                   //no boolean operation
                     0,                       //copy number
                     checkOverlaps);          //overlaps checking

   //
   // Lead Shield 2
   //
   G4Tubs* PbShield_2 = new G4Tubs("PbShield_2",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_2 =
                    new G4LogicalVolume(PbShield_2,       //shape
                                        Pb,            //material
                                        "PbShield_2");               //name

              new G4PVPlacement(0,                         //no rotation
                              pos2,             //at (0,0,0)
                              logicPbShield_2,              //logical volume
                              "PbShield_2",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 3
   //
     G4ThreeVector pos3 = G4ThreeVector(-16.27*cm, 11.61 / std::sqrt(2)*cm, 11.61 / std::sqrt(2)*cm);

     G4Tubs* solidDetector3 =new G4Tubs("NaI3",
         0., fRadiusNaI3, 0.5*fLengthNaI3, 0., twopi);

   fLogicNaI3 = new G4LogicalVolume
                         (solidDetector3,         //its solid
                         fMaterNaI3,          //its material
                         "NaI3");           //its name

    G4RotationMatrix* xRot3 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot3->rotateX(M_PI/4.*rad);

    fPhysNaI3 = new G4PVPlacement(xRot3,                       //no rotation
                      pos3,                    //at position
                      fLogicNaI3,             //its logical volume
                      "NaI3",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 3
   //
   G4Tubs* PbShield_3 = new G4Tubs("PbShield_3",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_3 =
                    new G4LogicalVolume(PbShield_3,       //shape
                                        Pb,            //material
                                        "PbShield_3");               //name

         new G4PVPlacement(xRot3,                         //no rotation
                              pos3,             //at (0,0,0)
                              logicPbShield_3,              //logical volume
                              "PbShield_3",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 4
   //
      G4ThreeVector pos4 = G4ThreeVector(-16.27*cm, 11.61*cm, 0);
      G4Tubs* solidDetector4 =new G4Tubs("NaI4",
         0., fRadiusNaI4, 0.5*fLengthNaI4, 0., twopi);

   fLogicNaI4 = new G4LogicalVolume
                         (solidDetector4,         //its solid
                         fMaterNaI4,          //its material
                         "NaI4");           //its name


    G4RotationMatrix* xRot4 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot4->rotateX(M_PI/2.*rad);

    fPhysNaI4 = new G4PVPlacement(xRot4,                       //no rotation
                      pos4,                    //at position
                      fLogicNaI4,             //its logical volume
                      "NaI4",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 4
   //
   G4Tubs* PbShield_4 = new G4Tubs("PbShield_4",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_4 =
                    new G4LogicalVolume(PbShield_4,       //shape
                                        Pb,            //material
                                        "PbShield_4");               //name

            new G4PVPlacement(xRot4,                         //no rotation
                              pos4,             //at (0,0,0)
                              logicPbShield_4,              //logical volume
                              "PbShield_4",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 5
   //
   G4ThreeVector pos5 = G4ThreeVector(-16.27*cm, 11.61 / std::sqrt(2)*cm, -11.61 / std::sqrt(2)*cm);

   G4Tubs* solidDetector5 =new G4Tubs("NaI5",
         0., fRadiusNaI5, 0.5*fLengthNaI5, 0., twopi);

   fLogicNaI5 = new G4LogicalVolume
                         (solidDetector5,         //its solid
                         fMaterNaI5,          //its material
                         "NaI5");           //its name


    G4RotationMatrix* xRot5 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot5->rotateX(-M_PI/4.*rad);

    fPhysNaI5 = new G4PVPlacement(xRot5,                       //no rotation
                      pos5,                    //at position
                      fLogicNaI5,             //its logical volume
                      "NaI5",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 5
   //
   G4Tubs* PbShield_5 = new G4Tubs("PbShield_5",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_5 =
                    new G4LogicalVolume(PbShield_5,       //shape
                                        Pb,            //material
                                        "PbShield_5");               //name

              new G4PVPlacement(xRot5,                         //no rotation
                              pos5,             //at (0,0,0)
                              logicPbShield_5,              //logical volume
                              "PbShield_5",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 6
   //
     G4ThreeVector pos6 = G4ThreeVector(-16.27*cm, 0, -11.61*cm);

     G4Tubs* solidDetector6 =new G4Tubs("NaI6",
         0., fRadiusNaI6, 0.5*fLengthNaI6, 0., twopi);

   fLogicNaI6 = new G4LogicalVolume
                         (solidDetector6,         //its solid
                         fMaterNaI6,          //its material
                         "NaI6");           //its name

    fPhysNaI6 = new G4PVPlacement(0,                       //no rotation
                       pos6,                    //at position
                       fLogicNaI6,             //its logical volume
                       "NaI6",                //its name
                       lWorld,                //its mother  volume
                       false,                   //no boolean operation
                       0,                       //copy number
                       checkOverlaps);

     //
     // Lead Shield 6
     //
     G4Tubs* PbShield_6 = new G4Tubs("PbShield_6",
                   2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
     G4LogicalVolume* logicPbShield_6 =
                      new G4LogicalVolume(PbShield_6,       //shape
                                          Pb,            //material
                                          "PbShield_6");               //name

                new G4PVPlacement(0,                         //no rotation
                                pos6,             //at (0,0,0)
                                logicPbShield_6,              //logical volume
                                "PbShield_6",                  //name
                                lWorld,                      //mother  volume
                                false,                       //no boolean operation
                                0);

   //
   // Detector 7
   //
     G4ThreeVector pos7 = G4ThreeVector(-16.27*cm, -11.61 / std::sqrt(2)*cm, -11.61 / std::sqrt(2)*cm);

     G4Tubs* solidDetector7 =new G4Tubs("NaI7",
         0., fRadiusNaI7, 0.5*fLengthNaI7, 0., twopi);

   fLogicNaI7 = new G4LogicalVolume
                         (solidDetector7,         //its solid
                         fMaterNaI7,          //its material
                         "NaI7");           //its name

    G4RotationMatrix* xRot7 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot7->rotateX(M_PI/4.*rad);

    fPhysNaI7 = new G4PVPlacement(xRot7,                       //no rotation
                      pos7,                    //at position
                      fLogicNaI7,             //its logical volume
                      "NaI7",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 7
   //
   G4Tubs* PbShield_7 = new G4Tubs("PbShield_7",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_7 =
                    new G4LogicalVolume(PbShield_7,       //shape
                                        Pb,            //material
                                        "PbShield_7");               //name

         new G4PVPlacement(xRot7,                         //no rotation
                              pos7,             //at (0,0,0)
                              logicPbShield_7,              //logical volume
                              "PbShield_7",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 8
   //
      G4ThreeVector pos8 = G4ThreeVector(-16.27*cm, -11.61*cm, 0);
      G4Tubs* solidDetector8 =new G4Tubs("NaI8",
         0., fRadiusNaI8, 0.5*fLengthNaI8, 0., twopi);

   fLogicNaI8 = new G4LogicalVolume
                         (solidDetector8,         //its solid
                         fMaterNaI8,          //its material
                         "NaI8");           //its name


    G4RotationMatrix* xRot8 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot8->rotateX(M_PI/2.*rad);

    fPhysNaI8 = new G4PVPlacement(xRot8,                       //no rotation
                      pos8,                    //at position
                      fLogicNaI8,             //its logical volume
                      "NaI8",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 8
   //
   G4Tubs* PbShield_8 = new G4Tubs("PbShield_8",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_8 =
                    new G4LogicalVolume(PbShield_8,       //shape
                                        Pb,            //material
                                        "PbShield_8");               //name

            new G4PVPlacement(xRot8,                         //no rotation
                              pos8,             //at (0,0,0)
                              logicPbShield_8,              //logical volume
                              "PbShield_8",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 9
   //
   G4ThreeVector pos9 = G4ThreeVector(-16.27*cm, -11.61 / std::sqrt(2)*cm, 11.61 / std::sqrt(2)*cm);

   G4Tubs* solidDetector9 =new G4Tubs("NaI9",
         0., fRadiusNaI9, 0.5*fLengthNaI9, 0., twopi);

   fLogicNaI9 = new G4LogicalVolume
                         (solidDetector9,         //its solid
                         fMaterNaI9,          //its material
                         "NaI9");           //its name


    G4RotationMatrix* xRot9 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot9->rotateX(-M_PI/4.*rad);

    fPhysNaI9 = new G4PVPlacement(xRot9,                       //no rotation
                      pos9,                    //at position
                      fLogicNaI9,             //its logical volume
                      "NaI9",                //its name
                      lWorld,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);

   //
   // Lead Shield 9
   //
   G4Tubs* PbShield_9 = new G4Tubs("PbShield_9",
                 2.54*cm, 2.8575*cm, 3.81*cm, 0.,twopi);
   G4LogicalVolume* logicPbShield_9 =
                    new G4LogicalVolume(PbShield_9,       //shape
                                        Pb,            //material
                                        "PbShield_9");               //name

              new G4PVPlacement(xRot9,                         //no rotation
                              pos9,             //at (0,0,0)
                              logicPbShield_9,              //logical volume
                              "PbShield_9",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

  
      //
      //Source Shield
      //

      G4Box *outerBox = new G4Box("Outer Box",
                                  7.5*cm,
                                  7.5*cm,
                                  5*cm);

      G4Box *innerBox = new G4Box("Inner Box",
                                  6.5*cm,
                                  8*cm,
                                  1.5*cm);

      G4SubtractionSolid *Hollow_Box =
              new G4SubtractionSolid("Hollow_Box",outerBox,innerBox);

      G4Tubs* Hole = new G4Tubs("Hole",
                      0, 1*cm, 5.5*cm, 0.,twopi);

      G4SubtractionSolid *Source_Shield =
                              new G4SubtractionSolid("Source_Shield",Hollow_Box,Hole);

      G4LogicalVolume* logicSource_Shield =
        new G4LogicalVolume(Source_Shield,          //its solid
                            Pb,           //its material
                            "Source_Shield");            //its name

        G4RotationMatrix* yRotSource_Shield = new G4RotationMatrix; // Rotates X and Z axes only
        yRotSource_Shield->rotateY(-M_PI/2.*rad);

        new G4PVPlacement(yRotSource_Shield,                     //no rotation
                          G4ThreeVector(),       //at (0,0,0)
                          logicSource_Shield,            //its logical volume
                          "Source_Shield",               //its name
                          lWorld,                     //its mother  volume
                          false,                 //no boolean operation
                          0,                     //copy number
                          checkOverlaps);        //overlaps checking




  PrintParameters();
  
  //always return the root volume
  //
  return fWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::PrintParameters()
{
  G4cout << "\n The Box is " << G4BestUnit(fBoxSizeXY,"Length")
         << " x " << G4BestUnit(fBoxSizeXY,"Length")
         << " x " << G4BestUnit(fBoxSizeZ,"Length")
         << " of " << fTargetMaterial->GetName() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetTargetMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* mat =
    G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);
  if (mat != fTargetMaterial) {
    if(mat) {
      fTargetMaterial = mat;
      UpdateGeometry();
    } else {
      G4cout << "### Warning!  Target material: <"
           << materialChoice << "> not found" << G4endl;  
    }     
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetWorldMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* mat =
    G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);
  if (mat != fWorldMaterial) {
    if(mat) {
      fWorldMaterial = mat;
      UpdateGeometry();
    } else {
      G4cout << "### Warning! World material: <"
           << materialChoice << "> not found" << G4endl;  
    }     
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetSizeXY(G4double value)
{
  fBoxSizeXY = value; 
  if (fWorldSize<fBoxSizeXY) fWorldSize = 1.2*fBoxSizeXY;
  UpdateGeometry();
}

void DetectorConstruction::SetSizeZ(G4double value)
{
  fBoxSizeZ = value; 
  if (fWorldSize<fBoxSizeZ) fWorldSize = 1.2*fBoxSizeZ;
  UpdateGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4RunManager.hh"

void DetectorConstruction::UpdateGeometry()
{
  if (fWorld) 
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
