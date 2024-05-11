#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

//Task1 Hospital Emergency Room

class Patient{

private:
    string name;
    int age;
    string condition;
    int priority;

public:
    Patient(){
        name = " ";
        age = 0;
        condition = " ";
        priority = 0;
    }

    Patient(string n, int a , string c,int p) {
        name = n;
        age = a;
        condition = c;
        priority = p;
    }

    friend class PatientQueue;
};


class PatientQueue{

private:

    struct Node{
        Patient patient;
        Node *next;
    };

    Node *front;
    Node *rear;
    int length;

public:


    PatientQueue(){
        front = rear = nullptr;
        length = 0;
    }


    bool isEmpty(){    // isEmpty function
        if (rear == nullptr) {
            return true;
        }

        else {
            return false;
        }
    }


    void EnqueueSort(Patient p){
        Node *newNode = new Node; // Allocate memory for newNode
        newNode->patient = p;
        newNode->next = nullptr;

        if (isEmpty() || p.priority > front->patient.priority) {
            newNode->next = front;
            front = newNode;

            if (rear == nullptr) {
                rear = front;
            }
        }

        else {
            Node *current = front;
            Node *prev = nullptr;

            while (current != nullptr && p.priority <= current->patient.priority) {
                prev = current;
                current = current->next;
            }

            prev->next = newNode;
            newNode->next = current;

            if (current == nullptr) {
                rear = newNode;
            }
        }

        length++;
    }

    void Display(){   //Display function

        if (isEmpty()) {
            cout << "queue is empty\n";
        }

        else {
            Node *current = front;
            cout << "Patients in the Queue are: \n";
            while (current != nullptr) {
                cout << current -> patient.name << " " << current -> patient.age << " " << current ->patient.condition << " " << current -> patient.priority<<endl;
                current = current -> next;
            }
            cout << endl;
        }
    }


    void Process(){
        if (isEmpty()) {
            cout << "queue is empty nothing to process\n";
        }

        else {

            cout << "Processing Patient...\n";
            cout << "processing patient: " << front ->patient.name << "( Priority: " << front ->patient.priority << " )\n";
            Node * current = front;
            front = front -> next;
            delete current;
            length --;
            if (length == 0) {
                front = nullptr;
                rear = nullptr;
            }

        }
    }


    void Update(string name,string newCondition) {
        Node *current = front;

        while (current != nullptr && current -> patient.name != name) {
            current = current -> next;
        }

        if (current == nullptr) {
            cout << "Patient not found\n";
            return;
        }

        else {

            int newPriority ;
            if (newCondition == "critical") {
                newPriority = 3;
            }

            else if (newCondition == "urgent") {
                newPriority = 2;
            }

            else if (newCondition == "normal"){
                newPriority = 1;
            }

            if (newPriority == current -> patient.priority) {
                cout << "That the same condition Patient will remain same\n";
                return;
            }

            current -> patient.condition = newCondition;
            current -> patient.priority = newPriority;

            Patient UpdatePatient = current -> patient;
            Node *prev= nullptr;
            Node *tmp = front;

            while (tmp != current) {
                prev = tmp;
                tmp = tmp -> next;
            }

            if (prev == nullptr) {
                front = front -> next;
            }
            else {
                prev -> next = current -> next;
            }

            delete current;
            length--;

            EnqueueSort(UpdatePatient);
            cout << "Condition of Patient " << UpdatePatient.name << " updated to " << UpdatePatient.condition<<endl;

        }
    }

    int QueueSize(){
        return length;
    }

    string FrontName() {
        if (isEmpty()) {
            string error = "Error Cant retrieve anything from an empty queue :(";
            throw error;
        }
        else {
            return front -> patient.name;
        }
    }


};


int calcPriority(string condition) {

    int priority;

    if (condition == "critical") {
        priority = 3;
    }

    else if (condition == "urgent") {
        priority = 2;
    }

    else {
        priority = 1;
    }


    return priority;

}

void printMenu(){

    cout << "----------------------------------------------\n";
    cout << "          Patient System           \n";
    cout << "1- Add Patients to Queue \n";
    cout << "2- Display Patients in Queue\n";
    cout << "3- Process Patient\n";
    cout << "4- Update Patient Condition\n";
    cout << "5- Get size of the Queue\n";
    cout << "6- Get Data of the first Patient in the Queue\n";
    cout << "7- Exit\n";
    cout << "---------------------------------------------\n";


}


//Task2
struct variable
{
    string  name;
    string datatype;
    string value;
    variable *next;
};


class variableStack
{
private:
    struct  Node
    {
        variable  data;
        Node *next;
    };

    Node *top;
    int capacity;

public:


    variableStack()
    {
        capacity = 5;
        top = NULL;
    }
    ~variableStack()
    {
        while (top !=NULL)
        {
            Node *tmp = top;
            top = top->next;
            delete tmp;
        }
    }
    void push(const variable& var)
    {
        Node *newitemptr = new Node;
        if(newitemptr == NULL)
        {
            cout<<"Stack push cannot allocate memory";
        }
        else
        {
            newitemptr->data = var;
            newitemptr->next = top;
            top = newitemptr;
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }

    variable pop()
    {
        if (isEmpty())
        {
            return  variable();
        }
        Node * temp = top;
        variable stacktop = temp->data;
        top = top->next;
        delete temp;
        return  stacktop;
    }

    void processFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        variable* top = nullptr;
        string line;
        variableStack variablestackk;
        vector<string> lines;

        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();

        for (int i = lines.size() - 1; i >= 0; --i)
        {
            line = lines[i];
            if (line.find('=') == -1) {

                string datatype;
                string name;
                bool foundDataType = false;
                bool foundName = false;

                for (char c : line)
                {
                    if (!foundDataType)
                    {
                        if (c != ' ')
                        {
                            datatype += c;
                        } else {
                            foundDataType = true;
                        }
                    } else if (!foundName)
                    {
                        if (c != ' ' && c != ';')
                        {
                            name += c;
                        } else if (c == ';')
                        {
                            foundName = true;
                        }

                        variable v;
                        v.name = name;
                        v.datatype = datatype;
                        variablestackk.push(v);
                    } else {

                        datatype.clear();
                        name.clear();
                        foundDataType = false;
                        foundName = false;
                    }
                }
            } else
            {

                processLine(top, line);
            }
        }
    }

    void processLine(variable* top, const string& line)
    {
        string word;

        int pos = line.find(' ');
        if (pos == -1)
        {
            return;
        }

        word = line.substr(0, pos);

        if (word == "int" || word == "double" || word == "float" || word == "char")
        {
            variable var;
            var.datatype = word;
            size_t nameStart = line.find_first_not_of(" \t", pos);
            int equalPos = line.find('=', nameStart);
            if (equalPos != -1)
            {
                var.name = line.substr(nameStart, equalPos - nameStart);
                var.value = line.substr(equalPos + 1);
            } else
            {
                var.name = line.substr(nameStart);
            }
            push(var);
        } else if (word == "return")
        {
            while (top != nullptr)
            {
                pop();
            }
        } else
        {
            int equalPos = line.find('=');
            if (equalPos != -1)
            {
                string varName = line.substr(0, equalPos);
                string value = line.substr(equalPos + 1);

                variable* current = top;
                while (current != nullptr)
                {
                    if (current->name == varName)
                    {
                        current->value = value;
                        break;
                    }
                    current = current->next;
                }
            }
        }
    }
    void updateVariables(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (line.find('=') != -1)
            {
                stringstream ss(line);
                string varName, value;
                ss >> varName;
                ss.ignore(1);
                getline(ss, value);


                Node* current = top;
                while (current != nullptr) {
                    if (current->data.name == varName)
                    {
                        current->data.value = value;
                        break;
                    }
                    current = current->next;
                }
            }
        }
        file.close();
    }


    void displayStack()
    {

        if (top == nullptr)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        variableStack tempStack;

        while (current != nullptr)
        {

            tempStack.push(current->data);

            Node* displayCurrent = tempStack.top;
            cout << "Stack Contents:\n";
            while (displayCurrent != nullptr)
            {
                cout << "Name: " << displayCurrent->data.name << ", Type: " << displayCurrent->data.datatype << ", Value: " << displayCurrent->data.value << endl;
                displayCurrent = displayCurrent->next;
            }
            cout << endl;

            current = current->next;
        }
    }

};
int main() {

    //task1
    cout<<"1-Task1 "<<endl;
    cout<<"2-Task2 "<<endl;
    int choice;
    cout<<"Choose what You want: "<<endl;
    cin>>choice;

    if(choice == 1) {


        PatientQueue queue;
        string name;
        int age;
        string condition;
        int priority;


        printMenu();
        int choice;
        bool flag = true;
        cout << "Choose from the Menu\n";
        cin >> choice;

        while (flag) {

            if (choice == 1) {
                cout << "Enter Patient info please\n";
                cout << "Name: ";
                cin >> name;
                cout << "Age: ";
                cin >> age;
                cout << "Condition: ";
                cin >> condition;
                priority = calcPriority(condition);
                Patient p(name, age, condition, priority);
                queue.EnqueueSort(p);
                printMenu();
                cin >> choice;
            }

            if (choice == 2) {
                queue.Display();
                printMenu();
                cin >> choice;
            }

            if (choice == 3) {
                queue.Process();
                printMenu();
                cin >> choice;
            }

            if (choice == 4) {
                cout << "Enter name and the new condition of the patient:\n";
                cout << "Name: ";
                cin >> name;
                cout << "New-Condition:";
                cin >> condition;
                queue.Update(name, condition);
                printMenu();
                cin >> choice;
            }

            if (choice == 5) {
                cout << "There are " << queue.QueueSize() << " Patients in the Queue\n";
                printMenu();
                cin >> choice;
            }

            if (choice == 6) {

                try {
                    cout << "Most urgent Patient name is : " << queue.FrontName() << endl;
                }
                catch (string notfound) {
                    cout << "error " << notfound << endl;
                }
                printMenu();
                cin >> choice;
            }

            if (choice == 7) {
                cout << "Exiting the system :)\n";
                flag = false;
            }
        }
    }

    else {


        //task2
        variableStack stack;
        stack.processFile("code.txt");

        stack.displayStack();
        stack.updateVariables("code.txt");
        stack.displayStack();
    }


    return 0;
}


//
//// Function declaration: processFile takes a constant reference to a string filename and returns void
//void processFile(const string& filename)
//{
//    // Declare and open an input file stream object named 'file' with the provided filename
//    ifstream file(filename);
//
//    // Check if the file failed to open
//    if (!file.is_open())
//    {
//        // If file opening failed, print an error message to standard error stream (cerr) and return from the function
//        cerr << "Error opening file: " << filename << endl;
//        return;
//    }
//
//    // Declare a pointer to a 'variable' object named 'top' and initialize it to nullptr
//    variable* top = nullptr;
//
//    // Declare a string variable named 'line' to store each line read from the file
//    string line;
//
//    // Declare an object of type 'variableStack' named 'variablestackk'
//    variableStack variablestackk;
//
//    // Declare a vector of strings named 'lines' to store each line of the file
//    vector<string> lines;
//
//    // Read each line from the file using 'getline' and store it in the 'lines' vector
//    while (getline(file, line))
//    {
//        lines.push_back(line);
//    }
//
//    // Close the file after reading all lines
//    file.close();
//
//    // Iterate through the 'lines' vector in reverse order
//    for (int i = lines.size() - 1; i >= 0; --i)
//    {
//        // Assign the current line being processed to the 'line' variable
//        line = lines[i];
//
//        // Check if the line does not contain '='
//        if (line.find('=') == -1)
//        {
//            // Declare variables to store datatype and name of the variable being parsed
//            string datatype;
//            string name;
//
//            // Flags to track whether datatype and name have been found
//            bool foundDataType = false;
//            bool foundName = false;
//
//            // Iterate through each character of the line
//            for (char c : line)
//            {
//                // If datatype is not found yet
//                if (!foundDataType)
//                {
//                    // If the character is not a space, append it to datatype
//                    if (c != ' ')
//                    {
//                        datatype += c;
//                    }
//                        // If the character is a space, set foundDataType to true
//                    else
//                    {
//                        foundDataType = true;
//                    }
//                }
//                    // If datatype is found but name is not
//                else if (!foundName)
//                {
//                    // If the character is neither a space nor a semicolon, append it to name
//                    if (c != ' ' && c != ';')
//                    {
//                        name += c;
//                    }
//                        // If the character is a semicolon, set foundName to true
//                    else if (c == ';')
//                    {
//                        foundName = true;
//                    }
//
//                    // Create a variable object with the parsed datatype and name, and push it onto the variable stack
//                    variable v;
//                    v.name = name;
//                    v.datatype = datatype;
//                    variablestackk.push(v);
//                }
//                    // If both datatype and name are found
//                else
//                {
//                    // Clear datatype, name, and reset the flags for the next variable parsing
//                    datatype.clear();
//                    name.clear();
//                    foundDataType = false;
//                    foundName = false;
//                }
//            }
//        }
//            // If the line contains '=', call the 'processLine' function
//        else
//        {
//            processLine(top, line);
//        }
//    }
//}
