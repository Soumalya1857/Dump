package DesignPatterns.ChainOfResponsibilityPattern.Logger;

import DesignPatterns.ChainOfResponsibilityPattern.LogLevelEnum;

public class DebugLogger extends AbstractLogger implements ILogger{

    private LogLevelEnum logLevelEnum = LogLevelEnum.debug;

    public DebugLogger(AbstractLogger nextLogger) {
        super(nextLogger);
    }

    @Override
    public void log(String logLevel, String msg) {
        if(logLevel.equalsIgnoreCase(logLevelEnum.getLogLevel())){
            System.out.println("LogLevel: " + logLevel + "\nmsg: " + msg + "\n---------------------------");
        } else{
            super.log(logLevel, msg); // call to super
        }
    }
}
