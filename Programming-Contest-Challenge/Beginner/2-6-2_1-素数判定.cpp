/* 
 * �򵥵������ж�������2~����n�ж��Ƿ�������
 * ����Լ��ö�٣��о��������ӣ��������ֽ⣨��֪�������ɶ�ģ�
 */
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int n;

bool is_prime(int n) // ���Բ���
{
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false; 
    }
    return n != 1; // 1������
}

vector<int> divisor(int n) // Լ��ö��
{
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

map<int, int> prime_factor(int n) // �����ֽ�
{
    map<int, int> res;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main()
{
    scanf("%d", &n);
    if(is_prime(n)) printf("Yes\n");
    else {
        printf("No\n");
        vector<int> yueshu = divisor(n);
        for(int i = 0; i < yueshu.size(); i++) {
            printf("%d ", yueshu[i]);
        }
        printf("\n");
        map<int, int> fenjie = prime_factor(n);
        map<int, int>::iterator ite;
        for(ite = fenjie.begin(); ite != fenjie.end(); ++ite) {
            printf("%d * %d = %d\n", ite->first, ite->second, n);
        }
    }
    return 0;
}

/* 
input1
53

input2
295927
*/