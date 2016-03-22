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
#define MIN(a, b) ((a) < (b)?(a):(b))
#define CHECK(a) ((a)%4 == 0 || (a)%7 == 0)

class TheSequencesLevelOne 
{
	public:
		vector <int> find(vector <int> sequence)
		{
			vector<int> result;
			for(unsigned int s = 0; s < sequence.size(); ++ s)
				for(int i = 0; i < 10; ++ i)
				{
					if(CHECK(sequence[s] - i))
					{
						result.push_back(sequence[s] - i);
						break;
					}

					if(CHECK(sequence[s] + i))
					{
						result.push_back(sequence[s] + i);
						break;
					}
				}



			return result;
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 4, 4, 4, 7, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {1000000000, 999999995}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 999999994 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 7, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 7, 7, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {44, 47, 77, 74, 474, 444, 747, 7777777}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {44, 48, 77, 72, 472, 444, 748, 7777777 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TheSequencesLevelOne ___test;
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
