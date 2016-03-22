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

class EllysFigurines //{{
{
	public:
		int getMoves(vector <string> board, int R, int C);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(3, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {
 "..X..",
 "...X.",
 "....X",
 "...X.",
 "..X..",
 ".X...",
 "X....",
 ".X...",
 "..X..",
 "...X.",
 "....X",
 "...X.",
 "..X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 4; verify_case(4, Arg3, getMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE
}; //}}

inline int count(vector<string> board, const int &mask, const int &R, const int &C)
{
    int result = __builtin_popcount(mask);
    for(int r = 0; r < board.size(); ++ r)
        if(mask & (1 << (r / R))) for(int q = 0; q < R && r + q < board.size(); ++ q)
            for(int s = 0; s < board[0].size(); ++ s)
                board[r + q][s] = '.';

    for(int h = 0; h < board[0].size(); ++ h)
    {
        bool empty = true;
        for(int r = 0; empty && r < board.size(); ++ r)
            empty = board[r][h] != 'X';

        if(empty)
            continue;

        result += 1;
        h += C - 1;
    }

    return result;
}

int EllysFigurines::getMoves(vector <string> board, int R, int C)
{
    int result = 15;
    for(int m = 0; m < (1 << ((board.size() + R - 1) / R)); ++ m)
        result = min(result, count(board, m, R, C));

    return result;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[]){EllysFigurines ___test;int x = argc == 1 ? 0 : atoi(argv[1]);___test.run_test(x);if (x==100 || argc == 2)return 0;x++;char txt[30]; sprintf(txt, "%d", x); execlp(argv[0], argv[0], txt, txt, NULL);}
// END CUT HERE
