#pragma once
#include "Entity.hpp"

class Player : public Entity {
public:
    Player(Vector2f p_pos, SDL_Texture* p_tex)
        : Entity(p_pos, p_tex), speed(0.1f) {}
    void move(float dx, float dy) {
        pos.x += dx * speed;
        pos.y += dy * speed;
    }
    void setSpeed(float newSpeed) {
        speed = newSpeed;
    }
    float getSpeed() const {
        return speed;
    }
private:
    float speed;
}