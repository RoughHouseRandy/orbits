#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

/**
 * A center of mass to be orbited around. Position is controlled by the player.
 */
class Center {
public:
    Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed);
    void update();
    bn::fixed_point position();
    bn::fixed mass();

private:
    bn::sprite_ptr _sprite;
    bn::fixed _mass;  // the mass of the center. The larger the value, the greater the attraction
    bn::fixed _speed; // the speed at which the center moves when the d-pad is held
};
