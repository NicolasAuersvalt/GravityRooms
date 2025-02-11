#include <iostream>
#include <cmath>
#include <mutex>
#include <thread>

using namespace std;

namespace Gerenciadores{

    class Gerenciador_Thread 
    {
        public:
            template <typename Func, typename... Args>
            Gerenciador_Thread(Func&& f, Args&&... args) {
                
                t = thread(forward<Func>(f), forward<Args>(args)...);
            }
        
            // Função para aguardar o término da thread
            void join() 
            {
                if (t.joinable()) {
                    t.join();
                }
            }
        
        private:
            thread t;
        };
}