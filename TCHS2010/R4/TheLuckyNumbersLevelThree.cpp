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

class TheLuckyNumbersLevelThree 
{
	public:
		vector<long long> find(long long a, long long b);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long Arr2[] = {0, 0, 0, 0, 1, 0, 0, 1, 1, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 78LL; long long Arg1 = 79LL; long Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 47LL; long Arr2[] = {2, 4, 7, 3, 7, 1, 2, 1, 2, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1000000000LL; long Arr2[] = {4, 2, 7, 4, 9, 3, 7, 5, 7, 2 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

long long makeItBigger(long long number)
{
	if((4 - number % 4) < (7 - number % 7))
		return number + 4 - number % 4;

	return number + 7 - number % 7;
}

void countStuff(vector<long long> &result, long long number)
{
	while(number)
	{
		++ result[number % 10];
		number /= 10;
	}

	return;
}

vector<long long> TheLuckyNumbersLevelThree::find(long long a, long long b)
{
	vector<long long> result(10);
	for(long long t = (a%4 && a%7)?makeItBigger(a):a; t <= b; t = makeItBigger(t))
		countStuff(result, t);

	return result;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TheLuckyNumbersLevelThree ___test;
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
