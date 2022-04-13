void test2(){



	TRandom2 *rand = new TRandom2(0);

	TGraphErrors *g = new TGraphErrors();

	TCanvas *c1 = new TCanvas();



	fstream file;

	file.open("data2.txt", ios::out);

	for (int i=0; i<50;i++){
		double x = rand->Rndm()*10;

		double y = x*x;

		double ex = rand->Rndm();

		double ey = rand->Rndm();

		file << x << " " << y << " " << ex << " " << ey << endl;

	}

	file.close();


	file.open("data2.txt", ios::in);

	double x,y,ex,ey;
	int n = 0;


	while (true){
		
		file >> x >> y >> ex >> ey;

		n = g->GetN();
		g->SetPoint(n,x,y);
		g->SetPointError(n,ex,ey);

		if(file.eof()) break;



	}

	file.close();

	TF1 *fit = new TF1("fit", "pol2", 0,10);

	g->Draw();
	g->Fit("fit");
}