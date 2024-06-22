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

stream.on("close", () => {
  const N = Number(lines[0].split(' ')[0]);
  const M = Number(lines[0].split(' ')[1]);

  const AList = lines[1].split(' ').map(Number);
  const BList = lines[2].split(' ').map(Number);

  const sortedAList = AList.sort((a, b) => a - b);
  const sortedBList = BList.sort((a, b) => a - b);

  let answer = 0;
  let filteredList = sortedAList;
  let isBreak = false;

  // const hoge = sortedBList.map((b) => {
  //   const target = filteredList.findIndex((a) => a >= b);
  //   return target;
  // });
  // console.log(filteredList)
  sortedBList.forEach((b) => {
    const targetIndex = filteredList.findIndex((a) => a >= b);
    console.log(targetIndex)
    if (targetIndex === -1) {
      isBreak = true;
      return;
    }
    answer += filteredList[targetIndex];
    filteredList.splice(0, targetIndex + 1);
    // console.log(b, filteredList)
  });
  if (isBreak) {
    console.log(-1);
    return;
  }
  console.log(answer)

  // sortedBList.forEach((b) => {
  //   filteredList = filteredList.filter((a) => a >= b);
  //   if (filteredList.length === 0) {
  //     isBreak = true;
  //     return;
  //   }
  //   answer += filteredList[0];
  //   filteredList.shift();
  // });
  // if (isBreak) {
  //   console.log(-1);
  // } else {
  //   console.log(answer);
  // }
});
