int nPoints=50000;
float complexity =3;
float maxMass=0.05;
float timeSpeed=0.002;
float phase=PI;

float windSpeed=70;
int step=10;

float[] pollenMass;
float[][] points;

void setup(){
  //size(500,400,P3D);
  size(displayWidth, displayHeight,P3D);
  background(0);
  frameRate(30);
  points=new float[nPoints][2];
  pollenMass=new float[nPoints];

  for(int i=0;i<nPoints;i++){
    points[i]=new float[]{
     random(0,width),random(0,height) 
    };
    pollenMass[i]=noise(0,maxMass);
  }
}

void draw(){
  background(0);
  stroke(255);
  smooth();

  //camera(mouseX, mouseY, 220.0, width/2, height/2, height/2, 1, 1, 1);

  for(int i=0; i<nPoints; i++){
  pushMatrix();
    float x = points[i][0];
    float y = points[i][1];
    float z = points[i][1];

    float normx = norm(x, 0, width);
    float normy = norm(y, 0, height);
    float normz = norm(z, 0, -1000);
    float u = noise(phase, normx * complexity, normy * complexity);
    float v = noise(phase, normy * complexity, normz * complexity);
    float w = noise(phase, normz * complexity, normx * complexity);
    float speed = (1 + noise(u, v, w)) / pollenMass[i];
    x += lerp(-speed, speed, u);
    y += lerp(-speed, speed, v);
    z += lerp(-speed, speed, w);

    strokeWeight(z/random(100, 500));
    point(x, y, z);
    //image(particleImg, x, y, 30, 30);

    points[i][0] = x;
    points[i][1] = y;
    points[i][1] = z;
    popMatrix();

  }
}

void mousePressed(){
  setup();
}

void keyPressed() {
  if ( key == ' ' ) {
    save( "hoge.png" );
  }
}
