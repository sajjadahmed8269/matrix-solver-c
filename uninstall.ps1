$installDir = "$HOME\matrix-solver-test"

Write-Host "Uninstalling Matrix Solver..." -ForegroundColor Yellow

# 1. Remove the directory and the EXE
if (Test-Path $installDir) {
    Remove-Item -Recurse -Force $installDir
    Write-Host "✅ Deleted files from $installDir" -ForegroundColor Green
}

# 2. Clean up the PATH environment variable
$oldPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($oldPath -like "*$installDir*") {
    # Remove the directory from the path string
    $newPath = $oldPath -replace [regex]::Escape(";$installDir"), ""
    $newPath = $newPath -replace [regex]::Escape($installDir), ""
    
    [Environment]::SetEnvironmentVariable("Path", $newPath, "User")
    Write-Host "✅ Removed from User PATH. Please restart your terminal." -ForegroundColor Green
}