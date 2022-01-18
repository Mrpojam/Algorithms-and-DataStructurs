#include <bits/stdc++.h>

using namespace std;
 
const int maxN = 10; 
 
bool isSafe(int v, bool graph[maxN][maxN], int path[], int pos) {
    if (!graph [path[pos - 1]][ v ])
        return false;
 
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
bool check_ham(bool graph[maxN][maxN], int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (check_ham (graph, path, pos + 1, n) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool Hamiltonian_Cycle(bool graph[maxN][maxN], int n) {
    int *path = new int[maxN];
    for (int i = 0; i < n; i++)
        path[i] = -1;
    path[0] = 0;
    if (check_ham(graph, path, 1, n) == false ) {
        cout << "There is no path" << endl;
        return false;
    }

  for (int i = 0; i < n; i++)
        cout << path[i] << " ";
    cout << path[0] << " " << endl;
    return true;
}
 

 
int main() {
    int n;
    cin >> n;
    bool graph[maxN][maxN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    Hamiltonian_Cycle(graph, n);
    return 0;
}
 
// This is code is contributed by rathbhupendra