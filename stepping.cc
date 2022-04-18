#include "stepping.hh"

mySteppingAction::mySteppingAction(myEventAction *event){

	fEventAction = event;
}

mySteppingAction::~mySteppingAction(){}

void mySteppingAction::UserSteppingAction(const G4Step *step){

	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

	 const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    
    if(volume != fScoringVolume)
        return;


	G4double edep = step->GetTotalEnergyDeposit();

	fEventAction->AddEdep(edep);
}