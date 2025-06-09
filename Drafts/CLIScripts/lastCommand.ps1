$PSDefaultParameterValues['Out-File:Width'] = 4096
$FormatEnumerationLimit = -1  # 解除枚举限制

# 获取上一条命令
$lastCommand = Get-History | Select-Object -Last 1 | Select-Object -ExpandProperty CommandLine

# 尝试执行上一条命令并捕获输出，同时处理可能的异常
try {
    $output = $result | Out-String -Width 4096  # ← 关键修改
    # 添加换行符规范化处理
    $output = $output -replace "`r`n", "`n" -replace "`n", "`r`n"
    $output = Invoke-Expression $lastCommand
}
catch {
    $output = "Command execution failed: $_"
}

# 组合命令和输出
$combined = "$lastCommand`n$output"

# 将组合内容复制到剪贴板
try {
    $combined | Set-Clipboard
    Write-Host "The last command and its output have been copied to the clipboard."
}
catch {
    Write-Host "Failed to copy to the clipboard: $_"
}