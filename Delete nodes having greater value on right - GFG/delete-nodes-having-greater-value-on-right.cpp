//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node * reverse(Node * &head)
    {
        Node * curr = head;
        Node * prev = NULL;
        Node * forward = curr;
        
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node * temp = new Node(0);
        Node * ans = temp;
        
        int x = head->data;
        
        while(head != NULL)
        {
            while(head != NULL && head->data < x) head = head->next;
            if(head == NULL)
            {
                temp->next = NULL;
                break;
            }
            x = head->data;
            //cout<<x<<endl;
            temp->next = head;
            temp = temp->next;
            head = head->next;
        }
        
       return reverse(ans->next);
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends