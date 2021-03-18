typedef struct NodeList{
    struct Node* firstNode;
    struct Node* lastNode;
    struct NodeList *nextList;
}NodeList;
typedef struct{
    NodeList *firstList,*lastList;
}LinkedList;
typedef struct Node{
    int data;
    struct Node* nextNode;
}Node;
void initiatesEmptyList(LinkedList* nodeList);
void initiatesFieldsOfList(NodeList* nodeList,int n);