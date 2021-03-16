#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include <limits>

namespace ft
{

template <class Key, class T>
struct rbtree_node
{
	rbtree_node	*left;
	rbtree_node	*right;
	rbtree_node	*p;
	int			color;
	std::pair<const Key, T>	value;

	rbtree_node(const std::pair<const Key, T>& val, rbtree_node<const Key, T> * nil, int color) :
		left(nil), right(nil), p(nil), color(color), value(val) { }
	rbtree_node(const rbtree_node<Key, T>& x) :
		left(x.left), right(x.right), p(x.p), color(x.color), value(x.value) { }
	~rbtree_node(void) { }

	rbtree_node<Key, T>
	&operator=(const rbtree_node<Key, T>& x)
	{
		left = x.left;
		right = x.right;
		p = x.p;
		color = x.color;
		value = x.value;
		return *this;
	}
};

template <class Key, class T>
struct	map_iterator
{
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef std::pair<const key_type, mapped_type>  value_type;
	typedef	std::pair<const key_type, mapped_type>*	pointer;
	typedef	std::pair<const key_type, mapped_type>&	reference;
	typedef map_iterator<key_type, mapped_type>		_Self;
	typedef rbtree_node<key_type, mapped_type>		_Node;
	typedef rbtree_node<key_type, mapped_type>*		_Node_pointer;

				map_iterator(void) : _node(0), _rbegin(0), _nil(0) { }
				map_iterator(const _Self &o) :
					_node(o._node), _rbegin(o._rbegin), _nil(o._nil) { }
				map_iterator(_Node_pointer node, _Node_pointer rb, _Node_pointer nil) :
					_node(node), _rbegin(rb), _nil(nil) { }
	virtual		~map_iterator(void) { }

	_Self		&operator=(const _Self &o) { _node = o._node; _nil = o._nil; return *this; }

	reference	operator*(void) const { return _node->value; }

	pointer		operator->(void) const { return &_node->value; }

	_Self		&operator++(void)
	{
		if (_node == _nil)
			return *this;
		if (_node->right == _nil)
		{
			while (_node->p != _nil && _node == _node->p->right)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->right;
			while (_node->left != _nil)
				_node = _node->left;
		}
		return *this;
	}

	_Self		operator++(int)
	{
		_Self temp = *this;
		operator++();
		return temp;
	}

	_Self		&operator--(void)
	{
		if (_node == _nil)
		{
			_node = _rbegin;
			return *this;
		}
		if (_node->left == _nil)
		{
			while (_node->p != _nil && _node == _node->p->left)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->left;
			while (_node->right != _nil)
				_node = _node->right;
		}
		return *this;
	}

	_Self		operator--(int)
	{
		_Self	temp = *this;
		operator--();
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node_pointer	_node;
	_Node_pointer	_rbegin;
	_Node_pointer	_nil;
};

template <class Key, class T>
struct	map_const_iterator
{
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef std::pair<const key_type, mapped_type>  value_type;
	typedef	const value_type*	pointer;
	typedef	const value_type&	reference;
	typedef map_const_iterator<key_type, mapped_type>		_Self;
	typedef rbtree_node<key_type, mapped_type>		_Node;
	typedef rbtree_node<key_type, mapped_type>*		_Node_pointer;

				map_const_iterator(void) : _node(0), _rbegin(0), _nil(0) { }
				map_const_iterator(const _Self &o) :
					_node(o._node), _rbegin(o._rbegin), _nil(o._nil) { }
				map_const_iterator(_Node_pointer node, _Node_pointer rb, _Node_pointer nil) :
					_node(node), _rbegin(rb), _nil(nil) { }
	virtual		~map_const_iterator(void) { }

	_Self		&operator=(const _Self &o) { _node = o._node; _nil = o._nil; return *this; }

	reference	operator*(void) const { return _node->value; }

	pointer		operator->(void) const { return &_node->value; }

	_Self		&operator++(void)
	{
		if (_node == _nil)
			return *this;
		if (_node->right == _nil)
		{
			while (_node->p != _nil && _node == _node->p->right)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->right;
			while (_node->left != _nil)
				_node = _node->left;
		}
		return *this;
	}

	_Self		operator++(int)
	{
		_Self temp = *this;
		operator++();
		return temp;
	}

	_Self		&operator--(void)
	{
		if (_node == _nil)
		{
			_node = _rbegin;
			return *this;
		}
		if (_node->left == _nil)
		{
			while (_node->p != _nil && _node == _node->p->left)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->left;
			while (_node->right != _nil)
				_node = _node->right;
		}
		return *this;
	}

	_Self		operator--(int)
	{
		_Self	temp = *this;
		operator--();
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node_pointer	_node;
	_Node_pointer	_rbegin;
	_Node_pointer	_nil;
};

template <class Key, class T>
struct	map_reverse_iterator
{
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef std::pair<const key_type, mapped_type>  value_type;
	typedef	value_type*				pointer;
	typedef	value_type&				reference;
	typedef map_reverse_iterator<key_type, mapped_type>		_Self;
	typedef rbtree_node<key_type, mapped_type>		_Node;
	typedef rbtree_node<key_type, mapped_type>*		_Node_pointer;

				map_reverse_iterator(void) : _node(0), _rbegin(0), _nil(0) { }
				map_reverse_iterator(const _Self &o) :
					_node(o._node), _rbegin(o._rbegin), _nil(o._nil) { }
				map_reverse_iterator(_Node_pointer node, _Node_pointer rb, _Node_pointer nil) :
					_node(node), _rbegin(rb), _nil(nil) { }
	virtual		~map_reverse_iterator(void) { }

	_Self		&operator=(const _Self &o) { _node = o._node; _nil = o._nil; return *this; }

	reference	operator*(void) const { return _node->value; }

	pointer		operator->(void) const { return &_node->value; }

	_Self		&operator++(void)
	{
		if (_node == _nil)
			return *this;
		if (_node->left == _nil)
		{
			while (_node->p != _nil && _node == _node->p->left)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->left;
			while (_node->right != _nil)
				_node = _node->right;
		}
		return *this;
	}

	_Self		operator++(int)
	{
		_Self temp = *this;
		operator++();
		return temp;
	}

	_Self		&operator--(void)
	{
		if (_node == _nil)
		{
			_node = _rbegin;
			return *this;
		}
		if (_node->right == _nil)
		{
			while (_node->p != _nil && _node == _node->p->right)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->right;
			while (_node->left != _nil)
				_node = _node->left;
		}
		return *this;
	}

	_Self		operator--(int)
	{
		_Self	temp = *this;
		operator--();
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node_pointer	_node;
	_Node_pointer	_rbegin;
	_Node_pointer	_nil;
};

template <class Key, class T>
struct	map_const_reverse_iterator
{
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef std::pair<const key_type, mapped_type>  value_type;
	typedef	value_type*				pointer;
	typedef	value_type&				reference;
	typedef map_const_reverse_iterator<key_type, mapped_type>		_Self;
	typedef rbtree_node<key_type, mapped_type>		_Node;
	typedef rbtree_node<key_type, mapped_type>*		_Node_pointer;

				map_const_reverse_iterator(void) : _node(0), _rbegin(0), _nil(0) { }
				map_const_reverse_iterator(const _Self &o) :
					_node(o._node), _rbegin(o._rbegin), _nil(o._nil) { }
				map_const_reverse_iterator(_Node_pointer node, _Node_pointer rb, _Node_pointer nil) :
					_node(node), _rbegin(rb), _nil(nil) { }
	virtual		~map_const_reverse_iterator(void) { }

	_Self		&operator=(const _Self &o) { _node = o._node; _nil = o._nil; return *this; }

	reference	operator*(void) const { return _node->value; }

	pointer		operator->(void) const { return &_node->value; }

	_Self		&operator++(void)
	{
		if (_node == _nil)
			return *this;
		if (_node->left == _nil)
		{
			while (_node->p != _nil && _node == _node->p->left)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->left;
			while (_node->right != _nil)
				_node = _node->right;
		}
		return *this;
	}

	_Self		operator++(int)
	{
		_Self temp = *this;
		operator++();
		return temp;
	}

	_Self		&operator--(void)
	{
		if (_node == _nil)
		{
			_node = _rbegin;
			return *this;
		}
		if (_node->right == _nil)
		{
			while (_node->p != _nil && _node == _node->p->right)
				_node = _node->p;
			_node = _node->p;
		}
		else
		{
			_node = _node->right;
			while (_node->left != _nil)
				_node = _node->left;
		}
		return *this;
	}

	_Self		operator--(int)
	{
		_Self	temp = *this;
		operator--();
		return temp;
	}

	friend bool	operator==(const _Self &a, const _Self &b) { return a._node == b._node; }
	friend bool	operator!=(const _Self &a, const _Self &b) { return a._node != b._node; }

	_Node_pointer	_node;
	_Node_pointer	_rbegin;
	_Node_pointer	_nil;
};


template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
class Map
{
private:
	typedef rbtree_node<const Key, T>    _Node;

public:
	typedef Key		key_type;
	typedef T		mapped_type;
	typedef std::pair<const key_type, mapped_type>	value_type;
	typedef Compare	key_compare;
	typedef Alloc	allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef map_iterator<const key_type, mapped_type>			iterator;
	typedef map_const_iterator<const key_type, mapped_type>		const_iterator;
	typedef map_reverse_iterator<const key_type, mapped_type>	reverse_iterator;
	typedef map_const_reverse_iterator<const key_type, mapped_type>		const_reverse_iterator;
	typedef std::ptrdiff_t						difference_type;
	typedef std::size_t							size_type;

	explicit	Map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
		_nil(new _Node(value_type(), 0, 0)), _root(_nil), _comp(comp), _alloc(alloc), _size(0)
	{
	}

	template <class InputIterator>
	Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) :
		_nil(new _Node(value_type(), 0, 0)), _root(_nil), _comp(comp), _alloc(alloc), _size(0)
	{
		for (; first != last; first++)
			insert(*first);
	}

	Map(const Map& x) :
		_nil(new _Node(value_type(), 0, 0)), _root(_nil), _comp(x._comp), _alloc(x._alloc), _size(0)
	{
		for (const_iterator i = x.begin(); i != x.end(); i++)
			insert(*i);
	}

	~Map(void) {  clear(); delete _nil; }

	Map		&operator=(const Map &o)
	{
		clear();
		for (const_iterator i = o.begin(); i != o.end(); i++)
			insert(*i);
		return *this;
	}

	mapped_type&	operator[](const key_type& k)
	{
		return (insert(value_type(k, mapped_type()))).first->second;
	}

	iterator	begin(void) { return iterator(rbtree_min(_root), rbtree_max(_root), _nil); }

	iterator	end(void) { return iterator(_nil, rbtree_max(_root), _nil); }

	const_iterator 		begin(void) const
	{
		return const_iterator(rbtree_min(_root), rbtree_max(_root), _nil);
	}

	const_iterator		end(void) const
	{
		return const_iterator(_nil, rbtree_max(_root), _nil);
	}

	reverse_iterator	rbegin(void)
	{
		return reverse_iterator(rbtree_max(_root), rbtree_min(_root), _nil);
	}

	reverse_iterator	rend(void)
	{
		return reverse_iterator(_nil, rbtree_min(_root), _nil);
	}

	const_reverse_iterator	rbegin(void) const
	{
		 return const_reverse_iterator(rbtree_max(_root), rbtree_min(_root), _nil);
	}

	const_reverse_iterator	rend(void) const
	{
		return const_reverse_iterator(_nil, rbtree_min(_root), _nil);
	}

	std::pair<iterator, bool>
	insert(const value_type& val)
	{
		std::pair<iterator, bool> ret = rbtree_insert(val);
		if (ret.second == true)
			_size++;
		return ret;
	}

	void	erase(iterator position)
	{
		rbtree_delete(position._node);
		_size--;
		delete position._node;
	}

	size_type	erase(const key_type& k)
	{
		iterator	i;
		iterator	temp;
		size_type	n = 0;

		i = begin();
		while (i != end())
			if (i->first == k)
			{
				temp = i;
				temp++;
				erase(i);
				i = temp;
				n++;
				return n;
			}
			else
				i++;
		return n;
	}

	void	erase(iterator first, iterator last)
	{
		_Node	*del;

		while (first != last)
		{
			del = first._node;
			first++;
			rbtree_delete(del);
			_size--;
			delete del;
		}
	}

	void	clear(void)
	{
		iterator i = begin();

		while (i != end())
		{
			rbtree_delete(i._node);
			delete i._node;
			i = begin();
		}
		_size = 0;
		_root = _nil;
	}
	
	bool		empty(void) const { return !_size; }

	size_type	size(void) const { return _size; }

	size_type	max_size(void)
	{
		return (std::numeric_limits<std::size_t>::max() / 6) / sizeof(_Node);
	}

	void		swap(Map &x)
	{
		Map	temp;

		temp = *this;
		*this = x;
		x = temp;
	}

	iterator		find(const key_type &k)
	{
		for (iterator i = begin(); i != end(); i++)
			if (i->first == k)
				return i;
		return end();
	}

	const_iterator	find(const key_type &k) const
	{
		for (const_iterator i = begin(); i != end(); i++)
			if (i->first == k)
				return i;
		return end();
	}

	size_type		count(const key_type &k) const
	{
		for (const_iterator i = begin(); i != end(); i++)
			if (i->first == k)
				return 1;
		return 0;
	}

	iterator		upper_bound(const key_type& k)
	{
		iterator	i = begin();
		for (; i != end(); i++)
            if (i->first == k)
				break ;
		if (i == end())
			return i;
		i++;
		return i;
	}

	const_iterator	upper_bound(const key_type& k) const
	{
		const_iterator	i = begin();
		for (; i != end(); i++)
            if (i->first == k)
				break ;
		if (i == end())
			return i;
		i++;
		return i;
	}

	iterator	lower_bound(const key_type& k)
	{
		iterator    i = begin();
		for (; i != end(); i++)
			if (i->first == k)
				return i;
		return i;
	}

	const_iterator	lower_bound(const key_type& k) const
	{
		const_iterator    i = begin();
		for (; i != end(); i++)
			if (i->first == k)
				return i;
		return i;
	}

	std::pair<iterator, iterator>
	equal_range(const key_type& k)
	{
		std::pair<iterator, iterator>	ret;
		ret.first = lower_bound(k);
		ret.second = upper_bound(k);
		return ret;
	}

	std::pair<const_iterator, const_iterator>
	equal_range(const key_type& k) const
	{
		std::pair<const_iterator, const_iterator>	ret;
		ret.first = lower_bound(k);
		ret.second = upper_bound(k);
		return ret;
	}

	key_compare	key_comp(void) const { return _comp; }

private:
	_Node			*_nil;
	_Node			*_root;
	key_compare		_comp;
	allocator_type	_alloc;
	size_type		_size;

	_Node	*rbtree_min(_Node *node) const
	{
		if (node == _nil)
			return node;
		while (node->left != _nil)
			node = node->left;
		return node;
	}

	_Node	*rbtree_max(_Node *node) const
	{
		if (node == _nil)
			return node;
		while (node->right != _nil)
			node = node->right;
		return node;
	}

	std::pair<iterator, bool>
	rbtree_insert(const value_type& val)
	{
		_Node	*y = _nil;
		_Node	*x = _root;
		_Node	*z = 0;
		std::pair<iterator, bool>   ret;

		while (x != _nil)
		{
			y = x;
			if (val.first < x->value.first)
				x = x->left;
			else if (val.first > x->value.first)
				x = x->right;
			else
			{
				ret.first = iterator(x, rbtree_max(_root), _nil);
				ret.second = false;
				return ret;
			}
		}
		z = new _Node(val, _nil, 1);
		z->p = y;
		if (y == _nil)
			_root = z;
		else if (z->value.first < y->value.first)
			y->left = z;
		else
			y->right = z;
		ret.first = iterator(z, rbtree_max(_root), _nil);
		rbtree_insert_fixup(z);
		_size++;
		return ret;
	}

	void
	rbtree_insert_fixup(_Node *z)
	{
		_Node	*y;
		while (z->p->color)
		{
			if (z->p == z->p->p->left)
			{
				y = z->p->p->right;
				if (y->color)
				{
					z->p->color = 0;
					y->color = 0;
					z->p->p->color = 1;
					z = z->p->p;
				}
				else
				{
					if (z == z->p->right)
					{
						z = z->p;
						rbtree_left_rotate(z);
					}
					z->p->color = 0;
					z->p->p->color = 1;
					rbtree_right_rotate(z->p->p);
				}
			}
			else
			{
				y = z->p->p->left;
				if (y->color)
				{
					y->color = 0;
					z->p->color = 0;
					z->p->p->color = 1;
					z = z->p->p;
				}
				else
				{
					if (z == z->p->left)
					{
						z = z->p;
						rbtree_right_rotate(z);
					}
					z->p->color = 0;
					z->p->p->color = 1;
					rbtree_left_rotate(z->p->p);
				}
			}
		}
		_root->color = 0;
	}

	void
	rbtree_left_rotate(_Node *x)
	{
		_Node	*y = x->right;

		x->right = y->left;
		if (y->left != _nil)
			y->left->p = x;
		y->p = x->p;
		if (x->p == _nil)
			_root = y;
		else if (x == x->p->left)
			x->p->left = y;
		else
			x->p->right = y;
		y->left = x;
		x->p = y;

	}
	
	void
	rbtree_right_rotate(_Node *y)
	{
		_Node   *x = y->left;

		y->left = x->right;
		if (x->left != _nil)
			x->right->p = y;
		x->p = y->p;
		if (y->p == _nil)
			_root = x;
		else if (y == y->p->left)
			y->p->left = x;
		else
			y->p->right = x;
		x->right = y;
		y->p = x;
	}

	void
	rbtree_transplant(_Node *u, _Node *v)
	{
		if (u->p == _nil)
			_root = v;
		else if (u == u->p->left)
			u->p->left = v;
		else
			u->p->right = v;
		v->p = u->p;
	}

	void
	rbtree_delete(_Node *z, bool fixup = true)
	{
		_Node	*y = z;
		_Node	*x = 0;
		int		color = y->color;

		if (z->left == _nil)
		{
			x = z->right;
			rbtree_transplant(z, z->right);
		}
		else if (z->right == _nil)
		{
			x = z->left;
			rbtree_transplant(z, z->left);
		}
		else
		{
			y = rbtree_min(z->right);
			color = y->color;
			x = y->right;
			if (y->p == z)
				x->p = y;
			else
			{
				rbtree_transplant(y, y->right);
				y->right = z->right;
				y->right->p = y;
			}
			rbtree_transplant(z, y);
			y->left = z->left;
			y->left->p = y;
			y->color = z->color;
		}
		if (!color && fixup)
			rbtree_delete_fixup(x);
	}

	void
	rbtree_delete_fixup(_Node *x)
	{
		_Node	*w = 0;

		while (x != _root && !x->color)
		{
			if (x == x->p->left)
			{
				w = x->p->right;
				if (w->color)
				{
					w->color = 0;
					x->p->color = 1;
					rbtree_left_rotate(x->p);
					w = x->p->right;
				}
				if (!w->left->color && !w->right->color)
				{
					w->color = 1;
					x = x->p;
				}
				else
				{
					if (!w->right->color)
					{
						w->left->color = 0;
						w->color = 1;
						rbtree_right_rotate(w);
						w = x->p->right;
					}
					w->color = x->p->color;
					x->p->color = 0;
					w->right->color = 0;
					rbtree_left_rotate(x->p);
					x = _root;
				}
			}
			else
			{
				w = x->p->left;
				if (w->color)
				{
					w->color = 0;
					x->p->color = 1;
					rbtree_right_rotate(x->p);
					w = x->p->right;
				}
				if (!w->right->color && !w->left->color)
				{
					w->color = 1;
					x = x->p;
				}
				else
				{
					if (!w->left->color)
					{
						w->right->color = 0;
						w->color = 1;
						rbtree_left_rotate(w);
						w = x->p->right;
					}
					w->color = x->p->color;
					x->p->color = 0;
					w->left->color = 0;
					rbtree_right_rotate(x->p);
					x = _root;
				}
			}
		}
		x->color = 0;
	}
};

}//ft

#endif
