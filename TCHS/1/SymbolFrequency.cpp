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

class SymbolFrequency 
{
	public:
		double language(vector <string> frequencies, vector <string> text);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a30b30c40","a20b40c40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aa bbbb cccc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, language(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"a30b30c40","a20b40c40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaa bbbb ccc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, language(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"a10b10c10d10e10f50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcde g"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 10.8; verify_case(2, Arg2, language(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01"
,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"this text is in english" 
,"the letter counts should be close to"
,"that in the table"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 130.6578; verify_case(3, Arg2, language(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a09b01c03d05e20g01h01i08l06n08o06r07s09t08u07x01"
,"a14b02c05d06e15g01h01i07l05n07o10r08s09t05u04x01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"en esta es una oracion en castellano"
,"las ocurrencias de cada letra"
,"deberian ser cercanas a las dadas en la tabla"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 114.9472; verify_case(4, Arg2, language(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"z99y01", "z99y01", "z99y01", "z99y01", "z99y01", 
 "z99y01", "z99y01", "z99y01", "z99y01", "z99y01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 495050.0; verify_case(5, Arg2, language(Arg0, Arg1)); }

// END CUT HERE

};

double SymbolFrequency::language(vector <string> frequencies, vector <string> text)
{
	double result[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		   tmp;
	int count[32],
		length = 0,
		expected[16][32];

	for(int f = 0; f < 16; ++ f)
		for(int c = 0; c < 32; ++ c)
			expected[f][c] = 0;

	for(int f = 0; f < frequencies.size(); ++ f)
		for(int c = 0; c < frequencies[f].size(); c += 3)
			expected[f][frequencies[f][c] - 'a'] = (frequencies[f][c + 1] - '0') * 10 + frequencies[f][c + 2] - '0';

	for(int c = 0; c < 32; ++ c)
		count[c] = 0;

	for(int t = 0; t < text.size(); ++ t)
		for(int c = 0; c < text[t].size(); ++ c)
		{
			if(text[t][c] > 'z' || text[t][c] < 'a')
				continue;

			++ length;
			++ count[text[t][c] - 'a'];
		}

	for(int f = 0; f < frequencies.size(); ++ f)
		for(int c = 0; c < 32; ++ c)
		{
			tmp = 1.0 * expected[f][c] * length / 100.0 - count[c];
			result[f] += tmp * tmp;
		}

	tmp = result[0];
	for(int f = 0; f < frequencies.size(); ++ f)
		if(result[f] < tmp)
			tmp = result[f];

	return tmp;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	SymbolFrequency ___test;
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
