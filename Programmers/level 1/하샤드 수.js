function solution(x) {
    let divider=0;
    divider=x.toString().split('').map(i=>parseInt(i)).reduce((acc, cur)=>acc+cur);
    if (x%divider===0) return true;
    else return false;
}
