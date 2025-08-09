package Example.tic_tac_toe.personal.strategy;

import Example.tic_tac_toe.personal.State;

import java.util.List;

public class RandomPlayingStrategy implements IPlayingStrategy{
    @Override
    public List<Integer> nextMove(State state) {
        System.out.println("Random strategy activated");
        return null;
    }
}
