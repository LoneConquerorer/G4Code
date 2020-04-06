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
/// \file DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 70755 2013-06-05 12:17:48Z ihrivnac $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

#include "G4SubtractionSolid.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include <cmath>
#include <math.h>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
 fWorldMater(0), fPhysiWorld(0),
 fDetectorMessenger(0)
{

  fMaterLaBr1 = 0;
  fLogicLaBr1 = 0;
  fMaterLaBr2 = 0;
  fLogicLaBr2 = 0;
  fMaterNaI1 = 0;
  fLogicNaI1 = 0;
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

  fLengthLaBr1      = 2.54*cm;
  fRadiusLaBr1      = 1.27*cm;

  fLengthLaBr2      = 2.54*cm;
  fRadiusLaBr2      = 1.27*cm;

  fLengthNaI1       = 7.62*cm;
  fRadiusNaI1       = 2.54*cm;

  fLengthNaI2       = 7.62*cm;
  fRadiusNaI2       = 2.54*cm;

  fLengthNaI3       = 7.62*cm;
  fRadiusNaI3       = 2.54*cm;

  fLengthNaI4       = 7.62*cm;
  fRadiusNaI4       = 2.54*cm;

  fLengthNaI5       = 7.62*cm;
  fRadiusNaI5       = 2.54*cm;

  fLengthNaI6       = 7.62*cm;
  fRadiusNaI6       = 2.54*cm;


//*** Changed to be constant
//  fWorldLength = std::max(fTargetLength,fDetectorLength);
//  fWorldRadius = fTargetRadius + fDetectorThickness;

  DefineMaterials();

  fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ delete fDetectorMessenger;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  return ConstructVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
  // build materials
  //
//  fDetectorMater =
//  new G4Material("Germanium", 32, 72.61*g/mole, 5.323*g/cm3);


  G4Element* N  = new G4Element("Nitrogen", "N", 7, 14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O", 8, 16.00*g/mole);
  //
  G4int ncomponents; G4double fractionmass;
  G4Material* Air20 = new G4Material("Air", 1.205*mg/cm3, ncomponents=2,
                      kStateGas, 293.*kelvin, 1.*atmosphere);
    Air20->AddElement(N, fractionmass=0.7);
    Air20->AddElement(O, fractionmass=0.3);
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
 a = 138.90547*g/mole;
 G4Element* elLanthanum = new G4Element(name="Lanthanum",symbol="La" , z= 57., a);

 a = 79.904*g/mole;
 G4Element* elBromine = new G4Element(name="Bromine" ,symbol="Br" , z= 35., a);
 density = 5.06*g/cm3;
 G4Material* LaBr = new G4Material(name="Lanthanum_Bromide",density,ncomponents=2);
 LaBr->AddElement(elLanthanum, natoms=1);
 LaBr->AddElement(elBromine, natoms=3);

  fMaterLaBr1 = LaBr;
  fMaterLaBr2 = LaBr;

  G4NistManager* nist = G4NistManager::Instance();

  G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
  G4Material* Aluminum = nist->FindOrBuildMaterial("G4_Al");

  Pb=Lead;
  Al=Aluminum;

  G4Material* NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");

  fMaterNaI1 = NaI;
  fMaterNaI2 = NaI;
  fMaterNaI3 = NaI;
  fMaterNaI4 = NaI;
  fMaterNaI5 = NaI;
  fMaterNaI6 = NaI;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::ConstructVolumes()
{
  // Cleanup old geometry
  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();

  // World
  //
  // (re) compute World dimensions if necessary
//*** Changed to be constant
//  fWorldLength = std::max(fTargetLength,fDetectorLength);
//  fWorldRadius = fTargetRadius + fDetectorThickness;

  G4double M_PI = 3.141592653589793238462643383279502884;

  G4Box*
  sWorld = new G4Box("World",                                 //name
                 1*m,1*m, 1*m); //dimensions

  G4LogicalVolume*
  lWorld = new G4LogicalVolume(sWorld,                  //shape
                             fWorldMater,               //material
                             "World");                  //name

  fPhysiWorld = new G4PVPlacement(0,                    //no rotation
                            G4ThreeVector(),            //at (0,0,0)
                            lWorld,                     //logical volume
                            "World",                    //name
                            0,                          //mother volume
                            false,                      //no boolean operation
                            0);                         //copy number

  // Target
  //
//  G4Tubs*
//  sTarget = new G4Tubs("Target",                                   //name
//                  0., fTargetRadius, 0.5*fTargetLength, 0.,twopi); //dimensions


//  fLogicTarget = new G4LogicalVolume(sTarget,           //shape
//                             fTargetMater,              //material
//                             "Target");                 //name

//           new G4PVPlacement(0,                         //no rotation
//                           G4ThreeVector(),             //at (0,0,0)
//                           fLogicTarget,                //logical volume
//                           "Target",                    //name
//                           lWorld,                      //mother  volume
//                           false,                       //no boolean operation
//                           0);                          //copy number

  // Detector
  //
//  G4Tubs*
//  sDetector = new G4Tubs("Detector",
//                fTargetRadius, fWorldRadius, 0.5*fDetectorLength, 0.,twopi);


//  fLogicDetector = new G4LogicalVolume(sDetector,       //shape
//                             fDetectorMater,            //material
//                             "Detector");               //name

//           new G4PVPlacement(0,                         //no rotation
//                           G4ThreeVector(0,0,10),             //at (0,0,0)
//                           fLogicDetector,              //logical volume
//                           "Detector",                  //name
//                           lWorld,                      //mother  volume
//                           false,                       //no boolean operation
//                           0);                          //copy number

   G4bool checkOverlaps = true;
//   G4NistManager* nist = G4NistManager::Instance();

//   G4Material* Pb = nist->FindOrBuildMaterial("G4_Pb");
//   G4Material* Al = nist->FindOrBuildMaterial("G4_Al");
   //
   // LaBr1
   //
//   G4Material* LaBr1_mat = nist->FindOrBuildMaterial("Lanthanum_Bromide");
   G4ThreeVector LaBrpos1 = G4ThreeVector(16.27*cm, 0, 0);

   // Conical section shape
//   G4double LaBr1_rmina =  0.*cm, LaBr1_rmaxa = 1.27*cm;
//   G4double LaBr1_rminb =  0.*cm, LaBr1_rmaxb = 1.27*cm;
//   G4double LaBr1_hz = 1.27*cm;
//   G4double LaBr1_phimin = 0.*deg, LaBr1_phimax = 360.*deg;
   G4Tubs* solidLaBr1 =
     new G4Tubs("LaBr1",
              0., fRadiusLaBr1, 0.5*fLengthLaBr1, 0., twopi);

   fLogicLaBr1 =
     new G4LogicalVolume(solidLaBr1,         //its solid
                         fMaterLaBr1,          //its material
                         "LaBr1");           //its name

   G4RotationMatrix* yRotLaBr1 = new G4RotationMatrix; // Rotates X and Z axes only
   yRotLaBr1->rotateY(M_PI/2.*rad);

   new G4PVPlacement(yRotLaBr1,                       //no rotation
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
  // G4Material* LaBr2_mat = nist->FindOrBuildMaterial("Lanthanum_Bromide");
   G4ThreeVector LaBrpos2 = G4ThreeVector(-16.27*cm, 0, 0);

   // Conical section shape
//   G4double LaBr2_rmina =  0.*cm, LaBr2_rmaxa = 1.27*cm;
//   G4double LaBr2_rminb =  0.*cm, LaBr2_rmaxb = 1.27*cm;
//   G4double LaBr2_hz = 1.27*cm;
//   G4double LaBr2_phimin = 0.*deg, LaBr2_phimax = 360.*deg;
  G4Tubs* solidLaBr2 =new G4Tubs("LaBr2",
           0., fRadiusLaBr2, 0.5*fLengthLaBr2, 0., twopi);

   fLogicLaBr2 = new G4LogicalVolume(solidLaBr2,         //its solid
                         fMaterLaBr2,          //its material
                         "LaBr2");           //its name

   G4RotationMatrix* yRotLaBr2 = new G4RotationMatrix; // Rotates X and Z axes only
   yRotLaBr2->rotateY(M_PI/2.*rad);

  new G4PVPlacement(yRotLaBr2,                       //no rotation
                    LaBrpos2,                    //at position
                    fLogicLaBr2,             //its logical volume
                    "LaBr2",                //its name
                    lWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


   //
   // Detector1
   //
//   G4Material* detector1_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
   G4ThreeVector pos1 = G4ThreeVector(16.27*cm, 0, 11.61*cm);

   // Conical section shape
//   G4double detector1_rmina =  0.*cm, detector1_rmaxa = 2.54*cm;
//   G4double detector1_rminb =  0.*cm, detector1_rmaxb = 2.54*cm;
//   G4double detector1_hz = 3.81*cm;
//   G4double detector1_phimin = 0.*deg, detector1_phimax = 360.*deg;
G4Tubs* solidDetector1 =new G4Tubs("NaI1",
         0., fRadiusNaI1, 0.5*fLengthNaI1, 0., twopi);

   fLogicNaI1 = new G4LogicalVolume
                         (solidDetector1,         //its solid
                         fMaterNaI1,          //its material
                         "NaI1");           //its name

   new G4PVPlacement(0,                       //no rotation
                     pos1,                    //at position
                     fLogicNaI1,             //its logical volume
                     "NaI1",                //its name
                     lWorld,                //its mother  volume
                     false,                   //no boolean operation
                     0,                       //copy number
                     checkOverlaps);          //overlaps checking



   //
   // Detector 2
   //
  // G4Material* detector2_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
   G4ThreeVector pos2 = G4ThreeVector(-16.27*cm, 0, 11.61*cm);

   // Conical section shape
//   G4double detector2_rmina =  0.*cm, detector2_rmaxa = 2.54*cm;
//   G4double detector2_rminb =  0.*cm, detector2_rmaxb = 2.54*cm;
//   G4double detector2_hz = 3.81*cm;
//   G4double detector2_phimin = 0.*deg, detector2_phimax = 360.*deg;
G4Tubs* solidDetector2 =new G4Tubs("NaI2",
         0., fRadiusNaI2, 0.5*fLengthNaI2, 0., twopi);

   fLogicNaI2 = new G4LogicalVolume
                         (solidDetector2,         //its solid
                         fMaterNaI2,          //its material
                         "NaI2");           //its name

   new G4PVPlacement(0,                       //no rotation
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
    // Detector3
    //
//    G4Material* detector3_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
    G4ThreeVector pos3 = G4ThreeVector(-16.27*cm, 11.61/std::sqrt(2)*cm, 11.61/std::sqrt(2)*cm);

    // Conical section shape
//    G4double detector3_rmina =  0.*cm, detector3_rmaxa = 2.54*cm;
//    G4double detector3_rminb =  0.*cm, detector3_rmaxb = 2.54*cm;
//    G4double detector3_hz = 3.81*cm;
//    G4double detector3_phimin = 0.*deg, detector3_phimax = 360.*deg;
G4Tubs* solidDetector3 =new G4Tubs("NaI3",
         0., fRadiusNaI3, 0.5*fLengthNaI3, 0., twopi);

   fLogicNaI3 = new G4LogicalVolume
                         (solidDetector3,         //its solid
                         fMaterNaI3,          //its material
                         "NaI3");           //its name

    G4RotationMatrix* xRot3 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot3->rotateX(M_PI/4.*rad);

    new G4PVPlacement(xRot3,                       //no rotation
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
    // Detector4
    //
//    G4Material* detector4_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
    G4ThreeVector pos4 = G4ThreeVector(-16.27*cm, 11.61*cm, 0);

    // Conical section shape
//    G4double detector4_rmina =  0.*cm, detector4_rmaxa = 2.54*cm;
//    G4double detector4_rminb =  0.*cm, detector4_rmaxb = 2.54*cm;
//    G4double detector4_hz = 3.81*cm;
//    G4double detector4_phimin = 0.*deg, detector4_phimax = 360.*deg;
G4Tubs* solidDetector4 =new G4Tubs("NaI4",
         0., fRadiusNaI4, 0.5*fLengthNaI4, 0., twopi);

   fLogicNaI4 = new G4LogicalVolume
                         (solidDetector4,         //its solid
                         fMaterNaI4,          //its material
                         "NaI4");           //its name


    G4RotationMatrix* xRot4 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot4->rotateX(M_PI/2.*rad);

    new G4PVPlacement(xRot4,                       //no rotation
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
    // Detector5
    //
//    G4Material* detector5_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
    G4ThreeVector pos5 = G4ThreeVector(-16.27*cm, 11.61/std::sqrt(2)*cm, -11.61/std::sqrt(2)*cm);

    // Conical section shape
//    G4double detector5_rmina =  0.*cm, detector5_rmaxa = 2.54*cm;
//    G4double detector5_rminb =  0.*cm, detector5_rmaxb = 2.54*cm;
//    G4double detector5_hz = 3.81*cm;
//    G4double detector5_phimin = 0.*deg, detector5_phimax = 360.*deg;
G4Tubs* solidDetector5 =new G4Tubs("NaI5",
         0., fRadiusNaI5, 0.5*fLengthNaI5, 0., twopi);

   fLogicNaI5 = new G4LogicalVolume
                         (solidDetector5,         //its solid
                         fMaterNaI5,          //its material
                         "NaI5");           //its name


    G4RotationMatrix* xRot5 = new G4RotationMatrix; // Rotates Y and Z axes only
    xRot5->rotateX(-M_PI/4.*rad);

    new G4PVPlacement(xRot5,                       //no rotation
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
    // Detector6
    //
//    G4Material* detector6_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
    G4ThreeVector pos6 = G4ThreeVector(-16.27*cm, 0, -11.61*cm);

    // Conical section shape
//    G4double detector6_rmina =  0.*cm, detector6_rmaxa = 2.54*cm;
//    G4double detector6_rminb =  0.*cm, detector6_rmaxb = 2.54*cm;
//    G4double detector6_hz = 3.81*cm;
//    G4double detector6_phimin = 0.*deg, detector6_phimax = 360.*deg;
G4Tubs* solidDetector6 =new G4Tubs("NaI6",
         0., fRadiusNaI6, 0.5*fLengthNaI6, 0., twopi);

   fLogicNaI6 = new G4LogicalVolume
                         (solidDetector6,         //its solid
                         fMaterNaI6,          //its material
                         "NaI6");           //its name

     new G4PVPlacement(0,                       //no rotation
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
      //Source Shield
      //
//      G4Box* Source_Shield =
//                7.5*cm, 7.5*cm, 7.5*cm);     //its size
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


              //
              //Aluminum Chip
              //



        G4Box * aluminumChip = new G4Box("aluminumChip",
                                    0.05*cm,
                                    1.27*cm,
                                    1.27*cm);

        G4LogicalVolume* logicAluminumChip =
          new G4LogicalVolume(aluminumChip,          //its solid
                              Al,                   //its material
                              "aluminumChip");            //its name

        new G4PVPlacement(0,                     //no rotation
                          G4ThreeVector(),       //at (0,0,0)
                          logicAluminumChip,            //its logical volume
                          "aluminumChip",               //its name
                          lWorld,                     //its mother  volume
                          false,                 //no boolean operation
                          0,                     //copy number
                          checkOverlaps);        //overlaps checking


//  PrintParameters();

  //always return the root volume
  //
  return fPhysiWorld;
}




G4double DetectorConstruction::GetLengthLaBr(G4int num)
{
  G4double result = 0.0;
  switch (num)
  {
    case 1:
      result =  fLengthLaBr1;
      break;
    case 2:
      result =  fLengthLaBr2;
      break;
    default:
      break;
  }
  return result;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetRadiusLaBr(G4int num)
{
  G4double result = 0.0;
  switch (num)
  {
    case 1:
      result = fRadiusLaBr1;
      break;
    case 2:
      result = fRadiusLaBr2;
      break;
    default:
      break;
  }
  return result;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetMaterialLaBr(G4int num)
{
  G4Material* result = 0;
  switch (num)
  {
    case 1:
      result = fMaterLaBr1;
      break;
    case 2:
      result = fMaterLaBr2;
      break;
    default:
      break;
  }
  return result;
}





//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* DetectorConstruction::GetLogicLaBr(G4int num)
{
  G4LogicalVolume* result = 0;
  switch (num)
  {
    case 1:
      result = fLogicLaBr1;
      break;
    case 2:
      result = fLogicLaBr2;
      break;
    default:
      break;
  }
  return result;
}



G4double DetectorConstruction::GetLengthNaI(G4int num)
{
  G4double result = 0.0;
  switch (num)
  {
    case 1:
      result = fLengthNaI1;
      break;
    case 2:
      result = fLengthNaI2;
      break;
    case 3:
      result = fLengthNaI3;
      break;
    case 4:
      result = fLengthNaI4;
      break;
    case 5:
      result = fLengthNaI5;
      break;
    case 6:
      result = fLengthNaI6;
      break;
    default:
      break;
  }
  return result;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetRadiusNaI(G4int num)
{
  G4double result = 0.0;
  switch (num)
  {
    case 1:
      result = fRadiusNaI1;
      break;
    case 2:
      result = fRadiusNaI2;
      break;
    case 3:
      result = fRadiusNaI3;
      break;
    case 4:
      result = fRadiusNaI4;
      break;
    case 5:
      result = fRadiusNaI5;
      break;
    case 6:
      result = fRadiusNaI6;
      break;
    default:
      break;
  }
  return result;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetMaterialNaI(G4int num)
{
  G4Material* result = 0;
  switch (num)
  {
    case 1:
      result = fMaterNaI1;
      break;
    case 2:
      result = fMaterNaI2;
      break;
    case 3:
      result = fMaterNaI3;
      break;
    case 4:
      result = fMaterNaI4;
      break;
    case 5:
      result = fMaterNaI5;
      break;
    case 6:
      result = fMaterNaI6;
      break;
    default:
      break;
  }
  return result;
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* DetectorConstruction::GetLogicNaI(G4int num)
{
  G4LogicalVolume* result = 0;
  switch (num)
  {
    case 1:
      result = fLogicNaI1;
      break;
    case 2:
      result = fLogicNaI2;
      break;
    case 3:
      result = fLogicNaI3;
      break;
    case 4:
      result = fLogicNaI4;
      break;
    case 5:
      result = fLogicNaI5;
      break;
    case 6:
      result = fLogicNaI6;
      break;
    default:
      break;
  }
  return result;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
void DetectorConstruction::PrintParameters()
{
  G4cout << "\n Target : Length = " << G4BestUnit(fTargetLength,"Length")
         << " Radius = " << G4BestUnit(fTargetRadius,"Length")
         << " Material = " << fTargetMater->GetName();
  G4cout << "\n Detector : Length = " << G4BestUnit(fDetectorLength,"Length")
         << " Tickness = " << G4BestUnit(fDetectorThickness,"Length")
         << " Material = " << fDetectorMater->GetName() << G4endl;
  G4cout << "\n" << fTargetMater << "\n" << fDetectorMater << G4endl;
}G4double DetectorConstruction::GetDetectorLength()
{
  return fDetectorLength;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetDetectorThickness()
{
  return fDetectorThickness;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetDetectorMaterial()
{
  return fDetectorMater;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* DetectorConstruction::GetLogicDetector()
{
  return fLogicDetector;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetTargetMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* pttoMaterial =
     G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);

  if (pttoMaterial) {
    fTargetMater = pttoMaterial;
    if(fLogicTarget) { fLogicTarget->SetMaterial(fTargetMater); }
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();
  } else {
    G4cout << "\n--> warning from DetectorConstruction::SetTargetMaterial : "
           << materialChoice << " not found" << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetDetectorMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* pttoMaterial =
     G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);

  if (pttoMaterial) {
    fDetectorMater = pttoMaterial;
    if(fLogicDetector) { fLogicDetector->SetMaterial(fDetectorMater); }
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();
  } else {
    G4cout << "\n--> warning from DetectorConstruction::SetDetectorMaterial : "
           << materialChoice << " not found" << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetTargetRadius(G4double value)
{
  fTargetRadius = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetTargetLength(G4double value)
{
  fTargetLength = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetDetectorThickness(G4double value)
{
  fDetectorThickness = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetDetectorLength(G4double value)
{
  fDetectorLength = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetTargetLength()
{
  return fTargetLength;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetTargetRadius()
{
  return fTargetRadius;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetTargetMaterial()
{
  return fTargetMater;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* DetectorConstruction::GetLogicTarget()
{
  return fLogicTarget;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetDetectorLength()
{
  return fDetectorLength;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4double DetectorConstruction::GetDetectorThickness()
{
  return fDetectorThickness;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Material* DetectorConstruction::GetDetectorMaterial()
{
  return fDetectorMater;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4LogicalVolume* DetectorConstruction::GetLogicDetector()
{
  return fLogicDetector;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
*/
