#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    int n;
    struct Node *head;
};

struct LinkedList* push(struct LinkedList *list, int data)
{
	if (list == NULL)
	{
		list = malloc(sizeof(struct LinkedList));
		list->n = 0;
		list->head = malloc(sizeof(struct Node));
		list->head->data = data;
		list->head->next = NULL;
		return list;
	}
	
    struct Node *current = list->head;
    while (current->next != NULL)
    {
    	if (current->data == data)
    	{
    		return list;
		}
		
        current = current->next;
    }

    current->next = malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;
    list->n = list->n + 1;

    return list;
}

int get(struct LinkedList *list, int n)
{
	int i;
	struct Node *current = list->head;
	
	for(i = 0; i < n; i++)
	{
		if (current != NULL)
		{
			current = current->next;
		}
		else
		{
			return -1;
		}
	}
	
	return current->data;
}

struct Node* find(struct LinkedList *list, int key)
{
	printf("k%d\n", key);
	struct Node *current = list->head;
	while (current != NULL)
	{
		if (current->data == key)
		{
			return current;
		}
		current = current->next;
	}
	
	return current;
}

void eSquared(struct LinkedList **adj, int V)
{
	int v;
    for (v = 1; v < V; ++v)
	{
		int i;
		struct Node *current;
        struct LinkedList *set = NULL;
        
        printf("%d:", v);
        for (i = adj[v]->n - 1; i >= 0; --i)
		{
			int j;
            int x = get(adj[v], i);
            for (j = adj[x]->n - 1; j >= 0; --j)
			{

                int y = get(adj[x], j);
                if (y != v)
                {
                	set = push(set, y);
				}
            }
        }
        
        current = set->head;
        while (current != NULL)
		{
            printf(" %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    char ch;
    char nameFile[10] = "Graph.txt";
    FILE *aFile;
    int V = 0;
    int i;
    struct LinkedList **adj;
    
    aFile = fopen(nameFile, "r"); /*read file*/
    int temp = 0;
    while(fscanf(aFile,"%d ", &temp) != EOF)
    {
        if (temp > V)
        {
        	V = temp;
		}
    }
    fclose(aFile);
    
    adj = malloc((V + 1) * sizeof(struct LinkedList));
    for (i = 0; i <= V; i++)
    {
    	adj[i] = NULL;
	}
    
    aFile = fopen(nameFile, "r"); /*read file*/
    if(aFile != NULL) /*if file is able to open read file, display, and G2*/
    {
        int i = 0;
        int j = 0;

		printf("input:\n");
        while(fscanf(aFile,"%d %d", &i, &j) != EOF)
        {
            printf("%d %d\n",i,j);
            adj[i] = push(adj[i], j);
        }
        
        printf("output:\n");
        eSquared(adj, V);
    }
    else
        printf("Fail to read file. \n");

    fclose(aFile);

    return 0;
}
