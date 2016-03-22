#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstring>
#define MIN(a, b) ((a) < (b)?(a):(b))
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
#define MAX(a, b) ((a) > (b)?(a):(b))
#define ABS(a) ((a) > 0?(a):-(a))
// END CUT HERE
using namespace std;

class FoldingMaze 
{
	public:
		int solve(vector <string> frontSide, vector <string> backSide);
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...E",
 "....",
 "S..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"####",
 "####",
 "####"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...E",
 "###.",
 "S.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"....",
 "....",
 "...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"....",
 "S.#.",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#...",
 "##.E",
 ".#.#"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"....####",
 "#####..#",
 "S#.....#",
 ".#.....#",
 ".####..#",
 "....####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".##..#..",
 "..#..#..",
 "#.#..#.E",
 "#.#..#..",
 "..#..###",
 ".##....#"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"....####",
 "#####..#",
 "S#.....#",
 ".#.....#",
 ".####..#",
 "....####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".#####.#",
 "..####..",
 "#.####.E",
 "#.####..",
 "..######",
 "........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};
int end = -1,
	start = -1;
vector<pair<int, pair<int, int> > > graph[1024];
int cost[1024];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, greater<pair<pair<int, int>, int> > > que;
pair<pair<int, int>, int> act;
//KOSZT, ZAGIECIE, PUNKT

int dijkstra(void)
{
	for(int c = 0; c < 1024; ++ c)
		cost[c] = 1000000;

	que.push(make_pair(0, 0), start);
	while(!que.empty())
	{
		act = que.top();
		que.pop();
		if(act.second == end)
			return act.first.first;

		for(int s = 0; s < graph[act.second].size(); ++ s)
		{
			if(act.first.second == 0)
				if(cost[graph[act.second][s].first] > act.first.first + graph[act.second][s].second.first)
				{
					cost[graph[act.second][s].first] = act.first.first + graph[act.second][s].second.first;
					que.
				}
		}
	}
}
/* To były jakieś harkorowe zadanka ;/... */

int FoldingMaze::solve(vector <string> frontSide, vector <string> backSide)
{
	for(int h = 0; h < frontSide.size(); ++ h)
		for(int w = 0; w < frontSide[h].size(); ++ w)
		{
			if(frontSide[h][w] == 'E')
				end = h * 50 + w;

			if(frontSide[h][w] == 'S')
				start = h * 50 + w;

			if(frontSide[h][w] == '#')
				continue;

			//GRAPH[h*50 + w]
			for(int i = -1; i < 2; i += 2)
				if(h + i >= 0 && h + i < frontSide.size() && frontSide[h + i][w] != '#')
					graph[h * 50 + w].push_back(make_pair((h + i) * 50 + w, make_pair(1, 0)));

			for(int i = -1; i < 2; i += 2)
				if(w + i >= 0 && w + i < frontSide[h].size() && frontSide[h][w + i] != '#')
					graph[h * 50 + w].push_back(make_pair(h * 50 + w + i, make_pair(1, 0)));
		}

	for(int h = 0; h < backSide.size(); ++ h)
		for(int w = 0; w < backSide[h].size(); ++ w)
		{
			if(backSide[h][w] == 'E')
				end = 250 + h * 50 + w;

			if(backSide[h][w] == 'S')
				start = 250 + h * 50 + w;

			if(backSide[h][w] == '#')
				continue;

			for(int i = -1; i < 2; i += 2)
				if(h + i >= 0 && h + i < backSide.size() && backSide[h + i][w] != '#')
					graph[250 + h * 50 + w].push_back(make_pair(250 + (h + i) * 50 + w, make_pair(1, 0)));

			for(int i = -1; i < 2; i += 2)
				if(w + i >= 0 && w + i < backSide[h].size() && backSide[h][w + i] != '#')
					graph[250 + h * 50 + w].push_back(make_pair(250 + h * 50 + w + i, make_pair(1, 0)));
		}
	for(int f = 1; f < frontSide[0].size(); ++ f)
	{
	for(int h = 0; h < frontSide.size(); ++ h)
	{
		if(frontSide[h][f - 1] == '#')
			continue;
		
		if(backSide[h][f - 1] != '#')
			graph[h * 50].push_back(make_pair(250 + h * 50, make_pair(2, f)));
	}

	for(int h = 0; h < frontSide.size(); ++ h)
	{
		if(backSide[h][f - 1] == '#')
			continue;
		
		if(frontSide[h][f - 1] != '#')
		{
			graph[250 + h * 50].push_back(make_pair(h * 50, make_pair(1, f)));
			graph[250 + h * 50].push_back(make_pair(h * 50, make_pair(2, 0)));
		}
	}
	}

	return dijkstra();
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	FoldingMaze ___test;
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
