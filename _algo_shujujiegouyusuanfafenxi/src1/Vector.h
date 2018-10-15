#include <iostream>
#include <vector>

using namespace std;

template <typename Object>
class Vector
{
public:
	explicit Vector(int init_size = 0):_size(init_size),_capacity(init_size + SPARE_SIZE)
	{
		if(init_size < 0)
			data = NULL;
		else
			data = new Object[_capacity];
	}

	Vector(const Vector & rhs) : data(NULL)
	{
		operator=(rhs);
	}	

	~Vector()
	{
		delete []data;
	}

	const Vector &operator=(const Vector &rhs)
	{
		if(*this != rhs) {
			delete []data;
			data = NULL;
			if(rhs._size >= 0 && rhs._capacity >= 0) {
				_size = rhs._size;
				_capacity = rhs._capacity;
				data = new Object[rhs._capacity];	
				for(int i = 0; i < _size; ++i)
					data[i] = rhs.data[i];
			}
		}
		return *this;
	}

	void resize(int new_size)
	{
		if(new_size > _capacity) {
			reserve(new_size);
		}
		this->_size = new_size;
	}

	void reserve(int new_capacity)
	{
		if(new_capacity <= _capacity)
			return;
		Object *p = new Object[new_capacity];
		if(!p)
			return;

		for(int i = 0; i < _size; ++i)
			p[i] = data[i];

		delete [] data;
		data = p;
		_capacity = new_capacity;
	}

	Object & operator[](int index)
	{
		return data[index];
	}

	const Object & operator[](int index) const
	{
		return data[index];
	}
	
	bool empty() const
	{
		return _size == 0;
	}

	int size() const
	{
		return _size;
	}

	int capacity() const
	{
		return _capacity;
	}

	void push_back(const Object &obj)
	{
		if(_size == _capacity)
			reserve(2 * _capacity);
		data[_size++] = obj;
	}

	void pop_back()
	{
		if(_size > 0)
			--_size;
	}

	const Object &back() const
	{
		return data[_size - 1];
	}
	
	typedef Object *iterator;
	typedef const Object *const_iterator;

	iterator begin() 
	{
		return data;
	}
	const_iterator begin() const
	{
		return data;
	}
	iterator end()
	{
		return &data[_size];
	}
	const_iterator end() const
	{
		return &data[_size];
	}

	enum {SPARE_SIZE = 16};	
private:
	int	_size;
	int _capacity;
	Object *data;
};

