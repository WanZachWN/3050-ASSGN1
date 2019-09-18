#include <stdio.h>
#include <stdlib.h>
struct Node{

    int data = 0;
    struct Node *next;
};
struct LinkedList{

    int node_size = 0;
    Node *head = NULL;

};

void push(LinkedList *head, int data){

    Node *current = LinkedList->head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->data = data;
    current->next->next = NULL;
    LinkedList->node_size++;

    return;
}

void it_node(Node *head)
{
    Node *current = head;
    while(current != NULL)
    {
        current = current->next;
    }
}

void eSquared(LinkedList **adj, int size_adj)
{
    for(int v = 1; v < this->V; ++v){

        set<int> *s = new set<int>;
        cout << v << ": ";
        for(int i = this->adj[v].size() - 1; i >= 0; --i){

            int x = this->adj[v][i];
            for(int j = this-> adj[x].size() - 1; j >= 0; --j){

                int y = this->adj[x][j];
                if(y != v)
                s->insert(y);
            }
        }
        for(set<int>::iterator it = s->begin(); it != s->end(); ++it){
            cout << " " << *it;
        }
        cout << endl;
    }
}

int main()
{
    char ch;
    char nameFile[10] = ";Graph.txt";
    FILE *aFile;

    //printf("Enter file name\n");
    //gets(nameFile);

    aFile = fopen(nameFile, "r"); //read file
void eSquared(){
        for(int v = 1; v < this->V; ++v){

            set<int> *s = new set<int>;
            cout << v << ": ";
            for(int i = this->adj[v].size() - 1; i >= 0; --i){

                int x = this->adj[v][i];
                for(int j = this-> adj[x].size() - 1; j >= 0; --j){

                    int y = this->adj[x][j];
                    if(y != v)
                        s->insert(y);
                }
            }
            for(set<int>::iterator it = s->begin(); it != s->end(); ++it){
                cout << " " << *it;
            }
            cout << endl;
        }
    }
    if(aFile != NULL) //if file is able to open read file, display, and G2
    {
        int i = 0;
        int j = 0;

        while(fscanf(aFile,"%d %d", &i, &j) != EOF)
        {
            printf("%d %d\n",i,j);
        }
    }
    else
        printf("Fail to read file. \n");

    fclose(aFile);

    return 0;
}
