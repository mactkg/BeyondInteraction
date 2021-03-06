#include "ofBlob.h"

//コンストラクタ：位置と半径を指定
ofBlob::ofBlob(){
    pos = ofPoint(400, 300); //位置の指定
    dim = 80.0; //半径の指定
}

//メソッド：円を描く
void ofBlob::draw(){
    //円1を描く - 外周
    ofSetColor(31, 63, 255, 100);
    ofCircle(pos.x, pos.y, dim);
    //円2を描く - 核
    ofSetColor(255, 0, 0, 200);
    ofCircle(pos.x, pos.y, dim/10.0);
    ofSetColor(31, 63, 255);
}

//posセッター
void ofBlob::setPos(ofPoint _pos){
    pos = _pos;
}

//posゲッター
ofPoint ofBlob::getPos(){
    return pos;
}

//dimセッター
void ofBlob::setDim(float _dim){
    dim = _dim;
}

//dimゲッター
float ofBlob::getDim(){
    return dim;
}