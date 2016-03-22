#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstring>
#define MIN(a, b) ((a) < (b)?(a):(b))
#define ABS(a) ((a) > 0?(a):-(a))
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

class DistanceOnCube 
{
	public:
		int calculate(int S, int x1, int y1, int z1, int x2, int y2, int z2);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 3; int Arg5 = 3; int Arg6 = 0; int Arg7 = 2; verify_case(0, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 2; int Arg3 = 0; int Arg4 = 4; int Arg5 = 3; int Arg6 = 2; int Arg7 = 4; verify_case(1, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 1; int Arg5 = 1; int Arg6 = 4; int Arg7 = 6; verify_case(2, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; int Arg3 = 0; int Arg4 = 2; int Arg5 = 3; int Arg6 = 0; int Arg7 = 0; verify_case(3, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 87; int Arg1 = 87; int Arg2 = 10; int Arg3 = 3; int Arg4 = 44; int Arg5 = 11; int Arg6 = 0; int Arg7 = 47; verify_case(4, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 49; int Arg1 = 0; int Arg2 = 13; int Arg3 = 43; int Arg4 = 49; int Arg5 = 10; int Arg6 = 45; int Arg7 = 62; verify_case(5, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_6() { int Arg0 = 48; int Arg1 = 13; int Arg2 = 0; int Arg3 = 5; int Arg4 = 8; int Arg5 = 48; int Arg6 = 1; int Arg7 = 59; verify_case(6, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_7() { int Arg0 = 77; int Arg1 = 17; int Arg2 = 20; int Arg3 = 77; int Arg4 = 2; int Arg5 = 35; int Arg6 = 0; int Arg7 = 111; verify_case(7, Arg7, calculate(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

int DistanceOnCube::calculate(int S, int x1, int y1, int z1, int x2, int y2, int z2)
{
	if((x1 == S && x2 == 0) || (x1 == 0 && x2 == S))
		return S + MIN(MIN(ABS(S - y1) + ABS(S - y2), y1 + y2) + ABS(z1 - z2), MIN(ABS(S - z1) + ABS(S - z2), z1 + z2) + ABS(y1 - y2));

	else if((y1 == S && y2 == 0) || (y1 == 0 && y2 == S))
		return S + MIN(MIN(ABS(S - x1) + ABS(S - x2), x1 + x2) + ABS(z1 - z2), MIN(ABS(S - z1) + ABS(S - z2), z1 + z2) + ABS(x1 - x2));

	else if((z1 == S && z2 == 0) || (z1 == 0 && z2 == S))
		return S + MIN(MIN(ABS(S - y1) + ABS(S - y2), y1 + y2) + ABS(x1 - x2), MIN(ABS(S - x1) + ABS(S - x2), x1 + x2) + ABS(y1 - y2));

	else
		return ABS(x1 - x2) + ABS(y1 - y2) + ABS(z1 - z2);
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	DistanceOnCube ___test;
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
