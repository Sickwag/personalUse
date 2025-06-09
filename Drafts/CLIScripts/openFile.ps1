<#
.SYNOPSIS
使用指定应用程序打开固定路径的短语文件

.PARAMETER Application
应用程序名称或路径（支持环境变量中的程序）
#>
param(
    [Parameter(Mandatory=$false)]
    [string]$Application = "notepad"  # 默认用记事本打开
)

# 固定文件路径
$FixedFilePath = "D:\Code Files\vscode\Drafts\choreFiles\sogouPhrase.txt"

# 验证文件存在性
if (-not (Test-Path $FixedFilePath)) {
    Write-Host "[ERROR] file doesn't exist: $FixedFilePath" -ForegroundColor Red
    exit 1
}

# 解析应用程序路径
try {
    # 检查是否为系统已知命令
    $appPath = (Get-Command $Application -ErrorAction Stop).Source
} catch {
    Write-Host "[ERROR] can't find the application: $Application" -ForegroundColor Red
    Write-Host "application available:"
    ($env:PATH -split ';') | Where-Object { $_ } | Get-ChildItem -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Name -Unique
    exit 2
}

# 启动应用程序
try {
    Start-Process -FilePath $appPath -ArgumentList """$FixedFilePath""" -ErrorAction Stop
    Write-Host "[SUCCESS] use $($appPath.Split('\')[-1]) opened file" -ForegroundColor Green
} catch {
    Write-Host "[LAUNCH ERROR] cannot open this file: $_" -ForegroundColor Red
}
