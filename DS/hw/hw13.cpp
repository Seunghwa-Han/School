#include <iostream>
#include <string>
using namespace std;

class s_record{
public:
    string s_id;
    string name;
    double score;
};

void show_thelist(s_record * list, int n){
    for(int i=0; i<n; i++)
        cout<< list[i].s_id <<" : "<<list[i].name<<" : "<<list[i].score<<"\n";
}

void insertion_sort(s_record * list, int n){
    int i, j;
    for(i = 1; i<n; i++){
        s_record tmp = list[i];
        for(j = i-1; j>=0; j--){
            if(tmp.s_id < list[j].s_id){
                list[j+1] = list[j]; 
            }else break;
        }
        list[j+1] = tmp;
    }
}

void bubble_sort(s_record * list, int n){
    for(int i = n-1 ; i>=1; i--){
        for(int j =0; j<i; j++){
            if(list[j].s_id > list[j+1].s_id){
                s_record tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            } 
        }
    }
}

void selection_sort(s_record * list, int n){
    int i,j;
    for(i =0; i<n; i++){
        int min_index = i;
        for(j = i+1; j<n; j++){
            if(list[min_index].s_id > list[j].s_id)
                min_index = j;
        }
        if(min_index != i){
            s_record tmp = list[i];
            list[i] = list[min_index];
            list[min_index] = tmp;
        }
    }
}

void quick_sort(s_record * list, int left, int right){
    int pivot = left;
    int end = right;
    s_record tmp;

    if(left >= right) return;
    
    left++;
    while(1){
        while(list[pivot].s_id > list[left].s_id)  //큰거 발견하면 stop 
            left++;
        while(list[pivot].s_id < list[right].s_id)  //작은거 발견하면 stop 
            right--;

        if(left>right) break;
        tmp = list[left];
        list[left] = list[right];
        list[right] = tmp;
    }
    
    tmp = list[pivot];
    list[pivot] = list[right];
    list[right] = tmp;

    quick_sort(list, 0, right-1);
    quick_sort(list, right+1, end);

}

void merge(s_record * a, s_record * b, int n1, int n2, int n3, int n4){
    int i = n1;
    int j = n3;
    int k = n1; 
    while(1){
        if(i>n2){
            for(;j<=n4; j++)
                b[j] = a[j];
            break;
        }
        else if(j>n4){
            for(; i<=n2; i++)
                b[k++] = a[i];
            break;
        }
        if(a[i].s_id<a[j].s_id){
            b[k++] = a[i++];
        }else  
            b[k++] = a[j++];
    }
}
// void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4) {
// 	int i, j, k, t;
// 	i = n1;
// 	j = n3;
// 	k = n1;
// 	while (i <= n2 && j <= n4) {
// 		if (a[i].s_id <= a[j].s_id)
// 			b[k++] = a[i++];
// 		else
// 			b[k++] = a[j++];
// 	}
// 	if (i > n2) {
// 		for (t = j; t <= n4; t++) {
// 			b[t] = a[t];
// 		}
// 	}
// 	else
// 		for (t = i; t <= n2; t++)
// 			b[k+t-i] = a[t];
// }
void merge_pass(s_record a[], s_record b[],int n, int s){
    //주어진 list(a)의 n개 원소에 대하여, 길이 s 단위로 merge하여 새로운list(b) 생성 
    // 0 1 2 3 4 5 6 7 8 9 10 11
    int i;
    for(i=0; i+2*s-1 < n; i+=2*s){
        merge(a,b, i, i+s-1, i+s, i+2*s-1);
    }

    if(i+s<=n){    //남은 조각들 처리 
        merge(a,b,i, i+s-1, i+s, n);
    }else{
        for(int j =i; j<=n; j++)
            b[j] = a[j];
    }
}
void merge_sort(s_record a[], int n){
    s_record b[n];

    for(int s = 1; s<n; s*=2){
        merge_pass(a, b, n-1, s);
        s= s*2;
        merge_pass(b, a, n-1, s);
    }
}

void adjust(s_record a[], int t_root, int size){   //0부터 시작하는 힙 
    s_record tmp = a[t_root];
    int child = t_root*2 +1;

    while(child<=size){
        if( child<size && a[child].s_id< a[child+1].s_id)  //right child가 있고, right이 left보다 클 때 
            child++;
        if( tmp.s_id > a[child].s_id)   //child가 더 작으면 stop 
            break;
        else{
            a[(child-1)/2] = a[child];  //큰거 끌어올리고 
            child = child*2+1;        //밑으로 내려가기 
        }
    }
    a[(child-1)/2] = tmp;
}
void heap_sort(s_record list[], int n){
    int size = n-1;
    
    for(int i = (size-1)/2; i>=0; i--){   //초기 힙 구성 
        adjust(list, i, size);
    }

    for(int i=size-1; i>=0; i--){
        s_record tmp = list[0];
        list[0] = list[i+1];
        list[i+1] = tmp;

        adjust(list, 0, i);
    }
}

int main(){

    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                 { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
                 { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
                 { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    int n = 12;

    // insertion_sort(s_list, n);
    // bubble_sort(s_list, n);
    // selection_sort(s_list, n);

    // quick_sort(s_list, 0, n-1);
     merge_sort(s_list, n);
    // heap_sort(s_list, n); 

    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);

    return 0;
}