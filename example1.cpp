#include <memory>
#include <iostream>

class Thing1
{
public:
    Thing1(const int num)
        : _num(num)  { }
private:
    int _num;
};

class Thing2
{
public:
    Thing2(const std::shared_ptr<Thing1>& thing)
        : _thingy(thing)
    {
        std::cout << "thing refcount: " << thing.use_count() << std::endl;
    }
private:
    std::shared_ptr<Thing1> _thingy;
};

class Thing3
{
public:
    Thing3(const std::shared_ptr<Thing1> thing)
        : _thingy(thing)
    {
        std::cout << "thing refcount: " << thing.use_count() << std::endl;
    }
private:
    std::shared_ptr<Thing1> _thingy;
};




int main(int argc, char*argv[])
{
    auto thing1 = std::make_shared<Thing1>(42);
    std::cout << "thing1 refcount: " << thing1.use_count() << std::endl;

    Thing2 thing2(thing1);
    std::cout << "thing1 refcount: " << thing1.use_count() << std::endl;

    Thing3 thing3(thing1);
    std::cout << "thing1 refcount: " << thing1.use_count() << std::endl;
}


