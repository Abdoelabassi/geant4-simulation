#include "physics.hh"


myphysicsList::myphysicsList(){

	RegisterPhysics (new G4EmStandardPhysics());
	RegisterPhysics(new G4OpticalPhysics());

}


myphysicsList::~myphysicsList(){

}

