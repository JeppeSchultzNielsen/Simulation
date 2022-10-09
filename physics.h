//
// Created by jeppe on 9/4/22.
//

#ifndef SIMULATION_PHYSICS_H
#define SIMULATION_PHYSICS_H
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"


class MyPhysicsList : public G4VModularPhysicsList {
public:
    MyPhysicsList();
};


#endif //SIMULATION_PHYSICS_H
