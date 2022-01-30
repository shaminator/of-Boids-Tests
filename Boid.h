#pragma once

#include <vector>
#include "ofMain.h"
//#include "RedBoid.h"

class Boid
{
protected:
	ofVec3f position;
	ofVec3f velocity;

	float neighbourhoodSize;
	float separationThreshold;

	ofVec3f alignment(std::vector<Boid*>& otherBoids);
	float alignmentWeight;

	ofVec3f cohesion(std::vector<Boid*>& otherBoids);
	float cohesionWeight;

	ofVec3f separation(std::vector<Boid*>& otherBoids);
	float seperationWeight;

	float xenophobiaWeight;
	float maxVelocity;
	

public:
	Boid();
	Boid(ofVec3f& pos, ofVec3f& vel);

	~Boid();

	ofVec3f getPosition();
	ofVec3f getVelocity();

	float getAlignmentWeight();
	void setAlignmentWeight(float f);

	void update(std::vector<Boid*>& otherBoids, ofVec3f& min, ofVec3f& max);
	void walls(ofVec3f& min, ofVec3f& max);
	void draw();
};

