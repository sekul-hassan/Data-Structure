#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<list<int>>li;
public:
    Graph(int V);
    void addEdge(int u,int v);
    void BFS(int s);
};
Graph::Graph(int v)
{
    this->V = v;
    li.resize(V);
}
void Graph::addEdge(int u,int v)
{
    li[u].push_back(v);
}
void Graph::BFS(int s)
{
    vector<bool>isVis;
    isVis.resize(V,false);
    list<int>q;
    isVis[s] = true;
    q.push_back(s);
    while(!q.empty())
    {
        s = q.front();
        cout<<s<<" ";
        q.pop_front();
        for(auto ad:li[s])
        {
            if(!isVis[ad]){
                isVis[ad] = true;
                q.push_back(ad);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int gs;
    gs = 4;
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    //g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(3,3);
    //g.addEdge(3,0);
    g.BFS(0);
    g.BFS(1);
    g.BFS(2);
    g.BFS(3);
    return 0;
}
