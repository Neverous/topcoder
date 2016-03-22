#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
// BEGIN CUT HERE
#include<utility>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<sstream>
#include<stack>
#define MIN(a, b) ((a) < (b)?(a):(b))
#define MAX(a, b) ((a) > (b)?(a):(b))
#define ABS(a) ((a) > 0?(a):-(a))
// END CUT HERE
using namespace std;

class TheLuckyNumbersLevelOne 
{
	public:
		long long find(long long a, long long b);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 45LL; long long Arg1 = 54LL; long long Arg2 = 0LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 477444774LL; long long Arg1 = 477444774LL; long long Arg2 = 1LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 24LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

long long makeNumber(long long half, bool pair = false)
{
	long long result = half;
	if(pair)
		half /= 10;

	while(half)
	{
		result = result * 10 + half % 10;
		half /= 10;
	}

	return result;
}

long long TheLuckyNumbersLevelOne::find(long long a, long long b)
{
	queue<long long> que;
	long long count = 0,
		 act,
		 num1,
		 num2;
	que.push(4);
	que.push(7);

	while(!que.empty())
	{
		act = que.front();
		num1 = makeNumber(act);
		num2 = makeNumber(act, true);
		que.pop();
		if(num1 >= a && num1 <= b)
			++ count;

		if(num2 >= a && num2 <= b)
			++ count;

		if(makeNumber(act * 10 + 4, true) <= b)
			que.push(act * 10 + 4);

		if(makeNumber(act * 10 + 7, true) <= b)
			que.push(act * 10 + 7);
	}

	return count;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TheLuckyNumbersLevelOne ___test;
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
