#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
using namespace std;

typedef int US;
typedef int _tp;


class _pq
{
public:
	_tp Q[10000000];
	int store;
	bool mode;//false min_pq / true max_pq
	_pq(bool mode){
		this->store = 0;
		this->mode = mode;
	}
	void _swap(int a, int b, _tp *Q){
		_tp temp;
		temp = Q[a];
		Q[a] = Q[b];
		Q[b] = temp;
	}
	void _push(_tp data){
		if (store == 0){
			Q[++store] = data;
		}
		else{
			Q[++store] = data;
			_tp temp = store;
			while (true)
			{
				if (temp == 1)
					break;
				if (mode)
				{
					if (Q[temp] > Q[temp / 2])
					{
						_swap(temp, temp / 2, Q);
						temp /= 2;
					}
					else
						break;
				}
				else
				{
					if (Q[temp] < Q[temp / 2])
					{
						_swap(temp, temp / 2, Q);
						temp /= 2;
					}
					else
						break;
				}
			}
		}
	}
	_tp _pop()
	{
		if (store == 0)
			return 0;
		else
		{
			_tp ret = Q[1];
			_swap(1, store, Q);
			store--;
			_tp temp = 1;
			while (true)
			{
				if (temp * 2 > store)
					break;
				if (mode)
				{
					if (temp * 2 == store)
					{
						if (Q[temp] < Q[temp * 2])
						{
							_swap(temp, temp * 2, Q);
							temp *= 2;
						}
						else
							break;
					}
					else
					{
						if (Q[temp * 2] > Q[temp * 2 + 1])
						{
							if (Q[temp] < Q[temp * 2])
							{
								_swap(temp, temp * 2, Q);
								temp *= 2;
							}
							else
								break;
						}
						else
						{
							if (Q[temp] < Q[temp * 2 + 1])
							{
								_swap(temp, temp * 2 + 1, Q);
								temp =temp * 2 +1;
							}
							else
								break;
						}
					}
				}
				else
				{
					if (temp * 2 == store)
					{
						if (Q[temp] > Q[temp * 2])
						{
							_swap(temp, temp * 2, Q);
							temp *= 2;
						}
						else
							break;
					}
					else
					{
						if (Q[temp * 2] < Q[temp * 2 + 1])
						{
							if (Q[temp] > Q[temp * 2])
							{
								_swap(temp, temp * 2, Q);
								temp *= 2;
							}
							else
								break;
						}
						else
						{
							if (Q[temp] > Q[temp * 2 + 1])
							{
								_swap(temp, temp * 2 + 1, Q);
								temp = temp * 2 +1 ;
							}
							else
								break;
						}
					}
				}
			}
			return ret;
		}
	}
};


class Node
{
public:
	US vertex;
	US weight;
	Node *next;
	Node(US vertex)
	{
		this->vertex = vertex;
		this->next = 0;
	}
	Node(US vertex, US weight)
	{
		this->vertex = vertex;
		this->weight = weight;
		this->next = 0;
	}
};
class _vector
{
public:
	Node *head;
	Node *tail;
	Node *now;
	int store;
	_vector()
	{

		head = tail = now = 0;
		store = 0;
	}
	void _push(Node *NEW)
	{
		if (head == 0)
		{
			head = NEW;
			head->next = 0;
			tail = head;
			now = head;
			store++;
		}
		else
		{
			tail->next = NEW;
			tail = tail->next;
			store++;
		}
	}
	void _push(US vertex)
	{
		if (head == 0)
		{
			head = new Node(vertex);
			head->next = 0;
			tail = head;
			now = head;
			store++;
		}
		else
		{
			tail->next = new Node(vertex);
			tail = tail->next;
			store++;
		}
	}
	void _push(US vertex, US weight)
	{
		if (head == 0)
		{
			head = new Node(vertex, weight);
			head->next = 0;
			tail = head;
			now = head;
			store++;
		}
		else
		{
			tail->next = new Node(vertex, weight);
			tail = tail->next;
			store++;
		}
	}

	void _clear()
	{
		if (store != 0)
		{
			Node *delNode = head;
			Node *delNextNode = head->next;
			delete delNode;
			while (delNextNode != 0)
			{
				delNode = delNextNode;
				delNextNode = delNextNode->next;
				delete delNode;
			}
		}

		head = tail = now = 0;
		store = 0;

	}

};

_vector Map[32001];
int parent[32001];
_pq Q(false);
int N, M;
//priority_queue<int> Q;
int main() {
	cin >> N >> M;
	int a, b;
	//a->b
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		Map[a]._push(b);
		parent[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (!parent[i]) {
			Q._push(i);
			//Q.push(-i);
		}
	}

	for (int i = 0; i < N; i++) {
		int x = Q._pop();
		//int x = -Q.top();
		//Q.pop();
		printf("%d ", x);
		int _size = Map[x].store;
		for (int j = 0; j < _size; j++) {
			int y = Map[x].now->vertex;
			parent[y]--;
			Map[x].now = Map[x].now->next;
			if (!parent[y])
				Q._push(y);
				//Q.push(-y);
		}
	}
	printf("\n");


	return 0;
}




