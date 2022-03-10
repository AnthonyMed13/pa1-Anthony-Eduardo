#include "ofApp.h"
#include<iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    sound.loadSound("beat.wav"); //Loads a sound file (in bin/data/)
    sound.setLoop(true); // Makes the song loop indefinitely
    sound.setVolume(1); // Sets the song volume
    ofSetBackgroundColor(255, 182,193); // Sets the Background Color)
    ofSetColor(ColorMode1,Color2Mode1,Color3Mode1); 


}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate(); // Updates all sound players
    visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if(!playing){
        ofDrawBitmapString("Press 'a' to play some music!", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    if(recording == true)
    {
        ofSetColor(0,0,0);
        ofDrawBitmapString("RECORDING", ofGetWidth()-80,ofGetHeight()/ofGetHeight()+10);
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
    switch(key){
        case 'a':
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
        case 'r':
            if (recording != true)
            {
            recording = true;
            }
            else recording = false;
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