int adjtoedge() {
  for (int i = 1; i <= n; ++i) {
    for (auto &p : adj[i]) {
      edges.push_back({i, p.first, p.second});
    }
  }
}

int edgetoadj() {
  int a, b, w;
  for (auto &t : edges) {
    tie(a, b, w) = t;
    adj[a].push_back({b, w});
  }
}

int adjtomatrix() {
  for (int i = 1; i <= n; ++i) {
    for (auto &p : adj[i]) {
      mat[i][p.first] = p.second;
    }
  }
}

int matrixtoadj() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (mat[i][j] != 0)
        adj[i].push_back({j, mat[i][j]});
    }
  }
}

int edgetomatrix() {
  int a, b, w;
  for (auto &e : edges) {
    tie(a,b,w) = e;
    mat[a][b] = w;
  }
}

int matrixtoedge() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (matrix[i][j] != 0) {
        edges.push_back({i, j, matrix[i][j]});
      }
    }
  }
}