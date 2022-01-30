#include "RedBoid.h"

ofVec3f RedBoid::separation(std::vector<RedBoid*>& otherRedBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherRedBoids.size(); i++)
	{
		if (position.distance(otherRedBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherRedBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}

ofVec3f RedBoid::cohesion(std::vector<RedBoid*>& otherRedBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherRedBoids.size(); i++)
	{
		if (position.distance(otherRedBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherRedBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - position;
	v.normalize();
	return v;
}

ofVec3f RedBoid::alignment(std::vector<RedBoid*>& otherRedBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherRedBoids.size(); i++)
	{
		if (position.distance(otherRedBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherRedBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - velocity;
	v.normalize();
	return v;
}

ofVec3f RedBoid::xenophobia(std::vector<Boid*>& otherBlueBoids) {
	for (int i = 0; i < otherBlueBoids.size(); i++)
	{
		if (position.distance(otherBlueBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherBlueBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}



void RedBoid::update(std::vector<RedBoid*>& otherRedBoids, std::vector<Boid*>& otherBlueBoids, ofVec3f& min, ofVec3f& max)
{
	velocity += seperationWeight * separation(otherRedBoids);
	velocity += cohesionWeight * cohesion(otherRedBoids);
	velocity += alignmentWeight * alignment(otherRedBoids);
	velocity.limit(maxVelocity);

	walls(min, max);
	position += velocity;
}

void RedBoid::draw()
{
	ofSetColor(255, 0, 0);
	ofDrawCircle(position.x, position.y, 5);
}