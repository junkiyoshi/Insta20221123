#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius_span = 20;
	auto len = 600;
	ofColor color;

	ofSeedRandom(39);
	for (int radius = 60; radius <= 320; radius += radius_span) {

		auto noise_seed = ofRandom(1000);
		for (int i = 0; i < len; i++) {

			auto deg = ofMap(ofNoise(noise_seed, i * 0.00035 - ofGetFrameNum() * 0.0025), 0, 1, -360, 360);
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		
			ofNoFill();
			ofSetColor(255);
			ofDrawCircle(location, radius_span * 0.3 + 1);
		}
	
	}

	ofSeedRandom(39);
	for (int radius = 60; radius <= 320; radius += radius_span) {

		auto noise_seed = ofRandom(1000);
		auto hue = ofMap(radius, 60, 320, 0, 255);
		for (int i = 0; i < len; i++) {

			auto deg = ofMap(ofNoise(noise_seed, i * 0.00035 - ofGetFrameNum() * 0.0025), 0, 1, -360, 360);
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			color.setHsb((int)(hue + i * 0.1) % 255, 200, 255);

			ofFill();
			ofSetColor(color);
			ofDrawCircle(location, radius_span * 0.3);
		}

	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}