template <class T>
struct EntryQueue {
	T token;
	EntryQueue* next = nullptr;
};

template<class T>
class Queue {
public:
	Queue();
	~Queue();
	T pop();
	T last();
	T next();	
	void push(T n);
	bool is_empty();

private:
	EntryQueue<T> * head;
	EntryQueue<T> * end;
};


template<class T>
Queue<T>::Queue()
{
	head = nullptr;
	end = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
	while (!this->is_empty()) {
		this->pop();
	}
}


//pops the head
template<class T>
T Queue<T>::pop()
{ 
	EntryQueue<T>* tempNode = head;
	T temp = tempNode->token;
	head = tempNode->next;
	delete tempNode;
	return temp;
}

template<class T>
T Queue<T>::last()
{
	return end->token;
}

template<class T>
inline T Queue<T>::next()
{
	return head->token;
}


template<class T>
void Queue<T>::push(T n)
{
	EntryQueue<T> *newNode = new EntryQueue<T>();
	newNode->token = n;
	if (!head) {
		head = newNode;
	}
	else {
		end->next = newNode;
	}

	end = newNode;
	
}

template<class T>
bool Queue<T>::is_empty()
{
	if (!head) {
		return true;
	}
	return false;
}