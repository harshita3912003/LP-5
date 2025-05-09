#include<iostream>
#include <vector>
#include <stack>
#include <omp.h>
using namespace std;
const int MAX = 100000;
vector<int>graph[MAX];
bool visited[MAX];
void dfs(int node) {
stack<int>s;
s.push(node);
while (!s.empty())
{
int curr_node = s.top();
s.pop();
if (!visited[curr_node])
{
visited[curr_node] = true;
if (visited[curr_node])
{
cout << curr_node << " ";
}
#pragma omp parallel for
for (int i = 0; i < graph[curr_node].size(); i++)
    {
int adj_node = graph[curr_node][i];
if (!visited[adj_node])
{
s.push(adj_node);
}
}
}
}
}
int main() {
int n, m, start_node;
cout << "Enter No of Node,Edges,and startnode:" ;
cin >> n >> m >> start_node;
//n: node,m:edges
cout << "Enter Pair of edges:" ;
for (int i = 0; i < m; i++)
{ int u, v;
cin >> u >> v;
//u and v: Pair of edges
graph[u].push_back(v);
graph[v].push_back(u);
}
#pragma omp parallel for
for (int i = 0; i < n; i++)
{
visited[i] = false;
}
dfs(start_node);
/*for (int i = 0; i < n; i++)
{
if (visited[i])
{
cout << i << " ";
}
}*/
return 0;
}


/*
output:
Enter number of nodes: 7
Enter number of edges: 5
Enter starting node for DFS: 1
Enter edge pairs (u v):
1 3
4 7
2 6
5 1
7 2
DFS Traversal: 1 3 5 

=== Code Execution Successful ===

explanation: 

Nodes: 1 to 7
Edges (undirected):
1 — 3
4 — 7
2 — 6
5 — 1
7 — 2


Step 1: Graph Representation (Adjacency List)
1: [3, 5]
2: [6, 7]
3: [1]
4: [7]
5: [1]
6: [2]
7: [4, 2]


Step 2: Visualizing the Graph
   1
  / \
 3   5


2 - 7 - 4
 \
  6


Step 3: DFS Traversal Starting from Node 1

 Step-by-step:
Pop 1 → mark visited → neighbors: [3, 5]
→ push 3, then 5 → (stack = [3, 5])

Pop 5 → mark visited → neighbor: [1] (already visited)

Pop 3 → mark visited → neighbor: [1] (already visited)

✅ Traversal ends because the stack is now empty.


Final DFS Output: 1 3 5
Only Component 1 is visited — the rest (2, 4, 6, 7) are unreachable from node 1.

*/