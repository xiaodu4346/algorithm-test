# LeetCode 刷题工作区

这个目录已经配置好 VS Code、LeetCode 中国站、C++17 和 Python 3。

## 第一次使用

1. 用 VS Code 打开 `D:\project\algorithm-test`。
2. 如果 VS Code 当前已经打开，请执行一次“开发人员: 重新加载窗口”，或直接重启 VS Code。
3. 点击左侧活动栏的 LeetCode 图标。
4. 点击 **Sign in to LeetCode**，登录力扣中国站账号。
5. 在题目列表里选择题目，然后点击 **Code Now**。

登录必须由账号本人完成；项目已默认指向 `leetcode.cn`，国内站和国际站账号不互通。

## 日常刷题

- 新题默认使用 C++，题目保存在 `leetcode/<难度>/cpp/`。
- 代码上方的 **Test** 用于运行自定义测试。
- 代码上方的 **Submit** 用于提交到力扣判题。
- **Solution** 查看题解，**Description** 重新打开题目说明。
- 需要改用 Python 时，按 `Ctrl+Shift+P`，执行 **LeetCode: Switch Default Language**，选择 `python3`。

## 本地环境

- C++：`C:\mingw64\bin\g++.exe`，按 C++17 提供补全和诊断。
- Python：`D:\python.exe`（Python 3.9）。
- LeetCode 插件专用 Node.js：`.tools\node-v20.18.2-win-x64\node.exe`。

原有的 `6.15-test.cpp` 仍可本地编译：

```powershell
g++ 6.15-test.cpp -std=c++17 -O2 -Wall -Wextra -o output/6.15-test.exe
.\output\6.15-test.exe
```
