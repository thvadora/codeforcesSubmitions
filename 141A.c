#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int len(char a[]){
    int i;
    for(i = 0; a[i] != '\0'; ++i);
    return i;
}
int merge(char *a, int first, int mid, int last){

    int length1, length2;
    length1 = mid - first + 1;
    length2 = last - mid;

    int left[length1+1000], right[length2+1000];
    int i,j,k;

    for(i = 0; i < length1; i++){
        left[i] = a[first+i];
    }
    for(j = 0; j < length2; j++){
        right[j] = a[mid+j+1];
    }

    left[i] = 2147483647;
    right[j] = 2147483647;

    i = 0;
    j = 0;
    k = first;

    for(k = first; k <= last; k++){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        
    }

return *a;

}

int merge_sort(char *a, int first, int last){

    int mid = 0;

    if (first<last){
        mid = (first + last)/ 2;
        merge_sort(a,first,mid);
        merge_sort(a,mid+1,last);
        merge(a,first,mid,last);
    }

return *a;

}

bool exists(char pile[], int tam, int elem){

    bool r = false;
    int i;
    for (i = 0; i < tam && r; i++){
        if(pile[i]==elem){
            r = true;
            break;
        }
    }

    return !r;
}


int main(int argc, char const *argv[]){
    
    char guest[500];
    char residence[500];
    char pile[500];
    bool r = true;
    bool s = false;
    char big_array[500];
    int i = 0;
    int j = 0;
    int t = 0;

    scanf("%s", &guest);
    scanf("%s", &residence);
    scanf("%s", &pile);

    if((len(guest)+len(residence)) == len(pile)){
        s = true;
    }

    while(i < (len(guest)+len(residence))){
        if(i < len(guest)){
            big_array[i] = guest[j];
            j++;
        }else if(i >= len(guest)){
            big_array[i] = residence[t];
            t++;
        }
        i++;
    }

    merge_sort(big_array,0,(len(guest)+len(residence))-1);
    merge_sort(pile,0,len(pile)-1);

    for (i = 0; i < len(pile); i++){
        r = r && (pile[i] == big_array[i]);
    }
     
if (r && s){
    printf("YES");
} else {
    printf("NO");       
}


    return 0;
}