const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
//const input = require('fs').readFileSync('./test.txt').toString().trim().split('\n');
const [N, A, M, B] = input.map(v => v.split(" ").map(x => Number(x)));
A.sort((a,b)=>a-b);
const binarySearch=(arr, left, right, target)=>{
    while (left<=right) {
        const mid=Math.floor((left+right)/2);
        if (arr[mid]===target) return 1;
        if (arr[mid]>target) right=mid-1;
        else left=mid+1;
    }
    return 0;
}
const result=B.map(b=>binarySearch(A, 0, A.length-1, b));
console.log(result.join("\n"));
