#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define double long double
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;
typedef complex<int> point;
typedef complex<double> fpoint;
#define X real()
#define Y imag()
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}
ostream& operator<<(ostream &output, const pii &pii) {
  cout << '(' << pii.first << "," << pii.second << ')';
  return output;
}
const double PI = 3.141592653589793238460;

void fft(valarray<complex<double>> &x)
{
	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
  complex<double> phiT = complex<double>(cos(thetaT), -sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				complex<double> t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{
			complex<double> t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
	}
}

void ifft(valarray<complex<double>> &A) {
  // coefficients = 1/n * fft(values) with w^-1

  // 1/i == -i
  A = A.apply(conj);
  fft(A);
  A = A.apply(conj);
  A /= A.size();

}

#undef int
int main()
#define int long long
{

cin.tie(0);
cout.tie(0);
ios::sync_with_stdio(0);

string str1, str2;
getline(cin, str1);
getline(cin, str2);
int n = max(str1.length(), str2.length());
int p = 1 << (lg((2*n+1)-1)+1);
valarray<complex<double>> n1(p), n2(p);
for (uint i = 0; i < str1.length(); ++i) n1[str1.length()-1-i] = str1[i]-'0';
for (uint i = 0; i < str2.length(); ++i) n2[str1.length()-1-i] = str2[i]-'0';
fft(n1); fft(n2);
valarray<complex<double>> n3(p);
for (uint i = 0; i < min(n1.size(), n2.size()); ++i) n3[i] = n1[i] * n2[i];
ifft(n3);
vector<complex<double>> ans;
vector<int> num;
for (uint i = 0; i < n3.size(); ++i) num.push_back(round(n3[i].X));
for (uint i = 0; i < num.size(); ++i)
  if (num[i] > 9) num[i+1] += num[i] / 10, num[i] %= 10;
while (num.size() > 1 && num.back() == 0) num.pop_back();
copy(num.rbegin(), num.rend(), ostream_iterator<int>(cout, ""));
}
