#include <boost/program_options.hpp>
#include <iostream>
#include "strategy_tester.h"

using namespace std;
namespace po = boost::program_options;
int main(int argc, const char* argv[]) {
    po::options_description desc("test_strat.exe options");
    desc.add_options()
            ("help","print this info")
            ("input_file", po::value<vector<string>>()->multitoken(),
                ".strat strategy file(s) to test")
            ("output_directory", po::value<string>(),
                "where to write the results (default strat_name)");

    po::variables_map vm;
    auto parsed = po::parse_command_line(argc,  argv, desc);
    po::store(parsed, vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        return 1;
    }

    if (vm.count("input_file")) {
        string out_dir;
        strategy_tester* st;
        if (vm.count("output_directory")) {
            out_dir = vm["output_directory"].as<string>();
            st = new strategy_tester(vm["input_file"].as<vector<string>>(),out_dir);
        } else {
            st = new strategy_tester(vm["input_file"].as<vector<string>>());
        }
        st->run();
    } else {
        cout << "Input file(s) required." << endl;
        return 1;
    }

    return 0;
}