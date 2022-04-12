#include "detector.hh"



myDetector::myDetector(G4String name): G4VSensitiveDetector(name)
{

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

		//G4cout << "position of the photons :" << posPhoton << G4endl;

		const G4VTouchable *touch = aStep->GetPreStepPoint()->GetTouchable();
		G4int copyNo = touch->GetCopyNumber();

		//G4cout << "copy number :" << copyNo << G4endl;
		G4VPhysicalVolume *phyvol = touch->GetVolume();
		G4ThreeVector posDetector = phyvol->GetTranslation();

		G4cout << "Detector position :" << posDetector << G4endl;
		
		G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

		G4AnalysisManager *man = G4AnalysisManager::Instance();

		man->FillNtupleIColumn(0,evt);
		man->FillNtupleDColumn(1, posDetector[0]);
		man->FillNtupleDColumn(2, posDetector[1]);
		man->FillNtupleDColumn(3,posDetector[2]);
		man->AddNtupleRow(0);


	}




