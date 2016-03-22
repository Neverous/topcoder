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

class ColoringRectangle 
{
	public:
		int chooseDisks(int Width, int height, vector <int> red, vector <int> blue)
		{
			int a = chooseDisks1(Width, height, red, blue),
				b = chooseDisks2(Width, height, red, blue);

			if(a == -1)
				return b;

			if(b == -1)
				return a;

			return a < b ? a : b;
		}

		int chooseDisks1(int Width, int Height, vector <int> red, vector <int> blue)
		{
			double width = Width,
				   height = Height;
			sort(red.rbegin(), red.rend());
			sort(blue.rbegin(), blue.rend());
			unsigned state = 0,
					 b = 0,
					 r = 0,
					 used = 0;

			for(; width > 0 && (b < blue.size() || r < red.size()); state = !state)
			{
				if(b == blue.size() && state)
					return -1;

				if(r == red.size() && !state)
					return -1;

				if(state)
				{
					if(height > blue[b])
						return -1;

					width -= 2.0 * sqrt((blue[b] - height) * (blue[b] + height) / 4);
					++ b;
					++ used;
				}

				else
				{
					if(height > red[r])
						return -1;

					width -= 2.0 * sqrt((red[r] - height) * (red[r] + height) / 4);
					++ r;
					++ used;
				}
			}

			return width > 0?-1:used;
		}

		int chooseDisks2(int Width, int Height, vector <int> red, vector <int> blue)
		{
			double width = Width,
				   height = Height;
			sort(red.rbegin(), red.rend());
			sort(blue.rbegin(), blue.rend());
			unsigned state = 1,
					 b = 0,
					 r = 0,
					 used = 0;

			for(; width > 0 && (b < blue.size() || r < red.size()); state = !state)
			{
				if(b == blue.size() && state)
					return -1;

				if(r == red.size() && !state)
					return -1;

				if(state)
				{
					if(height > blue[b])
						return -1;

					width -= 2.0 * sqrt((blue[b] - height) * (blue[b] + height) / 4);
					++ b;
					++ used;
				}

				else
				{
					if(height > red[r])
						return -1;

					width -= 2.0 * sqrt((red[r] - height) * (red[r] + height) / 4);
					++ r;
					++ used;
				}
			}

			return width > 0?-1:used;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 11; int Arg1 = 3; int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {4,10,7,8,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,6,11,7,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_2() { int Arg0 = 16; int Arg1 = 4; int Arr2[] = {6,5,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }

		// END CUT HERE

};


// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	ColoringRectangle ___test;
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
