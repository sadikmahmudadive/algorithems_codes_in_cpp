#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 6
#define MAX_NODES 100

// adjacency matrix graph
int adjMatrix[MAX_NODES][MAX_NODES] = {0}; // representing the adjacency matrix by D array
int numOfNodes; // Number of nodes in the graph

//structure of queue
typedef struct 
{
    int elements[MAX_SIZE]; // Array for hold elements of the queue
    int front, rear; // Front and rear pointers of the queue
} 
Queue;


// Function for createing an empty queue
Queue createQueue() 
{
    Queue q;
    q.front = -1; // Initializ front and rear to -1 indicates an empty queue
    q.rear = -1;
    return q;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *q, int val) 
{
    if ((q->rear + 1) % MAX_SIZE == q->front) 
    {
        printf("The queue is at full capacity and cannot accommodate additional entries.\n");
        return;
    }

    if (q->front == -1) // If queue is empty, adjust front pointer
        q->front = 0;
    q->rear = (q->rear + 1) % MAX_SIZE; // Increment rear pointer
    q->elements[q->rear] = val; // Add element to the rear of the queue
}

// Function to remove an element from the front of the queue
int dequeue(Queue *q) 
{
    int val;
    if (q->front == -1) // If queue is empty
    {
        printf("The queue is currently empty, rendering it unable to execute dequeuing operations.\n");
        return -1;
    }
    val = q->elements[q->front]; // Get the element from the front of the queue
    if (q->front == q->rear)
    {
        q->front = -1; // Reset front and rear pointers to indicate an empty queue
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_SIZE; // Move front pointer to the next element
    }
    return val; // Return the dequeued element
}

// Function to display the elements of the queue
void displayQueue(Queue *q) 
{
    if (q->front == -1)
    {
        printf("The queue does not contain any elements.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->front;
    do 
    { // Loop through the elements of the queue
        printf("%d ", q->elements[i]);
        i = (i + 1) % MAX_SIZE; // Move to the next element
    } while (i != (q->rear + 1) % MAX_SIZE); // Loop until we reach the rear of the queue
    printf("\n");
}

// Function to add an edge between two nodes in the graph
void addEdge(int sorc, int dest) 
{
    adjMatrix[sorc][dest] = 1; // Set the edge in the adjacency matrix
}

// Function to perform (BFS) traversal starting from a given node
void breadthFirstSearch(int startNode) 
{
    bool visited[MAX_NODES] = {false}; // Array for keep track of visited nodes
    Queue q = createQueue(); // Create an empty queue for BFS traversal

    visited[startNode] = true; // Mark the start node as visited
    enqueue(&q, startNode); // Enqueue the start node

    printf("Breadth First Traversal starting from the node %d: ", startNode);

    while (q.front != -1)
    {
        int currentNode = dequeue(&q); // Dequeue a node from the queue
        printf("%d ", currentNode);

        // Traverse all adjacent nodes of the dequeued node
        for (int i = 0; i < numOfNodes; ++i) {

            if (adjMatrix[currentNode][i] == 1 && !visited[i]) 
            {
                visited[i] = true; // Mark node 'i' as visited
                enqueue(&q, i); // Enqueue node 'i'
            }
        }
    }

    printf("\n");
}

// Function for display the adjacency matrix of the graph
void displayadjMatrix() 
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numOfNodes; i++) 
    {
        for (int j = 0; j < numOfNodes; j++) 
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int numberOfEdges, sorc, dest;

    printf("Enter the number of nodes: ");
    scanf("%d", &numOfNodes);
    if (numOfNodes > MAX_NODES)
    {
        printf("Number of nodes exceeds the maximum limit\n");
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numberOfEdges);

    printf("Enter the edges (sorc destination):\n");
    for (int i = 0; i < numberOfEdges; i++)
    {
        scanf("%d %d", &sorc, &dest);
        if (sorc < 0 || sorc >= numOfNodes || dest < 0 || dest >= numOfNodes)
        {
            printf("The edge provided is invalid as the node index is out of bounds.\n");
            return 1;
        }
        addEdge(sorc, dest); // Add the edge to the graph
    }

    printf("\n");
    displayadjMatrix(); // Displaying the adjacency matrix of the graph

    //BFS traversal starting from each node in the graph
    for (int i = 0; i < numOfNodes; ++i) 
    {
        breadthFirstSearch(i);
    }

    return 0;
}