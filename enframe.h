#pragma once
#ifndef ENFRAME
#define ENFRAME
#include<iostream>
#include<armadillo>
#define pi 3.1415926
using namespace std;
using namespace arma;

mat enframe(mat x, mat win, int inc);



#endif