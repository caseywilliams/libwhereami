#include <iostream>
#include <whereami/whereami.hpp>
#include <internal/vm.hpp>
#include <leatherman/logging/logging.hpp>

namespace lm = leatherman::logging;

int main(int argc, const char** argv)
{
    lm::set_level(lm::log_level::debug);
    lm::set_colorization(true);

    auto results = whereami::hypervisors();

    for (auto const& result : results) {
        // Print the name of the hypervisor
        std::cout << result.name() << std::endl;
        // Print each value in the metadata map, too
        for (auto const& metadata : result.metadata()) {
            std::cout << "- " << metadata.first
                      << ": " << metadata.second << std::endl;
        }
    }

}


