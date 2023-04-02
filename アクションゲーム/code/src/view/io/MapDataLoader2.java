package view.io;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class MapDataLoader2 {
	char map[][];
	public BufferedImage image; //←これに画像を入れることができたらこのプログラムをMapDataLoaderと差し替え

	public MapDataLoader2() {
	 try{
    	  int ch,x=0,y=0;map=new char[50][40];
    	  File file = new File("src/resources/mapB.txt");
    	  FileReader filereader = new FileReader(file);
    	  while((ch = filereader.read())!= -1&&y<40){
    		  if((char)ch=='\n') {
    			  x=0;y++;
    			  //System.out.println();
    		  }else if((char)ch!='\n'&&x<50){
        	   map[x][y]=(char)ch;
         	  //System.out.print(map[x][y]);
         	  x++;
           }
       }
       filereader.close();
    }catch(IOException e){
      System.out.println(e);
    }
  }
	public char[][]getmap(){
		return map;
	}
  private static boolean checkBeforeWritefile(File file){
    if (file.exists()){
      if (file.isFile() && file.canWrite()){
        return true;
      }
    }

    return false;
  }
}
