#include "detector.hh"



myDetector::myDetector(G4String name): G4VSensitiveDetector(name)
{
	QE = new G4PhysicsOrderedFreeVector();

	std::ifstream datafile;

	datafile.open("Qeff.dat");

	while(true){

		G4double wlen, Qeff;

		datafile >> wlen >> Qeff;

		if(datafile.eof()) break;


		//G4cout << wlen << " " << Qeff << G4endl;

		QE->InsertValues(wlen, Qeff);
	}

	datafile.close();

	QE->SetSpline(false);

}

myDetector::~myDetector()
{

}

G4bool myDetector::ProcessHits(G4Step *aStep, G4TouchableHistory
	*ROhist)
	{
		G4Track *track = aStep->GetTrack();
		//track->SetTrackStatus(fStopAndKill);

		G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
		G4StepPoint *postStepPoint = aStep->GetPostStepPoint();


		G4ThreeVector posPhoton = preStepPoint->GetPosition();
		G4ThreeVector momPhoton = preStepPoint->GetMomentum();

		G4double wlen = (1.239841939*eV/momPhoton.mag())*1E+03;

		//G4cout << "position of the photons :" << posPhoton << G4endl;

		const G4VTouchable *touch = aStep->GetPreStepPoint()->GetTouchable();
		G4int copyNo = touch->GetCopyNumber();

		//G4cout << "copy number :" << copyNo << G4endl;
		G4VPhysicalVolume *phyvol = touch->GetVolume();
		G4ThreeVector posDetector = phyvol->GetTranslation();

		//G4cout << "Detector position :" << posDetector << G4endl;
		
		G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

		G4AnalysisManager *man = G4AnalysisManager::Instance();

		man->FillNtupleIColumn(0,0,evt);
		man->FillNtupleDColumn(0,1, posPhoton[0]);
		man->FillNtupleDColumn(0,2, posPhoton[1]);
		man->FillNtupleDColumn(0,3,posPhoton[2]);
		man->FillNtupleDColumn(0,4,wlen);
		man->AddNtupleRow(0);

		if(G4UniformRand() < QE->Value(wlen)){

		man->FillNtupleIColumn(1,0,evt);
		man->FillNtupleDColumn(1,1, posDetector[0]);
		man->FillNtupleDColumn(1,2, posDetector[1]);
		man->FillNtupleDColumn(1,3,posDetector[2]);
		man->AddNtupleRow(1);
	}


	}




