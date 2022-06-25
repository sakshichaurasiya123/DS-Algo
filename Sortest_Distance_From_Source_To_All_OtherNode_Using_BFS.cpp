#include <iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    unordered_map<T,vector<T>> l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void bfs(int src){
            unordered_map<T,int> dest;
            queue<T>q;
            for(auto node_pair:l){
                T node=node_pair.first;
                dest[node]=INT_MAX;
            }
            q.push(src);
            dest[src]=0;
            while(!q.empty()){
                T node=q.front();
                q.pop();
                for(auto nbr:l[node]){
                    if(dest[nbr]==INT_MAX){
                        q.push(nbr);
                        dest[nbr]=dest[node]+1;
                    }
                }
            }
            for(auto node_pair:l){
                T node =node_pair.first;
                T d=dest[node];
                cout<<"Node = "<<node<<" Distance from src  "<<d<<endl;
            }
        }
};



int main() {
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,0);
	g.addEdge(2,3);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(3,0);
	g.addEdge(4,5);
	g.bfs(0);
	return 0;
}
