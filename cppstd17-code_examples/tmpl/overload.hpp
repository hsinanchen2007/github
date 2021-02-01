
// "inherit" all function call operators of passed base types:
template<typename... Ts>
struct overload : Ts...
{
  using Ts::operator()...;
};

// base types are deduced from passed arguments:
template<typename... Ts>
overload(Ts...) -> overload<Ts...>;

