import java.io.*;

public class FileCopy {
    public static void main(String[] args) throws IOException{
        int i;
        FileInputStream fin = null;
        FileOutputStream fout = null;
        if(args.length !=  2) {
            System.out.println("Usage: FileCopy source destination");
            return;
        }
        try{
            fin = new FileInputStream(args[0]);
            fout = new FileOutputStream(args[1]);

            do {
                i = fin.read();
                if(i != -1) fout.write(i);
            } while(i != -1);
        } catch (IOException e) {
            System.out.println("I/O Error: " + e);
        } finally {
            try {
                if (fin != null) fin.close();
            } catch (IOException e1) {
                System.out.println("Error closing input file: " + e1);
            }
            try {
                if(fout != null) fout.close();
            } catch (IOException e2) {
                System.out.println("Error closing output file: " + e2);
            }
        }
    }
}
