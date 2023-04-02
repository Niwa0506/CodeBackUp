package view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JPanel;

import model.character.Character;
import model.character.Position;
import model.game.Game;
import model.game.GameManager;
import view.io.MapDataLoader;

public class GamePanel extends JPanel implements Observer{
	private Game game;
	private BufferedImage mapImage;
	private Image   charaImage;
	private BasePanel basePanel;

	private static final String CHARACTER_IMAGE_FILE = "src/resources/fuku_g.png";

	public GamePanel(BasePanel basePanel) {
		this.basePanel = basePanel;
		this.setPreferredSize(new Dimension(800, 640));
		MapDataLoader loader = new MapDataLoader();
		mapImage = loader.image;

        charaImage = getToolkit().getImage(CHARACTER_IMAGE_FILE);

		game = GameManager.getInstance().getGame();
		game.addObserver(this);
	}

	@Override
	public void paint(Graphics graphics) {
		super.paintComponent(graphics);

		graphics.drawImage(mapImage, 0, 0, null);

		Position pos = game.getCharacterManager().getPlayer().getPosition();
		int r = 100;
		graphics.drawOval(pos.getX() - r + 16, pos.getY() - r + 24, 2*r, 2*r);

		for(Character character : game.getCharacterManager().getCharacters()) {
			if(character.getIsInfected()){
				pos = character.getPosition();
				graphics.setColor(Color.RED);
				graphics.drawOval(pos.getX() - r + 16, pos.getY() - r + 24, 2*r, 2*r);
			}
		}

		for(Character character : game.getCharacterManager().getCharacters()) {
			drawCharacterImage(graphics, character);
		}
	}

	public void drawCharacterImage(Graphics graphics, Character character) {
		Position pos = character.getPosition();
		int dx = (character.getLooksType() % 4) * 32 * 3;
		int dy = (character.getLooksType() / 4) *48 *4;

		graphics.drawImage(charaImage, pos.getX(), pos.getY(), pos.getX()+32, pos.getY()+48,
				dx + character.getWalkingPattern()*32, dy + pos.getRotate()*48, dx + character.getWalkingPattern()*32+32, dy + pos.getRotate()*48+48, this);
	}

	@Override
	public void update(Observable o, Object arg) {
		if(game.isGameOver()) {
			basePanel.switchWindow(BasePanel.TITLE_WINDOW_ID);
		}else {
			repaint();
		}
	}
}
