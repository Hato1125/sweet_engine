#ifndef SWTEST_FONT_TEST_H_
#define SWTEST_FONT_TEST_H_

#include <memory>

#include <font.h>
#include <font_family.h>
#include <font_render.h>
#include <scene_base.h>

#include "main.h"

namespace swtest {
    class FontTest : public sweet::SceneBase {
    private:
        std::unique_ptr<sweet::Font> _font;
        std::unique_ptr<sweet::FontRender> _font_render;

    protected:
        void impl_init() override;
        void impl_render() override;
    };
}

#endif // SWTEST_FONT_TEST_H_