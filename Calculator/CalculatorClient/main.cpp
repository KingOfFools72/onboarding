#include <boost/program_options.hpp>

#include <iostream>
#include <memory>
#include <string>

#include <Commands.h>

namespace po = boost::program_options;

int main(int argc, char** argv)
{
    int res = 0;

	po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("compression", po::value<int>(), "set compression level")
        ("action,a", po::value<std::string>(), "set action")
        ("first,f", po::value<int>(), "set first parameter")
        ("second,s", po::value<int>(), "set second parameter")
        ;

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (...) {
        std::cout << "Invalid parameter value\n";
        return -1;
    }
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("action")) {
        if (vm.count("first"))
        {
            if (vm.count("second"))
            {
                std::string actionStr = vm["action"].as<std::string>();                
                int a = vm["first"].as<int>();
                int b = vm["second"].as<int>();
                std::unique_ptr<IAction> act = nullptr;

                if (actionStr == "Add") act = std::make_unique<Add>(a, b);
                if (actionStr == "Sub") act = std::make_unique<Sub>(a, b);
                if (actionStr == "Div") act = std::make_unique<Div>(a, b);
                if (actionStr == "Mul") act = std::make_unique<Mul>(a, b);

                res = act->calculate();
            }
            else {
                std::cout << "Second param was not set.\n";
            }
        }
        else {
            std::cout << "First param was not set.\n";
        }
    }
    else {
        std::cout << "Action was not set.\n";
    }

    return res;
}