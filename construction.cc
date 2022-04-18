#include "construction.hh"
#include "detector.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
	fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");

	fMessenger->DeclareProperty("nCols", nCols, "Number of columns");
	fMessenger->DeclareProperty("nRows", nRows, "Number of rows");

	nCols = 30;
	nRows = 30;

	DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction()
{}

void MyDetectorConstruction::DefineMaterials(){

	G4NistManager *nist = G4NistManager::Instance();


	SiO2 = new G4Material("SiO2",2.201*g/cm3, 2);
	SiO2->AddElement(nist->FindOrBuildElement("Si"),1);
	SiO2->AddElement(nist->FindOrBuildElement("O"),2);

	H2O = new G4Material("H2O",1.00*g/cm3,2);
	H2O->AddElement(nist->FindOrBuildElement("H"),2);
	H2O->AddElement(nist->FindOrBuildElement("O"),1);

	C = nist->FindOrBuildElement("C");

	Aerogel = new G4Material('Aerogel', 0.2*g/cm3,3);
	Aerogel->AddMaterial(SiO2, 62.5*perCent);
	Aerogel->AddMaterial(H2O, 37.4*perCent);
	Aerogel->AddElement(C, 0.1*perCent);

	worldMat = nist->FindOrBuildMaterial("G4_AIR");
}

G4VPhysicalVolume *MyDetectorConstruction::Construct(){

	
	

	G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
	G4double rindexAerogel[2] = {1.1,1.1};
	G4double rindexWorld[2] = {1.0,1.0};

	G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
	mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);

	

	Aerogel->SetMaterialPropertiesTable(mptAerogel);


	

	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld,2);
	worldMat->SetMaterialPropertiesTable(mptWorld);

	solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);

	logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	G4VPhysicalVolume *physWorld = new G4PVPlacement(
		0, 
		G4ThreeVector(0,0,0),
		 logicWorld, 
		 "physWorld",
		 0,
		 false,
		 0,
		  true
		  );

	solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);

	logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");
	fScoringVolume = logicRadiator;

	G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0,0,0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);


	solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m,0.001*m);

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");

	for (G4int i=0;i<nRows;i++)
	{
		for (G4int j=0; j<nCols; j++)
		{
			G4VPhysicalVolume *physDetector = new G4PVPlacement(

				0,
				G4ThreeVector(-0.5*m+(i+0.5)*m/nRows, -0.5*m+(j+0.5)*m/nCols, 0.49*m),
				logicDetector,
				 "physDetector",
				  logicWorld,
				   false,
				    j+i*100,
				    true);
				
		}
	}

	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	myDetector *sensitiveDet = new myDetector("SensitiveDecetor");
	logicDetector->SetSensitiveDetector(sensitiveDet);
}