#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"


class mySteppingAction : public G4UserSteppingAction {

public:

	mySteppingAction(myEventAction* event);
	~mySteppingAction();

	virtual void UserSteppingAction(const G4Step*);

private:
	myEventAction *fEventAction;
};


#endif