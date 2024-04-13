public class Company{
    private int n;

    public void produce(int n){
        System.out.println("Produced " + n);
    }

    public void consume(int n){
        System.out.println("Consumed " + n);
    }
}

class MyThread extends Thread{

}