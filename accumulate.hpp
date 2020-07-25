#ifndef ACCU_H
#define ACCU_H
#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include <iterator>

using namespace std;


namespace itertools
{

	typedef struct
	{
		template<typename T>
		T operator ()(T x,T y)const
		{
			return x+y;
		}
	}plus;

	template <typename Container,typename Function = plus>
	class accumulate
    {
		private:
		    const Container& container;
			const Function& f;

		public:
			accumulate(const Container& cont, const Function& f = plus()):container(cont),f(f)
			{

			}
		class iterator
        {
			private:
				typename decay<decltype(*(container.begin()))>::type sum;
				decltype(container.begin()) beg;
				decltype(container.end()) end;
				Function f;

			public:

				iterator(decltype(container.begin()) p,decltype(container.end()) end,Function f):
					beg(p),end(end),f(f)
					{
						if(p!=end)
						{
							sum=*p;
						}
					}
				auto operator*() const
				{
					return sum;
				}

				iterator& operator++()
				{
					++beg;
					if(beg!=end)
					{
						sum=f(sum,*(beg));
					}
					return *this;
				}

				iterator operator++(int)
				{
					iterator tmp= *this;
                    beg++;
					sum=f(sum,*(beg));
					return tmp;
				}

				bool operator==(const iterator& it)  const
				{
					return beg == it.beg;
				}

				bool operator!=(const iterator& it) const
				{
					return beg != it.beg;
				}
			};

			iterator begin() const
			{
				return iterator(container.begin(),container.end(),f);
				
			}

			iterator end() const
			{
				return iterator(container.end(),container.end(),f);
			}
	};
}

#endif

