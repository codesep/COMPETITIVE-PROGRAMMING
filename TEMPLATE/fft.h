void fft(vector<complex<double> > &a, bool inv){
	int n = a.size();

	if(n == 1)
		return;

	vector<complex<double> > a0(n / 2), a1(n / 2);
	for(int i = 0, j = 0; i < n; i += 2, j++){
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}

	fft(a0, inv);
	fft(a1, inv);

	double ang = 2 * M_PI / n * (inv ? -1 : 1);
	complex<double> w(1), wn(cos(ang), sin(ang));

	for(int i = 0; i < n / 2; i++){
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if(inv)
			a[i] /= 2, a[i + n / 2] /= 2;
		w = w * wn;
	}
}

void multiply_poly(vector<int> &a, vector<int> &b, vector<int> &res){
	vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());

	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, 0), fft(fb, 0);

	for(int i = 0; i < n; i++)
		fa[i] = fa[i] * fb[i]; 

	fft(fa, 1);

	res.resize(n);
	for(int i = 0; i < n; i++)
		res[i] = round(fa[i].real());
}