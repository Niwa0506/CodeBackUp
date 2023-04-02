float ox=0;float oy=0;float oz=5;
float cx=0;float cy=0;float cz=0;
float r=1;
final float NO_HIT = Float.POSITIVE_INFINITY;
PVector lightPos = new PVector(10,10,10);
int lightpower = 4000;
void setup(){
  size(256,256);
}

int y = 0;
void draw(){
  for(int x = 0;x<width;x++){
    color c = calcPixelColor(x,y);
    set(x,y,c);
  }
  y++;
  if(height<=y)noLoop();
}
boolean intersectRaysphere(PVector rayOrigin,PVector rayDir,PVector spherecenter,float sphereradius){
  float a = sq(dx)+sq(dy)+sq(dz);
  float b = 2*(dx*(ox-cx)+dy*(oy-cy)+dz*(oz-cz));
  float c = sq(ox-cx)+sq(oy-cy)+sq(oz-cz)-sq(r);
  float d = b*b-4*a*c;
  return 0 <=d;
}

color calcPixelColor(int x,int y){
  float imagePlane = height;
  float dx = x+0.5-width/2;
  float dy = -(y+0.5-height/2);
  float dz = -imagePlane;
  if(intersectRaysphere(ox,oy,oz,dx,dy,dz,cx,cy,cz,r)){
    return color(255,255,255);
  }else{
    return color(0,0,0);
  }
}
