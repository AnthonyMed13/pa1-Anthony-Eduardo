#include "ofApp.h"
#include<iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    sound.setVolume(1);
    ofSetBackgroundColor(255, 182,193); // Sets the Background Color)
    ofSetColor(ColorMode1,Color2Mode1,Color3Mode1); 
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    if (keyA != true){
        ofSoundUpdate(); // Updates all sound players
        visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if(!playing){
        ofDrawBitmapString("Press 'p' to play some music!", ofGetWidth()/2 - 50, ofGetHeight()/2);
        ofDrawBitmapString("Press 'o' to select geesebeat.wav! / Press 'l' to select pigeon-coo.wav! / Press 'k' to select rock-song.wav! / Press 'd' to select beat.wav!", ofGetWidth()/2 - 500, ofGetHeight()/2 + 100);
    }
    if(playing){
        ofDrawBitmapString("Press 'p' again to select different beats!", 1580, 50);
    }
    if(recording == true)
    {
        ofSetColor(0,0,0);
        ofDrawBitmapString("RECORDING", ofGetWidth()-80,ofGetHeight()/ofGetHeight()+10);
    }
    if(replaying == true)
    {
        ofSetColor(0,0,0);
        ofDrawBitmapString("REPLAYING", ofGetWidth()-80,ofGetHeight()/ofGetHeight()+10);
    }
    vector<float> amplitudes = visualizer.getAmplitudes();
    if(mode == '1'){
        ofSetColor(ColorMode1,Color2Mode1,Color3Mode1); 
        drawMode1(amplitudes);
    }else if(mode == '2'){
        drawMode2(amplitudes);
    }else if(mode == '3'){
        drawMode3(amplitudes);
    }
}
void ofApp::drawMode1(vector<float> amplitudes){
        int w = 0;
        int bands = amplitudes.size();
        ofFill(); // Drawn Shapes will be filled in with color
        ofSetColor(256);  //This resets the color of the "brush" to white
        ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        
        
        for(int i=0; i< bands; i++){
            ofSetColor(ColorMode1,Color2Mode1,Color3Mode1); 
            ofDrawRectangle((ofGetWidth()-ofGetWidth())+w, ofGetHeight(), ofGetWidth()/64,  amplitudes[i]);
            w += ofGetWidth()/64;
        }



}
void ofApp::drawMode2(vector<float> amplitudes){
        ofSetLineWidth(5); // Sets the line width
        ofNoFill(); // Only the outline of shapes will be drawn
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Circle Radius Visualizer", 0, 15);
        int bands = amplitudes.size();
        for(int i=0; i< bands; i++){
            ofSetColor((bands - i)*32 %256,18,144); // Color varies between frequencies
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, amplitudes[0]/(i +1));
        }
}

void ofApp::drawMode3(vector<float> amplitudes){
    int w = 0;
    int bands = amplitudes.size();
    ofFill();
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
    // YOUR CODE HERE
    for(int i=0; i< bands; i++){
            ofSetColor(ColorMode3,Color2Mode3,Color3Mode3); 
            ofDrawRectangle(ofGetWidth(), (ofGetHeight()-ofGetHeight())+w,amplitudes[i], ofGetHeight()/64);
            w += ofGetHeight()/64;
        }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    if (recording == true)
    {
        keysPressed.push_back(key);
    }
    if (replaying == true)
    {
        for (int i = 0; i < keysPressed.size(); i++)
            keysPressed[i];
    }
    switch(key){
        case 'p':
            if(playing){
                sound.stop();
            }else{
                sound.play();
            }
            playing = !playing;

            break;
        case '1':
            mode = '1';
            ColorMode1 = ofRandom(255);
            Color2Mode1 = ofRandom(255);
            Color3Mode1 = ofRandom(255);
            break;
        case '2':
            mode = '2';
            break;
        case '3':
            mode = '3';
            ColorMode3 = ofRandom(255);
            Color2Mode3 = ofRandom(255);
            Color3Mode3 = ofRandom(255);
            break;
        case 'a':
            if (keyA != true){
                keyA = true;
            }
            else keyA = false;
            break;
        case 'o':
            sound.load("geesebeat.wav");
            sound.setLoop(true);
            break;
        case 'l':
            sound.load("pigeon-coo.wav");
            sound.setLoop(true);
            break;
        case 'k':
            sound.load("rock-song.wav");
            sound.setLoop(true);
            break;
        case 'd':
            sound.load("beat.wav");
            sound.setLoop(true);
            break;
        case '-':
            sound.setVolume(0);
            break;
        case '=':
            sound.setVolume(1);
            break;
        case 'r':
            if (recording != true)
            {
            recording = true;
            }
            else recording = false;
        case 't':
            if (replaying != true){
                replaying = true;
            }
            else replaying = false;
        case 'c':
            if (replaying != false){
                replaying = false;
            }
            else replaying = false;
    }

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