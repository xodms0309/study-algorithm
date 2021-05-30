function solution(strings, n) {
    strings.sort(); //먼저 알파벳 순서로 sort
    strings.sort((a,b)=>a[n]>b[n]?1:a[n]<b[n]?-1:0); //n번째 알파벳 기준으로 정렬
    return strings;
}
