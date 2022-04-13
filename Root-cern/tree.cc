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


	TCanvas *c = new TCanvas();

	TFile *input = new TFile("data.root", "read");

	TTree *tre = (TTree*)input->Get("tree");

	double a,b,ax,by;

    //let's read only two vars
	tre->SetBranchAddress("x", &a);
	tre->SetBranchAddress("y", &b);


	int entries = tre->GetEntries();

	cout << entries << endl;

	for (int i=0; i < entries; i++){

		tre->GetEntry(i);

		cout << a  << " " << b << endl;

	}


	input->Close();


}