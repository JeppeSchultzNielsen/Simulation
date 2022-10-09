//
// Created by jeppe on 9/18/22.
//

#ifndef SIMULATION_ACTION_H
#define SIMULATION_ACTION_H

#include "G4VUserActionInitialization.hh"
#include "generator.h"
#include "run.h"
#include "stepping.h"
#include "event.h"

class MyActionInitialization : public G4VUserActionInitialization{
public:
    MyActionInitialization();

    virtual void Build() const;
    virtual void BuildForMaster() const;
};


#endif //SIMULATION_ACTION_H
