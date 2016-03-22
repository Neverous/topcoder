#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstring>
// BEGIN CUT HERE
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
#define MIN(a, b) ((a) < (b)?(a):(b))
#define MAX(a, b) ((a) > (b)?(a):(b))
#define ABS(a) ((a) > 0?(a):-(a))
// END CUT HERE
using namespace std;

class FlatCatsBreeding 
{
	public:
		int days(int D, int K, int T);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; int Arg3 = 0; verify_case(0, Arg3, days(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 4; int Arg3 = 4; verify_case(1, Arg3, days(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 9; int Arg3 = 8; verify_case(2, Arg3, days(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1000000; int Arg3 = 40; verify_case(3, Arg3, days(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 91; int Arg1 = 6; int Arg2 = 10433; int Arg3 = 455; verify_case(4, Arg3, days(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 9; int Arg1 = 7; int Arg2 = 17079; int Arg3 = 45; verify_case(5, Arg3, days(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

int FlatCatsBreeding::days(int D, int K, int T)
{
	int R = 0,
		C = 1;

	while(T > C)
	{
		R += D;
		C += C * K;
	}

	return R;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	FlatCatsBreeding ___test;
	int x = argc == 1 ? 0 : atoi(argv[1]);
	___test.run_test(x);
	if (x==100 || argc == 2)
		return 0;
	x++;
	char
		txt[30];
	sprintf(txt, "%d", x);
	execlp(argv[0], argv[0], txt, txt, NULL);
}
// END CUT HERE
