package DesignPatterns.ChainOfResponsibilityPattern;

import DesignPatterns.ChainOfResponsibilityPattern.Logger.AbstractLogger;
import DesignPatterns.ChainOfResponsibilityPattern.Logger.AbstractLoggerFactory;

public class Runner {
    public static void main(String[] args) {
        AbstractLogger Logger = AbstractLoggerFactory.getLogger();


        // child called first as the object is Instance of InfoLogger altough its inside AbstractLogger
        Logger.log(LogLevelEnum.info.getLogLevel(), "Heres my info");
    }
}
