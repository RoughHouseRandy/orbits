#include "Center.h"
#include "movement.h"
#include "bn_sprite_items_square.h"
/**
 * A center of mass to be orbited around. Position is controlled by the player.
 */

    /**
     * Creates a new center.
     *
     * @param starting_position the initial location of the center
     * @param mass the mass of the center. The larger the value, the greater the attraction
     * @param speed the speed at which the center moves when the d-pad is held
     */
    Center::Center(bn::fixed_point starting_position, bn::fixed mass, bn::fixed speed) : 
    _sprite(bn::sprite_items::square.create_sprite(starting_position)),
        _mass(mass),
        _speed(speed){
    }

    /**
     * Updates the location of the Center based on player direction with the d-pad.
     */

    bn::fixed_point Center::position()
    {
        return _sprite.position();
    }
    
    void Center::update()
    {
        dPadMoveSprite(_sprite, _speed);
    }

   

    bn::fixed Center::mass()
    {
        return _mass;
    }
