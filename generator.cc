#include "generator.hh"


myPrimaryGenerator::myPrimaryGenerator()
{
	myGun = new G4ParticleGun(1);

	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("geantino");

	G4ThreeVector pos(0,0,0);
	G4ThreeVector mom(0,0,1.);

	myGun->SetParticlePosition(pos);
	myGun->SetParticleMomentumDirection(mom);
	myGun->SetParticleMomentum(10*GeV);
	myGun->SetParticleDefinition(particle);

}


#include "generator.hh"

myPrimaryGenerator::~myPrimaryGenerator()
{
	delete myGun;

}

void myPrimaryGenerator::GeneratePrimaries(G4Event *nevent)
{
	
	G4ParticleDefinition *particle = myGun->GetParticleDefinition();

	if(particle == G4Geantino::Geantino()){

		G4int Z = 27;
		G4int A = 60;

		G4double charge = 0*eplus;
		G4double energy = 0*keV;

		G4ParticleDefinition *ion = G4IonTable::GetIonTable()->GetIon(Z,A,energy);
		myGun->SetParticleDefinition(ion);
		myGun->SetParticleCharge(charge);
	}

	myGun->GeneratePrimaryVertex(nevent);

}