/* fft.c -- straightforward recursive FFT implementation
 *
 * Look for the link http://www.engineeringproductivitytools.com/stuff/T0001/PT03.HTM
 * for details about the implementation
 *
 * Written by Jarkko Vuori 2013
 */

#include <complex>
#include <numeric>
#include <iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<time.h>
#include<thread>
using namespace std;
using namespace std::chrono;

typedef complex<double> cx;
// radix-2 in-place FFT, n must be 2^k (e.g. 2,4,6,...)
void fft(int n, cx x[]) {
	const cx J(0, 1);
	const double PI = 3.14159265359;
	// check the trivial case
	if (n == 1)
		return;

	// perform two sub-transforms
	int n2 = n/2; // size of sub-transform
	cx *xe = new cx[n2];
	cx *xo = new cx[n2];
	for (int i = 0; i < n2; i++) { // perform n/2 DIF 'butterflies'
		xe[i] = x[i] + x[i+n2];	                     // even subset
		xo[i] = (x[i] - x[i+n2])*exp(-J*(2*PI*i/n)); // odd subset
	}
	fft(n2, xe);
	fft(n2, xo);

	// construct the result vector
	for (int k = 0; k < n2; k++) {
		x[2*k]   = xe[k]; // even k
		x[2*k+1] = xo[k]; // odd k
	}

	delete[] xe;
	delete[] xo;
}
double mean;
vector<double> varianceTimeContainer;
void varianceIntoContainer(double x){
	double num = pow((x - mean), 2);
	varianceTimeContainer.push_back(num);

}

int main() {
	
	int sum;
	
	vector<double>time_Measurements;
	
	for (int k = 0; k < 20; k++){
	
		time_point<high_resolution_clock>t1 = high_resolution_clock::now();
		cx *xc = new cx[16384];
		fft(16384, xc);
		
		time_point<high_resolution_clock> t2 = high_resolution_clock::now();
		
		auto c1 = duration_cast< milliseconds>(t2 - t1).count();
	
		double dm = (double)c1;
		
		time_Measurements.push_back(dm);
		
	}
	sum = accumulate(time_Measurements.begin(), time_Measurements.end(), 0);
	mean = (double)sum / (time_Measurements.size());
	for_each(time_Measurements.begin(), time_Measurements.end(), varianceIntoContainer);
	double varianceSum = accumulate(varianceTimeContainer.begin(), varianceTimeContainer.end(), 0);
	double variance = (double)varianceSum / varianceTimeContainer.size();
	cout << "mean is ";
	cout << mean << endl;
	cout << "standard deviation is ";
	cout << sqrt(variance) << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
valid output:
(28,-28)
(5.65685,13.6569)
(4.13891e-013,8)
(-2.34315,5.65685)
(-4,4)
(-5.65685,2.34315)
(-8,4.13447e-013)
(-13.6569,-5.65685)
Press any key to continue . . .*/
