package DesignPatterns.ChainOfResponsibilityPattern.Logger;

import DesignPatterns.ChainOfResponsibilityPattern.LogLevelEnum;

public class InfoLogger extends AbstractLogger implements ILogger{

    private LogLevelEnum logLevelEnum = LogLevelEnum.info;

    public InfoLogger(AbstractLogger nextLogger) {
        super(nextLogger);
    }

    @Override
    public void log(String logLevel, String msg){
        if(logLevel.equalsIgnoreCase(logLevelEnum.getLogLevel())){
            System.out.println("LogLevel: " + logLevel + "\nmsg: " + msg + "\n---------------------------");
        } else{
            super.log(logLevel, msg);
        }
    }
}
