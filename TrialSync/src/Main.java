public class Main {
    public static void main(String[] args) {

        System.out.println("Hello world!");
        Company company = new Company();
        MyThread producer = new MyThread(true, company), consumer = new MyThread(false, company);

        producer.start();
        consumer.start();
    }
}