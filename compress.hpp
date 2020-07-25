
#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cassert>
#include <iterator>

using namespace std;

namespace itertools{

	template<typename T> struct is_bool {
		static const bool value = false;
	};

	template<> struct is_bool<bool>
    {
		static const bool value = true;
	};


	template <typename Container,typename ContainerBool>
	class compress
    {
		
		private:
            const ContainerBool& containerbool;
			const Container& container;
			
		public:
			compress(const Container& cont,const ContainerBool& cb ):container(cont),containerbool(cb)
			{

			}

		class iterator
        {
			private:
				decltype(container.begin()) beg;
				decltype(container.end()) end;
                decltype(containerbool.begin()) beg_bool;
				decltype(containerbool.end()) end_bool;

			public:
				iterator(decltype(container.begin()) p,decltype(container.end()) end,
                decltype(containerbool.begin()) p_bool,decltype(containerbool.end()) end_bool):
					beg(p),end(end),beg_bool(p_bool),end_bool(end_bool)
					{

					}
				iterator& operator++()
				{
					cout<< "++operator "<<endl;
                    ++beg;
                    ++beg_bool;
                    while(!*beg_bool && beg_bool!=end_bool)
                    {
                        ++beg;
                        ++beg_bool;
                    }
					return *this;
				}
				iterator operator++(int)
				{
					cout<< "operator ++"<<endl;
					iterator tmp= *this;
                    beg++;
                    beg_bool++;
                    while(!*beg_bool && beg_bool!=end_bool){
                        ++beg;
                        ++beg_bool;
                    }
					return tmp;
				}

                auto operator*()
                {
					cout<<"iterator compress *\n"<<endl;
                    if(!*beg_bool && beg!=end)
                    {
                        (*this)++;
                    }
                    return *beg;
				}

				bool operator==(const iterator& it) const
				{
					return beg == it.beg;
				}

				bool operator!=(const iterator& it)  const
				{
					return beg != it.beg;
				}
			};

			iterator begin() const
			{
				cout<<"iterator compress begin\n"<<endl;
				return iterator(container.begin(),container.end(),containerbool.begin(),containerbool.end());
			}

			iterator end() const
			{
				cout<<"iterator compress end\n"<<endl;
				return iterator(container.end(),container.end(),containerbool.end(),containerbool.end());
			}
	};
}


