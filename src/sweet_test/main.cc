#include "main.h"

#include "sprite_test.h"
#include "font_test.h"

namespace swtest {
    const std::string Main::_window_title = "SweetEngine Test Application";
    const sweet::Point<uint32_t> Main::_window_point = { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED };
    const sweet::Size<uint32_t> Main::_window_size = { 1280, 720 };

    std::string Main::_current_path = {};
    std::string Main::_current_dire = {};

    std::unique_ptr<sweet::GameLoop> Main::k_game_loop = {};
    std::unique_ptr<sweet::Application> Main::k_application = {};

    void Main::initialize_application(const char **argv) {
        {
            auto current = std::filesystem::path { argv[0] };

            _current_path = current.c_str();
            _current_dire = current.parent_path().c_str();
        }

        k_game_loop = std::make_unique<sweet::GameLoop>();
        k_application = std::make_unique<sweet::Application>(
            _window_title,
            _window_point,
            _window_size
        );
    }

    std::string Main::get_current_path() {
        return _current_path;
    }

    std::string Main::get_current_dire() {
        return _current_dire;
    }
}

namespace {
    std::string _debug_scene_name;

    void inited(sweet::Application &app) {
        sweet::SceneManager::change_scene(_debug_scene_name);
    }

    void begin_frame(sweet::Application &app) {
        swtest::Main::k_game_loop->begin_update();
    }

    void end_frame(sweet::Application &app) {
        swtest::Main::k_game_loop->end_update();
    }

    void update(sweet::Application &app) {
        sweet::Keyboard::update();
        sweet::SceneManager::update_scene();
    }

    void render(sweet::Application &app) {
        sweet::SceneManager::render_scene();
    }

    void finishing(sweet::Application &app) {
    }

    void event(sweet::Application &app, SDL_Event &e) {
        sweet::Keyboard::update_event(e);
    }

    void regist_debug_scene() {
        sweet::SceneManager::regist_scene("sprite_test", new swtest::SpriteTest());
        sweet::SceneManager::regist_scene("font_test", new swtest::FontTest());
    }

    void output_title() {
        std::cout << "----------------Sweet Engine Debugger----------------" << "\n";
    }

    void output_scene_list() {
        std::cout << "List of registered debug scenes." << "\n";

        for(const auto &[key, value] : sweet::SceneManager::get_scene())
            std::cout << "| " << key << "\n";
    }

    bool select_debug_scene() {
        std::string scene_name {};
        std::cout << "> ";
        std::cin >> scene_name;

        if(!sweet::SceneManager::get_scene().contains(scene_name))
            return false;

        _debug_scene_name = scene_name;

        std::cout
            << "\x1b[32m"
            << "[o] Name of selected scene: "
            << _debug_scene_name
            << "\x1b[m"
            << "\n";

        return true;
    }

    void user_select() {
        bool is_contains_scene_name = false;

        do {
            std::cout << "Please enter the name of the scene you want to debug." << "\n";
            is_contains_scene_name = select_debug_scene();

            if(!is_contains_scene_name) {
                std::cout
                    << "\x1b[31m"
                    << "[x] That scene is not registered."
                    << "\x1b[m"
                    << "\n";
            }
        } while(!is_contains_scene_name);
    }
}

int main(const int argc, const char **argv) {
    swtest::Main::initialize_application(argv);

    regist_debug_scene();
    output_title();
    output_scene_list();
    user_select();

    swtest::Main::k_application->running({
        .on_inited = inited,
        .on_begin_frame = begin_frame,
        .on_end_frame = end_frame,
        .on_update = update,
        .on_render = render,
        .on_finishing = finishing,
        .on_event = event,
    });
}