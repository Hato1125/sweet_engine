#ifndef SWTEST_MAIN_H_
#define SWTEST_MAIN_H_

#include <string>
#include <memory>
#include <cstdint>
#include <iostream>
#include <filesystem>

#include <size.h>
#include <point.h>
#include <keyboard.h>
#include <logger.h>
#include <game_loop.h>
#include <scene_manager.h>
#include <application.h>
#include <application_loop_info.h>

namespace swtest {
    class Main final {
    private:
        Main() = delete;
        Main(const Main&) = delete;
        Main(Main&&) = delete;
        ~Main() = delete;

        static const std::string _window_title;
        static const sweet::Point<uint32_t> _window_point;
        static const sweet::Size<uint32_t> _window_size;

        static std::string _current_path;
        static std::string _current_dire;
        static std::string _output_log_path;

    public:
        static std::unique_ptr<sweet::GameLoop> k_game_loop;
        static std::unique_ptr<sweet::Application> k_application;

        static void initialize_application(const char **argv);

        static std::string get_current_path();
        static std::string get_current_dire();
    };
}

#endif // SWTEST_MAIN_H_