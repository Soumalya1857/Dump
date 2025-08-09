package Example.tic_tac_toe.personal;

import Example.tic_tac_toe.personal.strategy.IPlayingStrategy;

import java.util.List;

public class Player {
    private Symbol symbol;
    private String name;
    private IPlayingStrategy playingStrategy;

    public Player(String name, Symbol symbol, IPlayingStrategy playingStrategy){
        this.symbol = symbol;
        this.playingStrategy = playingStrategy;
        this.name = name;
    }

    List<Integer> nextMove(State currState){
        return playingStrategy.nextMove(currState);
    }
}
