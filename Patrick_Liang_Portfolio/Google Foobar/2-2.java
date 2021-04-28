public class Solution {
    public static int solution(int total_lambs) {
        return strict(total_lambs) - generous(total_lambs);
    }
    public static int generous(int total){
        int leftOver = total - 1;
        int count = 1;
        int highestEarning = 1;
        int secondHighestEarning = 0;
        while(leftOver > highestEarning){
            if(leftOver >= 2 * highestEarning){
                secondHighestEarning = highestEarning;
                highestEarning *= 2;
                leftOver -= highestEarning;
                count++;
            }
            else{
                if(leftOver > highestEarning + secondHighestEarning){
                    count++;
                    return count;
                }
                else{
                    return count;
                }
            }
        }
        return count;
    }

    public static int strict(int total){
        int leftOver = total - 1;
        int count = 1;
        int highestEarning = 1;
        int secondHighestEarning = 0;
        while(leftOver >= highestEarning){
            if(leftOver >= highestEarning + secondHighestEarning){
                int tmp = highestEarning;
                highestEarning += secondHighestEarning;
                secondHighestEarning = tmp;
                leftOver -= highestEarning;
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
}
