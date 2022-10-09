//
// Created by jeppe on 9/4/22.
//
#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include <G4PVPlacement.hh>
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "detector.h"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"

#ifndef SIMULATION_CONSTRUCTION_H
#define SIMULATION_CONSTRUCTION_H

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();

    G4LogicalVolume *GetScoringVolume1() const {
        return fScoringVolume1;
    }

    G4LogicalVolume *GetScoringVolume2() const {
        return fScoringVolume2;
    }

    G4VPhysicalVolume *GetWorldPhysVolume() const {
        return physWorld;
    }

private:

    G4LogicalVolume *logicDetector, *logicWorld, *logicSiDet1, *logicSiDet2, *fScoringVolume1, *fScoringVolume2, *logicAlCase, *logicVacuum, *logicNeutronDet;
    G4Tubs *solidScintillator;
    G4Material *NaI, *Si;
    G4Element *Na, *I;
    G4Box *solidWorld, *solidSiDet1, *solidSiDet2, *solidAlCase, *solidVacuum, *solidNeutronDet;
    G4VPhysicalVolume *physSiDet1, *physSiDet2, *physWorld, *physAlCase, *physVacuum, *physNeutronDet;
    G4NistManager *nist;

    G4double xWorld, yWorld, zWorld;
    void ConstructScintillator();
};



#endif //SIMULATION_CONSTRUCTION_H
