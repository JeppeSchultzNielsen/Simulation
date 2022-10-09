//
// Created by jeppe on 9/20/22.
//

#ifndef SIMULATION_RUN_H
#define SIMULATION_RUN_H

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"

class MyRunAction : public G4UserRunAction {
public:
    MyRunAction();
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
private:
};


#endif //SIMULATION_RUN_H
