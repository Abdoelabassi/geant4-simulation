void extract(){



	TCanvas *c = new TCanvas();

	TFile *input = new TFile("data.root", "read");

	TTree *tre = (TTree*)input->Get("tree");

	TH1F *hist = new TH1F("hist", "x", 50, 0, 15);

	double a,b,ax,by;

    //let's read only two vars
	tre->SetBranchAddress("x", &a);
	tre->SetBranchAddress("y", &b);


	int entries = tre->GetEntries();

	cout << entries << endl;

	for (int i=0; i < entries; i++){

		tre->GetEntry(i);

		cout << a  << " " << b << endl;

		hist->Fill(a);

	}

	hist->Draw();


	//input->Close();
}