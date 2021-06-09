function solution(s) {
  /*내 풀이*/
    var answer = [];
    s=s.split(' ');
    for (let i=0; i<s.length;i++){
        let l=s[i].length;
        let a="";
        for (let j=0; j<l; j++){
            if (j%2==0) {
                a+=s[i][j].toUpperCase();
            }
            else{
                a+=s[i][j].toLowerCase();
            }
        }
        answer.push(a);
    }
    answer=answer.join(" ");
    /*갓코드..*/
    s=s.split(' ').map(i => i.split('').map((v, i) => i % 2 === 0 ? v.toUpperCase() : v.toLowerCase()).join('')).join(' ');
}
