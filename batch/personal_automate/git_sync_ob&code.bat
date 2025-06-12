@echo off
setlocal

set LOG_FILE=D:\Code Files\vscode\batch\personal_automate\sync.log
set obsidian_repo_path=E:\file_storage\Obsidian vault\vault
set code_repo_path=D:\Code Files\vscode

REM 初始化日志文件
echo ===== 同步开始: %date% %time% ===== >> "%LOG_FILE%"

REM 同步Obsidian仓库
echo [%date% %time%] 开始同步Obsidian仓库: %obsidian_repo_path% >> "%LOG_FILE%"
cd /d "%obsidian_repo_path%" 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 错误: 无法进入目录: %obsidian_repo_path% >> "%LOG_FILE%"
  exit /b 1
)

git add . 2>&1 >> "%LOG_FILE%"
git commit -m "daily sync %date% %time%" 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 警告: Obsidian仓库提交失败 >> "%LOG_FILE%"
)

git push origin master 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 错误: Obsidian仓库推送失败 >> "%LOG_FILE%"
  exit /b 1
)

echo [%date% %time%] 同步完成: Obsidian仓库 %obsidian_repo_path% >> "%LOG_FILE%"

REM 同步Code仓库
echo [%date% %time%] 开始同步Code仓库: %code_repo_path% >> "%LOG_FILE%"
cd /d "%code_repo_path%" 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 错误: 无法进入目录: %code_repo_path% >> "%LOG_FILE%"
  exit /b 1
)

git add . 2>&1 >> "%LOG_FILE%"
git commit -m "daily sync: %date% %time%" 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 警告: Code仓库提交失败 >> "%LOG_FILE%"
)

git push origin master 2>&1 >> "%LOG_FILE%"
if errorlevel 1 (
  echo [%date% %time%] 错误: Code仓库推送失败 >> "%LOG_FILE%"
  exit /b 1
)

echo [%date% %time%] 同步完成: Code仓库 %code_repo_path% >> "%LOG_FILE%"
echo ===== 同步结束: %date% %time% ===== >> "%LOG_FILE%"
echo. >> "%LOG_FILE%"

endlocal
