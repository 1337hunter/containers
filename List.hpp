#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>
# include <algorithm>

namespace ft
{
template <typename T, class Alloc = std::allocator<T> > struct list_node;

template <typename T>
struct	list_iterator
{
	typedef list_iterator<T>	_Self;
	typedef list_node<T> 		_Node;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef std::ptrdiff_t	difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

				list_iterator(void): _node() { }
				list_iterator(const _Self &what) : _node(what._node) { }
				list_iterator(_Node *what): _node(what) { }
	virtual		~list_iterator(void) { }
	_Self		&operator=(const _Self &what) { this->_node = what._node; return *this; }
	reference	operator*(void) const { return *_node->getDataPtr(); }
	pointer		operator->(void) const { return _node->getDataPtr(); }

	_Self		&operator++(void)
	{
		_node = _node->_next;
		return *this; 
	}

	_Self	operator++(int)
	{
		_Self temp = *this;
		_node = _node->_next;
		return temp;
	}

	_Self	&operator--(void)
	{
		_node = _node->_prev;
		return *this;
	}

	_Self	operator--(int)
	{
		_Self temp = *this;
		_node = _node->_prev;
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node	*_node;
};

template <class T>
struct list_const_iterator
{
	typedef list_const_iterator<T>	_Self;
	typedef const list_node<T>		_Node;
	typedef list_iterator<T>		iterator;
	typedef std::ptrdiff_t			difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef T						value_type;
	typedef const T*				pointer;
	typedef const T&				reference;

				list_const_iterator(void): _node() {}
				list_const_iterator(const _Node *what): _node(what) {}
				list_const_iterator(const _Self &what) { *this = what; }
	virtual		~list_const_iterator(void) {}

	_Self		&operator=(const _Self &what)
	{
		this->_node = what._node;
		return *this;
	}

	reference	operator*(void) { return *_node->getDataPtr(); }

	pointer		operator->(void) { return _node->geDataPtr(); }

	_Self		&operator++(void)
	{
		_node = _node->_next;
		return *this;
	}

	_Self		operator++(int)
	{
		_Self temp = *this;
		_node = _node->_next;
		return temp;
	}

	_Self		&operator--(void)
	{
		_node = _node->_prev;
		return *this;
	}

	_Self		operator--(int)
	{
		_Self temp = *this;
		_node = _node->_prev;
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	const _Node	*_node;
};

template <class T>
struct list_const_reverse_iterator
{
	typedef list_const_iterator<T>	_Self;
	typedef const list_node<T>		_Node;
	typedef list_iterator<T>		iterator;
	typedef std::ptrdiff_t			difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef T						value_type;
	typedef const T*				pointer;
	typedef const T&				reference;

				list_const_reverse_iterator(void): _node() {}
				list_const_reverse_iterator(const _Node *what): _node(what) {}
				list_const_reverse_iterator(const _Self &what) { *this = what; }
	virtual		~list_const_reverse_iterator(void) {}
	_Self		&operator=(const _Self &what)
	{
		this->_node = what._node;
		return *this;
	}
	reference	operator*(void) { return *_node->getDataPtr(); }
	pointer		operator->(void) { return _node->geDataPtr(); }
	_Self		&operator++(void)
	{
		_node = _node->_prev;
		return *this;
	}
	_Self		operator++(int)
	{
		_Self temp = *this;
		_node = _node->_prev;
		return temp;
	}
	_Self		&operator--(void)
	{
		_node = _node->_next;
		return *this;
	}
	_Self		operator--(int)
	{
		_Self temp = *this;
		_node = _node->_next;
		return temp;
	}
	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	const _Node	*_node;
};


template <typename T>
struct	reverse_list_iterator
{
	typedef reverse_list_iterator<T>	_Self;
	typedef list_node<T> 				_Node;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef std::ptrdiff_t					difference_type;
	typedef std::bidirectional_iterator_tag	iterator_category;

				reverse_list_iterator(void): _node() { }
				reverse_list_iterator(const _Self &what) : _node(what._node) { }
				reverse_list_iterator(_Node *what): _node(what) { }
	virtual		~reverse_list_iterator(void) { }
	_Self		&operator=(const _Self &what) { this->_node = what._node; return *this; }
	reference	operator*(void) const { return *_node->getDataPtr(); }
	pointer		operator->(void) const { return _node->getDataPtr(); }
	_Self		&operator++(void)
	{
		_node = _node->_prev;
		return *this; 
	}
	_Self	operator++(int)
	{
		_Self temp = *this;
		_node = _node->_prev;
		return temp;
	}

	_Self	&operator--(void)
	{
		_node = _node->_next;
		return *this;
	}
	_Self	operator--(int)
	{
		_Self temp = *this;
		_node = _node->_next;
		return temp;
	}

	friend bool
	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }

	friend bool
	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node	*_node;
};


template <typename T, class Alloc>
struct list_node
{
	typedef T						value_type;
	typedef	Alloc					allocator_type;
	typedef list_node<T>			_Self;
	typedef list_iterator<T>		iterator;
	typedef list_const_iterator<T>	const_iterator;
	typedef std::ptrdiff_t			difference_type;

	value_type		*_value;
	list_node		*_next;
	list_node		*_prev;

				list_node(void) : _value(new value_type()), _next(this), _prev(this) {}
				~list_node(void) { delete _value; }
				list_node(value_type *val) : _value(val) { }
	list_node	&operator=(const list_node &ln)
	{
		this->_value = ln._value;
		this->_next = ln._next;
		this->_prev = ln._prev;
		return *this;
	}
					list_node(const list_node &ln) { *this = ln; }
	T				*getDataPtr(void) { return _value; }//__builtin_addressof(_value); }
	T const			*getDataPtr(void) const { return _value; }
	void			set_value(const value_type &val) { _value(val); }
	iterator		hook(iterator position, const value_type &val)
	{
		this->_next = position._node;
		this->_prev = position._node->_prev;
		position._node->_prev->_next = this;
		position._node->_prev = this;
		_value = new value_type(val);
		return iterator(this);
	}
	iterator		unhook(void)
	{
		_Self* next_node = this->_next;
		_Self* prev_node = this->_prev;
		prev_node->_next = next_node;
		next_node->_prev = prev_node;
		delete this;
		return iterator(next_node);
	}
};

template <class T, class Alloc = std::allocator<T> >
class List
{
private:
	typedef list_node<T>    				node_type;
	typedef	std::allocator<list_node<T> >	node_allocator;


public:
	typedef T 		value_type;
	typedef Alloc	allocator_type;
	typedef typename allocator_type::reference 			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer 			pointer;
	typedef typename allocator_type::const_pointer 		const_pointer;
	typedef list_iterator<T>				iterator;
	typedef list_const_iterator<T>			const_iterator;
	typedef reverse_list_iterator<T>		reverse_iterator;
	typedef list_const_reverse_iterator<T>	const_reverse_iterator;
	typedef std::ptrdiff_t	difference_type;
	typedef std::size_t 	size_type;

	explicit
	List(void) : _size(0), _node() { }

	~List(void) { clear(); }

	explicit
	List(size_type n, const value_type &val = value_type()) { while (n--) insert(end(), val); }

	template <class InputIterator>
	List(InputIterator first, InputIterator last)
	{
		typedef typename std::__is_integer<InputIterator>::__type	_Integral;
		assign_constructor_call(first, last, _Integral());
	}

	List(const List& x)
	{
		_size = 0;
		for (const_iterator it = x.cbegin(); it != x.cend(); it++)
		{
			node_type *node = _node_alloc.allocate(1);
			node->hook(end(), *it);
			_size++;
		}
	}

	List&
	operator=(const List& x)
	{
		assign(x.cbegin(), x.cend());
		return *this;
	}

	iterator		begin(void) { return iterator(_node._next); }

	const_iterator	begin(void) const { return const_iterator(_node._next); }

	iterator		end(void) { return iterator(&_node); }

	const_iterator	end(void) const { return const_iterator(&_node); }

	reverse_iterator	rbegin(void) { return reverse_iterator(_node._prev); }

	const_reverse_iterator rbegin(void) const 
	{ return const_reverse_iterator(_node._prev); }

	reverse_iterator	rend(void) { return reverse_iterator(&_node); }

	const_reverse_iterator rend(void) const
	{ return const_reverse_iterator(&_node); }
	
	std::size_t		size(void) const { return _size; }
	
	bool			empty(void) const { return !_size; }
	
	std::size_t		max_size(void) const
	{
		return (std::numeric_limits<std::size_t>::max() / 6) / sizeof(value_type);
	}
	
	reference		front(void) { return *_node._next->getDataPtr(); }
	
	const_reference	front(void) const { return *_node._next->getDataPtr(); }
	
	reference		back(void) { return *_node._prev->getDataPtr(); }
	
	const_reference	back(void) const { return *_node._prev->getDataPtr(); }
	
	iterator 		insert(iterator position, const value_type& val)
	{
		node_type		*n = _node_alloc.allocate(1);

		_size++;
		return n->hook(position, val);
	}

	void	insert(iterator position, size_type n, const value_type& val)
	{
		typedef typename std::__is_integer<value_type>::__type   _Integral;
		insert_help(position, n, val, _Integral());
	}

	template <class InputIterator>
	void	insert(iterator position, InputIterator first, InputIterator last)
	{
		typedef typename std::__is_integer<InputIterator>::__type   _Integral;
		insert_help(position, first, last, _Integral());
	}

	iterator		erase(iterator position) { _size--; return position._node->unhook(); }
	
	iterator		erase(iterator first, iterator last)
	{
		while (first != end() && first != last)
			first = erase(first);
		return first;
	}

	void	push_front(const value_type &val) { insert(begin(), val); }
	
	void	push_back(const value_type &val) { insert(end(), val); }
	
	void	pop_front(void) { if (_size) { erase(begin()); } }
	
	void	pop_back(void) { if (_size) { erase(--end()); } }
	
	template <class InputIterator>
	void	assign(InputIterator begin, InputIterator end)
	{
		typedef typename std::__is_integer<InputIterator>::__type   _Integral;
		assign_elements(begin, end, _Integral());
	}
	void	assign(size_type n, const value_type& val)
	{
		typedef typename std::__is_integer<value_type>::__type   _Integral;
		assign_elements(n, val, _Integral());
	}

	void	resize(size_type n, value_type val = value_type())
	{
		iterator 			_list_begin = begin();

		_size = 0;
		for (; _list_begin != end() && n; _list_begin++, n--, _size++)
				*_list_begin = val;
		if (_list_begin == end() && n)
			while (n--)
				insert(end(), val);
		else if (_list_begin != end() && !n)
			while (_list_begin != end())
				_list_begin = erase(_list_begin);

	}

	void	clear(void)
	{
		erase(begin(), end());
	}

	void 	swap(List& x)
	{
		iterator	b = begin();
		iterator	xb = x.begin();
		value_type	temp;

		for (; b != end() && xb != x.end(); b++, xb++)
		{
			temp = *b;
			*b = *xb;
			*xb = temp;
		}
		if (b == end())
			while (xb != x.end())
			{
				push_back(*xb);
				xb = x.erase(xb);
			}
		else if (xb == x.end())
			while (b != end())
			{
				x.push_back(*b);
				b = erase(b);
			}
	}
	void	splice(iterator position, List& x)
	{
		iterator    xb = x.begin();

		while (xb != x.end())
		{
			position = insert(position, *xb);
			xb = erase(xb);
		}
	}

	void	splice(iterator position, List& x, iterator i)
	{
		insert(position, *i);
		x.erase(i);
	}

	void	splice(iterator position, List& x, iterator first, iterator last)
	{
		(void)x;
		while (first != last)
		{
			insert(position, *first);
			first = erase(first);
		}
	}

	void	remove(const value_type& val)
	{
		iterator	it = begin();

		while (it != end())
			if (*it == val)
				it = erase(it);
			else
				it++;
	}

	template <class Predicate>
 	void	remove_if (Predicate pred)
	{
		iterator    it = begin();

		while (it != end())
			if (pred(*it))
				it = erase(it);
			else
				it++;
	}

	void	unique(void)
	{
		iterator    i = begin();
		iterator	ii = ++begin();

		if (i == end())
			return ;
		while (ii != end())
		{
			if (*ii == *i)
				ii = erase(ii);
			else
			{
				i = ii;
				ii++;
			}

		}
	}

	template <class BinaryPredicate>
	void	unique(BinaryPredicate binary_pred)
	{
		iterator    i = begin();
		iterator    ii = ++begin();

		if (i == end())
			return ;
		while (ii != end())
		{
			if (binary_pred(*ii, *i))
				ii = erase(ii);
			else
			{
				i = ii;
				ii++;
			}
		}
	}

	void	sort(void)
	{
		for (iterator i = begin(); i != end(); i++)
			for (iterator ii = i; ii != end(); ii++)
				if (*ii < *i)
				{
					value_type temp = *i;
					*i = *ii;
					*ii = temp;
				}
		//MergeSort(&_node._next);
	}

	template <class Compare>
	void	sort(Compare comp)
	{
		bool		flag = true;
		iterator	i, ii;
	
		while (flag)
		{
			flag = false;
			i = begin();
			ii = ++begin();
			while (i != end() && ii != end())
			{
				if (comp(*ii, *i))
                {
                    value_type temp = *i;
                    *i = *ii;
                    *ii = temp;
					flag = true;
                }
				i++;
				ii++;
			}
		}
		/*
		for (iterator i = begin(); i != end(); i++)
            for (iterator ii = i; ii != end(); ii++)
                if (comp(*ii, *i))
                {
                    value_type temp = *i;
                    *i = *ii;
                    *ii = temp;
                }*/
		//MergeSort(&_node._next, comp);
	}

	void	merge(List& x)
	{
		iterator    xb = x.begin();
		iterator	b = begin();

		while (b != end())
		{
			while (xb != x.end() && *xb <= *b)
			{
				insert(b, *xb);
				xb = x.erase(xb);
			}
			b++;
		}
		while (xb != x.end())
		{
			insert(end(), *xb);
			xb = x.erase(xb);
		}
	}

	template <class Compare> void
	merge (List& x, Compare comp)
	{
		iterator    xb = x.begin();
        iterator    b = begin();

        while (b != end())
        {
            while (xb != x.end() && comp(*xb ,*b))
            {
                insert(b, *xb);
                xb = x.erase(xb);
            }
            b++;
        }
        while (xb != x.end())
        {
            insert(end(), *xb);
            xb = x.erase(xb);
        }
	}
	void	reverse(void)
	{
		iterator b = begin();
		iterator e = --end();
		value_type	*temp;
		size_t	iters = _size / 2;

		while (iters)
		{
			temp = b._node->_value;
			b._node->_value = e._node->_value;
			e._node->_value = temp;
			iters--;
			e--;
			b++;
		}
	}

protected:
	std::size_t				_size;
	node_type				_node;
	node_allocator  		_node_alloc;

private:

	template <class InputIterator> void
	insert_help(iterator position, InputIterator first, InputIterator last, std::__false_type)
	{
		while (first != last)
		{
			insert(position, *first);
			first++;
		}
	}

	template <class InputIterator> void
	insert_help(iterator position, InputIterator first, InputIterator last, std::__true_type)
	{
		node_type   *temp;

        _size += first;
        while (first--)
        {
            temp = _node_alloc.allocate(1);
            temp->hook(position, last);
        }
	}

	template <class InputIterator> void
	assign_constructor_call(InputIterator first, InputIterator last, std::__false_type)
	{
		_size = 0;
		for (; first != last; ++first)
			push_back(*first);
	}

	template <class InputIterator> void
	assign_constructor_call(InputIterator first, InputIterator last, std::__true_type)
	{ while (first--) insert(end(), last); }

	template <class InputIterator> void
	assign_elements(InputIterator first, InputIterator last, std::__true_type)
	{
		size_type			n = first;
		const value_type	&val = last;
		iterator 			_list_begin = begin();

		_size = 0;
		for (; _list_begin != end() && n; _list_begin++, n--, _size++)
				*_list_begin = val;
		if (_list_begin == end() && n)
			while (n--)
				insert(end(), val);
		else if (_list_begin != end() && !n)
			while (_list_begin != end())
				_list_begin = erase(_list_begin);
	}
	template <class InputIterator> void
	assign_elements(InputIterator first, InputIterator last, std::__false_type)
	{
		iterator            _list_begin = begin();

		_size = 0;
		for (; first != last && _list_begin != end(); first++, _list_begin++, _size++)
			*_list_begin = *first;
		if (first == last && _list_begin != end())
			while (_list_begin != end())
				_list_begin = erase(_list_begin);
		else if (first != last)
			while (first != last)
			{
				push_back(*first);
				first++;
			}
	}
	const_iterator	cbegin(void) const { return const_iterator(_node._next); }
	const_iterator	cend(void) const { return const_iterator(&_node); }
#if 0
	void SplitList(node_type *source, node_type **front, node_type **back)
	{
		node_type* ptr2 = source;
		node_type* ptr1 = source->_next;

		while (ptr1 != &_node)
		{
			ptr1 = ptr1->_next;
			if (ptr1 != &_node) {
				ptr2 = ptr2->_next;
				ptr1 = ptr1->_next;
			}
		}
		*front = source;
		*back = ptr2->_next;
		ptr2->_next = &_node;
	}

	node_type *MergeSortedList(node_type *first, node_type *second)
	{
		if (first == &_node)
		{
			_node._prev = first->_prev;
            return second;
		}
        if (second == &_node)
		{
			_node._prev = second->_prev;
            return first;
		}
		if (*first->_value < *second->_value)
		{
			first->_next = MergeSortedList(first->_next, second);
			first->_next->_prev = first;
			first->_prev = &_node;
			_node._prev = first->_next;
			return first;
		}
		else
		{
			second->_next = MergeSortedList(first, second->_next);
			second->_next->_prev = second;
			second->_prev = &_node;
			_node._prev = second->_next;
			return second;
		}
	}

	void	MergeSort(node_type **shead)
	{
		node_type	*head = *shead;
		node_type	*p1;
		node_type	*p2;

		if (head == &_node || head->_next == &_node)
			return ;
		SplitList(head, &p1, &p2);
		MergeSort(&p1);
		MergeSort(&p2);
		*shead = MergeSortedList(p1, p2);
	}

	template <class Compare>
	node_type *MergeSortedList(node_type *first, node_type *second, Compare comp)
	{
		if (first == &_node)
			return second;
		if (second == &_node)
			return first;
		if (comp(*second->_value, *first->_value))
		{
			second->_next = MergeSortedList(first, second->_next, comp);
			second->_next->_prev = second;
			second->_prev = &_node;
			_node._prev = first->_next;
			return second;
		}
		else
		{
			first->_next = MergeSortedList(first->_next, second, comp);
			first->_next->_prev = first;
			first->_prev = &_node;
			_node._prev = second->_next;
			return first;
		}
	}

	template <class Compare>
	void    MergeSort(node_type **shead, Compare comp)
	{
		node_type	*head = *shead;
		node_type	*p1;
		node_type	*p2;

		if (head == &_node || head->_next == &_node)
			return ;
		SplitList(head, &p1, &p2);
		MergeSort(&p1, comp);
		MergeSort(&p2, comp);
		*shead = MergeSortedList(p1, p2, comp);
	}
#endif
};

template <class T, class Alloc>
inline bool	operator==(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	if (x.size() != y.size())
		return false;

	typename List<T, Alloc>::const_iterator	xb = x.begin();
	typename List<T, Alloc>::const_iterator	xe = x.end();
	typename List<T, Alloc>::const_iterator	yb = y.begin();
	typename List<T, Alloc>::const_iterator	ye = y.end();

	while (xb != xe && yb != ye && *yb == *xb)
	{
		xb++;
		yb++;
	}
	return xb == xe && yb == ye;
}

template <class T, class Alloc>
inline bool operator!=(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	return !(x == y);
}

template<class T, class Alloc>
inline bool	operator<(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<class T, class Alloc>
inline bool operator<=(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	return !(y < x);
}

template<class T, class Alloc>
inline bool operator>(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	return y < x;
}

template<class T, class Alloc>
inline bool operator>=(const List<T, Alloc>& x, const List<T, Alloc>& y)
{
	return !(x < y);
}

template <class T, class Alloc>
inline void	swap(List<T, Alloc>& x, List<T, Alloc>& y)
{
	x.swap(y);
}

} // ft 

#endif
