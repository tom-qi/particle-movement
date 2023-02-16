#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

#pragma once

class Swarm
{
public:

    const static int NPARTICLES = 5000;

private:
    Particle *m_pParticles;

public:
    Swarm();
    ~Swarm();
    const Particle *getParticles(){

        return m_pParticles; 

    };

};

#endif