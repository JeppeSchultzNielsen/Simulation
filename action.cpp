//
// Created by jeppe on 9/18/22.
//

#include "action.h"

MyActionInitialization::MyActionInitialization(){}

void MyActionInitialization::Build() const{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);

    MyEventAction *eventAction = new MyEventAction(runAction);
    SetUserAction(eventAction);

    MySteppingAction *steppingAction = new MySteppingAction(eventAction);
    SetUserAction(steppingAction);
}

void MyActionInitialization::BuildForMaster() const{
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}
