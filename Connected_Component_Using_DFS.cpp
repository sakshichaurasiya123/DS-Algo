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
        void dfs_helper(T src,unordered_map<T,bool>& visited){
            visited[src]=true;
            cout<<"  =  "<<src<<endl;
        
            for(T nbr:l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited);
                }
            }        
        }
        
        void Connected_Graph_Using_Dfs(){
            int cnt=0;
            unordered_map<T,bool> visited;
            for(auto p:l){
                T node=p.first;
                if(!visited[node]){
                    cout<<"Connected Node  "<<node<<"  ==  "<<endl;
                    dfs_helper(node,visited);
                    cnt++;
                }
            }
            cout<<"Count =  "<<(cnt)<<endl;
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
	g.addEdge(6,7);
	g.addEdge(7,9);
	g.addEdge(7,8);
	g.addEdge(10,11);
	g.addEdge(10,12);
	g.addEdge(11,12);
	g.addEdge(12,13);
	
//	g.bfs(0);
	g.Connected_Graph_Using_Dfs();
	return 0;
}
