#include <stdio.h>

typedef struct node
{
               int item;
               struct node *nextNode;
} Node;

Node* createLinkedList()
{
      return NULL;
}

int isEmpty( Node *first )
{
    return (first == NULL);
}

Node* insertNode( Node *first, int item )
{
      Node *newNode = (Node *) malloc( sizeof(Node) );
      newNode->item = item;
      newNode->nextNode = first;
      return newNode;
}

void printLinkedList( Node *first )
{
     Node *p;
     for( p = first; p != NULL; p = p->nextNode )
     {
          printf( "%d\n", p->item );
     }
}

Node* searchNode( Node *first, int item )
{
      Node *p;
      for( p = first; p != NULL; p = p->nextNode)
      {
           if( p->item == item )
           {
               return p;
           }
      }
      return NULL;
}

Node* removeNode( Node *first, int item )
{
      Node *previous = NULL;
      Node *current = first;
      while( current != NULL && current->item != item )
      {
             previous = current;
             current = current->nextNode;
      }if( current == NULL )
      {
           return first;
      }if( previous == NULL )
      {
           first = current->nextNode;
      }else
      {
           previous->nextNode = current->nextNode;
      }
      free( current );
      return first;
}

int main()
{
    Node* list = createLinkedList();
    Node* achado = createLinkedList();
    
    list = insertNode(list, 3);
    list = insertNode(list, 9);
    list = insertNode(list, 27);
    list = insertNode(list, 81);
    list = insertNode(list, 243);
    
    printf( "Complete List: \n" );
    
    printLinkedList( list );
    
    achado = searchNode(list, 9);
    
    printf( "Found: \n" );
    
    printLinkedList( achado );
    
    achado = searchNode( list, 40 );
    
    printf( "Found: \n" );
    
    printLinkedList( achado );
    
    list = removeNode( list, 9 );
    list = removeNode( list, 243 );
    printLinkedList( removeNode( NULL, 3 ) );
    
    printf( "Complete List: \n" );
    
    printLinkedList( list );
    
    getche();
    
    return 1;
}
