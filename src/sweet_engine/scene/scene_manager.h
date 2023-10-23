#ifndef ENGINE_SCENE_SCENE_MANAGER_H_
#define ENGINE_SCENE_SCENE_MANAGER_H_

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "scene_base.h"

namespace sweet {
    class SceneManager final {
    private:
        SceneManager() = delete;
        SceneManager(const SceneManager&) = delete;
        SceneManager(SceneManager&&) = delete;
        ~SceneManager() = delete;

        using smart_scene = std::shared_ptr<SceneBase>;
        using scene_vector = std::vector<smart_scene>;

        static std::string _current_scene_name;
        static std::map<std::string, scene_vector> _scenes;

    public:
        static void regist_scene(const std::string &name, const smart_scene &scene);
        static void regist_scene(const std::string &name, SceneBase *scene);
        static void regist_scene(const std::string &name, const scene_vector &scenes);
        static void regist_scene(const std::string &name, const std::vector<SceneBase*> &scenes);
        static void remove_scene(const std::string &name);
        static void remove_scene(const std::vector<std::string> &names);
        static void change_scene(const std::string &name);
        static void update_scene();
        static void render_scene();
    };
}

#endif // ENGINE_SCENE_SCENE_MANAGER_H_