//
// Created by jeppe on 9/18/22.
//

#include "generator.h"
MyPrimaryGenerator::MyPrimaryGenerator(){
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable-> FindParticle("geantino");

    G4ThreeVector pos(0,0,0);

    G4ThreeVector mom(0,0,1);

    fParticleGun ->SetParticlePosition(pos);
    fParticleGun ->SetParticleMomentumDirection(mom);
    fParticleGun ->SetParticleMomentum(0. * MeV);
    fParticleGun ->SetParticleDefinition(particle);
};

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleDefinition *particle = fParticleGun -> GetParticleDefinition();

    //cobalt is 27,60, 8Be is 4,8, 8Li is 3,8
    if(particle == G4Geantino::Geantino()){
        G4int Z = 2;
        G4int A = 8;
        G4double charge = 0 * eplus;
        G4double energy = 0 * keV;

        G4ParticleDefinition *ion = G4IonTable::GetIonTable() -> GetIon(Z,A,energy);

        fParticleGun ->SetParticleDefinition(ion);
        fParticleGun -> SetParticleCharge(charge);
    }

    fParticleGun ->GeneratePrimaryVertex(anEvent);
}