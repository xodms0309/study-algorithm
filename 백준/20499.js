const input = require('fs').readFileSync('/dev/stdin').toString().trim();
const [k, d, a] = input.split("/").map(Number);
if (d==0 || k+a<d) {
    console.log("hasu");
    return;
}
console.log("gosu");
