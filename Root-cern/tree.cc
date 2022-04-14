void tree(){




	TFile *output = new TFile("data.root", "RECREATE");

	fstream file;

	file.open("data2.txt", ios::in);

	double x,y,ex,ey;


	TTree *tree = new TTree("tree", "hits");

	tree->Branch("x", &x, "x/D");
	tree->Branch("y", &y, "y/D");
	tree->Branch("ex", &ex, "ex/D");
	tree->Branch("ey", &ey, "ey/D");


	while (true){

		file >> x >> y >> ex >>ey;
		if(file.eof()) break;

		tree->Fill();
	}


	output->Write();
	output->Close();

	file.close();


	//Read into the tree:




}