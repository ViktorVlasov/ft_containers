#include "list_iterator.hpp"

namespace ft 
{
	template < class T, class Alloc = std::allocator<T> >
	class List
	{
	private:
		template<typename T>
		class Node
		{
		public:
			Node *pNext;
			Node *pPrev;
			T data;
			
			Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
				this->pPrev = pPrev;
			}
			~Node();
		};
	
	public:
		typedef T                                               value_type;
		typedef Alloc                                           allocator_type;
		typedef size_t                                          size_type;
		typedef T*                                              pointer;
		typedef const T*                                        const_pointer;
		typedef T&                                              reference;
		typedef const T&                                        const_reference;
		typedef ft::list_iterator<T, Node, T*, T&>              iterator;
		typedef ft::list_iterator<T, Node, const T*, const T&>  const_iterator;
		//typedef fl::reverse_iterator<iterator>                  reverse_iterator;
		//typedef fl::reverse_iterator<const_iterator>            const_reverse_iterator;
		//typedef ptrdiff_t                                       difference_type;
		typedef Node                                            node;
		
	private: 
		size_t _size;
		allocator_type _alloc;
		Node<T>* _head;
		Node<T>* _tail;
	
	public:
		explicit List(const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc)
		List() 
		{
			_head = new node();
			_tail = _head;
		}

		explicit List(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc)
		{
			this->last_ = new node();
			while (n--)
				push_back(val);
		}

		~list()
		{
			//while (size_ > 0)
				//pop_back();
			//delete this->last_;
		}

		void push_back(const value_type& val);

		size_type size() const
		{
			return (size)
		}

		template<class T, class Alloc>
		size_type max_size() const
		{
			const long pageCount = sysconf( _SC_PHYS_PAGES );
			const long pageSize = sysconf( _SC_PAGE_SIZE );
			const unsigned long long totalBytes = pageCount * pageSize;
			const unsigned long long maxPossibleObjects = bytesAvailable / sizeof(T);
			return maxPossibleObjects;
		}



		void push_back(const T& val)
	{
		if (!head)
		{
			head = new Node<T>(val);
		}
		else
		{
			Node<t> *current = this->head;
			
			while (current->pNext)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}

		size++;
	}

	};
}