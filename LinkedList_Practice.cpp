
#include <iostream>
using namespace std;
class Node
{
   public:
        int data;       //   ___________
    	Node* next;     //   |Data|Next|    
};                        
class Linkedlist
{
  private:
	Node* head;
	int sumRec(Node* current) const
	{
		if (current == nullptr)
			return 0;

		return current->data + sumRec(current->next); 
	}
	double MultRec(Node *temp)const
	{
		if (temp == nullptr)
			return 1;

		return (  (temp->data)  *  ( MultRec(temp->next) )  );
	}
	
public: 

	 Node* GetHead() 
     {
           return head;
     }

	 Linkedlist() : head(nullptr) {}
	//Linkedlist() 
	//{
	//	head = nullptr;
	//}
	~Linkedlist()
	{
		Node* current = head;

		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	bool isempty() const
	{
		return (head == NULL);
	}
	bool Isfound(int key) const
	{
		Node* temp = head;

		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				return true;
			}

			temp = temp->next;
		}

		return false;
	}
	void Display() const
	{
		Node* temp = head;
		while (temp!=	nullptr)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
	 int getlength() const
	 {
		 int count = 0;
		 Node* current = head;
		 while (current != nullptr)
		 {
			 count++;
			 current = current->next;
		 }return count;

	 }
	
	void InsertFirst(int newvalue)
	{
		Node* newnode= new Node();
		newnode->data = newvalue;
		newnode->next = head;
		head = newnode;
	}
	 void InsertLast(int newvalue)
	 {
		 if (isempty())
			 InsertFirst(newvalue);
		 else
		 {
	         Node* temp = head;
	         Node* newnode = new Node(); 
	         newnode->data = newvalue;
	         while (temp->next!=NULL)
	         {
	        	 temp = temp->next;
	         } 
	         temp->next = newnode;
	         newnode->next = nullptr;
		 }
		
	 }
	 void InsertBefore(int item ,int newvalue)
	 {
		 if (isempty())
			 InsertFirst(newvalue);
		 else if (head->data == item)
		 {
			 InsertFirst(newvalue);
			 return;
		 }
		 else if (Isfound(item))// ntakd an al item aslan mawgod
		 {
			 Node* newnode = new Node();
			 newnode->data = newvalue;
			 Node* temp = head;
			 while (temp->next != nullptr && temp->next->data != item)
			 {
				 temp = temp->next;
			 }
			 newnode->next = temp->next;
			 temp->next = newnode;
		 }
		 else
		 {
			 cout << "sorry , Item Not Found\n";
		 }

	 }
	 int  FindMiddle() const
	 {
		 if (head == nullptr) return -1;
		 Node* slow = head;
		 Node* fast = head;

		 while (fast != nullptr && fast->next != nullptr)
		 {
			 slow = slow->next;
			 fast = fast->next->next;
		 }
		 return slow->data;
	 }
	 void Reverse()
	 {
		 Node* curr = head;
		 Node* prv = nullptr;
		 Node* Next;
		 while (curr != nullptr)
		 {
			 Next = curr->next;
			 curr->next = prv;
			 prv = curr;
			 curr = Next;
		 }
		 head = prv;
	 }
	 void Remove_nth_node_from_end(int nth_node)
	 {
		 int len = getlength();
		 int target = len - (nth_node);

		 if (nth_node <= 0 || nth_node > len)
			 return;

		 if (target == 0)
		 {
			 Node* temp = head;
			 head = head->next;
			 delete temp;
			 return;
		 }

		 Node* temp = head;
		 Node* pre = nullptr;
		 int count = 0;

		 while (temp != nullptr)
		 {
			 if (count == target)
			 {
				 pre->next = temp->next;
				 delete temp;
				 return;
			 }
			 pre = temp;
			 temp = temp->next;
			 count++;
		 }
	 }
	 void delet_dublecated_num()
	 {
		 Node* curent = head;

		 if (isempty() )
			 cout << "LISt is empty sir \n";

		 while (curent != nullptr )
		 {
			 Node* temp = curent->next; ;
			 Node* prev_Of_temp = curent;

			 while (temp != nullptr)
			 {
				 if (temp->data == curent->data)
				 {
					 prev_Of_temp->next = temp->next;
					 delete temp;

					 temp = prev_Of_temp->next;
				 }
				 else
				 {
					 prev_Of_temp = temp;
					 temp = temp->next;
				 }
			 }
			 curent = curent->next;
		 }

	 }
	 int minnum() const
	 {
		 if (isempty())
			 return -1;
		 
		 Node* curr = head;
		 int min = curr->data;
		 while (curr != nullptr)
		 {
			 if (curr->data <min)
			 {
				 min = curr->data;
			 }
			 curr = curr->next;
		 }
			 return min;
	 }
	 int maxnum() const
	 {
		 if (isempty())
			 return -404;
		 Node* curr = head;
		 int max = curr->data;
		 while (curr != nullptr)
		 {
			 if (curr->data > max)
			 {
		       max =curr->data ;
			 }
			 curr = curr->next;
		 }
			 return max;
	 }
	 double Mult() const
	 {
		 return MultRec(head);
	 }
	 int sum_of_list() const
	 {
		 int s = 0;
		 Node* current = head;
		 while (current != nullptr)
		 {
			 s += current->data;
			 current = current->next;
		 }return s;
	 }
	 int sum() const
	 {
		 return sumRec(head);
	 }
	 void del_Even_Num()
	 {
		 Node* current = head;
		 Node* prev = nullptr;
		 while (current != nullptr)
		 {
			 if (current->data % 2 == 0 &&prev == nullptr )
			 {	 
					  head= current->next;
					 delete current;
					 current = head;
			 }
			 else if (current->data % 2 == 0)
			 {
				 prev->next = current->next;
				 delete current;
				 current = prev->next;
			 }
			 else
			 {
				 prev = current;
				 current = current->next;
			 }
		 }
	 }
	 void del_by_val(int value)
	 {
		 if (isempty())
		 {
			 cout << "list is empty , no item";
			 return;
		 }

		 Node* delptr = head;
		 Node* prv = nullptr;

		 while (delptr != nullptr && delptr->data != value)
		 {
			 prv = delptr;
			 delptr = delptr->next;
		 }

		 if (delptr == nullptr)
		 {
			 cout << "item not found\n";
			 return;
		 }

		 if (prv == nullptr) // meaning head is the target
		 
			 head = head->next;
		 
		 else
		 {
			 prv->next = delptr->next;
		 }
		 delete delptr;
	 }
	 void Remove_nth_node(int nth_node)
	 {
		
		 if (nth_node == 0)
		 {
			 Node* temp = head;
			 head = head->next;
			 delete temp;
			 return;
		 }
		 Node* temp = head;
		 Node* prv = nullptr;
		 int count = 0;
		 while (temp != nullptr)
		 {
			 if (count == nth_node)
			 {
				 prv->next = temp->next;
				 delete temp;
				 return;
			 }
			 prv = temp;
			 temp = temp->next;
			 count++;
		 }
	 }
	 void Remove_all_elements_less_than_x(int x)
	 {
		 if (isempty())
		 {
			 cout << "empty"; return;
		 }
		 while (head != nullptr && head->data < x)
		 {
			 Node* temp = head;
			 head = head->next;
			 delete temp;
		 }
	     Node* current = head;
		 Node* prv = nullptr;
		 while (current != nullptr)
		 {
			 if (current->data<x)
			 {
				 prv->next = current->next;
	     		 delete current;
				 current=  prv->next ;
			 }
			 else
			 {
				 prv = current;
				 current = current->next;
			 }
		 }
	 }
	 void Remove_all_elements_greater_than_x(int x)
	 {
		 
		 if (isempty())
		 {
			 cout << "list is empty";
			 return ;
		 }
		 while (head!= nullptr &&head->data>x)
		 {
			 Node* current = head;
			 head = head->next;
			 delete current;
		 }
		 Node* temp = head;
		 Node* prv = nullptr;
		 while (temp!=nullptr)
		 {
			 if (temp->data>x)
			 {
				 prv->next = temp->next;
				 delete temp;
				 temp = prv->next;
			 }
			 else
			 {
				 prv = temp;
				 temp = temp->next;
			 }
		 }
	 }
	 void Remove_Between(int x,int y)
	 {
		 if (isempty())
		 {
			 cout << "list is empty";
			 return;
		 }
		 if (x>y)
			 swap(x, y);

		 while (head != nullptr && (head->data > x&& head->data < y ))
		 {
			 Node* temp = head;
			 head = head->next;
			 delete temp;
		 }
		 Node* temp = head;
		 Node* prv = nullptr;
		 while (temp != nullptr)
		 {
			 if ((temp->data > x && temp->data < y))
			 {
				 prv->next = temp->next;
				 delete temp;
				 temp = prv->next;
			 }
			 else
			 {
				 prv = temp;
				 temp = temp->next;
			 }
		 }
	 }
};

int getmax_non_member(Linkedlist& list) 
{
	if (list.GetHead() == nullptr)
		return -404;

	Node *current = list.GetHead();
	int max = current->data;

	while (current != nullptr)
	{
		if (current->data>max)
			max = current->data;
		
		current = current->next;
	}
	return max;
}
int getmin_non_member(Linkedlist& list)
{
	if (list.GetHead() == nullptr)
		return -404;

	Node* current = list.GetHead();
    int min = current->data;
	while (current != nullptr)
	{
		if (current->data<min)
			min = current->data;

		current = current->next;
	}
	return min;
}
double getAvg_non_member(Linkedlist& list)
{
	Node* current = list.GetHead();
	double sum = 0;
	double length = 0;
	while (current != nullptr)
	{
		sum = sum + current->data;
		current=current->next;
		length++;
	}
	if (length == 0)
		return -404;

	return sum / length;
}
int main()

{
	Linkedlist list; // object asmo list


	list.InsertLast(3);
	list.InsertLast(6);
	list.InsertLast(7);
	list.InsertLast(5);
	list.InsertLast(8);
	list.InsertLast(10);
	cout << endl;
	list.Display();
	cout << endl;
	cout<<list.Mult();
    cout << endl;
	cout<<list.sum();
	cout << endl;
	//cout << getAvg_non_member(list);
}
