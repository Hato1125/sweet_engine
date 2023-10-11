#ifndef ENGINE_GRAPHICS_SPRITE_H_
#define ENGINE_GRAPHICS_SPRITE_H_

#include <memory>
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_image.h>

#include <size.h>
#include <point.h>
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
            uint32_t _width;
            uint32_t _height;
            uint32_t _format;

        public:
            float horizontal_scale;
            float vertical_scale;
            double rotation_angle;

            HorizontalPoint renderer_h_pos;
            VerticalPoint renderer_v_pos;
            HorizontalPoint rotation_h_pos;
            VerticalPoint rotation_v_pos;

            SDL_BlendMode blend_mode;
            SDL_RendererFlip renderer_flip;

            Sprite();
            Sprite(SDL_Renderer *renderer, SDL_Texture *texture);
            Sprite(SDL_Renderer *renderer, SDL_Surface *surface);
            Sprite(SDL_Renderer *renderer, const std::string &path);

            void render(
                float x,
                float y,
                Rectangle<int> rect = {
                    0, 0, 0, 0
                }
            );

            void render(
                const Point<float>& pos,
                Rectangle<int> rect = {
                    0, 0, 0, 0
                }
            );

            uint64_t get_byte() const;
            uint32_t get_width() const;
            uint32_t get_height() const;

            [[nodiscard]] SDL_Texture* get_texture() const;
    };
}

#endif // ENGINE_GRAPHICS_SPRITE_H_