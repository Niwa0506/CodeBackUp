package controller;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import model.game.GameManager;
import view.BasePanel;

public class TitleController implements KeyListener{
	BasePanel basePanel;

	public TitleController(BasePanel panel) {
		this.basePanel = panel;
	}

	@Override
    public void keyPressed(KeyEvent e){
    	switch(e.getKeyCode( )){
            case KeyEvent.VK_ENTER:
            	GameManager.getInstance().newGame();
            	this.basePanel.switchWindow(BasePanel.GAME_WINDOW_ID);
            	break;
        }
    }

	@Override
	public void keyTyped(KeyEvent e) {}
	@Override
	public void keyReleased(KeyEvent e) {}
}
