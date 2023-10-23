#ifndef ENGINE_SCENE_SCENE_BASE_H_
#define ENGINE_SCENE_SCENE_BASE_H_

#include <vector>
#include <memory>

namespace sweet {
    enum class SceneState {
        active,
        inactive,
        pause
    };

    class SceneBase {
    protected:
        std::vector<std::shared_ptr<SceneBase>> scene_children {};

        virtual void impl_init() {}
        virtual void impl_update() {}
        virtual void impl_render() {}
        virtual void impl_finish() {}

    public:
        SceneState state { SceneState::active };

        void init();
        void update();
        void render();
        void finish();
    };
}

#endif // ENGINE_SCENE_SCENE_BASE_H_
