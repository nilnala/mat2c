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
#include<meta.h>
#include<hanning.h>
#include<enframe.h>
#define pi 3.1415926
using namespace std;
using namespace arma;

/*
mat tranverse(mat x, int win, int inc);
void audioread(string dest, mat x, int* Fs);//input dest,output x & Fs
mat fft(mat);
void spectrogram(mat x,int w,int o,int n,int fs,string lab);


int mean(mat x) {
	int s = 0;
	for (int i = 0; i < x.n_cols; i++) {
		for (int j = 0; j < x.n_rows; j++) {
			s += x(i, j);
		}
	}
	return s / x.n_cols / x.n_rows;
}




void zero_cross(mat xx, mat fs) {
	//xx=xx-mean(xx)
	int mean_xx = mean(xx);
	for (int i = 0; i < xx.n_cols; i++) {
		for (int j = 0; j < xx.n_rows; j++) {
			xx(i, j) -= mean_xx;
		}
	}

	int wlen = 200;
	int inc = 80;

	int win;
	//win = hanning(wlen);

	//int N = length(xx);

	mat X;
	mat afterTran = tranverse(xx,win,inc);
	X = enframe(afterTran);
	int fn = xx.n_cols;
	for (int i = 0; i < fn; i++) {
		zcr1(0, i) = 0;
	}

	for (int i = 1; i <= fn; i++) {
		for (int j = 1; j < wlen; j++) {
			if(X(i,j)*X(i,j+1)<0)
				zcr1(0,i) = zcr1(0,i) + 1;
		}
	}

	//somtting wrong with this
	//mat time = N / fs;
	//mat frameTime = (((1:fn) - 1)*inc + wlen / 2) / fs;

}


void pr241(string dest) {
	string fle = dest;
	mat x;
	int Fs;
	audioread(dest, x, &Fs);
	int wlen = 300, inc = 80;
	WIN win = hanning(wlen);
	int N = x.n_elem;
	int time = (N - 1) / Fs;
	mat y = enframe(x, win, inc);//'
	int fn = y.n_cols;


};
								  
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
}

/*
计算短时帧能量，即energy.m转.c
*/
/*void energy(mat x, double Fs)
{
	int wlen = 200;
	int inc = 80;			//给出帧长和帧移
	mat win = hanning(wlen);	//给出海宁窗
	int N = x.n_elem;		//信号长度
	mat X = enframe(x, win, inc).t();	//分帧
	int fn = X.n_cols;		//求出帧数
	mat time(1,N);
	for (int i = 1; i <= N; i++)
	{
		time(i - 1) = (i - 1) / Fs;
	}
	//需要计算X的行数和列数来每次取出一行
	int len;
	int nx = x.n_elem;	//取数据长度
	int nwin = win.n_elem;	//取窗长
	if (1 == nwin)	//判断窗长是否为1，若为1，即表示没有设窗函数
	{
		len = win(0);	//是，帧长=win
	}
	else
	{
		len = nwin;		//否，帧长=窗长
	}
	int nf = floor((nx - len + inc) / inc);	//计算帧数
	int j = 1;

	mat En(1, fn);			//对一帧累加求和
	for (int t = 1; t <= fn; t++)
	{
		mat u(len, 1);			//取出一帧
		for (int k = 0; k < nf; k++)
		{
			for (int i = 1; j < j + len, i < len + 1; j++, i++) {

				u(i - 1) = X(j - 1);
			}
		}
		mat u2 = u % u;		//求出能量
		En(t - 1) = accu(u2);
		
	}

	mat frameTime = frame2time(fn, wlen, inc, Fs);   // 求出每帧对应的时间
}
/*
分帧后计算每帧时间，即frame2time.m转.c
*/
/*mat frame2time(int frameNum,int frameLen,int inc,double fs)
{
	mat frametime(1,frameNum);
	for (int i = 1; i <= frameNum; i++)
	{
	
		frametime(i-1)=((i - 1)*inc + frameLen/2)/fs;	//分帧后每帧对应的时间
	}
	return frametime;

}
*/


int main() {
	hanning(200);
  /*
	将pr_2_4_1.m转为.c
	N=length(x); time=(0:N-1)/Fs;       % 计算时间
	y=enframe(x,win,inc)';              % 分帧
	fn=size(y,2);                       % 帧数
	frameTime=(((1:fn)-1)*inc+wlen/2)/Fs; % 计算每帧对应的时间
	W2=wlen/2+1; n2=1:W2;
	freq=(n2-1)*Fs/wlen;                % 计算FFT后的频率刻度
	Y=fft(y);                           % 短时傅里叶变换
	*/
	/*string file = "C:\\Users\\Wimdows\\Desktop\\MATLAB任务\\声谱图，能量函数，过零率\\bluesky3.wav";
	mat x;
	int Fs;
	audioread(file, x, Fs);		//读入数据文件
	int wlen = 300;
	int inc = 80;
	mat win = hanning(wlen);	//设置帧长，帧移和窗函数
	int N = x.n_elem;
	mat time(1, N);				//计算时间
	for (int i = 1; i <= N; i++)
	{
		time(i - 1) = (i - 1) / Fs;
	}
	mat y = enframe(x, win, inc).t();//分帧
	int fn = y.n_cols;				//帧数
	mat frameTime = frame2time(fn, wlen, inc, Fs);//计算每帧对应的时间
	int W2 = wlen / 2 + 1;
	mat n2(1, W2);
	for (int i = 1; i <= W2; i++)
	{
		n2(i - 1) = i;
	}
	mat freq(1, W2);		//计算FFT后的频率刻度
	for (int i = 1; i <= W2; i++)
	{
		freq(i - 1) = (n2(i - 1) - 1)*Fs / wlen;
	}
	cx_mat Y = fft(y);				// 短时傅里叶变换
	*/


	int T;
	cin >> T;
	return 0;
}