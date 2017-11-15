#include "ofApp.h"

// declare variables to store the state of the circle
ofVec2f circlePosition;
ofVec2f circleVelocity;
int radius = 30;
int r;
int g;
int b;

// declare a variable to store the amount of friction we want to apply every frame
float friction;

//--------------------------------------------------------------
void ofApp::setup(){

	// set the background color
	ofSetBackgroundColor(0, 0, 0);
    ofSetBackgroundAuto(false);
	// set the draw color
//    ofSetColor(r, g, b);
    
    r=50;
    g=50;
    b=50;

	// initialize the values in the circlePosition & circleVelocity vectors
	circlePosition.set(ofGetWidth()/2, ofGetHeight()/2);
	circleVelocity.set(0,0);

	// same for friction
	friction = 0.99f;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if ( circleVelocity.x > 0){
        r++;
        
    }
    
    if ( circleVelocity.y >0 ) {
        g++;
        
    }
    
    if(r>255){
        r=255;
    }
    if(g>255){
        g=255;
    }
    if(b>255){
        b=255;
    }
    
    
  
    
    
	// update the circle's position based on its velocity
	circlePosition += circleVelocity;

	// this is how you can print debug info to the console
//	printf("circle velocity: %f \n", circleVelocity.x);

	// reduce the velocity by a fractional amount to simulate friction
	circleVelocity *= friction;

	// check boundaries of screen -- if the x position is less than zero
	// or greater than the screen's width, invert the velocity to bring it back
	if (circlePosition.x < 0 || circlePosition.x > ofGetWidth()) {
		circleVelocity.x *= -1;
	}

	// do the same but for the y values
	if (circlePosition.y < 0 || circlePosition.y > ofGetHeight()) {
		circleVelocity.y *= -1;
	}
   
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw the circle at the current position as specified by the circlePosition
	// vector
    ofSetColor(r, g, b);
	ofDrawCircle(circlePosition.x, circlePosition.y, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='a'){
        r+=5;
    }
    if(key=='b'){
        g+=5;
    }
    if(key=='c'){
        b+=5;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

        radius+=1;
    
    
}

//--------------------------------------------------------------
// add a value between -5 and 5 to the circleVelocity values when the mouse
// is pressed
void ofApp::mousePressed(int x, int y, int button){
	circleVelocity.x += 5 - ofRandom(10);
	circleVelocity.y += 5 - ofRandom(10);
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
