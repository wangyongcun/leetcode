
double myPow(double x, int n) {
	if (n==0){
		return 1;
	}

	if (n== 1){
		return x;
	}

	long long on = n;
	if (on < 0){
		on = -n;
	}

	double r = 1;

	double t = myPow(x, on / 2);
	if (on % 2 == 1) {
		r = t * t * x;
	}
	else {
		r = t * t;
	}

	if (n<0){
		return 1.0 / r;
	}
	else {
		return r;
	}
}


void test_lcof16() {
	double t = myPow(8.95371, -1);
	t = myPow(2, 4);
	t = myPow(2, 5);
	t = myPow(2, 6);
	t = myPow(2, 8);
}