#include "MatrizDinamica.h"
#include <stdlib.h>
void initiatesMatrix(LinkedList* linkedList,int m,int n){
    for (int i = 0; i < m; i++)
    {
        initiatesEmptyList(linkedList);
        for (int j = 0; j < n; j++)
        {
            initiatesCell(linkedList);
        }
        
    }
    
}
void initiatesCell(NodeList* nodeList){
    nodeList->lastNode->nextNode = (Node*)malloc(sizeof(Node));
    nodeList->lastNode = nodeList->lastNode->nextNode;
    nodeList->lastNode->nextNode = NULL;
}
void initiatesEmptyList(LinkedList* linkedList){
    NodeList *nodeList = linkedList->firstList;
    nodeList->firstNode = (Node*)malloc(sizeof(Node));
    nodeList->lastNode = nodeList->firstNode;
    nodeList->firstNode->nextNode = NULL;
}
void initiatesLinkedList(LinkedList* linkedList){
    linkedList->firstList = (NodeList*)malloc(sizeof(NodeList));
    linkedList->lastList = linkedList->firstList;
    linkedList->firstList->nextList = NULL;
}