#include <bits/stdc++.h>

// <! Dijkstra's Shortest Path !> 

struct Edge{
    int v; // destination
    int c; // cost 

    Edge(){
        v = 0;
        c = 0;
    }
    Edge(int v, int c){
        this->v = v;
        this->c = c;
    }
};

class Comparator{  
public:
    int operator() (const Edge& e1, const Edge& e2){
        return e1.c > e2.c;
    }  
};

void dij(int start, std::vector <Edge> list[], Edge results[], int n){
    // initialization
    for (int i = 1; i <= n; i++)
        results[i].c = INT_MAX;
    results[start].c = 0;
    int current;
    int v; // next from the list
    std::priority_queue<Edge, std::vector<Edge>, Comparator> q; // the queue of processing
    Edge e(start, 0);
    q.push(e);
    // <! MAIN ALGORITHM !> //
    while (!q.empty()){
        current = q.top().v;
        q.pop();
        for (int i = 0; i < list[current].size(); i++){
            v = list[current][i].v;
            if (results[v].c > results[current].c + list[current][i].c){
                results[v].c = results[current].c + list[current][i].c;
                results[v].v = current;
                Edge e(v, results[v].c);
                q.push(e);
            }
        }
    }
}

int main(){
    int n; // number of vertices
    int m; // number of edges
    std::cout << "Input number of vertices: ";
    std::cin >> n;
    std::cout << "Input number of edges: ";
    std::cin >> m;

    // data
    std::vector <Edge> *list = new std::vector<Edge>[n+1];
    int a, b, w;

    // building the graph
    std::cout << "Now input the edges (a, b, w):\n";
    Edge edge1;
    for (int i = 0; i < m; i++){
        std::cin >> a >> b >> w;
        edge1.v = b;
        edge1.c = w;
        list[a].push_back(edge1);
        edge1.v = a;
        list[b].push_back(edge1);
    }

    int start; // the starting point
    std::cout << "Input the starting point: ";
    std::cin >> start;

    Edge *results = new Edge[n+1]; // the array for results
    dij(start, list, results, n);    

    std::vector <int> road;
    int current;
    for (int i = 1; i <= n; i++){
        if (i == start){
            std::cout << i << " - that's the starting point\n";
            continue; 
        }
        road.clear();
        current = i;
        while (current != start){
            road.push_back(current);
            current = results[current].v;
        }
        road.push_back(start);
        for (int j = road.size()-1; j > 0; j--)
            std::cout << road[j] << " -> ";
        std::cout << road[0] << " with the cost of " << results[i].c << "\n";
    }
}
