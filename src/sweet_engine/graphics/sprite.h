#ifndef ENGINE_GRAPHICS_SPRITE_H_
#define ENGINE_GRAPHICS_SPRITE_H_

#include <memory>
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_image.h>

#include <size.h>
#include <point.h>
#include <color.h>
#include <rectangle.h>

namespace sweet {
    enum class HorizontalPoint {
        left,
        center,
        right
    };

    enum class VerticalPoint {
        top,
        center,
        bottom
    };

    class Sprite {
        private:
            SDL_Renderer *_renderer;
            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> _texture;

            float calclate_horizontal_point(float width, HorizontalPoint pos) const;
            float calclate_vertical_point(float height, VerticalPoint pos) const;

            uint64_t _byte;
            int32_t _width;
            int32_t _height;
            uint32_t _format;

        public:
            uint8_t alpha;
            float horizontal_scale;
            float vertical_scale;
            double rotation_angle;

            HorizontalPoint renderer_h_pos;
            VerticalPoint renderer_v_pos;
            HorizontalPoint rotation_h_pos;
            VerticalPoint rotation_v_pos;

            Color blend_color;
            SDL_BlendMode blend_mode;
            SDL_ScaleMode scale_mode;
            SDL_RendererFlip renderer_flip;

            Sprite();
            Sprite(SDL_Renderer *renderer, SDL_Texture *texture);
            Sprite(SDL_Renderer *renderer, SDL_Surface *surface);
            Sprite(SDL_Renderer *renderer, const std::string &path);

            void render(
                float x,
                float y,
                Rectangle<int32_t> rect = {}
            );

            void render(
                const Point<float> &pos,
                Rectangle<int32_t> rect = {}
            );

            uint64_t get_byte() const;
            int32_t get_width() const;
            int32_t get_height() const;

            [[nodiscard]] SDL_Texture *get_texture() const;
    };
}

#endif // ENGINE_GRAPHICS_SPRITE_H_