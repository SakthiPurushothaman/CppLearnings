#include <iostream>
using namespace std;

struct Node
{
  Node *next;
  int data;

  Node(int data)
  {
    this->next = nullptr;
    this->data = data;
  }
};

Node *createSingleLinkedList(int array[], int size)
{
  Node *head = new Node(array[0]);
  Node *current = head;
  for (int i = 1; i < size; i++)
  {
    current->next = new Node(array[i]);
    current = current->next;
  }
  return head;
}

void printSingleLinkedList(Node *head)
{
  Node *temp = head;

  while (temp != nullptr)
  {

    cout << temp->data << "--->" << " ";
    temp = temp->next;
  }
  cout << "nullptr" << endl;
}

Node *inserLinkedList(Node *head, int position, int data)
{
  Node *new_node = new Node(data);
  Node *temp = head;
  if (temp == nullptr)
  {
    return nullptr;
  }
  if (position == 0)
  {
    new_node->next = temp;
    return new_node;
  }
  int count = 0;
  while (temp != nullptr && count < position - 1)
  {
    temp = temp->next;
    count++;
  }
  new_node->next = temp->next;
  temp->next = new_node;

  return head;
}
void countSingleLinkedList(Node *head)
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }

  cout << "No of nodes in LL" << "  " << count << endl;
}
Node *deleteLinkedList(Node *head, int position)
{
  Node *temp = head;
  if (temp == nullptr)
  {
    return nullptr;
  }
  if (position == 0)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  int count = 0;
  while (temp != nullptr && count < position - 1)
  {
    count++;
    temp = temp->next;
  }
  if (temp->next == nullptr)
  {
    cout << "position out of bound" << endl;
  }

  Node *nodetoDelete = temp->next;
  temp->next = nodetoDelete->next;

  delete nodetoDelete;
  return head;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  Node *Listnode = createSingleLinkedList(arr, size);
  printSingleLinkedList(Listnode);
  Listnode = inserLinkedList(Listnode, 3, 7);
  printSingleLinkedList(Listnode);
  Listnode = inserLinkedList(Listnode, 1, 8);
  printSingleLinkedList(Listnode);
  Listnode = inserLinkedList(Listnode, 2, 9);
  printSingleLinkedList(Listnode);
  Listnode = deleteLinkedList(Listnode, 2);
  printSingleLinkedList(Listnode);
  Listnode = deleteLinkedList(Listnode, 0);
  printSingleLinkedList(Listnode);
  Listnode = deleteLinkedList(Listnode, 1);
  printSingleLinkedList(Listnode);
  countSingleLinkedList(Listnode);
  return 0;
}
