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
#include<enframe.h>
#define pi 3.1415926
using namespace std;
using namespace arma;

mat enframe(mat x, mat win, int inc) {
	int len;
	int nwin = win.n_elem;
	if (nwin == 1) {
		len = win(0);
	}
	else {
		len = nwin;
	}

	if (inc == -1) {
		inc = len;
	}
	cout << "x.elem:" << x.n_elem << endl << "inc:" << inc << endl;
	int nf = floor((x.n_elem - len + inc) / inc);
	cout << "nf:" << nf << endl << "len:" << len << endl;

	mat frameout(1, nf*len + 1);
	mat a(nf, 1);
	for (int i = 0; i < nf; i++) {
		a(i) = i;
	}
	mat indf = inc*a;
	mat inds(1, len);
	for (int i = 1; i <= len; i++) {
		inds(i - 1) = i;
	}

	int k = 0;
	inds = repmat(inds, nf, 1);
	indf = repmat(indf, 1, len);
	a = inds + indf;
	for (int i = 0; i < a.n_elem; i++) {
		frameout(k++) = x(a(i) - 1);
	}
	frameout.reshape(nf, len);

	if (nwin > 1) {
		a = win.t();
		frameout = frameout%repmat(a, nf, 1);
	}
	return frameout;
}

