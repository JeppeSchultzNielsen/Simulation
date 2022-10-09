//
// Created by jeppe on 9/20/22.
//

#ifndef SIMULATION_STEPPING_H
#define SIMULATION_STEPPING_H

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.h"
#include "event.h"

class MySteppingAction : public G4UserSteppingAction {
public:
    MySteppingAction(MyEventAction* eventAction);
    ~MySteppingAction();

    virtual void UserSteppingAction(const G4Step*);
private:
    MyEventAction *fEventAction;
};


#endif //SIMULATION_STEPPING_H
