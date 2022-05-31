#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "g4root.hh"
#include "G4SystemOfUnits.hh"




class myDetector : public G4VSensitiveDetector
{
public:

	myDetector(G4String);
	~myDetector();

private:
	virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*);

	G4PhysicsOrderedFreeVector *QE;
};


#endif