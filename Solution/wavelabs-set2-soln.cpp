#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //this will store our graph connections
        unordered_map<int,vector<pair<int,int>>>gr;
        //u=x[0] , v=x[1] wt=x[2] (there is an edge from u to v with weight wt)
        for(auto x:times)
          gr[x[0]].push_back({x[1],x[2]});
        //this will store distance from k to every other node
        vector<int>dist(n+1,INT_MAX);
        //distance of source node will be 0
        dist[k]=0;
        //this will give us the node with minimum distance 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //add a pair of distance,node (here we will add source node with distance 0)
        pq.push({0,k});
        //run DIJIKSTRA ALGORITHM!
        while(!pq.empty())
        {
            //get the node from front of queue
            int nd=pq.top().second;
            //get the distance of front node in queue
            int d=pq.top().first;
            pq.pop();
            //traverse neighbour nodes of the extracted node
            for(auto x:gr[nd])
            {
                //nbr has the node (v of edge u to v)
                int nbr=x.first;
                //wt has the weight of edge 
                int wt=x.second;
                //if distance of neighbor node is greater than the parent node + the weight of the edge then we will update the distance since we got a shorter cost
                if(dist[nbr]>dist[nd]+wt)
                {
                    dist[nbr]=dist[nd]+wt;
                    //push the new pair to the queue
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        //this will calculate the maximum distance calculated
        int ans=-1e9;
        //in order to ignore 0 we make it 0 bcoz nodes value range from 1 to n
        dist[0]=0;
        //get the max dist else if there is even a single node wose distance is not updated then return -1
        for(auto x:dist)
        {
            if(x==INT_MAX)
                return -1;
            else
                ans=max(ans,x);
        }
        return ans;
    }

int main(){
    vector<vector<int>> times;
    int n,k;
    int u,v,w;
    cout<<"enter no of nodes : ";
    cin>>n;
    for(int i =0;i<n-1;i++){
        cout<<"enter the travel times as directed edges times[i] = (ui, vi, wi) : ";
        cin>>u>>v>>w;
        vector<int> vect{ u, v, w };
        times.push_back(vect);
    }
    cout<<"enter starting node : ";
    cin>>k;
    cout<<"minimum time it takes for all the n nodes to receive the signal : "<<networkDelayTime(times,n,k)<<endl;
}