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

class AppleWord 
{
	public:
		int minRep(string word)
		{
			int w = 0,
				changes = 0;
			for(w = 0; word[w]; ++ w);

			if(w < 5)
				return -1;

			if(word[0] != 'a' && word[0] != 'A')
				++ changes;

			if(word[w - 1] != 'E' && word[w - 1] != 'e')
				++ changes;

			if(word[w - 2] != 'l' && word[w - 2] != 'L')
				++ changes;

			for(int W = 1; W < w - 2; ++ W)
				if(word[W] != 'p' && word[W] != 'P')
					++ changes;

			return changes;
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Apple"; int Arg1 = 0; verify_case(0, Arg1, minRep(Arg0)); }
	void test_case_1() { string Arg0 = "apPpPPlE"; int Arg1 = 0; verify_case(1, Arg1, minRep(Arg0)); }
	void test_case_2() { string Arg0 = "APLE"; int Arg1 = -1; verify_case(2, Arg1, minRep(Arg0)); }
	void test_case_3() { string Arg0 = "TopCoder"; int Arg1 = 7; verify_case(3, Arg1, minRep(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	AppleWord ___test;
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
