#include<hanning.h>
#include<meta.h>
#define pi 3.1415926
using namespace std;
using namespace arma;

mat hanning(int wlen) {
	mat* p = meta(wlen / 2);
	mat* w = new mat(2, wlen / 2);

	for (int i = 1; i <= wlen / 2; i++) {
		double t = 0.5*(1 - cos(2 * pi*p->at(1, i) / (wlen + 1)));
		w->at(1, i) = t;
		w->at(2, wlen / 2 - i + 1) = t;
	}
	for (int j = 1; j <= 2; j++)
		for (int i = 1; i <= wlen / 2; i++)
			cout << w->at(j, i) << endl;

	return *w;
}