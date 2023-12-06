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
    #define SW_LOG(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "LOG" << "]" \
            << " " << message; \
        \
        std::cout << out.str() << '\n'; \
    } \
    while(0)

    #define SW_LOG_INFO(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "INFO" << "]" \
            << " " << message; \
        \
        sweet::Logger::write_line_log(out.str()); \
        std::cout << out.str() << '\n'; \
    } \
    while(0)

    #define SW_LOG_WARN(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "WARN" << "]" \
            << " " << message; \
        \
        sweet::Logger::write_line_log(out.str()); \
        std::cout << "\x1b[103m" << out.str() << "\x1b[0m" << '\n'; \
    } \
    while(0)

    #define SW_LOG_ERROR(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "ERROR" << "]" \
            << "[" << __FILE__ << "]" \
            << " " << message; \
        \
        sweet::Logger::write_line_log(out.str()); \
        std::cerr << "\x1b[101m" << out.str() << "\x1b[0m" << '\n'; \
    } \
    while(0)

    #define SW_LOG_FATAL(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "FATAL" << "]" \
            << "[" << __FILE__ << "]" \
            << " " << message; \
        \
        sweet::Logger::write_line_log(out.str()); \
        std::cerr << "\x1b[101m" << out.str() << "\x1b[0m" << '\n'; \
    } \
    while(0)

    #define SW_LOG_DEBUG(message) \
    do { \
        std::stringstream out; \
        \
        out << "[" << __TIME__ << "]" \
            << "[" << "DEBUG" << "]" \
            << " " << message; \
        \
        std::cout << out.str() << '\n'; \
    } \
    while(0)
}

#endif // ENGINE_CORE_LOGGER_H_
