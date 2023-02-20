#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

#pragma once

class Swarm
{
public:

    const static int NPARTICLES = 1000;

private:
    Particle *m_pParticles;

public:
    Swarm();
    ~Swarm();

    void update();

    const Particle *getParticles(){

        return m_pParticles; 

    };

};

#endif