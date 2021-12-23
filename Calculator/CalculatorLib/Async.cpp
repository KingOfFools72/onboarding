#include "pch.h"
#include "Commands.h"
#include <boost/signals2.hpp>
#include <boost/program_options.hpp>

//template<typename Container>
//struct aggregate_values
//{
//    typedef Container result_type;
//
//    template<typename InputIterator>
//    Container operator()(InputIterator first, InputIterator last) const
//    {
//        Container values;
//        std::pair<int, int> res;
//        int id = 0;
//        while (first != last) {
//            res = std::pair<int, int>{ id,*first };
//            values.push_back(res);
//            ++first;
//        }
//        return values;
//    }
//};

//int test()
//{
//	boost::signals2::signal<int(int, int)> sig;
//
//    sig.connect(&Add::calculate);
//    sig(7, 8);
//
//	return 0;
//}

//namespace po = boost::program_options;
//
//int options(int argc, char** argv)
//{
//    po::options_description desc("Allowed options");
//    desc.add_options()
//        ("help", "produce help message")
//        ("compression", po::value<int>(), "set compression level")
//        ("Add", po::value<int>(), "set compression level")
//        ;
//
//    po::variables_map vm;
//    po::store(po::parse_command_line(argc, argv, desc), vm);
//    po::notify(vm);
//
//    if (vm.count("help")) {
//        std::cout << desc << "\n";
//        return 1;
//    }
//
//    if (vm.count("compression")) {
//        std::cout << "Compression level was set to "
//            << vm["compression"].as<int>() << ".\n";
//    }
//    else {
//        cout << "Compression level was not set.\n";
//    }
//
//    int res = 8;
//    return res;
//}