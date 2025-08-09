package DesignPatterns.ChainOfResponsibilityPattern.Logger;

import java.util.Objects;

public class AbstractLogger {

    private AbstractLogger nextLogger;

    public AbstractLogger(AbstractLogger nextLogger){
        this.nextLogger = nextLogger;
    }

    public void log(String logLevel, String msg) {
        if(Objects.nonNull(nextLogger)){
            nextLogger.log(logLevel, msg);
        } else{
            System.out.println("LOGGING failed!");
        }
    }
}
