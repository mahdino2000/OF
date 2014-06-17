#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

    drawSeedBox();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);

	/*float movementSpeed = .1;
	float cloudSize = ofGetWidth() / 2;
	float maxBoxSize = 100;
	float spacing = 1;
	int boxCount = 100;*/



	cam.begin();

    mesh.draw();

	/*for(int i = 0; i < boxCount; i++) {
		ofPushMatrix();

		float t = (ofGetElapsedTimef() + i * spacing) * movementSpeed;
		ofVec3f pos(
			ofSignedNoise(t, 0, 0),
			ofSignedNoise(0, t, 0),
			ofSignedNoise(0, 0, t));

		float boxSize = maxBoxSize * ofNoise(pos.x, pos.y, pos.z);

		pos *= cloudSize;
		ofTranslate(pos);
		ofRotateX(pos.x);
		ofRotateY(pos.y);
		ofRotateZ(pos.z);

		ofLogo.bind();
		ofFill();
		ofSetColor(255);
		ofDrawBox(boxSize);
		ofLogo.unbind();

		ofNoFill();
		ofSetColor(ofColor::fromHsb(sinf(t) * 128 + 128, 255, 255));
		ofDrawBox(boxSize * 1.1f);

		ofPopMatrix();
	}*/

	cam.end();
}

void ofApp::drawSeedBox(){

    float boxSize=50;
    float offsetFromBottom=50;
    // draw the ofBox outlines with some weight
	ofSetLineWidth(2);


	//mesh.setMode(OF_PRIMITIVE_POINTS);
	mesh.setMode(OF_PRIMITIVE_LINES);
    //mesh.enableColors();
    mesh.enableIndices();



    //vertices on down
    ofVec3f dTopLeft(150- boxSize, -ofGetHeight()/2+offsetFromBottom   , boxSize);
    ofVec3f dBottomLeft(150 - boxSize, -ofGetHeight()/2+offsetFromBottom   , 0.0);
    ofVec3f dTopRight(150 + boxSize, -ofGetHeight()/2+offsetFromBottom   , boxSize);
    ofVec3f dBottomRight(150 + boxSize, -ofGetHeight()/2 +offsetFromBottom  , 0.0);

    //vertices on top
    ofVec3f tTopLeft(100.0, 50.0, 0.0);
    ofVec3f tBottomLeft(50.0, 150.0, 0.0);
    ofVec3f tTopRight(150.0, 150.0, 0.0);
    ofVec3f tBottomRight(150.0, 150.0, 0.0);

   /* mesh.addVertex(dTopLeft);
    mesh.addVertex(dBottomLeft);
    mesh.addVertex(dBottomRight);
    mesh.addVertex(dTopRight);

    mesh.addVertex(tTopLeft);
    mesh.addVertex(tBottomLeft);
    mesh.addVertex(tBottomRight);
    mesh.addVertex(tTopRight);*/


   /* mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(2);
    mesh.addIndex(0);
    mesh.addIndex(0);
    mesh.addIndex(2);
    mesh.addIndex(2);
    mesh.addIndex(3);
    mesh.addIndex(3);
    mesh.addIndex(0);*/

/*
    mesh.addIndex(3);
    mesh.addIndex(4);
    mesh.addIndex(4);
    mesh.addIndex(5);
    mesh.addIndex(5);
    mesh.addIndex(3);
    mesh.addIndex(3);
    mesh.addIndex(5);
    mesh.addIndex(5);
    mesh.addIndex(6);
    mesh.addIndex(6);
    mesh.addIndex(3);*/



    mesh = ofMesh::box(200.0, 200.0, 200.0);


    mesh.addTriangle(0,1,2);



    mesh.save("test.ply",false);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
