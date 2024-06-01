package Example.tic_tac_toe.personal.strategy;

import Example.tic_tac_toe.personal.State;

import java.util.List;

public interface IPlayingStrategy {

    List<Integer> nextMove(State state);
}
