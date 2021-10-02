#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int weight;
};
bool compare(Edge a, Edge b){
    return (a.weight<b.weight);
}
int find(int parent[],int v){
    if (parent[v] == v){
        return v;
    }
    else
        return parent[v] = find(parent, parent[v]);//path compression which sets the root parent as the parent of the node 
}

void kruskal(Edge *input, int E, int V){
    //sort the edges w.r.t the weights
    sort(input, input+E, compare);
    Edge*output = new Edge[V-1];//The output for the MST

    int parent[V];
    for (int i =0;i<V;i++){
        parent[i] = i;//initially every node is the root of itself
    }

    int count = 0;//to keep track of how many edges have been covered
    int i = 0; // for the current edge

    while(count!=V-1){
        Edge currentEdge = input[i];//Current Edge with minimum weight
        int sourceParent = find(parent, currentEdge.src);
        int destParent = find(parent, currentEdge.dest);

        if (sourceParent != destParent){
            output[count++]=currentEdge;
            parent[sourceParent] = destParent;//union
        }
        i++; //for the next edge
    }
    cout<<"\nAccording to the Kruskal Algorithm, the final MST is \n";
    cout<<"\n   Source      destination     weight\n";
    for (int i = 0;i<V-1;i++){
        if (output[i].src<output[i].dest){
            cout<<"     "<<output[i].src<<"  -   "<<output[i].dest<<"    ->  "<<output[i].weight<<endl;
        }
        else{
            cout<<"     "<<output[i].dest<<"  -   "<<output[i].src<<"    ->  "<<output[i].weight<<endl;
        }
    }
    
}

int main(){
    int V, E;
    cout<<"\nEnter the number of vertices : ";
    cin>>V;
    cout<<"\nEnter the number of Edges : ";
    cin>>E;
    Edge * input = new Edge[E];
    cout<<"\nEnter the source destination and weight(space separated)\n";
    for (int i =0;i<E;i++){
        cin>>input[i].src>>input[i].dest>>input[i].weight;
    }
    kruskal(input, E, V);
}