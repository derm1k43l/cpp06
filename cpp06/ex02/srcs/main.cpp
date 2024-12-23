#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    //dynamic_cast returns a null pointer if the cast fails
    // 
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown obj type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    // catch the exception thrown by dynamic_cast
    // in case its not that type. we dont print anything but we try all the types
    catch (std::bad_cast&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast&)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast&)
            {
                std::cout << "Unknown obj type" << std::endl;
            }
        }
    }
}

int main()
{
    //seed the random number generator used in generate() wiht the current time
    srand(time(NULL));

    Base* base1 = generate();
    Base* base2 = generate();
    Base* base3 = generate();

    std::cout << "Identify by pointer:" << std::endl;
    identify(base1);
    identify(base2);
    identify(base3);

    std::cout << "Identify by reference:" << std::endl;    
    identify(*base1);
    identify(*base2);
    identify(*base3);

    delete base1;
    delete base2;
    delete base3;

    return 0;
}
