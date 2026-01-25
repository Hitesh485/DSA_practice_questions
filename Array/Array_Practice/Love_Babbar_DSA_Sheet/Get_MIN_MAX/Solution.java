package Get_MIN_MAX;

import java.util.ArrayList;

public class Solution {

    public ArrayList<Integer> getMinMax(int[] arr) {
        // code Here
        // find max
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        
        for (int i = 0; i < arr.length; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        res.add(min);
        res.add(max);
        return res;
        
    }

    public static void main (String[] args)
    {

    }
}
