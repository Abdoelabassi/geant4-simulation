#include "run.hh"

Run::Run()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->CreateNtuple("Hits", "hits");
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->FinishNtuple(0);

}

Run::~Run(){}


void Run::BeginOfRunAction(const G4Run* run){

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	G4int runID = run->GetRunID();

	std::stringstream strRunID;

	strRunID << runID;

	man->OpenFile("output"+strRunID.str()+".root");

	

}

void Run::EndOfRunAction(const G4Run*){

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->Write();
	man->CloseFile();

}