
#include <utility>     // for std::invoke()
#include <functional>  // for std::forward()

template<typename Callable, typename... Args>
void call(Callable&& op, Args&&... args)
{
  //...
  std::invoke(std::forward<Callable>(op),    // call passed callable with
              std::forward<Args>(args)...);  // all additional passed args
}

