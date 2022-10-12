
#include <iostream>

using namespace std;


struct Node{
    int data;
    Node* next;
};

//Function to find intersection point in Y shaped Linked Lists.
/**
 * LinkList1 = 3->6->9->common
 * LinkList2 = 10->common
 * common = 15->30->NULL
 * Output: 15
 */

int intersectPoint(Node* head1, Node* head2) {
    
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    int count1 = 0;
    int count2 = 0;
    
    while(temp1 != NULL) {
        count1++;
        temp1 = temp1->next;
    }
    
    while(temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }
    
    temp1 = head1;
    temp2 = head2;
    
    if(count1 > count2) {
        int diff = count1 - count2;
        while(diff--) {
            temp1 = temp1->next;
        }
    }
    else {
        int diff = count2 - count1;
        while(diff--) {
            temp2 = temp2->next;
        }
    }


    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 == temp2) {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return -1;

}

