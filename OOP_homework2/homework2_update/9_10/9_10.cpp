#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define MAXN 100
#define inf 1e2

//-------------------------------------------------------------------------------------------

class Edge {
public:
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    int u; // one of the endpoints
    int v; // another endpoint 
    int w; // weight
};

int n; // number of vertices
int edge_num; // number of edges
int adjM[100][100]; // adjacent matrix
vector<Edge> edgeSet; // store every edge

void init()
{
    memset(adjM, -1, sizeof(adjM));
    cin >> n >> edge_num;

    int u, v, w;
    for (int i = 0; i < edge_num; i++) {
        cin >> u >> v >> w;
        adjM[u][v] = adjM[v][u] = w;
        edgeSet.push_back(Edge(u, v, w));
    }
}

//-------------------------------------------------------------------------------------------
// This part is about problem 9.
/*input
 7
 11
 0 1 5
 0 5 3
 1 2 10
 1 4 1
 1 6 4
 2 3 5
 2 6 8
 3 4 7
 3 6 9
 4 5 6
 4 6 2
*/
void Prims_Algorithm(int s)
{
    bool visit[MAXN]; // record whether the vertex is in MST
    int key[MAXN]; // record the minimum cost from MST to the vertex

    for (int i = 0; i < n; i++) {
        visit[i] = false;
        key[i] = inf;
    }

    key[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        // TODO 1
        // hint: find the vertex which have not been visited and have minimum key
        for (int k = 0; k < n; k++)
        {
            if (key[k] <= min && visit[k] == false)
            {
                u = k;
                min = key[k];
            }
        }

        visit[u] = true;
        for (int j = 0; j < n; j++) {
            // TODO 2
            // hint: update key of u's neighbor
            if (adjM[u][j] != -1 && visit[j] == false)
            {
                if (key[j] <= adjM[u][j])
                {
                    continue;
                }
                else
                {
                    key[j] = adjM[u][j];
                }
            }
        }
    }

    int MSTweight = 0;
    for (int i = 0; i < n; i++)
    {
        MSTweight += key[i];
    }
    cout << endl;
    cout << "Get MST's weight " << MSTweight << " by Prim's algorithm." << endl;
}
//-------------------------------------------------------------------------------------------
// This part is about problem 10.

int subsets[MAXN]; // record each vertex belong to which set(represent by leader's index).
int cheapest[MAXN]; // there may be many edges outgoing from a set, this array just record the edge which have minimum weight.
                    // for example, cheapest[1] = 2 means edge 2 is outgoing from the set vertex 1 belong to and has minimum weight.

// find and Union functions are related to disjoint-sets forest.
// I just write a naive version here. Actually, it can be more efficient by some tricks.

// find the leader of the set
int find(int x)
{
    while (x != subsets[x])
        x = subsets[x];

    return x;
}

// union two sets
void Union(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;

    subsets[x] = y;
}

// Sollin's algorithm is also known as Borůvka's algorithm.
void Sollins_Algorithm()
{
    int numTrees = n, MSTweight = 0;
    for (int i = 0; i < n; i++)
        subsets[i] = i;

    while (numTrees > 1) {
        for (int i = 0; i < n; i++)
            cheapest[i] = -1;

        for (int i = 0; i < edge_num; i++) {
            int set1 = find(edgeSet[i].u);
            int set2 = find(edgeSet[i].v);
            if (set1 == set2) continue;

            // TODO 3
            // hint: update the cheapest for both set1 and set2
            else
            {
                if (cheapest[set1] == -1 || edgeSet[cheapest[set1]].w > edgeSet[i].w)
                {
                    cheapest[set1] = i;
                }
                if (cheapest[set2] == -1 || edgeSet[cheapest[set2]].w > edgeSet[i].w)
                {
                    cheapest[set2] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (cheapest[i] != -1) {
                int set1 = find(edgeSet[cheapest[i]].u);
                int set2 = find(edgeSet[cheapest[i]].v);
                if (set1 == set2) continue;

                // TODO 4
                // hint: union two sets and change MSTweight & numTree
                MSTweight += edgeSet[cheapest[i]].w;
                Union(set1, set2);
                numTrees--;
            }
        }
    }

    cout << "Get MST's weight " << MSTweight << " by Sollin's algorithm." << endl;
}

//-------------------------------------------------------------------------------------------

int main()
{
    init();
    Prims_Algorithm(0);
    Sollins_Algorithm();

    return 0;
}