#include "construction.h"

MyDetectorConstruction::MyDetectorConstruction() {
    nist = G4NistManager::Instance();

    xWorld = 1*m;
    yWorld = 1*m;
    zWorld = 1*m;

    Si = new G4Material("Si", 2.33*g/cm3, 1);
    Si ->AddElement(nist ->FindOrBuildElement("Si"),1);
}

MyDetectorConstruction::~MyDetectorConstruction() {}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    //G4Material *worldMat = nist ->FindOrBuildMaterial("G4_AIR");

    //pV = nRT => n/V = p/RT => density = pressure * molar mass (assume N2) / (R * 293 K)
    G4double density = 1 * 14 / (8.31446261815324*293); //R in unit m3⋅Pa⋅K−1⋅mol−1 -> this is at pressure of 1e-6 mBar
    G4Material *vacuumMat = new G4Material("vacuum",density*g/m3,2);
    auto O = nist ->FindOrBuildElement("O");
    auto N = nist ->FindOrBuildElement("N");
    vacuumMat ->AddElement(O,20);
    vacuumMat ->AddElement(N,80);

    density = 100000000*101.325 * 14 / (8.31446261815324*293);
    G4Material *worldMat = new G4Material("h2",density*g/cm3,1);
    auto He3 = nist ->FindOrBuildElement("H");
    worldMat ->AddElement(He3,1);

    G4Material *alMat = new G4Material("Aluminum",2.7*g/cm3,1);
    auto al = nist ->FindOrBuildElement("Al");
    alMat ->AddElement(al,1);

    solidWorld = new G4Box("solidWorld",xWorld,yWorld,zWorld);
    logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld");
    physWorld = new G4PVPlacement(0,G4ThreeVector(0,0,0),logicWorld,"physWorld",0,false,0, true);

    //create aluminum casing
    solidAlCase = new G4Box("solidAlCase",40*cm,40*cm,40*cm);
    logicAlCase = new G4LogicalVolume(solidAlCase,alMat,"logicAlCase");
    physAlCase = new G4PVPlacement(0,G4ThreeVector(0,0,0), logicAlCase,"physAlCase",logicWorld,false,0,true);

    //create vacuum within aluminum casing
    solidVacuum = new G4Box("solidVacuum",36*cm,36*cm,36*cm);
    logicVacuum = new G4LogicalVolume(solidVacuum,vacuumMat,"logicVacuum");
    physVacuum = new G4PVPlacement(0,G4ThreeVector(0,0,0), logicVacuum,"physAlCase",logicAlCase,false,0,true);

    ConstructScintillator();

    return physWorld;
}

void MyDetectorConstruction::ConstructScintillator() {
    solidSiDet1 = new G4Box("solidScintillator1", 30*cm, 30*cm, 200*micrometer);
    logicSiDet1 = new G4LogicalVolume(solidSiDet1, Si, "logicalScintillator1");
    fScoringVolume1 = logicSiDet1;
    physSiDet1 = new G4PVPlacement(0, G4ThreeVector(0,0,20*cm), logicSiDet1, "physScintillator", logicVacuum, false, 0, true);

    solidSiDet2 = new G4Box("solidScintillator2", 30*cm, 30*cm, 200*micrometer);
    logicSiDet2 = new G4LogicalVolume(solidSiDet2, Si, "logicalScintillator2");
    fScoringVolume2 = logicSiDet2;
    physSiDet2 = new G4PVPlacement(0, G4ThreeVector(0,0,-20*cm), logicSiDet2, "physScintillator2", logicVacuum, false, 0, true);

    solidNeutronDet = new G4Box("solidNeutronDet", 3*cm, 3*cm, 3*cm);
    logicNeutronDet = new G4LogicalVolume(solidNeutronDet, Si, "logicNeutronDet");
    physNeutronDet = new G4PVPlacement(0, G4ThreeVector(70*cm,0,0), logicNeutronDet, "physNeutronDet", logicWorld, false, 0, true);
}