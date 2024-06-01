package DesignPatterns.ChainOfResponsibilityPattern.Logger;

public class AbstractLoggerFactory {

    public static AbstractLogger getLogger(){
        return new InfoLogger(new ErrorLogger(new DebugLogger(null)));
    }
}
