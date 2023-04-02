package view.io;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;

public class MapDataLoader {
	private static int MAPCHIP_SIZE;
	private char[][] mapData;
	public BufferedImage image;
	private static final String MAP_FILE_PATH = "src/resources/mapB.txt";

	private static final int WIDTH = 50;
	private static final int HEIGHT = 40;

	public MapDataLoader() {
		MAPCHIP_SIZE = MapChipLoader.MAPCHIP_SIZE;
		/*芝サンプル
		mapData = new char[HEIGHT][WIDTH];
		for(int i = 0; i < WIDTH; i++) {
			for(int j = 0; j < HEIGHT; j++) {
				mapData[j][i] =  'A';
			}
		}
		*/

		mapData = loadMapData();
		image = createMapImage();
	}

	public char[][] loadMapData() {
		String[] lines;
		int lineCount = 0;
		char[][] chars = null;

		try{
			FileReader fileReader = new FileReader(new File(MAP_FILE_PATH));
			LineNumberReader lnr = new LineNumberReader(fileReader);
            while (lnr.readLine() != null){
            	lineCount++;
            }
            lnr.close();
		}catch(FileNotFoundException e){
			System.out.println(e);
		}catch(IOException e){
			System.out.println(e);
		}

		FileReader fileReader;
		try {
			fileReader = new FileReader(new File(MAP_FILE_PATH));
			BufferedReader br = new BufferedReader(fileReader);
	        lines = new String[lineCount];
	        int i = 0;
			String string;
			while((string = br.readLine()) != null){
				lines[i++] = string;
			}
			br.close();
			chars = new char[lineCount][];
		    for (i = 0; i < lineCount; i++) {
		        chars[i] = lines[i].toCharArray();
		    }
		} catch (IOException e) {
			e.printStackTrace();
		}
	    return chars;
	}


	private BufferedImage createMapImage() {
	    int height = mapData.length;
	    int width = mapData[0].length;
	    BufferedImage bi = new BufferedImage(MAPCHIP_SIZE * width, MAPCHIP_SIZE * height, BufferedImage.TYPE_INT_RGB);
	    Graphics g = bi.getGraphics();
	    MapChipLoader mapChipLoader = new MapChipLoader();
	    int gY = 0;
	    for (int y = 0; y < height; y++) {
	        int gX = 0;
	        for (int x = 0; x < width; x++) {
	            g.drawImage(mapChipLoader.getMapChipImage(mapData[y][x]), gX, gY, null);
	            gX += MAPCHIP_SIZE;
	        }
	        gY += MAPCHIP_SIZE;
	    }
	    return bi;
	}
}
