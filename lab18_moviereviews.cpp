// COMSC210 | Lab 18 | Winston Jose
// IDE Used: Visual Studio Code
// Github Link: https://github.com/winstonjose01/COMSC210-Lab18-movie 

# include <iostream>
# include <limits>
using namespace std;



struct Node{
    double val;
    string comment;
    Node *next;
};

// Function protototypes
void add_node_front (Node *&);  // Adds a new node at the front of the list  
void add_node_tail (Node *&);   // Adds a new node at the tail of the list
void print_list (Node *&);      // Prints all reviews in the list   
double getrating();             // Prompts the user to input a rating review
string getcomment();            // Propts the user to input a comment review


int main(){
    Node *head = nullptr;   // Initialize the head of linked list
    int choice;             // Vaariable to store the user choice
    cout << "Which linked list method should we use? \n";
    cout << "\t[1] New nodes are added at the head of the linked list\n";
    cout << "\t[2] New nodes are added at the tail of the linked list\n";
    // Input validation for choice
    while(true){
        cout << "Choice :";
        cin >> choice;
 
        if (cin.fail() || choice < 1 || choice > 2){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input, select [1] or [2] only\n"; // Prompt the user for a valid input
        }
        else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch(choice){
                case 1: add_node_front(head); // Add node to the front of the list
                    break;
                case 2: add_node_tail(head);  // Add node to the tail of the list
                    break;
            }
            break; // Exit the loop after processing valid input
    }
    return 0;

    }
}

// add_node_front() adds a new review node to the front of the linked list
// arguments: &head reference to the head of the linked list
// returns: nothing
void add_node_front(Node* &head){
    string choice = "";
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
    cout << "\nOutputting all reviews:\n";
    print_list(head);
}
// add_node_tail() adds a new review node to the end of the linked list
// arguments: &head reference to the head of the linked list
// returns: nothing
void add_node_tail (Node* &head){
    string choice = "";
    while (true){
        Node* newNode = new Node;   // Create a new node
        newNode->next = nullptr;    // Initialize the next ptr to the new node
        newNode->val = getrating(); // Get the review rating from the user
        cin.ignore();
        newNode->comment = getcomment(); // Get the review comment from the user

        if (!head){
            head = newNode;
        }
        else{
            Node* current = head;
            while (current->next){
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "\nEnter another review? Y/N: ";
        getline(cin, choice);
        if (choice == "N" || choice == "n"){
            break;
        }
    }
    cout << "\nOutputting all reviews:\n";
    print_list(head);

}

void print_list(Node* &head){
    double sum_review = 0;
    if (!head){
        cout << "\nThe list is empty";
        return;
    }
    int count = 1;
    Node *current = head;
    while (current){
        cout << "\tReview #" << count++ << " : " << current->val << " : " << current->comment << endl;
        sum_review += current->val;
        current = current->next;
    }
    cout << "\tAverage : " << sum_review / count;
    cout << endl;

}

double getrating(){
    double rating;
    while (true){
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        if (cin.fail() || rating < 0 || rating > 5){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            cout << "\nInvalid input: Please enter number between 0-5\n";
        }
        else
            return rating;
        }
}

string getcomment(){
    string comment;
    cout << "Enter review comments: ";
    getline(cin, comment);
    return comment;
}