#include "set.h"

using namespace std;

	typedef int value_type;
	typedef std::size_t size_type;

	set::set(size_type initial_capacity)
	{
		 data=new value_type[capacity]; // pointer that points to array, and lets there be data from the "heap"
		 used=0; // How much of array is used
		 capacity=initial_capacity;
	}
	// postcondition: empty set with initial_capacity having been created

	set::~set()
	{
		delete[] data;
	}
	// postcondition: all dynamically allocated memory has been deallocated

	set::set(const set& s)
	{
		used = s.used;
		data = s.data;
		capacity = s.capacity;

	}
	// copy of s has been created;

	set& set::operator= (const set& s)
	{
		set s2(s);
		return s2; //calling other constructor and return s2, copying.
	}
	// postcondition: exact copy of s has been assigned to the current set object

	bool set::erase(const value_type& target)
	{
		if (contains(target))
		{
			for (int i = 0; i < used; i++)
			{
				if (target == data[i]) //look through to find target, since it's contained we are trying to erase it, so we set used to used -1
				{
					data[i] = data[used - 1];
					return true;
				}
			}	
		}
		else
		{
			return false;
		}
	}
	// postcondition: returned true if target was removed from set or false if target was not in the set

	bool set::contains(const value_type& target) const
	{
		for (int i =0; i < used; i++)
		{
			if (data[i] == target)
			{
				return true;
			}
		}
		return false;
	}
	bool set::insert(const value_type& entry)
	{	
		for (int i = 0; i < used; i++)
		{
			if (data[i] == entry)
			{
				return true;
			}
			if (i == used)
			{
				reserve(i + 1);
				data[i] = entry;
				used++;
				return true;
			}
			
		}
		return false;

	}
	// postcondition: if entry was not in the set, then entry has been added - or nothing was done

	void set::operator+= (const set& addend)
	{

	}

	// postcondition: non-duplicating elements from addend have been added to the set

	size_type set::size() const
	{
		return size_type();
	}
	// postcondition: number of elements in the set has been returned
	void set::reserve(size_type new_capacity)
	{
		value_type* data2;
		data2 = new value_type[new_capacity];
		data = data2;
		delete[] data2;

	}
	// precondition: size() <= new_capacity
	// postcondition: capacity is new_capacity

	
	// postcondition: returned whether target is in the set

	std::ostream& operator<<(std::ostream& output, const set& s)
	{
		output << s.data;
		return output;

	 }


