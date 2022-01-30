#pragma once
#include "Boid.h"
class RedBoid :
    public Boid
{
    protected:
		ofVec3f alignment(std::vector<RedBoid*>& otherRedBoids);
		ofVec3f cohesion(std::vector<RedBoid*>& otherRedBoids);
		ofVec3f separation(std::vector<RedBoid*>& otherRedBoids);
		ofVec3f xenophobia(std::vector<Boid*>& otherBlueBoids);
		
	public:
		void update(std::vector<RedBoid*>& otherRedBoids, std::vector<Boid*>& otherBlueBoids, ofVec3f& min, ofVec3f& max);
		void draw();
};


