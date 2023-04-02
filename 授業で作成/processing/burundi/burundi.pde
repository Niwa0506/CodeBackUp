size(450,300);
background(255);
noStroke();
fill(206,16,33);
triangle(20,0,430,0,225,130);
triangle(20,300,430,300,225,170);

fill(30,181,58);
triangle(0,15,0,285,205,150);
triangle(450,15,450,285,245,150);
fill(255);
ellipse(225,150,160,160);
fill(206,16,33);
  int R = 40,r = 18,w,h;strokeWeight(1.5);
  int one_w = int(R*cos(radians(-90))+225),one_h = int(R*sin(radians(-90))+150),
      two_w = int(R*cos(radians(30))+225), two_h = int(R*sin(radians(30))+150),
      three_w = int(R*cos(radians(150))+225),three_h = int(R*sin(radians(150))+150);
     stroke(30,181,58);
     for(int i=0;i<3;i++){
       if(i==0){w=one_w;h=one_h;}
       else if(i==1){w=two_w;h=two_h;}
       else {w=three_w;h=three_h;}
       stroke(30,181,58);
       beginShape();
       for(int j=0;j<12;j++){
         int lr,sr=r-8;
         if(j%2==0)lr=r;
         else lr=sr;
         vertex(lr*cos(radians(30*j-90))+w,lr*sin(radians(30*j-90))+h);
       }
       endShape(CLOSE);
     }
