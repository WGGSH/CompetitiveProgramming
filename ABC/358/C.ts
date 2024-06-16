import * as readline from "readline";

const stream = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let inputs = "";
let lines: string[] = [];
stream.on("line", (line) => {
  inputs += line;
  inputs += "\n";
  lines.push(line);
});

const getBitCount = (n: number) => {
  let count = 0;
  while (n) {
    n &= n - 1;
    count++;
  }
  return count;
}

const getBitPositions = (n: number, max: number) => {
  const positions: number[] = [];
  for (let i = 0; i < max; i++) {
    if (n & (1 << i)) {
      positions.push(i);
    }
  }
  return positions;
}

stream.on("close", () => {
  const N = Number(lines[0].split(' ')[0]);
  const M = Number(lines[0].split(' ')[1]);
  const S = lines.slice(1).map((line) => String(line.split(' ')));
  // ['ooxxo', ...]
  // 'o' → true, 'x' → false に変換，ビット化して整数とする
  const dataList = S.map((data) => {
    return data.split('').map((char) => char === 'o').reduce((acc, cur) => acc << 1 | (cur ? 1 : 0), 0);
  })

  // データの加工
  const max = 1 << N;
  let min = N;

  const answer = (1 << M) - 1;
  for(let bitCase = 0; bitCase < max; bitCase++) {
    // bitCase が立っているものだけでデータを取り出す

    const bitCount = getBitCount(bitCase);
    if (bitCount >= min) continue;
    const bitPositions = getBitPositions(bitCase, N);
    const filteredDataList = bitPositions.map((bitPosition) => dataList[bitPosition]);

    const result = filteredDataList.reduce((acc, cur) => acc | cur, 0);
    if (result === answer) {
      if (bitCount < min) {
        min = bitCount;
        // console.log(bitCount, bitPositions.map((bitPosition) => bitPosition + 1).join(' '));
      }
    }
  }

  console.log(min)
});
