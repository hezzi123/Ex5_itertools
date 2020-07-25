
#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>
#include <iterator>

using namespace std;

namespace itertools
{
	template <typename Function,typename Container>
	class filterfalse
    {
		private:
            const Function& f;
			const Container& container;
			
		public:
			filterfalse(const Function& f,const Container& cont ):container(cont),f(f)
			{

			}

		class iterator
        {
			private:
				decltype(container.begin()) beg;
				decltype(container.end()) end;
				Function f;

			public:
				iterator(decltype(container.begin()) p,decltype(container.end()) end,Function f):
					beg(p),end(end),f(f)
					{

					}
				iterator& operator++()
				{
                    ++beg;
                    while(f(*beg) && beg!=end)
                    {
                        ++beg;
                    }
					return *this;
				}
				iterator operator++(int)
				{
					iterator tmp= *this;
                    beg++;
                    while(f(*beg) && beg!=end)
                    {
                        beg++;
                    }
					return tmp;
				}

                auto operator*()
                {
                    if(f(*beg)&& beg!=end)
                    {
                        (*this)++;
                    }
                    return *beg;
				}

				bool operator==(const iterator& it) const
				{
					return beg == it.beg;
				}

				bool operator!=(const iterator& it) const
				{
					return beg != it.beg;
				}
			};

			iterator begin()const
			{
				return iterator(container.begin(),container.end(),f);
			}

			iterator end() const
			{
				return iterator(container.end(),container.end(),f);
			}
	};
}


