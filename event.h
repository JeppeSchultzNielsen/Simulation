//
// Created by jeppe on 9/20/22.
//

#ifndef SIMULATION_EVENT_H
#define SIMULATION_EVENT_H

#include "G4UserEventAction.hh"
#include "G4EventManager.hh"
#include "G4AnalysisManager.hh"
#include "run.h"
#include "G4SystemOfUnits.hh"

class MyEventAction : public G4UserEventAction {
public:
    MyEventAction(MyRunAction*);
    ~MyEventAction();

    virtual void BeginOfEventAction(const G4Event*);

    virtual void EndOfEventAction(const G4Event*);

    void AddEdep1(G4double edep){fEdep1 += edep;}
    void AddEdep2(G4double edep){fEdep2 += edep;}
    void AddEdepTot(G4double edep){fEdepTot += edep;}
    void writeAlphaE(G4double ekin){if(alphaE == 0) alphaE = ekin;}
    void writeNeutronE(G4double ekin){if(neutronE == 0) neutronE = ekin;}
    void writeTritonE(G4double ekin){if(tritonE == 0) tritonE = ekin;}
    void writeGammaE(G4double ekin){if(gammaE == 0) gammaE = ekin;}
    void writeLi7E(G4double ekin){if(Li7E == 0) Li7E = ekin;}
private:
    G4double fEdep1;
    G4double fEdep2;
    G4double fEdepTot;
    G4double alphaE;
    G4double neutronE;
    G4double tritonE;
    G4double gammaE;
    G4double Li7E;
};


#endif //SIMULATION_EVENT_H
