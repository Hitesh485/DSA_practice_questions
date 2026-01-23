// User function Template for Java

class ReverseStringArr {
        
    static void swap(char[] ch, int i, int j)
    {
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
    
    public static String reverseString(String s) {
        // code here
        int start = 0;
        int end = s.length() - 1;
        
        char ch[] = s.toCharArray();
        
        while (start < end)
        {
            swap(ch, start, end);
            start++;
            end--;
        }
        
        return new String(ch);
        
    }

    public static void main (String[] args)
    {
        String str = "Geeksforgeeks";
        System.out.println(reverseString(str));
    }
}

