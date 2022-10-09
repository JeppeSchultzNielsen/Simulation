//
// Created by jeppe on 9/18/22.
//

#include "detector.h"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name){};

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){
    G4Track *track = aStep -> GetTrack();

    track ->SetTrackStatus(fStopAndKill);

    G4StepPoint *preStepPoint = aStep -> GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep -> GetPostStepPoint();

    G4ThreeVector  posPhoton = preStepPoint -> GetPosition();

    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->FillNtupleIColumn(0, evt);
    man->AddNtupleRow(0);
    return true;
}