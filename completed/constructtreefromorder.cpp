#include <bits/stdc++.h>
using namespace std;

// from preorder and inorder

struct Node {
  int left;
  int right;
  Node(int l = 0, int r = 0) : left(l), right(r) {};
};

const int N = 7;
vector<int> preo;
vector<int> ino;
array<Node, N> tree = {
  Node(),
  Node(2, 3),
  Node(4, 5),
  Node(0, 7),
  Node(),
  Node(6, 0)
};
array<Node, N> ntree;
array<int, N> bk;

int solveindex = 0;

int solve(int l, int r) {
  int m = bk[preo[solveindex]];
  int i = solveindex++;
  ntree[preo[i]] = Node();
  if (l < m) ntree[preo[i]].left = solve(l, m);
  if (r > m+1) ntree[preo[i]].right = solve(m+1, r);
  return preo[i];
}

void preorder(int x) {
  Node s = tree[x];
  preo.push_back(x);
  if (s.left) preorder(s.left);
  if (s.right) preorder(s.right);
}

void inorder(int x) {
  Node s = tree[x];
  if (s.left) inorder(s.left);
  ino.push_back(x);
  if (s.right) inorder(s.right);
}

int main() {
  preorder(1); inorder(1);
  for (int i = 0; i < N; ++i) bk[ino[i]] = i;
  solve(0, N);
  for (const Node &n : ntree) cout << n.left << " " << n.right << '\n';
}