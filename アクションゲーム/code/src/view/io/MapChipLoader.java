package view.io;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;

import javax.imageio.ImageIO;

public class MapChipLoader {

	public static final int MAPCHIP_SIZE = 16;
	private static final String MAPCHIP_FILE_PATH = "src/resources/mapchip320x240.png";

    private BufferedImage image;

    public MapChipLoader() {
        try {
            this.image = ImageIO.read(new File(MAPCHIP_FILE_PATH));
        } catch (IOException e) {
            throw new UncheckedIOException(e);
        }
    }

    public BufferedImage getMapChipImage(char code) {
    	int x = 0;
        int y = 0;
    	switch (code) {
		case 'A':
			x = 0;
			y = 4;
			break;
		case 'B':
			x = 1;
			y = 4;
			break;
		default:
			break;
		}
    	int dx = x * MAPCHIP_SIZE;
        int dy = y * MAPCHIP_SIZE;
        return image.getSubimage(dx, dy, MAPCHIP_SIZE, MAPCHIP_SIZE);
    }

}