#include<stdio.h>
#include<vector>

#include<stack>
using namespace std;

int V,E,L,desti;
vector<int> Graph[100];
int maxdist=0 ;
int flag = 0;
stack<int> st;

void insert_graph()
{
    int i,j;
    printf("Please enter the number Verteces : \n");
    scanf("%d",&V);
    printf("Please enter the number of Edges : \n");
    scanf("%d",&E);
    for(i=1; i<=E; i++)
    {
        int V1,V2;
        printf("Enter The connections : ");
        scanf("%d %d",&V1,&V2);
        Graph[V1].push_back(V2);
        Graph[V2].push_back(V1);
    }
}

void print_graph()
{
    int i,j;
    printf("\nthe connetions are : \n");
    for(i=1; i<=V; i++)
    {
        printf("Connections of %d ----> ",i);
        for(j=0; j<Graph[i].size(); j++)
        {
            printf("%d , ",Graph[i][j]);
        }
        printf("\n");
    }
}

bool visited[100];
int d[100];
int p[100];



void dfs_visit(int source)
{

    for(int i=0; i<Graph[source].size(); i++)
    {
        if(flag==1)
        {
            return;
        }

    }
    if(flag==0 && maxdist> L)
    {
        printf("Not found\n");
    }


}

void dfs(int source)
{
    int maxdist= L+10 ;
    for(int i=0; i<V; i++)
    {
        visited[i] = 0;
        d[i]= maxdist;
        p[i]=-1;
    }
    maxdist = 0;
    d[source] = 0 ;
    visited[source] = 1;
    st.push(source);

    //printf("cpp : %d p %d  child : %d parent : %d\n",u,source,d[u],d[source]);
    //  printf("child dist  %d\n", d[u]);hhhh
    while(!st.empty())
    {
       // printf("Kiya halot he bacchu \n");
        int v = st.top();
       // printf("st top %d\n",v);
        st.pop();
       // printf("st pop %d\n",v);

        for(int i=0; i<Graph[v].size(); i++)
        {

            int u = Graph[v][i];
           // printf("All edges %d parent %d \n",u,v);
            if(d[u] >=(d[v]+1))
            {
                visited[u] = 0;
                st.push(u);//  printf("c : %d p %d \n",u,source);
            }
            if(visited[u]==0)
            {

                visited[u]=1;
                d[u]=d[v]+1;
                if(d[u]> maxdist)
                {
                    maxdist = d[u];
                 //   printf("Maxdist : %d",maxdist);
                }
                //printf("distance %d\n",d[u]);
                if(u==desti && d[u]<=L)
                {
                    printf("Destination found");
                    flag= 1;
                    return ;
                }
            }
        }
    }

    if(flag==0) printf("Not found");

}





int main()
{
    while(1)
    {

        insert_graph();
        print_graph();
        printf("Please enter the source and destination  : ");
        int source;
        scanf("%d %d",&source, &desti);
        printf("Please enter the limit : ");
        scanf("%d",&L);
        dfs(source);
        // bfs();
        // print_distance();
        return  0;
    }
}

/*
6
7
1 2
1 4
2 4
2 5
3 4
4 5
4 6

1 6
2

*/
