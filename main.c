/**Rana Musa
1210007
Section 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 9999
#define MAX 16
#define MAX_LINE_LENGTH 100
#define N 14
/*i used matrix implementation for graph in my project */
typedef struct graph {
    char city1[20];
    char city2[20];
    int distance;
} graph;

int source_index;
int destination_index;
void Dijkstra(graph* Graph[MAX][MAX], int start);
int getIndex(const char* city);
const* get_city(int n);
FILE* output;

int main() {
    printf("1: Load Cities from file\n");
    printf("2: Enter source city\n");
    printf("3: Enter destination city\n");
    printf("4: Exit and print all on file\n");

    int n;
    scanf("%d", &n);
    printf("\n");

    graph* graph[MAX][MAX]; // adjacency list representation

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            graph[i][j] = NULL;
        }
    }

    while (n != 4) {
        switch (n) {
            case 1: {
                FILE* file;
                char line[MAX_LINE_LENGTH];

                file = fopen("cities.txt", "r");
                if (file == NULL) {
                    printf("Failed to open the file.\n");
                    return 1;
                }

                while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
                    char city1[20], city2[20];
                    int distance;

                    sscanf(line, "%s %s %dkm", city1, city2, &distance);

                    // update the graph
                    graph[getIndex(city1)][getIndex(city2)] = malloc(sizeof(graph));
                    strcpy(graph[getIndex(city1)][getIndex(city2)]->city1, city1);
                    strcpy(graph[getIndex(city1)][getIndex(city2)]->city2, city2);
                    graph[getIndex(city1)][getIndex(city2)]->distance = distance;
                }

                printf("Data loaded successfully.\n\n");

                printf("Enter 1 if you want to see the graph or 0 to continue:  ");
                int n;
                scanf("%d",&n);
                printf("\n");
                if(n==1)
                {
                    printf("the graph is: \n\n");
                for (int i = 0; i < MAX; ++i) {
                    for (int j = 0; j < MAX; ++j) {
                        if (graph[i][j] != NULL && graph[i][j]->distance != -1) {
                            printf("%s - %s : %dkm\n", graph[i][j]->city1, graph[i][j]->city2, graph[i][j]->distance);
                        }
                    }
                }

                }


                printf("\n");

                fclose(file);
                break;
            }
            case 2: {

                char city[50];
                printf("Enter source city: ");
                scanf("%s", city);
                printf("\n");

                 source_index = getIndex(city);
                if (source_index != -1) {
                    printf("Source city: %s Saved\n", city);
                    printf("\n");
                } else {
                    printf("Invalid source city! Enter option 2 again\n\n");
                }

                break;
            }
            case 3: {

                char destinationCity[50];
                printf("Enter destination city: ");
                scanf("%s", destinationCity);
                printf("\n");

                output = fopen("shortest_distance.txt", "a");
                 destination_index = getIndex(destinationCity);
                if (destination_index != -1) {

                    printf("Results from Dijkstra:\n");
                    fprintf(output,"\n\nInformation from %s to %s:\n\n",get_city(source_index),destinationCity );


                    Dijkstra(graph, source_index);

                    printf("****************************************\n\n");
                    printf("Results From BFS:\n");
                    BFS(graph,source_index,destinationCity);
                    printf("\n");
                    fclose(output);
                } else {
                    printf("Invalid destination city! Enter choice 3 again\n\n");
                }

                break;
            }
            default: {
                printf("NO SUCH OPERATION!!\n\n");
                break;
            }
        }

        printf("1: Load Cities from file\n");
        printf("2: Enter source city\n");
        printf("3: Enter destination city\n");
        printf("4: Exit and print all on file\n");

        scanf("%d", &n);
        printf("\n");
    }

    // free allocated memory
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            free(graph[i][j]);
        }
    }

    return 0;
}

int getIndex(const char* city) {
    if (strcmp(city, "Akka") == 0) {
        return 1;
    } else if (strcmp(city, "Haifa") == 0) {
        return 2;
    } else if (strcmp(city, "Nazareth") == 0) {
        return 3;
    } else if (strcmp(city, "Jenin") == 0) {
        return 4;
    } else if (strcmp(city, "Bethlehem") == 0) {
        return 5;
    } else if (strcmp(city, "Jerusalem") == 0) {
        return 6;
    } else if (strcmp(city, "Jaffa") == 0) {
        return 7;
    } else if (strcmp(city, "Tulkarem") == 0) {
        return 8;
    } else if (strcmp(city, "Jericho") == 0) {
        return 9;
    } else if (strcmp(city, "Qalqilya") == 0) {
        return 10;
    } else if (strcmp(city, "Tubas") == 0) {
        return 11;
    } else if (strcmp(city, "Nablus") == 0) {
        return 12;
    } else if (strcmp(city, "Ramallah") == 0) {
        return 13;
    } else if (strcmp(city, "Salfit") == 0) {
        return 14;
    }

    else if (strcmp(city, "Hebron") == 0) {
        return 15;
    }


    return -1;
}
const* get_city(int n)
{
     if (n==1) {
        return "Akka";
    } else if (n==2) {
        return "Haifa";
    } else if (n==3) {
        return "Nazareth";
    } else if (n==4) {
        return "Jenin";
    } else if (n==5) {
        return "Bethlehem";
    } else if (n==6) {
        return "Jerusalem";
    } else if (n==7) {
        return "Jaffa";
    } else if (n==8){
        return "Tulkarem";
    } else if (n==9) {
        return "Jericho";
    } else if(n==10){
        return "Qalqilya";
    } else if (n==11) {
        return "Tubas";
    } else if (n==12) {
        return "Nablus";
    } else if (n==13) {
        return "Ramallah";
    } else if (n==14){
        return "Salfit";
    }
    else if (n==15){
        return "Hebron";
    }

    return NULL;
}



void Dijkstra(graph* Graph[MAX][MAX], int start) {
    int distance[MAX], pred[MAX];//predecessor
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    int cost[MAX][MAX];
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (Graph[i][j] == NULL) {
                cost[i][j] = INFINITY;// set unreachable edges to infinity
            } else {
                cost[i][j] = Graph[i][j]->distance;// set edge weight as distance
            }
        }
    }

    for (i = 0; i < MAX; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;//set all nodes as unvisited
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;// number of visited nodes

     // find the node with the minimum distance

    while (count < MAX - 1) {
        mindistance = INFINITY;

        for (i = 0; i < MAX; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < MAX; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // printing the distance for the source and destination cities
    printf("Distance from source to destination: %d\n", distance[destination_index]);

    // drawing the path
    int path[MAX];
    int pathLength = 0;
    int currentNode = destination_index;

    // backtrack from destination to source to find the path
    while (currentNode != start) {
        path[pathLength++] = currentNode;
        currentNode = pred[currentNode];
    }
    path[pathLength++] = start;

    // print the path

    printf("Path: ");
    for (i = pathLength - 1; i > 0; i--) {
        printf("%s -> ", Graph[path[i]][path[i - 1]]->city1);
    }
    printf("%s \n",get_city(destination_index));
    printf("\n\n");



    fprintf(output, "Dijkstra:\n");
    fprintf(output, "Path: ");
    for (i = pathLength - 1; i > 0; i--) {
        fprintf(output, "%s -> ", Graph[path[i]][path[i - 1]]->city1);
    }
    fprintf(output, "%s \n", get_city(destination_index));
    fprintf(output,"Distance from source to destination: %d\n\n", distance[destination_index]);


}


void BFS(graph* Graph[MAX][MAX], int start, const char* destination) {
    char visited[MAX] = {0};
    int distance[MAX];
    int parent[MAX];
    int edges[MAX]; // new array to keep track of the number of edges

    for (int i = 0; i < MAX; i++) {
        distance[i] = INFINITY;
        parent[i] = -1;
        edges[i] = -1; // initialize the edges array
    }

    visited[start] = 1;
    distance[start] = 0;
    edges[start] = 0; // number of edges to start node is 0

    char queue[MAX][20];
    int front = -1;
    int rear = -1;
    strcpy(queue[++rear], get_city(start));

    while (front != rear) {
        int current = getIndex(queue[++front]);

        for (int i = 0; i < MAX; i++) {
            if (Graph[current][i] != NULL && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + Graph[current][i]->distance;
                parent[i] = current;
                edges[i] = edges[current] + 1; // Update the number of edges
                strcpy(queue[++rear], get_city(i));

                if (strcmp(get_city(i), destination) == 0) {
                    // Destination reached, print the path, cost, and number of edges
                    int path[MAX];
                    int pathIndex = 0;
                    int node = i;

                    while (node != start) {
                        path[pathIndex++] = node;
                        node = parent[node];
                    }

                    path[pathIndex++] = start;

                    printf("Path: ");
                    for (int j = pathIndex - 1; j >= 0; j--) {
                        printf("%s", get_city(path[j]));
                        if (j > 0) {
                            printf(" -> ");
                        }
                    }
                    printf("\n");

                    printf("Cost: %d km\n", distance[i]);
                    printf("Number of edges: %d\n", edges[i]);




    while (front != rear) {

        if (strcmp(get_city(i), destination) == 0) {
            // Destination reached, print the path, cost, and number of edges to the file

            fprintf(output, "\nBFS:\n", edges[i]);
            fprintf(output, "Path: ");
            for (int j = pathIndex - 1; j >= 0; j--) {
                fprintf(output, "%s", get_city(path[j]));
                if (j > 0) {
                    fprintf(output, " -> ");
                }
            }
            fprintf(output, "\n");

            fprintf(output, "Cost: %d km\n", distance[i]);
            fprintf(output, "Number of edges: %d\n", edges[i]);



            return;
        }
    }


    fprintf(output, "No path found between the cities.\n\n");


                    return;
                }
            }
        }


    }

    printf("No path found between the cities.\n\n");
}
