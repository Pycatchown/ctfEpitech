#include "auto.hpp"

// the flag is 110b61f972b78ee5b0c2a2eb0b615987

constexpr FLAG flag;

char p[flag.length()];

constexpr auto call_random(int i)
{
  PCG pcg;
  while (i-- > 0)
    pcg();
  return pcg();
}

struct do_stuff
{
  template<int index> static inline void func()
  {
    constexpr auto a = call_random(index) % std::numeric_limits<char>::max();
    constexpr char b = flag[index];
    mxor<a, b>(p[index]);
  }
};

constexpr void compute(void)
{
  static_for<flag.length(), do_stuff>();
}


int main(void)
{
  compute();
  std::cout << "Welcome to the most mysterious challenge ever made" << std::endl
	    << "What's inside ???" << std::endl
	    << "What lurks from below ???" << std::endl << std::endl
	    << "Once the mist have faded" << std::endl
	    << "Once you embrace its power wide" << std::endl
	    << "The flag will appear like a swallow" << std::endl << std::endl
	    << "flag: " << p << std::endl;
  return 0;
}
