function solution(word, pages) {
    const pageMap=new Map();
    pages.forEach((page, idx) =>{
        const pageArr=page.split("\n");

        const urlIdx=pageArr.findIndex(el=>el.includes("meta property"));
        const pageURL=pageArr[urlIdx].match(/"https:\S*"/)[0]; //현재 페이지의 URL

        //body 안에 연결된 URL이 있음
        const bodyStart=pageArr.findIndex(el=>el.includes("<body>"));
        const bodyEnd=pageArr.findIndex(el=>el.includes("</body>"));
        
        const body=pageArr.slice(bodyStart+1, bodyEnd);
        //기본 점수
        const defaultPoint=body.flatMap((str)=>str.toLowerCase().split(/[\d|\W]/)).filter(e=>e===word.toLowerCase()).length; //숫자와 특수 문자 제외
        const externalURL=body.flatMap(str=>str.match(/<a href="https:\S*"/gi)).filter(e=>e).map(e=>e.substr(8, e.length));

        pageMap.set(pageURL, {idx, defaultPoint, matchingPoint:0, externalURL});
    })
    
    for(const [key, value] of pageMap) {
        const linkPoint = value.defaultPoint / value.externalURL.length; //해당 URL의 링크점수
    
        for(const link of value.externalURL) {
          if(pageMap.has(link)) {
            const origin = pageMap.get(link);
            const calculatedPoint = origin.matchingPoint 
                ? origin.matchingPoint + linkPoint
                : origin.defaultPoint + linkPoint;
            pageMap.set(link, { ...origin, matchingPoint: calculatedPoint });
          }
        }
  }
    
    const answer = [];
  
    for(const [key, value] of pageMap) {
        const { idx, defaultPoint, matchingPoint, externalURL } = value;
        const finalPoint = matchingPoint ? matchingPoint : defaultPoint;
        answer.push([ idx, finalPoint ]);
     };

     answer.sort((a, b) => a[1] === b[1] ? a[0] - b[0] : b[1] - a[1]);

     return answer[0][0];
    
}
