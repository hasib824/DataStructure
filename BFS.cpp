#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int V,E;
vector<int> Graph[10];
vector<int> distle[10];
int maxdist=0 ;

void insert_graph()
{
    int i,j;
    printf("Please enter the number Verteces : \n");
    scanf("%d",&V);
    printf("Please enter the number of Edges : \n");
    scanf("%d",&E);
    for(i=1;i<=E;i++)
    {
        int V1,V2;
        printf("Enter The connections : ");
        scanf("%d %d",&V1,&V2);
        Graph[V1].push_back(V2);
        Graph[V2].push_back(V1);
    }
}

void print_graph()
{   int i,j;
    printf("\nthe connetions are : \n");
    for(i=1;i<=V;i++)
    {
        printf("Connections of %d ----> ",i);
        for(j=0;j<Graph[i].size();j++)
        {
            printf("%d , ",Graph[i][j]);
        }
        printf("\n");
    }
}

  int visited[100];
  int d[100];
  int p[100];

void bfs()
{   int u,i,j;
    for(i=1;i<=V;i++)
    {

        visited[i]=0; // 1 if visited and 0 if not visited
        d[i]=999999;
        p[i]=-1;
    }
    queue<int>q;

    printf("\nPlease Enter the agent : ");
    int agent ; scanf("%d",&agent);
    visited[agent]=1;
    d[agent]=0;
    q.push(agent);
    while(!q.empty())
    {
       u=q.front();
       q.pop();
       for(i=0;i<Graph[u].size();i++)
       {
            //printf("connection is %d\n",i);
            j=Graph[u][i];
            if(visited[j]==0)
           {
              visited[j]=1;
              p[j]=u;
              d[j]=d[u]+1;
              if(d[j]>maxdist)
              {
                  maxdist= d[j];
             }
              q.push(j);
           }
       }

    }
}


void print_distance()
{
    printf("\nPrinting the distance :");
     for(int i=0;i<=maxdist;i++)
     {
         printf("\nLevel %d : ",i);
         for(int j=1;j<=V;j++)
         {
            if(d[j]==i)
            {
              printf("%d, ",j);
            }
         }

     }
     printf("\n");
}
int main()
{
    while(1)
    {

        insert_graph();
        print_graph();
        bfs();
        print_distance();
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

*/
