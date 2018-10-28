#include <stdio.h>

#ifndef INF
#define INF 0x7fffffff
#endif

#define maxN 7

/*
  n               size
  des             destination
  d[]             distances from nodes
  vis[]           visted nodes
  prev[]         path
  matrix[]      map distance


 */

int matrix[maxN][maxN] = {
    {0, 1, INF, 4, 4, INF},     {INF, 0, INF, 2, INF, INF},
    {INF, INF, 0, INF, INF, 1}, {INF, INF, 2, 0, 3, INF},
    {INF, INF, INF, INF, 0, 3}, {INF, INF, INF, INF, INF, 0}};

// dijkstra
void dijkstra(int n, int d[n], int prev[n], int des, int matrix[n][n]) {}

// main
int main() {
  int d[maxN];
  for (int i = 0; i < maxN; ++i) {
    d[i] = INF;
  }

  int prev[maxN];
  for (int i = 0; i < maxN; ++i) {
    prev[i] = 0;
  }

  int des = 6;

  dijkstra(maxN, d, prev, des, matrix);

  return 0;
}

///////////////////////////////////////////

void Dijkstra_c(int out[], int N, int v0) {
  int i, j;
  int visited[maxN] = {
      0};  // 表示顶点是否被选中，0：顶点未被选中；1：顶点已被选中
  int last_visited = 0;
  for (i = 0; i < N; ++i) {
    out[i] = INF;  // 把输出结果全部初始化为无穷大
  }
  visited[v0] = 1;               // 选中起始顶点	out[v0] = 0;
  for (i = 0; i < N - 1; ++i) {  // N 个顶点需要做 N - 1次循环
                                 // 查看顶点周围的所有点
    for (j = 0; j < N; ++j) {    // 循环遍历所有顶点
      if (visited[j] == 0) {  // 保证被查看的新顶点没有被访问到
        if (matrix[v0][j] != 0) {  //保证当前顶点（V0）与新顶点（j）之间有路径
          int dist = matrix[v0][j] + last_visited;  // 计算 V0 到 J的路径距离
          if (dist < out[j]) out[j] = dist;  // 用新路径代替原来的路径
        }
      }
    }
    // 找出最小值
    int minIndex = 0;
    while (visited[minIndex] == 1) minIndex++;
    //找第一个没有被选中的节点
    for (j = minIndex; j < N; ++j) {
      if (visited[j] == 0 && out[j] < out[minIndex]) {
        minIndex = j;
      }
    }
    last_visited = out[minIndex];  // 更新最小值
    visited[minIndex] = 1;         // 将最小值顶点选中
    v0 = minIndex;                 // 下次查找从最限制顶点开始
  }
}
