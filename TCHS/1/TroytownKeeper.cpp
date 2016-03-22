#include<algorithm>
#include<queue>
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

class TroytownKeeper 
{
	public:
	int limeLiters(vector <string> maze);

	// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"##..#"
		,"#.#.#"
			,"#.#.#"
			,"#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(0, Arg1, limeLiters(Arg0)); }
	void test_case_1() { string Arr0[] = {"##",
		"##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, limeLiters(Arg0)); }
	void test_case_2() { string Arr0[] = {"######"
		,"#....."
			,"#.####"
			,"#.#..#"
			,"#.##.#"
			,"#....#"
			,"######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56; verify_case(2, Arg1, limeLiters(Arg0)); }
	void test_case_3() { string Arr0[] = {"######"
		,"#....."
			,"#..#.."
			,"#....."
			,"######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(3, Arg1, limeLiters(Arg0)); }
	void test_case_4() { string Arr0[] = {"#.#.#.#"
		,".#.#.#."
			,"#.#.#.#"
			,".#.#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(4, Arg1, limeLiters(Arg0)); }

	// END CUT HERE

};

int TroytownKeeper::limeLiters(vector <string> maze)
{
	bool visited[maze.size()][maze[0].size()];
	int result = 0;
	std::pair<int, int> act;
	for(int r = 0; r < maze.size(); ++ r)
		for(int c = 0; c < maze[0].size(); ++ c)
			visited[r][c] = false;

	std::queue<std::pair<int, int> > que;
	for(int r = 0; r < maze.size(); ++ r)
	{
		if(maze[r][0] == '.')
		{
			visited[r][0] = true;
			que.push(std::make_pair(r, 0));
		}

		else
			++ result;

		if(maze[r][maze[0].size() - 1] == '.')
		{
			visited[r][maze[0].size() - 1] = true;
			que.push(std::make_pair(r, maze[0].size() - 1));
		}
		
		else
			++ result;
	}

	for(int c = 0; c < maze[0].size(); ++ c)
	{
		if(maze[0][c] == '.')
		{
			if(!visited[0][c])
			{
				visited[0][c] = true;
				que.push(std::make_pair(0, c));
			}
		}
		
		else
			++ result;

		if(maze[maze.size() - 1][c] == '.')
		{
			if(!visited[maze.size() - 1][c])
			{
				visited[maze.size() - 1][c] = true;
				que.push(std::make_pair(maze.size() - 1, c));
			}
		}

		else
			++ result;
	}

	while(!que.empty())
	{
		act = que.front();
		que.pop();
		for(int i = -1; i < 2; ++ i)
			for(int j = i?0:-1; j < 2; j+= 2)
				if(act.first + i >= 0 && act.first + i < maze.size() && act.second + j >= 0 && act.second + j < maze[0].size())
				{
					if(maze[act.first + i][act.second + j] == '#')
						++ result;

					else if(!visited[act.first + i][act.second + j])
					{
						visited[act.first + i][act.second + j] = true;
						que.push(std::make_pair(act.first + i, act.second + j));
					}
				}

	}

	return result;
}

// BEGIN CUT HERE
#include <unistd.h>
int main(int argc,char *argv[])
{
	TroytownKeeper ___test;
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
