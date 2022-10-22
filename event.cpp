//
// Created by jeppe on 9/20/22.
//

#include "event.h"

MyEventAction::MyEventAction(MyRunAction *) {
    fEdep1 = 0;
    fEdep2 = 0;
    fEdepTot = 0;
    alphaE = 0;
    neutronE = 0;
    tritonE = 0;
    gammaE = 0;
    Li7E = 0;
}

MyEventAction::~MyEventAction(){
}

void MyEventAction::BeginOfEventAction(const G4Event *) {
    fEdep1 = 0;
    fEdep2 = 0;
    fEdepTot = 0;
    alphaE = 0;
    neutronE = 0;
    tritonE = 0;
    gammaE = 0;
    Li7E = 0;
}

void MyEventAction::EndOfEventAction(const G4Event *) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man ->FillNtupleDColumn(1,0,fEdep1*GeV); //Don't know why it has to be *GeV to print out unit in keV
    man ->FillNtupleDColumn(1,1,fEdep2*GeV);
    man ->FillNtupleDColumn(1,2,fEdepTot*GeV);

    man ->FillNtupleDColumn(1,3,alphaE*GeV); //Don't know why it has to be *GeV to print out unit in keV
    man ->FillNtupleDColumn(1,4,neutronE*GeV);
    man ->FillNtupleDColumn(1,5,tritonE*GeV);
    man ->FillNtupleDColumn(1,6,gammaE*GeV);
    man ->FillNtupleDColumn(1,7,Li7E*GeV);
    man -> AddNtupleRow(1);
}