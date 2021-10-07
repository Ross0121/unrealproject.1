/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x){
    struct Node* current=NULL;
    struct Node* current1=NULL;
    current=head;
    current1=head->next;
    
    if(x==1)
        return head->next;
        
    for(int i=1; i<x-1; i++){
        current=current->next;
        current1=current1->next;
    }
    current->next = current->next->next; //or current->next=current1->next;
    delete current1;
    
    return head;
}
