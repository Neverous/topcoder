#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;

// BEGIN CUT HERE
/* Często użyteczne rzeczy... */
// END CUT HERE

class RecursiveFigures 
{
	public:
		double getArea(int sideLength, int K)
		{
			double s = sideLength;
			double result = (double) s * s * M_PI / 4;
			for(int k = 1; k < K; ++ k)
			{
				s /= sqrt(2);
				result -= s * s;
				result += s * s * M_PI / 4;
			}

			return result;
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; double Arg2 = 78.53981633974483; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; double Arg2 = 67.80972450961724; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; double Arg2 = 62.444678594553444; verify_case(2, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	RecursiveFigures ___test;
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
