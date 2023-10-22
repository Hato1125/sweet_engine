#include "logger.h"

namespace sweet {
    std::unique_ptr<std::ofstream, Logger::OFStreamDeleter> Logger::_stream = {};

    void Logger::init_log(const std::string &path) {
        _stream = std::unique_ptr<std::ofstream, OFStreamDeleter>(
            new std::ofstream(path)
        );
    }

    void Logger::write_log(const std::string &message) {
        if(_stream.get() == nullptr)
            return;

        *_stream.get() << message;
    }

    void Logger::write_line_log(const std::string &message) {
        std::string mes = message.back() != '\n'
            ? message + "\n"
            : message;

        write_log(mes);
    }
}