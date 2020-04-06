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

  fLengthLaBr1 = 2.54*cm;
  fRadiusLaBr1 = 1.27*cm;

  fLengthLaBr2 = 2.54*cm;
  fRadiusLaBr2 = 1.27*cm;

 // fLengthNaI1 = 7.62*cm;
 // fRadiusNaI1 = 2.54*cm;

  fLengthNaI12 = 7.62*cm;
  fRadiusNaI12 = 2.54*cm;

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

   fMaterNaI2 = NaI;
   fMaterNaI3 = NaI;
   fMaterNaI4 = NaI;
   fMaterNaI5 = NaI;
   fMaterNaI6 = NaI;
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
  
  G4ThreeVector LaBrpos1 = G4ThreeVector(-16.27*cm, 0, 0);

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
  G4ThreeVector LaBrpos2 = G4ThreeVector(16.27*cm, 0, 0);

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
  //G4ThreeVector pos12 = G4ThreeVector(16.27*cm, 0, 11.61*cm);
  G4ThreeVector pos12 = G4ThreeVector(-16.27*cm, 0, -11.61*cm);
  //G4ThreeVector pos12 = G4ThreeVector(16.27*cm, 11.61*cm, 0);
  G4Tubs* solidDetector12 = new G4Tubs("NaI12",
                                       0., fRadiusNaI12, 0.5*fLengthNaI12, 0., twopi);

  fLogicNaI12 = new G4LogicalVolume
                                   (solidDetector12,         //its solid
                                      fMaterNaI12,          //its material
                                      "NaI12");           //its name
  G4RotationMatrix* xRot12 = new G4RotationMatrix; // Rotates Y and Z axes only
  xRot12->rotateX(M_PI / 2.*rad);


  fPhysNaI12 = new G4PVPlacement(0, //,  xRot12                     //no rotation
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

              new G4PVPlacement(0, //xRot12,                         //no rotation
                              pos12,             //at (0,0,0)
                              logicPbShield_12,              //logical volume
                              "PbShield_12",                  //name
                              lWorld,                      //mother  volume
                              false,                       //no boolean operation
                              0);

   //
   // Detector 2
   //
  G4ThreeVector pos2 = G4ThreeVector(16.27*cm, 0, 11.61*cm);

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
     G4ThreeVector pos3 = G4ThreeVector(16.27*cm, 11.61 / std::sqrt(2)*cm, 11.61 / std::sqrt(2)*cm);

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
      G4ThreeVector pos4 = G4ThreeVector(16.27*cm, 11.61*cm, 0);
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
   G4ThreeVector pos5 = G4ThreeVector(16.27*cm, 11.61 / std::sqrt(2)*cm, -11.61 / std::sqrt(2)*cm);

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
     G4ThreeVector pos6 = G4ThreeVector(16.27*cm, 0, -11.61*cm);

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
