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

class TheLargestString //{{
{
	public:
		string find(string s, string t);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "zy"; string Arg2 = "by"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; string Arg1 = "zzzaaaa"; string Arg2 = "cbaaaa"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "xx"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "tttttttttttttttttttttttttttttttttttttdaa"; string Arg1 = "atttttttttttttttttttttttttttttttttttbyyy"; string Arg2 = "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttb"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
}; //}}

inline string append(string word, char a, char b)
{
    return word.substr(0, word.size() / 2) + a + word.substr(word.size() / 2) + b;
}

string TheLargestString::find(string s, string t)
{
    string result[64][64] = {};
    for(unsigned int l = 1; l <= s.size(); ++ l)
        for(unsigned int p = l; p <= s.size(); ++ p)
            for(int j = p - 1; j >= 0; -- j)
            {
                string temp = append(result[l - 1][j], s[p - 1], t[p - 1]);
                if(temp > result[l][p])
                    result[l][p] = temp;
            }

    string res = "";
    for(unsigned int l = 0; l <= s.size(); ++ l)
        for(unsigned int p = 0; p <= s.size(); ++ p)
        if(result[l][p] > res)
            res = result[l][p];

    return res;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[]){TheLargestString ___test;int x = argc == 1 ? 0 : atoi(argv[1]);___test.run_test(x);if (x==100 || argc == 2)return 0;x++;char txt[30]; sprintf(txt, "%d", x); execlp(argv[0], argv[0], txt, txt, NULL);}
// END CUT HERE
