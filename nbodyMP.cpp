#include <iostream>
#include <omp.h>
#include <time.h>
#include <cstdlib>
#include <cmath>

#include "Particle.h"
#include "Universe.h"

using namespace std;

void displayAllParticleInfo(Particle particles[], int numParticles){
	for (int i = 0; i < numParticles; i++){
			cout << "Particle " << i
			<< "  X = " << particles[i].getCoordX()
			<< "  Y = " << particles[i].getCoordY()
			<< "  X Vel = " << particles[i].getVelocityX()
			<< "  Y Velocity = " << particles[i].getVelocityY()
			<< "  Mass = " << particles[i].getMass()
			<< endl;
		}
}

int main(int argc, char * argv[]){

	if (argc != 3){
		cout << "Not right amount of arguments" << endl;
		return -1;
	}

	int numParticles = atoi(argv[1]);
	int numberOfTimesteps = atoi(argv[2]);

	srand(time(NULL));

	Particle particles [numParticles];

	displayAllParticleInfo(particles, numParticles);
	cout << endl;


	double deltaT = unitTime;

	for (int i = 0; i < numberOfTimesteps; i++){
		//if output print output data

		for (int i = 0; i < numParticles; i++){
			particles[i].setForceX(0);
			particles[i].setForceY(0);
		}

		for (int i = 0; i < numParticles; i++){
			for (int j = 0; j < numParticles; j++){
				if (i != j){
					double x_diff = particles[i].getCoordX() - particles[j].getCoordX();
					double y_diff = particles[i].getCoordY() - particles[j].getCoordY();

					double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
					double distCubed = distance * distance * distance;
					double forceijX = gravitationalConst * particles[i].getMass() * particles[j].getMass() / distCubed * x_diff;
					double forceijY = gravitationalConst * particles[i].getMass() * particles[j].getMass() / distCubed * y_diff;

					particles[i].setForceX(particles[i].getForceX() - forceijX);
					particles[i].setForceY(particles[i].getForceY() - forceijY);

				}

			}

		}

		for (int i = 0; i < numParticles; i++){
			particles[i].setCoordX(particles[i].getCoordX() + deltaT * particles[i].getVelocityX());
			particles[i].setCoordY(particles[i].getCoordY() + deltaT * particles[i].getVelocityY());
			particles[i].setVelocityX(particles[i].getVelocityX() + deltaT / particles[i].getMass() + particles[i].getForceX());
			particles[i].setVelocityY(particles[i].getVelocityY() + deltaT / particles[i].getMass() + particles[i].getForceY());
		}

	}

	displayAllParticleInfo(particles, numParticles);

	return 0;
}

