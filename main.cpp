#include <iostream>
using namespace std;


int fun2(float[], int);
char fun1(float a);

int fun3(float[], int);

int main() 
{
    int exercise;
    cout << "exercise №:";
    cin >> exercise;
    switch(exercise){
        case 1:{
            int x;
            int temp_reference = 273;
            cin >> x;
            if (x < temp_reference)
                cout << "warning low temp:" << x << endl;
            else if (x > temp_reference)
                cout << x << "| T-X= |" << x-temp_reference << endl;
            break;}
        case 2:{
            cout << "\nEnter the distance (mm) ";
            float dist;
            cin>> dist;
            if (dist < 1000 && dist > 850)    
                cout << "\nObstacle close to the sensor ";
            if (dist < 850 && dist > 300)    
                cout << "\nThe obstacle is less than 85cm away ";
            if (dist < 300 && dist !=0 )    
                cout << "\nObstacle is less than 30cm away ";
            if (dist == 0 )    
                cout << "\nIncorrect operation of the sensor ";
            break;}
        case 3:{
            int illumination_value;
            int i = 0;
            int threshold = 50; // порог 50
            for(int x=1; ; x++)
            {   
                cin >> illumination_value;
                illumination_value = illumination_value + i;
                cout << illumination_value/x;
                i = illumination_value;
                if((illumination_value/x) > threshold){
                    cout << "loop was finished";
                    break;}
            }
            break;}
        case 4:{
            int illumination_value;
            int i = 0;
            int threshold = 50; // порог 50
            for(int x=1; ; x++)
            {   
                cin >> illumination_value;
                if(illumination_value < 0){
                    x=x-1;
                    continue;}
                illumination_value = illumination_value + i;
                cout << illumination_value/x << endl;
                i = illumination_value;
                if((illumination_value/x) > threshold){
                    cout << " loop was finished " << endl;
                    break;}
            }
            break;}
        default:{
            cout << "exercise not exist";}
        case 5:{
            
            const int n = 6;
            int array [n];
            for (int i = 0; i < n; i++)
            {
                cin >> array[i];

            }
            int min = array[0], max = array[0];
            for (int j = 0; j < n; j++)
            {
                if (min > array[j]) min = array[j];
                if (max < array[j]) max = array[j];
            }
            
            for (int k = 0; k < n; k++)
            {
            cout << array[k];
            }
            cout << "The difference between min & max  "<< abs(min-max) <<" ";

            break;}
       case 6:{
            
            const int n = 6;
            int array [n];
            for (int i = 0; i < n; i++)
            {
                cin >> array[i];

            }
            int min = array[0], max = array[0];
            for (int j = 0; j < n; j++)
            {
                if (min > array[j]) min = array[j];
                if (max < array[j]) max = array[j];
            }
            int min1 = max, max1 = min;//чтобы первое число массива не оказалось самым маленьким или самым большим 
            for (int a = 0; a < n; a++)
            {
                if (min1 > array[a] && array[a]!=min) min1 = array[a];
                if (max1 < array[a] && array[a]!=max) max1 = array[a];
            }
            for (int k = 0; k < n; k++)
            {
            cout<< array[k];        
            }
            cout << " The difference between min & max  "<< abs(min-max) <<" " << endl;
            cout << "second min: " <<min1 << " second max: " << max1;

            break;}
        case 7:{
            const int n = 6;
            float smth_array[n];
            for (int i = 0; i < n; i++)
            {
                cin >> smth_array[i];
            }
            fun2(smth_array,n);
            break;}
        case 8:{
            const int n = 6;
            float smth_array[n];
            for (int i = 0; i < n; i++)
            {
                cin >> smth_array[i];
            }
            fun3(smth_array,n);
            break;
        }
    }
    return 0;
}

char fun1(float a)
{
    if(a == 0){
        return '0';
    }
    if(a > 0){
        return 'p';
    }
    if(a < 0){
        return 'n';
    }
}
int fun2(float array[], int n)
{
    int positive = 0;
    int negative = 0;
    int zero = 0;
    char comparison; 
    for(int j = 0; j < n; j++)
    {
        comparison = fun1(array[j]);
        //cout << comparison;
        if(comparison == '0') zero++;
        if(comparison == 'p') positive++;
        if(comparison == 'n') negative++;

    }
    cout << "zero:" << zero<< endl;
    cout << "positive:"<< positive<< endl;
    cout << "negative:"<< negative<< endl;
    if(zero > positive && zero > negative) cout<< "zero most of all";
    else if(positive > zero && positive > negative) cout<< "positive most of all";
    else if(negative > zero && positive < negative) cout<< "negative most of all";
    else cout << "there is no definite winner ";
}

int fun3(float array[], int n)
{
    float counter=0;
    for(int j = 0; j < n; j++)
    {
        if(array[j]==0) array[j]=array[j+1];
        if( j == 5 ){
            for (int i = 0; i < n; i++)
            {
                if(array[i]==0) j = 0;
            }
        }
    }
        for(int j = 0; j < n; j++)
    {
        cout << array[j];
        counter = counter+array[j];
    }
    cout << endl << counter/n;
}