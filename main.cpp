//------------------Mohammad Saleem Kobesh & Omar Taha--------------------
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;
class Graph
{
public:
    static int VNum;
    static vector<vector<int>> adj;

    Graph(int VNum = 0)
    {
        this->VNum = VNum;
        adj.resize(VNum);
    }

    void addEdge(int a, int b)
    {
        adj.at(a).push_back(b);
    }

    void print_graph()
    {
        for (int i = 0; i < VNum; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < adj.at(i).capacity(); j++)
            {
                cout << adj.at(i).at(j) << " , ";
            }
            cout << endl;
        }
    }

    //---------------------Hala Khalefa----------------------
    void convert_to_undirected()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.at(i).size(); j++)
            {
                this->addEdge(adj.at(i).at(j), i);
            }
        }
    }
};

//-----------------------Omar Taha---------------------------

void gabow_dfs(const Graph& G , int v , vector<char>& state , int dfsCounter ,
vector<int>& dfsNum , stack<int>& Ostack , stack<int>& Rstack , vector<int>& comp)
{
 state.push_back('A');// A = Active
 dfsNum.push_back(dfsCounter);
 dfsCounter=dfsCounter+1;
 Ostack.push(v);
 Rstack.push(v);
 for(int i=0;i<G.adj.at(v).capacity();i++)
 { int w = G.adj.at(v).at(i);
 if(state[w]=='N')// N = New
 {
 gabow_dfs(G,w,state,dfsCounter,dfsNum,Ostack,Rstack,comp);
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

//------------------Kareem Aboud & Yazan Alyousef------------------------

void merge(vector<int> &A, int p, int q, int r) {
 int nl = q - p + 1;
 int nr = r - q;
 vector<int> L(nl);
 vector<int> R(nr);

 for (int i = 0; i < nl; i++) {
 L[i] = A[p + i];
 }
 for (int j = 0; j < nr; j++) {
 R[j] = A[q + 1 + j];
 }

 int i = 0, j = 0, k = p;
 while (i < nl && j < nr) {
 if (L[i] <= R[j]) {
 A[k] = L[i];
 i++;
 } else {
 A[k] = R[j];
 j++;
 }
 k++;
 }

 while (i < nl) {
 A[k] = L[i];
 i++;
 k++;
 }

 while (j < nr) {
 A[k] = R[j];
 j++;
 k++;
 }
}

void merge_sort(vector<int> &A, int p, int r) {


 if (p >= r)
 return;

 int q = floor((p + r) / 2);
 merge_sort(A, p, q);
 merge_sort(A, q + 1, r);
 merge(A, p, q, r);
}

//------------------Mohamnad Iskandar--------------------

int MaxNum(const vector<int>& B)
{

 int maxIndex = 0;
 int max1 = B[0];

 for (int i = 1; i < B.size(); ++i)
 {
 if (B[i] > max1)
 {
 max1 = B[i];
 maxIndex = i;
 }
 }

 return maxIndex;
}

//---------------------Omar Taha & Kareem Aboud--------------------------

void Not_Strongly_Connected(vector <int> B,const Graph & G){
bool Cheriyan_Mehlhorn_Gabow(const Graph & G);
 vector <int>A;
 for(int i=0;i<B.size();i++){
 A.push_back(B[i]);
 }
 merge_sort(A,A.at(0),A.at(A.size()-1));
 vector <int>counters;
 for(int j=0;j<A.size();j++)
 {
 int counter1=0;
 for(int i=0;i<A.size();i++)
 {
 if(A[i]==j)
 counter1++;
 }
 counters.push_back(counter1);
 }
  vector<int>R;
 int n= MaxNum(counters);
 for(int i=0;i<A.size();i++){
 if(B[i]==n)
 R.push_back(i);

 }
for(int i=0;i<G.adj.size();i++)
{
    for(int j=0;j<G.adj.size();j++)
    {
        if(i!=R.at(j)){
            G.adj.erase(G.adj.begin()+i);
            G.VNum-=1;
    }
    }
}
 Cheriyan_Mehlhorn_Gabow(G);
}

//---------------------Rawad Namour & Lujain Hamad--------------------------

bool Cheriyan_Mehlhorn_Gabow(const Graph & G)
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
 gabow_dfs(G,v,state,dfsCounter,dfsNum,Ostack,Rstack,comp);//**Omar Taha**
 }
 }
 bool t= false;
 for(int i=0;i<comp.size();i++)
 {
 if(comp.at(0)==comp.at(i))
 t=true ;
 }
 if(t)
    {
 return t;
 }
    else
    {
        cout<<"the graph isn't strongly connected so we will take the maximum SCC"<<endl;

 Not_Strongly_Connected(comp,G);//**Kareem Aboud**
 return t;
    }
}

//---------------------Riham Eisa--------------------------

 void jens_dfs(int u, vector<bool>& visited)
 {
    visited[u] = true;
    for (int v : Graph::adj[u])
    {
        if (!visited[v])
        {
            jens_dfs(v, visited);
        }
    }
}

//---------------------Tala Nakkara--------------------------

bool jens_schmidt(Graph & G)
{
    G.convert_to_undirected();
    vector<bool> visited(G.VNum, false);
    jens_dfs(0, visited);
    for (int i = 0; i < G.VNum; i++)
    {
        for (int v : G.adj[i])
        {
            if (!visited[v])
            {
                //Not a 2-edge connected graph
                return false;
            }
        }
    }
    for (int u = 0; u < G.VNum; ++u) {
        for (int v : G.adj[u]) {
            if (v != 0 && !visited[v]) {
                //2-edge connected graph but Not 2-connected graph
                return false;
                }
            }
        }
    //2-connected graph
    return true;
}

//---------------------Asaad Kherbek--------------------------

bool strongly_biconnected(Graph G)
{
    if(jens_schmidt(G) && Cheriyan_Mehlhorn_Gabow(G))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
     ifstream inputFile("email-Eu-core.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int numVertices=265214 ;
    int numEdges=420045;

    Graph graph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        inputFile >> u >> v;
        graph.addEdge(u, v);
    }

    cout<<strongly_biconnected(graph)<<endl;
    graph.print_graph();
    return 0;
}
