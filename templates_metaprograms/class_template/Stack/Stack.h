#pragma once
constexpr int MAX = 100;
template <typename T>
class Stack
{
	T data_[100];
	int top_;

public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const T &inp);
	const T &top();
	void pop();
};

// Definitions

template <typename T>
Stack<T>::Stack() : top_(-1) {}
template <typename T>
Stack<T>::~Stack() {}

template <typename T>
bool Stack<T>::isEmpty() const { return top_ == -1; }
template <typename T>
bool Stack<T>::isFull() const { return top_ == (MAX - 1); }
template <typename T>
void Stack<T>::push(const T &inp)
{
	if (!isFull())
	{
		data_[++top_] = inp;
	}
	else
	{
		std::cout << "The stack is full!!\n";
	}
}
template <typename T>
const T &Stack<T>::top() { return data_[top_]; }
template <typename T>
void Stack<T>::pop() { --top_; }
