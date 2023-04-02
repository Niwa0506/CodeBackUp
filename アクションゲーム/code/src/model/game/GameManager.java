package model.game;
public class GameManager {

	private static GameManager instance = new GameManager();
	private Game game;

	private GameManager() {
		game = new Game();
	}

	public static GameManager getInstance() {
		return instance;
	}

	public void newGame() {
		game.initGame();
		game.start();
	}

	public Game getGame() {
		return game;
	}
}
