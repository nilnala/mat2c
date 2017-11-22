#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<armadillo>
#include<math.h>
#include<meta.h>
#define pi 3.1415926
using namespace std;
using namespace arma;

mat* meta(int n) {
	mat* x = new mat(1, n);
	for (int i = 1; i <= n; i++) {
		x->at(1, i) = i;
	}
	return x;
}