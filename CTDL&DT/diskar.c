#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
#define INF 1000000

int A[MAX][MAX];
int c[MAX][MAX];
int n, m;
int s, t;
int d[MAX];
int node[MAX];
int idx[MAX];
int sH;
int fixed[MAX];

void swap(int i, int j) {
    int tmp = node[i];
    node[i] = node[j];
    node[j] = tmp;
    idx[node[i]] = i;
    idx[node[j]] = j;
}

void upHeap(int i) {
    if (i == 0) return;
    while (i > 0) {
        int pi = (i - 1) / 2;
        if (d[node[i]] < d[node[pi]]) {
            swap(i, pi);
        } else {
            break;
        }
        i = pi;
    }
}

void downHeap(int i) {
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int minIdx = i;
    if (L < sH && d[node[L]] < d[node[minIdx]]) minIdx = L;
    if (R < sH && d[node[R]] < d[node[minIdx]]) minIdx = R;
    if (minIdx != i) {
        swap(i, minIdx);
        downHeap(minIdx);
    }
}

void insert(int v, int k) {
    d[v] = k;
    node[sH] = v;
    idx[node[sH]] = sH;
    upHeap(sH);
    sH++;
}

int inHeap(int v) {
    return idx[v] >= 0;
}

void updateKey(int v, int k) {
    if (d[v] > k) {
        d[v] = k;
        upHeap(idx[v]);
    } else {
        d[v] = k;
        downHeap(idx[v]);
    }
}

int deleteMin() {
    int sel_node = node[0];
    swap(0, sH - 1);
    sH--;
    downHeap(0);
    return sel_node;
}

void input() {
    scanf("%d%d", &n, &m);
    for (int k = 1; k <= m; k++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u][k] = v;
        c[u][k] = w;
    }
    scanf("%d%d", &s, &t);
}

void init(int s) {
    sH = 0;
    for (int v = 1; v <= n; v++) {
        fixed[v] = 0;
        idx[v] = -1;
    }
    d[s] = 0;
    fixed[s] = 1;
    for (int i = 1; i <= m; i++) {
        int v = A[s][i];
        insert(v, c[s][i]);
    }
}

void solve() {
    init(s);
    while (sH > 0) {
        int u = deleteMin();
        fixed[u] = 1;
        for (int i = 1; i <= m; i++) {
            int v = A[u][i];
            if (fixed[v]) continue;
            if (!inHeap(v)) {
                int w = d[u] + c[u][i];
                insert(v, w);
            } else {
                if (d[v] > d[u] + c[u][i]) updateKey(v, d[u] + c[u][i]);
            }
        }
    }
    int rs = d[t];
    if (!fixed[t]) rs = -1;
    printf("%d", rs);
}

int main() {
    input();
    solve();
    return 0;
}
