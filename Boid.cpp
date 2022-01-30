#include "Boid.h"
#include "ofMain.h"

Boid::Boid() {
	separationThreshold = 15;
	neighbourhoodSize = 50;

	seperationWeight = 1.0f;
	alignmentWeight = 0.1f;
	cohesionWeight = 0.2f;
	xenophobiaWeight = 1.0f;
	maxVelocity = 5.0f;

	position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f& pos, ofVec3f& vel)
{
	separationThreshold = 15;
	neighbourhoodSize = 50;

	seperationWeight = 1.0f;
	alignmentWeight = 0.1f;
	cohesionWeight = 0.2f;
	xenophobiaWeight = 1.0f;
	maxVelocity = 5.0f;

	position = pos;
	velocity = vel;
}

Boid::~Boid()
{

}

ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

float Boid::getAlignmentWeight() {
	return alignmentWeight;
}

void Boid::setAlignmentWeight(float f) {
	alignmentWeight = f;
}

ofVec3f Boid::separation(std::vector<Boid*>& otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}

ofVec3f Boid::cohesion(std::vector<Boid*>& otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - position;
	v.normalize();
	return v;
}

ofVec3f Boid::alignment(std::vector<Boid*>& otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - velocity;
	v.normalize();
	return v;
}



void Boid::update(std::vector<Boid*>& otherBoids, ofVec3f& min, ofVec3f& max)
{
	velocity += seperationWeight * separation(otherBoids);
	velocity += cohesionWeight * cohesion(otherBoids);
	velocity += alignmentWeight * alignment(otherBoids);
	velocity.limit(maxVelocity);

	walls(min, max);
	position += velocity;
}

void Boid::walls(ofVec3f& min, ofVec3f& max)
{
	if (position.x < min.x) {
		position.x = max.x;
	}
	else if (position.x > max.x) {
		position.x = min.x;
	}

	if (position.y < min.y) {
		position.y = max.y;
	}
	else if (position.y > max.y) {
		position.y = min.y;
	}

	/*if (position.x < min.x) {
		position.x = min.x;
		velocity.x *= -1;
	}
	else if (position.x > max.x) {
		position.x = max.x;
		velocity.x *= -1;
	}

	if (position.y < min.y) {
		position.y = min.y;
		velocity.y *= -1;
	}
	else if (position.y > max.y) {
		position.y = max.y;
		velocity.y *= -1;
	}*/


}

void Boid::draw()
{
	ofSetColor(0, 255, 255);
	ofDrawCircle(position.x, position.y, 5);
}