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

class TournamentWinner 
{
	public:
		vector <double> winningProbabilities(vector <int> P);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {5,   0,  10,  15,  20,  25,  30,
      0,  35,  40,  45,  50,  55,
         100, 100, 100, 100, 100,
               60,  65,  70,  75,
                    80,  85,  90,
                         95,  50,
                              50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, winningProbabilities(Arg0)); }
	void test_case_1() { int Arr0[] = {100,  25,   0,  25,  25,  25,  25,
       25,  25,  25,  25,  25,  25,
             0,  25,  25,  25,  25,
                 50,  25,  25,  25,
                     100,  25, 100,
                           25,  25,
                                 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, winningProbabilities(Arg0)); }
	void test_case_2() { int Arr0[] = {50,  50,  50,  50,  50,  50,  50,
      50,  50,  50,  50,  50,  50,
           50,  50,  50,  50,  50,
                50,  50,  50,  50,
                     50,  50,  50,
                          50,  50,
                               50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, winningProbabilities(Arg0)); }
	void test_case_3() { int Arr0[] = {100, 50,  50,  50,  50,  50,  50,
       0,  50,  50,  50,  50,  50,
          100,  50,  50,  50,  50,
                 0,  50,  50,  50,
                    100,  50,  50,
                           0,  50,
                              100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.25, 0.0, 0.25, 0.0, 0.25, 0.0, 0.25, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, winningProbabilities(Arg0)); }
	void test_case_4() { int Arr0[] = { 50, 50,  50,  50,  50,  50,  50,
      50,  50,  50,  50,  50,  50,
           50,  50,  50,  50,  50,
                50,  50,  50,  50,
                    100, 100, 100,
                          10,  20,
                               30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.125, 0.125, 0.125, 0.125, 0.5, 0.0, 0.0, 0.0 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, winningProbabilities(Arg0)); }
	void test_case_5() { int Arr0[] = {  1,  2,   4,   7,  11,  16,  22,
       3,   5,   8,  12,  17,  23,
            6,   9,  13,  18,  24,
                10,  14,  19,  25,
                     15,  20,  26,
                          21,  27,
                               28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {6.88919608E-5, 0.009061234459199999, 0.011498979459599998, 0.1853675541204, 0.0328889066112, 0.18542493028680002, 0.17985791390280004, 0.3958315891991999 }; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, winningProbabilities(Arg0)); }

// END CUT HERE

};

vector <double> TournamentWinner::winningProbabilities(vector <int> P)
{
	{{ WRITE }}
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TournamentWinner ___test;
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
