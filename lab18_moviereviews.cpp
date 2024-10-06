// COMSC210 | Lab 18 | Winston Jose
// IDE Used: Visual Studio Code
// Github Link: https://github.com/winstonjose01/COMSC210-Lab18-movie 

# include <iostream>
using namespace std;



struct Node{
    double val;
    string comment;
    Node *next;
};

// Function protototypes
void add_node_front(Node *&);
void add_node_tail


int main(){
    Node *head = nullptr;   // Initialize the head of linked list
    int choice;

    cout << "Which linked list method should we use? \n";
    cout << "\t[1] New nodes are added at the head of the linked list\n";
    cout << "\t[2] New nodes are added at the tail of the linked list\n";
    cout << "Choice :";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1: add_node_front(head);
            break;

    }


}