# 使用方法为打开终端后，使用. curDialog(文件名).ps1将当前脚本**加载到当前会话**中，然后在终端的IO就都会被记录
# 强制声明脚本版本和编码
#Requires -Version 5
[System.Text.Encoding]::OutputEncoding = [System.Text.Encoding]::UTF8
# 在脚本开头添加输出缓冲区设置
$PSDefaultParameterValues['Out-File:Width'] = 4096
$FormatEnumerationLimit = -1  # 解除枚举限制

# 日志路径配置（修复路径漂移问题）
$global:LogRoot = "D:\Code Files\vscode\Drafts\terminalLog"
$timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
$global:LogFullPath = Join-Path $LogRoot "powershellLog_$timestamp.log"

# 强化目录创建（带错误捕获）
try {
    if (-not (Test-Path $LogRoot)) {
        New-Item -Path $LogRoot -ItemType Directory -Force -ErrorAction Stop | Out-Null
        Write-Host "[DEBUG] created log directory: $LogRoot" -ForegroundColor Cyan
    }
} catch {
    Write-Host "[FATAL] create log directory failed: $_" -ForegroundColor Red
    exit 1
}

# 增强版日志函数（追加进程ID和错误堆栈）
function global:Log-InputOutput {
    param (
        [string]$InputCommand,
        [string]$Output
    )
    try {
        $output = $result | Out-String -Width 4096  # ← 关键修改
        # 添加换行符规范化处理
        $output = $output -replace "`r`n", "`n" -replace "`n", "`r`n"
        $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss.fff"
        $processInfo = "[PID:$PID][$(whoami)]"
        $logEntry = "[$timestamp]$processInfo Input: $InputCommand`nOutput:`n$Output`n$(Get-PSCallStack | Out-String)`n------------------------`n"
        $logEntry | Out-File -FilePath $global:LogFullPath -Append -Encoding UTF8 -ErrorAction Stop
    } catch {
        Write-Host "[ERROR] write log in file failed: $_" -ForegroundColor Red
    }
}

# 安全版prompt函数
function global:prompt {
    $lastCommand = Get-History -Count 1 -ErrorAction SilentlyContinue
    if ($lastCommand -and -not [string]::IsNullOrWhiteSpace($lastCommand.CommandLine)) {
        try {
            $result = Invoke-Expression $lastCommand.CommandLine 2>&1
            $output = $result | Out-String
        } catch {
            $output = "[EXCEPTION] $_`n$($_.ScriptStackTrace)"
        }
        Log-InputOutput -InputCommand $lastCommand.CommandLine -Output $output
    }
    # 返回原始提示符
    "PS $($executionContext.SessionState.Path.CurrentLocation)$ "
}

# 启动自检
try {
    Test-Path $global:LogFullPath -ErrorAction Stop | Out-Null
    Write-Host "[BOOT] log system is ready : $global:LogFullPath" -ForegroundColor Green
} catch {
    Write-Host "[BOOT] initialize failed: $_" -ForegroundColor Red
}
