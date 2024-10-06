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
void add_node_front (Node *&);
void add_node_tail (Node *&);
double getrating();
string getcomment();



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
        case 2: add_node_tail(head);
            break;

    }
    
    return 0;

}

// add_node_front() adds a new review node to the front of the linked list
// arguments: &head reference to the head of the linked list
// returns: nothing
void add_node_front(Node* &head){
    string choice;
    while (true){
        Node *newNode = new Node;
        newNode->val = getrating();
        cin.ignore();
        newNode->comment = getcomment();
        newNode->next = head;
        head = newNode;

        cout << "\nEnter another review? Y/N: ";
        getline(cin, choice);
        if (choice == "N" || choice == "n"){
            break;
        }
    }
}

void add_node_tail (Node* &head){
    
}

double getrating(){
    double rating;
    cout << "Enter review rating 0-5: ";
    cin >> rating;
    return rating;
}

string getcomment(){
    string comment;
    cout << "Enter review comments: ";
    getline(cin, comment);
    return comment;
}