#include<iostream>
#include"G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"


#include "construction.hh"
#include "physics.hh"
#include "action.hh"

int main(int argc, char** argv){

	G4RunManager *runManager = new G4RunManager();
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(new myphysicsList());
	runManager->SetUserInitialization(new myActionInit());
	runManager->Initialize();

	G4UIExecutive *ui = new G4UIExecutive(argc, argv);

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();


	G4UImanager *uiManager =  G4UImanager::GetUIpointer();
	uiManager->ApplyCommand("/vis/open OGL");
	uiManager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
	uiManager->ApplyCommand("/vis/drawVolume");
	uiManager->ApplyCommand("/vis/viewer/set/autorefresh true");
	uiManager->ApplyCommand("/vis/scene/add/trajectories smooth");
	uiManager->ApplyCommand("/vis/scene/endOfEventAction accumulate");


	ui->SessionStart();



















	return 0;
}