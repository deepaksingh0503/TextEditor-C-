#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertData1(Node *&head, string data)
{

    Node *node = new Node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}
Node *copyList(Node *head)
{
    Node *newHead = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        string data = temp->data;
        InsertData1(newHead, data);
        temp = temp->next;
    }
    return newHead;
}
void Undo(Node *&head, stack<Node *> &redo, stack<Node *> &undo)
{
    Node *newHead = copyList(head);
    if (undo.empty())
    {
        cout << "Cannot do undo more" << endl;
    }
    else
    {
        redo.push(newHead);
        head = undo.top();
        undo.pop();
    }
}
void Redo(Node *&head, stack<Node *> &redo)
{
    if (redo.empty())
    {
        cout << "cannot redo more!!" << endl;
        return;
    }
    head = redo.top();
    redo.pop();
}
void addToStack(Node *&head, stack<Node *> &undo)
{
    Node *newNode = copyList(head);
    undo.push(newNode);
}
void InsertData(Node *&head, string data, stack<Node *> &undo)
{

    Node *node = new Node(data);

    addToStack(head, undo);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}
void UpdateData(Node *&head, int index, string data, stack<Node *> &undo)
{

    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no data!!!!\nFirst insert some data to  update it!" << endl;
        return;
    }
    addToStack(head, undo);

    while (--index)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "The given index is not avilable please enter an valid index!" << endl;
            return;
        }
    }

    temp->data = data;
}
void SearchInData(Node *&head, string dataToSearch)
{
    if (head == NULL)
    {
        cout << "Not Found" << endl;
    }
    Node *temp = head;
    cout << "The given data found in-----" << endl
         << endl;
    while (temp != NULL)
    {
        if (temp->data.find(dataToSearch) != -1)
        {
            cout << temp->data << endl;
        }
        temp = temp->next;
    }
}
void AppendData(Node *&head, string data, int index, stack<Node *> &undo)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no data!!!!\nFirst insert some data to  update it!" << endl;
        return;
    }
    addToStack(head, undo);

    while (--index)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "The given index is not avilable please enter an valid index!" << endl;
            return;
        }
    }

    temp->data = temp->data + data;
}
void PrintData(Node *&head)
{
    if (head == NULL)
    {
        cout << "No data is avilable Please enter some data first!!!" << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void DeleteData(Node *&head, int index, stack<Node *> &undo)
{
    addToStack(head, undo);

    if (index == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *pre = NULL;

        int count = 1;
        while (count < index)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }

        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void PrintCatalogMessage()
{
    cout << endl
         << endl;
    cout << "Enter 1 to insert data" << endl;
    cout << "Enter 2 to update data" << endl;
    cout << "Enter 3 to apend data" << endl;
    cout << "Enter 4 to print data" << endl;
    cout << "Enter 5 to search in data" << endl;
    cout << "Enter 6 to exit" << endl;
    cout << "Enter 7 to delete a node" << endl;
    cout << "Enter 8 to undo" << endl;
    cout << "Enter 9 to redo" << endl;
    cout << "Enter 10 to save data" << endl;
    cout << "Enter 11 to Open file data" << endl;

    cout << "Enter you Choice!!!!";
    cout << "-------------------------------------------------------" << endl
         << endl;
}
void SaveData(Node *&head, string file)
{
    string fileName = file + ".txt";
    Node *temp = head;
    string data;
    while (temp != NULL)
    {
        data = data + "\n" + temp->data;
        temp = temp->next;
    }
    ofstream
        MyFile(fileName);
    MyFile << data;
    MyFile.close();
}
void CheckSave(Node *&head)
{
    cout << "Want to save the existing file?" << endl;
    cout << "Enter 1 to save and enter 2 to discard" << endl;
    int condition;
    cin >> condition;
    switch (condition)
    {
    case 1:
    {
        string file;
        cout << "Enter the file name!" << endl;
        cin >> file;
        SaveData(head, file);
        break;
    }
    case 2:
        return;
    default:
        break;
    }
}
void OpenFile(Node *&head, string fileName)
{
    string text;
    if (head != NULL)
    {
        CheckSave(head);
    }
    head = NULL;
    ifstream
        MyReadFile(fileName);
    while (getline(MyReadFile, text))
    {
        InsertData1(head, text);
    }
    MyReadFile.close();
}
int SwitchFunctionCall(Node *&head, stack<Node *> &undo, stack<Node *> &redo)
{
    int choice;
    cin >> choice;

    switch (choice)
    {

    case 1:
    {
        cout << "Enter the value to data to be Inserted!" << endl;
        string data;
        string temp;
        getline(cin, temp);
        getline(cin, data);
        InsertData(head, data, undo);
        return 1;
    }

    case 2:
    {
        cout << "Enter the data " << endl;
        string data;
        string temp;
        getline(cin, temp);
        getline(cin, data);
        cout << "Enter the index" << endl;
        int index;

        cin >> index;
        UpdateData(head, index, data, undo);
        return 1;
    }

    case 3:
    {
        cout << "Enter the data " << endl;
        string data;
        string temp;
        getline(cin, temp);
        getline(cin, data);
        cout << "Enter the index" << endl;
        int index;

        cin >> index;
        AppendData(head, data, index, undo);
        return 1;
    }
    case 4:
    {
        PrintData(head);
        return 1;
    }
    case 5:
    {
        cout << "Enter the data you want to search!!" << endl;
        string data;
        getline(cin, data);
        getline(cin, data);
        SearchInData(head, data);
        return 1;
    }
    case 6:
    {
        cout << "Thanks for using!!!" << endl;
        return 0;
    }
    case 7:
    {
        cout << "Enter the index you want to delete!" << endl;
        int index;
        cin >> index;
        DeleteData(head, index, undo);
        return 1;
    }
    case 8:
    {

        Undo(head, redo, undo);
        return 1;
    }
    case 9:
    {

        Redo(head, redo);
        return 1;
    }
    case 10:
    {

        cout << "Enter the file name!!" << endl;
        string fileName;
        cin >> fileName;
        SaveData(head, fileName);
        return 1;
    }
    case 11:
    {

        cout << "Enter the file name to open file!!" << endl;
        string fileName;
        cout << "Enter the complete file name" << endl;
        cin >> fileName;
        OpenFile(head, fileName);
        return 1;
    }
    default:
    {
        cout << "Enter a valid number" << endl;
        return 1;
    }
    }
}
int main()
{
    Node *head = NULL;
    stack<Node *> redo;
    stack<Node *> undo;
    cout << "Heyyy Welcome to Text Editor!!!!!!!"
         << endl;
    int condition = 1;
    while (condition)
    {
        PrintCatalogMessage();
        condition = SwitchFunctionCall(head, undo, redo);
    }
    return 0;
}