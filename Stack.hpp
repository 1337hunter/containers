#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

namespace ft
{

template <class T, class Container = std::deque<T> >
class Stack
{
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef std::size_t	size_type;

	explicit	Stack(const container_type& ctnr = container_type()) : _stack(ctnr) { }

	bool		empty(void) { return _stack.empty(); }

	size_type	size(void) const { return _stack.size(); }

	value_type	&top(void) { return _stack.back(); }

	const value_type	&top(void) const { return _stack.back(); }

	void		push(const value_type &val) { _stack.push_back(val); }

	void		pop(void) { _stack.pop_back(); }

	template <class value_type, class container_type> friend bool
	operator==(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack == rhs._stack;
	}

	template <class value_type, class container_type> friend bool
	operator!=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack != rhs._stack;
	}

	template <class value_type, class container_type> friend bool
	operator<(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack < rhs._stack;
	}

	template <class value_type, class container_type> friend bool
	operator<=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack <= rhs._stack;
	}

	template <class value_type, class container_type> friend bool
	operator>(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack > rhs._stack;
	}

	template <class value_type, class container_type> friend bool
	operator>=(const Stack<value_type, container_type>& lhs, const Stack<value_type, container_type>& rhs)
	{
		return lhs._stack >= rhs._stack;
	}


private:
	container_type	_stack;
};

}//ft

#endif
