#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	int m_;
	PComparator c_;
	std::vector<T> dat; 


};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_(m), c_(c)
{
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
	return dat.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const 
{
	return dat.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) 
{
	dat.push_back(item); 
	int ins = dat.size()-1;
	
	while(ins != 0) 
	{
	int par = (ins-1)/m_;
	if(!c_(dat[ins], dat[par])) break;
	
		T temp = dat[ins];
		dat[ins] = dat[par];
		dat[par] = temp;
		ins = par;
	}
	
}
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("top");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return dat.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("pop");
  }
		dat[0] = dat[dat.size()-1];
    dat.pop_back();
    int start_index = 0;
    while(start_index*m_+1 <= (signed)dat.size()) 
    {
        int max_child_index = start_index*m_+1;
        for(int i = start_index*m_+2; i<=(start_index+1)*m_; i++) 
        {
          if(i>=(signed)dat.size()) break;
          if(c_(dat[i], dat[max_child_index])) 
          {
            max_child_index = i;
          }
        }
        
        if(c_(dat[start_index], dat[max_child_index])) break;
        T temp = dat[start_index];
        dat[start_index] = dat[max_child_index]; 
        dat[max_child_index] = temp;
        start_index = max_child_index;


    }
	

}



#endif

