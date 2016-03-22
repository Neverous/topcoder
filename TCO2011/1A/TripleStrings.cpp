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

class TripleStrings 
{
	public:
		int getMinimumOperations(string init, string goal);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ooxxox"; string Arg1 = "xoxoxo"; int Arg2 = 6; verify_case(0, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oooxxoo"; string Arg1 = "oooxxoo"; int Arg2 = 0; verify_case(1, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ox"; string Arg1 = "xo"; int Arg2 = 2; verify_case(2, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ooxxooxx"; string Arg1 = "xxoxoxoo"; int Arg2 = 12; verify_case(3, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "oxxoxxoooxooooxxxoo"; string Arg1 = "oxooooxxxooooxoxxxo"; int Arg2 = 16; verify_case(4, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "xxxoxoxxooxooxoxooo"; string Arg1 = "oxxooxxooxxoxoxooxo"; int Arg2 = 36; verify_case(5, Arg2, getMinimumOperations(Arg0, Arg1)); }

// END CUT HERE

};

int TripleStrings::getMinimumOperations(string init, string goal)
{
	int overlay = 0;
	for(overlay = init.size(); overlay > 0; -- overlay)
	{
		if(init.substr(init.size() - overlay, overlay) == goal.substr(0, overlay))
			break;
	}

	return 2 * (init.size() - overlay);
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TripleStrings ___test;
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
