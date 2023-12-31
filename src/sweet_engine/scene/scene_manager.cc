#include "scene_manager.h"

namespace sweet {
    using smart_scene = std::shared_ptr<SceneBase>;
    using scene_vector = std::vector<smart_scene>;

    std::string SceneManager::_current_scene_name = {};
    std::map<std::string, scene_vector> SceneManager::_scenes = {};

    void SceneManager::regist_scene(const std::string &name, const smart_scene &scene) {
        if(!_scenes.contains(name))
            _scenes.insert({name, scene_vector()});

        _scenes[name].push_back(scene);
    }

    void SceneManager::regist_scene(const std::string &name, SceneBase *scene) {
        regist_scene(name, std::shared_ptr<SceneBase>(scene));
    }

    void SceneManager::regist_scene(const std::string &name, const scene_vector &scenes) {
        if(!_scenes.contains(name)) {
            _scenes.insert({name, scenes});
            return;
        }

        for(const auto &scene : scenes)
            _scenes[name].push_back(scene);
    }

    void SceneManager::regist_scene(const std::string &name, const std::vector<SceneBase*> &scenes) {
        scene_vector svec {};

        for(const auto &scene : scenes)
            svec.push_back(std::shared_ptr<SceneBase>(scene));

        regist_scene(name, svec);
    }

    void SceneManager::remove_scene(const std::string &name) {
        if(_scenes.contains(name))
            _scenes.erase(name);
    }

    void SceneManager::remove_scene(const std::vector<std::string> &names) {
        for(const auto &name : names)
            remove_scene(name);
    }

    void SceneManager::change_scene(const std::string &name) {
        if(!_scenes.contains(name))
            return;

        if(_current_scene_name != "") {
            for(const auto &scene : _scenes[_current_scene_name])
                scene->finish();
        }

        _current_scene_name = name;

        for(const auto &scene : _scenes[_current_scene_name])
            scene->init();
    }

    void SceneManager::update_scene() {
        if(!_scenes.contains(_current_scene_name) || _current_scene_name == "")
            return;

        for(const auto &scene : _scenes[_current_scene_name])
            scene->update();
    }

    void SceneManager::render_scene() {
        if(!_scenes.contains(_current_scene_name) || _current_scene_name == "")
            return;

        for(const auto &scene : _scenes[_current_scene_name])
            scene->render();
    }

    std::map<std::string, scene_vector> &SceneManager::get_scene() {
        return _scenes;
    }
}