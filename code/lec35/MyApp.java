import java.io.*;
// javac MyApp.java && java MyApp &
// jps or ps aux | grep MyApp 
// kill -SIGQUIT pid
// "Thread-0" and main thread

class MyApp {

public static void main(String[] args) throws IOException {
  // Linux specific
  String pid = new File("/proc/self").getCanonicalFile().getName();
  System.out.println("Started\nProcess id :" +  pid ); 

  Thread t = new Thread() { 
    public long calculate() {
        return new File("MyApp.java").lastModified();    
    }

    public void run() {
      System.out.println("Thread started");
      long previous = calculate();
      while(true) { 
       long current = calculate();
       if(previous != current) {
           System.out.println("Just what do you think you're doing, Dave?");
           previous = current;
       }
      } 
     }
  };
  t.setName("HAL 9000");
  t.start();

  try {
    Thread.sleep(100000);
  } catch (InterruptedException ex) {
    System.out.println("InterruptedException");
  }
  System.out.println("Exiting");
}

}
