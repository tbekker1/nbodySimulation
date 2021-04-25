#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
public:
	Particle();

	void setCoordX(double x);
	void setCoordY(double y);
	double getCoordX();
	double getCoordY();

	void setVelocityX(double vX);
	void setVelocityY(double vY);
	double getVelocityX();
	double getVelocityY();

	void setForceX(double fX);
	void setForceY(double fY);
	double getForceX();
	double getForceY();

	double getMass();


private:
	double m_x;
	double m_y;
	double m_velocityX;
	double m_velocityY;
	double m_forceX;
	double m_forceY;
	double m_mass;

};

#endif /* PARTICLE_H_ */
