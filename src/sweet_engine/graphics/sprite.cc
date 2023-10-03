#include "sprite.h"

namespace sweet {
    Sprite::Sprite() : _texture(nullptr, SDL_DestroyTexture){
        _renderer = nullptr;
        _byte = 0;
        _width = 0;
        _height = 0;

        horizontal_scale = 1.0f;
        vertical_scale = 1.0f;
        rotation_angle = 0.0f;

        renderer_h_pos = HorizontalPoint::left;
        renderer_v_pos = VerticalPoint::top;
        rotation_h_pos = HorizontalPoint::left;
        rotation_v_pos = VerticalPoint::top;

        blend_mode = SDL_BLENDMODE_NONE;
        renderer_flip = SDL_FLIP_NONE;
    }

    Sprite::Sprite(SDL_Renderer *renderer, const std::string &path) : Sprite() {
        _renderer = renderer;

        if(_renderer != nullptr) {
            SDL_Texture *texture = IMG_LoadTexture(_renderer, path.c_str());

            if(texture != nullptr) {
                _texture.reset(texture);

                SDL_QueryTexture(
                    _texture.get(),
                    &_format,
                    nullptr,
                    reinterpret_cast<int*>(&_width),
                    reinterpret_cast<int*>(&_height)
                );

                _byte = SDL_BYTESPERPIXEL(_format) * _width * _height;
            }
        }
    }

    float Sprite::calclate_horizontal_point(float width, HorizontalPoint pos) const {
        switch(pos) {
            case HorizontalPoint::left: return 0.0f;
            case HorizontalPoint::center: return width / 2.0f;
            case HorizontalPoint::right: return width;
            default: return 0.0f;
        }
    }

    float Sprite::calclate_vertical_point(float height, VerticalPoint pos) const {
        switch(pos) {
            case VerticalPoint::top: return 0.0f;
            case VerticalPoint::center: return height / 2.0f;
            case VerticalPoint::bottom: return height;
            default: return 0.0f;
        }
    }

    void Sprite::render(float x, float y, Rectangle<int> rect) {
        if(_renderer == nullptr || _texture.get() == nullptr)
            return;

        if(rect == Rectangle<int> {0, 0, 0, 0}) {
            rect.width = _width;
            rect.height = _height;
        }

        Point<float> render_pos {
            calclate_horizontal_point(rect.width * horizontal_scale, renderer_h_pos),
            calclate_vertical_point(rect.height * vertical_scale, renderer_v_pos)
        };

        SDL_FPoint rotation_pos {
            calclate_horizontal_point(rect.width * horizontal_scale, rotation_h_pos),
            calclate_vertical_point(rect.height * vertical_scale, rotation_v_pos)
        };

        SDL_Rect image_rect {
            rect.x,
            rect.y,
            rect.width,
            rect.height
        };

        SDL_FRect render_rect {
            x - render_pos.x,
            y - render_pos.y,
            rect.width * horizontal_scale,
            rect.height * vertical_scale
        };

        SDL_SetTextureBlendMode(_texture.get(), blend_mode);
        SDL_RenderCopyExF(
            _renderer,
            _texture.get(),
            &image_rect,
            &render_rect,
            rotation_angle,
            &rotation_pos,
            renderer_flip
        );
    }

    void Sprite::render(const Point<float> &pos, Rectangle<int> rect) {
        render(pos.x, pos.y, rect);
    }

    uint64_t Sprite::get_byte() const {
        return _byte;
    }

    uint32_t Sprite::get_width() const {
        return _width;
    }

    uint32_t Sprite::get_height() const {
        return _height;
    }

    SDL_Texture* Sprite::get_texture() const {
        return _texture.get();
    }
}