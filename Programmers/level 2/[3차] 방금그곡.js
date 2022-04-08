function solution(m, musicinfos) {
    const replace=(melody)=>{
        return melody
            .replace(/(C#)/g, "c")
            .replace(/(D#)/g, "d")
            .replace(/(F#)/g, "f")
            .replace(/(G#)/g, "g")
            .replace(/(A#)/g, "a");
    }
    m=replace(m);
    const arr=musicinfos.map((music)=>{
        const [start, end, title, score]=music.split(',');
        const hour=end.slice(0,2)-start.slice(0,2);
        const min=end.slice(3,5)-start.slice(3,5);
        const playtime=hour*60+min;
        const newScore=replace(score);
        let playedMusic=newScore.repeat(playtime/newScore.length);
        playedMusic+=newScore.slice(0, playtime%newScore.length);
        return [title, playtime, playedMusic]
    })
    let answer='';
    let longLen=0;
    arr.forEach((el)=>{
        if (replace(el[2]).includes(m) && el[1]>longLen) {
            answer=el[0];
            longLen=el[1];
        }
    })
    if (answer==='') return '(None)';
    else return answer;
}
