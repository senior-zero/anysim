//
// Created by egi on 5/10/19.
//

#ifndef FDTD_SOURCES_H
#define FDTD_SOURCES_H

#include <vector>
#include <cmath>

template <class float_type>
float_type gaussian_pulse (float_type t, float_type t_0, float_type tau)
{
  return std::exp (-(((t - t_0) / tau) * (t - t_0) / tau));
}

template <class float_type>
class sources_holder
{
public:
  void append_source (float_type frequency_arg, unsigned int offset)
  {
    offsets.push_back (offset);
    frequencies.push_back (frequency_arg);
    sources_count++;
  }

  void update_sources (float_type t, float_type *e)
  {
    for (unsigned int source = 0; source < sources_count; source++)
      {
        const float_type tau = 0.5 / frequencies[source];
        const float_type t_0 = 6 * tau;
        e[offsets[source]] += gaussian_pulse (t, t_0, tau);
      }
  }

private:
  unsigned int sources_count = 0;
  std::vector<unsigned int> offsets;
  std::vector<float_type> frequencies;
};

#endif //FDTD_SOURCES_H
