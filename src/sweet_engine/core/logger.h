#ifndef ENGINE_CORE_LOGGER_H_
#define ENGINE_CORE_LOGGER_H_

#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace sweet {
    class Logger final {
    private:
        struct OFStreamDeleter {
            void operator() (std::ofstream *stream) {
                stream->close();
                delete stream;
                stream = nullptr;
            }
        };

    private:
        Logger() = delete;
        Logger(const Logger&) = delete;
        Logger(Logger&&) = delete;
        ~Logger() = delete;

        static std::unique_ptr<std::ofstream, OFStreamDeleter> _stream;

    public:
        static void init_log(const std::string &path);

        static void write_log(const std::string &message);
        static void write_line_log(const std::string &message);
    };

    // 参考 https://qiita.com/nanasess/items/350e59b29cceb2f122b3
    #define SW_LOG_FATAL(message) { \
        std::stringstream mes; \
        mes \
            << "[FATAL] " \
            << "[" << __TIME__ << "] " \
            << "[" << __FILE__ << "] " \
            << message; \
        \
        sweet::Logger::write_line_log(mes.str()); \
        std::cerr << "\x1b[38;2;255;0;0m" << mes.str() << "\x1b[m" <<'\n'; \
    }

    #define SW_LOG_ERROR(message) { \
        std::stringstream mes; \
        mes \
            << "[ERROR] " \
            << "[" << __TIME__ << "] " \
            << "[" << __FILE__ << "] " \
            << message; \
        \
        sweet::Logger::write_line_log(mes.str()); \
        std::cerr << "\x1b[38;2;255;0;0m" << mes.str() << "\x1b[m" <<'\n'; \
    }

    #define SW_LOG_WARN(message) { \
        std::stringstream mes; \
        mes \
            << "[WARN] " \
            << "[" << __TIME__ << "] " \
            << message; \
        \
        sweet::Logger::write_line_log(mes.str()); \
        std::cerr << "\x1b[38;2;255;241;0m" << mes.str() << "\x1b[m" <<'\n'; \
    }

    #define SW_LOG_INFO(message) { \
        std::stringstream mes; \
        mes \
            << "[INFO] " \
            << "[" << __TIME__ << "] " \
            << message; \
        \
        sweet::Logger::write_line_log(mes.str()); \
    }

    #define SW_LOG_TRACE(message) { \
        std::stringstream mes; \
        mes \
            << "[TRACE] " \
            << "[" << __TIME__ << "] " \
            << message; \
        \
        sweet::Logger::write_line_log(mes.str()); \
    }

    #define SW_LOG(message) { \
        std::stringstream mes; \
        mes \
            << "[LOG] " \
            << "[" << __TIME__ << "] " \
            << message; \
        \
        std::cout << mes.str() << '\n'; \
    }
}

#endif // ENGINE_CORE_LOGGER_H_