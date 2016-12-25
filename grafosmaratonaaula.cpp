#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

vector <int> g[MAX];
int vis[MAX];
int vtimer[MAX];
int timer = 0;

void dfs(int curr)
{
  //if(vis[curr] == GRAY) cout << "Its a cycle!" << endl; to find cycles!!
  
  if(vis[curr] != WHITE) return; //if node has already been visited, stop
  timer++; //time has passed
  if(vtimer[curr] == -1) vtimer[curr] = timer; //when we visited the node for the first time
  vis[curr] = GRAY; //setting as visited
  cout << "Entering " << curr+1 << endl;

  for(int i = 0; i < g[curr].size(); ++i)
  {
    int next = g[curr][i]; //Next node to visit
    if(vis[next] == WHITE) printf("(%d, %d) is Tree Edge\n", curr+1, next+1);
    else if(vis[next] == GRAY) printf("(%d, %d) is Back Edge\n", curr+1, next+1);
    else
    {
      if(vtimer[curr] >= vtimer[next])
      {
        printf("(%d, %d) is Cross Edge\n", curr+1, next+1);
      }
      else
      {
        printf("(%d, %d) is Forward Edge\n", curr+1, next+1);
      }

    }
    dfs(next);

  }

  cout << "Leaving " << curr+1 << endl;
  vis[curr] = BLACK; //Exiting the node
  return;
}

int main()
{
  int cases; cin >> cases; //How many test cases there are
  while(cases--)
  {
    memset(vis, WHITE, sizeof vis); //setting vis[i] to 0
    memset(vtimer, -1, sizeof vtimer); //setting vtimer[i] to -1
    timer = 0; //Starting the time
    for(int i = 0; i < MAX; ++i)
    {
      g[i].clear();//clearing the vector from previous test cases
    }
    int v, e; //nodes and edges
    cin >> v >> e;
    for(int i = 0; i < e; ++i)
    {
      int x, y; //from node x to node y
      cin >> x >> y;
      x--; y--; //If it starts from node 1
      g[x].push_back(y);
    }
    dfs(0); //calling the dfs function
  }

  return 0;

}
