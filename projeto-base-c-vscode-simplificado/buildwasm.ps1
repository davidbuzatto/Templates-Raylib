# Custom build script for webassembly (windows powershell).
#
# Usage:
#    .\buildwasm.ps1: clean, compile and run
#    .\buildwasm.ps1 -clean: clean compiled file
#    .\buildwasm.ps1 -cleanAndCompile: clean compiled file and compile the project
#    .\buildwasm.ps1 -compile: compile the project
#    .\buildwasm.ps1 -compileAndRun: compile the project and run the compiled file
#    .\buildwasm.ps1 -run: run the compiled file
#
# Author: Prof. Dr. David Buzatto

param(
    [switch]$clean,
    [switch]$cleanAndCompile,
    [switch]$compile,
    [switch]$compileAndRun,
    [switch]$run
);

$CurrentFolderName = Split-Path -Path (Get-Location) -Leaf
$CompiledFile = "$CurrentFolderName"
$BuildDir = "build"

$all = $false
if ( -not( $clean -or $cleanAndCompile -or $compile -or $compileAndRun -or $run ) ) {
    $all = $true
}

# clean
if ( $clean -or $cleanAndCompile -or $all ) {
    Write-Host "Cleaning..."
    if ( Test-Path $BuildDir ) {
        Remove-Item $BuildDir -Recurse -Force
    }
}

# compile
if ( $compile -or $cleanAndCompile -or $compileAndRun -or $all ) {
    Write-Host "Compiling..."
    New-Item -Path ".\$BuildDir" -Force -ItemType Directory > $null
    # @(...) forces an array even when there is a single .c file: a lone result is
    # a scalar string, and splatting a string (@string) iterates its characters.
    # Relative paths (no spaces) + @ splat make each .c reach emcc as a separate
    # argument; passing the array as one token ($sources) would instead collapse
    # into a single joined string when emcc.ps1 forwards UnboundArguments to python.
    $sources = @(Get-ChildItem -Path .\src -Recurse -Filter *.c | Resolve-Path -Relative)
    emcc -o "./$BuildDir/$CompiledFile.html" `
         @sources `
         -Wall `
         -std=c99 `
         -D_DEFAULT_SOURCE `
         -Wno-missing-braces `
         -Wunused-result `
         -Os `
         -I./src/include `
         -L./lib/wasm/ `
         -s USE_GLFW=3 `
         -s USE_SDL=2 `
         -s USE_SDL_MIXER=2 `
         -s ASYNCIFY `
         -s INITIAL_MEMORY=134217728 `
         -s ALLOW_MEMORY_GROWTH=1 `
         -s FORCE_FILESYSTEM=1 `
         --preload-file ./resources@/resources `
         --shell-file ./src/wasm/minshell.html `
         -lraylib `
         -DPLATFORM_WEB `
         -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' `
         -s EXPORTED_RUNTIME_METHODS=ccall
         #-s ASSERTIONS   # uncomment for debugging (increases .wasm size and runtime overhead)
}

# run
if ( $run -or $compileAndRun -or $all ) {
    Write-Host "Running..."
    if ( Test-Path "$BuildDir\$CompiledFile.html" ) {
        emrun ".\$BuildDir\$CompiledFile.html"
    } else {
        Write-Host "$CompiledFile does not exists!"
    }
}