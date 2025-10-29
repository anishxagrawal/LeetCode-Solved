/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = NULL;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL; // handle empty list

        Node* temp1 = head; // pointer to traverse the original list
        Node* res = new Node(0); // dummy node to simplify construction of copied list
        Node* temp2 = res; // pointer to keep track of the last node in copied list

        // Map to store the correspondence between original nodes and their copies
        unordered_map<Node*, Node*> hash;

        // First pass: create copies of nodes and store mapping in hash
        while (temp1 != NULL){
            Node* newNode = new Node(temp1->val); // create new node with same value
            temp2->next = newNode; // attach copied node to the copied list
            hash[temp1] = newNode; // map original node -> copied node

            // Move to next nodes in original and copied lists
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Second pass: assign random pointers for the copied nodes
        temp1 = head;
        temp2 = res->next;

        while(temp1 != NULL){
            // Set random pointer using the hash map
            // If original node's random is NULL, copied node's random will also be NULL
            temp2->random = temp1->random ? hash[temp1->random] : NULL;

            // Move to next nodes in both lists
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Return the head of the copied list (skip the dummy node)
        return res->next;
    }
};
