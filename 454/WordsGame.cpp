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

class WordsGame 
{
	private:
		int columnSwaps(vector <string> grid, string word)
		{
			int best = 10000,
				moves;

			bool flag;
			vector<string> temp = grid;
			for(unsigned int r = 0; r < grid.size(); ++ r)
			{
				flag = true;
				moves = 0;
				for(unsigned int pos = 0; pos < grid[r].length() && flag; ++ pos)
				{
					for(unsigned int c = pos; c < grid[r].length() && flag; ++ c)
						if(word[pos] == grid[r][c])
						{
							if(pos != c)
							{
								swap(grid[r][c], grid[r][pos]);
								++ moves;
							}

							flag = false;
						}

					if(flag)
						flag = false;

					else
						flag = true;
				}

				if(flag && best > moves)
					best = moves;
			}

			return best == 10000?-1:best;
		}

		int rowSwaps(vector <string> grid, string word)
		{
			int best = 10000,
				moves;

			bool flag;
			vector<string> temp = grid;
			for(unsigned int c = 0; c < grid[0].size(); ++ c)
			{
				flag = true;
				moves = 0;
				for(unsigned int pos = 0; pos < grid[c].length() && flag; ++ pos)
				{
					for(unsigned int r = pos; r < grid[c].length() && flag; ++ r)
						if(word[pos] == grid[r][c])
						{
							if(pos != r)
							{
								swap(grid[r][c], grid[pos][c]);
								++ moves;
							}

							flag = false;
						}

					if(flag)
						flag = false;

					else
						flag = true;
				}

				if(flag && best > moves)
					best = moves;
			}

			return best == 10000?-1:best;
		}
	public:
		int minimumSwaps(vector <string> grid, string word)
		{
			int result = columnSwaps(grid, word),
				temp = rowSwaps(grid, word);

			return temp == -1?result:(result == -1?temp:(result < temp?result:temp));
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Mu",
 "uM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Mu"; int Arg2 = 0; verify_case(0, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"sdf",
 "bca",
 "hgf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 2; verify_case(1, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cdf",
 "bca",
 "agf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 1; verify_case(2, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bkHg"; int Arg2 = 2; verify_case(3, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "oDmWcJHGNk"; int Arg2 = 6; verify_case(4, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aB"; int Arg2 = -1; verify_case(5, Arg2, minimumSwaps(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	WordsGame ___test;
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
