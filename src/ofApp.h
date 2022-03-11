#pragma once

#include "ofMain.h"
#include "AudioVisualizer.h"
#include <vector>
#include <string>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void drawMode1(vector<float> amplitudes);
		void drawMode2(vector<float> amplitudes);
		void drawMode3(vector<float> amplitudes);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		int ColorMode1;
    	int Color2Mode1;
    	int Color3Mode1;
		int ColorMode3;
    	int Color2Mode3;
    	int Color3Mode3;
		bool keyA = false;
		bool recording = false;
		std::vector<char> keysPressed;
	private:
		ofSoundPlayer sound;
		AudioVisualizer visualizer;
		
		bool playing = false;
		char mode = '1';
};
