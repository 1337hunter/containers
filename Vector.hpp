#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <cstring>
# include <iostream>
# include <limits>

namespace ft
{

template <typename T>
struct vector_iterator
{
	typedef vector_iterator<T>	_Self;
	typedef std::ptrdiff_t		difference_type;
	typedef T					value_type;
	typedef T*					pointer;
	typedef T&					reference;
	typedef std::size_t			size_type;
	typedef std::random_access_iterator_tag	iterator_category;

				vector_iterator(void) : _ptr(0) { }

				vector_iterator(pointer ptr) : _ptr(ptr) { }

				vector_iterator(_Self const &o) : _ptr(o._ptr) { }

	virtual		~vector_iterator(void) { }

	_Self		&operator=(_Self const &o) { this->_ptr = o._ptr; return *this; }

	reference	operator*(void) const { return *_ptr; }

	pointer		operator->(void) const { return _ptr; }

	_Self		&operator++(void) { _ptr++; return *this; }

	_Self		operator++(int) { _Self	temp = *this; _ptr++; return temp; }

	_Self		&operator--(void) { _ptr--; return *this; }

	_Self		operator--(int) { _Self	temp = *this; _ptr--; return *this; }

	reference	operator[](size_type n) { return *(_ptr + n); }

	_Self		&operator+=(difference_type diff) { _ptr += diff; return *this; }

	_Self		&operator-=(difference_type diff) { _ptr -= diff; return *this; }

	_Self		operator-(difference_type diff) { return _Self(_ptr - diff); }

	_Self		operator+(difference_type diff) { return _Self(_ptr + diff); }

	difference_type	operator-(const _Self &it) { return _ptr - it._ptr; }

	friend _Self	operator+(difference_type diff, const _Self it)
	{
		_Self temp = it;
		return temp + diff;
	}

	friend bool	operator<(const _Self &a, const _Self &b) { return a._ptr < b._ptr; }
	friend bool	operator>=(const _Self &a, const _Self &b) { return !(a._ptr < b._ptr); }
	friend bool	operator>(const _Self &a, const _Self &b) { return a._ptr > b._ptr; }
	friend bool operator<=(const _Self &a, const _Self &b) { return !(a._ptr > b._ptr); }
	friend bool	operator==(const _Self &a, const _Self &b) { return a._ptr == b._ptr; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._ptr != b._ptr; }

	pointer		_ptr;
};

template <typename T>
struct vector_const_iterator
{
	typedef vector_const_iterator<T>	_Self;
	typedef std::ptrdiff_t				difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef	T const *					const_pointer;
	typedef T&							reference;
	typedef T const &					const_reference;
	typedef std::size_t					size_type;
	typedef std::random_access_iterator_tag	iterator_category;

				vector_const_iterator(void) : _ptr(0) { }

				vector_const_iterator(const_pointer ptr) : _ptr(ptr) { }

				vector_const_iterator(_Self const &o) : _ptr(o._ptr) { }

	virtual		~vector_const_iterator(void) { }

	_Self		&operator=(_Self const &o) { this->_ptr = o._ptr; return *this; }

	const_reference	operator*(void) const { return *_ptr; }

	const_pointer	operator->(void) const { return _ptr; }

	_Self		&operator++(void) { _ptr++; return *this; }

	_Self		operator++(int) { _Self	temp = *this; _ptr++; return temp; }

	_Self		&operator--(void) { _ptr--; return *this; }

	_Self		operator--(int) { _Self	temp = *this; _ptr--; return *this; }

	const_reference	operator[](size_type n) { return *(_ptr + n); }

	_Self		&operator+=(difference_type diff) { _ptr += diff; return *this; }

	_Self		&operator-=(difference_type diff) { _ptr -= diff; return *this; }

	_Self		operator-(difference_type diff) { return _Self(_ptr - diff); }

	_Self		operator+(difference_type diff) { return _Self(_ptr + diff); }

	difference_type	operator-(const _Self &it) { return _ptr - it._ptr; }

	friend _Self	operator+(difference_type diff, const _Self it)
	{
		_Self temp = it;
		return temp + diff;
	}

	friend bool	operator<(const _Self &a, const _Self &b) { return a._ptr < b._ptr; }
	friend bool	operator>=(const _Self &a, const _Self &b) { return !(a._ptr < b._ptr); }
	friend bool	operator>(const _Self &a, const _Self &b) { return a._ptr > b._ptr; }
	friend bool operator<=(const _Self &a, const _Self &b) { return !(a._ptr > b._ptr); }
	friend bool	operator==(const _Self &a, const _Self &b) { return a._ptr == b._ptr; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._ptr != b._ptr; }

	const_pointer	_ptr;
};

template <typename T>
struct vector_reverse_iterator
{
	typedef vector_reverse_iterator<T>	_Self;
	typedef std::ptrdiff_t				difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef std::size_t					size_type;
	typedef std::random_access_iterator_tag	iterator_category;

				vector_reverse_iterator(void) : _ptr(0) { }

				vector_reverse_iterator(pointer ptr) : _ptr(ptr) { }

				vector_reverse_iterator(_Self const &o) : _ptr(o._ptr) { }

	virtual		~vector_reverse_iterator(void) { }

	_Self		&operator=(_Self const &o) { this->_ptr = o._ptr; return *this; }

	reference	operator*(void) const { return *_ptr; }

	pointer		operator->(void) const { return _ptr; }

	_Self		&operator++(void) { _ptr--; return *this; }

	_Self		operator++(int) { _Self	temp = *this; _ptr--; return temp; }

	_Self		&operator--(void) { _ptr++; return *this; }

	_Self		operator--(int) { _Self	temp = *this; _ptr++; return *this; }

	reference	operator[](size_type n) { return *(_ptr + n); }

	_Self		&operator+=(difference_type diff) { _ptr -= diff; return *this; }

	_Self		&operator-=(difference_type diff) { _ptr += diff; return *this; }

	_Self		operator-(difference_type diff) { return _Self(_ptr + diff); }

	_Self		operator+(difference_type diff) { return _Self(_ptr - diff); }

	difference_type	operator-(const _Self &it) { return _ptr + it._ptr; }

	friend _Self	operator+(difference_type diff, const _Self it)
	{
		_Self temp = it;
		return temp - diff;
	}

	friend bool	operator<(const _Self &a, const _Self &b) { return a._ptr > b._ptr; }
	friend bool	operator>=(const _Self &a, const _Self &b) { return !(a._ptr < b._ptr); }
	friend bool	operator>(const _Self &a, const _Self &b) { return a._ptr < b._ptr; }
	friend bool operator<=(const _Self &a, const _Self &b) { return !(a._ptr > b._ptr); }
	friend bool	operator==(const _Self &a, const _Self &b) { return a._ptr == b._ptr; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._ptr != b._ptr; }

	pointer	_ptr;
};

template <typename T>
struct vector_const_reverse_iterator
{
	typedef vector_const_reverse_iterator<T>	_Self;
	typedef std::ptrdiff_t				difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef	T const *					const_pointer;
	typedef T&							reference;
	typedef T const &					const_reference;
	typedef std::size_t					size_type;
	typedef std::random_access_iterator_tag	iterator_category;

				vector_const_reverse_iterator(void) : _ptr(0) { }

				vector_const_reverse_iterator(const_pointer ptr) : _ptr(ptr) { }

				vector_const_reverse_iterator(_Self const &o) : _ptr(o._ptr) { }

	virtual		~vector_const_reverse_iterator(void) { }

	_Self		&operator=(_Self const &o) { this->_ptr = o._ptr; return *this; }

	const_reference	operator*(void) const { return *_ptr; }

	const_pointer		operator->(void) const { return _ptr; }

	_Self		&operator++(void) { _ptr--; return *this; }

	_Self		operator++(int) { _Self	temp = *this; _ptr--; return temp; }

	_Self		&operator--(void) { _ptr++; return *this; }

	_Self		operator--(int) { _Self	temp = *this; _ptr++; return *this; }

	const_reference	operator[](size_type n) { return *(_ptr + n); }

	_Self		&operator+=(difference_type diff) { _ptr -= diff; return *this; }

	_Self		&operator-=(difference_type diff) { _ptr += diff; return *this; }

	_Self		operator-(difference_type diff) { return _Self(_ptr + diff); }

	_Self		operator+(difference_type diff) { return _Self(_ptr - diff); }

	difference_type	operator-(const _Self &it) { return _ptr + it._ptr; }

	friend _Self	operator+(difference_type diff, const _Self it)
	{
		_Self temp = it;
		return temp - diff;
	}

	friend bool	operator<(const _Self &a, const _Self &b) { return a._ptr > b._ptr; }
	friend bool	operator>=(const _Self &a, const _Self &b) { return !(a._ptr < b._ptr); }
	friend bool	operator>(const _Self &a, const _Self &b) { return a._ptr < b._ptr; }
	friend bool operator<=(const _Self &a, const _Self &b) { return !(a._ptr > b._ptr); }
	friend bool	operator==(const _Self &a, const _Self &b) { return a._ptr == b._ptr; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._ptr != b._ptr; }

	const_pointer	_ptr;
};

template <class T, class Alloc = std::allocator<T> >
class Vector
{
public:
	typedef T		value_type;
	typedef Alloc   allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef vector_iterator<T>					iterator;
	typedef vector_const_iterator<T>			const_iterator;
	typedef vector_reverse_iterator<T>			reverse_iterator;
	typedef vector_const_reverse_iterator<T>	const_reverse_iterator;
	typedef std::ptrdiff_t						difference_type;
	typedef std::size_t							size_type;

private:
	pointer		_data;
	size_type	_size;
	size_type	_cap;

public:
	explicit Vector(const allocator_type& alloc = allocator_type())
	{
		(void)alloc;
		_data = 0;
		_size = 0;
		_cap = 0;
	}
	explicit Vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
	{
		(void)alloc;
		_data = new value_type[n];
		_size = n;
		_cap = n;
		for (size_type i = 0; i < n; i++)
			_data[i] = val;

	}

	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc =
			allocator_type())
	{
		(void)alloc;
		typedef typename std::__is_integer<InputIterator>::__type   _Integral;
		assign_constructor_call(first, last, _Integral());
	}

	Vector(const Vector &x)
	{
		_size = x.size();
		_cap = _size;
		if (_size > 0)
		{
			_data = new value_type[_size];
			size_type n = 0;
			for (const_iterator i = x.begin(); i < x.end(); n++, i++)
				_data[n] = *i;
		}
		else
			_data = 0;
	}

	~Vector () { delete[] _data; }

	iterator		begin(void) { return iterator(_data); }
	
	const_iterator	begin(void) const { return const_iterator(_data); }

	iterator		end(void) { return iterator(_data + _size); }

	const_iterator	end(void) const { return const_iterator(_data + _size); }

	reverse_iterator	rbegin(void) { return reverse_iterator(_data + _size - 1); }

	reverse_iterator	rend(void) { return reverse_iterator(_data - 1); }

	Vector&		operator=(const Vector& x)
	{
		delete[]	_data;

		_data = 0;
		_size = 0;
		_cap = 0;
		typedef typename std::__is_integer<iterator>::__type   _Integral;
		assign_constructor_call(x.begin(), x.end(), _Integral());
		return *this;
	}

	reference	operator[](size_type n)
	{
		return *(_data + n);
	}

	size_type	size(void) const { return _size; }

	size_type	max_size(void)
	{
		return (std::numeric_limits<std::size_t>::max() / 2 ) / sizeof(value_type);
	}

	void		resize(size_type n, value_type val = value_type())
	{
		if (n == _size)
			return ;
		else if (n == 0)
		{
			delete[] _data;
			_size = 0;
			_data = 0;
			_cap = 0;
		}
		else if (n > _size)
		{
			if (n >= _cap)
			{
				pointer	temp;
	
				temp = new value_type[n + n / 2];
				size_type i = 0;
				for (; i < _size; i++)
					temp[i] = _data[i];
				for (; i < n; i++)
					temp[i] = val;
				delete[] _data;
				_size = n;
				_cap = n + n / 2;
				_data = temp;
			}
			else
			{
				for (; _size < n; _size++)
					_data[_size] = val;
			}
		}
		else if (n < _size)
		{
			pointer temp;
			temp = new value_type[n + n / 4];
			for (size_type i = 0; i < n; i++)
				temp[i] = _data[i];
			delete[] _data;
			_size = n;
			_cap = n + n / 4;
			_data = temp;
		}
	}

	size_type	capacity(void) const { return _cap; }

	bool		empty(void) const { return !_size; }

	void		reserve(size_type n)
	{
		if (n > _size && n != _cap)
		{
			pointer	temp;

			_cap = n;
			temp = new value_type[_cap];
			for (size_type i = 0; i < _size; i++)
				temp[i] = _data[i];
			delete[] _data;
			_data = temp;
		}
	}

	reference		at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector: index out of range");
		return _data[n];
	}

	const_reference	at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector: index out of range");
		return _data[n];
	}

	reference		front(void) { return _data[0]; }

	const_reference	front(void) const { return _data[0]; }

	reference		back(void) { return _data[_size - 1]; }

	const_reference	back(void) const { return _data[_size - 1]; }

	void	assign(size_type n, const value_type& val)
	{
		delete[] _data;
		_size = n;
		_cap = _size;
		_data = new value_type[_size];
		while (n--)
			_data[n] = val;
	}

	template <class InputIterator>
	void	assign(InputIterator first, InputIterator last)
	{
		typedef typename std::__is_integer<InputIterator>::__type   _Integral;
		assign_call(first, last, _Integral());
	}

	void	push_back(const value_type& val)
	{
		if (_size < _cap)
			_data[_size++] = val;
		else
		{
			pointer	temp = new value_type[_cap + _cap / 2 + 1];
			_cap = _cap + _cap / 2 + 1;
			for (size_type i = 0; i < _size; i++)
				temp[i] = _data[i];
			temp[_size++] = val;
			delete[] _data;
			_data = temp;
		}
	}

	void	pop_back(void)
	{
		if (_size > _cap / 2)
			_size--;
		else 
		{
			if (_size == 1)
			{
				delete[] _data;
				_data = 0;
				_size = 0;
				_cap = 0;
			}
			else if (_size > 1)
			{
				pointer temp = new value_type[_cap - _cap / 2 - 1];
				_cap = _cap - _cap / 2 - 1;
				_size--;
				for (size_type i = 0; i < _size; i++)
					temp[i] = _data[i];
				delete[] _data;
				_data = temp;
			}
		}
	}

	iterator	insert(iterator position, const value_type& val)
	{
		if (_size < _cap)
		{
			for (iterator pos = end(); pos > position; pos--)
				*pos = *(pos - 1);
			_size++;
			*position = val;
			return position;
		}
		else
		{
			pointer temp = new value_type[_cap + _cap / 2 + 1];
			_cap = _cap + _cap / 2 + 1;
			size_type n = 0;
			for (iterator i = begin(); i < position; n++, i++)
				temp[n] = *i;
			temp[n++] = val;
			iterator	ret = iterator(&temp[n - 1]);
			for (; position < end(); n++, position++)
				temp[n] = *position;
			_size++;
			delete[] _data;
			_data = temp;
			return ret;
		}
	}

	void	insert(iterator position, size_type n, const value_type& val)
	{
		if (_size + n <= _cap)
		{
			for (size_type pos = _size + n - 1; pos > _size - 1; pos--)
				_data[pos] = _data[pos - n];

	//		for (iterator pos = end() + n - 1; pos > position; pos--)
	//			*pos = *(pos - n);
			size_type i = 0;
			for (iterator pos = position; i < n; i++, pos++)
				*pos = val;
			_size += n;
		}
		else
		{
			pointer temp = new value_type[_cap + _cap / 2 + n];
			_cap = _cap + _cap / 2 + n;
			size_type ii = 0;
			for (iterator i = begin(); i < position; ii++, i++)
				temp[ii] = *i;
			for (size_type num = 0; num < n; num++, ii++)
				temp[ii] = val;
			for (; position < end(); ii++, position++)
				temp[ii] = *position;
			_size += n;
			delete[] _data;
			_data = temp;
		}
	}

	template <class InputIterator>
	void	insert(iterator position, InputIterator first, InputIterator last)
	{
		typedef typename std::__is_integer<iterator>::__type   _Integral;
		insert_call(position, first, last, _Integral());
	}

	iterator	erase(iterator position)
	{
		if (_size > _cap / 2)
		{
			iterator ret = position;
			for (; position < end() - 1; position++)
				*position = *(position + 1);
			_size--;
			return ret;
		}
		else
		{
			pointer temp = new value_type[_cap - _cap / 2 - 1];
			_cap = _cap - _cap / 2 - 1;
			size_type n = 0;
			for (iterator i = begin(); i < position; i++, n++)
				temp[n] = *i;
			iterator ret = iterator(temp + n);
			for (iterator i = position + 1; i < end(); i++, n++)
				temp[n] = *i;
			delete[] _data;
			_data = temp;
			_size--;
			return ret;
		}
	}

	iterator	erase(iterator first, iterator last)
	{
		size_type diff = last - first;
		if (_size - diff >= _cap / 2)
		{
			iterator ret = first;
			for (; last < end(); last++, first++)
				*first = *last;
			_size -= diff;
			return ret;
		}
		else
		{
			pointer temp = new value_type[_cap - _cap / 2 - diff];
			_cap = _cap - _cap / 2 - diff;
			size_type n = 0;
			for (iterator i = begin(); i < first; i++, n++)
				temp[n] = *i;
			iterator ret = iterator(temp + n);
			for (iterator i = last; last < end(); last++, n++)
				temp[n] = *i;
			_size -= diff;
			delete[] _data;
			_data = temp;
			return ret;
		}
	}

	void	clear(void) { delete[] _data; _data = 0; _size = 0; _cap = 0; }

	void	swap(Vector &x)
	{
		pointer 	temp_data = _data;
		size_type	temp_size = _size;
		size_type	temp_cap = 	_cap;

		_data = x._data;
		_size = x._size;
		_cap = x._cap;
		x._data = temp_data;
		x._size = temp_size;
		x._cap = temp_cap;
	}

private:
	template <class InputIterator> void
	insert_call(iterator position, InputIterator first, InputIterator last, std::__true_type)
	{
		size_type n = first;
		value_type val = last;
		if (_size + n <= _cap)
		{
			for (iterator pos = end() + n - 1; pos > position; pos--)
				*pos = *(pos - n);
			size_type i = 0;
			for (iterator pos = position; i < n; i++, pos++)
				*pos = val;
			_size += n;
		}
		else
		{
			pointer temp = new value_type[_cap + _cap / 2 + n];
			_cap = _cap + _cap / 2 + n;
			size_type ii = 0;
			for (iterator i = begin(); i < position; ii++, i++)
				temp[ii] = *i;
			for (size_type num = 0; num < n; num++, ii++)
				temp[ii] = val;
			for (; position < end(); ii++, position++)
				temp[ii] = *position;
			_size += n;
			delete[] _data;
			_data = temp;
		}
	}

	template <class InputIterator> void
	insert_call(iterator position, InputIterator first, InputIterator last, std::__false_type)
	{
		size_type diff = (last - first);
		if (_size + diff <= _cap)
		{
			for (iterator pos = end() + diff; pos > position; pos--)
				*pos = *(pos - diff);
			for (iterator pos = position; first < last; first++, pos++)
				*pos = *first;
			_size += diff;
		}
		else
		{
			pointer temp = new value_type[_cap + _cap / 2 + diff];
			_cap = _cap + _cap / 2 + diff;
			size_type ii = 0;
			for (iterator i = begin(); i < position; ii++, i++)
				temp[ii] = *i;
			for (; first < last; first++, ii++)
				temp[ii] = *first;
			for (; position < end(); ii++, position++)
				temp[ii] = *position;
			_size += diff;
			delete[] _data;
			_data = temp;
		}
	}

	template <class InputIterator> void
	assign_call(InputIterator first, InputIterator last, std::__false_type)
	{
		delete[] _data;
		_size = last - first;
		_cap = _size;
		_data = new value_type[_size];
		for (size_type i = 0; first < last; i++, first++)
			_data[i] = *first;
	}

	template <class InputIterator> void
	assign_call(InputIterator first, InputIterator last, std::__true_type)
	{
		delete[] _data;
		_size = first;
		_cap = _size;
		_data = new value_type[_size];
		while (first--)
			_data[first] = last;
	}

	template <class InputIterator> void
	assign_constructor_call(InputIterator first, InputIterator last, std::__false_type)
	{
		if (last - first > 0)
		{
			_size = last - first;
			_cap = _size;
			_data = new value_type[_size];
			for (size_type i = 0; first < last; first++, i++)
				_data[i] = *first;
		}
		else
		{
			_size = 0;
			_data = 0;
			_cap = 0;
		}
	}
	template <class InputIterator> void
	assign_constructor_call(InputIterator first, InputIterator last, std::__true_type)
	{
		_size = first;
		_cap = _size;
		if (_size > 0)
			_data = new value_type[_size];
		else
			_data = 0;
		for (size_type i = 0; i < _size; i++)
			_data[i] = last;
	}
};

template <class T, class Alloc>
inline bool operator==(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	if (x.size() != y.size())
		return false;

	typename Vector<T, Alloc>::const_iterator xb = x.begin();
	typename Vector<T, Alloc>::const_iterator xe = x.end();
	typename Vector<T, Alloc>::const_iterator yb = y.begin();
	typename Vector<T, Alloc>::const_iterator ye = y.end();

	while (xb != xe && yb != ye && *yb == *xb)
	{
		xb++;
		yb++;
	}
	return xb == xe && yb == ye;
}

template <class T, class Alloc>
inline bool operator!=(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	return !(x == y);
}

template<class T, class Alloc>
inline bool operator<(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<class T, class Alloc>
inline bool operator<=(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	return !(y < x);
}

template<class T, class Alloc>
inline bool operator>(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	return y < x;
}

template<class T, class Alloc>
inline bool operator>=(const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
	return !(x < y);
}

template <class T, class Alloc>
inline void swap(Vector<T, Alloc>& x, Vector<T, Alloc>& y)
{
	x.swap(y);
}

}//ft


#endif
