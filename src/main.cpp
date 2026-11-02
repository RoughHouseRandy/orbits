#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_fixed_point.h>
#include <bn_vector.h>
#include <bn_regular_bg_animate_actions.h>
#include "Center.h"
#include "Orbiter.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_tower.h"

// A scaling factor by which to reduce the force applied when orbiting
// Important for numerical stability
static constexpr bn::fixed FORCE_SCALE = 10;

// Maximum number of orbiters allowed on the screen
static constexpr int MAX_ORBITERS = 30;

// Default starting posiiton and velocity for Orbiter
static constexpr bn::fixed_point ORBITER_START_POSIITON = {0, 0};
static constexpr bn::fixed_point ORBITER_START_VELOCITY = {0, 5};

int main()
{
    bn::core::init();
    bn::regular_bg_ptr bg = bn::regular_bg_items::tower.create_bg(0,0);
    bn::regular_bg_animate_action<7> particles = bn::create_regular_bg_animate_action_forever(
        bg,
        6,
        bn::regular_bg_items::tower.map_item(), 0, 1, 2, 3, 4, 5, 6 );

    Center center = Center({30, 40}, .05, 2);
    bn::vector<Orbiter, MAX_ORBITERS> orbiters = {};

    while (true)
    {
        // Add an orbiter when A is pressed if there's room
        if (bn::keypad::a_pressed())
        {
            if (orbiters.size() < MAX_ORBITERS)
            {
                orbiters.push_back(Orbiter(ORBITER_START_POSIITON, ORBITER_START_VELOCITY, center));
            }
        }

        // Remove an orbiter when B is pressed if there's at least one
        if (bn::keypad::b_pressed())
        {
            if (orbiters.size() > 0)
            {
                orbiters.pop_back();
            }
        }

        if(bn::keypad::start_pressed()){
            if(orbiters.size() > 0)
            {
                orbiters.clear();
            }
        }

        center.update();
        for (Orbiter &orbiter : orbiters)
        {
            orbiter.update();
        }
        particles.update();
        bn::core::update();
    }
}