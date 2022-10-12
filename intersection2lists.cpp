// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1


#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {

    int data;
    Node *next;

    Node(int val) {
        data=val;
        next=NULL;
    }

};

Node* inputList(int size) {

    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size) {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n) {
    
    while(n) {
        cout<< n->data << " ";
        n = n->next;
    }

}


/**
 * Input:
 * LinkedList1: 9->6->4->2->3->8
 * LinkedList2: 1->2->8->6
 * Output: 6 2 8
 */

class Solution{

  public:
    Node* findIntersection(Node* head1, Node* head2) {

        unordered_map<int, int> m;
       
        Node* temp = head2;
        while(temp != NULL) {
            m[temp->data]++;
            temp = temp->next;
        }

        Node* head = NULL;
        Node* tail = NULL;
        temp = head1;

        while(temp != NULL){

            // if the element is present in the map(also, in the second list)
            if(m[temp->data] > 0){

                if(head == NULL){
                    head = tail = new Node(temp->data);
                }else{
                    tail->next = new Node(temp->data);
                    tail = tail->next;
                }
            }
            
            temp = temp->next;
        }

        return head;
    }
};

