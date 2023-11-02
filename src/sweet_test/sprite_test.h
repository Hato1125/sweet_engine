#ifndef SWTEST_SPRITE_TEST_H_
#define SWTEST_SPRITE_TEST_H_

#include <memory>

#include <sprite.h>
#include <scene_base.h>

#include "main.h"

namespace swtest {
    class SpriteTest : public sweet::SceneBase {
    private:
        std::unique_ptr<sweet::Sprite> _sprite;

    protected:
        void impl_init() override;
        void impl_render() override;
    };
}

#endif // SWTEST_SPRITE_TEST_H_