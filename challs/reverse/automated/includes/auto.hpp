#ifndef AUTO_HPP_
# define AUTO_HPP_

# include <string>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <limits>
# include <utility>

# include "static_for.hpp"

constexpr uint64_t seed()
{
  std::uint64_t shifted = 0;

  for (const auto c: __TIME__)
    {
      shifted <<= 8;
      shifted |= c;
    }

  return shifted;
}

struct PCG
{
  struct pcg32_random_t { std::uint64_t state=0; std::uint64_t inc=seed(); };
  pcg32_random_t rng;
  typedef std::uint32_t result_type;

  constexpr result_type operator()()
  {
    return pcg32_random_r();
  }

  constexpr static result_type min()
  {
    return std::numeric_limits<result_type>::min();
  }
  
  constexpr static result_type max()
  {
    return std::numeric_limits<result_type>::max();
  }

private:
  constexpr std::uint32_t pcg32_random_r()
  {
    std::uint64_t oldstate = rng.state;
    // Advence internal state
    rng.state = oldstate * 6364136223846793005ULL + (rng.inc|1);
    std::uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    std::uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
  }
};

struct FLAG
{
  constexpr static char flag[] = "History:\n\nNo academic study has been written on the history of the baguette as a type of bread. Thus, much of its history is speculative; however, some facts can be established. Among these are the increased popularity of long, stick-like breads in France starting in the 18th century, the shift among French bakers to using \"gruau\", a highly refined Hungarian high-milled flour in the early 19th century, the introduction of Viennese steam oven baking to Paris in 1839 by August Zang, and the subsequent introduction of the Austrian Adolf Ignaz Mautner von Markhof's compact yeast to Paris in 1867 at the Universal Exposition. Finally, there is the first use of the word \"baguette\" in print, to define a particular type of bread, in a set of laws enacted by the Prefecture of the Seine Department in August 1920: \"The baguette, having a minimum weight of 80 g and a maximum length of 40 cm (FLAG IS 110b61f972b78ee5b0c2a2eb0b615987), may not be sold for a price higher than 0.35 francs apiece\" While no one of these events is in itself definable as \"the invention of the baguette\", each of them, the shape, the flour, the fermentation, and the steam baking, contribute to what is today recognized as a \"baguette\".";

  constexpr char const &operator[](int i) const
  {
    return flag[i];
  }

  constexpr size_t length(void) const
  {
    return sizeof(flag);
  }
};

template<std::uint32_t A, std::uint32_t B>
static inline void mxor(char &chr)
{
  chr = A ^ B;
}

#endif // AUTO_HPP
