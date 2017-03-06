#include <coddle/coddle.hpp>
#include <coddle/config.hpp>

int main(int argc, char **argv)
{
  Config config(argc, argv);
  config.pkgs.push_back("sdl2");
  return coddle(&config);
}
