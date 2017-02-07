#include<bits/stdc++.h>
using namespace std;


// Code For Queue
struct Node
{
    Node* prev;
    int data;
};

Node* last= NULL;
Node* first= NULL;

void push(int n)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    if(first == NULL)
    {
        first = temp ;
    }
    else
    {
        last->prev = temp;
    }
    temp->prev = NULL;
    temp->data = n;
    last = temp ;

}

int mfront()
{
   if(first == NULL)
   {
       return NULL;
   }
   else
    {
     return first->data;
    }
}
int pop()
{
    if(first == NULL)
    {
        return NULL ;
    }
    else
    {
       // printf("Under pop\n");
        Node* temp = first->prev;
        int data= first->data ;
        free(temp);
        first = temp;
        return data;
    }

}
void printQueue()
{
    Node * temp = first;
    while(temp != NULL)
    {
        printf("%d , ", temp->data);
        temp=temp->prev ;
    }
}

// BFS Starts

int V;
int E;
map< int,vector<int> > Graph;
std::map< int, vector<int> > ::iterator  it ;
map< int , bool > color;
map< int, int > distances;
int maxlevel = 0;



void bfs()
{
    printf("Please enter the Agent\n");
    int agent;
    scanf("%d",&agent);
    for(it = Graph.begin(); it!=Graph.end(); ++it)
    {
        int t = it->first;
       //color[t] = 0;
        distances[t]= 0;
    }

    color[agent] = 1;
    push(agent);
    int k=0;int p;
    while(p != NULL)
    {   // printf("\n");
         p = mfront();  pop() ;
       // printf("parent %d : \n",p);
        vector<int> adj = Graph[p];
        for(int i=0;i<adj.size();i++)
        {
            int v = adj[i];
           if(color[v] == 0 )
           {
             //  printf("\nInside bfs : %d and color : %d", adj[i],color[v]);
               color[v] = 1;
               distances[v] = distances[p] + 1;
               if(maxlevel< distances[p] + 1)
               {
                   maxlevel = distances[p] + 1 ;
               }
               push(adj[i]);
           }
        }

    k++;
    }

}



void printLevel()
{
    //printf("printlevel is called \n");
    std::map<int,int> :: iterator dist;
    for(int i=0;i<=maxlevel;i++)
    {
        printf("Level %d :",i);
        for(dist = distances.begin(); dist!=distances.end(); ++dist)
        {
            if(dist->second == i)
            {
               printf("%d, ", dist->first);
              // printf("printlevel is called \n");
            }

        }
       printf("\n");

    }
}


void printGraph()
{

    for(it=Graph.begin(); it!=Graph.end(); ++it)
    {
        printf("Connection of %d : ", it->first);
        vector<int> adj = it->second;
        for(int i=0; i<adj.size(); i++)
        {
            printf("%d , ",adj[i]);
        }
        printf("\n");

    }
}





int main()
{


        maxlevel = 0;
        printf("Please enter the number of Verteces : ");
        scanf("%d, ",&V);
        printf("Please enter the number of Edges : ");
        scanf("%d, ",&E);
        for(int i=1; i<=E; i++)
        {
            int v1,v2;
            printf("Please enter the connection between verteces : ");
            scanf("%d %d", &v1, &v2);
            Graph[v1].push_back(v2);
            Graph[v2].push_back(v1);

        }

        printGraph();
        bfs();
        printLevel();


    return 0;
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





























/*
int main()
{
     int i=0;int n;
     while(i<5)
     {
         printf("Please enter number : ");
         scanf("%d",&n);
         push(n);
         i++;
     }
     printf("Printing ..... ");
     printQueue();

     while(1)
     {   int n;
         printf("Please enter data : ");
         scanf("%d, ",&n);
         push(n);  printf("Printing ..... "); printQueue();
         pop(); printf("Printing ..... "); printQueue();

     }


    return 0;
}
*/


