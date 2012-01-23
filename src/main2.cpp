#include <boost/program_options.hpp>
#include <iostream>

#include "httpserver.hpp"


namespace po = boost::program_options;

int main(int arg, char * argv[]) {
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("hostname", po::value<std::string>(), "set hostname (default:\"localhost\")")
    ("port", po::value<int>(), "listen port (default: \"8000\")")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(arg, argv, desc), vm);
    po::notify(vm);    
    
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }
    
//     if (vm.count("compression")) {
//         std::cout << "Compression level was set to " 
//         << vm["compression"].as<int>() << ".\n";
//     } else {
//         std::cout << "Compression level was not set.\n";
//     }
    
    try {
        HttpHandler httpHandler;
        HttpServer serverProc("localhost", "8000", httpHandler);
        serverProc.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
