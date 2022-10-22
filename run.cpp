//
// Created by jeppe on 9/20/22.
//

#include "run.h"

MyRunAction::MyRunAction(){}
MyRunAction::~MyRunAction(){
    delete G4AnalysisManager::Instance();
}

void MyRunAction::BeginOfRunAction(const G4Run*) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->OpenFile("output.root");

    man->CreateNtuple("Hits","Hits");
    man->CreateNtupleIColumn("fEvent");
    man -> FinishNtuple(0);

    man ->CreateNtuple("Scoring","Scoring");
    man ->CreateNtupleDColumn("fEdep1");
    man ->CreateNtupleDColumn("fEdep2");
    man ->CreateNtupleDColumn("fEdepTot");
    man ->CreateNtupleDColumn("AlphaE");
    man ->CreateNtupleDColumn("NeutronE");
    man ->CreateNtupleDColumn("TritonE");
    man ->CreateNtupleDColumn("GammaE");
    man ->CreateNtupleDColumn("Li7E");
    man -> FinishNtuple(1);
}

void MyRunAction::EndOfRunAction(const G4Run*) {
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man -> Write();
    man -> CloseFile();
}
