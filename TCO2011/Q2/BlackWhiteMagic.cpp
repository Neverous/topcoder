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

class BlackWhiteMagic 
{
	public:
		int count(string creatures);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WBBW"; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "WWWWBBBB"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "BBWW"; int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "BWWWWWWWBBBBBBBW"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "WBWBWBWBWWBWBWBWBBBWBW"; int Arg1 = 5; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

int BlackWhiteMagic::count(string creatures)
{
	int whites = 0,
		res = 0;
	for(int c = 0; c < creatures.size(); ++ c)
		whites += creatures[c] == 'W';

	for(int c = whites; c < creatures.size(); ++ c)
		res += creatures[c] == 'W';

	return res;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	BlackWhiteMagic ___test;
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
