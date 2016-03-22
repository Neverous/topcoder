#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
// BEGIN CUT HERE
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
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
// END CUT HERE
using namespace std;

class TheOlympiadInInformatics //{{
{
	public:
		int find(vector <int> sums, int k);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7, 0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 7; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {999999999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {95, 23, 87, 23, 82, 78, 59, 44, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; int Arg2 = 6; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
}; //}}

inline bool check(vector<int> data, int got, int p)
{
    int better = 0;
    for(unsigned int d = 0; better <= p && d < data.size(); ++ d)
        better += data[d] / got;

    return better <= p;
}

int TheOlympiadInInformatics::find(vector <int> sums, int k)
{
    int start = 0,
        end = 1000000000,
        mid;

    while(start != end)
    {
        mid = (start + end) / 2;
        if(check(sums, mid + 1, k))
            end = mid;

        else
            start = mid + 1;
    }

    return end;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[]){TheOlympiadInInformatics ___test;int x = argc == 1 ? 0 : atoi(argv[1]);___test.run_test(x);if (x==100 || argc == 2)return 0;x++;char txt[30]; sprintf(txt, "%d", x); execlp(argv[0], argv[0], txt, txt, NULL);}
// END CUT HERE
