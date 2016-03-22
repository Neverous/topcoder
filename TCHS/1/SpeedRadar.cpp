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

class SpeedRadar 
{
	public:
		double averageSpeed(int minLimit, int maxLimit, vector <int> readings);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {45, 40, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 45.0; verify_case(0, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {42,43,44,45,46,47,48,49,50,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 46.0; verify_case(1, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 50; int Arr2[] = {42,46,48,50,52}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(2, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 60; int Arr2[] = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 41.68421052631579; verify_case(3, Arg3, averageSpeed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

double SpeedRadar::averageSpeed(int minLimit, int maxLimit, vector <int> readings)
{
	int bad = 0,
		sum = 0;
	for(int r = 0; r < readings.size(); ++ r)
		if(readings[r] > maxLimit || readings[r] < minLimit)
			++ bad;
		
		else
			sum += readings[r];

	if(bad * 10 > readings.size())
		return 0.0;

	return (double)sum / (readings.size() - bad);
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	SpeedRadar ___test;
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
