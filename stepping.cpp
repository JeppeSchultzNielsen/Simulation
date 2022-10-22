//
// Created by jeppe on 9/20/22.
//

#include "stepping.h"

MySteppingAction::MySteppingAction(MyEventAction *eventAction) {
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction(){}

void MySteppingAction::UserSteppingAction(const G4Step *step) {
    auto x = step->GetPostStepPoint()->GetPosition().x();
    auto y = step->GetPostStepPoint()->GetPosition().y();
    auto z = step->GetPostStepPoint()->GetPosition().z();

    if(abs(x) > 400 || abs(y) > 400 || abs(z) > 400) return;

    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

    const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

    G4LogicalVolume *fScoringVolume1 = detectorConstruction->GetScoringVolume1();
    G4LogicalVolume *fScoringVolume2 = detectorConstruction->GetScoringVolume2();

    G4String particleType = step -> GetTrack() -> GetParticleDefinition() -> GetParticleName();

    //G4cout << particleType << G4endl;

    /*G4cout <<"Scoring2: " << fScoringVolume2 -> GetName() << G4endl;
    G4cout <<"Current: " <<  volume -> GetName() << G4endl;*/

    /*if(particleType[2] == '5'){
        G4cout << particleType << G4endl;
    }*/

    G4double edep = step -> GetTotalEnergyDeposit();
    if(volume == fScoringVolume1){
        fEventAction ->AddEdep1(edep);
    }

    if(volume == fScoringVolume2){
        fEventAction ->AddEdep2(edep);
    }

    if(particleType == "neutron"){
        fEventAction ->writeNeutronE(step -> GetPreStepPoint() -> GetKineticEnergy());
    }

    if(particleType == "alpha"){
        fEventAction ->writeAlphaE(step -> GetPreStepPoint() -> GetKineticEnergy());
    }

    if(particleType == "triton"){
        fEventAction ->writeTritonE(step -> GetPreStepPoint() -> GetKineticEnergy());
    }

    if(particleType == "gamma"){
        //G4cout << step -> GetPreStepPoint() -> GetKineticEnergy() << G4endl;
        fEventAction ->writeGammaE(step -> GetPreStepPoint() -> GetKineticEnergy());
    }

    if(particleType == "Li7"){
        fEventAction ->writeLi7E(step -> GetPreStepPoint() -> GetKineticEnergy());
    }


}