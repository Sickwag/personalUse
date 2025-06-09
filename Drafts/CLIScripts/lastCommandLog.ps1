$PSDefaultParameterValues['Out-File:Width'] = 4096
$FormatEnumerationLimit = -1  # 解除枚举限制

# 获取上一条命令
$lastCommand = Get-History | Select-Object -Last 1 | Select-Object -ExpandProperty CommandLine
Write-Host "Last command: $lastCommand"

# 执行上一条命令并捕获输出
try {
    $output = $result | Out-String -Width 4096  # ← 关键修改
    # 添加换行符规范化处理
    $output = $output -replace "`r`n", "`n" -replace "`n", "`r`n"
    $output = Invoke-Expression $lastCommand
    Write-Host "Command output: $output"
} catch {
    Write-Host "Error executing command: $_"
}

# 组合命令和输出
$combined = "$lastCommand`n$output"

# 指定要保存的文件路径
$filePath = "D:\Code Files\vscode\Drafts\terminalLog\terminalLog.txt"
Write-Host "Saving to file: $filePath"

# 将组合内容保存到文件中
try {
    $combined | Out-File -FilePath $filePath -Encoding UTF8
    Write-Host "Output saved to file successfully."
} catch {
    Write-Host "Error saving to file: $_"
}