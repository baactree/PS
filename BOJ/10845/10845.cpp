#include <iostream>
#include <string>
using namespace std;
int a[2];
int cnt;
class Node
{
	public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data=data;
		next=0;
	}
	void setData(int data)
	{
		this->data=data;
	}
	void setNext(Node *next)
	{
		this->next=next;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
};
class List
{
	public:
	Node *head;
	Node *now;
	List()
	{
		head=0;
		now=head;
	}
	void push(int data)
	{
		if(head==0)
		{
			head=new Node(data);
			now=head;
		}
		else
		{
			Node *newNode=new Node(data);
			now->setNext(newNode);
			now=newNode;
		}
	}
	void empty()
	{
		if(head==0)
		cout<<1<<endl;
		else
		cout<<0<<endl;
	}
	void size()
	{
		if(head==0)
			cout<<0<<endl;
			else
			{
		int cnt=1;
		Node *temp;
		temp=head;
		while(temp->getNext()!=0)
		{
			cnt++;
			temp=temp->getNext();
		}
		cout<<cnt<<endl;
	}
	}
	void front()
	{
			if(head==0)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<head->getData()<<endl;
			}		
	}
	void back()
	{
		if(head==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<now->getData()<<endl;
		}
	}
	void pop()
	{
		if(head==0)
		 cout<<-1<<endl;
		else
		{
			front();
			head=head->getNext();
		}
	}
};
int main(void)
{
	
	int Case;
	List list;
	cin>>Case;
	while(Case--)
	{
		
		string str;
		int n;
		cin>>str;
		if(str=="push")
		{
			cin>>n;
			list.push(n);
		}
		else if(str=="pop")
		{
			list.pop();
		}
		else if(str=="size")
		{
			list.size();
		}
		else if(str=="empty")
		{
			list.empty();
		}
		else if(str=="front")
		{
			list.front();
		}
		else if(str=="back")
		{
			list.back();
		}
		
		
	}
    return 0;
}
