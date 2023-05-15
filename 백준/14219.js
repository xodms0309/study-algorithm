const input = require('fs').readFileSync('/dev/stdin').toString().trim();
const [n, m] = input.split(" ").map(Number);
if (n*m%3===0) console.log("YES");
else console.log("NO");
