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


	}




