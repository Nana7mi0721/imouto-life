
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00421040(int param_1,int param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  BOOL BVar4;
  CHAR local_67c [264];
  CHAR local_574 [264];
  _WIN32_FIND_DATAA local_46c;
  HANDLE local_328;
  CHAR local_324 [263];
  char acStack_21d [264];
  char acStack_115 [269];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    FUN_004711b0(acStack_21d + 1,param_1,0x104);
    sVar2 = _strlen(acStack_21d + 1);
    if (acStack_21d[sVar2] != '\\') {
      FUN_00471190(acStack_21d + 1,&DAT_007cc758,0x104);
    }
    FUN_004711b0(acStack_115 + 1,param_2,0x104);
    sVar2 = _strlen(acStack_115 + 1);
    if (acStack_115[sVar2] != '\\') {
      FUN_00471190(acStack_115 + 1,&DAT_007cc75c,0x104);
    }
    iVar3 = FUN_004fe42e(acStack_21d + 1,0);
    if (iVar3 == -1) {
      uVar1 = 0;
    }
    else {
      iVar3 = FUN_004711d0(acStack_21d + 1,acStack_115 + 1);
      if (iVar3 == 0) {
        uVar1 = 0;
      }
      else {
        CreateDirectoryA(acStack_115 + 1,(LPSECURITY_ATTRIBUTES)0x0);
        FUN_004711b0(local_324,acStack_21d + 1,0x104);
        FUN_00471190(local_324,&DAT_007cc760,1);
        local_328 = FindFirstFileA(local_324,&local_46c);
        if (local_328 == (HANDLE)0xffffffff) {
          uVar1 = 0;
        }
        else {
          do {
            if (local_46c.cFileName[0] != '.') {
              FUN_004711b0(local_67c,acStack_21d + 1,0x104);
              FUN_00471190(local_67c,local_46c.cFileName,0x104);
              FUN_004711b0(local_574,acStack_115 + 1,0x104);
              FUN_00471190(local_574,local_46c.cFileName,0x104);
              if ((local_46c.dwFileAttributes & 0x10) == 0) {
                BVar4 = CopyFileA(local_67c,local_574,0);
                if (BVar4 == 0) {
                  FindClose(local_328);
                  return 0;
                }
                DeleteFileA(local_67c);
              }
              else {
                iVar3 = FUN_00421040(local_67c,local_574);
                if (iVar3 == 0) {
                  FindClose(local_328);
                  return 0;
                }
                RemoveDirectoryA(local_67c);
              }
            }
            BVar4 = FindNextFileA(local_328,&local_46c);
          } while (BVar4 != 0);
          FindClose(local_328);
          uVar1 = 1;
        }
      }
    }
  }
  return uVar1;
}

