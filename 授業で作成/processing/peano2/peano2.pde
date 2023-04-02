int n = 0;float x0,y0;
void setup(){
  size(620,640);
  textFont(createFont("Tempus Sans ITC",24));
  fill(0);
  smooth();
}

void peanoA(int i,float h){
  if(i>0){
    peanoC(i-1,h);move(0,-h);
    peanoA(i-1,h);move(h,0);
    peanoA(i-1,h);move(0,h);
    peanoB(i-1,h);
  }
}
void peanoB(int i,float h){
  if(i>0){
    peanoD(i-1,h);move(-h,0);
    peanoB(i-1,h);move(0,h);
    peanoB(i-1,h);move(h,0);
    peanoA(i-1,h);
  }
}

void peanoC(int i,float h){
  if(i>0){
    peanoA(i-1,h);move(h,0);
    peanoC(i-1,h);move(0,-h);
    peanoC(i-1,h);move(-h,0);
    peanoD(i-1,h);
  }
}
void peanoD(int i,float h){
  if(i>0){
    peanoB(i-1,h);move(0,h);
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
  text("n = "+n,10,30);
  if(n!=0){
    float h = (600/pow(2,n));//edge
    set_start((600/(4*pow(2,n-1)))+10,(600/(4*pow(2,n-1))*(4*pow(2,n-1)-1))+30);
    peanoA(n,h);
  }
}
