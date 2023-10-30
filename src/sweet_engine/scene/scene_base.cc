#include "scene_base.h"

namespace sweet {
    void SceneBase::init() {
        for(const auto &child : scene_children)
            child->init();

        impl_init();
    }

    void SceneBase::update() {
        if(state == SceneState::inactive || state == SceneState::pause)
            return;

        for(const auto &child : scene_children) {
            if(child->state == SceneState::active)
                child->update();
        }

        impl_update();
    }

    void SceneBase::render() {
        if(state == SceneState::inactive)
            return;

        for(const auto &child : scene_children) {
            if(child->state == SceneState::inactive)
                child->render();
        }

        impl_render();
    }

    void SceneBase::finish() {
        for(const auto &child : scene_children)
            child->finish();

        impl_finish();
    }
}