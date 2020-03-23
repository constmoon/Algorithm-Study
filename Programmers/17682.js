function calcBonus(bonus, x) {
    switch(bonus) {
        case 'S':
            return x;
        case 'D':
            return Math.pow(x, 2);
        case 'T':
            return Math.pow(x, 3);
    }
}
function solution(dartResult) {
    // 한 글자씩 읽을 거면 정규식을 쓰지 않거나 더 넓은 범위에서 사용하도록 고치기
    const numExp = /[0-9]/;
    const alphaExp = /[A-Z]/;
    let score = [];
    let num = 0;
    let dartResultLen = dartResult.length;
    
    for(let i=0; i<dartResultLen; i++) {
        if(numExp.test(dartResult[i])) {
            num = num*10 + Number(dartResult[i]);
        } else if(alphaExp.test(dartResult[i])) {
            score.push(calcBonus(dartResult[i], num));
            num = 0;
        } else {
            let prev = score.length -1;
            if(dartResult[i] === '*') {
                score[prev] *= 2;
                if(prev > 0) {
                    score[prev-1] *= 2;
                }
            } else if(dartResult[i] === '#') {
                score[prev] *= -1;
            }
        }
    }
    
    return score.reduce((acc, curr) => acc + curr)
}