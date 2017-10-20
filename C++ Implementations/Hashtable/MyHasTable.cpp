#include<bits/stdc++.h>
using namespace std;

const int s = 3; // n can be vary based on our requirements

struct Node
{
    string name;
    int id; int age; int batch; Node* next;
    Node(string nam,int identy,int aged,int batchy)
    {
        name = nam; id = identy;
        age = aged; batch = batchy;
        next = NULL;
    }
};

// Implements JShash
int getKey(string str)
{
   unsigned int hash = 1315423911;
   unsigned int i    = 0;
   for(i = 0; i<str.length(); i++)
   {
      hash ^= ((hash << 5) + (str[i]) + (hash >> 2));
   }
   return hash%n;
}

class MyHashTable
{
    public:
        Node* myHashTable[n];
        MyHashTable()
        {
            for(int i=0;i<n;i++)
                myHashTable[i] = NULL;
        }

        void put(string name,Node *student)
        {
            int key = getKey(name);
            Node* temp = myHashTable[key];
            if(temp== NULL)
            {
                myHashTable[key] = student;
                return;
            }
            Node * parent = temp;
            while(temp->next !=NULL && temp->name != name)
            {
                parent = temp;
                temp = temp->next;
            }
            if(temp->name == name)
            {
                student->next = temp->next;
                parent->next = student;
                delete temp;
            }
            else
                temp->next = student;

        } // End Of Put

        Node* get(string name)
        {
            int key = getKey(name);
            Node* temp = myHashTable[key];
            if(temp == NULL ) return NULL;
            while(temp != NULL && temp->name != name)
                temp = temp->next;
            return temp;
        }

        void remove_data(string name)
        {
            int key = getKey(name);
            Node* temp = myHashTable[key];
            if(temp == NULL )
            {
                printf("\nNo such data\n");
                return;
            }
            Node * parent = temp;
            while(temp->next!= NULL && temp->name != name)
            {   parent = temp;
                temp = temp->next;
            }
            if (temp->name == name)
            {
                parent->next = temp->next;
                delete temp; return;
            }
            else
                 printf("\nNo such data\n");
        }

};

int main()
{
    printf("How many datas ? ");
    int nDatas; scanf("%d",&nDatas);
    MyHashTable hashTable;

    for(int i=0;i<nDatas;i++)
    {
        string name; int id;int age;int batch;
        cin>>name>>id>>age>>batch;
        hashTable.put(name,new Node(name,id,age,batch));
    }
    while(true)
    {
        printf("\npress \n1 to insert \n2 to get \n3 to remove\n");
        int s; cin>>s;
        if(s==1)
        {
            cout<<"please enter datas"<<"\n";
            string name0; int id;int age;int batch;
            cin>>name0>>id>>age>>batch;
            hashTable.put(name0,new Node(name0,id,age,batch));
        }
        else if(s==2)
        {
            cout<<"please enter key to get"<<"\n";
            string name1; cin>>name1;
            Node* temp = hashTable.get(name1);
            if(temp==NULL) cout<<"\nNo such data"<<"\n";
            else
                cout<<"\nName : "<<temp->name<<"\n"<<"Id : "<<temp->id<<"\n"<<"Age : "<<temp->age<<"\n";

        }
        else if(s==3)
        {
            cout<<"please enter key to remove"<<"\n";
            string name2; cin>>name2;
             hashTable.remove_data(name2);

        }
        getchar();
    }
    return 0;
}

/*
6
Hasib
32
28
35
Shakib
32
28
35
Sakhawat
35
28
35
Saimor
34
28
35
Mamun
33
28
35
Alamin
36
30
35


2
Sakhawat
2
Saimor
2
hasib
2
Mamun
2
Alamin
*/
