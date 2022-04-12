#ifndef GENERATOR_HH
#define GENERATOR_HH
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

class myPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:

	myPrimaryGenerator();
	~myPrimaryGenerator();

	virtual void GeneratePrimaries(G4Event*);


private:

	G4ParticleGun *myGun;

};


#endif