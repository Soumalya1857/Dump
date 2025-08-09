
public class UserThread extends Thread {

    public UserThread(String threadName){
        super(threadName);
    }

    @Override
    public void run(){
        for(int i=0; i<5; i++){
            System.out.println("inside "+ Thread.currentThread().getName()+ " " + i);
        }
    }
}
