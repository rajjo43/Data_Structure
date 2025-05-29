#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[1000], block[1000] = {}, block_size;

    cin >> n;
    block_size = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //calculate the blocks
    for(int i = 0; i < n; i++)
    {
        block[i / block_size] += arr[i];
    }

    cout << "block size: " << block_size << endl;

    int q;
    cin >> q;

    while(q--){
        int op, x, y;
        cin >> op >>x >> y;

        if(op == 1){
            //update
            arr[x] = y;
            block[x / block_size] += y;
        }else{
            int sum = 0;
            for(int i = x; i <= y; ){
                if(i % block_size == 0 && i + block_size - 1 <= y){
                    sum += block[i / block_size];
                }else{
                    sum += arr[i];
                    i++;
                }
            }
            cout << sum << endl;
        }
    }
}