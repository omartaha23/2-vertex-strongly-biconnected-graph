#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Graph
{
public:
    int VNum;
    vector <vector <int>>adj;
    Graph(int VNum=0)
    {
        this->VNum=VNum;
        adj.resize(VNum);
    }
    void addEdge(int a,int b)
    {
        adj.at(a).push_back(b);
    }
    void print_graph()
    {
        for(int i=0;i<VNum;i++)
        {   cout<<i<<" -> ";
            for(int j=0;j<adj.at(i).capacity();j++)
            {
                cout<<adj.at(i).at(j)<<" , ";
            }
            cout<<endl;
        }

    }
};

void dfs(const Graph& G , int v , vector<char>& state , int dfsCounter ,
vector<int>& dfsNum , stack<int>& Ostack , stack<int>& Rstack , vector<int>& comp)
{
    state.push_back('A');// A = Active
    dfsNum.push_back(dfsCounter);
    dfsCounter=dfsCounter+1;
    Ostack.push(v);
    Rstack.push(v);
    for(int i=0;i<G.adj.at(v).capacity();i++)
        {   int w = G.adj.at(v).at(i);
            if(state[w]=='N')// N = New
            {
                dfs(G,w,state,dfsCounter,dfsNum,Ostack,Rstack,comp);
            }
            else
            {
                if(!Ostack.empty() && dfsNum[w]<dfsNum[Rstack.top()])
                {
                    do Rstack.pop();
                    while(!Rstack.empty() && dfsNum[w]<dfsNum[Rstack.top()]);

                }
            }
        }
    state[v] ='F';// F = Finished
    if(v==Rstack.top())
        Rstack.pop();
    while(!Ostack.empty())
    {
        int w=Ostack.top();
        comp[w]=v;
        if(w==v)
            break;
    }
}
void Cheriyan_Mehlhorn_Gabow(const Graph & G)
{
    int v;
    int dfsCounter =1;
    vector <char> state(v,'N');
    vector <int> dfsNum(v,-1);
    vector <int> comp(v,-1);
    stack <int> Rstack;
    stack <int> Ostack;
    for(int i=0;i<v;i++)
    {
        if (state.at(i)=='N')
        {
            dfs(G,v,state,dfsCounter,dfsNum,Ostack,Rstack,comp);
        }
    }
}
int main()
{
 /*   Graph x(3);
    for (int i=0;i<2;i++)
    {
        int a,b;

        cout<<"enter the Begin vertex: ";
        cin>>a;
        cout<<"enter the End vertex: ";
        cin>>b;
        x.addEdge(a,b);
    }
    x.print_graph();
 */
    return 0;
}
