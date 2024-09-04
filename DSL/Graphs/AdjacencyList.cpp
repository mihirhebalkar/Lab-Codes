#include<stdio.h>
#include<stdlib.h>

 //A C Program to demonstrate adjacency list representation of graphs
 
 // A structure to represent an adjacency list node
struct Node
{
    int data;
    struct Node* next;
};

// A structure to represent an adjacency list
struct List
{
    struct Node* head;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct List* array;
};

//Function to create a new adjacency list node
struct Node*c_node(int x)
{
    struct Node*q=(struct Node*)malloc(sizeof(struct Node));
    
    q->data=x;
    
    q->next=NULL;
    
    return q;
}

//Function that creates a graph of V vertices
struct Graph*createGraph(int V)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    
    graph->V=V;
    
     // Create an array of adjacency lists.  Size of array will be V
     
    graph->array=(struct List*)malloc(sizeof(struct List)*V);
    
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    
    for(i=0;i<V;i++)
     {
        graph->array[i].head=NULL;
     }
    return graph;
}

// Adds an edge to a directed graph
void addEdge(struct Graph* graph,int src,int des)
{
    //Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    
     struct Node*temp=c_node(des);
     
     temp->next=graph->array[src].head;
    
     graph->array[src].head=temp;
    
}

//Function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    int v;
    
    for (v = 0; v < graph->V; ++v)
    {
        struct Node* trav = graph->array[v].head;
        
        printf("\n Adjacency list of vertex %d\n head ", v);
        
        while (trav!=NULL)
        {
            printf("-> %d", trav->data);
            
            trav = trav->next;
        }
        printf("\n");
    }
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}


