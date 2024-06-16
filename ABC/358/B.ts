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
  const A = Number(lines[0].split(' ')[1]);
  const times = lines[1].split(' ').map(Number);

  let currentTime = 0;
  // currentTime: その人がチケット購入を完了した時刻
  // time: その人が並んだ時刻
  const completedTimes: number[] = [];
  times.forEach((time) => {
    if (currentTime <= time) {
      currentTime = time + A;
    } else {
      currentTime += A;
    }
    completedTimes.push(currentTime);
  });
  // 全人の購入完了
  console.log(completedTimes.map(String).join('\n'));
});
