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

void InsertData(Node *&head, string data)
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

void UpdateData(Node *&head, int index, string data)
{

    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no data!!!!\nFirst insert some data to  update it!" << endl;
        return;
    }
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

void AppendData(Node *&head, string data, int index)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There is no data!!!!\nFirst insert some data to  update it!" << endl;
        return;
    }
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
    cout << "Enter you Choice!!!!";
    cout << "-------------------------------------------------------" << endl
         << endl;
}

int SwitchFunctionCall(Node *&head)
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
        InsertData(head, data);
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
        UpdateData(head, index, data);
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
        AppendData(head, data, index);
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
    cout << "Heyyy Welcome to Text Editor!!!!!!!"
         << endl;
    int condition = 1;
    while (condition)
    {
        PrintCatalogMessage();
        condition = SwitchFunctionCall(head);
    }
    return 0;
}