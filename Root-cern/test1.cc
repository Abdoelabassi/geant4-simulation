void test1()
{
	//simple 1d histogram

	TH1F *hist = new TH1F("hist", "k+ mass", 100, 0, 15);


	
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


	hist->GetXaxis()->SetTitle("Reconstructed mass");
	hist->GetYaxis()->SetTitle("Events");
	hist->GetXaxis()->SetTitleSize(0.05);
	hist->GetYaxis()->SetTitleSize(0.05);
	hist->GetXaxis()->SetLabelSize(0.05);
	hist->GetYaxis()->SetLabelSize(0.05);

	TF1 *fit = new TF1("fit", "gaus", 0, 15);

	fit->SetLineWidth(3);
	fit->SetLineColor(kRed);
	fit->SetLineStyle(1);

	fit->SetParameter(0,40);
	fit->SetParameter(1,5);
	fit->SetParameter(2,1);

	


	TCanvas *c = new TCanvas();
	//hist->GetYaxis()->SetRangeUser(0,200);
	c->SetTickx();
	c->SetTicky();
	hist->SetFillColor(kAzure);
	hist->SetStats(0);
	hist->Fit("fit");
	hist->Draw();

	TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
	leg->AddEntry(hist, "Measured data", "f");
	leg->AddEntry(fit, "fit Fuction", "l");
	leg->Draw();


	TLine *l = new TLine(0,10,15,20);
	l->SetLineWidth(2);
	l->SetLineColor(kOrange);

	double x0 = 6.2;
	int bin = hist->FindBin(x0);
	double y0 = hist->GetBinContent(bin);


	TArrow *arr = new TArrow(10,20,x0,y0);
	arr->SetLineColor(kGreen+2);
	arr->SetArrowSize(0.02);
	arr->SetLineWidth(2);
	arr->Draw();

	TLatex *tex = new TLatex(10,20, "kappa important");
	tex->Draw();

	double mean = fit->GetParameter(1);
	double std = fit->GetParameter(2);


	delete rand;

}