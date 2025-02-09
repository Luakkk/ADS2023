#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node *cur = head;
    while(cur){
        while(cur->next and cur->data == cur->next->data){
            if(cur->next->next){
                cur->next = cur->next->next;
            }
            else{
                cur->next = NULL;
            }
        }
        cur = cur->next;
    }
}
  

int getCount(Node* head)  
{  
    int count = 0; 
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count += 1;
    }
    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}