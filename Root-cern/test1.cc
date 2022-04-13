void test1()
{
	//simple 1d histogram

	TH1F *hist = new TH1F("hist", "Hitogram", 100, 0, 10);


	hist->GetXaxis()->SetTitle("distro");
	hist->GetYaxis()->SetTitle("entries");

	//Random vars:
	//write the data to a file:

	TRandom2 *rand = new TRandom2();

	fstream file;
	file.open("data.txt", ios::out);


	for (int i = 0; i< 1000; i++){

		double r = rand->Gaus(5,1);
		file << r << endl;
		//hist->Fill(r);
	}

	file.close();

	

	

	//TGraph:

	//double x[5] = {1,2,3,4,5};
	//double y[5] = {1,0.69,1.09,1.38,1.60};

	//TGraph *g = new TGraph();
	//g->SetMarkerStyle(2);
	//g->SetMarkerSize(2);
	//g->SetLineWidth(2);
	//g->SetLineColor(kRed);

	//g->GetXaxis()->SetTitle("a values");
	//g->GetYaxis()->SetTitle("b values");


	

	//fill histogram with random data:
	file.open("data.txt", ios::in);

	//double value;

	while (true){

		double a;

		file >> a ;
		hist->Fill(a);
		//g->SetPoint(g->GetN(), a, b);
		if(file.eof()) break;
	}

	file.close();

	//TCanvas *c1 = new TCanvas();
	//g->Draw("ACP");

	TCanvas *c = new TCanvas();
	//hist->GetYaxis()->SetRangeUser(0,200);
	hist->Fit("gaus");
	hist->Draw();


	delete rand;

}