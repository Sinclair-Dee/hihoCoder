//深度遍历，从中心点到四周扩散
//基本思想：DFS
#include<iostream>
using namespace std;
int N, M, r;
int s[100][100];//存放每个岛屿的值
bool v[100][100];//标记函数,表示该点已经遍历过了。
int d[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};//前后左右的点

//巧妙的利用深度遍历，实现从(x,y)中心点往四周扩展。
//遇到矩阵的大边界或者该边接壤的点不是s[i][j]，那么就说明该边是岛屿的一个边界，周长加一。

//DFS Pseudo-code
//r = s上的数字
//IF 坐标(x,y)处于矩阵的边界 OR 坐标(x,y)上的数不等于r。 return 1(即周长+1)
//IF 坐标(x,y)被标记过了，return 0; 不再往下操作。
//(否则)标记坐标(x,y)
//定义周长：result
//递归调用DFS,(x,y)的上下左右点作为DFS的参数递归调用。结果累加到result中。

int dfs(int x, int y){
  //需要算周长的情况
  if(x<0 || y<0 || x>=N || y>=M || s[x][y] != r) return 1;
  //不需要算周长的情况-两个正方形连到一块。
  if(v[x][y]) return 0;
  v[x][y] = true;
  int result = 0;
  for(int i=0; i<4; i++) result += dfs(x+d[i][0], y+d[i][1]);
  return result;
}

//test - main
int main(){
  int x,y;
  cin>>N>>M>>x>>y;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>s[i][j];
  r = s[x][y];
  cout<<dfs(x,y)<<endl;
  return 0;
}