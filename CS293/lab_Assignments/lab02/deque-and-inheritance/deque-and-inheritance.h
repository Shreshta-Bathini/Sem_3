

using namespace std;

template <typename T>
class Deque
{
    // Write a "Friend" function that overloads the "<<"" operator, and can be used to "cout" a deque.
    // Read about friend functions. Note that friend functions have access to private, public and 
    // protected members!
    friend ostream& operator<<(ostream& out, const Deque& dq)
    { 
        // TODO: Complete the overloading function. 
        // HINT: You just have to populate the ostream (output stream) with the members of the deque
        // array! Look at the testcases to see how the print should look like
        return out; // dummy
    }

protected:
    // TODO: Suitably initialize the queue parameters (Feel free to add any other variables as needed) 
    T* arr;
    int capacity;
    int resize_factor;
    int size;
    bool auto_resize;

public:
    Deque(int cap, bool resize = true, int resize_factor = 2) 
    {       
        // TODO: Implement the constructor that initializes the Deque with a given capacity
        // and optionally the resize factor                                    
    }

    Deque(bool resize = true, int resize_factor = 2)
    {
        // TODO: Implement the constructor that initializes the Deque with a default capacity
        // and optionally given the resize factor
    }

    Deque(const Deque& dq)
    {
        // TODO: Implement the copy constructor for the Deque. 
        // What you need to do is copy the contents of the Deque object dq to the new Deque object
        // being instantiated.
    }

    ~Deque()
    {
       // TODO: Implement the destructor
    }

    void print()
    {
        // TODO: Implement a print function similar to the << overload. You can cout the values. Look at the testcases to see how the print output should look

    }

    bool is_empty()
    {
        // TODO: Implement the is_empty method to check if the deque is empty
      return false; // DUMMY RETURN
    } 

    int get_capacity()
    {
        // TODO: Implement a getter for the capacity of the Deque
      return 0; // DUMMY RETURN
    }

    int get_size()
    {
        // TODO: Implement a getter for the size of the Deque
      return 0; // DUMMY RETURN
    }
// ATTENTION !!
// We DO NOT want to use Deque as a data structure for the purpose of this lab,
// but want to be able to inherit it's functions selectively and create our 
// Stack and Queue. Therefore, we do not make the following functions public.
protected:

    bool push_back(T data)
    {
        // TODO: Implement the push_back method to push the data into the back of the deque
        // If the deque is full and auto_resize is true, scale the capacity of the deque
        // Returns true if push succeds else returns false
        return 1;
    }

    T pop_front()
    {
        // TODO: Implement the pop_front method to pop the data from the front of the deque
        // Throw exception if the deque is empty
      T x; return x; // DUMMY RETURN
    }

//Returns true if push succeds else returns false
    bool push_front(T data)
    {
        // TODO: Implement the push_front method to push the data into the front of the deque
        // If the deque is full and auto_resize is true, scale the capacity of the deque
        // Returns true if push succeds else returns false
      return false; //DUMMY RETURN
    }

    T pop_back()
    {
        // TODO: Implement the pop_back method to pop the data from the back of the deque
        // Throw exception if the deque is empty
      T x; return x; // DUMMY RETURN
    }

    T peek_front()
    {
        // TODO: Implement the peek_front method to return the front element of the deque
        // Throw exception if the deque is empty
      T x; return x; // DUMMY RETURN
    }

    T peek_back()
    {
        // TODO: Implement the peek_back method to return the last element of the deque
        // Throw exception if the deque is empty
    }
};

// Before you go on to this part, read about class inheritance and understand the 3 types below:

// Public inheritance: public->public, protected->protected
// Protected inheritance: public->protected, protected->protected
// Private inheritance (default): public->private, protected->private

// To access private members of the base class, you need to declare derived class as a friend class

// Now, create the Queue class, and you must derive it from Deque. Why implement everything again!

template<typename T>
class Queue : public Deque<T>
{
    // TO THINK: Do we need a similar friend function to overload << as Deque? 
    // Or will Queue inherit it from Deque?
public:
    // TODO: Inherit the constructor that initializes the queue with a given capacity
    // and optionally the resize factor from Deque
    Queue(int cap, bool resize = true, int resize_factor = 2)
    {}

    // TODO: Inherit the constructor that initializes the queue with a default capacity
    // and optionally given the resize factor from Deque
    Queue(bool resize = true, int resize_factor = 2)
    {}

    // TODO: Write a custom copy constructor for the Queue. It must take a const reference to a
    // Queue object and copy its contents to the new Queue object being created.
    // HINT: You can use the copy constructor of the Deque class to copy the contents of the Deque

    // NOTE: Since Queue inherits from Deque, and Deque already has a destructor that correctly
    // deallocates the dynamic array arr, you don't need to write an additional destructor for Queue 

    // TODO: Make the (protected) member functions from Deque that are needed publicly by a 
    // Queue as Public members
    // HINT: do it by "using"


  // ------------------------------------------
  // The following functions are added to ensure initial compilation
  // Remove the following dummy functions once you implement the above functions
  //-------------------------------------------
  bool push      (T data) { return false; } // DUMMY
  bool push_back (T data) { return false; } // DUMMY
  bool push_front(T data) { return false; } // DUMMY
  T pop_front()  { T x; return x; } // DUMMY
  T pop_back()   { T x; return x; } // DUMMY
  T peek_front() { T x; return x; } // DUMMY
  T peek_back()  { T x; return x; } // DUMMY

};

// Now, create the Stack class, and you must derive it from Deque. Why implement everything again!


template<typename T>
class Stack : public Deque<T>
{
public:
    // TODO: Inherit the constructor that initializes the queue with a given capacity
    // and optionally the resize factor from Deque
    Stack(int cap, bool resize = true, int resize_factor = 2) 
    {}

    // TODO: Inherit the constructor that initializes the queue with a default capacity
    // and optionally given the resize factor from Deque
    Stack(bool resize = true, int resize_factor = 2)
    {}

    // TODO: Write a custom copy constructor for the Stack. It must take a const reference to a
    // Stack object and copy its contents to the new Stack object being created.
    // HINT: You can use the copy constructor of the Deque class to copy the contents of the Deque

    // NOTE: Since Stack inherits from Deque, and Deque already has a destructor that correctly
    // deallocates the dynamic array arr, you don't need to write an additional destructor for Stack 

    // TODO: Make the (protected) member functions from Deque that are needed publicly by a 
    // Stack as Public members
    // HINT: do it by "using" the necessary functions

  // ------------------------------------------
  // The following functions are added to ensure initial compilation
  // Remove the following dummy functions once you implement the above functions
  //-------------------------------------------
  bool push_back (T data) { return false; } // DUMMY
  bool push_front(T data) { return false; } // DUMMY
  T pop_front()  { T x; return x; } // DUMMY
  T pop_back()   { T x; return x; } // DUMMY
  T peek_front() { T x; return x; } // DUMMY
  T peek_back()  { T x; return x; } // DUMMY

};
