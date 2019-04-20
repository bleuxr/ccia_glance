#include<thread>

void do_some_work();
std::thread my_thread(do_some_work);

void do_something();
void do_something_els();
class background_task{
    public:
        void operator()() const{
            do_something();
            do_something_els();
        }
};
background_task f;
std::thread my_thread2(f);

std::thread my_thread3((background_task()));
std::thread my_thread4{background_task()};

std::thread my_thread5([]{
    do_something();
    do_something_els();
});
