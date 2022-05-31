#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4NistManager.hh"
#include "G4GenericMessenger.hh"
#include "G4Tubs.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction 

{



public:


	MyDetectorConstruction();
	~MyDetectorConstruction();

	G4LogicalVolume *GetScoringVolume() const {return fScoringVolume;}



	virtual G4VPhysicalVolume *Construct();

private:
	

	virtual void ConstructSDandField();

	G4int nCols, nRows;
	G4bool isCherenkov, isScintillator;


	G4Box *solidWorld , *solidRadiator, *solidDetector, *solidScintillator;

	G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector, *logicScintillator;

	G4VPhysicalVolume *physRadiator, *physWorld, *physDetector, *phyScintillator;

	G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI;


	G4Element *C, *Na, *I;


	void ConstructCherenkov();

	void ConstructScintillator();


	G4GenericMessenger *fMessenger;
	G4LogicalVolume *fScoringVolume;

	void DefineMaterials();

};


#endif	
