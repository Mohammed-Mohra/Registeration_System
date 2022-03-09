#include <string>
#include <iostream>
#include <exception>
using namespace std;
#include "Exception.h"
// Create your own exception


 const char* File_Register::what() {
    return "Unfortunatly we couldnot register\n";
}
const char* Login::what() {
    return "Unfortunatly we couldnot enter to the student for some reason\n";
}
const char* Mem_Alloc::what() {
    return "Unfortunatly we couldnot allocate memory. We have to shut down\n";
}


/*#include <string>
#include <iostream>
#include <exception>
using namespace std;
// Create your own exception
class DivByZeroException : public exception
{
    virtual const char* what() const throw()
    {
        return "Division by zero happened";
    }
} DivByZeroEx;
class NonPosDivisorException : public exception
{
    virtual const char* what() const throw()
    {
        return "The divisor is not positive";
    }
} NonPosDivisorEx;
class NonPosDividendException : public exception
{
    virtual const char* what() const throw()
    {
        return "The dividend is not positive";
    }
} NonPosDividendEx;


double divide(double x, double y) throw(int)    // restricts the function to 
                                        //throwing only int type exceptions
//  double divide(double x, double y) throw()   // cannot throw exceptions
{
    if (y == 0)
        throw DivByZeroEx;
    if (x <= 0)
        throw NonPosDividendEx;
    if (y <= 0)
        throw NonPosDivisorEx;
    return x / y;
}
int main()
{
    double a, b, c;
    cin >> a >> b;    // Restriction: a and b can only be positive!
    try
    {
        c = divide(a, b);
        cout << c << endl;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    /*  switch (e)
        {
        case 1:
            cout << "The dividend is not positive!" << endl;
            break;
        case 2:
            cout << "The divisor is not positive!" << endl;
            break;
        case 10:
            cout << "Exception happened: division by zero!" << endl;
            break;
        default:
            cout << "Unexpected exception happened!" << endl;
        }*/
   /* }

    try
    {
        int* p = new int[100];
    }
    catch (bad_alloc&)  // catch memory allocation exception
    {
        cout << "Memory allocation exception happened" << endl;
        //.... handle the exception, clean memory...
        // terminate the execution
    }
    catch (exception& e)
    {
        cout << "Some other standard exception happened. Message: " << e.what() << endl;
    }

    return 0;

    // Exception Handling in C++:  throw; catch; try
    //try
    //{ // Code under inspection
    //  //...
    //  //...
    //  //...
    //  // Error Happened!!
    //  //if(...)
    //  throw 20;
    //  //...
    //  // ...
    //}
    //catch (int e)   // Exception handler, exactly one parameter!
    //{
    //  cout << "The exception happened. Exception code: " << e << endl;
    //}
    //catch (double d)  // Will catch only double
    //{
    //  cout << "Double type exception happened!" << endl;
    //}
    //catch (...)  // Catches every type of exception (default catch block)
    //{
    //  cout << "Default exception happened" << endl;
    //}

    ////Nested try/catch
    //try
    //{
    //  //...
    //  //...
    //  try
    //  {
    //      //...
    //      // throw...
    //  }
    //  catch (int n)
    //  {
    //      //if(some special kind of exception), cannot handle here, need to go to upper level
    //      throw;
    //  }
    //}
    //catch (int e)
    //{
    //  cout << "Exception ocured!" << endl;
    //}


    */