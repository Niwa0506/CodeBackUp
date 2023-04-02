package controller;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import model.character.Player;
import model.game.GameManager;

public class GameController implements KeyListener
{
	private static final int SPEED = 8;
    Player player;
    public GameController() {
    	player = GameManager.getInstance().getGame().getCharacterManager().getPlayer();
    }

    @Override
    public void keyPressed(KeyEvent e){
    	switch(e.getKeyCode( )){
            case KeyEvent.VK_DOWN:
            	player.move(0, 1);
            	break;
            case KeyEvent.VK_LEFT:
            	player.move(-1, 0);
            	break;
            case KeyEvent.VK_RIGHT:
            	player.move(1, 0);
            	break;
    		case KeyEvent.VK_UP:
            	player.move(0, -1);
        		break;
    		case KeyEvent.VK_SPACE:
    			GameManager.getInstance().getGame().dismiss();
        }
    }

	@Override
    public void keyReleased(KeyEvent e) { }
	@Override
    public void keyTyped(KeyEvent e) { }
}

