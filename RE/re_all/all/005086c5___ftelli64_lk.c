
/* Library Function - Single Match
    __ftelli64_lk
   
   Library: Visual Studio 2003 Release */

ulonglong __ftelli64_lk(uint *param_1)

{
  uint _FileHandle;
  byte bVar1;
  ulonglong uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int unaff_EDI;
  longlong lVar10;
  undefined8 local_14;
  uint local_8;
  
  puVar3 = param_1;
  _FileHandle = param_1[4];
  if ((int)param_1[1] < 0) {
    param_1[1] = 0;
  }
  local_14 = __lseeki64(_FileHandle,0x100000000,unaff_EDI);
  uVar8 = (uint)((ulonglong)local_14 >> 0x20);
  if ((uVar8 != 0 && -1 < local_14) || (-1 < local_14)) {
    if ((param_1[3] & 0x108) == 0) {
      return local_14 - (int)param_1[1];
    }
    pcVar5 = (char *)*param_1;
    pcVar6 = (char *)param_1[2];
    local_8 = (int)pcVar5 - (int)pcVar6;
    if ((param_1[3] & 3) == 0) {
      if (-1 < (char)param_1[3]) {
        puVar4 = (undefined4 *)FUN_00501f2f();
        *puVar4 = 0x16;
        goto LAB_00508782;
      }
    }
    else if (((*(byte *)((&DAT_00f48b80)[(int)_FileHandle >> 5] + 4 + (_FileHandle & 0x1f) * 0x24) &
              0x80) != 0) && (pcVar7 = pcVar6, pcVar6 < pcVar5)) {
      do {
        if (*pcVar7 == '\n') {
          local_8 = local_8 + 1;
        }
        pcVar7 = pcVar7 + 1;
      } while (pcVar7 < (char *)*param_1);
    }
    if (local_14 == 0) {
      uVar2 = (ulonglong)local_8;
    }
    else {
      if ((param_1[3] & 1) != 0) {
        if (param_1[1] == 0) {
          local_8 = 0;
        }
        else {
          pcVar5 = pcVar5 + (param_1[1] - (int)pcVar6);
          iVar9 = (_FileHandle & 0x1f) * 0x24;
          if ((*(byte *)(iVar9 + 4 + (&DAT_00f48b80)[(int)_FileHandle >> 5]) & 0x80) != 0) {
            lVar10 = __lseeki64(_FileHandle,0x200000000,unaff_EDI);
            if (local_14 == lVar10) {
              pcVar6 = (char *)param_1[2];
              pcVar7 = pcVar6 + (int)pcVar5;
              param_1 = (uint *)pcVar5;
              for (; pcVar6 < pcVar7; pcVar6 = pcVar6 + 1) {
                if (*pcVar6 == '\n') {
                  param_1 = (uint *)((int)param_1 + 1);
                }
              }
              bVar1 = *(byte *)((int)puVar3 + 0xd) & 0x20;
            }
            else {
              __lseeki64(_FileHandle,(ulonglong)uVar8,unaff_EDI);
              pcVar6 = (char *)0x200;
              if ((((char *)0x200 < pcVar5) || ((param_1[3] & 8) == 0)) ||
                 ((param_1[3] & 0x400) != 0)) {
                pcVar6 = (char *)param_1[6];
              }
              bVar1 = *(byte *)(iVar9 + 4 + (&DAT_00f48b80)[(int)_FileHandle >> 5]) & 4;
              param_1 = (uint *)pcVar6;
            }
            pcVar5 = (char *)param_1;
            if (bVar1 != 0) {
              pcVar5 = (char *)((int)param_1 + 1);
            }
          }
          param_1 = (uint *)pcVar5;
          local_14 = CONCAT44(uVar8 - ((char *)local_14 < param_1),
                              (int)(char *)local_14 - (int)param_1);
        }
      }
      uVar2 = CONCAT44(local_14._4_4_ + (uint)CARRY4(local_8,(uint)local_14),
                       local_8 + (uint)local_14);
    }
  }
  else {
LAB_00508782:
    uVar2 = 0xffffffffffffffff;
  }
  return uVar2;
}

