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

class TextFrames 
{
	public:
		vector <string> generateFrame(int width, int height, string phrase, int x1, int y1, int x2, int y2);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 29; int Arg1 = 5; string Arg2 = "I.LOVE.TOPCODER"; int Arg3 = 0; int Arg4 = 0; int Arg5 = 29; int Arg6 = 5; string Arr7[] = {"I.LOVE.TOPCODER.I.LOVE.TOPCOD", "............................E", "R...........................R", "E............................", "DOCPOT.EVOL.I.REDOCPOT.EVOL.I" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(0, Arg7, generateFrame(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; string Arg2 = "THIS.SHOWS.A.CORNER"; int Arg3 = 5; int Arg4 = 5; int Arg5 = 10; int Arg6 = 10; string Arr7[] = {"....O", "....R", "....N", "....E", "IHT.R" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(1, Arg7, generateFrame(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arg2 = "THE.PHRASE.CAN.BE.LONGER.THAN.THE.PERIMETER"; int Arg3 = 1; int Arg4 = 2; int Arg5 = 4; int Arg6 = 4; string Arr7[] = {"..H", "SAR" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(2, Arg7, generateFrame(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 777; int Arg1 = 896; string Arg2 = "THE.PORTION.MAY.NOT.CONTAIN.ANY.LETTER"; int Arg3 = 30; int Arg4 = 20; int Arg5 = 50; int Arg6 = 30; string Arr7[] = {"....................", "....................", "....................", "....................", "....................", "....................", "....................", "....................", "....................", "...................." }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(3, Arg7, generateFrame(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; string Arg2 = "LIVE"; int Arg3 = 0; int Arg4 = 508; int Arg5 = 4; int Arg6 = 528; string Arr7[] = {"E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "....", "E...", "V...", "I...", "L...", "...." }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(4, Arg7, generateFrame(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

char isTextHere(int width, int height, string phrase, int x, int y)
{
	if(y == 0)
		return phrase[x % phrase.size()];

	if(y == height - 1)
		return phrase[(width + height - 3 + width - x) % phrase.size()];

	if(x == 0)
		return phrase[(2 * width + height - 4 + height - y) % phrase.size()];

	if(x == width - 1)
		return phrase[(width - 1 + y) % phrase.size()];

	return '.';
}

vector <string> TextFrames::generateFrame(int width, int height, string phrase, int x1, int y1, int x2, int y2)
{
	vector<string> res;
	phrase += ".";
	for(int y = y1; y < y2; ++ y)
	{
		string result;
		for(int x = x1; x < x2; ++ x)
			result += isTextHere(width, height, phrase, x, y);

		res.push_back(result);
	}

	return res;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TextFrames ___test;
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
