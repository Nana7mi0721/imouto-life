
/* Library Function - Single Match
    ___mbstowcs_mt
   
   Library: Visual Studio 2003 Release */

uint ___mbstowcs_mt(int param_1,LPWSTR param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  size_t sVar6;
  uint local_8;
  
  uVar1 = 0;
  if (param_2 == (LPWSTR)0x0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      sVar6 = _strlen((char *)param_3);
      return sVar6;
    }
    iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,-1,(LPWSTR)0x0,0);
    if (iVar2 != 0) goto LAB_004fd8f7;
  }
  else {
    if (param_4 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x14) == 0) {
      if (param_4 == 0) {
        return 0;
      }
      do {
        *param_2 = (ushort)param_3[uVar1];
        if (param_3[uVar1] == 0) {
          return uVar1;
        }
        uVar1 = uVar1 + 1;
        param_2 = param_2 + 1;
      } while (uVar1 < param_4);
      return uVar1;
    }
    iVar2 = MultiByteToWideChar(*(UINT *)(param_1 + 4),9,(LPCSTR)param_3,-1,param_2,param_4);
    if (iVar2 != 0) {
LAB_004fd8f7:
      return iVar2 - 1;
    }
    DVar3 = GetLastError();
    if (DVar3 == 0x7a) {
      local_8 = param_4;
      pbVar5 = param_3;
      do {
        local_8 = local_8 - 1;
        if (*pbVar5 == 0) break;
        if (((*(byte *)(*(int *)(param_1 + 0x48) + 1 + (uint)*pbVar5 * 2) & 0x80) != 0) &&
           (pbVar5 = pbVar5 + 1, *pbVar5 == 0)) goto LAB_004fd87c;
        pbVar5 = pbVar5 + 1;
      } while (local_8 != 0);
      uVar1 = MultiByteToWideChar(*(UINT *)(param_1 + 4),1,(LPCSTR)param_3,
                                  (int)pbVar5 - (int)param_3,param_2,param_4);
      if (uVar1 != 0) {
        return uVar1;
      }
    }
  }
LAB_004fd87c:
  puVar4 = (undefined4 *)FUN_00501f2f();
  *puVar4 = 0x2a;
  return 0xffffffff;
}

