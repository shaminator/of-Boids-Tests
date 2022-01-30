#include "ofApp.h"

ofApp::~ofApp() {
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
	for (int i = 0; i < redBoids.size(); i++)
	{
		delete redBoids[i];
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0, 50, 50);

	// set up the boids
	for (int i = 0; i < 50; i++) {
		boids.push_back(new Boid());
		redBoids.push_back(new RedBoid());
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
	}
	for (int i = 0; i < redBoids.size(); i++)
	{
		redBoids[i]->update(redBoids, boids, min, max);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
	for (int i = 0; i < redBoids.size(); i++)
	{
		redBoids[i]->draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}