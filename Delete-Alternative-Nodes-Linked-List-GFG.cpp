//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};
// } Driver Code Ends


/*
Structure of the node of the binary tree
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};
*/



// Complete this function
class Solution{
    public:
    void deleteAlt(struct Node *head){
        
        //base case 
        if(head == NULL){
            return ;
        }
        
        //Hare and the Tortoise Approach 
        struct Node* a = head;  //previous node 
        struct Node* b = head -> next;   //current node
        
        //Basic Condition Checked
        while(a!=NULL && b!=NULL){
            
            //Change next link of preview node 
            a -> next = b -> next;
            
            //free node 
            free(b);
            
            //Update previous node 
            a = a -> next;
            
            //Update both nodes
            if(a != NULL){
                b = a -> next;
            }
        }
        
        
    }
};
