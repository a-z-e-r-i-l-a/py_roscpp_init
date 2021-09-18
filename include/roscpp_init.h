#include <ros/ros.h>
#include <ros/time.h>

#include <stdio.h>




class ROScppInitializer
{
public:
  ROScppInitializer(std::string node_name, int n_spinner);
  ~ROScppInitializer();

  int n_spinner;
  void roscpp_init();
  void roscpp_shutdown();


    static std::vector<std::string>        args;
    static std::vector<std::string>& ROScppArgs()
          {
          static std::vector<std::string> args;
          return args;
          }

};


