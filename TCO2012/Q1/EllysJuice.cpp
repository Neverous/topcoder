#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<set>
// BEGIN CUT HERE
#include<utility>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<list>
#include<numeric>
#include<queue>
#include<sstream>
#include<stack>
#define MIN(a, b) ((a) < (b)?(a):(b))
#define MAX(a, b) ((a) > (b)?(a):(b))
#define ABS(a) ((a) > 0?(a):-(a))
// END CUT HERE
using namespace std;

class EllysJuice 
{
	public:
		vector <string> getWinners(vector <string> players);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "aaaaaa", "kriss", "stancho", "aaaaaa", "stancho" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaaaa", "stancho" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinners(Arg0)); }
	void test_case_1() { string Arr0[] = {"torb", "aaaaaa", "stancho", "kriss"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinners(Arg0)); }
	void test_case_2() { string Arr0[] = {"aaaaaa", "aaaaaa", "aaaaaa", "aaaaaa", "aaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaaaa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinners(Arg0)); }
	void test_case_3() { string Arr0[] = { "a", "b", "b", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a", "b"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinners(Arg0)); }

// END CUT HERE

};

int simulate(vector<int> way)
{
	vector<int> score;
	score.resize(way.size(), 0);
	int o = 1024,
		a = 1024,
		best = 0;
	for(int w = 0; w < way.size(); ++ w)
	{
		if(w % 2 == 0)
		{
			score[way[w]] += o / 2;
			o /= 2;
		}

		else
		{
			score[way[w]] += a / 2;
			a /= 2;
		}
	}

	for(int s = 0; s < way.size(); ++ s)
		if(score[best] < score[way[s]])
			best = way[s];

//	for(int s = 0; s < way.size(); ++ s)
//		fprintf(stderr, "Res %d: %d\n", way[s], score[way[s]]);

	for(int s = 0; s < way.size(); ++ s)
		if(score[best] == score[way[s]] && way[s] != best)
			return -1;

	return best;
}

vector <string> EllysJuice::getWinners(vector <string> players)
{
//	fprintf(stderr, "wtf?\n");
	int winner = 0,
		counter = 0;
	vector<int> way(players.size());
	map<string, int> was;
	string name[16];
	set<string> result;
	for(int s = 0; s < players.size(); ++ s)
	{
		if(!was[players[s]])
		{
			was[players[s]] = ++ counter;
			name[counter] = players[s];
		}

		way[s] = was[players[s]] - 1;
	}

	std::sort(way.begin(), way.end());

//	fprintf(stderr, "WTF?\n");
	do
	{
		winner = simulate(way);
//		for(int s = 0; s < players.size(); ++ s)
//			fprintf(stderr, "%d ", way[s]);
//		fprintf(stderr, "\n");
		if(winner != -1)
//		{
//			fprintf(stderr, "Winner is: %s\n", name[winner + 1].c_str());
			result.insert(name[winner + 1]);
//		}

//		else
//			fprintf(stderr, "No winner\n");
	}
	while(next_permutation(way.begin(), way.end()));

	return vector<string>(result.begin(), result.end());
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	EllysJuice ___test;
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
