#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
// BEGIN CUT HERE
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<utility>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
// END CUT HERE
using namespace std;

class BlurredDartboard //{{
{
	public:
		int minThrows(vector <int> points, int P);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3, 4, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 2; verify_case(0, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 5; verify_case(1, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 7, 8, 1, 3, 2, 6, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 252; verify_case(2, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2012; int Arg2 = 307; verify_case(3, Arg2, minThrows(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 84656087; verify_case(4, Arg2, minThrows(Arg0, Arg1)); }

// END CUT HERE
}; //}}

inline static const int MIN(const int &a, const int &b){return a<b?a:b;}
inline static const int MAX(const int &a, const int &b){return a>b?a:b;}

int BlurredDartboard::minThrows(vector <int> points, int P)
{
	int unknownSum = points.size() * (points.size() + 1) / 2,
	    unknownCount = 0,
	    res = (1<<30),
	    maks = 0,
	    cnt = (1<<30),
	    cnt2 = (1<<30);

	bool onboard[64];
	for(int i = 0; i < 64; ++ i)
		onboard[i] = false;

	for(int p = 0; p < points.size(); ++ p)
		if(points[p])
		{
			unknownSum -= points[p];
			maks = MAX(maks, points[p]);
			onboard[points[p]] = true;
		}

		else
			++ unknownCount;

	if(maks)
		res = (P + maks - 1) / maks;

	if(unknownCount)
	{
		cnt = P / unknownSum;
		P -= cnt * unknownSum;
		cnt *= unknownCount;
		if(maks)
			cnt2 = cnt + (P + maks - 1) / maks;

		for(int p = 1; P > 0 && p <= points.size(); ++ p)
			if(!onboard[p])
			{
				++ cnt;
				P -= p;
			}
	}

	return MIN(res, MIN(cnt, cnt2));
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[]){BlurredDartboard ___test;int x = argc == 1 ? 0 : atoi(argv[1]);___test.run_test(x);if (x==100 || argc == 2)return 0;x++;char txt[30]; sprintf(txt, "%d", x); execlp(argv[0], argv[0], txt, txt, NULL);}
// END CUT HERE
