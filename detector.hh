#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"





class myDetector : public G4VSensitiveDetector
{
public:

	myDetector(G4String);
	~myDetector();

private:
	virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);
};


#endif