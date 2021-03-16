#ifndef QUEUE_HPP
# define QUEUE_HPP

# include <deque>

namespace ft
{

template <class T, class Container = std::deque<T> >
class Queue
{
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef std::size_t	size_type;

	explicit	Queue(const container_type& ctnr = container_type()) : _queue(ctnr) { }

	bool		empty(void) { return _queue.empty(); }

	size_type	size(void) const { return _queue.size(); }

	value_type	&front(void) { return _queue.front(); }

	const value_type	&front(void) const { return _queue.front(); }

	void		push(const value_type &val) { _queue.push_back(val); }

	void		pop(void) { _queue.pop_front(); }

	template <class value_type, class container_type> friend bool
	operator==(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue == rhs._queue;
	}

	template <class value_type, class container_type> friend bool
	operator!=(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue != rhs._queue;
	}

	template <class value_type, class container_type> friend bool
	operator<(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue < rhs._queue;
	}

	template <class value_type, class container_type> friend bool
	operator<=(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue <= rhs._queue;
	}

	template <class value_type, class container_type> friend bool
	operator>(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue > rhs._queue;
	}

	template <class value_type, class container_type> friend bool
	operator>=(const Queue<value_type, container_type>& lhs, const Queue<value_type, container_type>& rhs)
	{
		return lhs._queue >= rhs._queue;
	}


private:
	container_type	_queue;
};

}//ft

#endif
