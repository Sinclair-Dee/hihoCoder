#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class UF{
public:
UF(int the_len){
    pre.resize(the_len);
    for(int i=0;i<the_len;i++){
        pre[i] = i;
    }
}
int find(int x){
    //查找根节点
    int root = x;
    while(pre[root] !=root)
        root = pre[root];
    //压缩-->ROOT
    while(pre[x] != root){
        int pre_temp = pre[x];
        pre[x] = root;
        x = pre_temp;
    }
    //返回根节点
    return root;
}
//判断x 和y 是否属于同一类簇，是则返回true，否则返回false。
bool isunion(int x,int y){
    return find(x) == find(y);//这种写法比较简短
/********************************
    x = find(x);
    y = find(y);
    if(x == y) 
        return true;
    else 
        return false;
*******************************/
}
//将x 和y 所属的两个类簇合并，也即将y 所属类簇的根结点ry连接到x所属类簇的根结点rx上。
void uniontwo(int x,int y){
	int rx = find(x);
	int ry = find(y);
	pre[ry] =rx;
}
//得到某一个点的前驱
int getpre(int k){
    return pre[k];
}
protected:
vector<int> pre; //前导数组，pre[i]表示i 与pre[i]属于同一类，且pre[i]为i的上一级。每一个类簇的根root的pre[root]=root
};

class Solution{
public:
int Sum_Local_L(int x,int y,vector<vector<char>>& grid){
    //如果vector长度为0，则返回0.
    if(grid.size() == 0)
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    int local = grid[x][y];
    int sum_local = 0;
    //定义并查集对象，大小为m*n。
    UF unionfind(m*n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            if(i>0 && grid[i-1][j] == grid[i][j]){
            unionfind.uniontwo((i-1)*n+j, i*n+j);//i*n+j(即i行*n列+j)
        }
            if(j>0 && grid[i][j-1] == grid[i][j]){
            unionfind.uniontwo(i*n+(j-1), i*n+j);
        }
    }
    int pre_local = unionfind.getpre(x*n+y);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            int now_local = unionfind.getpre(i*n+j);
			if(now_local == pre_local){
                sum_local += 4;
			if(i>0 && grid[i-1][j] == grid[x][y]){
                sum_local -= 2;}
            if(j>0 && grid[i][j-1] == grid[x][y]){
                sum_local -=2;}
			}
		}
		return sum_local;
	}    
};

//test
int main(){
    int m,n,x,y;
    cin>>m>>n>>x>>y;
	vector<vector<char>> grid(m,vector<char>(n));//必须要指定其大小，不然后续会造成越界。
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
            int in;
            cin>>in;
            grid[i][j] = in;
        }
    Solution solution;
    int Sum_Local_L = solution.Sum_Local_L(x,y,grid);
	cout<<Sum_Local_L;
    return 0;
}