#include "run.hh"

Run::Run()
{

}

Run::~Run(){}


void Run::BeginOfRunAction(const G4Run*){

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->OpenFile('output.root');

	man->CreateNtuple("Hits", "hits");
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->FinishNtuple(0);

}

void Run::EndOfRunAction(const G4Run*){

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->Write();
	man->CloseFile();

}