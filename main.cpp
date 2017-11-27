#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<time.h>
#include<armadillo>
#include<math.h>
#include"meta.h"
#include"hanning.h"
#include"enframe.h"
#include"fft.h"
#include"Complex.h"
#define pi 3.1415926
using namespace std;
using namespace arma;


/*
void zero_cross(mat xx, int fs) {
	int mean_xx = mean(xx);
	for (int i = 0; i < xx.n_cols; i++) {
		for (int j = 0; j < xx.n_rows; j++) {
			xx(i, j) -= mean_xx;
		}
	}

	int wlen = 200;
	int inc = 80;

	mat win = hanning(wlen);

	int N = xx.n_elem;

	mat X = enframe(xx, win, inc);//'
	int fn = xx.n_cols;

	mat zcr1(1,fn);
	for (int i = 1; i <= fn; i++) {
		zcr1(1, i) = 0;
	}

	for (int i = 1; i <= fn; i++) {
		for (int j = 1; j < wlen; j++) {
			if(X(i,j)*X(i,j+1)<0){
				zcr1(0, i) = zcr1(0, i) + 1;
			}
		}
	}

	mat time = meta(N - 1);
	mat frameTime(1,fn);

	for (int i = 1; i <= fn; i++) {
		//frameTime(1,i) = ((i - 1)*inc + wlen / 2) / fs(i);//?
	}

	//draw


}

				  
void energy(string dest) {
	mat x;
	int Fs;
	audioread(dest, x, &Fs);
	int wlen = 200, inc = 80;
	WIN win = hanning(wlen);
	int N = x.n_elem;
	mat X = enframe(x, win, inc);//'
	int fn = X.n_cols;
	mat time;// = (0:N-1)/Fs
	for (int i = 1; i <= N - 1; i++) {
		int u = X(i);
		int u2 = u % u;
		//En(i)=sum(u2);
	}
	//....
}

void create_spectrogram(string dest) {
	mat y;
	int fs;
	audioread(dest, y, &fs);
	int nfft = 1024;
	int w = 512;
	int overlap_new = 256;
	spectrogram(y, w, overlap_new, nfft, fs, "yaxis");
	//¶ÌÊ±fft
}

*/

void audioread(string dest, mat x, int Fs) {

}

int main() {

	/*	string dest;
	cin >> dest;
	mat x;
	int Fs = 0;
	audioread(dest,x,Fs);
	int wlen = 300, inc = 80;
	mat win = hanning(wlen);
	int N = x.n_elem;
	mat time(1,N);
	for (int i = 1; i <= N; i++)
		time(1, i) = i / Fs;
	mat y = enframe(x, win, inc);
	int fn = y.n_cols;
	mat frameTime(1,fn);
	for (int i = 1; i <= fn; i++)
		frameTime(1, i) = ((i - 1)*inc + wlen / 2) / Fs;
	int W2 = wlen / 2 + 1;
	mat n2 = meta(W2);
	mat freq = (n2 - 1)*Fs / wlen;

	*/


	mat m = {1,2,-1,3};

	cout<<FFT(m);



	int T;
	cin >> T;
	return 0;
}