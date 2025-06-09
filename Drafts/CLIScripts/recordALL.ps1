# 将当前终端中所有的输入输出放入日志文件中并标记命令执行时间
# 将这段代码放入powershell的配置文件即可生效
# 调起notepad编辑配置文件代码
# if (-not (Test-Path $PROFILE)) {
#     New-Item -ItemType File -Path $PROFILE -Force
# }
# notepad $PROFILE

# 定义日志文件路径
$logFilePath = "D:\Code Files\vscode\Drafts\terminalLog\allRecords.log"

# 定义一个函数来记录日志
function Log-Command {
    param (
        [string]$Command,
        [string]$Output
    )
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $logEntry = "[$timestamp] Command: $Command`nOutput:`n$Output`n"
    $logEntry | Out-File -FilePath $logFilePath -Append -Encoding UTF8
}

# 覆盖默认的命令执行行为
function global:prompt {
    # 获取最新的历史记录项
    $lastHistory = Get-History | Sort-Object Id -Descending | Select-Object -First 1
    if ($lastHistory) {
        # 获取当前会话的输入行
        $currentInput = (Get-History -Count 1).CommandLine
        # 检查当前输入是否为空或仅为空格
        if (-not [string]::IsNullOrWhiteSpace($currentInput)) {
            try {
                # 直接执行命令并捕获输出
                $output = Invoke-Expression $currentInput 2>&1 | Out-String
            }
            catch {
                $output = $_.Exception.Message
            }
            Log-Command -Command $currentInput -Output $output
        }
    }
    return "PS $($executionContext.SessionState.Path.CurrentLocation)$ "
}
