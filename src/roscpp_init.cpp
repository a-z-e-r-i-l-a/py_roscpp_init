#include <roscpp_init.h>
#include <boost/thread.hpp>


static std::vector<std::string>& ROScppArgs()
{
  static std::vector<std::string> args;
  return args;
}



namespace
{
struct InitProxy
{
  InitProxy(std::string node_name)
  {
    const std::vector<std::string>& args = ROScppArgs();
    char** fake_argv = new char*[args.size()];
    for (std::size_t i = 0; i < args.size(); ++i)
        fake_argv[i] = strdup(args[i].c_str());
    int fake_argc = args.size();
    ros::init(fake_argc, fake_argv, node_name,  ros::init_options::AnonymousName | ros::init_options::NoSigintHandler);
  }

  ~InitProxy()
  {
    if (ros::isInitialized() && !ros::isShuttingDown())
      ros::shutdown();
  }
};
}  // namespace



ROScppInitializer::ROScppInitializer(std::string node_name, int n_spinner) {

//  ensure we do not accidentally initialize ROS multiple times per process
    static boost::mutex lock;
    boost::mutex::scoped_lock slock(lock);
    static std::unique_ptr<InitProxy> proxy;
    static std::unique_ptr<ros::AsyncSpinner> spinner;
    proxy.reset(new InitProxy(node_name));
    spinner.reset(new ros::AsyncSpinner(n_spinner));
    spinner->start();
}

ROScppInitializer::~ROScppInitializer() {
}

void ROScppInitializer::roscpp_init() {

}
