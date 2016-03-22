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

class HouseBuilding //{{
{
	public:
		int getMinimum(vector <string> area);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "31"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"54454",
 "61551"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"989"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"5781252",
 "2471255",
 "0000291",
 "1212489"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 53; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE
}; //}}

int HouseBuilding::getMinimum(vector <string> area)
{
    int best = 1048576;
    for(int r = 0; r < 10; ++ r)
    {
        int result = 0;
        for(int h = 0; h < area.size(); ++ h)
            for(int w = 0; w < area[h].size(); ++ w)
                result += min(abs(area[h][w] -'0' - r), abs(area[h][w] - '0' - r - 1));

        if(best > result)
            best = result;
    }

    return best;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[]){HouseBuilding ___test;int x = argc == 1 ? 0 : atoi(argv[1]);___test.run_test(x);if (x==100 || argc == 2)return 0;x++;char txt[30]; sprintf(txt, "%d", x); execlp(argv[0], argv[0], txt, txt, NULL);}
// END CUT HERE
