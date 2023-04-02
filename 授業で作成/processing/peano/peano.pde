int n = 0;float x0,y0;
void setup(){
  size(600,600);
  fill(0);
  smooth();
}

void peanoA(float i,float h){
  if(i>0){
    peanoD(i-1,h);move(-h,0);
    peanoA(i-1,h);move(0,h);
    peanoA(i-1,h);move(h,0);
    peanoB(i-1,h);
  }
}
void peanoB(float i,float h){
  if(i>0){
    peanoC(i-1,h);move(0,-h);
    peanoB(i-1,h);move(h,0);
    peanoB(i-1,h);move(0,h);
    peanoA(i-1,h);
  }
}
void peanoC(float i,float h){
  if(i>0){
    peanoB(i-1,h);move(h,0);
    peanoC(i-1,h);move(0,-h);
    peanoC(i-1,h);move(-h,0);
    peanoD(i-1,h);
  }
}
void peanoD(float i,float h){
  if(i>0){
    peanoA(i-1,h);move(0,h);
    peanoD(i-1,h);move(-h,0);
    peanoD(i-1,h);move(0,-h);
    peanoC(i-1,h);
  }
}
void mousePressed(){
  if((mouseButton ==LEFT)&&(n<15))n++;
  else if((mouseButton ==RIGHT)&&(n>0))n--;
}
void move(float x, float y){
  line(x0,y0,x0+=x,y0+=y);
}
void set_start(float x, float y){
  x0=x;
  y0=y;
}
void draw(){
  background(255);
  if(n!=0){
    float h = (width/pow(2,n));//edge
    set_start((width/(4*pow(2,n-1))),(height/(4*pow(2,n-1))*(4*pow(2,n-1)-1)));
    peanoB(n,h);
  }
}
