#include <iostream>
#include <fstream>

using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node *head;
public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert data into the linked list
    void insert(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }


    // Function to display the linked list
    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to move a node with given value to the front of the linked list
    int moveToFront(int value) {
        Node *curr = head;
        Node *prev = nullptr;
        int steps = 0;


        // Traverse the linked list to find the node with the given value
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
            steps++;
        }


        // If the node is found, move it to the front
        if (curr) {
            if (prev) {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                steps++; // Increment steps by one for the move
            }
            return steps;
        } else {
            return -1; // Node with the given value not found
        }
    }


    int transpose(int value) {
        Node *curr = head;
        Node *prev = nullptr;
        int steps = 0;


        // Traverse the linked list to find the node with the given value
        while (curr && curr->data != value) {
            prev = curr;
            curr = curr->next;
            steps++;
        }
        //If the node is the lead of the list then only add one step, if it is second in the list only add two steps and move it forward one step, if it is third in the list add three steps and move it forward one step, etc
        if (curr && prev) {
            Node *prevPrev = nullptr;
            if (prev != head) {
                prevPrev = head;
                while (prevPrev->next != prev) {
                    prevPrev = prevPrev->next;
                }
                prevPrev->next = curr;
                prev->next = curr->next;
                curr->next = prev;
                steps += 1; // Increment steps by two for the move
            } else {
                head = curr;
                prev->next = curr->next;
                curr->next = prev;
                steps++; // Increment steps by one for the move
            }
            return steps;
        } else {
            steps += 1;
            return steps; // Node with the given value not found
        }
    }

// Function to read data from file and store in linked list
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            int num;
            LinkedList reversedList; // Create a temporary linked list to store data in reverse order
            while (file >> num) {
                reversedList.insert(num); // Insert each element at the beginning of the temporary list
            }
            file.close();

            // Copy data from temporary list to current list
            while (reversedList.head) {
                insert(reversedList.head->data); // Insert each element from the temporary list into the current list
                Node* temp = reversedList.head;
                reversedList.head = reversedList.head->next;
                delete temp; // Free memory of temporary list nodes
            }
        } else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
    // Function to read data from file and store in linked list
};

int main(int argc, char* argv[]) {
    LinkedList list;
    list.readFromFile("validation2.txt");


    int heuristic = stoi(argv[1]);
    string requestF = argv[2];
    string data = argv[3];

    ifstream myfile1(data);
    if (myfile1.is_open()) {
        int num;
        while (myfile1 >> num) {
            list.insert(num);
        }
        myfile1.close();
    } else {
        cerr << "Unable to open file: " << data << endl;
        return 1;
    }
    //make linked list with data from file
    list.display();

    if (heuristic != 0 && heuristic != 1) {
        cerr << "Invalid choice of heuristic. Exiting..." << endl;
        return 1;
    }

    // Initialize the list with the data "0123456789"
    for (int i = 9; i >= 0; --i) {
        list.insert(i);
    }

    int totalSteps = 0;

    // Apply the selected heuristic to each value in validation1.txt
    ifstream requestFile(requestF);
    if (requestFile.is_open()) {
        char num;
        while (requestFile >> num) {
            int value = num - '0'; // Convert char to int
            int steps;
            if (heuristic == 0) {
                steps = list.moveToFront(value);
            } else if (heuristic == 1) {
                steps = list.transpose(value);
            }
            if (steps == -1) {
                cout << "Value " << value << " not found in the list." << endl;
            } else {
                totalSteps += steps;
                cout << (heuristic == 0 ? "Move-to-Front" : "Transpose") << ": Moved value " << value << " in " << steps
                     << " steps." << endl;
            }
        }
        requestFile.close();
    } else {
        cerr << "Unable to open file: request file" << endl;
        return 1;
    }

    // Output the total steps for the selected heuristic
    if (heuristic == 0) {
        cout << "Total steps: " << totalSteps + 1 << endl;
    }else if(heuristic == 1){
        cout << "Total steps: " << totalSteps << endl;
    }
    return 0;
}


