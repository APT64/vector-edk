build -p OvmfPkg\OvmfPkgX64.dsc -a X64 -t VS2010x86 -D USE_OLD_SHELL -b RELEASE
copy /y Build\OvmfX64\RELEASE_VS2010x86\FV\OVMF.fd e:\
