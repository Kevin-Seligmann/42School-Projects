#include "libftpp.hpp"
#include <iostream>

class TestObject {
public:
    TestObject()
    { 
        rsc = new int(0);
        std::cout << "TestObject default constructor" << std::endl; 
    }
    TestObject(int value)
    {
        std::cout << "TestObject constructor with value [" << value << "]" << std::endl;
        rsc = new int(value);
    }
    ~TestObject()
    {
        std::cout << "TestObject destructor" << std::endl;
        delete rsc;
    }
    TestObject(TestObject && obj)
    {std::cout << "TestObject move constructor" << std::endl; rsc = obj.rsc; obj.rsc = nullptr;}
    
    TestObject & operator=(TestObject && obj)
    {
        std::cout << "TestObject move" << std::endl;
        delete rsc; rsc = obj.rsc; obj.rsc = nullptr; return *this;
    }

    TestObject(const TestObject & obj)
    {
        std::cout << "TestObject reference construct" << std::endl;
        rsc = new int(*(obj.rsc));
    }

    TestObject & operator=(const TestObject & obj)
    {
        std::cout << "TestObject copy" << std::endl;
        delete rsc; rsc = new int(*(obj.rsc)); return *this;
    }

    void sayHello() const { std::cout << "Hello from TestObject" << std::endl; }

    int *rsc;
};

void testMove()
{

}

#include <iostream>

int main() {
    // Create a Pool for TestObject
   // testMove();

   Pool<TestObject> myPool;

    // Pool<TestObject> myOtherPool(5);

    // Resize the pool to pre-allocate 5 objects
    // Should output the 5 "TestObject constructor"
    myPool.resize(5);

    // Acquire an object from the pool
  // Pool<TestObject>::Object obj1 = myPool.acquire_new();
  // Pool<TestObject>::Object obj2 = myPool.acquire(15);
   // obj1->sayHello();  // Should output: "Hello from TestObject"

    {
        // Acquire another object in a different scope
       //    Pool<TestObject>::Object obj2 = myPool.acquire();

    Pool<TestObject>::Object obj2 = myPool.acquire(15);
        obj2->sayHello();  // Should also output: "Hello from TestObject"
        // obj2 is released back to the pool when it goes out of scope
    }

    // Acquire another object; this should give us the object that obj2 pointed to
   // Pool<TestObject>::Object obj3 = myPool.acquire();
  // obj3->sayHello();  // Should output: "Hello from TestObject"

    // obj1 and obj3 are released back to the pool when the program ends
    std::cout << "Main end ---" << std::endl;
    return 0;
}

