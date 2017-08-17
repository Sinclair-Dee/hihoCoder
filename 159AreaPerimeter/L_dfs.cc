#include<iostream>
using namespace std;
int N, M, r;
int s[100][100];//存放每个岛屿的值
bool v[100][100];
int d[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};

//巧妙的利用深度遍历，实现从(x,y)中心点往四周扩展。
//遇到矩阵的大边界或者该边接壤的点不是s[i][j]，那么就说明该边是岛屿的一个边界，周长加一。
int dfs(int x , int y)
{
  if(x<0||y<0||x>=N||y>=M||s[x][y]!=r)return 1;
  if(v[x][y])return 0;
  v[x][y] = 1;
  int result = 0;
  for(int i=0;i<4;i++)result += dfs(x+d[i][0], y+d[i][1]);
  return result;
}

int main()
{
  int x, y;
  cin>>N>>M>>x>>y;
  for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>s[i][j];
  r = s[x][y];
  cout<<dfs(x, y)<<endl;
  return 0;
}