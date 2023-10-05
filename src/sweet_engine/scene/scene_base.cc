#include "scene_base.h"

namespace sweet {
    void SceneBase::init() {
        for(int i = 0; i < scene_children.size(); i++)
            scene_children[i]->init();

        impl_init();
    }

    void SceneBase::update() {
        if(state == SceneState::inactive || state == SceneState::pause)
            return;

        for(int i = 0; i < scene_children.size(); i++) {
            if(scene_children[i]->state == SceneState::active)
                scene_children[i]->update();
        }

        impl_update();
    }

    void SceneBase::render() {
        if(state == SceneState::inactive)
            return;

        for(int i = 0; i < scene_children.size(); i++) {
            if(scene_children[i]->state != SceneState::inactive)
                scene_children[i]->render();
        }

        impl_render();
    }

    void SceneBase::finish() {
        for(int i = 0; i < scene_children.size(); i++)
            scene_children[i]->finish();

        impl_finish();
    }
}