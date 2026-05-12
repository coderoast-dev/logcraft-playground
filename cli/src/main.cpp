#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <utility>

#include "logcraft/core/command.hpp"
#include "logcraft/core/engine_api.hpp"
#include "logcraft/core/logging.hpp"
#include "logcraft/core/scenario_loader.hpp"

int main(int argc, char** argv)
{
    auto args{std::span(argv, static_cast<size_t>(argc))};

    logcraft::core::logging::init_logging(logcraft::core::logging::config_from_env("core.log"));

    try
    {
        // Require exactly one argument: the scenario path
        if (argc != 2)
        {
            std::cerr << "Usage: logcraft_cli <scenario.yaml>\n";
            return EXIT_FAILURE;
        }

        const std::string scenario_path{args[argc - 1]};

        // Create engine and run scenario
        auto api{logcraft::core::create_engine_api()};
        auto config{logcraft::core::ScenarioLoader::load(scenario_path)};
        auto engine{api->create_engine(std::move(config))};
        engine->submit(logcraft::core::StartEngine{});

        // Wait for engine to complete
        constexpr int poll_interval_ms = 100; // NOLINT(readability-magic-numbers)
        while (engine->is_running())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(poll_interval_ms));
        }

        logcraft::core::logging::shutdown_logging();
        return EXIT_SUCCESS;
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << '\n';
        logcraft::core::logging::shutdown_logging();
        return EXIT_FAILURE;
    }
}
