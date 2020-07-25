#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

namespace itertools
{
	class range
    {
		public:
			int start;
			int finish;

			range(int x,int y):start(x),finish(y)
			{

			}

	class iterator
    {
		private:
			int current;
		public:

			iterator(int num)
			    : current(num)
				{

				}
			int operator*() const
			{
				return current;
			}
			iterator& operator++()
			{
				(current)++;
				return *this;
			}
			const iterator operator++(int)
			{
				iterator temp = *this;
                current++;
				return temp;
			}

			bool operator==(const iterator& i) const
			{
				return current == i.current;
			}

			bool operator!=(const iterator& i) const
			{
				return current != i.current;
			}
		};

		iterator begin() const
		{
			return iterator{start};
		}
		
		iterator end() const
		{
			return iterator{finish};
		}
	};
}