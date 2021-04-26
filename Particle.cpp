#include "Particle.h"
#include "Universe.h"

#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

Particle::Particle() {
	m_velocityX = 0;
	m_velocityY = 0;

	setCoordX((double)rand()/RAND_MAX);
	setCoordY((double)rand()/RAND_MAX);


	double f = (double)rand() / RAND_MAX;
	m_mass = 1 + f * (maxMass - 1);

}


void Particle::setCoordX(double x){
	m_x = x;
}

void Particle::setCoordY(double y){
	m_y = y;
}

double Particle::getCoordX(){
	return m_x;
}

double Particle::getCoordY(){
	return m_y;
}

void Particle::setVelocityX(double vX){
	m_velocityX = vX;
}

void Particle::setVelocityY(double vY){
	m_velocityY = vY;
}

double Particle::getVelocityX(){
	return m_velocityX;
}


double Particle::getVelocityY(){
	return m_velocityY;
}

void Particle::setForceX(double fX){
	m_forceX = fX;
}

void Particle::setForceY(double fY){
	m_forceY = fY;
}

double Particle::getForceX(){
	return m_forceX;
}

double Particle::getForceY(){
	return m_forceY;
}


double Particle::getMass(){
	return m_mass;
}
