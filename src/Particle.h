#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once

class Particle
{
public:

    Particle();
    ~Particle();
    void update();

    double m_x;
    double m_y;

    double m_xspeed;
    double m_yspeed;

private:


};

#endif