//
// Created by jeppe on 9/18/22.
//

#ifndef SIMULATION_GENERATOR_H
#define SIMULATION_GENERATOR_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Geantino.hh"
#include "G4IonTable.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction {
public:
    MyPrimaryGenerator();

    virtual void GeneratePrimaries(G4Event*);
private:
    G4ParticleGun * fParticleGun;
};


#endif //SIMULATION_GENERATOR_H
