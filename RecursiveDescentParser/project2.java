/*
 *  Toufic Hamadeh
 *  UCID 31234305
 *  Java version
 */

import java.io.*;
import java.util.*;

class project2 {

    public static void main(String[] args) {
        try {
            FileInputStream fstream = new FileInputStream("input.txt");
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            
            while ((s = br.readLine()) != null) {
                if (A() && i == s.length()) {
                    System.out.println("The string \"" + s + "\" is in the language.");
                    i = 0;
                }
                else {
                    System.out.println("The string \"" + s + "\" is not in the language.");
                    i = 0;
                }
            }
        in.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    public static boolean A() {
        if (I()) {
            if (i < s.length() && s.charAt(i) == '=') {
                ++i;
                if (E()) {
                    return true;
                }
            }
        }
        if (E()) {
            return true;
        }
    return false;
    }
  
    public static boolean E () {
        if (T()) {
            if (i < s.length() && s.charAt(i) == '+' || i < s.length() && s.charAt(i) == '-') {
                ++i;
                if (E()) {
                    return true;
                }
            }
            return true;
        }
    return false;
    }
    
    public static boolean T() {
        if (F()) {
            if (i < s.length() && s.charAt(i) == '/' || i < s.length() && s.charAt(i) == '*') {
                ++i;
                if (T()) {
                    return true;
                }
            }
            return true;
        }
    return false;
    }
    
    public static boolean F() {
        if (P()) {
            if (i < s.length() && s.charAt(i) == '^') {
                ++i;
                if (F()) {
                    return true;
                }
            }
            return true;
        }
    return false;
    }
    
    public static boolean P() {
        if (I()) {
            return true;
        }
        if (L()) {
            return true;
        }
        if (U()) {
            if(I() || L()) {
               return true;
            }
        }
        if (i < s.length() && s.charAt(i) == '(') {
            ++i;
            if (A()) {
                if (i < s.length() && s.charAt(i) == ')') {
                    ++i;
                    return true;
                }
            }
        }
    return false;
    }
    
    public static boolean U() {
        if (i < s.length() && s.charAt(i) == '+'  || i < s.length() && s.charAt(i) == '-' || i < s.length() && s.charAt(i) == '!' ) {
        ++i;
        return true;
        }
    return false;
    }
    
    public static boolean I() {
        if (C()){
            if (I()) {
                return true;
            }
        return true;
        }
    return false;
    }
    
    public static boolean C() {
        if (i < s.length() && s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
            ++i;
            return true;
        }
        return false;
    }
    
    public static boolean L() {
        if (D()){
            if (L()) {
                return true;
            }
        return true;
        }
    return false;
    }
    
    public static boolean D() {
        if (i < s.length() && '0' <= s.charAt(i) && s.charAt(i) <= '9') {
            ++i;
            return true;
        }

        return false;
    }
    private static String s;
    private static int i;
}
