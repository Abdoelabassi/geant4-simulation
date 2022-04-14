#include "generator.hh"


myPrimaryGenerator::myPrimaryGenerator()
{
	myGun = new G4ParticleGun(1);

	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName = "proton";
	G4ParticleDefinition *particle = particleTable->FindParticle("proton");

	G4ThreeVector pos(0,0,0);
	G4ThreeVector mom(0,0,1.);

	myGun->SetParticlePosition(pos);
	myGun->SetParticleMomentumDirection(mom);
	myGun->SetParticleMomentum(100*GeV);
	myGun->SetParticleDefinition(particle);

}


#include "generator.hh"

myPrimaryGenerator::~myPrimaryGenerator()
{
	delete myGun;

}

void myPrimaryGenerator::GeneratePrimaries(G4Event *nevent)
{
	

	myGun->GeneratePrimaryVertex(nevent);

}