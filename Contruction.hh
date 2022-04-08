#ifndef CONTRUCTION_HH
#define CONTRUCTION_HH
#include "G4UserDetectorConstruction.hh"

class myDetectorConstruction : public G4UserDetectorConstruction{
public:
	myDetectorConstruction();
	~myDetectorConstruction();

	virtual G4VPhysicalVolume *Construct();

}


#endif