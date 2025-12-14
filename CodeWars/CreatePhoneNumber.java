public class Kata 
{
  public static String createPhoneNumber(int numbers[]) 
  {
    char[] Arr = new char[14];

    Arr[0]  = '(';
    Arr[1]  = (char)(numbers[0] + '0');
    Arr[2]  = (char)(numbers[1] + '0');
    Arr[3]  = (char)(numbers[2] + '0');
    Arr[4]  = ')';
    Arr[5]  = ' ';
    Arr[6]  = (char)(numbers[3] + '0');
    Arr[7]  = (char)(numbers[4] + '0');
    Arr[8]  = (char)(numbers[5] + '0');
    Arr[9]  = '-';
    Arr[10] = (char)(numbers[6] + '0');
    Arr[11] = (char)(numbers[7] + '0');
    Arr[12] = (char)(numbers[8] + '0');
    Arr[13] = (char)(numbers[9] + '0');

    return new String(Arr);
  }
}
