#include "run.hh"

Run::Run()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();


	man->CreateNtuple("photons", "photons");
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->CreateNtupleDColumn("fWlen");
	man->FinishNtuple(0);


	man->CreateNtuple("Hits", "hits");
	man->CreateNtupleIColumn("fEvent");
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ");
	man->FinishNtuple(1);

	man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("fEdep");
    man->FinishNtuple(2);

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