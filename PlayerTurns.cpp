//This program demonstrates how a circular
//linked list may be used to rotate through
//players in a turn-based game
//Kodi Lein
#include <iostream>

struct node 
{
    char name[10];
    struct node* next;
};

//The circular linked list tail pointer
struct node* tail = NULL;

void addNode(struct node* newnode) 
{
    //List empty, create new list
    if (tail == NULL) 
    {
        tail = newnode;
        newnode->next = tail;
    }
    else 
    {
        //Add at tail
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

int main() 
{
    int i;
    char players[4][10] =  //array for 4 players allowed 10 characters each
    {
      "Joanie", "Simon", "Sasha", "Perry"
    };

    //Use this node for traversing the list.
    struct node* current;

    //Create a circularly linked list for the players
    for (i = 0; i < 4; i++) 
    {
        //Create node for each of the players in the players array
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));
        strcpy_s(newnode->name, players[i]);

        //Add the 4 players to the queue
        addNode(newnode);
    }
    
    //Set first node
    current = tail->next;

    //loop through list twice
    for (i = 0; i < 8; i++)
    {
        std::cout << "\nIt's your turn: ";
        std::cout << current->name;
        //traverse list
        current = current->next;
    }
}