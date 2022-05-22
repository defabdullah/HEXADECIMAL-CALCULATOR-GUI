#include <iostream>
using namespace std;
int power(int a,int b){
        int result=1;
        for(int i=0;i<b;i++){
                result*=a;
        }
        return result;
}


int convert_integer(std::string number) {
    int size = number.length();
    int result=0;
    for(int i=0;i<size;i++){
            if(number[size-i-1]=='1'){
                    result= power(16,i) * 1 + result; 
            }else if(number[size-i-1]=='2'){
                    result= power(16,i) * 2 + result; 
            }else if(number[size-i-1]=='3'){
                    result= power(16,i) * 3 + result; 
            }else if(number[size-i-1]=='4'){
                    result= power(16,i) * 4 + result; 
            }else if(number[size-i-1]=='5'){
                    result= power(16,i) * 5 + result; 
            }else if(number[size-i-1]=='6'){
                    result= power(16,i) * 6 + result; 
            }else if(number[size-i-1]=='7'){
                    result= power(16,i) * 7 + result; 
            }else if(number[size-i-1]=='8'){
                    result= power(16,i) * 8 + result; 
            }else if(number[size-i-1]=='9'){
                    result= power(16,i) * 9 + result; 
            }else if(number[size-i-1]=='A'){
                    result= power(16,i) * 10 + result;
            }else if(number[size-i-1]=='B'){
                    result= power(16,i) * 11 + result; 
            }else if(number[size-i-1]=='C'){
                    result= power(16,i) * 12 + result; 
            }else if(number[size-i-1]=='D'){
                    result= power(16,i) * 13 + result; 
            }else if(number[size-i-1]=='E'){
                    result= power(16,i) * 14 + result; 
            }else if(number[size-i-1]=='F'){
                    result= power(16,i) * 15 + result; 
           }
    }
   if(number[0]=='-'){
            result*=-1;
    }
    return result;
}

std::string convert_string(int number) {
        char hexaDeciNum[100];
        char result[100];
        std::string result_str;
        int i =0;
        int  is_negative=0;
        if(number==0){
                return "0";
        }else if(number<0){
                number *=-1;
                is_negative=1;
        }
        while (number != 0) {
        // temporary variable to store remainder
        int temp = 0;
        // storing remainder in temp variable.
        temp = number % 16;
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        number = number / 16;
    }
    if(is_negative){
            hexaDeciNum[i]='-';
            hexaDeciNum[i+1]='\0';
            int j=1;
            i=i+1;
            for(j;j<i+1;j++){
                result[j-1]=hexaDeciNum[i-j];
            }
            result[j-1]='\0';
    }else{
            hexaDeciNum[i]='\0';
            int j=1;
            for(j;j<i+1;j++){
                result[j-1]=hexaDeciNum[i-j];
            }
            result[j-1]='\0';
    }
    result_str =result;
    return result_str;
}

int main() {
  std::string number = "";
  cout << convert_integer(number);
  cout << "\n";   
  cout << convert_string(00);
  cout << "\n";  
  return 0;
}

