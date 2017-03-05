#include <coddle/coddle.hpp>
#include <coddle/config.hpp>

int main(int argc, char **argv)
{
  Config config(argc, argv);
  config.cflags.push_back("$(sdl2-config --cflags)");
  config.ldflags.push_back("$(sdl2-config --libs)");
  return coddle(&config);
}
