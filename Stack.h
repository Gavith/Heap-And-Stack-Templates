template <class T>
struct EntryStack {
	T token;
	EntryStack* next;
};

template<class T>
class Stack {
public:
	Stack();
	~Stack();
	T pop();
	T peek();
	void push(T n);
	bool is_empty();

private:
	EntryStack<T> * head;
};


template<class T>
Stack<T>::Stack()
{
	head = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
	while (!this->is_empty()) {
		this->pop();
	}
}

template<class T>
T Stack<T>::pop()
{ 
	EntryStack<T>* tempNode = head;
	T temp = tempNode->token;
	head = tempNode->next;
	delete tempNode;
	return temp;
}

template<class T>
T Stack<T>::peek()
{
	return head->token;
}

template<class T>
void Stack<T>::push(T n)
{
	EntryStack<T> *newNode = new EntryStack<T>();
	newNode->token = n;
	newNode->next = head;
	head = newNode;
}

template<class T>
bool Stack<T>::is_empty()
{
	if (!head) {
		return true;
	}
	return false;
}