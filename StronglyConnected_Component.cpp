#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> graph[], unordered_map<int,bool> &visited, vector<int> &stack,int src){
    visited[src]=true;
    for(auto nbr:graph[src]){
        if(!visited[nbr]){
            dfs(graph,visited,stack,nbr);
        }
    }
    stack.push_back(src);
}

void dfs2(vector<int> rev_graph[],unordered_map<int,bool> &visited,int src){
    visited[src]=true;
    cout<<src<<" ";
    for(auto nbr:rev_graph[src]){
        if(!visited[nbr]){
            dfs2(rev_graph,visited,nbr);
        }
    }
    
}
void solve(vector<int> graph[],vector<int> rev_graph[],int V){
    unordered_map<int,bool>visited;
    vector<int> stack;
    for(int i=0;i<V; i++){
        if(!visited[i]){
            dfs(graph,visited,stack,i);
        }
    }
    
    //step 1 -> has been completed (store vertices in ordered list)

    //Step 2 -> Reverse vector is also completed

    //step 3 -> Do dfs again with ordered list from right to left with the help of Reverse graph 

    visited.clear();
    char component='A';
    for(int i=stack.size()-1; i>=0; i--){
        
        auto node=stack[i];
        if(!visited[node]){
            std::cout<<"Connected Component of "<<component<<"  --> ";
            dfs2(rev_graph,visited,node);
        }
        cout<<"\n";
    }

    
}

int main(){
    int V;
    cin>>V;
    vector<int> graph[V];
    vector<int> rev_graph[V];
    int e;
    cin>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
        
    }
   solve(graph,rev_graph,V);
    return 0;
    
}



/* Input Output
Number of Inputs 
7 
8
2 1
1 0
0 2
0 3
3 5
5 6
6 3
3 4


Output ->
Connected Component of A  --> 0 1 2 
Connected Component of A  --> 3 6 5 
Connected Component of A  --> 4 

*/
