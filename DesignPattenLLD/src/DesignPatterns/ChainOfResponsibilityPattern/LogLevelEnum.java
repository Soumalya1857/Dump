package DesignPatterns.ChainOfResponsibilityPattern;

public class LogLevelEnum {
    String logLevel;

    public static final LogLevelEnum info = new LogLevelEnum("info");
    public static final LogLevelEnum error = new LogLevelEnum("error");
    public static final LogLevelEnum debug = new LogLevelEnum("debug");

    public LogLevelEnum(String logLevel){
        this.logLevel = logLevel;
    }

    public String getLogLevel() {
        return logLevel;
    }
}
